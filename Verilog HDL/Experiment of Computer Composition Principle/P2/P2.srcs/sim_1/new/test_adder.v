`timescale 1ns/100ps
module test_adder();
        reg [3:0] my_a;
        reg [3:0] my_b;
        reg my_cin;
        wire [3:0] my_sum;
        wire my_cout;
        reg clk;
        adder u0(my_a,my_b,my_cin,my_sum,my_cout);
        always #10 clk=~clk;
        initial
        begin
                clk=1'b0;
                my_a=4'b0000;my_b=4'b0000;my_cin=1'b0;     
	        #100;
	       my_a=4'b0000;my_b=4'b0001;my_cin=1'b0;     
	       #100;//一共有2^9种情况 ，可以添加下其他激励信号   
        end
endmodule
