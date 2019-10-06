`timescale 1ns/100ps
module test_adder();
    reg clk_1Hz;
    reg [3:0]a,b;
    reg cin;
    wire  [3:0]s;
    wire cout;
parallel_adder u0(.a(a),.b(b),.cin(cin),.s(s),.cout(cout));  
always #50 clk_1Hz = ~clk_1Hz ;
  initial
  begin
    clk_1Hz=0;
    a=4'b0000;b=4'b0000;cin=1'b0;
    #100;
    a=4'b0000;b=4'b0001;cin=1'b0;
    #100;
    b=4'b1111;cin=1'b1;
    #100;
    a=4'b1101;b=4'b0100;
    #100;
    a=4'b0000;b=4'b1001;cin=1'b0;
    #100;
    a=4'b1000;b=4'b0110;
end
endmodule