`timescale 1ns/100ps
module test_decoder3_8();
    reg clk_1Hz;
    reg S1,S2,S3 ;
    reg [2:0] A ;
    wire [7:0] Y ;
    decoder3_8 u0( S1 ,Y ,S2 ,A ,S3);
    always #50 clk_1Hz = ~clk_1Hz ;
    initial
    begin
        clk_1Hz=0;
        S1 = 0;S2 = 1;S3 = 1;A = 3'b000;
        #100;
        S1 = 1;S2 = 0;A = 3'b000;
        #100;
        S2 = 1;A = 3'b000;
        #100;
        A = 3'b001;     
        #100;
        A = 3'b010;
        #100;
        A = 3'b011;
        #100;
        A = 3'b100;
        #100;
        A = 3'b101;
        #100;
        A = 3'b110; 
        #100;
        A = 3'b111; 
    end
endmodule
