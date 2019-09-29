module decision_structure (a,b,c,y);
	input wire a,b,c;
	output wire y;
	wire ab,bc,ac;
	and g1(ab,a,b);
	and g2(bc,b,c);
	and g3(ac,a,c);
	or g4(y,ab,bc,ac);
endmodule