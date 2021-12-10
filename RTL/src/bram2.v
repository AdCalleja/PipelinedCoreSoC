module bram2#(
    parameter ADDR_WIDTH = 13       //width of addresses buses
)(
input CLK,
input [(ADDR_WIDTH-1):0] W_ADDR,
input [(ADDR_WIDTH-1):0] R_ADDR,
input WRITE_EN,
input READ_EN,
input [7:0] DIN,
output reg [7:0] DOUT
);

reg [7:0] mem [2**(ADDR_WIDTH-3):0];

integer idx;
initial begin
    $readmemh("/home/adrian/codigo/RISC-V/PPCSoC/RTL/build/output/data2.txt", mem);
    $dumpfile("PPCSoC_tb.vcd");
    //for (idx = 4070; idx < 4095; idx = idx + 1) $dumpvars(0, mem[idx]);
    $dumpvars(0, mem[200]);
end
always @(negedge CLK) begin
    if (WRITE_EN)
    mem[W_ADDR[ADDR_WIDTH-1:2]] <= DIN;
    if (READ_EN)
    DOUT <= mem[R_ADDR[ADDR_WIDTH-1:2]];
    end
endmodule
