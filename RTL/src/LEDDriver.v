// Modified from:
// femtorv32, a minimalistic RISC-V RV32I core
//       Bruno Levy, 2020-2021
//
// This file: driver for LEDs (does nearly nothing !)
//

module LEDDriver(	  
        input wire 	       clk, // system clock
        input wire [7:0]   wdata, // data to be written
        input wire 	       sel, // select (read/write ignored if low)	
        input wire 	       wstrb, // write strobe
        input wire 	       rstrb, // read strobe	
        output wire [31:0] rdata, // read data
        output wire [7:0]  LED    // LED pins
    );
      
reg [7:0] led_state;

initial begin
    led_state = 8'b00000000;
end

assign rdata = (sel ? {24'b0, led_state} : 32'b0);

always @(posedge clk) begin
    if(sel && wstrb) begin
        led_state <= wdata[7:0];		 
    `ifdef BENCH
        $display("****************** LEDs = %b", wdata[3:0]);
    `endif	 
    end
end

assign LED = led_state;

endmodule
