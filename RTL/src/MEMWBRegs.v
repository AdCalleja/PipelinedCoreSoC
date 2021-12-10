module MEMWBRegs(
    input clk,
    input rst,
    input en,
    //Inputs
    input [31:0]    writePC,
    input [31:0]    writeALUOutput,
    input [31:0]    writeDataOutput,
    input [4:0]     writeRd,
    input           writeRegWrite,
    input [1:0]     writeWriteDataSrc,

    //DEBUG
    `ifdef DEBUGINSTRUCTION
        input [31:0]    writeInstruction,
        output [31:0]   readInstruction,
    `endif

    //Outputs
    output [31:0]   readPC,
    output [31:0]    readALUOutput,
    output [31:0]    readDataOutput,
    output [4:0]     readRd,
    output           readRegWrite,
    output [1:0]    readWriteDataSrc
);




// Datapath
reg [31:0]  regPC;
reg [31:0]  regALUOutput;
reg [31:0]  regDataOutput;
reg [4:0]   regRd;
`ifdef DEBUGINSTRUCTION
    reg [31:0]  regInstruction;
`endif

// Control
reg         regRegWrite;
reg [1:0] regWriteDataSrc;



always @(posedge clk) begin : WriteRegs
    if (rst == 0) begin
        if (en == 1) begin
            regPC <= writePC;
            regALUOutput <= writeALUOutput;
            regDataOutput <= writeDataOutput;
            regRd <= writeRd;
            regRegWrite <= writeRegWrite;
            regWriteDataSrc <= writeWriteDataSrc;
            `ifdef DEBUGINSTRUCTION
                regInstruction <= writeInstruction;
            `endif
        end
    end else begin
        regPC <= 0;
        regALUOutput <= 0;
        regDataOutput <= 0;
        regRd <= 0;
        regRegWrite <= 0;
        regWriteDataSrc <= 0;
        `ifdef DEBUGINSTRUCTION
            regInstruction <= 0;
        `endif

    end
end
assign readPC = regPC;
assign readALUOutput = regALUOutput;
assign readDataOutput = regDataOutput;
assign readRd = regRd;
assign readRegWrite = regRegWrite;
assign readWriteDataSrc = regWriteDataSrc;
`ifdef DEBUGINSTRUCTION
    assign readInstruction = regInstruction;
`endif

endmodule
