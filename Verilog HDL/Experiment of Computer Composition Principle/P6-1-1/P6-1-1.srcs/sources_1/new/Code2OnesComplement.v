module Code2OnesComplement (N,M);//ԭ��->����
	parameter WIDTH=32;
	input wire [WIDTH-1:0] N;
	output wire [WIDTH-1:0] M;
	assign M=N[WIDTH-1]?{N[WIDTH-1],~N[WIDTH-2:0]}:N;
	//assign M=N[WIDTH-1]?{N+1}:N;
endmodule
