`timescale 1ns/100ps
module test_adder();
  reg clk_1Hz,op;
  reg [3:0]a,b;
  wire [3:0]s;
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
    a=4'b0000;b=4'b0000;op=1'b0;
    #20;
    a=4'b0000;b=4'b0000;op=1'b1;
    
    #20;
    a=4'b0000;b=4'b0001;op=1'b0;
    #20;
    a=4'b0000;b=4'b0001;op=1'b1;

    #20;
    a=4'b1101;b=4'b0100;op=1'b0;
    #20;
    a=4'b1101;b=4'b0100;op=1'b1;

    #20;
    a=4'b0000;b=4'b1001;op=1'b0;
    #20;
    a=4'b0000;b=4'b1001;op=1'b1;
    
    #20;
    a=4'b1000;b=4'b0110;op=1'b0;
    #20;
    a=4'b1000;b=4'b0110;op=1'b1;
    end
endmodule