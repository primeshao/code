module MultiPP(pp_in,xj,yi,cin,pp_out,cout);
input pp_in;
	input xj;
	input yi;
	input cin;
	output pp_out;
	output cout;
	wire and_out=xj&yi;
    FullAdder u_fulladder(pp_in,and_out,cin,pp_out,cout);
endmodule
