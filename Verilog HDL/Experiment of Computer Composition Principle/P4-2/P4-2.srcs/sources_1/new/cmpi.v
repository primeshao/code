module cmpi(ai,bi,li,mi,gi);
	input  wire ai,bi;
	output wire li,mi,gi;
	assign li = ai & (~bi);
	assign gi = ai ^~ bi;
	assign mi = (~ai) & bi;
endmodule