module StoreLogic(
    input [31:0]        Data,
    input [1:0]         ALUOutput,
    input [1:0]         DataType,
    output reg [31:0]   FixedData,
    output reg [3:0]    MemoryByteSel
);

reg [31:0] Byte0;
reg [31:0] Byte1;
reg [31:0] Byte2;
reg [31:0] Byte3;
reg [31:0] Half0;
reg [31:0] Half1;
reg [31:0] Byte;
reg [31:0] Half;
reg [31:0] Word;

always@(*)begin
    Byte0 = {24'b0,Data[7:0]};
    Byte1 = {16'b0,Data[7:0],8'b0};
    Byte2 = {8'b0,Data[7:0],16'b0};
    Byte3 = {Data[7:0],24'b0};
    Half0 = {16'b0,Data[15:0]};
    Half1 = {Data[15:0],16'b0};
    Word = Data;
    case(DataType)
        0:begin
            case (ALUOutput)
                0:begin 
                    Byte = Byte0;
                    MemoryByteSel = 4'b0001;
                end
                1: begin
                    Byte = Byte1;
                    MemoryByteSel = 4'b0010;
                end
                2: begin
                    Byte = Byte2;
                    MemoryByteSel = 4'b0100;
                end
                
                3: begin
                    Byte = Byte3;
                    MemoryByteSel = 4'b1000;
                end
                default:begin
                    Byte = 0;
                    MemoryByteSel = 4'b0000;
                end 
            endcase
            FixedData = Byte;
        end
        1:begin
            case (ALUOutput)
                0: begin
                    Half = Half0;
                    MemoryByteSel = 4'b0011;
                end
                
                2: begin
                    Half = Half1;
                    MemoryByteSel = 4'b1100;
                end
                
                default: begin
                    Half = 0;
                    MemoryByteSel = 4'b0000;
                end
                
            endcase
            FixedData = Half;
        end
        2:begin
            FixedData = Word;
            MemoryByteSel = 4'b1111;
        end
        default:begin
            FixedData = 0;
            MemoryByteSel = 4'b0000;
        end
    endcase

end
endmodule
