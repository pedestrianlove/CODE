module ALU (A, B, sel, Cin, Y, Zero);
	input signed [32 - 1 : 0] A, B;
	input [4 - 1 : 0] sel;
	input Cin;
	output reg [32 - 1 : 0] Y;
	output reg Zero;
	reg [32-1 : 0]temp;

	// MODULE VARIABLES
	wire and_1, or_1, not_1, xor_1, xnor_1, nor_1;
	wire [32-1:0]  dec_1;
	wire [5-1:0] arb_1;
	AND AND1(A[0], B[0], and_1);
	OR OR1(A[0], B[0], or_1);
	NOT NOT1(A[0], not_1);
	XOR XOR1(A[0], B[0], xor_1);
	XNOR XNOR1(A[0], B[0], xnor_1);
	NOR NOR1(A[0], B[0], nor_1);

	Arbiter arb1(A[5-1:0], arb_1);
	Decoder dec1(A[5-1:0], dec_1);
	//Design your code here
	always@(*)begin
		case(sel)
			// LOGIC GATE PART
			4'b0000: Y = and_1;
			4'b0001: Y = or_1;
			4'b0010: Y = not_1;
			4'b0011: Y = xor_1;
			4'b0100: Y = xnor_1;
			4'b0101: Y = nor_1;
			// ARITHMETIC PART
			4'b0110: Y = A + B + Cin;
			4'b0111: Y = A - B;
			4'b1000: begin
					temp = A - B;
						if(temp[31] == 1'b1) begin
							 Y = -temp;
						end
						else begin
							Y = temp;
						end
				 end
			4'b1001: Y = A[15:0]*B[15:0];
			// SHIFTER PART
			4'b1010: Y = A << 1'b1;
			4'b1011: Y = A <<< 1'b1;
			4'b1100: Y = A >> 1'b1;
			4'b1101: Y = A >>> 1'b1;
			// MISCELLANEOUS
			4'b1110: Y = dec_1; // FIXME
			4'b1111: Y = arb_1; // FIXME
		endcase
		
		if(Y!=0 || sel==4'b1110 || sel==4'b1111)
			Zero = 1'b0;
		else
			Zero = 1'b1; 
	end
endmodule 

module Arbiter(r, g); // find-first-one unit
	input [5 - 1 : 0] r;
	output reg [5 - 1 : 0] g;
	// IMPLEMENTATION
	always@(*)begin
		case(r)
			5'b00000: g = 5'b00000;
			5'b00001: g = 5'b00001;
			5'b00011: g = 5'b00001;
			5'b00101: g = 5'b00001;
			5'b01001: g = 5'b00001;
			5'b10001: g = 5'b00001;
			5'b11001: g = 5'b00001;
			5'b10011: g = 5'b00001;
			5'b00111: g = 5'b00001;
			5'b01101: g = 5'b00001;
			5'b10101: g = 5'b00001;
			5'b01011: g = 5'b00001;
			5'b11101: g = 5'b00001;
			5'b11011: g = 5'b00001;
			5'b10111: g = 5'b00001;
			5'b01111: g = 5'b00001;
			5'b11111: g = 5'b00001;
			5'b00010: g = 5'b00010;
			5'b00110: g = 5'b00010;
			5'b01110: g = 5'b00010;
			5'b11110: g = 5'b00010;
			5'b10110: g = 5'b00010;
			5'b11010: g = 5'b00010;
			5'b10010: g = 5'b00010;
			5'b01010: g = 5'b00010;
			5'b00100: g = 5'b00100;
			5'b01100: g = 5'b00100;
			5'b11100: g = 5'b00100;
			5'b10100: g = 5'b00100;
			5'b01000: g = 5'b01000;
			5'b11000: g = 5'b01000;
			5'b10000: g = 5'b10000;
			default: g = 5'hx;
		endcase
	end
endmodule

module Decoder(a, b); // binary to one-hot decoder
	input [5 - 1 : 0] a;
	output [32 - 1 : 0] b;
	// IMPLEMENTATION
	assign b = 1 << a;
endmodule

module AND (a, b, c);
	input  a, b;
	output c;
	wire nand_0;
	// IMPLEMENTATION
	nand nand1(nand_0, a, b);
	NOT N1(nand_0, c);
endmodule

module OR (a, b, c);
	input  a, b;
	output c;
	wire not_0, not_1;
	// IMPLEMENTATION
	NOT N1(a, not_0);
	NOT N2(b, not_1);
	nand(c, not_0, not_1);
endmodule

module NOT (a, b);
	input  a;
	output b;
	// IMPLEMENTATION
	nand(b, a, a);
endmodule

module XOR (a, b, c);
	input  a, b;
	output c;
	wire and_0, and_1, not_a, not_b;
	// IMPLEMENTATION
	NOT NOT1(a, not_a);
	NOT NOT2(b, not_b);
	AND AND1(a, not_b, and_0);
	AND AND2(b, not_a, and_1);
	OR OR1(and_0, and_1, c);	
endmodule

module XNOR (a, b, c);
	input  a, b;
	output c;
	wire xor_0;
	XOR XOR1(a, b, xor_0);
	NOT NOT1(xor_0, c);
endmodule

module NOR (a, b, c);
	input  a, b;
	output c;
	wire or_0;
	// IMPLEMENTATION
	OR OR1(a, b, or_0);
	NOT NOT1(or_0, c);
endmodule
