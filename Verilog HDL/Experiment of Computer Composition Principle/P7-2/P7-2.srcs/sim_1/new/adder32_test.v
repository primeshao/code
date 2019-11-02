`timescale 1ns/100ps
module adder32_test();
    reg clk_1Hz,cin;
    reg [31:0] a;//被加数
	reg [31:0] b;//加数
	wire [31:0] s;//和
	wire cout;//进位输出
    adder32 U0(a,b,cin,s,cout);
    always #50 clk_1Hz = ~clk_1Hz ;
    initial
    begin
    clk_1Hz=0;cin=0;
	a=32'b00000000000000000000000000000000;b=32'b00000000000000000000000000000001; 
	#100;
	a=32'b11111111111111111111111111111111;b=32'b00000000000000000000000000000001;
	#100;
	a=32'b01010101010101010101010101010101;b=32'b10101010101010101010101010101010;
	#100;
	a=32'b00000010100110110010001011011111;b=32'b01010101010101010101010101010101;
	end
endmodule
