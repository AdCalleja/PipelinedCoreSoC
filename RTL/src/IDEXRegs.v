module IDEXRegs(
    input clk,
    input rst,
    input en,

    //Inputs
    input [31:0]    writePC,     //32 or 64 bits
    input [31:0]    writeReadData1,
    input [31:0]    writeReadData2,
    input [31:0]    writeImmediate,
    input [4:0]     writeRs1,
    input [4:0]     writeRs2,
    input [4:0]     writeRd,
    input           writeRegWrite,
    input [1:0]     writeWriteDataSrc,
    input [2:0]     writeStoreLoadSel,
    input           writeMemWrite,
    input           writeMemRead,
    input           writeALUSrc,
    input [1:0]     writeLuiAuipcSel,
    input [4:0]     writeALUCtrl,

    //DEBUG
    `ifdef DEBUGINSTRUCTION
        input [31:0]    writeInstruction,
        output [31:0]   readInstruction,
    `endif
    
    //Outputs
    output [31:0]   readPC,     //32 or 64 bits
    output [31:0]   readReadData1,
    output [31:0]   readReadData2,
    output [31:0]   readImmediate,
    output [4:0]    readRs1,
    output [4:0]    readRs2,
    output [4:0]    readRd,
    output          readRegWrite,
    output [1:0]    readWriteDataSrc,
    output [2:0]    readStoreLoadSel,
    output          readMemWrite,
    output          readMemRead,
    output          readALUSrc,
    output [1:0]     readLuiAuipcSel,
    output [4:0]    readALUCtrl
);

// Datapath
reg [31:0]  regPC;
reg [31:0]  regReadData1;
reg [31:0]  regReadData2;
reg [31:0]  regImmediate;
reg [4:0]   regRd;
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
//To EX
reg regALUSrc;
reg[ 1:0] regLuiAuipcSel;
reg [4:0] regALUCtrl;

// Forwarding
reg [4:0]   regRs1;
reg [4:0]   regRs2;

always @(posedge clk) begin : WriteRegs
    if (rst == 0) begin
        if (en == 1) begin
            regPC <= writePC;
            regReadData1 <= writeReadData1;
            regReadData2 <= writeReadData2;
            regImmediate <= writeImmediate;
            regRd <= writeRd;
            regRegWrite <= writeRegWrite;
            regWriteDataSrc <= writeWriteDataSrc;
            regStoreLoadSel <= writeStoreLoadSel;
            regMemWrite <= writeMemWrite;
            regMemRead <= writeMemRead;
            regALUSrc <= writeALUSrc;
            regLuiAuipcSel <= writeLuiAuipcSel;
            regALUCtrl <= writeALUCtrl;
            regRs1 <= writeRs1;
            regRs2 <= writeRs2;
            `ifdef DEBUGINSTRUCTION
                regInstruction <= writeInstruction;
            `endif
        end
    end else begin
        regPC <= 0;
        regReadData1 <= 0;
        regReadData2 <= 0;
        regImmediate <= 0;
        regRd <= 0;
        regRegWrite <= 0;
        regWriteDataSrc <= 0;
        regStoreLoadSel <= 0;
        regMemWrite <= 0;
        regMemRead <= 0;
        regALUSrc <= 0;
        regLuiAuipcSel <= 0;
        regALUCtrl <= 0;
        regRs1 <= 0;
        regRs2 <= 0;
        `ifdef DEBUGINSTRUCTION
            regInstruction <= 0;
        `endif
    end
end

assign readPC = regPC;
assign readReadData1 = regReadData1;
assign readReadData2 = regReadData2;
assign readImmediate = regImmediate;
assign readRd = regRd;
assign readRegWrite = regRegWrite;
assign readWriteDataSrc = regWriteDataSrc;
assign readStoreLoadSel = regStoreLoadSel;
assign readMemWrite = regMemWrite;
assign readMemRead = regMemRead;
assign readALUSrc = regALUSrc;
assign readLuiAuipcSel = regLuiAuipcSel;
assign readALUCtrl = regALUCtrl;
assign readRs1 = regRs1;
assign readRs2 = regRs2;
`ifdef DEBUGINSTRUCTION
    assign readInstruction = regInstruction;
`endif

endmodule
