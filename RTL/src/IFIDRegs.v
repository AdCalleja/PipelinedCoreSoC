module IFIDRegs(
    input clk,
    input rst,
    input en,
    input [31:0]    writePC,     //32 or 64 bits
    input [31:0]    writeInstruction,
    output [31:0]    readPC,     //32 or 64 bits
    output [31:0]    readInstruction
);

reg [31:0] regPC;
reg [31:0] regInstruction;

always @(posedge clk) begin : WriteRegs
    if (rst == 0) begin
        if (en == 1) begin
            regPC <= writePC;
            regInstruction <= writeInstruction;
        end
    end else begin
        regPC <= 0;
        regInstruction <= 0;
    end
end

assign readPC = regPC;
assign readInstruction = regInstruction;

endmodule
