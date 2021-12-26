// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCOREPIPE_H_
#define _VCOREPIPE_H_  // guard

#include "verilated_heavy.h"

//==========

class VCorePipe__Syms;

//----------

VL_MODULE(VCorePipe) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK,0,0);
    VL_IN8(RESET,0,0);
    VL_OUT8(PRINT_EN,0,0);
    VL_OUT(PRINT_VAL,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ CorePipe__DOT__BRNEN;
    CData/*0:0*/ CorePipe__DOT__FLUSH;
    CData/*0:0*/ CorePipe__DOT__STALL;
    CData/*0:0*/ CorePipe__DOT__DE_JUMP;
    CData/*0:0*/ CorePipe__DOT__DE_JUMPR;
    CData/*0:0*/ CorePipe__DOT__MW_REGWRT;
    CData/*2:0*/ CorePipe__DOT__DE_TYPE;
    CData/*0:0*/ CorePipe__DOT__DE_BRN;
    CData/*0:0*/ CorePipe__DOT__DE_ALUSRC1;
    CData/*0:0*/ CorePipe__DOT__DE_ALUSRC2;
    CData/*3:0*/ CorePipe__DOT__DE_ALUOP;
    CData/*0:0*/ CorePipe__DOT__DE_REGWRT;
    CData/*0:0*/ CorePipe__DOT__DE_MEMRD;
    CData/*0:0*/ CorePipe__DOT__DE_MEMWRT;
    CData/*0:0*/ CorePipe__DOT__DE_WRTSRC;
    CData/*0:0*/ CorePipe__DOT__DE_M2R;
    CData/*0:0*/ CorePipe__DOT__EM_REGWRT;
    CData/*0:0*/ CorePipe__DOT__EM_MEMRD;
    CData/*0:0*/ CorePipe__DOT__EM_MEMWRT;
    CData/*0:0*/ CorePipe__DOT__EM_WRTSRC;
    CData/*0:0*/ CorePipe__DOT__EM_M2R;
    CData/*0:0*/ CorePipe__DOT__MW_WRTSRC;
    CData/*0:0*/ CorePipe__DOT__MW_M2R;
    CData/*0:0*/ CorePipe__DOT__BranchLogic__DOT__w_equal;
    CData/*0:0*/ CorePipe__DOT__BranchLogic__DOT__w_signed;
    CData/*0:0*/ CorePipe__DOT__BranchLogic__DOT__w_unsigned;
    CData/*7:0*/ CorePipe__DOT__DataMemory__DOT__LB;
    SData/*10:0*/ CorePipe__DOT__Control__DOT__INS_ARR;
    SData/*15:0*/ CorePipe__DOT__DataMemory__DOT__LH;
    IData/*31:0*/ CorePipe__DOT__JUMP_BRANCH_TARGET;
    IData/*31:0*/ CorePipe__DOT__IMM_EXT;
    IData/*31:0*/ CorePipe__DOT__PC_sig;
    IData/*31:0*/ CorePipe__DOT__REG_IN;
    IData/*31:0*/ CorePipe__DOT__ALU_IN1;
    IData/*31:0*/ CorePipe__DOT__ALU_IN2;
    IData/*31:0*/ CorePipe__DOT__FD_PC;
    IData/*31:0*/ CorePipe__DOT__FD_IR;
    IData/*31:0*/ CorePipe__DOT__MW_IR;
    IData/*31:0*/ CorePipe__DOT__DE_PC;
    IData/*31:0*/ CorePipe__DOT__DE_IR;
    IData/*31:0*/ CorePipe__DOT__DE_PC_PLUSFOUR;
    IData/*31:0*/ CorePipe__DOT__DE_SRC1;
    IData/*31:0*/ CorePipe__DOT__DE_SRC2;
    IData/*31:0*/ CorePipe__DOT__DE_IMM_EXT;
    IData/*31:0*/ CorePipe__DOT__EM_PC_PLUSFOUR;
    IData/*31:0*/ CorePipe__DOT__EM_SRC2;
    IData/*31:0*/ CorePipe__DOT__EM_IR;
    IData/*31:0*/ CorePipe__DOT__EM_ALUOUT;
    IData/*31:0*/ CorePipe__DOT__MW_PC_PLUSFOUR;
    IData/*31:0*/ CorePipe__DOT__MW_ALUOUT;
    IData/*31:0*/ CorePipe__DOT__MW_R_DATA;
    IData/*16:0*/ CorePipe__DOT__Control__DOT__control_sig;
    IData/*31:0*/ CorePipe__DOT__DataMemory__DOT__LW;
    IData/*31:0*/ CorePipe__DOT__DataMemory__DOT__BYTE_WR;
    IData/*31:0*/ CorePipe__DOT__DataMemory__DOT__HALF_WR;
    IData/*31:0*/ CorePipe__DOT__InstMemory__DOT__I_MEM[33554432];
    IData/*31:0*/ CorePipe__DOT__RegFile__DOT__REG[31];
    IData/*31:0*/ CorePipe__DOT__DataMemory__DOT__D_MEM[33554432];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__CLK;
    IData/*31:0*/ CorePipe__DOT__RegFile__DOT____Vlvbound2;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VCorePipe__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VCorePipe);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VCorePipe(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VCorePipe();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VCorePipe__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VCorePipe__Syms* symsp, bool first);
  private:
    static QData _change_request(VCorePipe__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VCorePipe__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VCorePipe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VCorePipe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VCorePipe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VCorePipe__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VCorePipe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
