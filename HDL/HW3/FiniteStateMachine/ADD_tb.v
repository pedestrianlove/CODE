`define SDFFILE   "./ADD.sdf"
`define End_CYCLE  100000

`define info  "./info.dat"   

module ADD_tb;
	//Clock period
	parameter cyc = 30;
	
	parameter dataWidth = 3;
	parameter memWidth = 3;

	// #pattern
	parameter PAT = 10;

	reg [dataWidth - 1 : 0] dataROM [0 : PAT - 1];
	reg [memWidth - 1 : 0] maxSize;

	reg clk , rst , start , tf;
	reg [dataWidth - 1 : 0] data;
	wire fin , en;
	wire [dataWidth - 1 : 0] result;
	wire [memWidth - 1 : 0] addr;

	//STM module
	ADD add( 
		.clk(clk),
		.rst(rst), 
		.start(start), 
		.data(data),
        .en(en),
        .addr(addr),
        .fin(fin),
        .result(result)
	);
	
	always #(cyc/2) clk = ~clk;
	
	initial begin
		`ifdef SDF
			$sdf_annotate(`SDFFILE, add);
			$fsdbDumpfile("ADD_syn.fsdb");
		`else
			$fsdbDumpfile("ADD.fsdb");
		`endif
		$fsdbDumpvars;
	end

	
	initial begin
		$display(" ");
		//Init ROM
		$readmemb ("info.dat", dataROM);

		maxSize = 3'd7;		
		rst = 1'b0;
		clk = 1'b0;
		start = 1'b0;
		data = 'hz;

		@(negedge clk)  rst = 1'b1; 
		#(cyc);    rst = 1'b0; 
		#(cyc);
		@(negedge clk)  start = 1'b1;
		while (fin == 0) begin             
			if(en && addr <= maxSize) begin
				data = dataROM[addr];
			end else begin
				data = 'hz;
			end                    
			@(negedge clk);  

		end
		$display(" ");
		if(result == dataROM[8])begin
			$display("!!!!! ACCEPTED !!!!! , your ans = %d , correct ans = %d" , result , dataROM[8]);
		end
		else begin
			$display("WRONG ANSWER QAQ , your ans = %d , correct ans = %d" , result , dataROM[8]);
		end
		$display(" ");
		$finish;
	end
	
	initial  begin
		#`End_CYCLE ;
		$display("-----------------------------------------------------\n");
		$display("Error!!! Somethings' wrong with your code ...!\n");
		$display("-------------------------FAIL------------------------\n");
		$display("-----------------------------------------------------\n");
		$finish;
	end
endmodule
