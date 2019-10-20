`timescale 1ns/100ps
module test();
    reg clk_1Hz;
    reg [3:0]a;
    wire [0:6]y;
    led_7 u0(a,y);
    always #50 clk_1Hz = ~clk_1Hz ;
    initial
    begin
    clk_1Hz=0;
    a = 4'b0000;
    #100;
    a = 4'b0001;
    #100;
    a = 4'b0010;
    #100;
    a = 4'b0011;
    #100;
    a = 4'b0100;
    #100;
    a = 4'b0101;
    #100;
    a = 4'b0110;
    #100;
    a = 4'b0111;
    #100;
    a = 4'b1000;
    #100;
    a = 4'b1001;
    end
endmodule

