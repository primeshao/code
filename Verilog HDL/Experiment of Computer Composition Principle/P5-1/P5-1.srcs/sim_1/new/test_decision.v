`timescale 1ns/100ps
module test_decision();
  reg clk_1Hz,a,b,c;
  wire y;
  decision_behavior u0(a,b,c,y);
    always #50 clk_1Hz = ~clk_1Hz ;
    initial
    begin
    clk_1Hz=0;
    #100;
    a=0;b=0;c=0;
    #100;
    a=0;b=0;c=1;  
    #100;
    a=0;b=1;c=0;  
    #100;
    a=0;b=1;c=1;  
    #100;
    a=1;b=0;c=0;  
    #100;
    a=1;b=0;c=1;  
    #100;
    a=1;b=1;c=0;  
    #100;
    a=1;b=1;c=1;  
    end
endmodule
