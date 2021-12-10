module LoadLogic(
    input [31:0]        Data,
    input [1:0]         ALUOutput,
    input [1:0]         DataType,
    input               Unsigned,
    output reg [31:0]   FixedData
);

reg [7:0] Byte0;
reg [7:0] Byte1;
reg [7:0] Byte2;
reg [7:0] Byte3;
reg [15:0] Half0;
reg [15:0] Half1;
reg [7:0] Byte;
reg [15:0] Half;
reg [31:0] Word;

always@(*)begin
    Byte0 = Data[7:0];
    Byte1 = Data[15:8];
    Byte2 = Data[23:16];
    Byte3 = Data[31:24];
    Half0 = Data[15:0];
    Half1 = Data[31:16];
    Word = Data;
    case(DataType)
        0:begin
            case (ALUOutput)
                0:begin 
                    Byte = Byte0;
                end
                1: begin
                    Byte = Byte1;
                    
                end
                
                2: begin
                    Byte = Byte2;
                end
                
                3: begin
                    Byte = Byte3;
                end
                default:begin
                    Byte = 0;
                end 
            endcase
            if (Unsigned == 0) begin
                FixedData = {{24{Byte[7]}},Byte};
            end else begin
                FixedData = {24'b0,Byte};
            end
        end
        1:begin
            case (ALUOutput)
                0: begin
                    Half = Half0;
                end
                
                2: begin
                    Half = Half1;
                end
                
                default: begin
                    Half = 0;
                end
            endcase
            if (Unsigned == 0) begin
                FixedData = {{16{Half[15]}},Half};
            end else begin
                FixedData = {16'b0,Half};
            end
        end
        2:begin
            FixedData = Word;
        end
        default:begin
            FixedData = 0;
        end
    endcase

end
endmodule
