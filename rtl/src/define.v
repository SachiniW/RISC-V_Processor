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

//Immediate extension definitions
localparam  U = 3'b000,
            S = 3'b001,
            B = 3'b010,
            I = 3'b011,
            J = 3'b100,
            R = 3'b101;

localparam  ALUSRC1_RS1 = 1'b0,
            ALUSRC1_PC  = 1'b1;

localparam  ALUSRC2_RS2 = 1'b0,
            ALUSRC2_IMM = 1'b1;

// Load 
localparam LW     = 10'b0100000011;
localparam LB     = 10'b0000000011;
localparam LH     = 10'b0010000011;
localparam LBU    = 10'b1000000011;
localparam LHU    = 10'b1010000011;
// Store
localparam SW     = 10'b0100100011;
localparam SB     = 10'b0000100011;
localparam SH     = 10'b0010100011;
// Shifts
localparam SLL    = 11'b00010110011;
localparam SLLI   = 11'b00010010011;
localparam SRL    = 11'b01010110011;
localparam SRLI   = 11'b01010010011;
localparam SRA    = 11'b11010110011;
localparam SRAI   = 11'b11010010011;
// Arithmetic
localparam ADD    = 11'b00000110011;
localparam ADDI   = 10'b0000010011;
localparam SUB    = 11'b10000110011;
localparam LUI    = 7'b0110111;
localparam AUIPC  = 7'b0010111;
// Logical
localparam XOR    = 11'b01000110011;
localparam XORI   = 10'b1000010011;
localparam OR     = 11'b01100110011;
localparam ORI    = 10'b1100010011;
localparam AND    = 11'b01110110011;
localparam ANDI   = 10'b1110010011;
// Compare
localparam SLT    = 11'b00100110011;
localparam SLTI   = 10'b0100010011;
localparam SLTU   = 11'b00110110011;
localparam SLTIU  = 10'b0110010011;
// Branches
localparam BRANCH =    7'b1100011;
// Jump & Link
localparam JAL    = 7'b1101111;
localparam JALR   = 10'b0001100111;

// Multicycle stages
localparam FETCH = 3'd0,
           DECODE = 3'd1, 
           EXECUTE = 3'd2,
           MEMORY_ACCESS = 3'd3,
           WRITE_BACK = 3'd4;