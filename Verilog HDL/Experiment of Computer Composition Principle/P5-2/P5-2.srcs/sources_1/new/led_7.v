module led_7(a,y);
	input wire [3:0]a;
	output reg [0:6]y;
	always @(a)
	begin
        y[0] = ~(a[3] | a[1] | (a[2]&a[0]) | ((~a[2])&(~a[0])));
        y[1] = ~(~a[2] | ((~a[1])&(~a[0])) | (a[1]&a[0]));
        y[2] = ~(a[2] | (~a[1]) | a[0]);
        y[3] = ~a[3]&((a[0]&~a[1]&~a[2]) | (~a[0]&~a[1]&a[2]) | (a[0]&a[1]&a[2]));
        y[4] = ~(((~a[2])&(~a[0])) | (a[1]&(~a[0])));
        y[5] = ~(a[3] | (~a[1]&(~a[0]|a[2])) | (a[2]&~a[0]));
        y[6] = ~(a[3] | (a[2]&(~a[1])) | ((~a[2])&a[1]) | (a[2]&(~a[0])));
        if(a[3] == 1)
            if(a != 4'b0001 && a!= 4'b1001)
                y = 7'b0000000;
	end
endmodule
