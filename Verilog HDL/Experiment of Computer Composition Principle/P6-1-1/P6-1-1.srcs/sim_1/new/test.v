module test();//simulation
    parameter WIDTH=32;
    reg [WIDTH-1:0] N;
    wire [WIDTH-1:0] M;
    Code2OnesComplement u0(N,M);
    initial
    begin
        #10;
        N=32'h00_00_00_01;
        #10;
        N=32'h00_00_00_02;
        #10;
        N=32'h80_00_00_01;
        #10;
        N=32'h80_00_00_02;  
        #10;
        $finish;      
    end
endmodule
