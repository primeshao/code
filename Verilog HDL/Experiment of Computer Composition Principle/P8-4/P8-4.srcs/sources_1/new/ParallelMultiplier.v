module ParallelMultiplier(X,Y,Z);
	parameter N=4;
	input wire [1:N] X;
	input wire [1:N] Y;
	output wire [1:N*2] Z;
	
	MultiPP   u_X4Y4(0,X[4],Y[4],0,X4Y4_pp_out,X4Y4_cout);
	MultiPP   u_X3Y4(0,X[3],Y[4],X4Y4_cout,X3Y4_pp_out,X3Y4_cout);
	MultiPP   u_X2Y4(0,X[2],Y[4],X3Y4_cout,X2Y4_pp_out,X2Y4_cout);
	MultiPP   u_X1Y4(0,X[1],Y[4],X2Y4_cout,X1Y4_pp_out,X1Y4_cout);

	MultiPP   u_X4Y3(X3Y4_pp_out,X[4],Y[3],0,X4Y3_pp_out,X4Y3_cout);
    MultiPP  u_X3Y3(X2Y4_pp_out,X[3],Y[3],X4Y3_cout,X3Y3_pp_out,X3Y3_cout);
	MultiPP  u_X2Y3(X1Y4_pp_out,X[2],Y[3],X3Y3_cout,X2Y3_pp_out,X2Y3_cout);
    MultiPP  u_X1Y3(X1Y4_cout,X[1],Y[3],X2Y3_cout,X1Y3_pp_out,X1Y3_cout);

	MultiPP  u_X4Y2(X3Y3_pp_out,X[4],Y[2],0,X4Y2_pp_out,X4Y2_cout);
    MultiPP  u_X3Y2(X2Y3_pp_out,X[3],Y[2],X4Y2_cout,X3Y2_pp_out,X3Y2_cout);
	MultiPP  u_X2Y2(X1Y3_pp_out,X[2],Y[2],X3Y2_cout,X2Y2_pp_out,X2Y2_cout);
	MultiPP  u_X1Y2(X1Y3_cout,X[1],Y[2],X2Y2_cout,X1Y2_pp_out,X1Y2_cout);

	MultiPP  u_X4Y1(X3Y2_pp_out,X[4],Y[1],0,X4Y1_pp_out,X4Y1_cout);
    MultiPP  u_X3Y1(X2Y2_pp_out,X[3],Y[1],X4Y1_cout,X3Y1_pp_out,X3Y1_cout);
	MultiPP  u_X2Y1(X1Y2_pp_out,X[2],Y[1],X3Y1_cout,X2Y1_pp_out,X2Y1_cout);
	MultiPP  u_X1Y1(X1Y2_cout,X[1],Y[1],X2Y1_cout,X1Y1_pp_out,X1Y1_cout);

    assign Z={X1Y1_cout,X1Y1_pp_out,X2Y1_pp_out,X3Y1_pp_out,X4Y1_pp_out,X4Y2_pp_out,X4Y3_pp_out,X4Y4_pp_out};
endmodule
