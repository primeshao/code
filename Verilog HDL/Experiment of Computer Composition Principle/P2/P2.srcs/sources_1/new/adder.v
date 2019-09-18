module adder(a,b,cin,s,cout);
	parameter N=4;
	output wire [N-1:0] s;
	output wire cout;
	input wire [N-1:0]a;
	input wire [N-1:0]b;
	input wire cin;
	wire [N-2:0]c;
	fulladder FA1(a[0],b[0],cin,s[0],c[0]);	
	fulladder FA2(a[1],b[1],c[0],s[1],c[1]);
	fulladder FA3(a[2],b[2],c[1],s[2],c[2]);
	fulladder FA4(a[3],b[3],c[2],s[3],cout);
endmodule

