`timescale 1ns/100ps
module test_adder();
  reg clk_1Hz,op;
  reg [3:0]a,b;
  wire  [3:0]s;
  wire cout;
  adder u0(a,b,op,s,cout);
  always #10 clk_1Hz = ~clk_1Hz ;
  initial
  begin
    clk_1Hz=0;
    #20;
    a=4'b1110;b=4'b1011;op=1'b0;
    #20;
    a=4'b1110;b=4'b1011;op=1'b1;
    #20;
    a=4'b1010;b=4'b1001;op=1'b0;
    #20;
    a=4'b0010;b=4'b1011;op=1'b1;
    #20;
    a=4'b1010;b=4'b1011;op=1'b0;
    #20;
    a=4'b1100;b=4'b0011;op=1'b1;
    #20;
    a=4'b1000;b=4'b1011;op=1'b0;
    #20;
    a=4'b0010;b=4'b1010;op=1'b1;
    end
endmodule
