module FullAdder(a,b,cin,s,cout);
output s,cout;
	input a,b,cin;
	wire a,b,cout,s;
	wire a_bar,b_bar,cin_bar;
	not not1(a_bar,a);
	not not2(b_bar,b);
	not not3(cin_bar,cin);
	and and4(and4_out,a_bar,b_bar,cin);
	and and5(and5_out,a_bar,b,cin_bar);
	and and6(and6_out,a,b_bar,cin_bar);
	and and7(and7_out,a,b,cin);
	or or8(s,and4_out,and5_out,and6_out,and7_out);
	and and9(and9_out,a,b);
	and and10(and10_out,a,cin);
	and and11(and11_out,b,cin);
	or or12(cout,and9_out,and10_out,and11_out);	   
endmodule
