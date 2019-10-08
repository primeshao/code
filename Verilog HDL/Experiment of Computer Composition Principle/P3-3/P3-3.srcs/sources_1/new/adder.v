module adder(a,b,op,s,cout);
    parameter N=4;//������λ��
    input wire [N-1:0]a;//����(��)��
    input wire [N-1:0]b;//��(��)��
    input wire op;//��������
    output wire [N-1:0]s;//��
    output wire cout;//��λ���
    wire c1,c2,c3;
    wire b0,b1,b2,b3;
    xor(b0,op,b[0]);
    xor(b1,op,b[1]);
    xor(b2,op,b[2]);
    xor(b3,op,b[3]);
	fulladder u0_fa(a[0],b0,op,s[0],c1);
	fulladder u1_fa(a[1],b1,c1,s[1],c2);
	fulladder u2_fa(a[2],b2,c2,s[2],c3);
	fulladder u3_fa(a[3],b3,c3,s[3],cout);
endmodule

//һλȫ����������
module fulladder(a,b,cin,sum,cout);
  input a,b,cin;
  output cout,sum;
  wire x,y,c;
  xor(x,a,b);
  xor(sum,x,cin);
  and(y,a,b);
  and(c,cin,x);
  or(cout,y,c);
endmodule