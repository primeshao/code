`timescale 1ns/100ps
module test_selector4();
    reg clk_1Hz;
    reg [3:0]D;
    reg [1:0]A;
    wire Y;
    selector4 u0(A,D,Y);
    always #25 clk_1Hz = ~clk_1Hz ;
    initial
    begin
        clk_1Hz=0;
        D = 4'b0001;A = 2'b00;
        #50;
        D = 4'b0001;A = 2'b01;
        #50;
        D = 4'b0001;A = 2'b10;
        #50;
        D = 4'b0001;A = 2'b11;
        
        #50;
        D = 4'b0010;A = 2'b00;
        #50;
        D = 4'b0010;A = 2'b01;
        #50;
        D = 4'b0010;A = 2'b10;
        #50;
        D = 4'b0010;A = 2'b11;
        
        #50;
        D = 4'b0100;A = 2'b00;
        #50;
        D = 4'b0100;A = 2'b01;
        #50;
        D = 4'b0100;A = 2'b10;
        #50;
        D = 4'b0100;A = 2'b11;
        
        #50;
        D = 4'b1000;A = 2'b00;
        #50;
        D = 4'b1000;A = 2'b01;
        #50;
        D = 4'b1000;A = 2'b10;
        #50;
        D = 4'b1000;A = 2'b11;
    end
endmodule

