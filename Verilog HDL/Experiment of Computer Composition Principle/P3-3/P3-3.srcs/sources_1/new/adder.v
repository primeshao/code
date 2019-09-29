module adder(a,b,op,s,cout);
    parameter N=4;//������λ��
    input wire [N-1:0]a;//����
    input wire [N-1:0]b;//������
    input wire op;//��������
    output wire [N-1:0]s;//��
    output wire cout;//��λ���
    assign {cout,s}=op?(a+b):(a-b); 
endmodule
