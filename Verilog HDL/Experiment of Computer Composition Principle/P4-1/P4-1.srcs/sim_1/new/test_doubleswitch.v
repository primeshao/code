`timescale 1ns/100ps
module test_doubleswitch();
  reg clk_1Hz,a,b;
  wire y;
  doubleswitch_dataflow u0(a,b,y);
  always #100 clk_1Hz = ~clk_1Hz ;
  initial
  begin
  	 clk_1Hz=0;
   	 a=0;b=0;
   	 #200;
  	 a=0;b=1;  
  	 #200;
  	 a=1;b=0;  
  	 #200;
  	 a=1;b=1;   
  end
endmodule