//IceStick PLL
// PLL: 
//    SB_PLL40_CORE #(
//       .FEEDBACK_PATH("SIMPLE"),
//       .PLLOUT_SELECT("GENCLK"),
//       .DIVR(4'b0000),
//       //.DIVF(7'b0110100), .DIVQ(3'b011), // 80 MHz
//       //.DIVF(7'b0110001), .DIVQ(3'b011), // 75 MHz
//         .DIVF(7'b1001111), .DIVQ(3'b100), // 60 MHz
//       //.DIVF(7'b0110100), .DIVQ(3'b100), // 40 MHz
//       //.DIVF(7'b1001111), .DIVQ(3'b101), // 30 MHz
//       .FILTER_RANGE(3'b001),
//    ) pll (
//       .REFERENCECLK(pclk),
//       .PLLOUTCORE(clk),
//       .RESETB(1'b1),
//       .BYPASS(1'b0)
//    );

module LatticeDataMemory #(
    parameter BYTE_WIDTH = 8,          //width of data bus
    parameter ADDR_WIDTH = 9           //width of addresses buses
  )(
    input                     clk,   //clock signal
    input  [31:0]             data_in,   //[(BYTE_WIDTH-1):0] data_in,  //data to be written
    input  [(ADDR_WIDTH-1):0] addr,  //address for write/read operation
    input                     we,    //write enable signal
    input                     re,    //read enable signal
    input [3:0]               MemoryByteSel,
    output [31:0] data_out      //read data
  );
  
  wire [3:0] csen;
  assign csen = we ? MemoryByteSel : 0;

// LatticeDataMemory RAM(
//     .clk(clk),
//     .data_in(StoreFixed),
//     .addr(MEMALUOutput[DATA_ADDR_WIDTH-1:0]), //MEMALUOutput[5:2]
//     .we(MemWrite),
//     .re(MemRead),
//     .MemoryByteSel(MemoryByteSel),
//     .data_out(LoadToFix)
// );


SB_RAM40_4K #(
    .READ_MODE(1),
    .WRITE_MODE(1)
)ram0 (
 .RDATA(data_out[7:0]),
 .RADDR(addr),
 .RCLK(clk),
 .RCLKE(1),
 .RE(re),
 .WADDR(addr),
 .WCLK(clk),
 .WCLKE(1),
 .WDATA(data_in[7:0]),
 .WE(csen[0])
);
SB_RAM40_4K #(
    .READ_MODE(1),
    .WRITE_MODE(1)
) ram1 (
 .RDATA(data_out[15:8]),
 .RADDR(addr),
 .RCLK(clk),
 .RCLKE(1),
 .RE(re),
 .WADDR(addr),
 .WCLK(clk),
 .WCLKE(1),
 .WDATA(data_in[15:8]),
 .WE(csen[1])
);
SB_RAM40_4K #(
    .READ_MODE(1),
    .WRITE_MODE(1)
) ram2 (
 .RDATA(data_out[23:16]),
 .RADDR(addr),
 .RCLK(clk),
 .RCLKE(1),
 .RE(re),
 .WADDR(addr),
 .WCLK(clk),
 .WCLKE(1),
 .WDATA(data_in[23:16]),
 .WE(csen[2])
);
SB_RAM40_4K #(
    .READ_MODE(1),
    .WRITE_MODE(1)
) ram3 (
 .RDATA(data_out[31:24]),
 .RADDR(addr),
 .RCLK(clk),
 .RCLKE(1),
 .RE(re),
 .WADDR(addr),
 .WCLK(clk),
 .WCLKE(1),
 .WDATA(data_in[31:24]),
 .WE(csen[3])
);

endmodule
