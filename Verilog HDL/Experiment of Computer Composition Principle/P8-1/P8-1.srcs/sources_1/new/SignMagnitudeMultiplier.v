module SignMagnitudeMultiplier(
    clk,start,X,Y,Z,finished
    );
    parameter N=31;
    input wire clk;
    input wire start;
    input wire [0:N] X;
    input wire [0:N] Y;
    output wire [0:2*N] Z;
    output reg finished;

    reg [0:N+1] A,B;
    reg [1:N]C;
    integer Cd;   

    always @(posedge clk  or posedge start)
    if (start==0)
    begin
        A<=0;//寄存器清0，作为初始部分积
        Cd<=N;//用于控制乘法运算次数，初始值为乘数位数
        B<={2'b00,X[1:N]};//寄存器中存放被乘数的绝对值
        C<=Y[1:N];//寄存器采用移位寄存器，存放乘数的绝对值
        finished<=1'b0;
    end
    else if (Cd==0)
    begin
        finished<=1'b1;
    end
    else 
    begin
        if(C[N]==1'b1)
        begin
            A=A+B;
        end
        {A[0:N+1],C[1:N]}={1'b0,A[0:N+1],C[1:N-1]};
        Cd=Cd-1;        
    end

    assign Z={X[0]^Y[0],A[2:N+1],C[1:N]};
 endmodule
