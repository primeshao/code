module cmp(a,b,l,m,g);
	parameter N=4;
	input wire [N-1:0]a;
    input wire [N-1:0]b;
	output wire l,m,g;
	wire [N-1:0]mi;//内部cmpi实例mi输出信号
    wire [N-1:0]gi;//内部cmpi实例gi输出信号
	//请填写cmpi的一些实例
	cmpi cmp0(.ai(a[0]),.bi(b[0]),.mi(mi[0]),.gi(gi[0]));
    cmpi cmp1(.ai(a[1]),.bi(b[1]),.mi(mi[1]),.gi(gi[1]));
    cmpi cmp2(.ai(a[2]),.bi(b[2]),.mi(mi[2]),.gi(gi[2]));
    cmpi cmp3(.ai(a[3]),.bi(b[3]),.mi(mi[3]),.gi(gi[3]));	
    //请填写数据流建模代码
    assign m=mi[3]|(gi[3]&mi[2])|(gi[3]&gi[2]&mi[1])|( gi[3]&gi[2]&gi[1]&mi[0]);
    assign g=gi[3]&gi[2]&gi[1]&gi[0];
    assign l=!(m|g);
endmodule
