module adder(a,b,op,s,cout);
    parameter N=4;//二进制位数
    input wire [N-1:0]a;//加数
    input wire [N-1:0]b;//被加数
    input wire op;//操作控制
    output wire [N-1:0]s;//和
    output wire cout;//进位输出
    assign {cout,s}=op?(a+b):(a-b); 
endmodule
