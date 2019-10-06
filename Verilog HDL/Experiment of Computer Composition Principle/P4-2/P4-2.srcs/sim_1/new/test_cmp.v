`timescale 1ns/100ps
module test_cmp();
    reg clk_1Hz;
    reg [3:0]a;
    reg [3:0]b;
    wire l,m,g;
    cmp u0(a,b,l,m,g);
    always #100 clk_1Hz = ~clk_1Hz ;
    initial
    begin
        clk_1Hz=0;
        a=4'b0000;b=4'b0000;
        #200;
        a=4'b0010;b=4'b1010;   
        #200;
        a=4'b0100;b=4'b0101;
        #200;
        a=4'b1010;b=4'b1001; 
    end
endmodule
