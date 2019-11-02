module  sub_adder32(x,y,op,z,overflow);
	input [31:0] x;//被加数
	input [31:0] y;//加数
	input op;//运算类型 0：+，1：-
	output [31:0] z;//和
	output overflow;//溢出标志 0：正常 1：溢出
	wire [31:0] a;
	wire [31:0] b;
	wire cin;
	wire [31:0] s;
	wire sf;//双符号位的最高符号位
	wire cout;
	assign a=x;
	assign b=y^{32{op}};//求补操作
	assign cin=op;
	adder32 u0(a,b,cin,s,cout);
	assign sf=s[31];
	assign overflow=sf^s[30]; //溢出
    assign z=s;

endmodule