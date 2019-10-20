module decision_behavior(a,b,c,y);
	input wire a,b,c;
	output reg y;
	always @(a,b,c)
	begin
		y=(a&b)|(a&c);
	end
endmodule
