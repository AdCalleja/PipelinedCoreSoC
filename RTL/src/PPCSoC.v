`include "DataMemory.v"
`include "LEDDriver.v"
`include "PipelinedCore.v"

//`define BUTTON = 1
//`define SLOWCLOCK = 1
//`define DEBUGINSTRUCTION = 1
//Debouncer
`ifdef BUTTON
    `include "Debouncer.v"
`endif
//SlowClock
`ifdef SLOWCLOCK
    `include "SlowClock.v"
`endif


module PPCSoC(
    input   original_clk,
    input   original_rst,
`ifdef BUTTON
    input   btn,
`endif
    output [7:0] leds     //! Onboard Leds to Debug.
);

// ----- PARAMETERS -----
//parameter TEXT_DATA_WIDTH = 32;
parameter TEXT_ADDR_WIDTH = 12; //12 = 1K
//parameter DATA_DATA_WIDTH = 8;
parameter DATA_ADDR_WIDTH = 13; 
//Max addr width 14 -> [7:0]4*4096 
//[1:0] select Byte from 0 to 3
//[13:2] 2**12 Select 1 of 4096 dirs


// ----- CLOCK -----
wire clk;

`ifdef BUTTON
    Debouncer DebouncerPPC(.clk(original_clk), .btn(btn), .btn_out(clk));
`elsif SLOWCLOCK
    SlowClock SlowClockPPC(.clk(original_clk), .slow_clk(clk));
`else
    assign clk = original_clk;
`endif

// ----- rst -----
// A little delay for sending the rst signal after startup.
// Explanation here: (ice40 BRAM reads incorrect values during
// first cycles).
// http://svn.clifford.at/handicraft/2017/ice40bramdelay/README
// On the ICE40-UP5K, 4096 cycles do not suffice (-> 65536 cycles)
    //Seems like no needed in my case
    wire rst = original_rst;
//When debugging dont delay rst
// `ifdef DEBUGINSTRUCTION
//     
// `else
//     reg [15:0] reset_cnt = 0;

//     /* verilator lint_off WIDTH */  
//     always @(posedge clk, posedge original_rst) begin
//         if(original_rst) begin
//             reset_cnt <= 0;
//         end else begin
//             reset_cnt <= reset_cnt + !rst;
//         end
//     end
//     wire rst = &reset_cnt;
// `endif


/***************************************************************************************************
//
 * Memory and memory interface
 * memory map:
 *   address[DATA_ADDR_WIDTH-1:2][13:2] RAM word address (4 Kb max). (ends at 0x0000.1000)
 *   address[DATA_ADDR_WIDTH-1+1] [14]   
 *      0: RAM
 *      1: IO page (1-hot)  (starts at 0x0000.4000)
 */ 

 // ----- MEMORY BUS -----
wire [DATA_ADDR_WIDTH:0] mem_address; //The two LSBs are ignored (using word addresses)
wire  [3:0] mem_mask;   // mem write mask and strobe /write Legal values are: 0001 0010 0100 1000 (select byte to write memory). wstrobe = |wmask
wire [31:0] mem_rdata;   // processor <- (mem and peripherals) 
wire [31:0] mem_wdata;   // processor -> (mem and peripherals)
wire        mem_rstrb;   // mem read strobe. Goes high to initiate memory read.
wire        mem_wstrb;   // mem write strobe. Goes high to write memory
//wire        mem_rbusy;   // processor <- (mem and peripherals). Stays high until a read transfer is finished.
//wire        mem_wbusy;   // processor <- (mem and peripherals). Stays high until a write transfer is finished.

//wire        mem_wstrb = |mem_mask; // mem_wstrb can't be deduced from mask as my design uses mask both for write and read. Instead get mem_strobe from MemWrite.

// Check if memory if writing to ram or IO
wire mem_address_is_io  =  mem_address[DATA_ADDR_WIDTH-1+1];
wire mem_address_is_ram = !mem_address[DATA_ADDR_WIDTH-1+1];

//IO wires
reg  [31:0] io_rdata; 
wire [31:0] io_wdata = mem_wdata;
wire        io_rstrb = mem_rstrb && mem_address_is_io;
wire        io_wstrb = mem_wstrb && mem_address_is_io;
wire [DATA_ADDR_WIDTH-3:0] io_word_address = mem_address[DATA_ADDR_WIDTH-3:0]; // NO OFFSET FOR io page
//wire	    io_rbusy; 
//wire      io_wbusy;

//IO busy
//assign      mem_rbusy = io_rbusy;
//assign      mem_wbusy = io_wbusy;


wire [DATA_ADDR_WIDTH-1:0] ram_word_address = mem_address[DATA_ADDR_WIDTH-1:0]; 

// ----- DATA MEMORY -----
// 0x0000.0000 - 0x0000.1000
wire [31:0] ram_rdata;
DataMemory #(
    .ADDR_WIDTH(DATA_ADDR_WIDTH)
)DataMemoryPPC(
    .clk(clk),
    .data_in(mem_wdata),
    .addr(ram_word_address), //MEMALUOutput[5:2]
    .we(mem_wstrb & mem_address_is_ram),
    .re(1'b1), //Always read. Value discarded if not usseful
    .MemoryByteSel(mem_mask),
    .data_out(ram_rdata)
);

// ----- LEDS -----
// 1Hot addressing bit: addr[0]
// 0x0000.4001
wire [31:0] leds_rdata;
LEDDriver LEDDriverPPCSoC(
    .clk(clk),
    .wdata(io_wdata[15:8]), //As it's in 0x4001 get the data from the 2nd (of 4 bytes 0x4000-0x4001-0x4002-0x4003) byte of 32 bits data memory 		
    .sel(io_word_address[0]),		  
    .wstrb(io_wstrb),
    .rstrb(io_rstrb),
    .rdata(leds_rdata),
    .LED(leds)
);

// io_rdata is latched
always @(posedge clk) begin
    io_rdata <= 0 | leds_rdata;
end

//Select mem_rdata
assign mem_rdata = mem_address_is_io ? io_rdata : ram_rdata;

PipelinedCore #(
    .TEXT_ADDR_WIDTH(TEXT_ADDR_WIDTH),
    .DATA_ADDR_WIDTH(DATA_ADDR_WIDTH+1) //+1 to have the last-half-bit addrs for IO
) PipelinedCore(
    .clk(clk),
    .rst(rst),
    .mem_addr(mem_address),
    .mem_wdata(mem_wdata),
    .mem_mask(mem_mask),
    .mem_rdata(mem_rdata),
    .mem_rstrb(mem_rstrb),
    .mem_wstrb(mem_wstrb)
    //.mem_rbusy(mem_rbusy),
    //.mem_wbusy(mem_wbusy),
);

endmodule
