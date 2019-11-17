module test_ParallelMultiplier ();
	reg [1:4] x;
	reg [1:4] y;
    wire [1:8] z;
	ParallelMultiplier u0(x,y,z);
	initial
	begin
    x=4'h0;
	y=4'h0;
	#40;
	x=4'h2;
	y=4'h3;
	#40;
	x=4'hf;
	y=4'hf;
    $stop;
	end
endmodule
