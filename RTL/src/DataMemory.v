`include "bram0.v"
`include "bram1.v"
`include "bram2.v"
`include "bram3.v"
module DataMemory #(
  //parameter BYTE_WIDTH = 8,          //width of data bus
  parameter ADDR_WIDTH = 14           //width of addresses buses
)(
  input                     clk,   //clock signal
  input  [31:0]             data_in,   //[(BYTE_WIDTH-1):0] data_in,  //data to be written
  input  [(ADDR_WIDTH-1):0] addr,  //address for write/read operation
  input                     we,    //write enable signal
  input                     re,    //read enable signal
  input [3:0]               MemoryByteSel,
  output [31:0]             data_out      //read data
);

//Defined independent BRAM modules to tell filedir without having to used a parameter
//that leads to error because it uses the default one before.
//That could be solved by using -defer in readverilog but create many problems also
bram0 #(
  .ADDR_WIDTH(ADDR_WIDTH)
)ram0(
  .CLK(clk),
  .W_ADDR(addr),
  .R_ADDR(addr),
  .WRITE_EN(we & MemoryByteSel[0]),
  .READ_EN(re & MemoryByteSel[0]),
  .DIN(data_in[7:0]),
  .DOUT(data_out[7:0])
);

bram1 #(
  .ADDR_WIDTH(ADDR_WIDTH)
  ) ram1(
  .CLK(clk),
  .W_ADDR(addr),
  .R_ADDR(addr),
  .WRITE_EN(we & MemoryByteSel[1]),
  .READ_EN(re & MemoryByteSel[1]),
  .DIN(data_in[15:8]),
  .DOUT(data_out[15:8])
);
bram2 #(
  .ADDR_WIDTH(ADDR_WIDTH)
) ram2(
  .CLK(clk),
  .W_ADDR(addr),
  .R_ADDR(addr),
  .WRITE_EN(we & MemoryByteSel[2]),
  .READ_EN(re & MemoryByteSel[2]),
  .DIN(data_in[23:16]),
  .DOUT(data_out[23:16])
);
bram3 #(
  .ADDR_WIDTH(ADDR_WIDTH)
) ram3(
  .CLK(clk),
  .W_ADDR(addr),
  .R_ADDR(addr),
  .WRITE_EN(we & MemoryByteSel[3]),
  .READ_EN(re & MemoryByteSel[3]),
  .DIN(data_in[31:24]),
  .DOUT(data_out[31:24])
);



// reg [7:0] ram [0:2**(ADDR_WIDTH-3)][0:3];
// // reg [BYTE_WIDTH-1:0] ram0 [2**(ADDR_WIDTH-3):0]; //Depth = [2**ADDR_WIDTH-1:0]
// // reg [BYTE_WIDTH-1:0] ram1 [2**(ADDR_WIDTH-3):0];
// // reg [BYTE_WIDTH-1:0] ram2 [2**(ADDR_WIDTH-3):0];
// // reg [BYTE_WIDTH-1:0] ram3 [2**(ADDR_WIDTH-3):0];
// //Height of the banck is calculates based on the addr width - 2. The lower bits used to select the byte colum.
// //reg [ADDR_WIDTH-1:0] addr_r;
// reg [7:0] Byte0;
// reg [7:0] Byte1;
// reg [7:0] Byte2;
// reg [7:0] Byte3;

// //Initializa RAM
// integer idx;
// integer i,j;

// initial begin
//   $readmemh("/home/adrian/codigo/RISC-V/PipelinedCoreRISCV/RTL/src/datamemoryverilog.txt", ram);
//   // $readmemh("/home/adrian/codigo/RISC-V/PipelinedCoreRISCV/RTL/src/ram1.txt", ram1);
//   // $readmemh("/home/adrian/codigo/RISC-V/PipelinedCoreRISCV/RTL/src/ram2.txt", ram2);
//   // $readmemh("/home/adrian/codigo/RISC-V/PipelinedCoreRISCV/RTL/src/ram3.txt", ram3);
//   $dumpfile("PipelinedCore_tb.vcd");

//   // for (i = 0; i < 10; i = i + 1) begin
//   //   for (j = 0; j < 4; j = j + 1) begin
//   //      $dumpvars(0, ram[i][j]);
//   //   end  
//   // end
//   // for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, ram[idx][0]);
//   // for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, ram[idx][0]);
//   // for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, ram[0][idx]);
//   // for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, ram[0][idx]);

//   // for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, ram0[idx]);
//   // for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, ram1[idx]);
//   // for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, ram2[idx]);
//   // for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, ram3[idx]);
// end


// always @(negedge clk) begin //WRITE
//   if (we) begin
//     if(MemoryByteSel[0]) ram[addr[ADDR_WIDTH-1:2]][0] <= data_in[7:0];
//     if(MemoryByteSel[1]) ram[addr[ADDR_WIDTH-1:2]][1] <= data_in[15:8];
//     if(MemoryByteSel[2]) ram[addr[ADDR_WIDTH-1:2]][2] <= data_in[23:16];
//     if(MemoryByteSel[3]) ram[addr[ADDR_WIDTH-1:2]][3] <= data_in[31:24];
//   end
  
// end
// always @(negedge clk) begin //WRITE
//   if (re) begin
//     if(MemoryByteSel[0]) Byte0 <= ram[addr[ADDR_WIDTH-1:2]][0];
//     if(MemoryByteSel[1]) Byte1 <= ram[addr[ADDR_WIDTH-1:2]][1];
//     if(MemoryByteSel[2]) Byte2 <= ram[addr[ADDR_WIDTH-1:2]][2];
//     if(MemoryByteSel[3]) Byte3 <= ram[addr[ADDR_WIDTH-1:2]][3];
//   end
  
// end



// assign data_out = {Byte3,Byte2,Byte1,Byte0};

endmodule
