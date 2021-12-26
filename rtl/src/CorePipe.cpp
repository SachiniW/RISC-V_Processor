#include "VCorePipe.h"
#include "verilated.h"

//#define DEBUG
//#define COMPARE

// #include "bitset.h"
#include <bitset>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#define HIGH 1
#define LOW 0

int main(int argc, char **argv, char **env)
{
	Verilated::commandArgs(argc, argv);

	VCorePipe* top = new VCorePipe;

	int counter = 0;
	int counter2 = 0;
	char* c;
	int printCounter = 0;

	string fd_IRReg;
	string fd_IRRegOPcode ;
	string fd_IRRegrd     ;
	string fd_IRRegfunct3 ;
	string fd_IRRegrs1    ;
	string fd_IRRegrs2    ;
	string fd_IRRegImm    ;

	string CTRL_SIG     ;
	string REGWRT_SIG     ;

	static int clock = 0;


	while (!Verilated::gotFinish())
	{
		
		clock = (clock+1) & 1;

		top->CLK = clock;
		
		if(counter < 10){
			top->RESET = HIGH;
		}
		else{
			top->RESET = LOW;
		}

		if(clock == 1){
			counter = counter + 1;
			if(top->PRINT_EN){
				printf("%d\t%d",counter,printCounter);
				printf("\t%c\n",top->PRINT_VAL);
			}
			

			CTRL_SIG = bitset<17>(top->CorePipe__DOT__Control__DOT__control_sig).to_string();
			REGWRT_SIG = bitset<1>(top->CorePipe__DOT__MW_REGWRT).to_string();
			if (REGWRT_SIG[0] == '1'){
				printCounter ++;
			}


			#ifdef DEBUG

			 //if (REGWRT_SIG[0] == '1'){

				getchar();
				printf("%d\t%d",counter,printCounter);

				printf("\n\nFetech-Decode Latches \n");
				fd_IRReg = bitset<32>(top->CorePipe__DOT__FD_IR ).to_string();
				fd_IRRegOPcode = bitset<7>(top->CorePipe__DOT__FD_IR & 0x0000007F).to_string();
				fd_IRRegrd     = bitset<5>((top->CorePipe__DOT__FD_IR & 0x00000F80)>>7).to_string();
				fd_IRRegfunct3 = bitset<3>((top->CorePipe__DOT__FD_IR & 0x00007000)>>12).to_string();
				fd_IRRegrs1    = bitset<5>((top->CorePipe__DOT__FD_IR & 0x000F8000)>>15).to_string();
				fd_IRRegrs2    = bitset<5>((top->CorePipe__DOT__FD_IR & 0x01F00000)>>20).to_string();
				fd_IRRegImm    = bitset<7>((top->CorePipe__DOT__FD_IR & 0xFE000000)>>25).to_string();

				cout << "IRReg : " << fd_IRRegImm << "_" << fd_IRRegrs2 << "_" << fd_IRRegrs1 << "_" << fd_IRRegfunct3 << "_" << fd_IRRegrd << "_" << fd_IRRegOPcode << endl;

				printf("IRReg := %08x \t", top->CorePipe__DOT__FD_IR);
				printf("PCReg := %08x \t", (top->CorePipe__DOT__FD_PC + 0x10054));

				printf("\n\nDecode-Execute Latches \n");
				
				printf("IRReg := %08x \t", top->CorePipe__DOT__DE_IR);
				printf("PCReg := %08x \n", (top->CorePipe__DOT__DE_PC+ 0x10054));
				printf("RS1   := %08x \t", top->CorePipe__DOT__DE_SRC1);
				printf("RS2   := %08x \t", top->CorePipe__DOT__DE_SRC2);
				printf("Imm   := %08x \t", top->CorePipe__DOT__DE_IMM_EXT);
				printf("\naluSrc1 := %08x \t ", top->CorePipe__DOT__ALU_IN1);
				printf("aluSrc2 := %08x \t ", top->CorePipe__DOT__ALU_IN2);
	
				printf("\nA_sel\tB_sel\tjumpR\tbranch\tjump\tmem_wrt\n");
				printf("%d \t ", top->CorePipe__DOT__DE_ALUSRC1);
				printf("%d \t ", top->CorePipe__DOT__DE_ALUSRC2);
				printf("%d \t ", top->CorePipe__DOT__DE_JUMPR);
				printf("%d \t ", top->CorePipe__DOT__DE_BRN);
				printf("%d \t ", top->CorePipe__DOT__DE_JUMP);
				printf("%d \t ", top->CorePipe__DOT__DE_MEMWRT);
				
				printf("\nregwrt\tmem_rd \taluop\twbSel\tflush\tstall\n");
				printf("%d \t ", top->CorePipe__DOT__DE_REGWRT);
				printf("%d \t ", top->CorePipe__DOT__DE_MEMRD);
				printf("%d \t ", top->CorePipe__DOT__DE_ALUOP);
				printf("%d,%d \t ", top->CorePipe__DOT__DE_M2R,top->CorePipe__DOT__DE_WRTSRC);
				printf("%d \t ", top->CorePipe__DOT__FLUSH);
				printf("%d \t ", top->CorePipe__DOT__STALL);

				printf("\n\nExecute-MemoryAccess Latches \n");
				printf("IRReg := %08x \t ", top->CorePipe__DOT__EM_IR);
				printf("PCReg := %08x \t ", (top->CorePipe__DOT__EM_PC_PLUSFOUR+ 0x10050));
				printf("ALUout:= %08x \t ", top->CorePipe__DOT__EM_ALUOUT);
				printf("RS2   := %08x \t ", top->CorePipe__DOT__EM_SRC2);

				printf("\nmemrd\tmemwrt \tregwrt\twbSel\n");
				printf("%d \t ", top->CorePipe__DOT__EM_MEMRD);
				printf("%d \t ", top->CorePipe__DOT__EM_MEMWRT);
				printf("%d \t ", top->CorePipe__DOT__EM_REGWRT);
				printf("%d,%d \t ", top->CorePipe__DOT__EM_M2R,top->CorePipe__DOT__EM_WRTSRC);

				printf("\n\nMemoryAccess-WriteBack Latches \n");
				printf("IRReg := %08x \t ", top->CorePipe__DOT__MW_IR);
				printf("PCReg := %08x \t ", (top->CorePipe__DOT__MW_PC_PLUSFOUR+ 0x10050));
				printf("ALUout:= %08x \t ", top->CorePipe__DOT__MW_ALUOUT);
				printf("Rdata := %08x \t ", top->CorePipe__DOT__MW_R_DATA);
				//printf("wrtDa := %08x \t ", top->CorePipe__DOT__REG_IN);

				printf("\nregWrt\twbSel\n");
				printf("%d \t ", top->CorePipe__DOT__MW_REGWRT);
				printf("%d,%d \t \n ", top->CorePipe__DOT__MW_M2R,top->CorePipe__DOT__MW_WRTSRC);

				printf ("PC: %08x \n", top->CorePipe__DOT__FD_PC + 0x10054);
				printf ("Instruction %d: %08x \n" , int(counter/2), top->CorePipe__DOT__FD_IR);
				cout << "CS_TYPE     : "   <<  CTRL_SIG[0]  << CTRL_SIG[1] << CTRL_SIG[2] << endl;
				cout << "CS_JUMP     : "   <<  CTRL_SIG[3]    << endl;
				cout << "CS_JUMPR    : "   <<  CTRL_SIG[4]    << endl;
				cout << "CS_BRANCH   : "   <<  CTRL_SIG[5]    << endl;
				cout << "CS_ALUOP    : "   <<  CTRL_SIG[6]  << CTRL_SIG[7] <<  CTRL_SIG[8] << CTRL_SIG[9] << endl;
				cout << "CS_ALUSRC1  : "   <<  CTRL_SIG[10]     << endl;
				cout << "CS_ALUSRC2  : "   <<  CTRL_SIG[11]     << endl;
				cout << "CS_MEMRD    : "   <<  CTRL_SIG[12]     << endl; 
				cout << "CS_MEMWRT   : "   <<  CTRL_SIG[13]     << endl;
				cout << "CS_M2R      : "   <<  CTRL_SIG[14]     << endl;
				cout << "CS_WRTSRC   : "   <<  CTRL_SIG[15]     << endl;
				cout << "CS_REGWRT   : "   <<  CTRL_SIG[16]     << endl;	

				printf("\n\nRegisterFile \n");	
				printf("Reg00(00) := 00000000 \t");
				printf("Reg01(ra) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[0]);
				printf("Reg02(sp) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[1]);
				printf("Reg03(gp) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[2]);
				printf("Reg04(tp) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[3]);
				printf("Reg05(t0) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[4]);
				printf("Reg06(t1) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[5]);
				printf("Reg07(t2) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[6]);
				printf("Reg08(s0) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[7]);
				printf("Reg09(s1) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[8]);
				printf("Reg10(a0) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[9]);
				printf("Reg11(a1) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[10]);
				printf("Reg12(a2) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[11]);
				printf("Reg13(a3) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[12]);
				printf("Reg14(a4) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[13]);
				printf("Reg15(a5) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[14]);
				printf("Reg16(a6) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[15]);
				printf("Reg17(a7) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[16]);
				printf("Reg18(s2) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[17]);
				printf("Reg19(s3) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[18]);
				printf("Reg20(s4) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[19]);
				printf("Reg21(s5) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[20]);
				printf("Reg22(s6) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[21]);
				printf("Reg23(s7) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[22]);
				printf("Reg24(s8) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[23]);
				printf("Reg25(s9) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[24]);
				printf("Reg26(sA) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[25]);
				printf("Reg27(sB) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[26]);
				printf("Reg28(t3) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[27]);
				printf("Reg29(t4) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[28]);
				printf("Reg30(t5) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[29]);
				printf("Reg31(t6) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[30]);

				printf("Output location: %d \n",top->PRINT_VAL);
				printf("Enable: %d \n",top->PRINT_EN);
			// }

			


			#endif

			#ifdef COMPARE

			if (top->CorePipe__DOT__MW_REGWRT){

				getchar();
				printf("%d\t%d \n",counter,printCounter);

				// printf("\n\nFetech-Decode Latches \n");
				// fd_IRReg = bitset<32>(top->CorePipe__DOT__FD_IR ).to_string();
				// fd_IRRegOPcode = bitset<7>(top->CorePipe__DOT__FD_IR & 0x0000007F).to_string();
				// fd_IRRegrd     = bitset<5>((top->CorePipe__DOT__FD_IR & 0x00000F80)>>7).to_string();
				// fd_IRRegfunct3 = bitset<3>((top->CorePipe__DOT__FD_IR & 0x00007000)>>12).to_string();
				// fd_IRRegrs1    = bitset<5>((top->CorePipe__DOT__FD_IR & 0x000F8000)>>15).to_string();
				// fd_IRRegrs2    = bitset<5>((top->CorePipe__DOT__FD_IR & 0x01F00000)>>20).to_string();
				// fd_IRRegImm    = bitset<7>((top->CorePipe__DOT__FD_IR & 0xFE000000)>>25).to_string();

				// cout << "IRReg : " << fd_IRRegImm << "_" << fd_IRRegrs2 << "_" << fd_IRRegrs1 << "_" << fd_IRRegfunct3 << "_" << fd_IRRegrd << "_" << fd_IRRegOPcode << endl;

				// printf("IRReg := %08x \t", top->CorePipe__DOT__FD_IR);
				// printf("PCReg := %08x \t", (top->CorePipe__DOT__FD_PC + 0x10054));

				// printf("\n\nDecode-Execute Latches \n");
				
				// printf("IRReg := %08x \t", top->CorePipe__DOT__DE_IR);
				// printf("PCReg := %08x \n", (top->CorePipe__DOT__DE_PC+ 0x10054));
				// printf("RS1   := %08x \t", top->CorePipe__DOT__DE_SRC1);
				// printf("RS2   := %08x \t", top->CorePipe__DOT__DE_SRC2);
				// printf("Imm   := %08x \t", top->CorePipe__DOT__DE_IMM_EXT);
				// printf("\naluSrc1 := %08x \t ", top->CorePipe__DOT__ALU_IN1);
				// printf("aluSrc2 := %08x \t ", top->CorePipe__DOT__ALU_IN2);
	
				// printf("\nA_sel\tB_sel\tjumpR\tbranch\tjump\tmem_wrt\n");
				// printf("%d \t ", top->CorePipe__DOT__DE_ALUSRC1);
				// printf("%d \t ", top->CorePipe__DOT__DE_ALUSRC2);
				// printf("%d \t ", top->CorePipe__DOT__DE_JUMPR);
				// printf("%d \t ", top->CorePipe__DOT__DE_BRN);
				// printf("%d \t ", top->CorePipe__DOT__DE_JUMP);
				// printf("%d \t ", top->CorePipe__DOT__DE_MEMWRT);
				
				// printf("\nregwrt\tmem_rd \taluop\twbSel\tflush\tstall\n");
				// printf("%d \t ", top->CorePipe__DOT__DE_REGWRT);
				// printf("%d \t ", top->CorePipe__DOT__DE_MEMRD);
				// printf("%d \t ", top->CorePipe__DOT__DE_ALUOP);
				// printf("%d,%d \t ", top->CorePipe__DOT__DE_M2R,top->CorePipe__DOT__DE_WRTSRC);
				// printf("%d \t ", top->CorePipe__DOT__FLUSH);
				// printf("%d \t ", top->CorePipe__DOT__STALL);

				// printf("\n\nExecute-MemoryAccess Latches \n");
				// printf("IRReg := %08x \t ", top->CorePipe__DOT__EM_IR);
				// printf("PCReg := %08x \t ", (top->CorePipe__DOT__EM_PC_PLUSFOUR+ 0x10050));
				// printf("ALUout:= %08x \t ", top->CorePipe__DOT__EM_ALUOUT);
				// printf("RS2   := %08x \t ", top->CorePipe__DOT__EM_SRC2);

				// printf("\nmemrd\tmemwrt \tregwrt\twbSel\n");
				// printf("%d \t ", top->CorePipe__DOT__EM_MEMRD);
				// printf("%d \t ", top->CorePipe__DOT__EM_MEMWRT);
				// printf("%d \t ", top->CorePipe__DOT__EM_REGWRT);
				// printf("%d,%d \t ", top->CorePipe__DOT__EM_M2R,top->CorePipe__DOT__EM_WRTSRC);

				// printf("\n\nMemoryAccess-WriteBack Latches \n");
				// printf("IRReg := %08x \t ", top->CorePipe__DOT__MW_IR);
				// printf("PCReg := %08x \t ", (top->CorePipe__DOT__MW_PC_PLUSFOUR+ 0x10050));
				// printf("ALUout:= %08x \t ", top->CorePipe__DOT__MW_ALUOUT);
				// printf("Rdata := %08x \t ", top->CorePipe__DOT__MW_R_DATA);
				// //printf("wrtDa := %08x \t ", top->CorePipe__DOT__REG_IN);

				// printf("\nregWrt\twbSel\n");
				// printf("%d \t ", top->CorePipe__DOT__MW_REGWRT);
				// printf("%d,%d \t ", top->CorePipe__DOT__MW_M2R,top->CorePipe__DOT__MW_WRTSRC);

				printf ("PC: %08x \n", top->CorePipe__DOT__FD_PC + 0x10054);
				printf ("Instruction %d: %08x \n" , int(counter/2), top->CorePipe__DOT__FD_IR);
				cout << "CS_TYPE     : "   <<  CTRL_SIG[0]  << CTRL_SIG[1] << CTRL_SIG[2] << endl;
				cout << "CS_JUMP     : "   <<  CTRL_SIG[3]    << endl;
				cout << "CS_JUMPR    : "   <<  CTRL_SIG[4]    << endl;
				cout << "CS_BRANCH   : "   <<  CTRL_SIG[5]    << endl;
				cout << "CS_ALUOP    : "   <<  CTRL_SIG[6]  << CTRL_SIG[7] <<  CTRL_SIG[8] << CTRL_SIG[9] << endl;
				cout << "CS_ALUSRC1  : "   <<  CTRL_SIG[10]     << endl;
				cout << "CS_ALUSRC2  : "   <<  CTRL_SIG[11]     << endl;
				cout << "CS_MEMRD    : "   <<  CTRL_SIG[12]     << endl; 
				cout << "CS_MEMWRT   : "   <<  CTRL_SIG[13]     << endl;
				cout << "CS_M2R      : "   <<  CTRL_SIG[14]     << endl;
				cout << "CS_WRTSRC   : "   <<  CTRL_SIG[15]     << endl;
				cout << "CS_REGWRT   : "   <<  CTRL_SIG[16]     << endl;	

				printf("\n\nRegisterFile \n");	
				printf("Reg00(00) := 00000000 \t");
				printf("Reg01(ra) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[0]);
				printf("Reg02(sp) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[1]);
				printf("Reg03(gp) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[2]);
				printf("Reg04(tp) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[3]);
				printf("Reg05(t0) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[4]);
				printf("Reg06(t1) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[5]);
				printf("Reg07(t2) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[6]);
				printf("Reg08(s0) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[7]);
				printf("Reg09(s1) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[8]);
				printf("Reg10(a0) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[9]);
				printf("Reg11(a1) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[10]);
				printf("Reg12(a2) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[11]);
				printf("Reg13(a3) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[12]);
				printf("Reg14(a4) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[13]);
				printf("Reg15(a5) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[14]);
				printf("Reg16(a6) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[15]);
				printf("Reg17(a7) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[16]);
				printf("Reg18(s2) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[17]);
				printf("Reg19(s3) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[18]);
				printf("Reg20(s4) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[19]);
				printf("Reg21(s5) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[20]);
				printf("Reg22(s6) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[21]);
				printf("Reg23(s7) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[22]);
				printf("Reg24(s8) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[23]);
				printf("Reg25(s9) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[24]);
				printf("Reg26(sA) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[25]);
				printf("Reg27(sB) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[26]);
				printf("Reg28(t3) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[27]);
				printf("Reg29(t4) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[28]);
				printf("Reg30(t5) := %08x \t", top->CorePipe__DOT__RegFile__DOT__REG[29]);
				printf("Reg31(t6) := %08x \n", top->CorePipe__DOT__RegFile__DOT__REG[30]);

				printf("Output location: %d \n",top->PRINT_VAL);
				printf("Enable: %d \n",top->PRINT_EN);
			}

			


			#endif

		
		}



		



		

		// usleep(20);
		top->eval(); 
		// if(clock == 1) getchar();
		// getchar();

		usleep(5);
	}

	delete top;
	exit(0);
}

