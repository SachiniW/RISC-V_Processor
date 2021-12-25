// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCorePipe.h for the primary calling header

#include "VCorePipe.h"
#include "VCorePipe__Syms.h"

//==========

VL_CTOR_IMP(VCorePipe) {
    VCorePipe__Syms* __restrict vlSymsp = __VlSymsp = new VCorePipe__Syms(this, name());
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VCorePipe::__Vconfigure(VCorePipe__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VCorePipe::~VCorePipe() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VCorePipe::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCorePipe::eval\n"); );
    VCorePipe__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("CorePipe.v", 41, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCorePipe::_eval_initial_loop(VCorePipe__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("CorePipe.v", 41, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCorePipe::_initial__TOP__1(VCorePipe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_initial__TOP__1\n"); );
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*191:0*/ __Vtemp1[6];
    WData/*191:0*/ __Vtemp2[6];
    // Body
    vlTOPp->CorePipe__DOT__MW_PC_PLUSFOUR = 0U;
    vlTOPp->CorePipe__DOT__MW_ALUOUT = 0U;
    vlTOPp->CorePipe__DOT__MW_R_DATA = 0U;
    vlTOPp->CorePipe__DOT__MW_WRTSRC = 0U;
    vlTOPp->CorePipe__DOT__MW_M2R = 0U;
    __Vtemp1[0U] = 0x2e6d656dU;
    __Vtemp1[1U] = 0x6d6f7279U;
    __Vtemp1[2U] = 0x6e5f6d65U;
    __Vtemp1[3U] = 0x6374696fU;
    __Vtemp1[4U] = 0x73747275U;
    __Vtemp1[5U] = 0x696eU;
    VL_READMEM_N(true, 32, 33554432, 0, VL_CVT_PACK_STR_NW(6, __Vtemp1)
                 , vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM
                 , 0, ~VL_ULL(0));
    __Vtemp2[0U] = 0x2e6d656dU;
    __Vtemp2[1U] = 0x6d6f7279U;
    __Vtemp2[2U] = 0x6e5f6d65U;
    __Vtemp2[3U] = 0x6374696fU;
    __Vtemp2[4U] = 0x73747275U;
    __Vtemp2[5U] = 0x696eU;
    VL_READMEM_N(true, 32, 33554432, 0, VL_CVT_PACK_STR_NW(6, __Vtemp2)
                 , vlTOPp->CorePipe__DOT__InstMemory__DOT__I_MEM
                 , 0, ~VL_ULL(0));
    vlTOPp->CorePipe__DOT__MW_REGWRT = 0U;
    vlTOPp->CorePipe__DOT__EM_PC_PLUSFOUR = 0U;
    vlTOPp->CorePipe__DOT__EM_WRTSRC = 0U;
    vlTOPp->CorePipe__DOT__EM_M2R = 0U;
    vlTOPp->CorePipe__DOT__EM_SRC2 = 0U;
    vlTOPp->CorePipe__DOT__EM_MEMWRT = 0U;
    vlTOPp->CorePipe__DOT__DE_ALUSRC1 = 0U;
    vlTOPp->CorePipe__DOT__DE_ALUSRC2 = 0U;
    vlTOPp->CorePipe__DOT__MW_IR = 0U;
    vlTOPp->CorePipe__DOT__FD_PC = 0xfffffffcU;
    vlTOPp->CorePipe__DOT__EM_MEMRD = 0U;
    vlTOPp->CorePipe__DOT__DE_JUMP = 0U;
    vlTOPp->CorePipe__DOT__DE_JUMPR = 0U;
    vlTOPp->CorePipe__DOT__DE_PC = 0U;
    vlTOPp->CorePipe__DOT__DE_BRN = 0U;
    vlTOPp->CorePipe__DOT__DE_IMM_EXT = 0U;
    vlTOPp->CorePipe__DOT__EM_ALUOUT = 0U;
    vlTOPp->CorePipe__DOT__DE_SRC1 = 0U;
    vlTOPp->CorePipe__DOT__FD_IR = 0U;
    vlTOPp->CorePipe__DOT__DE_PC_PLUSFOUR = 0U;
    vlTOPp->CorePipe__DOT__DE_ALUOP = 0U;
    vlTOPp->CorePipe__DOT__DE_MEMRD = 0U;
    vlTOPp->CorePipe__DOT__DE_MEMWRT = 0U;
    vlTOPp->CorePipe__DOT__DE_WRTSRC = 0U;
    vlTOPp->CorePipe__DOT__DE_M2R = 0U;
    vlTOPp->CorePipe__DOT__EM_REGWRT = 0U;
    vlTOPp->CorePipe__DOT__EM_IR = 0U;
    vlTOPp->CorePipe__DOT__DE_SRC2 = 0U;
    vlTOPp->CorePipe__DOT__DE_REGWRT = 0U;
    vlTOPp->CorePipe__DOT__DE_IR = 0U;
}

VL_INLINE_OPT void VCorePipe::_sequent__TOP__2(VCorePipe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_sequent__TOP__2\n"); );
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__CorePipe__DOT__DE_ALUOP;
    CData/*0:0*/ __Vdly__CorePipe__DOT__DE_REGWRT;
    CData/*0:0*/ __Vdly__CorePipe__DOT__DE_MEMRD;
    CData/*0:0*/ __Vdly__CorePipe__DOT__DE_MEMWRT;
    CData/*0:0*/ __Vdly__CorePipe__DOT__DE_WRTSRC;
    CData/*0:0*/ __Vdly__CorePipe__DOT__DE_M2R;
    CData/*0:0*/ __Vdlyvset__CorePipe__DOT__RegFile__DOT__REG__v0;
    CData/*4:0*/ __Vdlyvdim0__CorePipe__DOT__RegFile__DOT__REG__v31;
    CData/*0:0*/ __Vdlyvset__CorePipe__DOT__RegFile__DOT__REG__v31;
    CData/*0:0*/ __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v0;
    CData/*0:0*/ __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v1;
    CData/*0:0*/ __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v2;
    IData/*31:0*/ __Vdly__CorePipe__DOT__FD_PC;
    IData/*31:0*/ __Vdly__CorePipe__DOT__FD_IR;
    IData/*31:0*/ __Vdly__CorePipe__DOT__DE_IR;
    IData/*31:0*/ __Vdly__CorePipe__DOT__DE_SRC1;
    IData/*31:0*/ __Vdly__CorePipe__DOT__DE_SRC2;
    IData/*31:0*/ __Vdly__CorePipe__DOT__DE_PC_PLUSFOUR;
    IData/*31:0*/ __Vdlyvval__CorePipe__DOT__RegFile__DOT__REG__v31;
    IData/*24:0*/ __Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v0;
    IData/*31:0*/ __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v0;
    IData/*24:0*/ __Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v1;
    IData/*31:0*/ __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v1;
    IData/*24:0*/ __Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v2;
    IData/*31:0*/ __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v2;
    // Body
    __Vdly__CorePipe__DOT__DE_PC_PLUSFOUR = vlTOPp->CorePipe__DOT__DE_PC_PLUSFOUR;
    __Vdly__CorePipe__DOT__FD_PC = vlTOPp->CorePipe__DOT__FD_PC;
    __Vdly__CorePipe__DOT__DE_M2R = vlTOPp->CorePipe__DOT__DE_M2R;
    __Vdly__CorePipe__DOT__DE_WRTSRC = vlTOPp->CorePipe__DOT__DE_WRTSRC;
    __Vdly__CorePipe__DOT__DE_MEMWRT = vlTOPp->CorePipe__DOT__DE_MEMWRT;
    __Vdly__CorePipe__DOT__DE_MEMRD = vlTOPp->CorePipe__DOT__DE_MEMRD;
    __Vdly__CorePipe__DOT__DE_REGWRT = vlTOPp->CorePipe__DOT__DE_REGWRT;
    __Vdly__CorePipe__DOT__DE_ALUOP = vlTOPp->CorePipe__DOT__DE_ALUOP;
    __Vdlyvset__CorePipe__DOT__RegFile__DOT__REG__v0 = 0U;
    __Vdlyvset__CorePipe__DOT__RegFile__DOT__REG__v31 = 0U;
    __Vdly__CorePipe__DOT__FD_IR = vlTOPp->CorePipe__DOT__FD_IR;
    __Vdly__CorePipe__DOT__DE_IR = vlTOPp->CorePipe__DOT__DE_IR;
    __Vdly__CorePipe__DOT__DE_SRC2 = vlTOPp->CorePipe__DOT__DE_SRC2;
    __Vdly__CorePipe__DOT__DE_SRC1 = vlTOPp->CorePipe__DOT__DE_SRC1;
    __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v0 = 0U;
    __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v1 = 0U;
    __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v2 = 0U;
    __Vdly__CorePipe__DOT__DE_PC_PLUSFOUR = ((IData)(vlTOPp->RESET)
                                              ? 0U : 
                                             ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                               ? vlTOPp->CorePipe__DOT__DE_PC_PLUSFOUR
                                               : ((IData)(4U) 
                                                  + vlTOPp->CorePipe__DOT__FD_PC)));
    vlTOPp->CorePipe__DOT__MW_PC_PLUSFOUR = ((IData)(vlTOPp->RESET)
                                              ? 0U : vlTOPp->CorePipe__DOT__EM_PC_PLUSFOUR);
    __Vdly__CorePipe__DOT__FD_PC = ((IData)(vlTOPp->RESET)
                                     ? 0xfffffffcU : 
                                    ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                      ? vlTOPp->CorePipe__DOT__FD_PC
                                      : vlTOPp->CorePipe__DOT__PC_sig));
    vlTOPp->CorePipe__DOT__MW_M2R = ((~ (IData)(vlTOPp->RESET)) 
                                     & (IData)(vlTOPp->CorePipe__DOT__EM_M2R));
    vlTOPp->CorePipe__DOT__MW_WRTSRC = ((~ (IData)(vlTOPp->RESET)) 
                                        & (IData)(vlTOPp->CorePipe__DOT__EM_WRTSRC));
    vlTOPp->CorePipe__DOT__DE_PC = ((IData)(vlTOPp->RESET)
                                     ? 0U : ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                              ? vlTOPp->CorePipe__DOT__DE_PC
                                              : vlTOPp->CorePipe__DOT__FD_PC));
    __Vdly__CorePipe__DOT__DE_M2R = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                           & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                               ? (IData)(vlTOPp->CorePipe__DOT__DE_M2R)
                                               : ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 2U)))));
    __Vdly__CorePipe__DOT__DE_WRTSRC = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                              & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                  ? (IData)(vlTOPp->CorePipe__DOT__DE_WRTSRC)
                                                  : 
                                                 ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 1U)))));
    __Vdly__CorePipe__DOT__DE_MEMWRT = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                              & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                  ? (IData)(vlTOPp->CorePipe__DOT__DE_MEMWRT)
                                                  : 
                                                 ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 3U)))));
    __Vdly__CorePipe__DOT__DE_MEMRD = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                             & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                 ? (IData)(vlTOPp->CorePipe__DOT__DE_MEMRD)
                                                 : 
                                                ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 4U)))));
    __Vdly__CorePipe__DOT__DE_REGWRT = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                              & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                  ? (IData)(vlTOPp->CorePipe__DOT__DE_REGWRT)
                                                  : 
                                                 ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                  & vlTOPp->CorePipe__DOT__Control__DOT__control_sig))));
    __Vdly__CorePipe__DOT__DE_ALUOP = ((IData)(vlTOPp->RESET)
                                        ? 0U : (0xfU 
                                                & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                    ? (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP)
                                                    : 
                                                   ((IData)(vlTOPp->CorePipe__DOT__FLUSH)
                                                     ? 0U
                                                     : 
                                                    (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 7U)))));
    vlTOPp->CorePipe__DOT__MW_ALUOUT = ((IData)(vlTOPp->RESET)
                                         ? 0U : vlTOPp->CorePipe__DOT__EM_ALUOUT);
    vlTOPp->CorePipe__DOT__DE_ALUSRC2 = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                               & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                   ? (IData)(vlTOPp->CorePipe__DOT__DE_ALUSRC2)
                                                   : 
                                                  ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 5U)))));
    vlTOPp->CorePipe__DOT__DE_ALUSRC1 = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                               & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                   ? (IData)(vlTOPp->CorePipe__DOT__DE_ALUSRC1)
                                                   : 
                                                  ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 6U)))));
    vlTOPp->CorePipe__DOT__DE_IMM_EXT = ((IData)(vlTOPp->RESET)
                                          ? 0U : ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                   ? vlTOPp->CorePipe__DOT__DE_IMM_EXT
                                                   : vlTOPp->CorePipe__DOT__IMM_EXT));
    vlTOPp->CorePipe__DOT__DE_JUMP = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                            & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                ? (IData)(vlTOPp->CorePipe__DOT__DE_JUMP)
                                                : (
                                                   (~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xdU)))));
    vlTOPp->CorePipe__DOT__DE_JUMPR = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                             & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                                 ? (IData)(vlTOPp->CorePipe__DOT__DE_JUMPR)
                                                 : 
                                                ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xcU)))));
    vlTOPp->CorePipe__DOT__DE_BRN = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                           & ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                               ? (IData)(vlTOPp->CorePipe__DOT__DE_BRN)
                                               : ((~ (IData)(vlTOPp->CorePipe__DOT__FLUSH)) 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 0xbU)))));
    vlTOPp->CorePipe__DOT__MW_R_DATA = ((IData)(vlTOPp->RESET)
                                         ? 0U : (((2U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->CorePipe__DOT__EM_IR 
                                                       >> 0xcU))) 
                                                  & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                  ? vlTOPp->CorePipe__DOT__DataMemory__DOT__LW
                                                  : 
                                                 ((((0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->CorePipe__DOT__EM_IR 
                                                         >> 0xcU))) 
                                                    & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD)) 
                                                   & VL_LTES_III(1,32,32, 0U, 
                                                                 VL_EXTENDS_II(32,8, (IData)(vlTOPp->CorePipe__DOT__DataMemory__DOT__LB))))
                                                   ? (IData)(vlTOPp->CorePipe__DOT__DataMemory__DOT__LB)
                                                   : 
                                                  ((((0U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CorePipe__DOT__EM_IR 
                                                          >> 0xcU))) 
                                                     & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD)) 
                                                    & VL_GTS_III(1,32,32, 0U, 
                                                                 VL_EXTENDS_II(32,8, (IData)(vlTOPp->CorePipe__DOT__DataMemory__DOT__LB))))
                                                    ? 
                                                   ((IData)(0xffffff00U) 
                                                    + (IData)(vlTOPp->CorePipe__DOT__DataMemory__DOT__LB))
                                                    : 
                                                   ((((1U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CorePipe__DOT__EM_IR 
                                                           >> 0xcU))) 
                                                      & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD)) 
                                                     & VL_LTES_III(1,32,32, 0U, 
                                                                   VL_EXTENDS_II(32,16, (IData)(vlTOPp->CorePipe__DOT__DataMemory__DOT__LH))))
                                                     ? (IData)(vlTOPp->CorePipe__DOT__DataMemory__DOT__LH)
                                                     : 
                                                    ((((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CorePipe__DOT__EM_IR 
                                                            >> 0xcU))) 
                                                       & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD)) 
                                                      & VL_GTS_III(1,32,32, 0U, 
                                                                   VL_EXTENDS_II(32,16, (IData)(vlTOPp->CorePipe__DOT__DataMemory__DOT__LH))))
                                                      ? 
                                                     ((IData)(0xffff0000U) 
                                                      + (IData)(vlTOPp->CorePipe__DOT__DataMemory__DOT__LH))
                                                      : 
                                                     (((4U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CorePipe__DOT__EM_IR 
                                                            >> 0xcU))) 
                                                       & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                       ? 
                                                      (((0U 
                                                         == 
                                                         (3U 
                                                          & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                        & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                        ? 
                                                       (0xffU 
                                                        & vlTOPp->CorePipe__DOT__DataMemory__DOT__LW)
                                                        : 
                                                       (((1U 
                                                          == 
                                                          (3U 
                                                           & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                         & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                         ? 
                                                        (0xffU 
                                                         & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                            >> 8U))
                                                         : 
                                                        (((2U 
                                                           == 
                                                           (3U 
                                                            & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                          & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                          ? 
                                                         (0xffU 
                                                          & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                             >> 0x10U))
                                                          : 
                                                         (((3U 
                                                            == 
                                                            (3U 
                                                             & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                           & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                           ? 
                                                          (0xffU 
                                                           & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                              >> 0x18U))
                                                           : 0U))))
                                                       : 
                                                      (((5U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->CorePipe__DOT__EM_IR 
                                                             >> 0xcU))) 
                                                        & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                        ? 
                                                       (((~ vlTOPp->CorePipe__DOT__EM_ALUOUT) 
                                                         & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                         ? 
                                                        (0xffffU 
                                                         & vlTOPp->CorePipe__DOT__DataMemory__DOT__LW)
                                                         : 
                                                        ((vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                                          & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                          ? 
                                                         (0xffffU 
                                                          & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                             >> 0x10U))
                                                          : 0U))
                                                        : 0U))))))));
    if (vlTOPp->RESET) {
        __Vdlyvset__CorePipe__DOT__RegFile__DOT__REG__v0 = 1U;
    } else {
        if (((IData)(vlTOPp->CorePipe__DOT__MW_REGWRT) 
             & (0U != (0x1fU & (vlTOPp->CorePipe__DOT__MW_IR 
                                >> 7U))))) {
            vlTOPp->CorePipe__DOT__RegFile__DOT____Vlvbound2 
                = vlTOPp->CorePipe__DOT__REG_IN;
            if ((0x1eU >= (0x1fU & ((vlTOPp->CorePipe__DOT__MW_IR 
                                     >> 7U) - (IData)(1U))))) {
                __Vdlyvval__CorePipe__DOT__RegFile__DOT__REG__v31 
                    = vlTOPp->CorePipe__DOT__RegFile__DOT____Vlvbound2;
                __Vdlyvset__CorePipe__DOT__RegFile__DOT__REG__v31 = 1U;
                __Vdlyvdim0__CorePipe__DOT__RegFile__DOT__REG__v31 
                    = (0x1fU & ((vlTOPp->CorePipe__DOT__MW_IR 
                                 >> 7U) - (IData)(1U)));
            }
        }
    }
    __Vdly__CorePipe__DOT__FD_IR = ((IData)(vlTOPp->RESET)
                                     ? 0U : ((IData)(vlTOPp->CorePipe__DOT__STALL)
                                              ? vlTOPp->CorePipe__DOT__FD_IR
                                              : (VL_GTS_III(1,32,32, 0U, vlTOPp->CorePipe__DOT__PC_sig)
                                                  ? 0U
                                                  : 
                                                 vlTOPp->CorePipe__DOT__InstMemory__DOT__I_MEM
                                                 [(0x1ffffffU 
                                                   & (vlTOPp->CorePipe__DOT__PC_sig 
                                                      >> 2U))])));
    if (vlTOPp->RESET) {
        __Vdly__CorePipe__DOT__DE_IR = 0U;
        __Vdly__CorePipe__DOT__DE_SRC1 = 0U;
        __Vdly__CorePipe__DOT__DE_SRC2 = 0U;
    } else {
        if (vlTOPp->CorePipe__DOT__STALL) {
            __Vdly__CorePipe__DOT__DE_IR = vlTOPp->CorePipe__DOT__DE_IR;
            __Vdly__CorePipe__DOT__DE_SRC1 = ((((0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__DE_IR 
                                                    >> 0xfU)) 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__MW_IR 
                                                    >> 7U))) 
                                               & (IData)(vlTOPp->CorePipe__DOT__MW_REGWRT))
                                               ? vlTOPp->CorePipe__DOT__REG_IN
                                               : vlTOPp->CorePipe__DOT__DE_SRC1);
            __Vdly__CorePipe__DOT__DE_SRC2 = ((((0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__DE_IR 
                                                    >> 0x14U)) 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__MW_IR 
                                                    >> 7U))) 
                                               & (IData)(vlTOPp->CorePipe__DOT__MW_REGWRT))
                                               ? vlTOPp->CorePipe__DOT__REG_IN
                                               : vlTOPp->CorePipe__DOT__DE_SRC2);
        } else {
            __Vdly__CorePipe__DOT__DE_IR = vlTOPp->CorePipe__DOT__FD_IR;
            __Vdly__CorePipe__DOT__DE_SRC1 = ((0U == 
                                               (0x1fU 
                                                & (vlTOPp->CorePipe__DOT__FD_IR 
                                                   >> 0xfU)))
                                               ? 0U
                                               : ((
                                                   (0x1fU 
                                                    & (vlTOPp->CorePipe__DOT__FD_IR 
                                                       >> 0xfU)) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlTOPp->CorePipe__DOT__MW_IR 
                                                       >> 7U)))
                                                   ? vlTOPp->CorePipe__DOT__REG_IN
                                                   : 
                                                  ((0x1eU 
                                                    >= 
                                                    (0x1fU 
                                                     & ((vlTOPp->CorePipe__DOT__FD_IR 
                                                         >> 0xfU) 
                                                        - (IData)(1U))))
                                                    ? 
                                                   vlTOPp->CorePipe__DOT__RegFile__DOT__REG
                                                   [
                                                   (0x1fU 
                                                    & ((vlTOPp->CorePipe__DOT__FD_IR 
                                                        >> 0xfU) 
                                                       - (IData)(1U)))]
                                                    : 0U)));
            __Vdly__CorePipe__DOT__DE_SRC2 = ((0U == 
                                               (0x1fU 
                                                & (vlTOPp->CorePipe__DOT__FD_IR 
                                                   >> 0x14U)))
                                               ? 0U
                                               : ((
                                                   (0x1fU 
                                                    & (vlTOPp->CorePipe__DOT__FD_IR 
                                                       >> 0x14U)) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlTOPp->CorePipe__DOT__MW_IR 
                                                       >> 7U)))
                                                   ? vlTOPp->CorePipe__DOT__REG_IN
                                                   : 
                                                  ((0x1eU 
                                                    >= 
                                                    (0x1fU 
                                                     & ((vlTOPp->CorePipe__DOT__FD_IR 
                                                         >> 0x14U) 
                                                        - (IData)(1U))))
                                                    ? 
                                                   vlTOPp->CorePipe__DOT__RegFile__DOT__REG
                                                   [
                                                   (0x1fU 
                                                    & ((vlTOPp->CorePipe__DOT__FD_IR 
                                                        >> 0x14U) 
                                                       - (IData)(1U)))]
                                                    : 0U)));
        }
    }
    if (((~ (IData)(vlTOPp->RESET)) & (IData)(vlTOPp->CorePipe__DOT__EM_MEMWRT))) {
        if ((2U == (7U & (vlTOPp->CorePipe__DOT__EM_IR 
                          >> 0xcU)))) {
            __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v0 
                = vlTOPp->CorePipe__DOT__EM_SRC2;
            __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v0 = 1U;
            __Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v0 
                = (0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                 >> 2U));
        } else {
            if ((0U == (7U & (vlTOPp->CorePipe__DOT__EM_IR 
                              >> 0xcU)))) {
                __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v1 
                    = (((0x1fU >= (0x18U & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                            << 3U)))
                         ? ((0xffU & vlTOPp->CorePipe__DOT__EM_SRC2) 
                            << (0x18U & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                         << 3U))) : 0U) 
                       | vlTOPp->CorePipe__DOT__DataMemory__DOT__BYTE_WR);
                __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v1 = 1U;
                __Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v1 
                    = (0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                     >> 2U));
            } else {
                if ((1U == (7U & (vlTOPp->CorePipe__DOT__EM_IR 
                                  >> 0xcU)))) {
                    __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v2 
                        = (((0x1fU >= (0x10U & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                                << 4U)))
                             ? ((0xffffU & vlTOPp->CorePipe__DOT__EM_SRC2) 
                                << (0x10U & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                             << 4U)))
                             : 0U) | vlTOPp->CorePipe__DOT__DataMemory__DOT__HALF_WR);
                    __Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v2 = 1U;
                    __Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v2 
                        = (0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                         >> 2U));
                }
            }
        }
    }
    vlTOPp->CorePipe__DOT__FD_PC = __Vdly__CorePipe__DOT__FD_PC;
    if (__Vdlyvset__CorePipe__DOT__RegFile__DOT__REG__v0) {
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[1U] = 0x1000000U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[2U] = 0x2000000U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[3U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[4U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[5U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[6U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[7U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[8U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[9U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0xaU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0xbU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0xcU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0xdU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0xeU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0xfU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x10U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x11U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x12U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x13U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x14U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x15U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x16U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x17U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x18U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x19U] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x1aU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x1bU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x1cU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x1dU] = 0U;
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[0x1eU] = 0U;
    }
    if (__Vdlyvset__CorePipe__DOT__RegFile__DOT__REG__v31) {
        vlTOPp->CorePipe__DOT__RegFile__DOT__REG[__Vdlyvdim0__CorePipe__DOT__RegFile__DOT__REG__v31] 
            = __Vdlyvval__CorePipe__DOT__RegFile__DOT__REG__v31;
    }
    vlTOPp->CorePipe__DOT__DE_SRC1 = __Vdly__CorePipe__DOT__DE_SRC1;
    vlTOPp->CorePipe__DOT__FD_IR = __Vdly__CorePipe__DOT__FD_IR;
    if (__Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v0) {
        vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v0] 
            = __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v0;
    }
    if (__Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v1) {
        vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v1] 
            = __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v1;
    }
    if (__Vdlyvset__CorePipe__DOT__DataMemory__DOT__D_MEM__v2) {
        vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__CorePipe__DOT__DataMemory__DOT__D_MEM__v2] 
            = __Vdlyvval__CorePipe__DOT__DataMemory__DOT__D_MEM__v2;
    }
    vlTOPp->CorePipe__DOT__EM_PC_PLUSFOUR = ((IData)(vlTOPp->RESET)
                                              ? 0U : vlTOPp->CorePipe__DOT__DE_PC_PLUSFOUR);
    vlTOPp->CorePipe__DOT__EM_M2R = ((~ (IData)(vlTOPp->RESET)) 
                                     & ((~ (IData)(vlTOPp->CorePipe__DOT__STALL)) 
                                        & (IData)(vlTOPp->CorePipe__DOT__DE_M2R)));
    vlTOPp->CorePipe__DOT__EM_WRTSRC = ((~ (IData)(vlTOPp->RESET)) 
                                        & ((~ (IData)(vlTOPp->CorePipe__DOT__STALL)) 
                                           & (IData)(vlTOPp->CorePipe__DOT__DE_WRTSRC)));
    vlTOPp->CorePipe__DOT__JUMP_BRANCH_TARGET = (vlTOPp->CorePipe__DOT__DE_PC 
                                                 + vlTOPp->CorePipe__DOT__DE_IMM_EXT);
    vlTOPp->CorePipe__DOT__REG_IN = ((IData)(vlTOPp->CorePipe__DOT__MW_WRTSRC)
                                      ? ((IData)(vlTOPp->CorePipe__DOT__MW_M2R)
                                          ? vlTOPp->CorePipe__DOT__MW_R_DATA
                                          : vlTOPp->CorePipe__DOT__MW_ALUOUT)
                                      : vlTOPp->CorePipe__DOT__MW_PC_PLUSFOUR);
    vlTOPp->CorePipe__DOT__EM_MEMRD = ((~ (IData)(vlTOPp->RESET)) 
                                       & ((~ (IData)(vlTOPp->CorePipe__DOT__STALL)) 
                                          & (IData)(vlTOPp->CorePipe__DOT__DE_MEMRD)));
    vlTOPp->CorePipe__DOT__MW_REGWRT = ((~ (IData)(vlTOPp->RESET)) 
                                        & (IData)(vlTOPp->CorePipe__DOT__EM_REGWRT));
    vlTOPp->CorePipe__DOT__MW_IR = ((IData)(vlTOPp->RESET)
                                     ? 0U : vlTOPp->CorePipe__DOT__EM_IR);
    vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR = 
        ((0x400U & (vlTOPp->CorePipe__DOT__FD_IR >> 0x14U)) 
         | ((0x380U & (vlTOPp->CorePipe__DOT__FD_IR 
                       >> 5U)) | (0x7fU & vlTOPp->CorePipe__DOT__FD_IR)));
    vlTOPp->CorePipe__DOT__EM_MEMWRT = ((~ (IData)(vlTOPp->RESET)) 
                                        & ((~ (IData)(vlTOPp->CorePipe__DOT__STALL)) 
                                           & (IData)(vlTOPp->CorePipe__DOT__DE_MEMWRT)));
    vlTOPp->CorePipe__DOT__EM_ALUOUT = ((IData)(vlTOPp->RESET)
                                         ? 0U : ((0U 
                                                  == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                  ? 
                                                 (vlTOPp->CorePipe__DOT__ALU_IN1 
                                                  + vlTOPp->CorePipe__DOT__ALU_IN2)
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                   ? 
                                                  (vlTOPp->CorePipe__DOT__ALU_IN1 
                                                   - vlTOPp->CorePipe__DOT__ALU_IN2)
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                    ? 
                                                   (vlTOPp->CorePipe__DOT__ALU_IN1 
                                                    & vlTOPp->CorePipe__DOT__ALU_IN2)
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                     ? 
                                                    (vlTOPp->CorePipe__DOT__ALU_IN1 
                                                     | vlTOPp->CorePipe__DOT__ALU_IN2)
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                      ? 
                                                     (vlTOPp->CorePipe__DOT__ALU_IN1 
                                                      ^ vlTOPp->CorePipe__DOT__ALU_IN2)
                                                      : 
                                                     (((5U 
                                                        == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP)) 
                                                       & VL_LTS_III(1,32,32, vlTOPp->CorePipe__DOT__ALU_IN1, vlTOPp->CorePipe__DOT__ALU_IN2))
                                                       ? 1U
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                        ? 
                                                       (vlTOPp->CorePipe__DOT__ALU_IN1 
                                                        << 
                                                        (0x1fU 
                                                         & vlTOPp->CorePipe__DOT__ALU_IN2))
                                                        : 
                                                       (((7U 
                                                          == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP)) 
                                                         & (vlTOPp->CorePipe__DOT__ALU_IN1 
                                                            < vlTOPp->CorePipe__DOT__ALU_IN2))
                                                         ? 1U
                                                         : 
                                                        ((8U 
                                                          == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                          ? 
                                                         (vlTOPp->CorePipe__DOT__ALU_IN1 
                                                          >> 
                                                          (0x1fU 
                                                           & vlTOPp->CorePipe__DOT__ALU_IN2))
                                                          : 
                                                         ((9U 
                                                           == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                           ? 
                                                          VL_SHIFTRS_III(32,32,5, vlTOPp->CorePipe__DOT__ALU_IN1, 
                                                                         (0x1fU 
                                                                          & vlTOPp->CorePipe__DOT__ALU_IN2))
                                                           : 
                                                          ((0xaU 
                                                            == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                            ? vlTOPp->CorePipe__DOT__ALU_IN1
                                                            : 
                                                           ((0xbU 
                                                             == (IData)(vlTOPp->CorePipe__DOT__DE_ALUOP))
                                                             ? vlTOPp->CorePipe__DOT__ALU_IN2
                                                             : 0U)))))))))))));
    vlTOPp->CorePipe__DOT__EM_SRC2 = ((IData)(vlTOPp->RESET)
                                       ? 0U : vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__DE_PC_PLUSFOUR = __Vdly__CorePipe__DOT__DE_PC_PLUSFOUR;
    vlTOPp->CorePipe__DOT__DE_M2R = __Vdly__CorePipe__DOT__DE_M2R;
    vlTOPp->CorePipe__DOT__DE_WRTSRC = __Vdly__CorePipe__DOT__DE_WRTSRC;
    vlTOPp->CorePipe__DOT__DE_MEMRD = __Vdly__CorePipe__DOT__DE_MEMRD;
    vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
        = ((0x37U == (0x7fU & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
            ? 0x5a3U : ((0x17U == (0x7fU & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                         ? 0x63U : ((0x6fU == (0x7fU 
                                               & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                     ? 0x12001U : (
                                                   (0x67U 
                                                    == 
                                                    (0x3ffU 
                                                     & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                    ? 0xd001U
                                                    : 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                     ? 0x8800U
                                                     : 
                                                    ((0x103U 
                                                      == 
                                                      (0x3ffU 
                                                       & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                      ? 0xc037U
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (0x3ffU 
                                                        & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                       ? 0xc037U
                                                       : 
                                                      ((0x83U 
                                                        == 
                                                        (0x3ffU 
                                                         & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                        ? 0xc037U
                                                        : 
                                                       ((0x203U 
                                                         == 
                                                         (0x3ffU 
                                                          & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                         ? 0xc037U
                                                         : 
                                                        ((0x283U 
                                                          == 
                                                          (0x3ffU 
                                                           & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                          ? 0xc037U
                                                          : 
                                                         ((0x123U 
                                                           == 
                                                           (0x3ffU 
                                                            & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                           ? 0x4028U
                                                           : 
                                                          ((0x23U 
                                                            == 
                                                            (0x3ffU 
                                                             & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                            ? 0x4028U
                                                            : 
                                                           ((0xa3U 
                                                             == 
                                                             (0x3ffU 
                                                              & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                             ? 0x4028U
                                                             : 
                                                            ((0x13U 
                                                              == 
                                                              (0x3ffU 
                                                               & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                              ? 0xc023U
                                                              : 
                                                             ((0x113U 
                                                               == 
                                                               (0x3ffU 
                                                                & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                               ? 0xc2a3U
                                                               : 
                                                              ((0x193U 
                                                                == 
                                                                (0x3ffU 
                                                                 & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                                ? 0xc3a3U
                                                                : 
                                                               ((0x213U 
                                                                 == 
                                                                 (0x3ffU 
                                                                  & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                                 ? 0xc223U
                                                                 : 
                                                                ((0x313U 
                                                                  == 
                                                                  (0x3ffU 
                                                                   & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                                  ? 0xc1a3U
                                                                  : 
                                                                 ((0x393U 
                                                                   == 
                                                                   (0x3ffU 
                                                                    & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                                   ? 0xc123U
                                                                   : 
                                                                  ((0x93U 
                                                                    == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                    ? 0xc323U
                                                                    : 
                                                                   ((0x293U 
                                                                     == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                     ? 0xc423U
                                                                     : 
                                                                    ((0x693U 
                                                                      == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                      ? 0xc4a3U
                                                                      : 
                                                                     ((0x33U 
                                                                       == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                       ? 0x14003U
                                                                       : 
                                                                      ((0x433U 
                                                                        == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                        ? 0x14083U
                                                                        : 
                                                                       ((0xb3U 
                                                                         == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                         ? 0x14303U
                                                                         : 
                                                                        ((0x133U 
                                                                          == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                          ? 0x14283U
                                                                          : 
                                                                         ((0x1b3U 
                                                                           == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                           ? 0x14383U
                                                                           : 
                                                                          ((0x233U 
                                                                            == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                            ? 0x14203U
                                                                            : 
                                                                           ((0x2b3U 
                                                                             == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                             ? 0x14403U
                                                                             : 
                                                                            ((0x6b3U 
                                                                              == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                              ? 0x14483U
                                                                              : 
                                                                             ((0x333U 
                                                                               == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                               ? 0x14183U
                                                                               : 
                                                                              ((0x3b3U 
                                                                                == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                                ? 0x14103U
                                                                                : 0U))))))))))))))))))))))))))))))));
    vlTOPp->CorePipe__DOT__DE_MEMWRT = __Vdly__CorePipe__DOT__DE_MEMWRT;
    vlTOPp->CorePipe__DOT__DE_ALUOP = __Vdly__CorePipe__DOT__DE_ALUOP;
    vlTOPp->CorePipe__DOT__ALU_IN1 = ((IData)(vlTOPp->CorePipe__DOT__DE_ALUSRC1)
                                       ? vlTOPp->CorePipe__DOT__DE_PC
                                       : vlTOPp->CorePipe__DOT__DE_SRC1);
    vlTOPp->CorePipe__DOT__DE_SRC2 = __Vdly__CorePipe__DOT__DE_SRC2;
    vlTOPp->CorePipe__DOT__EM_REGWRT = ((~ (IData)(vlTOPp->RESET)) 
                                        & ((~ (IData)(vlTOPp->CorePipe__DOT__STALL)) 
                                           & (IData)(vlTOPp->CorePipe__DOT__DE_REGWRT)));
    vlTOPp->CorePipe__DOT__EM_IR = ((IData)(vlTOPp->RESET)
                                     ? 0U : vlTOPp->CorePipe__DOT__DE_IR);
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xfffffffeU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (1U & ((3U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xeU)))
                                                ? (vlTOPp->CorePipe__DOT__FD_IR 
                                                   >> 0x14U)
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                        >> 0xeU))) 
                                                   & (vlTOPp->CorePipe__DOT__FD_IR 
                                                      >> 7U)))));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xffffffe1U 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0x1eU & ((
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                         >> 0xeU))) 
                                                    | (4U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                           >> 0xeU))))
                                                    ? 
                                                   (vlTOPp->CorePipe__DOT__FD_IR 
                                                    >> 0x15U)
                                                    : 
                                                   (((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                          >> 0xeU))) 
                                                     | (2U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                            >> 0xeU))))
                                                     ? 
                                                    (vlTOPp->CorePipe__DOT__FD_IR 
                                                     >> 8U)
                                                     : 0U)) 
                                                  << 1U)));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xfffff81fU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | ((((((3U == 
                                              (7U & 
                                               (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                >> 0xeU))) 
                                             | (1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xeU)))) 
                                            | (2U == 
                                               (7U 
                                                & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                   >> 0xeU)))) 
                                           | (4U == 
                                              (7U & 
                                               (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                >> 0xeU))))
                                           ? (0x3fU 
                                              & (vlTOPp->CorePipe__DOT__FD_IR 
                                                 >> 0x19U))
                                           : 0U) << 5U));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xfffff7ffU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0x800U & (
                                                   (((3U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                          >> 0xeU))) 
                                                     | (1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                            >> 0xeU))))
                                                     ? 
                                                    (vlTOPp->CorePipe__DOT__FD_IR 
                                                     >> 0x1fU)
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                          >> 0xeU)))
                                                      ? 
                                                     (vlTOPp->CorePipe__DOT__FD_IR 
                                                      >> 7U)
                                                      : 
                                                     ((0U 
                                                       != 
                                                       (7U 
                                                        & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                           >> 0xeU))) 
                                                      & ((4U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                              >> 0xeU))) 
                                                         & (vlTOPp->CorePipe__DOT__FD_IR 
                                                            >> 0x14U))))) 
                                                   << 0xbU)));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xfff00fffU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0xff000U & 
                                         (((((3U == 
                                              (7U & 
                                               (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                >> 0xeU))) 
                                             | (1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xeU)))) 
                                            | (2U == 
                                               (7U 
                                                & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                   >> 0xeU))))
                                            ? VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->CorePipe__DOT__FD_IR 
                                                                      >> 0x1fU))))
                                            : ((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xeU)))
                                                ? (vlTOPp->CorePipe__DOT__FD_IR 
                                                   >> 0xcU)
                                                : (
                                                   (4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                        >> 0xeU)))
                                                    ? 
                                                   (vlTOPp->CorePipe__DOT__FD_IR 
                                                    >> 0xcU)
                                                    : 0U))) 
                                          << 0xcU)));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0x800fffffU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0x7ff00000U 
                                         & ((((((3U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))) 
                                                | (1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                       >> 0xeU)))) 
                                               | (2U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                              | (4U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))))
                                              ? VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->CorePipe__DOT__FD_IR 
                                                                        >> 0x1fU))))
                                              : ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))
                                                  ? 
                                                 (vlTOPp->CorePipe__DOT__FD_IR 
                                                  >> 0x14U)
                                                  : 0U)) 
                                            << 0x14U)));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0x7fffffffU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0x80000000U 
                                         & (((((((3U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xeU))) 
                                                 | (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                        >> 0xeU)))) 
                                                | (2U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                       >> 0xeU)))) 
                                               | (0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                              | (4U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 0xeU)))) 
                                             << 0x1fU) 
                                            & vlTOPp->CorePipe__DOT__FD_IR)));
    vlTOPp->CorePipe__DOT__DataMemory__DOT__BYTE_WR 
        = ((~ ((0x1fU >= (((IData)(3U) - (3U & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                          << 3U)) ? (0xff000000U >> 
                                     (((IData)(3U) 
                                       - (3U & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                      << 3U)) : 0U)) 
           & vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM
           [(0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                           >> 2U))]);
    vlTOPp->CorePipe__DOT__DataMemory__DOT__HALF_WR 
        = ((~ ((0x1fU >= (((IData)(1U) - (1U & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                          << 4U)) ? (0xffff0000U >> 
                                     (((IData)(1U) 
                                       - (1U & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                      << 4U)) : 0U)) 
           & vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM
           [(0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                           >> 2U))]);
    vlTOPp->PRINT_EN = ((0x3800040cU == (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                         >> 2U)) & (IData)(vlTOPp->CorePipe__DOT__EM_MEMWRT));
    vlTOPp->CorePipe__DOT__DataMemory__DOT__LW = vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM
        [(0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                        >> 2U))];
    vlTOPp->PRINT_VAL = vlTOPp->CorePipe__DOT__EM_SRC2;
    vlTOPp->CorePipe__DOT__ALU_IN2 = ((IData)(vlTOPp->CorePipe__DOT__DE_ALUSRC2)
                                       ? vlTOPp->CorePipe__DOT__DE_IMM_EXT
                                       : vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_equal 
        = (vlTOPp->CorePipe__DOT__DE_SRC1 == vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_signed 
        = VL_LTS_III(1,32,32, vlTOPp->CorePipe__DOT__DE_SRC1, vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_unsigned 
        = (vlTOPp->CorePipe__DOT__DE_SRC1 < vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__DE_REGWRT = __Vdly__CorePipe__DOT__DE_REGWRT;
    vlTOPp->CorePipe__DOT__DE_IR = __Vdly__CorePipe__DOT__DE_IR;
    vlTOPp->CorePipe__DOT__DataMemory__DOT__LH = (0xffffU 
                                                  & (((~ vlTOPp->CorePipe__DOT__EM_ALUOUT) 
                                                      & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                      ? 
                                                     (0xffffU 
                                                      & vlTOPp->CorePipe__DOT__DataMemory__DOT__LW)
                                                      : 
                                                     ((vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                                       & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                       ? 
                                                      (0xffffU 
                                                       & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                          >> 0x10U))
                                                       : 0U)));
    vlTOPp->CorePipe__DOT__DataMemory__DOT__LB = (0xffU 
                                                  & (((0U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                      & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                      ? 
                                                     (0xffU 
                                                      & vlTOPp->CorePipe__DOT__DataMemory__DOT__LW)
                                                      : 
                                                     (((1U 
                                                        == 
                                                        (3U 
                                                         & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                       & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                          >> 8U))
                                                       : 
                                                      (((2U 
                                                         == 
                                                         (3U 
                                                          & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                        & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                        ? 
                                                       (0xffU 
                                                        & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                           >> 0x10U))
                                                        : 
                                                       (((3U 
                                                          == 
                                                          (3U 
                                                           & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                         & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                         ? 
                                                        (0xffU 
                                                         & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                            >> 0x18U))
                                                         : 0U)))));
    vlTOPp->CorePipe__DOT__STALL = ((((5U == (7U & 
                                              (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                               >> 0xeU))) 
                                      | (1U == (7U 
                                                & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                   >> 0xeU)))) 
                                     | (2U == (7U & 
                                               (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                >> 0xeU))))
                                     ? (((((0x1fU & 
                                            (vlTOPp->CorePipe__DOT__DE_IR 
                                             >> 0xfU)) 
                                           == (0x1fU 
                                               & (vlTOPp->CorePipe__DOT__EM_IR 
                                                  >> 7U))) 
                                          | ((0x1fU 
                                              & (vlTOPp->CorePipe__DOT__DE_IR 
                                                 >> 0x14U)) 
                                             == (0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__EM_IR 
                                                    >> 7U)))) 
                                         & (0U != (0x1fU 
                                                   & (vlTOPp->CorePipe__DOT__EM_IR 
                                                      >> 7U)))) 
                                        | ((((0x1fU 
                                              & (vlTOPp->CorePipe__DOT__DE_IR 
                                                 >> 0xfU)) 
                                             == (0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__MW_IR 
                                                    >> 7U))) 
                                            | ((0x1fU 
                                                & (vlTOPp->CorePipe__DOT__DE_IR 
                                                   >> 0x14U)) 
                                               == (0x1fU 
                                                   & (vlTOPp->CorePipe__DOT__MW_IR 
                                                      >> 7U)))) 
                                           & (0U != 
                                              (0x1fU 
                                               & (vlTOPp->CorePipe__DOT__MW_IR 
                                                  >> 7U)))))
                                     : ((3U == (7U 
                                                & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                   >> 0xeU))) 
                                        & ((((0x1fU 
                                              & (vlTOPp->CorePipe__DOT__DE_IR 
                                                 >> 0xfU)) 
                                             == (0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__EM_IR 
                                                    >> 7U))) 
                                            & (0U != 
                                               (0x1fU 
                                                & (vlTOPp->CorePipe__DOT__EM_IR 
                                                   >> 7U)))) 
                                           | (((0x1fU 
                                                & (vlTOPp->CorePipe__DOT__DE_IR 
                                                   >> 0xfU)) 
                                               == (0x1fU 
                                                   & (vlTOPp->CorePipe__DOT__MW_IR 
                                                      >> 7U))) 
                                              & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlTOPp->CorePipe__DOT__MW_IR 
                                                     >> 7U)))))));
    vlTOPp->CorePipe__DOT__BRNEN = ((IData)(vlTOPp->CorePipe__DOT__DE_BRN) 
                                    & (((((((0U == 
                                             (7U & 
                                              (vlTOPp->CorePipe__DOT__DE_IR 
                                               >> 0xcU))) 
                                            & (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_equal)) 
                                           | ((1U == 
                                               (7U 
                                                & (vlTOPp->CorePipe__DOT__DE_IR 
                                                   >> 0xcU))) 
                                              & (~ (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_equal)))) 
                                          | ((4U == 
                                              (7U & 
                                               (vlTOPp->CorePipe__DOT__DE_IR 
                                                >> 0xcU))) 
                                             & (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_signed))) 
                                         | ((5U == 
                                             (7U & 
                                              (vlTOPp->CorePipe__DOT__DE_IR 
                                               >> 0xcU))) 
                                            & (~ (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_signed)))) 
                                        | ((6U == (7U 
                                                   & (vlTOPp->CorePipe__DOT__DE_IR 
                                                      >> 0xcU))) 
                                           & (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_unsigned))) 
                                       | ((7U == (7U 
                                                  & (vlTOPp->CorePipe__DOT__DE_IR 
                                                     >> 0xcU))) 
                                          & (~ (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_unsigned)))));
    vlTOPp->CorePipe__DOT__FLUSH = (((IData)(vlTOPp->CorePipe__DOT__DE_JUMP) 
                                     | (IData)(vlTOPp->CorePipe__DOT__DE_JUMPR)) 
                                    | (IData)(vlTOPp->CorePipe__DOT__BRNEN));
    vlTOPp->CorePipe__DOT__PC_sig = ((IData)(vlTOPp->CorePipe__DOT__DE_JUMP)
                                      ? vlTOPp->CorePipe__DOT__JUMP_BRANCH_TARGET
                                      : ((IData)(vlTOPp->CorePipe__DOT__DE_JUMPR)
                                          ? (vlTOPp->CorePipe__DOT__DE_SRC1 
                                             + vlTOPp->CorePipe__DOT__DE_IMM_EXT)
                                          : ((IData)(vlTOPp->CorePipe__DOT__BRNEN)
                                              ? vlTOPp->CorePipe__DOT__JUMP_BRANCH_TARGET
                                              : ((IData)(4U) 
                                                 + vlTOPp->CorePipe__DOT__FD_PC))));
}

void VCorePipe::_settle__TOP__3(VCorePipe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_settle__TOP__3\n"); );
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->CorePipe__DOT__REG_IN = ((IData)(vlTOPp->CorePipe__DOT__MW_WRTSRC)
                                      ? ((IData)(vlTOPp->CorePipe__DOT__MW_M2R)
                                          ? vlTOPp->CorePipe__DOT__MW_R_DATA
                                          : vlTOPp->CorePipe__DOT__MW_ALUOUT)
                                      : vlTOPp->CorePipe__DOT__MW_PC_PLUSFOUR);
    vlTOPp->PRINT_VAL = vlTOPp->CorePipe__DOT__EM_SRC2;
    vlTOPp->CorePipe__DOT__JUMP_BRANCH_TARGET = (vlTOPp->CorePipe__DOT__DE_PC 
                                                 + vlTOPp->CorePipe__DOT__DE_IMM_EXT);
    vlTOPp->CorePipe__DOT__DataMemory__DOT__BYTE_WR 
        = ((~ ((0x1fU >= (((IData)(3U) - (3U & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                          << 3U)) ? (0xff000000U >> 
                                     (((IData)(3U) 
                                       - (3U & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                      << 3U)) : 0U)) 
           & vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM
           [(0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                           >> 2U))]);
    vlTOPp->CorePipe__DOT__DataMemory__DOT__HALF_WR 
        = ((~ ((0x1fU >= (((IData)(1U) - (1U & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                          << 4U)) ? (0xffff0000U >> 
                                     (((IData)(1U) 
                                       - (1U & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                      << 4U)) : 0U)) 
           & vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM
           [(0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                           >> 2U))]);
    vlTOPp->PRINT_EN = ((0x3800040cU == (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                         >> 2U)) & (IData)(vlTOPp->CorePipe__DOT__EM_MEMWRT));
    vlTOPp->CorePipe__DOT__DataMemory__DOT__LW = vlTOPp->CorePipe__DOT__DataMemory__DOT__D_MEM
        [(0x1ffffffU & (vlTOPp->CorePipe__DOT__EM_ALUOUT 
                        >> 2U))];
    vlTOPp->CorePipe__DOT__ALU_IN1 = ((IData)(vlTOPp->CorePipe__DOT__DE_ALUSRC1)
                                       ? vlTOPp->CorePipe__DOT__DE_PC
                                       : vlTOPp->CorePipe__DOT__DE_SRC1);
    vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR = 
        ((0x400U & (vlTOPp->CorePipe__DOT__FD_IR >> 0x14U)) 
         | ((0x380U & (vlTOPp->CorePipe__DOT__FD_IR 
                       >> 5U)) | (0x7fU & vlTOPp->CorePipe__DOT__FD_IR)));
    vlTOPp->CorePipe__DOT__ALU_IN2 = ((IData)(vlTOPp->CorePipe__DOT__DE_ALUSRC2)
                                       ? vlTOPp->CorePipe__DOT__DE_IMM_EXT
                                       : vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_equal 
        = (vlTOPp->CorePipe__DOT__DE_SRC1 == vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_signed 
        = VL_LTS_III(1,32,32, vlTOPp->CorePipe__DOT__DE_SRC1, vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_unsigned 
        = (vlTOPp->CorePipe__DOT__DE_SRC1 < vlTOPp->CorePipe__DOT__DE_SRC2);
    vlTOPp->CorePipe__DOT__DataMemory__DOT__LH = (0xffffU 
                                                  & (((~ vlTOPp->CorePipe__DOT__EM_ALUOUT) 
                                                      & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                      ? 
                                                     (0xffffU 
                                                      & vlTOPp->CorePipe__DOT__DataMemory__DOT__LW)
                                                      : 
                                                     ((vlTOPp->CorePipe__DOT__EM_ALUOUT 
                                                       & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                       ? 
                                                      (0xffffU 
                                                       & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                          >> 0x10U))
                                                       : 0U)));
    vlTOPp->CorePipe__DOT__DataMemory__DOT__LB = (0xffU 
                                                  & (((0U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                      & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                      ? 
                                                     (0xffU 
                                                      & vlTOPp->CorePipe__DOT__DataMemory__DOT__LW)
                                                      : 
                                                     (((1U 
                                                        == 
                                                        (3U 
                                                         & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                       & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                          >> 8U))
                                                       : 
                                                      (((2U 
                                                         == 
                                                         (3U 
                                                          & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                        & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                        ? 
                                                       (0xffU 
                                                        & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                           >> 0x10U))
                                                        : 
                                                       (((3U 
                                                          == 
                                                          (3U 
                                                           & vlTOPp->CorePipe__DOT__EM_ALUOUT)) 
                                                         & (IData)(vlTOPp->CorePipe__DOT__EM_MEMRD))
                                                         ? 
                                                        (0xffU 
                                                         & (vlTOPp->CorePipe__DOT__DataMemory__DOT__LW 
                                                            >> 0x18U))
                                                         : 0U)))));
    vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
        = ((0x37U == (0x7fU & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
            ? 0x5a3U : ((0x17U == (0x7fU & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                         ? 0x63U : ((0x6fU == (0x7fU 
                                               & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                     ? 0x12001U : (
                                                   (0x67U 
                                                    == 
                                                    (0x3ffU 
                                                     & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                    ? 0xd001U
                                                    : 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                     ? 0x8800U
                                                     : 
                                                    ((0x103U 
                                                      == 
                                                      (0x3ffU 
                                                       & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                      ? 0xc037U
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (0x3ffU 
                                                        & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                       ? 0xc037U
                                                       : 
                                                      ((0x83U 
                                                        == 
                                                        (0x3ffU 
                                                         & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                        ? 0xc037U
                                                        : 
                                                       ((0x203U 
                                                         == 
                                                         (0x3ffU 
                                                          & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                         ? 0xc037U
                                                         : 
                                                        ((0x283U 
                                                          == 
                                                          (0x3ffU 
                                                           & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                          ? 0xc037U
                                                          : 
                                                         ((0x123U 
                                                           == 
                                                           (0x3ffU 
                                                            & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                           ? 0x4028U
                                                           : 
                                                          ((0x23U 
                                                            == 
                                                            (0x3ffU 
                                                             & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                            ? 0x4028U
                                                            : 
                                                           ((0xa3U 
                                                             == 
                                                             (0x3ffU 
                                                              & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                             ? 0x4028U
                                                             : 
                                                            ((0x13U 
                                                              == 
                                                              (0x3ffU 
                                                               & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                              ? 0xc023U
                                                              : 
                                                             ((0x113U 
                                                               == 
                                                               (0x3ffU 
                                                                & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                               ? 0xc2a3U
                                                               : 
                                                              ((0x193U 
                                                                == 
                                                                (0x3ffU 
                                                                 & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                                ? 0xc3a3U
                                                                : 
                                                               ((0x213U 
                                                                 == 
                                                                 (0x3ffU 
                                                                  & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                                 ? 0xc223U
                                                                 : 
                                                                ((0x313U 
                                                                  == 
                                                                  (0x3ffU 
                                                                   & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                                  ? 0xc1a3U
                                                                  : 
                                                                 ((0x393U 
                                                                   == 
                                                                   (0x3ffU 
                                                                    & (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR)))
                                                                   ? 0xc123U
                                                                   : 
                                                                  ((0x93U 
                                                                    == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                    ? 0xc323U
                                                                    : 
                                                                   ((0x293U 
                                                                     == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                     ? 0xc423U
                                                                     : 
                                                                    ((0x693U 
                                                                      == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                      ? 0xc4a3U
                                                                      : 
                                                                     ((0x33U 
                                                                       == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                       ? 0x14003U
                                                                       : 
                                                                      ((0x433U 
                                                                        == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                        ? 0x14083U
                                                                        : 
                                                                       ((0xb3U 
                                                                         == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                         ? 0x14303U
                                                                         : 
                                                                        ((0x133U 
                                                                          == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                          ? 0x14283U
                                                                          : 
                                                                         ((0x1b3U 
                                                                           == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                           ? 0x14383U
                                                                           : 
                                                                          ((0x233U 
                                                                            == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                            ? 0x14203U
                                                                            : 
                                                                           ((0x2b3U 
                                                                             == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                             ? 0x14403U
                                                                             : 
                                                                            ((0x6b3U 
                                                                              == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                              ? 0x14483U
                                                                              : 
                                                                             ((0x333U 
                                                                               == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                               ? 0x14183U
                                                                               : 
                                                                              ((0x3b3U 
                                                                                == (IData)(vlTOPp->CorePipe__DOT__Control__DOT__INS_ARR))
                                                                                ? 0x14103U
                                                                                : 0U))))))))))))))))))))))))))))))));
    vlTOPp->CorePipe__DOT__BRNEN = ((IData)(vlTOPp->CorePipe__DOT__DE_BRN) 
                                    & (((((((0U == 
                                             (7U & 
                                              (vlTOPp->CorePipe__DOT__DE_IR 
                                               >> 0xcU))) 
                                            & (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_equal)) 
                                           | ((1U == 
                                               (7U 
                                                & (vlTOPp->CorePipe__DOT__DE_IR 
                                                   >> 0xcU))) 
                                              & (~ (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_equal)))) 
                                          | ((4U == 
                                              (7U & 
                                               (vlTOPp->CorePipe__DOT__DE_IR 
                                                >> 0xcU))) 
                                             & (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_signed))) 
                                         | ((5U == 
                                             (7U & 
                                              (vlTOPp->CorePipe__DOT__DE_IR 
                                               >> 0xcU))) 
                                            & (~ (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_signed)))) 
                                        | ((6U == (7U 
                                                   & (vlTOPp->CorePipe__DOT__DE_IR 
                                                      >> 0xcU))) 
                                           & (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_unsigned))) 
                                       | ((7U == (7U 
                                                  & (vlTOPp->CorePipe__DOT__DE_IR 
                                                     >> 0xcU))) 
                                          & (~ (IData)(vlTOPp->CorePipe__DOT__BranchLogic__DOT__w_unsigned)))));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xfffffffeU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (1U & ((3U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xeU)))
                                                ? (vlTOPp->CorePipe__DOT__FD_IR 
                                                   >> 0x14U)
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                        >> 0xeU))) 
                                                   & (vlTOPp->CorePipe__DOT__FD_IR 
                                                      >> 7U)))));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xffffffe1U 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0x1eU & ((
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                         >> 0xeU))) 
                                                    | (4U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                           >> 0xeU))))
                                                    ? 
                                                   (vlTOPp->CorePipe__DOT__FD_IR 
                                                    >> 0x15U)
                                                    : 
                                                   (((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                          >> 0xeU))) 
                                                     | (2U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                            >> 0xeU))))
                                                     ? 
                                                    (vlTOPp->CorePipe__DOT__FD_IR 
                                                     >> 8U)
                                                     : 0U)) 
                                                  << 1U)));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xfffff81fU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | ((((((3U == 
                                              (7U & 
                                               (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                >> 0xeU))) 
                                             | (1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xeU)))) 
                                            | (2U == 
                                               (7U 
                                                & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                   >> 0xeU)))) 
                                           | (4U == 
                                              (7U & 
                                               (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                >> 0xeU))))
                                           ? (0x3fU 
                                              & (vlTOPp->CorePipe__DOT__FD_IR 
                                                 >> 0x19U))
                                           : 0U) << 5U));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xfffff7ffU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0x800U & (
                                                   (((3U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                          >> 0xeU))) 
                                                     | (1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                            >> 0xeU))))
                                                     ? 
                                                    (vlTOPp->CorePipe__DOT__FD_IR 
                                                     >> 0x1fU)
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                          >> 0xeU)))
                                                      ? 
                                                     (vlTOPp->CorePipe__DOT__FD_IR 
                                                      >> 7U)
                                                      : 
                                                     ((0U 
                                                       != 
                                                       (7U 
                                                        & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                           >> 0xeU))) 
                                                      & ((4U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                              >> 0xeU))) 
                                                         & (vlTOPp->CorePipe__DOT__FD_IR 
                                                            >> 0x14U))))) 
                                                   << 0xbU)));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0xfff00fffU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0xff000U & 
                                         (((((3U == 
                                              (7U & 
                                               (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                >> 0xeU))) 
                                             | (1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xeU)))) 
                                            | (2U == 
                                               (7U 
                                                & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                   >> 0xeU))))
                                            ? VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->CorePipe__DOT__FD_IR 
                                                                      >> 0x1fU))))
                                            : ((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                    >> 0xeU)))
                                                ? (vlTOPp->CorePipe__DOT__FD_IR 
                                                   >> 0xcU)
                                                : (
                                                   (4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                        >> 0xeU)))
                                                    ? 
                                                   (vlTOPp->CorePipe__DOT__FD_IR 
                                                    >> 0xcU)
                                                    : 0U))) 
                                          << 0xcU)));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0x800fffffU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0x7ff00000U 
                                         & ((((((3U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))) 
                                                | (1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                       >> 0xeU)))) 
                                               | (2U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                              | (4U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))))
                                              ? VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->CorePipe__DOT__FD_IR 
                                                                        >> 0x1fU))))
                                              : ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))
                                                  ? 
                                                 (vlTOPp->CorePipe__DOT__FD_IR 
                                                  >> 0x14U)
                                                  : 0U)) 
                                            << 0x14U)));
    vlTOPp->CorePipe__DOT__IMM_EXT = ((0x7fffffffU 
                                       & vlTOPp->CorePipe__DOT__IMM_EXT) 
                                      | (0x80000000U 
                                         & (((((((3U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xeU))) 
                                                 | (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                        >> 0xeU)))) 
                                                | (2U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                       >> 0xeU)))) 
                                               | (0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                              | (4U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                     >> 0xeU)))) 
                                             << 0x1fU) 
                                            & vlTOPp->CorePipe__DOT__FD_IR)));
    vlTOPp->CorePipe__DOT__STALL = ((((5U == (7U & 
                                              (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                               >> 0xeU))) 
                                      | (1U == (7U 
                                                & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                   >> 0xeU)))) 
                                     | (2U == (7U & 
                                               (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                >> 0xeU))))
                                     ? (((((0x1fU & 
                                            (vlTOPp->CorePipe__DOT__DE_IR 
                                             >> 0xfU)) 
                                           == (0x1fU 
                                               & (vlTOPp->CorePipe__DOT__EM_IR 
                                                  >> 7U))) 
                                          | ((0x1fU 
                                              & (vlTOPp->CorePipe__DOT__DE_IR 
                                                 >> 0x14U)) 
                                             == (0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__EM_IR 
                                                    >> 7U)))) 
                                         & (0U != (0x1fU 
                                                   & (vlTOPp->CorePipe__DOT__EM_IR 
                                                      >> 7U)))) 
                                        | ((((0x1fU 
                                              & (vlTOPp->CorePipe__DOT__DE_IR 
                                                 >> 0xfU)) 
                                             == (0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__MW_IR 
                                                    >> 7U))) 
                                            | ((0x1fU 
                                                & (vlTOPp->CorePipe__DOT__DE_IR 
                                                   >> 0x14U)) 
                                               == (0x1fU 
                                                   & (vlTOPp->CorePipe__DOT__MW_IR 
                                                      >> 7U)))) 
                                           & (0U != 
                                              (0x1fU 
                                               & (vlTOPp->CorePipe__DOT__MW_IR 
                                                  >> 7U)))))
                                     : ((3U == (7U 
                                                & (vlTOPp->CorePipe__DOT__Control__DOT__control_sig 
                                                   >> 0xeU))) 
                                        & ((((0x1fU 
                                              & (vlTOPp->CorePipe__DOT__DE_IR 
                                                 >> 0xfU)) 
                                             == (0x1fU 
                                                 & (vlTOPp->CorePipe__DOT__EM_IR 
                                                    >> 7U))) 
                                            & (0U != 
                                               (0x1fU 
                                                & (vlTOPp->CorePipe__DOT__EM_IR 
                                                   >> 7U)))) 
                                           | (((0x1fU 
                                                & (vlTOPp->CorePipe__DOT__DE_IR 
                                                   >> 0xfU)) 
                                               == (0x1fU 
                                                   & (vlTOPp->CorePipe__DOT__MW_IR 
                                                      >> 7U))) 
                                              & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlTOPp->CorePipe__DOT__MW_IR 
                                                     >> 7U)))))));
    vlTOPp->CorePipe__DOT__FLUSH = (((IData)(vlTOPp->CorePipe__DOT__DE_JUMP) 
                                     | (IData)(vlTOPp->CorePipe__DOT__DE_JUMPR)) 
                                    | (IData)(vlTOPp->CorePipe__DOT__BRNEN));
    vlTOPp->CorePipe__DOT__PC_sig = ((IData)(vlTOPp->CorePipe__DOT__DE_JUMP)
                                      ? vlTOPp->CorePipe__DOT__JUMP_BRANCH_TARGET
                                      : ((IData)(vlTOPp->CorePipe__DOT__DE_JUMPR)
                                          ? (vlTOPp->CorePipe__DOT__DE_SRC1 
                                             + vlTOPp->CorePipe__DOT__DE_IMM_EXT)
                                          : ((IData)(vlTOPp->CorePipe__DOT__BRNEN)
                                              ? vlTOPp->CorePipe__DOT__JUMP_BRANCH_TARGET
                                              : ((IData)(4U) 
                                                 + vlTOPp->CorePipe__DOT__FD_PC))));
}

