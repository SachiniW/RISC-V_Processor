#include "VCore.h"
#include "verilated.h"

//  #define DEBUG
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

	VCore* top = new VCore;

	//ofstream out;

	//FILE *out;

	//out=fopen ("Core.txt","w");
  	//out << "Writing this to a file.\n";
	//fprintf (out, "Start \n");

	int counter = 0;
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

	static int clock = 0;


	while (!Verilated::gotFinish())
	{
		
		clock = (clock+1) & 1;
	    
		counter = counter + 1;

		top->CLK = clock;
		
		if(counter < 10){
			top->RESET = HIGH;
		}
		else{
			top->RESET = LOW;
		}
	
		if(clock == 1){
			//printf("%d \n",counter);
			if(top->PRINT_EN){
				//printf("%d\t%d",counter,printCounter);
				// printf("\t%c\n",top->io_printVal);
				//printf("\t%c\n",top->PRINT_VAL);

				printf("%c",top->PRINT_VAL);

				// printf("\t %08x \t %08x  \n",top->io_pc-8,top->io_printval        IData/*31:0*/ Core__DOT__pcsel_io_pcOut;
			}
			

			CTRL_SIG = bitset<17>(top->Core__DOT__Control__DOT__control_sig).to_string();
			if (CTRL_SIG[16] == '1'){
				printCounter ++;
			}

		//counter = counter + 1;
		// if(clock == 1){
		// 	//printf("%d \n",counter);
		// 	if(top->PRINT_EN){
		// 		// printf("%d",counter);
		// 		// printf("\t%c\n",top->io_printVal);
		// 		printf("%c",top->PRINT_VAL);
		// 		// printf("\t %08x \t %08x  \n",top->io_pc-8,top->io_printval        IData/*31:0*/ Core__DOT__pcsel_io_pcOut;
		// 	}


			#ifdef DEBUG
				getchar();
				
				printf("%d\t%d\t",counter,top->reset);
				printf("Count := %08x \t ", printCounter);

			
				printf("\n\nBranchPr-Fetch Latches \n");
				printf("PCReg := %08x \t", (top->Core__DOT__bf_PCReg + 0x10054));
				
				// printf("IRReg := %08x \t", top->Core__DOT__icache__DOT__rdata);
			

				printf("\n\nFetech-Decode Latches \n");
				fd_IRReg = bitset<32>(top->Core__DOT__fd_IRReg ).to_string();
				fd_IRRegOPcode = bitset<7>(top->Core__DOT__fd_IRReg & 0x0000007F).to_string();
				fd_IRRegrd     = bitset<5>((top->Core__DOT__fd_IRReg & 0x00000F80)>>7).to_string();
				fd_IRRegfunct3 = bitset<3>((top->Core__DOT__fd_IRReg & 0x00007000)>>12).to_string();
				fd_IRRegrs1    = bitset<5>((top->Core__DOT__fd_IRReg & 0x000F8000)>>15).to_string();
				fd_IRRegrs2    = bitset<5>((top->Core__DOT__fd_IRReg & 0x01F00000)>>20).to_string();
				fd_IRRegImm    = bitset<7>((top->Core__DOT__fd_IRReg & 0xFE000000)>>25).to_string();


				cout << "IRReg : " << fd_IRRegImm << "_" << fd_IRRegrs2 << "_" << fd_IRRegrs1 << "_" << fd_IRRegfunct3 << "_" << fd_IRRegrd << "_" << fd_IRRegOPcode << endl;

			
				printf("IRReg := %08x \t", top->Core__DOT__fd_IRReg);
				printf("PCReg := %08x \t", (top->Core__DOT__fd_PCReg + 0x10054));
				// printf("bhtbEn:= %d   \t", top->io_bhtbEn); 
				// printf("Target Address: %08x\t", top->io_targetAddr);

				printf("\n\nDecode-Execute Latches \n");
				
				printf("IRReg := %08x \t", top->Core__DOT__de_IRReg);
				printf("PCReg := %08x \n", (top->Core__DOT__de_PCReg+ 0x10054));
				printf("RS1   := %08x \t", top->Core__DOT__de_rsData1Reg);
				printf("RS2   := %08x \t", top->Core__DOT__de_rsData2Reg);
				printf("Imm   := %08x \t", top->Core__DOT__de_ImmReg);
				printf("\naluSrc1 := %08x \t ", top->Core__DOT__alu_io_A);
				printf("aluSrc2 := %08x \t ", top->Core__DOT__alu_io_B);
				printf("\nFSEL1 := %1d  \t ", top->Core__DOT__forwardingUnit_io_frs1_sel);
				printf("FSEL2 := %1d  \t ", top->Core__DOT__forwardingUnit_io_frs2_sel);
				printf("bhtbEn := %1d  \t ", top->Core__DOT__de_bhtbEnReg);
				

				
				printf("\nA_sel\tB_sel\tjumpR\tbranch\tjump\tmem_wrt\tbEn\n");
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSaluSrcA);
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSaluSrcB);
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSjumpReg);
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSbranch);
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSjump);
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSmemWrite);
				printf("%d \t ", top->Core__DOT__branchLogic_io_br_taken);

				printf("\nregwrt\tmem_rd \taluop\twbSel\tflush\tstall\n");
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSregWrite);
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSmemRead);
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSaluOp);
				printf("%d \t ", top->Core__DOT__de_CtrlSigReg_CSwbSel);
				printf("%d \t ", top->Core__DOT__flush);
				printf("%d \t ", top->Core__DOT__forwardingUnit_io_stall);

				printf("\n\nExecute-MemoryAccess Latches \n");
				printf("IRReg := %08x \t ", top->Core__DOT__em_IRReg);
				printf("PCReg := %08x \t ", (top->Core__DOT__em_PCReg+ 0x10054));
				printf("ALUout:= %08x \t ", top->Core__DOT__em_aluOutReg);
				printf("RS2   := %08x \t ", top->Core__DOT__em_rsData2Reg);

				printf("\nmemrd\tmemwrt \tregwrt\twbSel\n");
				printf("%d \t ", top->Core__DOT__em_CtrlSigReg_CSmemRead);
				printf("%d \t ", top->Core__DOT__em_CtrlSigReg_CSmemWrite);
				printf("%d \t ", top->Core__DOT__em_CtrlSigReg_CSregWrite);
				printf("%d \t ", top->Core__DOT__em_CtrlSigReg_CSwbSel);

				
				printf("\n\nMemoryAccess-WriteBack Latches \n");
				printf("IRReg := %08x \t ", top->Core__DOT__mw_rdReg);
				printf("PCReg := %08x \t ", (top->Core__DOT__mw_pcPlusFourReg+ 0x10054));
				printf("ALUout:= %08x \t ", top->Core__DOT__mw_aluOutReg);
				printf("Rdata := %08x \t ", top->Core__DOT__dMem_io_rData);
				printf("wrtDa := %08x \t ", top->Core__DOT__registerFile_io_wData);

				printf("\nregWrt\twbSel\n");
				printf("%d \t ", top->Core__DOT__mw_CtrlSigReg_CSregWrite);
				printf("%d \t ", top->Core__DOT__mw_CtrlSigReg_CSwbSel);


				// printf("\nMemory Address %08x\t%08x\t%08x", top->Core__DOT__dcache__DOT__mem[0x3FFFD6],
				// 											top->Core__DOT__dcache__DOT__mem[0x3FFFD7],
				// 											top->Core__DOT__dcache__DOT__mem[0x3FFFD8]	 );

				// printf("\n wdata := %08x", top->io_wtdata);

					
				printf("\n\nRegisterFile \n");	
				printf("Reg00(00) := %08x \t", top->Core__DOT__RegFile__DOT__REG[0];);
				printf("Reg01(ra) := %08x \t", top->Core__DOT__RegFile__DOT__REG[1];);
				printf("Reg02(sp) := %08x \t", top->Core__DOT__RegFile__DOT__REG[2];);
				printf("Reg03(gp) := %08x \n", top->Core__DOT__RegFile__DOT__REG[3];);
				printf("Reg04(tp) := %08x \t", top->Core__DOT__RegFile__DOT__REG[4];);
				printf("Reg05(t0) := %08x \t", top->Core__DOT__RegFile__DOT__REG[5];);
				printf("Reg06(t1) := %08x \t", top->Core__DOT__RegFile__DOT__REG[6];);
				printf("Reg07(t2) := %08x \n", top->Core__DOT__RegFile__DOT__REG[7];);
				printf("Reg08(s0) := %08x \t", top->Core__DOT__RegFile__DOT__REG[8];);
				printf("Reg09(s1) := %08x \t", top->Core__DOT__RegFile__DOT__REG[9];);
				printf("Reg10(a0) := %08x \t", top->Core__DOT__RegFile__DOT__REG[10];);
				printf("Reg11(a1) := %08x \n", top->Core__DOT__RegFile__DOT__REG[11];);
				printf("Reg12(a2) := %08x \t", top->Core__DOT__RegFile__DOT__REG[12];);
				printf("Reg13(a3) := %08x \t", top->Core__DOT__RegFile__DOT__REG[13];);
				printf("Reg14(a4) := %08x \t", top->Core__DOT__RegFile__DOT__REG[14];);
				printf("Reg15(a5) := %08x \n", top->Core__DOT__RegFile__DOT__REG[15];);
				printf("Reg16(a6) := %08x \t", top->Core__DOT__RegFile__DOT__REG[16];);
				printf("Reg17(a7) := %08x \t", top->Core__DOT__RegFile__DOT__REG[17];);
				printf("Reg18(s2) := %08x \t", top->Core__DOT__RegFile__DOT__REG[18];);
				printf("Reg19(s3) := %08x \n", top->Core__DOT__RegFile__DOT__REG[19];);
				printf("Reg20(s4) := %08x \t", top->Core__DOT__RegFile__DOT__REG[20];);
				printf("Reg21(s5) := %08x \t", top->Core__DOT__RegFile__DOT__REG[21];);
				printf("Reg22(s6) := %08x \t", top->Core__DOT__RegFile__DOT__REG[22];);
				printf("Reg23(s7) := %08x \n", top->Core__DOT__RegFile__DOT__REG[23];);
				printf("Reg24(s8) := %08x \t", top->Core__DOT__RegFile__DOT__REG[24];);
				printf("Reg25(s9) := %08x \t", top->Core__DOT__RegFile__DOT__REG[25];);
				printf("Reg26(sA) := %08x \t", top->Core__DOT__RegFile__DOT__REG[26];);
				printf("Reg27(sB) := %08x \n", top->Core__DOT__RegFile__DOT__REG[27];);
				printf("Reg28(t3) := %08x \t", top->Core__DOT__RegFile__DOT__REG[28];);
				printf("Reg29(t4) := %08x \t", top->Core__DOT__RegFile__DOT__REG[29];);
				printf("Reg30(t5) := %08x \t", top->Core__DOT__RegFile__DOT__REG[30];);
				printf("Reg31(t6) := %08x \n", top->Core__DOT__RegFile__DOT__REG[31];);
				if (top->Core__DOT__mw_CtrlSigReg_CSregWrite){
					++printCounter;}


			#endif


			#ifdef COMPARE


			if (CTRL_SIG[16] == '1'){

				getchar();

				//printf("%d\t%d\n",counter,printCounter);
				
				// out << showbase << hex << (top->Core__DOT__mw_pcPlusFourReg+ 0x10050) << endl;
				// printf("IRReg := %08x \t ", top->Core__DOT__mw_rdReg);
				// printf("PCReg := %08x \t ", (top->Core__DOT__mw_pcPlusFourReg+ 0x10050));
				// printf("Count := %08x \t ", ++printCounter);
				// printf("ALUout:= %08x \t ", top->Core__DOT__mw_aluoutReg);
				// printf("Rdata := %08x \t ", top->Core__DOT__dcache_io_rdata);
				// printf("wrtDa := %08x \t ", top->Core__DOT__registerFile_io_wdata);

				// printf("\nregWrt\tmem2R \twrtSrc\n");
				// printf("%d \t ", top->Core__DOT__mw_CtrlSigReg_CSregWrite);
				// printf("%d \t ", top->Core__DOT__mw_CtrlSigReg_CSmem2Reg);
				// printf("%d \t ", top->Core__DOT__mw_CtrlSigReg_CSwrtSrc);

				// printf("\nMemory Address %08x\t%08x\t%08x", top->Core__DOT__dcache__DOT__mem[0x3FFFD6],
				// 											top->Core__DOT__dcache__DOT__mem[0x3FFFD7],
				// 											top->Core__DOT__dcache__DOT__mem[0x3FFFD8]	 );
				// CTRL_SIG = bitset<17>(top->Core__DOT__Control__DOT__control_sig).to_string();

				cout << "\nPrint Counter :" << printCounter << endl;
				
				printf ("PC: %08x \n", top->Core__DOT__PC);
				//fprintf (out, "PC: %08x \n", top->Core__DOT__PC);
				printf ("Instruction %d: %08x \n" , int(counter/2), top->Core__DOT__INSTRUCTION);
				//fprintf (out, "Instruction %d: %08x \n" , int(counter/2), top->Core__DOT__INSTRUCTION);
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

				// if (CTRL_SIG[16] == "1"){
				// 	printCounter ++;
				// }

						
				printf("\n\nRegisterFile \n");	
				printf("Reg00(00) := 00000000 \t");
				printf("Reg01(ra) := %08x \t", top->Core__DOT__RegFile__DOT__REG[0]);
				printf("Reg02(sp) := %08x \t", top->Core__DOT__RegFile__DOT__REG[1]);
				printf("Reg03(gp) := %08x \n", top->Core__DOT__RegFile__DOT__REG[2]);
				printf("Reg04(tp) := %08x \t", top->Core__DOT__RegFile__DOT__REG[3]);
				printf("Reg05(t0) := %08x \t", top->Core__DOT__RegFile__DOT__REG[4]);
				printf("Reg06(t1) := %08x \t", top->Core__DOT__RegFile__DOT__REG[5]);
				printf("Reg07(t2) := %08x \n", top->Core__DOT__RegFile__DOT__REG[6]);
				printf("Reg08(s0) := %08x \t", top->Core__DOT__RegFile__DOT__REG[7]);
				printf("Reg09(s1) := %08x \t", top->Core__DOT__RegFile__DOT__REG[8]);
				printf("Reg10(a0) := %08x \t", top->Core__DOT__RegFile__DOT__REG[9]);
				printf("Reg11(a1) := %08x \n", top->Core__DOT__RegFile__DOT__REG[10]);
				printf("Reg12(a2) := %08x \t", top->Core__DOT__RegFile__DOT__REG[11]);
				printf("Reg13(a3) := %08x \t", top->Core__DOT__RegFile__DOT__REG[12]);
				printf("Reg14(a4) := %08x \t", top->Core__DOT__RegFile__DOT__REG[13]);
				printf("Reg15(a5) := %08x \n", top->Core__DOT__RegFile__DOT__REG[14]);
				printf("Reg16(a6) := %08x \t", top->Core__DOT__RegFile__DOT__REG[15]);
				printf("Reg17(a7) := %08x \t", top->Core__DOT__RegFile__DOT__REG[16]);
				printf("Reg18(s2) := %08x \t", top->Core__DOT__RegFile__DOT__REG[17]);
				printf("Reg19(s3) := %08x \n", top->Core__DOT__RegFile__DOT__REG[18]);
				printf("Reg20(s4) := %08x \t", top->Core__DOT__RegFile__DOT__REG[19]);
				printf("Reg21(s5) := %08x \t", top->Core__DOT__RegFile__DOT__REG[20]);
				printf("Reg22(s6) := %08x \t", top->Core__DOT__RegFile__DOT__REG[21]);
				printf("Reg23(s7) := %08x \n", top->Core__DOT__RegFile__DOT__REG[22]);
				printf("Reg24(s8) := %08x \t", top->Core__DOT__RegFile__DOT__REG[23]);
				printf("Reg25(s9) := %08x \t", top->Core__DOT__RegFile__DOT__REG[24]);
				printf("Reg26(sA) := %08x \t", top->Core__DOT__RegFile__DOT__REG[25]);
				printf("Reg27(sB) := %08x \n", top->Core__DOT__RegFile__DOT__REG[26]);
				printf("Reg28(t3) := %08x \t", top->Core__DOT__RegFile__DOT__REG[27]);
				printf("Reg29(t4) := %08x \t", top->Core__DOT__RegFile__DOT__REG[28]);
				printf("Reg30(t5) := %08x \t", top->Core__DOT__RegFile__DOT__REG[29]);
				printf("Reg31(t6) := %08x \n", top->Core__DOT__RegFile__DOT__REG[30]);

				printf("Output location: %d \n",top->PRINT_VAL);
				printf("Enable: %d \n",top->PRINT_EN);
			}

			


			#endif


		
		}



		



		

		// usleep(20);
		top->eval(); 
		// if(clock == 1) getchar();
		// getchar();

		usleep(20);
	}
	//fclose(out);

	delete top;
	exit(0);
}

