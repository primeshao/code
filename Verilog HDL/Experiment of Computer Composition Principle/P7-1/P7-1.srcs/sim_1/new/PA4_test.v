`timescale 1ns/100ps
module PA4_test();
  reg clk_1Hz,cin;
  reg [3:0]a,b;
  wire [3:0]s;
  wire cout;
  PA4 u0(a,b,cin,s,cout);
  always #50 clk_1Hz = ~clk_1Hz ;
  initial
  begin
	 clk_1Hz=0;cin=0;
	 a=4'b0000;b=4'b1010;
	 #100;
	 a=4'b1000;b=4'b1110;  
	 #100;
	 a=4'b0100;b=4'b1000;  
	 #100;
	 a=4'b0010;b=4'b1011;   
	 end
endmodule
