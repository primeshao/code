module OnesComplement2TwosComplement (N,M);
	parameter WIDTH=32;
	input wire [WIDTH-1:0] N;
	output wire [WIDTH-1:0] M;
	assign M=N[WIDTH-1]?(N+1):N;
endmodule
/*
module OnesComplement2TwosComplement (N,M);
	parameter WIDTH=32;
	input wire [WIDTH-1:0] N;
	output wire [WIDTH-1:0] M;
	wire cout;	
	assign {cout,X} = N+32¡¯d1;
	assign M=N[WIDTH-1]?X:N;
endmodule
*/
