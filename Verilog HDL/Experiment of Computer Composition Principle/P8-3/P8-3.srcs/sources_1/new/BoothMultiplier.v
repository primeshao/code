module BoothMultiplier(
     clk,start,X,Y,Z,finished
    );
    parameter N=4;//可改为31
    input wire clk;
    input wire start;
    input wire [0:N] X;
    input wire [0:N] Y;
    output wire [0:2*N] Z;
    output reg finished;
    
    reg M;
    reg [0:N+1] A,B;
    reg [0:N+1]C;
    integer Cd;   
always @(posedge clk)
    if (start==0)
    begin
        A<=0;
        Cd<=N+1;
        B<={X[0],X[0:N]};
        C<=Y[0:N];
        M<=0;//ERROR位置定位
        finished<=1'b0;
    end  
    else if(Cd==0)
        begin
            finished<=1'b1;
        end
    else 
        begin
        {A[0:N+1],C[1:N]}={A[0],A[0:N+1],C[1:N-1]};
        if(Y[N]==0&&M==1)
            begin 
                A<=A+B;
            end
        else if(Y[N]==1&&M==0)
            begin
                A<=A-B;
            end
        Cd=Cd-1;
     end
     assign Z={A[1:N+1],C[1:N]};
endmodule
