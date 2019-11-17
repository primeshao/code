module ComplementMultiplier (
    clk,start,X,Y,Z,finished
    );
    parameter N=4;//¿É¸ÄÎª31
    input wire clk;
    input wire start;
    input wire [0:N] X;
    input wire [0:N] Y;
    output wire [0:2*N] Z;
    output reg finished;

    reg [0:N+1] A,B;
    reg [1:N]C;
    integer Cd;   

    always @(posedge clk)
    if (start==0)
    begin
        A<=0;
        Cd<=N;
        B<={X[0],X[0:N]};
        C<=Y[1:N];
        finished<=1'b0;
    end
    else if (Cd==0)
    begin
       if(Y[0]==1)
       begin
            A=A-B;
       end
            finished<=1'b1;
    end
    else 
    begin
        if(C[N]==1'b1)
        begin
            A=A+B;
        end
        {A[0:N+1],C[1:N]}={A[0],A[0:N+1],C[1:N-1]};
        Cd=Cd-1;        
    end
    assign Z={A[1:N+1],C[1:N]};
endmodule
