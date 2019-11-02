module adder32(a,b,cin,s,cout);
	input [31:0] a;//被加数
	input [31:0] b;//加数
	input cin;//进位输入
	output [31:0] s;//和
	output cout;//进位输出
	wire [6:0] carry;//级联进位
PA4 u0(a[3:0],b[3:0],cin,s[3:0],carry[0]);
PA4 u1(a[7:4],b[7:4],carry[0],s[7:4],carry[1]);
PA4 u2(a[11:8],b[11:8],carry[1],s[11:8],carry[2]);
PA4 u3(a[15:12],b[15:12],carry[2],s[15:12],carry[3]);
PA4 u4(a[19:16],b[19:16],carry[3],s[19:16],carry[4]);
PA4 u5(a[23:20],b[23:20],carry[4],s[23:20],carry[5]);
PA4 u6(a[27:24],b[27:24],carry[5],s[27:24],carry[6]);
PA4 u7(a[31:28],b[31:28],carry[6],s[31:28],cout);

endmodule
