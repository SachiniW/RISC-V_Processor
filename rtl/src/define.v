//alu-op definitions
localparam ALU_ADD      = 4'd0;
localparam ALU_SUB      = 4'd1;
localparam ALU_AND      = 4'd2;
localparam ALU_OR       = 4'd3;
localparam ALU_XOR      = 4'd4;
localparam ALU_SLT      = 4'd5;
localparam ALU_SLL      = 4'd6;
localparam ALU_SLTU     = 4'd7;
localparam ALU_SRL      = 4'd8;
localparam ALU_SRA      = 4'd9;
localparam ALU_COPY1    = 4'd10;
localparam ALU_COPY2    = 4'd11;

//branch-logic definitions
localparam  BEQ = 3'b000,
            BNE = 3'b001,
            BLT = 3'b100,
            BGE = 3'b101,
            BLTU = 3'b110,
            BGEU = 3'b111;


