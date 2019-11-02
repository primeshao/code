module  sub_adder32(x,y,op,z,overflow);
	input [31:0] x;//������
	input [31:0] y;//����
	input op;//�������� 0��+��1��-
	output [31:0] z;//��
	output overflow;//�����־ 0������ 1�����
	wire [31:0] a;
	wire [31:0] b;
	wire cin;
	wire [31:0] s;
	wire sf;//˫����λ����߷���λ
	wire cout;
	assign a=x;
	assign b=y^{32{op}};//�󲹲���
	assign cin=op;
	adder32 u0(a,b,cin,s,cout);
	assign sf=s[31];
	assign overflow=sf^s[30]; //���
    assign z=s;

endmodule