module TextMemory #(        //width of data bus
  parameter TEXT_ADDR_WIDTH='h800,
  parameter ADDR_WIDTH=12           //width of addresses buses
)(
  //input CLK,  
  input  [(ADDR_WIDTH-1):0] R_ADDR,  //address for write/read operation
  output reg [(32-1):0] DOUT      //read data
);


//! Internal memory instantation
reg [(32-1):0] rom[2**ADDR_WIDTH-1:0];
initial begin
  //$display(ramN);
  $readmemh("../build/output/text.txt", rom, TEXT_ADDR_WIDTH[ADDR_WIDTH:2]);
  $dumpfile("PPCSoC_tb.vcd");
  //for (idx = 0; idx < 10; idx = idx + 1) $dumpvars(0, mem[idx]);
end

//The Lattice FPGA i am using can't generate 32-bits wide BRAM
//assign DOUT = rom[R_ADDR];
always@(*) begin
  DOUT = rom[R_ADDR];
end

endmodule

// always@(*)
// begin
//     case(addr)

//       // Store Load Test
//       1: data_out = 32'h10002503;
//       2: data_out = 32'h10001583;
//       3: data_out = 32'h10201583;
//       4: data_out = 32'h10000603;
//       5: data_out = 32'h10100603;
//       6: data_out = 32'h10200603;
//       7: data_out = 32'h10300603;
//       8: data_out = 32'h10005683;
//       9: data_out = 32'h10205683;
//       10: data_out = 32'h10004703;
//       11: data_out = 32'h10104703;
//       12: data_out = 32'h10204703;
//       13: data_out = 32'h10304703;
//       14: data_out = 32'h100007b7;
//       15: data_out = 32'hfff78793;
//       16: data_out = 32'h00f02023;
//       17: data_out = 32'h00f01223;
//       18: data_out = 32'h00f012a3;
//       19: data_out = 32'h00f01323;
//       20: data_out = 32'h00f013a3;
//       21: data_out = 32'h00f00423;
//       22: data_out = 32'h00f004a3;
//       23: data_out = 32'h00f00523;
//       24: data_out = 32'h00f005a3;


//       // //Lui Auipc Test
//       // 0: data_out = 32'hfffff537;
//       // 1: data_out = 32'h00004597;

//       // // Jumps Test. Based on Immediates Test with Jal and Jalr jumping above it all
//       // 0: data_out = 32'h00002883;
//       // 1: data_out = 32'h01c882e7; //Jalr, jump to Jal
//       // 2: data_out = 32'h00150513;
//       // 3: data_out = 32'h00253593;
//       // 4: data_out = 32'h00053593;
//       // 5: data_out = 32'hffb58613;
//       // 6: data_out = 32'hfff62693;
//       // 7: data_out = 32'h022000ef; //Jal, jump to last instruction
//       // 8: data_out = 32'hff662693;
//       // 9: data_out = 32'h00564713;
//       // 10: data_out = 32'h00566793;
//       // 11: data_out = 32'h00567813;
//       // 12: data_out = 32'h80088893;
//       // 13: data_out = 32'h41f8d893;
//       // 14: data_out = 32'h01f89893;
//       // 15: data_out = 32'h01f8d893;

//       // // Immediates Test
//       // 0: data_out = 32'h00150513;
//       // 1: data_out = 32'h00253593;
//       // 2: data_out = 32'h00053593;
//       // 3: data_out = 32'hffb58613;
//       // 4: data_out = 32'hfff62693;
//       // 5: data_out = 32'hff662693;
//       // 6: data_out = 32'h00564713;
//       // 7: data_out = 32'h00566793;
//       // 8: data_out = 32'h00567813;
//       // 9: data_out = 32'h80088893;
//       // 10: data_out = 32'h41f8d893;
//       // 11: data_out = 32'h01f89893;
//       // 12: data_out = 32'h01f8d893;

//       // //Branching Test
//       // 0: data_out = 32'h00052503;
//       // 1: data_out = 32'h0045a583;
//       // 2: data_out = 32'h00862603;
//       // 3: data_out = 32'h00b51863;
//       // 4: data_out = 32'h00000013;
//       // 5: data_out = 32'h00000013;
//       // 6: data_out = 32'h00000013;
//       // 7: data_out = 32'h00a64863;
//       // 11: data_out = 32'h00a55863;
//       // 15: data_out = 32'h00c55863;
//       // 19: data_out = 32'h00c56863;
//       // 23: data_out = 32'h00a67863;
//       // 27: data_out = 32'h00a51a63;
//       // 28: data_out = 32'h00c54863;
//       // 29: data_out = 32'h00a65663;
//       // 30: data_out = 32'h00a66463;
//       // 31: data_out = 32'h00c57263;
//       // 35: data_out = 32'h00a2a423;

//       // //RType Test
//       // 0: data_out = 32'h00052503;
//       // 1: data_out = 32'h0045a583;
//       // 2: data_out = 32'h00b51633;
//       // 3: data_out = 32'h00b526b3;
//       // 4: data_out = 32'h00a62733;
//       // 5: data_out = 32'h00a63733;
//       // 6: data_out = 32'h00b657b3;
//       // 7: data_out = 32'h40b65833;
//       // 8: data_out = 32'h00b848b3;

//       // //TestASM
//       // 0: data_out = 32'h00052503;
//       // 1: data_out = 32'h0045a583;
//       // 2: data_out = 32'h00b50633;
//       // 3: data_out = 32'h00c2a423;
//       // 4: data_out = 32'h02b60063;
//       // 5: data_out = 32'h40b606b3;
//       // 6: data_out = 32'h40d60633;
//       // 7: data_out = 32'h00b60a63;
//       // 8: data_out = 32'h00000013;
//       // 9: data_out = 32'h00000013;
//       // 10: data_out = 32'h00000013;
//       // 11: data_out = 32'h00000013;
//       // 12: data_out = 32'h00c6f6b3;  //EQUAL
//       // 13: data_out = 32'h00c6e733;
//       // 14: data_out = 32'h0046a683;
//       // 15: data_out = 32'h00d70a63;
//       // 16: data_out = 32'h00000013;
//       // 17: data_out = 32'h00000013;
//       // 18: data_out = 32'h00000013;
//       // 19: data_out = 32'h00000013;
//       // 20: data_out = 32'h00d707b3;  //LWBRANCH



//         default: data_out = 32'h00000000;
//     endcase
// end
// endmodule
