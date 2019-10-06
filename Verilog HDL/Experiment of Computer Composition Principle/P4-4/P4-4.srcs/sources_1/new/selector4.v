module selector4(A,D,Y);
    input wire [3:0]D;
    input wire [1:0]A;
    output wire Y;
    assign Y =
       (!A[1] & !A[0])?D[0]:
       (!A[1] & A[0])?D[1]:
       (A[1] & !A[0])?D[2]:
       D[3];
endmodule