void VCorePipe::_eval(VCorePipe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_eval\n"); );
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VCorePipe::_eval_initial(VCorePipe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_eval_initial\n"); );
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VCorePipe::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::final\n"); );
    // Variables
    VCorePipe__Syms* __restrict vlSymsp = this->__VlSymsp;
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VCorePipe::_eval_settle(VCorePipe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_eval_settle\n"); );
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData VCorePipe::_change_request(VCorePipe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_change_request\n"); );
    VCorePipe* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCorePipe::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RESET & 0xfeU))) {
        Verilated::overWidthError("RESET");}
}
#endif  // VL_DEBUG

void VCorePipe::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCorePipe::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    RESET = VL_RAND_RESET_I(1);
    PRINT_VAL = VL_RAND_RESET_I(32);
    PRINT_EN = VL_RAND_RESET_I(1);
    CorePipe__DOT__BRNEN = VL_RAND_RESET_I(1);
    CorePipe__DOT__JUMP_BRANCH_TARGET = VL_RAND_RESET_I(32);
    CorePipe__DOT__IMM_EXT = VL_RAND_RESET_I(32);
    CorePipe__DOT__PC_sig = VL_RAND_RESET_I(32);
    CorePipe__DOT__REG_IN = VL_RAND_RESET_I(32);
    CorePipe__DOT__ALU_IN1 = VL_RAND_RESET_I(32);
    CorePipe__DOT__ALU_IN2 = VL_RAND_RESET_I(32);
    CorePipe__DOT__FLUSH = VL_RAND_RESET_I(1);
    CorePipe__DOT__STALL = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_JUMP = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_JUMPR = VL_RAND_RESET_I(1);
    CorePipe__DOT__FD_PC = VL_RAND_RESET_I(32);
    CorePipe__DOT__FD_IR = VL_RAND_RESET_I(32);
    CorePipe__DOT__MW_IR = VL_RAND_RESET_I(32);
    CorePipe__DOT__MW_REGWRT = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_PC = VL_RAND_RESET_I(32);
    CorePipe__DOT__DE_IR = VL_RAND_RESET_I(32);
    CorePipe__DOT__DE_PC_PLUSFOUR = VL_RAND_RESET_I(32);
    CorePipe__DOT__DE_SRC1 = VL_RAND_RESET_I(32);
    CorePipe__DOT__DE_SRC2 = VL_RAND_RESET_I(32);
    CorePipe__DOT__DE_IMM_EXT = VL_RAND_RESET_I(32);
    CorePipe__DOT__DE_BRN = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_ALUSRC1 = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_ALUSRC2 = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_ALUOP = VL_RAND_RESET_I(4);
    CorePipe__DOT__DE_REGWRT = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_MEMRD = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_MEMWRT = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_WRTSRC = VL_RAND_RESET_I(1);
    CorePipe__DOT__DE_M2R = VL_RAND_RESET_I(1);
    CorePipe__DOT__EM_PC_PLUSFOUR = VL_RAND_RESET_I(32);
    CorePipe__DOT__EM_SRC2 = VL_RAND_RESET_I(32);
    CorePipe__DOT__EM_IR = VL_RAND_RESET_I(32);
    CorePipe__DOT__EM_ALUOUT = VL_RAND_RESET_I(32);
    CorePipe__DOT__EM_REGWRT = VL_RAND_RESET_I(1);
    CorePipe__DOT__EM_MEMRD = VL_RAND_RESET_I(1);
    CorePipe__DOT__EM_MEMWRT = VL_RAND_RESET_I(1);
    CorePipe__DOT__EM_WRTSRC = VL_RAND_RESET_I(1);
    CorePipe__DOT__EM_M2R = VL_RAND_RESET_I(1);
    CorePipe__DOT__MW_PC_PLUSFOUR = VL_RAND_RESET_I(32);
    CorePipe__DOT__MW_ALUOUT = VL_RAND_RESET_I(32);
    CorePipe__DOT__MW_R_DATA = VL_RAND_RESET_I(32);
    CorePipe__DOT__MW_WRTSRC = VL_RAND_RESET_I(1);
    CorePipe__DOT__MW_M2R = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<33554432; ++__Vi0) {
            CorePipe__DOT__InstMemory__DOT__I_MEM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<31; ++__Vi0) {
            CorePipe__DOT__RegFile__DOT__REG[__Vi0] = VL_RAND_RESET_I(32);
    }}
    CorePipe__DOT__RegFile__DOT____Vlvbound2 = VL_RAND_RESET_I(32);
    CorePipe__DOT__Control__DOT__INS_ARR = VL_RAND_RESET_I(11);
    CorePipe__DOT__Control__DOT__control_sig = VL_RAND_RESET_I(17);
    CorePipe__DOT__BranchLogic__DOT__w_equal = VL_RAND_RESET_I(1);
    CorePipe__DOT__BranchLogic__DOT__w_signed = VL_RAND_RESET_I(1);
    CorePipe__DOT__BranchLogic__DOT__w_unsigned = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<33554432; ++__Vi0) {
            CorePipe__DOT__DataMemory__DOT__D_MEM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    CorePipe__DOT__DataMemory__DOT__LW = VL_RAND_RESET_I(32);
    CorePipe__DOT__DataMemory__DOT__LH = VL_RAND_RESET_I(16);
    CorePipe__DOT__DataMemory__DOT__LB = VL_RAND_RESET_I(8);
    CorePipe__DOT__DataMemory__DOT__BYTE_WR = VL_RAND_RESET_I(32);
    CorePipe__DOT__DataMemory__DOT__HALF_WR = VL_RAND_RESET_I(32);
}
