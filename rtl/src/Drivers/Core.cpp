#include "VCore.h"
#include "verilated.h"

 // #define DEBUG
// #define COMPARE


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
	string PRINT_COUNT;
	cout << "Do you want to print the clock cycle counts? [Y/N] : " ;
	cin >> PRINT_COUNT;
	cout << "\n" ;
	Verilated::commandArgs(argc, argv);

	VCore* top = new VCore;

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
	if(PRINT_COUNT == "Y" or PRINT_COUNT == "y"){
		printf("    Clock Count  | RegWrt Count  |  Character \n");
		printf("    -----------------------------------------  \n");
	}
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

			CTRL_SIG = bitset<17>(top->Core__DOT__Control__DOT__control_sig).to_string();
			if (CTRL_SIG[16] == '1'){
				printCounter ++;
			}
			
			if(top->PRINT_EN){
				if(PRINT_COUNT == "Y" or PRINT_COUNT == "y"){
					printf("\t%d\t\t%d",counter,printCounter);
					printf("\t\t%c\n",top->PRINT_VAL);
				}
				else {
					printf("%c",top->PRINT_VAL);
				}
			}
		


			#ifdef DEBUG

			if (CTRL_SIG[16] == '1'){

				getchar();

				printf("%d\t%d\n",counter,printCounter);
				
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
				
				printf ("PC: %08x \n", top->Core__DOT__PC + 0x10054);
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

			#ifdef COMPARE

			if (CTRL_SIG[16] == '1'){

				getchar();

				printf("%d\t%d\n",counter,printCounter);
				
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
				
				printf ("PC: %08x \n", top->Core__DOT__PC + 0x10054);
				//fprintf (out, "PC: %08x \n", top->Core__DOT__PC);
				printf ("Instruction %d: %08x \n" , int(counter/2), top->Core__DOT__INSTRUCTION);
				// //fprintf (out, "Instruction %d: %08x \n" , int(counter/2), top->Core__DOT__INSTRUCTION);
				// cout << "CS_TYPE     : "   <<  CTRL_SIG[0]  << CTRL_SIG[1] << CTRL_SIG[2] << endl;
				// cout << "CS_JUMP     : "   <<  CTRL_SIG[3]    << endl;
				// cout << "CS_JUMPR    : "   <<  CTRL_SIG[4]    << endl;
				// cout << "CS_BRANCH   : "   <<  CTRL_SIG[5]    << endl;
				// cout << "CS_ALUOP    : "   <<  CTRL_SIG[6]  << CTRL_SIG[7] <<  CTRL_SIG[8] << CTRL_SIG[9] << endl;
				// cout << "CS_ALUSRC1  : "   <<  CTRL_SIG[10]     << endl;
				// cout << "CS_ALUSRC2  : "   <<  CTRL_SIG[11]     << endl;
				// cout << "CS_MEMRD    : "   <<  CTRL_SIG[12]     << endl; 
				// cout << "CS_MEMWRT   : "   <<  CTRL_SIG[13]     << endl;
				// cout << "CS_M2R      : "   <<  CTRL_SIG[14]     << endl;
				// cout << "CS_WRTSRC   : "   <<  CTRL_SIG[15]     << endl;
				// cout << "CS_REGWRT   : "   <<  CTRL_SIG[16]     << endl;

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



			for (size_t i = 768; i < 33554432; i++)
				{
					if (top->Core__DOT__DataMemory__DOT__D_MEM[i] != 0){
						printf("%lu \t : %08x \n", i , top->Core__DOT__DataMemory__DOT__D_MEM[i]);
					}
					/* code */
				}
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

