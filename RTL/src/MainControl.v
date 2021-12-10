//! Main control unit. Generate control lanes based on the Opcode selected
//! and ALUOp to ALUControl.v as a 2 levels control abstraction.
module MainControl(
    input [31:0]     Instruction,     //! Instruction
    output reg          RegWrite,   //! Enable Register File WriteEn
    output reg [1:0]    WriteDataSrc,  //! Select the source to Register File WriteData between
    output reg [2:0]    StoreLoadSel,
    output reg          MemWrite,   //! Enable Data Memory write
    output reg          MemRead,    //! Enable Data Memory read
    output reg          ALUSrc,     //! Select the source to ALU input ***b*** between **RegisterFile / Immediate**
    output reg          PCJumpSrc,
    output reg [1:0]    LuiAuipcSel,
    output reg          DoBranch,     //! Select new branching program counter (if ALU also sets zero lane)
    output reg [4:0]    ALUCtrl      //! Previous instruction decodification to simplify ALUControl.
);
wire [6:0] Opcode = Instruction[6:0];
wire Func7 = Instruction[30];
wire [2:0] Func3 = Instruction[14:12];

always@(*)begin : OpcodeDecode
    case(Opcode)
    //R-type
    7'b0110011:  begin
        RegWrite = 1;
        WriteDataSrc = 0;
        StoreLoadSel = 0;    //Don't care
        MemWrite = 0;
        MemRead = 0;
        ALUSrc = 0;
        PCJumpSrc = 0;
        LuiAuipcSel = 0;
        DoBranch = 0;
        case(Func3)
        3'b000: case(Func7)
                1'b0: ALUCtrl = 0;  //ADD
                1'b1: ALUCtrl = 1;  //SUB
                endcase
        3'b001: ALUCtrl = 2;        //SLL
        3'b010: ALUCtrl = 3;        //SLT
        3'b011: ALUCtrl = 4;        //SLTU
        3'b100: ALUCtrl = 5;        //XOR
        3'b101: case(Func7)
                1'b0: ALUCtrl = 6;  //SRL
                1'b1: ALUCtrl = 7;  //SRA
                endcase
        3'b110: ALUCtrl = 8;       //OR
        3'b111: ALUCtrl = 9;       //AND
        default: ALUCtrl = 0;
        endcase
    end
    //I -type Immediates
    7'b0010011:  begin
        RegWrite = 1;
        WriteDataSrc = 0;
        StoreLoadSel = 0;    //Don't care
        MemWrite = 0;
        MemRead = 0;
        ALUSrc = 1;
        PCJumpSrc = 0;
        LuiAuipcSel = 0;
        DoBranch = 0;
        case(Func3)
        3'b000: ALUCtrl = 0;    //ADDI
        3'b010: ALUCtrl = 3;    //SLTI
        3'b011: ALUCtrl = 4;    //SLTIU
        3'b100: ALUCtrl = 5;    //XORI
        3'b110: ALUCtrl = 8;    //ORI
        3'b111: ALUCtrl = 9;    //ANDI
        3'b001: ALUCtrl = 2;    //SLLI
        3'b101: case(Func7)
                1'b0: ALUCtrl = 6;  //SRLI
                1'b1: ALUCtrl = 7;  //SRAI
                endcase
        endcase
    end
    //Lw
    7'b0000011:  begin
        RegWrite = 1;
        WriteDataSrc = 1;
        StoreLoadSel = Func3;    //Use Func3 to Select Size and Align Address
        MemWrite = 0;
        MemRead = 1;
        ALUSrc = 1;
        PCJumpSrc = 0;
        LuiAuipcSel = 0;
        DoBranch = 0;
        ALUCtrl = 0;    //Add to get Data Memory Address
    end
    //Sw
    7'b0100011:  begin
        RegWrite = 0;
        WriteDataSrc = 0;
        StoreLoadSel = Func3;    //Use Func3 to Select Size and Align Address
        MemWrite = 1;
        MemRead = 0;
        ALUSrc = 1;
        PCJumpSrc = 0;
        LuiAuipcSel = 0;
        DoBranch = 0;
        ALUCtrl = 0;    //Add to get datamem. dir
    end
    //Branches
    7'b1100011:  begin
        RegWrite = 0;
        WriteDataSrc = 0;
        StoreLoadSel = 0;    //Don't care
        MemWrite = 0;
        MemRead = 0;
        ALUSrc = 0;
        PCJumpSrc = 0;
        LuiAuipcSel = 0;
        DoBranch = 1;
        case(Func3)
        3'b000: ALUCtrl = 26; //BEQ
        3'b001: ALUCtrl = 27; //BNE
        3'b100: ALUCtrl = 28; //BLT
        3'b101: ALUCtrl = 29; //BGE
        3'b110: ALUCtrl = 30; //BLTU
        3'b111: ALUCtrl = 31; //BGEU
        default: ALUCtrl = 0;
        endcase
    end
    //Jal
    7'b1101111:  begin
        RegWrite = 1;       //Enable writing PC to RegisterFile
        WriteDataSrc = 2;   //Select PC as WriteData
        StoreLoadSel = 0;    //Don't care
        MemWrite = 0;       //Don't write Data Memory
        MemRead = 0;        //Don't read Data Memory
        ALUSrc = 0;         //Don't care about ALU
        PCJumpSrc = 0;      //Target address = PC + Immediate
        LuiAuipcSel = 0;
        DoBranch = 0;       //Not a Branch
        ALUCtrl = 0;        //Don't case about ALU
    end
    //Jalr
    7'b1100111:  begin
        RegWrite = 1;       //Enable writing PC to RegisterFile
        WriteDataSrc = 2;   //Select PC as WriteData
        StoreLoadSel = 0;    //Don't care
        MemWrite = 0;       //Don't write Data Memory
        MemRead = 0;        //Don't read Data Memory
        ALUSrc = 0;         //Don't care about ALU
        PCJumpSrc = 1;      //Target address = [rs1]ReadData1 + immediate
        LuiAuipcSel = 0;
        DoBranch = 0;       //Not a Branch
        ALUCtrl = 0;        //Don't case about ALU
    end
    //Lui
    7'b0110111:  begin
        RegWrite = 1;       //Enable writing the immediate to RegisterFile
        WriteDataSrc = 0;   //Select ALU as WriteData
        StoreLoadSel = 0;    //Don't care
        MemWrite = 0;       //Don't write Data Memory
        MemRead = 0;        //Don't read Data Memory
        ALUSrc = 1;         //Selects immediate as the input to ALUB
        PCJumpSrc = 0;      //Don't care
        LuiAuipcSel = 1;    //Selects 0 as the input to ALUA. 
        DoBranch = 0;       //Not a Branch
        ALUCtrl = 0;        //ADD: ALU 0 + ALUB immediate
    end
    //Auipc
    7'b0010111:  begin
        RegWrite = 1;       //Enable writing the immediate to RegisterFile
        WriteDataSrc = 0;   //Select ALU as WriteData
        StoreLoadSel = 0;    //Don't care
        MemWrite = 0;       //Don't write Data Memory
        MemRead = 0;        //Don't read Data Memory
        ALUSrc = 1;         //Selects immediate as the input to ALUB
        PCJumpSrc = 0;      //Don't care
        LuiAuipcSel = 2;    //Selects PC as the input to ALUA. 
        DoBranch = 0;       //Not a Branch
        ALUCtrl = 0;        //ADD: ALU 0 + ALUB immediate
    end
    default:  begin
        RegWrite = 0;
        WriteDataSrc = 0;
        StoreLoadSel = 0;
        MemWrite = 0;
        MemRead = 0;
        ALUSrc = 0;
        PCJumpSrc = 0;
        LuiAuipcSel = 0;
        DoBranch = 0;
        ALUCtrl = 0; 
    end
    endcase
end

endmodule
