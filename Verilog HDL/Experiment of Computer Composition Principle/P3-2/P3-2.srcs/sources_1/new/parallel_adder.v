//四位全加器的描述
module parallel_adder(a,b,cin,s,cout);
	parameter N=4;//二进制位数
	input wire [N-1:0]a;//加数
	input wire [N-1:0]b;//被加数
	input wire cin;//进位输入
	output wire [N-1:0]s;//和
	output wire cout;//进位输出
	wire c0,c1,c2;
	fulladder u0_fa(a[0],b[0],cin,s[0],c0);
	fulladder u1_fa(a[1],b[1],c0,s[1],c1);
	fulladder u2_fa(a[2],b[2],c1,s[2],c2);
	fulladder u3_fa(a[3],b[3],c2,s[3],cout);
endmodule

//一位全加器的描述
module fulladder(input a,b,cin,output sum,cout);
	wire s,d1,d2;
	halfadder ha0(.b(b),.a(a),.s(s),.c(d1));
	halfadder ha1(.b(cin),.a(s),.s(sum),.c(d2));
	or g1(cout,d2,d1);
endmodule

//一位半加器的描述
module halfadder(input a,b,output s,c);
	xor(s,a,b);
	and(c,a,b);
endmodule