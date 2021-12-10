module EXMEMRegs(
    input clk,
    input rst,
    input en,
    //Inputs
    input [31:0]    writePC,
    //input           writeZero,
    input [31:0]    writeALUOutput,
    input [31:0]    writeReadData2Forw,
    input [4:0]     writeRd,
    input           writeRegWrite,
    input [1:0]     writeWriteDataSrc,
    input [2:0]     writeStoreLoadSel,
    input           writeMemWrite,
    input           writeMemRead,
    
    //DEBUG
    `ifdef DEBUGINSTRUCTION
        input [31:0]    writeInstruction,
        output [31:0]   readInstruction,
    `endif

    //Outputs
    output [31:0]   readPC,
    //output          readZero,
    output [31:0]   readALUOutput,
    output [31:0]   readReadData2Forw,
    output [4:0]    readRd,
    output          readRegWrite,
    output [1:0]    readWriteDataSrc,
    output [2:0]    readStoreLoadSel,
    output          readMemWrite,
    output          readMemRead
);




// Datapath
reg [31:0]   regPC;
//reg          regZero;
reg [31:0]   regALUOutput;
reg [31:0]   regReadData2Forw;
reg [4:0]    regRd;
`ifdef DEBUGINSTRUCTION
    reg [31:0]  regInstruction;
`endif

// Control
//To WB
reg regRegWrite;
reg [1:0] regWriteDataSrc;
//To MEM
reg [2:0] regStoreLoadSel;
reg regMemWrite;
reg regMemRead;

always @(posedge clk) begin : WriteRegs
    if (rst == 0) begin
        if (en == 1) begin
            regPC <= writePC;
            //regZero <= writeZero;
            regALUOutput <= writeALUOutput;
            regReadData2Forw <= writeReadData2Forw;
            regRd <= writeRd;
            regRegWrite <= writeRegWrite;
            regWriteDataSrc <= writeWriteDataSrc;
            regStoreLoadSel <= writeStoreLoadSel;
            regMemWrite <= writeMemWrite;
            regMemRead <= writeMemRead;
            `ifdef DEBUGINSTRUCTION
                regInstruction <= writeInstruction;
            `endif

        end
    end else begin
        regPC <= 0;
        //regZero <= 0;
        regALUOutput <= 0;
        regReadData2Forw <= 0;
        regRd <= 0;
        regRegWrite <= 0;
        regWriteDataSrc <= 0;
        regStoreLoadSel <= 0;
        regMemWrite <= 0;
        regMemRead <= 0;
        `ifdef DEBUGINSTRUCTION
            regInstruction <= 0;
        `endif

    end
end

assign readPC = regPC;
//assign readZero = regZero;
assign readALUOutput = regALUOutput;
assign readReadData2Forw = regReadData2Forw;
assign readRd = regRd;
assign readRegWrite = regRegWrite;
assign readWriteDataSrc = regWriteDataSrc;
assign readStoreLoadSel = regStoreLoadSel;
assign readMemWrite = regMemWrite;
assign readMemRead = regMemRead;
`ifdef DEBUGINSTRUCTION
    assign readInstruction = regInstruction;
`endif

endmodule
