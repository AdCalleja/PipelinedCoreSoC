`timescale 1ns / 1ns
`include "PPCSoC.v"

module PPCSoC_tb();

reg original_clk;
reg original_rst;
//reg btn;
wire [7:0] leds;

PPCSoC PPCTB(
    .original_clk(original_clk),
    .original_rst(original_rst),
// `ifdef BUTTON
//     .btn(btn),
// `endif
    .leds(leds)
);

always #1 original_clk = ~original_clk;

initial begin
    $dumpfile("PPCSoC_tb.vcd");
    $dumpvars(0,PPCSoC_tb);
    

    original_clk = 0;
    original_rst = 0;
    //btn = 0;
    #10;
    original_rst = 1;
    #180000;
    original_rst = 0;
    #10000 $finish;
    
end



//always begin
    // #305 btn = !btn;
//end

endmodule
