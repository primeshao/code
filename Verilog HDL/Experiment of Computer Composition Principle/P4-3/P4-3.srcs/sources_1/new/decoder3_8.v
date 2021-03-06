module decoder3_8( S1 ,Y ,S2 ,A ,S3 );
    input wire S1,S2,S3 ;
    input wire [2:0] A ;
    output wire [7:0] Y ;
    assign Y =
    ({S1 & ~(~S2 | ~S3),A}==4'b1000)?8'b1111_1110:
    ({S1 & ~(~S2 | ~S3),A}==4'b1001)?8'b1111_1101:    
    ({S1 & ~(~S2 | ~S3),A}==4'b1010)?8'b1111_1011:
    ({S1 & ~(~S2 | ~S3),A}==4'b1011)?8'b1111_0111:    
    ({S1 & ~(~S2 | ~S3),A}==4'b1100)?8'b1110_1111:
    ({S1 & ~(~S2 | ~S3),A}==4'b1101)?8'b1101_1111:    
    ({S1 & ~(~S2 | ~S3),A}==4'b1110)?8'b1011_1111:
    ({S1 & ~(~S2 | ~S3),A}==4'b1111)?8'b0111_1111:
    8'b1111_1111;          
endmodule
