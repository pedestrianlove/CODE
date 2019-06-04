module kevin_G(in, out);
	// constant
	parameter bitLength = 4;

	// gate temp variables
	wire not_a, not_b, not_c, not_d;
	wire and_0, and_1, and_2, and_3, and_4, and_5, and_6;
	wire or_0;


	// IO specified
	input [bitLength-1 : 0] in;
	output out;

	//compute && output
	not not0(not_a, in[3]);
	not not3(not_b, in[2]);
	not not2(not_c, in[1]);
	not not1(not_d, in[0]);

	and and0(and_0, not_a, in[2], in[1]);
	and and1(and_1, not_a, in[2], in[0]);
	and and2(and_2, in[3], in[1], not_d);
	and and3(and_3, in[3], in[2], not_d);
	and and4(and_4, not_b, not_c, in[0]);
	and and5(and_5, not_a, not_c, in[0]);
	and and6(and_6, in[2], in[1], not_d);

	or or0(out, and_0, and_1, and_2, and_3, and_4, and_5, and_6);
endmodule

module kevin_D(in, out);
	//const
	parameter bitLength = 4;

	// IO info
	input [bitLength-1 : 0] in;
	output out;

	//compute && output
	assign out = (!in[3]&in[2]&in[1])
			|(!in[3]&in[2]&in[0])
			|(in[3]&in[1]&!in[0])
			|(in[3]&in[2]&!in[0])
			|(!in[2]&!in[1]&in[0])
			|(!in[3]&!in[1]&in[0])
			|(in[2]&in[1]&!in[0]);
endmodule


module kevin_B(in, out);
	//const
	parameter bitLength = 4;

	// IO info
	input [bitLength-1 : 0] in;
	output reg out;

	// compute
	always@(*)begin
		case(in)
			1,5,6,7,9,10,12,14:
				begin
					out = 1'b1;
				end
			default:
				begin
					out = 1'b0;
				end
		endcase
	end
endmodule
