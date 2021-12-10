module HazardDetection(
    input [31:0]    Instruction,
    input           MemReadEX,  //ALU Stall by Load.  Stall until it can be forwarded from MEM/WB. Used for branch bubbles.
    input           RegWriteEX, //BranchALU RTYPE and LOAD1
    input           MemRead,    //BranchALU LOAD2
    input [4:0]     EXRd,
    input [4:0]     MEMRd,    
    input           DoBranch,   //Knows a Branch needs to be calculates in ID. Stall until 1.R-type op. is made in ALU and forward from EX/MEM 2.Load and stall 2 cycles and forward from MEMWB.
    input           PCSrc,
    output reg      PCWrite,
    output reg      IFIDWrite,
    output reg      Stall,
    output reg      IFIDFlush
);

wire [4:0] Rs1;
wire [4:0] Rs2;

assign Rs1 = Instruction[19:15];
assign Rs2 = Instruction[24:20];

always@(*)begin : StallingUnit
    if (
    //ALU Op. has to stall next inst. in ID then both move
    (MemReadEX && ((EXRd == Rs1) || (EXRd == Rs2))) ||                      //ALU Stall cause by Load. (Sequence: Stall and lw moves to MEM. Both move, and forward from MEM/WB to ALU)
    //Branch has to stall next inst. in ID but don't move next ClockCycle. 
    (DoBranch &&  RegWriteEX && ((EXRd == Rs1) || (EXRd == Rs2))) ||      //BranchALU R-TYPE Stall AND Load Stall 1   
    (DoBranch &&  MemRead && ((MEMRd == Rs1) || (MEMRd == Rs2)))            //BranchALU Load Stall 2 (Can't forward lw from EX/MEM)
    ) begin
        //Stall
        PCWrite = 0;
        IFIDWrite = 0;
        Stall = 1;
    end else begin
        //Un-Stall
        PCWrite = 1;
        IFIDWrite = 1;
        Stall = 0;
    end
end

//Branching control: No prediction unit ASSUMES BRANCH NOT TAKEN
always@(*)begin : FlusingUnit
    if(PCSrc) begin
        IFIDFlush = 1;
    end else begin
        IFIDFlush = 0;
    end
end

endmodule
