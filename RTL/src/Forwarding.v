module Forwarding(
    input [4:0]     Rs1,
    input [4:0]     Rs2,
    input [4:0]     MEMRd,
    input [4:0]     WBRd,
    input           RegWriteMEM,
    input           RegWrite,
    output reg [1:0] ForwardA,
    output reg [1:0] ForwardB
);
always@(*) begin : ForwardingComb

    // INPUT A
    if (RegWriteMEM && (MEMRd != 0) && (MEMRd == Rs1) && (MEMRd == Rs1))begin
        //EX Hazard
        ForwardA = 2'b01;
    end else if (RegWrite && (WBRd != 0) && (WBRd == Rs1) && (WBRd == Rs1))begin
        //MEM Hazard
        ForwardA = 2'b10;
    end else begin
        //RegFile 
        ForwardA = 2'b00;
    end
    
    // INPUT B
    if (RegWriteMEM && (MEMRd != 0) && (MEMRd == Rs2) && (MEMRd == Rs2))begin
        //EX Hazard
        ForwardB = 2'b01;
    end else if (RegWrite && (WBRd != 0) && (WBRd == Rs2) && (WBRd == Rs2))begin
        //MEM Hazard
        ForwardB = 2'b10;
    end else begin
        //RegFile 
        ForwardB = 2'b00;
    end
    
    
end
endmodule
