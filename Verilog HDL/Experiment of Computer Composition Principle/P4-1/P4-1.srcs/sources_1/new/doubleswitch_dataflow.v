module doubleswitch_dataflow(a,b,y);
	input wire a,b;
	output wire y;
	assign y=a^b;
endmodule