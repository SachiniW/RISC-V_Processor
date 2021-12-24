// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCORE_H_
#define _VCORE_H_  // guard

#include "verilated_heavy.h"

//==========

class VCore__Syms;

//----------

VL_MODULE(VCore) {
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
    CData/*0:0*/ Core__DOT__BranchLogic__DOT__w_equal;
    CData/*0:0*/ Core__DOT__BranchLogic__DOT__w_signed;
    CData/*0:0*/ Core__DOT__BranchLogic__DOT__w_unsigned;
    CData/*7:0*/ Core__DOT__DataMemory__DOT__LB;
    SData/*10:0*/ Core__DOT__Control__DOT__INS_ARR;
    SData/*15:0*/ Core__DOT__DataMemory__DOT__LH;
    IData/*31:0*/ Core__DOT__INSTRUCTION;
    IData/*31:0*/ Core__DOT__JUMP_BRANCH_TARGET;
    IData/*31:0*/ Core__DOT__SRC1;
    IData/*31:0*/ Core__DOT__SRC2;
    IData/*31:0*/ Core__DOT__IMM_EXT;
    IData/*31:0*/ Core__DOT__PC_sig;
    IData/*31:0*/ Core__DOT__ALUOUT;
    IData/*31:0*/ Core__DOT__R_DATA;
    IData/*31:0*/ Core__DOT__ALU_IN1;
    IData/*31:0*/ Core__DOT__ALU_IN2;
    IData/*31:0*/ Core__DOT__PC;
    IData/*16:0*/ Core__DOT__Control__DOT__control_sig;
    IData/*31:0*/ Core__DOT__DataMemory__DOT__LW;
    IData/*31:0*/ Core__DOT__DataMemory__DOT__BYTE_WR;
    IData/*31:0*/ Core__DOT__DataMemory__DOT__HALF_WR;
    IData/*31:0*/ Core__DOT__InstMemory__DOT__I_MEM[67108864];
    IData/*31:0*/ Core__DOT__RegFile__DOT__REG[31];
    IData/*31:0*/ Core__DOT__DataMemory__DOT__D_MEM[2];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__CLK;
    IData/*31:0*/ Core__DOT__RegFile__DOT____Vlvbound2;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VCore__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VCore);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VCore(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VCore();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VCore__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VCore__Syms* symsp, bool first);
  private:
    static QData _change_request(VCore__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VCore__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VCore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VCore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VCore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VCore__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VCore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
