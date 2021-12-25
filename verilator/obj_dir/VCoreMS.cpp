// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreMS.h for the primary calling header

#include "VCoreMS.h"
#include "VCoreMS__Syms.h"

//==========

VL_CTOR_IMP(VCoreMS) {
    VCoreMS__Syms* __restrict vlSymsp = __VlSymsp = new VCoreMS__Syms(this, name());
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VCoreMS::__Vconfigure(VCoreMS__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VCoreMS::~VCoreMS() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VCoreMS::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCoreMS::eval\n"); );
    VCoreMS__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("CoreMS.v", 5, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCoreMS::_eval_initial_loop(VCoreMS__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("CoreMS.v", 5, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCoreMS::_initial__TOP__1(VCoreMS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_initial__TOP__1\n"); );
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*191:0*/ __Vtemp1[6];
    WData/*191:0*/ __Vtemp2[6];
    // Body
    __Vtemp1[0U] = 0x2e6d656dU;
    __Vtemp1[1U] = 0x6d6f7279U;
    __Vtemp1[2U] = 0x6e5f6d65U;
    __Vtemp1[3U] = 0x6374696fU;
    __Vtemp1[4U] = 0x73747275U;
    __Vtemp1[5U] = 0x696eU;
    VL_READMEM_N(true, 32, 33554432, 0, VL_CVT_PACK_STR_NW(6, __Vtemp1)
                 , vlTOPp->CoreMS__DOT__InstMemory__DOT__I_MEM
                 , 0, ~VL_ULL(0));
    vlTOPp->CoreMS__DOT__EF_BRNEN = 0U;
    vlTOPp->CoreMS__DOT__WF_JUMP = 0U;
    vlTOPp->CoreMS__DOT__WF_JUMPR = 0U;
    vlTOPp->CoreMS__DOT__WF_JUMP_BRANCH_TARGET = 0U;
    vlTOPp->CoreMS__DOT__WF_JUMPREG_TARGET = 0U;
    __Vtemp2[0U] = 0x2e6d656dU;
    __Vtemp2[1U] = 0x6d6f7279U;
    __Vtemp2[2U] = 0x6e5f6d65U;
    __Vtemp2[3U] = 0x6374696fU;
    __Vtemp2[4U] = 0x73747275U;
    __Vtemp2[5U] = 0x696eU;
    VL_READMEM_N(true, 32, 33554432, 0, VL_CVT_PACK_STR_NW(6, __Vtemp2)
                 , vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM
                 , 0, ~VL_ULL(0));
    vlTOPp->CoreMS__DOT__MW_PC_PLUSFOUR = 0U;
    vlTOPp->CoreMS__DOT__MW_ALUOUT = 0U;
    vlTOPp->CoreMS__DOT__MW_R_DATA = 0U;
    vlTOPp->CoreMS__DOT__MW_JUMP = 0U;
    vlTOPp->CoreMS__DOT__MW_JUMPR = 0U;
    vlTOPp->CoreMS__DOT__MW_JUMP_BRANCH_TARGET = 0U;
    vlTOPp->CoreMS__DOT__MW_JUMPREG_TARGET = 0U;
    vlTOPp->CoreMS__DOT__EM_SRC2 = 0U;
    vlTOPp->CoreMS__DOT__EM_IR = 0U;
    vlTOPp->CoreMS__DOT__DE_IR = 0U;
    vlTOPp->CoreMS__DOT__EM_PC_PLUSFOUR = 0U;
    vlTOPp->CoreMS__DOT__EM_JUMP = 0U;
    vlTOPp->CoreMS__DOT__EM_JUMPR = 0U;
    vlTOPp->CoreMS__DOT__EM_JUMP_BRANCH_TARGET = 0U;
    vlTOPp->CoreMS__DOT__EM_JUMPREG_TARGET = 0U;
    vlTOPp->CoreMS__DOT__DE_SRC2 = 0U;
    vlTOPp->CoreMS__DOT__EM_ALUOUT = 0U;
    vlTOPp->CoreMS__DOT__DE_PC_PLUSFOUR = 0U;
    vlTOPp->CoreMS__DOT__DE_PC = 0U;
    vlTOPp->CoreMS__DOT__DE_IMM_EXT = 0U;
    vlTOPp->CoreMS__DOT__DE_SRC1 = 0U;
    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40000U;
    vlTOPp->CoreMS__DOT__ControlMS__DOT__state = 0U;
    vlTOPp->CoreMS__DOT__FD_PC = 0xfffffffcU;
    vlTOPp->CoreMS__DOT__FD_IR = 0U;
}

VL_INLINE_OPT void VCoreMS::_sequent__TOP__2(VCoreMS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_sequent__TOP__2\n"); );
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__CoreMS__DOT__RegFile__DOT__REG__v0;
    CData/*4:0*/ __Vdlyvdim0__CoreMS__DOT__RegFile__DOT__REG__v31;
    CData/*0:0*/ __Vdlyvset__CoreMS__DOT__RegFile__DOT__REG__v31;
    CData/*2:0*/ __Vdly__CoreMS__DOT__ControlMS__DOT__state;
    CData/*0:0*/ __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v0;
    CData/*0:0*/ __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v1;
    CData/*0:0*/ __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v2;
    IData/*31:0*/ __Vdly__CoreMS__DOT__FD_PC;
    IData/*31:0*/ __Vdly__CoreMS__DOT__FD_IR;
    IData/*31:0*/ __Vdlyvval__CoreMS__DOT__RegFile__DOT__REG__v31;
    IData/*24:0*/ __Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v0;
    IData/*31:0*/ __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v0;
    IData/*24:0*/ __Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v1;
    IData/*31:0*/ __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v1;
    IData/*24:0*/ __Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v2;
    IData/*31:0*/ __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v2;
    // Body
    __Vdly__CoreMS__DOT__ControlMS__DOT__state = vlTOPp->CoreMS__DOT__ControlMS__DOT__state;
    __Vdly__CoreMS__DOT__FD_PC = vlTOPp->CoreMS__DOT__FD_PC;
    __Vdly__CoreMS__DOT__FD_IR = vlTOPp->CoreMS__DOT__FD_IR;
    __Vdlyvset__CoreMS__DOT__RegFile__DOT__REG__v0 = 0U;
    __Vdlyvset__CoreMS__DOT__RegFile__DOT__REG__v31 = 0U;
    __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v0 = 0U;
    __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v1 = 0U;
    __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v2 = 0U;
    vlTOPp->CoreMS__DOT__WF_JUMP_BRANCH_TARGET = ((IData)(vlTOPp->RESET)
                                                   ? 0U
                                                   : vlTOPp->CoreMS__DOT__MW_JUMP_BRANCH_TARGET);
    vlTOPp->CoreMS__DOT__WF_JUMPREG_TARGET = ((IData)(vlTOPp->RESET)
                                               ? 0U
                                               : vlTOPp->CoreMS__DOT__MW_JUMPREG_TARGET);
    vlTOPp->CoreMS__DOT__WF_JUMP = ((~ (IData)(vlTOPp->RESET)) 
                                    & (IData)(vlTOPp->CoreMS__DOT__MW_JUMP));
    vlTOPp->CoreMS__DOT__WF_JUMPR = ((~ (IData)(vlTOPp->RESET)) 
                                     & (IData)(vlTOPp->CoreMS__DOT__MW_JUMPR));
    __Vdly__CoreMS__DOT__FD_PC = ((IData)(vlTOPp->RESET)
                                   ? 0xfffffffcU : 
                                  ((0x40000U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                                    ? vlTOPp->CoreMS__DOT__FD_PC
                                    : vlTOPp->CoreMS__DOT__PC_sig));
    vlTOPp->CoreMS__DOT__EF_BRNEN = ((~ (IData)(vlTOPp->RESET)) 
                                     & ((vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                         >> 0xcU) & 
                                        (((((((0U == 
                                               (7U 
                                                & (vlTOPp->CoreMS__DOT__DE_IR 
                                                   >> 0xcU))) 
                                              & (IData)(vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_equal)) 
                                             | ((1U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CoreMS__DOT__DE_IR 
                                                     >> 0xcU))) 
                                                & (~ (IData)(vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_equal)))) 
                                            | ((4U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__DE_IR 
                                                    >> 0xcU))) 
                                               & (IData)(vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_signed))) 
                                           | ((5U == 
                                               (7U 
                                                & (vlTOPp->CoreMS__DOT__DE_IR 
                                                   >> 0xcU))) 
                                              & (~ (IData)(vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_signed)))) 
                                          | ((6U == 
                                              (7U & 
                                               (vlTOPp->CoreMS__DOT__DE_IR 
                                                >> 0xcU))) 
                                             & (IData)(vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_unsigned))) 
                                         | ((7U == 
                                             (7U & 
                                              (vlTOPp->CoreMS__DOT__DE_IR 
                                               >> 0xcU))) 
                                            & (~ (IData)(vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_unsigned))))));
    __Vdly__CoreMS__DOT__FD_IR = ((IData)(vlTOPp->RESET)
                                   ? 0U : ((0x40000U 
                                            & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                                            ? vlTOPp->CoreMS__DOT__FD_IR
                                            : vlTOPp->CoreMS__DOT__INSTRUCTION));
    if (vlTOPp->RESET) {
        __Vdlyvset__CoreMS__DOT__RegFile__DOT__REG__v0 = 1U;
    } else {
        if (((vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
              >> 1U) & (0U != (0x1fU & (vlTOPp->CoreMS__DOT__FD_IR 
                                        >> 7U))))) {
            vlTOPp->CoreMS__DOT__RegFile__DOT____Vlvbound2 
                = ((4U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                    ? ((8U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                        ? vlTOPp->CoreMS__DOT__MW_R_DATA
                        : ((1U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                            ? vlTOPp->CoreMS__DOT__EM_ALUOUT
                            : vlTOPp->CoreMS__DOT__MW_ALUOUT))
                    : ((1U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                        ? vlTOPp->CoreMS__DOT__EM_PC_PLUSFOUR
                        : vlTOPp->CoreMS__DOT__MW_PC_PLUSFOUR));
            if ((0x1eU >= (0x1fU & ((vlTOPp->CoreMS__DOT__FD_IR 
                                     >> 7U) - (IData)(1U))))) {
                __Vdlyvval__CoreMS__DOT__RegFile__DOT__REG__v31 
                    = vlTOPp->CoreMS__DOT__RegFile__DOT____Vlvbound2;
                __Vdlyvset__CoreMS__DOT__RegFile__DOT__REG__v31 = 1U;
                __Vdlyvdim0__CoreMS__DOT__RegFile__DOT__REG__v31 
                    = (0x1fU & ((vlTOPp->CoreMS__DOT__FD_IR 
                                 >> 7U) - (IData)(1U)));
            }
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->RESET)) & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                             >> 4U)))) {
        if ((2U == (7U & (vlTOPp->CoreMS__DOT__EM_IR 
                          >> 0xcU)))) {
            __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v0 
                = vlTOPp->CoreMS__DOT__EM_SRC2;
            __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v0 = 1U;
            __Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v0 
                = (0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                 >> 2U));
        } else {
            if ((0U == (7U & (vlTOPp->CoreMS__DOT__EM_IR 
                              >> 0xcU)))) {
                __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v1 
                    = (((0x1fU >= (0x18U & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                            << 3U)))
                         ? ((0xffU & vlTOPp->CoreMS__DOT__EM_SRC2) 
                            << (0x18U & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                         << 3U))) : 0U) 
                       | vlTOPp->CoreMS__DOT__DataMemory__DOT__BYTE_WR);
                __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v1 = 1U;
                __Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v1 
                    = (0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                     >> 2U));
            } else {
                if ((1U == (7U & (vlTOPp->CoreMS__DOT__EM_IR 
                                  >> 0xcU)))) {
                    __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v2 
                        = (((0x1fU >= (0x10U & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                                << 4U)))
                             ? ((0xffffU & vlTOPp->CoreMS__DOT__EM_SRC2) 
                                << (0x10U & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                             << 4U)))
                             : 0U) | vlTOPp->CoreMS__DOT__DataMemory__DOT__HALF_WR);
                    __Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v2 = 1U;
                    __Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v2 
                        = (0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                         >> 2U));
                }
            }
        }
    }
    if (__Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v0) {
        vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v0] 
            = __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v0;
    }
    if (__Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v1) {
        vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v1] 
            = __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v1;
    }
    if (__Vdlyvset__CoreMS__DOT__DataMemory__DOT__D_MEM__v2) {
        vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__CoreMS__DOT__DataMemory__DOT__D_MEM__v2] 
            = __Vdlyvval__CoreMS__DOT__DataMemory__DOT__D_MEM__v2;
    }
    vlTOPp->CoreMS__DOT__MW_JUMP_BRANCH_TARGET = ((IData)(vlTOPp->RESET)
                                                   ? 0U
                                                   : vlTOPp->CoreMS__DOT__EM_JUMP_BRANCH_TARGET);
    vlTOPp->CoreMS__DOT__MW_JUMPREG_TARGET = ((IData)(vlTOPp->RESET)
                                               ? 0U
                                               : vlTOPp->CoreMS__DOT__EM_JUMPREG_TARGET);
    vlTOPp->CoreMS__DOT__MW_JUMP = ((~ (IData)(vlTOPp->RESET)) 
                                    & (IData)(vlTOPp->CoreMS__DOT__EM_JUMP));
    vlTOPp->CoreMS__DOT__MW_JUMPR = ((~ (IData)(vlTOPp->RESET)) 
                                     & (IData)(vlTOPp->CoreMS__DOT__EM_JUMPR));
    vlTOPp->CoreMS__DOT__MW_R_DATA = ((IData)(vlTOPp->RESET)
                                       ? 0U : vlTOPp->CoreMS__DOT__R_DATA);
    vlTOPp->CoreMS__DOT__MW_PC_PLUSFOUR = ((IData)(vlTOPp->RESET)
                                            ? 0U : vlTOPp->CoreMS__DOT__EM_PC_PLUSFOUR);
    vlTOPp->CoreMS__DOT__MW_ALUOUT = ((IData)(vlTOPp->RESET)
                                       ? 0U : vlTOPp->CoreMS__DOT__EM_ALUOUT);
    vlTOPp->CoreMS__DOT__EM_IR = ((IData)(vlTOPp->RESET)
                                   ? 0U : vlTOPp->CoreMS__DOT__DE_IR);
    vlTOPp->CoreMS__DOT__EM_SRC2 = ((IData)(vlTOPp->RESET)
                                     ? 0U : vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->CoreMS__DOT__EM_JUMP_BRANCH_TARGET = ((IData)(vlTOPp->RESET)
                                                   ? 0U
                                                   : 
                                                  (vlTOPp->CoreMS__DOT__DE_PC 
                                                   + vlTOPp->CoreMS__DOT__DE_IMM_EXT));
    vlTOPp->CoreMS__DOT__EM_JUMPREG_TARGET = ((IData)(vlTOPp->RESET)
                                               ? 0U
                                               : (vlTOPp->CoreMS__DOT__DE_SRC1 
                                                  + vlTOPp->CoreMS__DOT__DE_IMM_EXT));
    vlTOPp->CoreMS__DOT__EM_JUMP = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                          & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                             >> 0xeU)));
    vlTOPp->CoreMS__DOT__EM_JUMPR = (1U & ((~ (IData)(vlTOPp->RESET)) 
                                           & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                              >> 0xdU)));
    vlTOPp->CoreMS__DOT__EM_PC_PLUSFOUR = ((IData)(vlTOPp->RESET)
                                            ? 0U : vlTOPp->CoreMS__DOT__DE_PC_PLUSFOUR);
    vlTOPp->CoreMS__DOT__EM_ALUOUT = ((IData)(vlTOPp->RESET)
                                       ? 0U : vlTOPp->CoreMS__DOT__ALUOUT);
    vlTOPp->CoreMS__DOT__DE_IR = ((IData)(vlTOPp->RESET)
                                   ? 0U : vlTOPp->CoreMS__DOT__FD_IR);
    vlTOPp->PRINT_VAL = vlTOPp->CoreMS__DOT__EM_SRC2;
    vlTOPp->CoreMS__DOT__DE_SRC2 = ((IData)(vlTOPp->RESET)
                                     ? 0U : ((0U == 
                                              (0x1fU 
                                               & (vlTOPp->CoreMS__DOT__FD_IR 
                                                  >> 0x14U)))
                                              ? 0U : 
                                             ((0x1eU 
                                               >= (0x1fU 
                                                   & ((vlTOPp->CoreMS__DOT__FD_IR 
                                                       >> 0x14U) 
                                                      - (IData)(1U))))
                                               ? vlTOPp->CoreMS__DOT__RegFile__DOT__REG
                                              [(0x1fU 
                                                & ((vlTOPp->CoreMS__DOT__FD_IR 
                                                    >> 0x14U) 
                                                   - (IData)(1U)))]
                                               : 0U)));
    vlTOPp->CoreMS__DOT__DE_PC = ((IData)(vlTOPp->RESET)
                                   ? 0U : vlTOPp->CoreMS__DOT__FD_PC);
    vlTOPp->CoreMS__DOT__DE_IMM_EXT = ((IData)(vlTOPp->RESET)
                                        ? 0U : vlTOPp->CoreMS__DOT__IMM_EXT);
    vlTOPp->CoreMS__DOT__DE_SRC1 = ((IData)(vlTOPp->RESET)
                                     ? 0U : ((0U == 
                                              (0x1fU 
                                               & (vlTOPp->CoreMS__DOT__FD_IR 
                                                  >> 0xfU)))
                                              ? 0U : 
                                             ((0x1eU 
                                               >= (0x1fU 
                                                   & ((vlTOPp->CoreMS__DOT__FD_IR 
                                                       >> 0xfU) 
                                                      - (IData)(1U))))
                                               ? vlTOPp->CoreMS__DOT__RegFile__DOT__REG
                                              [(0x1fU 
                                                & ((vlTOPp->CoreMS__DOT__FD_IR 
                                                    >> 0xfU) 
                                                   - (IData)(1U)))]
                                               : 0U)));
    if (vlTOPp->RESET) {
        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40000U;
    } else {
        if ((4U & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__state))) {
            if ((2U & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__state))) {
                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40000U;
                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
            } else {
                if ((1U & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__state))) {
                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40000U;
                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                } else {
                    if ((0x37U == (0x7fU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                    } else {
                        if ((0x17U == (0x7fU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                        } else {
                            if ((0x6fU == (0x7fU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40003U;
                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                            } else {
                                if ((0x67U == (0x3ffU 
                                               & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40003U;
                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                } else {
                                    if ((0x103U == 
                                         (0x3ffU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x4000eU;
                                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                    } else {
                                        if ((3U == 
                                             (0x3ffU 
                                              & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x4000eU;
                                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                        } else {
                                            if ((0x83U 
                                                 == 
                                                 (0x3ffU 
                                                  & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x4000eU;
                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                            } else {
                                                if (
                                                    (0x203U 
                                                     == 
                                                     (0x3ffU 
                                                      & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x4000eU;
                                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                } else {
                                                    if (
                                                        (0x283U 
                                                         == 
                                                         (0x3ffU 
                                                          & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x4000eU;
                                                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                    } else {
                                                        if (
                                                            (0x13U 
                                                             == 
                                                             (0x3ffU 
                                                              & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                        } else {
                                                            if (
                                                                (0x113U 
                                                                 == 
                                                                 (0x3ffU 
                                                                  & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                            } else {
                                                                if (
                                                                    (0x193U 
                                                                     == 
                                                                     (0x3ffU 
                                                                      & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                } else {
                                                                    if (
                                                                        (0x213U 
                                                                         == 
                                                                         (0x3ffU 
                                                                          & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                    } else {
                                                                        if (
                                                                            (0x313U 
                                                                             == 
                                                                             (0x3ffU 
                                                                              & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                        } else {
                                                                            if (
                                                                                (0x393U 
                                                                                == 
                                                                                (0x3ffU 
                                                                                & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                            } else {
                                                                                if (
                                                                                (0x93U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x293U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x693U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x33U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x433U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0xb3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x133U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x1b3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x233U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x2b3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x6b3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x333U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                if (
                                                                                (0x3b3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40007U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                } else {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40000U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__state))) {
                if ((1U & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__state))) {
                    if ((0x103U == (0x3ffU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40020U;
                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                    } else {
                        if ((3U == (0x3ffU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40020U;
                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                        } else {
                            if ((0x83U == (0x3ffU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40020U;
                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                            } else {
                                if ((0x203U == (0x3ffU 
                                                & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40020U;
                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                } else {
                                    if ((0x283U == 
                                         (0x3ffU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40020U;
                                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                    } else {
                                        if ((0x123U 
                                             == (0x3ffU 
                                                 & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40010U;
                                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                        } else {
                                            if ((0x23U 
                                                 == 
                                                 (0x3ffU 
                                                  & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40010U;
                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                            } else {
                                                if (
                                                    (0xa3U 
                                                     == 
                                                     (0x3ffU 
                                                      & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40010U;
                                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                } else {
                                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40000U;
                                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((0x37U == (0x7fU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40b40U;
                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                    } else {
                        if ((0x17U == (0x7fU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x400c0U;
                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                        } else {
                            if ((0x6fU == (0x7fU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x44000U;
                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                            } else {
                                if ((0x67U == (0x3ffU 
                                               & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x42000U;
                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                } else {
                                    if ((0x63U == (0x7fU 
                                                   & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x41000U;
                                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                    } else {
                                        if ((0x103U 
                                             == (0x3ffU 
                                                 & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 3U;
                                        } else {
                                            if ((3U 
                                                 == 
                                                 (0x3ffU 
                                                  & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 3U;
                                            } else {
                                                if (
                                                    (0x83U 
                                                     == 
                                                     (0x3ffU 
                                                      & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 3U;
                                                } else {
                                                    if (
                                                        (0x203U 
                                                         == 
                                                         (0x3ffU 
                                                          & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 3U;
                                                    } else {
                                                        if (
                                                            (0x283U 
                                                             == 
                                                             (0x3ffU 
                                                              & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 3U;
                                                        } else {
                                                            if (
                                                                (0x123U 
                                                                 == 
                                                                 (0x3ffU 
                                                                  & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 3U;
                                                            } else {
                                                                if (
                                                                    (0x23U 
                                                                     == 
                                                                     (0x3ffU 
                                                                      & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                                                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 3U;
                                                                } else {
                                                                    if (
                                                                        (0xa3U 
                                                                         == 
                                                                         (0x3ffU 
                                                                          & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                        vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                                                        __Vdly__CoreMS__DOT__ControlMS__DOT__state = 3U;
                                                                    } else {
                                                                        if (
                                                                            (0x13U 
                                                                             == 
                                                                             (0x3ffU 
                                                                              & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                            vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40040U;
                                                                            __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                        } else {
                                                                            if (
                                                                                (0x113U 
                                                                                == 
                                                                                (0x3ffU 
                                                                                & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40540U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                            } else {
                                                                                if (
                                                                                (0x193U 
                                                                                == 
                                                                                (0x3ffU 
                                                                                & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40740U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x213U 
                                                                                == 
                                                                                (0x3ffU 
                                                                                & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40440U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x313U 
                                                                                == 
                                                                                (0x3ffU 
                                                                                & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40340U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x393U 
                                                                                == 
                                                                                (0x3ffU 
                                                                                & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40240U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x93U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40640U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x293U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40840U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x693U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40940U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x33U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40000U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x433U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40100U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0xb3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40600U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x133U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40500U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x1b3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40700U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x233U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40400U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x2b3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40800U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x6b3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40900U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x333U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40300U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                if (
                                                                                (0x3b3U 
                                                                                == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))) {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40200U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 4U;
                                                                                } else {
                                                                                vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0x40000U;
                                                                                __Vdly__CoreMS__DOT__ControlMS__DOT__state = 0U;
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__state))) {
                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                        = ((0x37U == (0x7fU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                            ? 0x58000U : ((0x17U == 
                                           (0x7fU & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                           ? 0x58000U
                                           : ((0x6fU 
                                               == (0x7fU 
                                                   & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                               ? 0x60000U
                                               : ((0x67U 
                                                   == 
                                                   (0x3ffU 
                                                    & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                   ? 0x40000U
                                                   : 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                    ? 0x50000U
                                                    : 
                                                   ((0x103U 
                                                     == 
                                                     (0x3ffU 
                                                      & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                     ? 0x40000U
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x3ffU 
                                                       & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                      ? 0x40000U
                                                      : 
                                                     ((0x83U 
                                                       == 
                                                       (0x3ffU 
                                                        & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                       ? 0x40000U
                                                       : 
                                                      ((0x203U 
                                                        == 
                                                        (0x3ffU 
                                                         & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                        ? 0x40000U
                                                        : 
                                                       ((0x283U 
                                                         == 
                                                         (0x3ffU 
                                                          & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                         ? 0x40000U
                                                         : 
                                                        ((0x123U 
                                                          == 
                                                          (0x3ffU 
                                                           & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                          ? 0x48000U
                                                          : 
                                                         ((0x23U 
                                                           == 
                                                           (0x3ffU 
                                                            & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                           ? 0x48000U
                                                           : 
                                                          ((0xa3U 
                                                            == 
                                                            (0x3ffU 
                                                             & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                            ? 0x48000U
                                                            : 
                                                           ((0x13U 
                                                             == 
                                                             (0x3ffU 
                                                              & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                             ? 0x40000U
                                                             : 
                                                            ((0x113U 
                                                              == 
                                                              (0x3ffU 
                                                               & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                              ? 0x40000U
                                                              : 
                                                             ((0x193U 
                                                               == 
                                                               (0x3ffU 
                                                                & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                               ? 0x40000U
                                                               : 
                                                              ((0x213U 
                                                                == 
                                                                (0x3ffU 
                                                                 & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                                ? 0x40000U
                                                                : 
                                                               ((0x313U 
                                                                 == 
                                                                 (0x3ffU 
                                                                  & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                                 ? 0x40000U
                                                                 : 
                                                                ((0x393U 
                                                                  == 
                                                                  (0x3ffU 
                                                                   & (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR)))
                                                                  ? 0x40000U
                                                                  : 
                                                                 ((0x93U 
                                                                   == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                   ? 0x40000U
                                                                   : 
                                                                  ((0x293U 
                                                                    == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                    ? 0x40000U
                                                                    : 
                                                                   ((0x693U 
                                                                     == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                     ? 0x40000U
                                                                     : 
                                                                    ((0x33U 
                                                                      == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                      ? 0x68000U
                                                                      : 
                                                                     ((0x433U 
                                                                       == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                       ? 0x68000U
                                                                       : 
                                                                      ((0xb3U 
                                                                        == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                        ? 0x68000U
                                                                        : 
                                                                       ((0x133U 
                                                                         == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                         ? 0x68000U
                                                                         : 
                                                                        ((0x1b3U 
                                                                          == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                          ? 0x68000U
                                                                          : 
                                                                         ((0x233U 
                                                                           == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                           ? 0x68000U
                                                                           : 
                                                                          ((0x2b3U 
                                                                            == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                            ? 0x68000U
                                                                            : 
                                                                           ((0x6b3U 
                                                                             == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                             ? 0x68000U
                                                                             : 
                                                                            ((0x333U 
                                                                              == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                              ? 0x68000U
                                                                              : 
                                                                             ((0x3b3U 
                                                                               == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR))
                                                                               ? 0x68000U
                                                                               : 0x40000U))))))))))))))))))))))))))))))));
                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 2U;
                } else {
                    vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG = 0U;
                    __Vdly__CoreMS__DOT__ControlMS__DOT__state = 1U;
                }
            }
        }
    }
    vlTOPp->CoreMS__DOT__DE_PC_PLUSFOUR = ((IData)(vlTOPp->RESET)
                                            ? 0U : 
                                           ((IData)(4U) 
                                            + vlTOPp->CoreMS__DOT__FD_PC));
    vlTOPp->CoreMS__DOT__DataMemory__DOT__BYTE_WR = 
        ((~ ((0x1fU >= (((IData)(3U) - (3U & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                        << 3U)) ? (0xff000000U >> (
                                                   ((IData)(3U) 
                                                    - 
                                                    (3U 
                                                     & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                   << 3U))
              : 0U)) & vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM
         [(0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                         >> 2U))]);
    vlTOPp->CoreMS__DOT__DataMemory__DOT__HALF_WR = 
        ((~ ((0x1fU >= (((IData)(1U) - (1U & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                        << 4U)) ? (0xffff0000U >> (
                                                   ((IData)(1U) 
                                                    - 
                                                    (1U 
                                                     & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                   << 4U))
              : 0U)) & vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM
         [(0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                         >> 2U))]);
    vlTOPp->CoreMS__DOT__DataMemory__DOT__LW = vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM
        [(0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                        >> 2U))];
    if (__Vdlyvset__CoreMS__DOT__RegFile__DOT__REG__v0) {
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[1U] = 0x1000000U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[2U] = 0x2000000U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[3U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[4U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[5U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[6U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[7U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[8U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[9U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0xaU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0xbU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0xcU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0xdU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0xeU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0xfU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x10U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x11U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x12U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x13U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x14U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x15U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x16U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x17U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x18U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x19U] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x1aU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x1bU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x1cU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x1dU] = 0U;
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[0x1eU] = 0U;
    }
    if (__Vdlyvset__CoreMS__DOT__RegFile__DOT__REG__v31) {
        vlTOPp->CoreMS__DOT__RegFile__DOT__REG[__Vdlyvdim0__CoreMS__DOT__RegFile__DOT__REG__v31] 
            = __Vdlyvval__CoreMS__DOT__RegFile__DOT__REG__v31;
    }
    vlTOPp->CoreMS__DOT__FD_IR = __Vdly__CoreMS__DOT__FD_IR;
    vlTOPp->CoreMS__DOT__ControlMS__DOT__state = __Vdly__CoreMS__DOT__ControlMS__DOT__state;
    vlTOPp->CoreMS__DOT__FD_PC = __Vdly__CoreMS__DOT__FD_PC;
    vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_equal 
        = (vlTOPp->CoreMS__DOT__DE_SRC1 == vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_signed 
        = VL_LTS_III(1,32,32, vlTOPp->CoreMS__DOT__DE_SRC1, vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_unsigned 
        = (vlTOPp->CoreMS__DOT__DE_SRC1 < vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->PRINT_EN = ((0x3800040cU == (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                         >> 2U)) & 
                        (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                         >> 4U));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xfffffffeU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (1U & ((0U == 
                                              (7U & 
                                               (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                >> 0xfU)))
                                              ? (vlTOPp->CoreMS__DOT__FD_IR 
                                                 >> 0x14U)
                                              : ((1U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 0xfU))) 
                                                 & (vlTOPp->CoreMS__DOT__FD_IR 
                                                    >> 7U)))));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xffffffe1U & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0x1eU & ((((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                       >> 0xfU))) 
                                                  | (4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 0xfU))))
                                                  ? 
                                                 (vlTOPp->CoreMS__DOT__FD_IR 
                                                  >> 0x15U)
                                                  : 
                                                 (((1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 0xfU))) 
                                                   | (2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 0xfU))))
                                                   ? 
                                                  (vlTOPp->CoreMS__DOT__FD_IR 
                                                   >> 8U)
                                                   : 0U)) 
                                                << 1U)));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xfffff81fU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | ((((((0U == (7U 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 0xfU))) 
                                           | (1U == 
                                              (7U & 
                                               (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                >> 0xfU)))) 
                                          | (2U == 
                                             (7U & 
                                              (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                               >> 0xfU)))) 
                                         | (4U == (7U 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 0xfU))))
                                         ? (0x3fU & 
                                            (vlTOPp->CoreMS__DOT__FD_IR 
                                             >> 0x19U))
                                         : 0U) << 5U));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xfffff7ffU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0x800U & (((
                                                   (0U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 0xfU))) 
                                                   | (1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 0xfU))))
                                                   ? 
                                                  (vlTOPp->CoreMS__DOT__FD_IR 
                                                   >> 0x1fU)
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 0xfU)))
                                                    ? 
                                                   (vlTOPp->CoreMS__DOT__FD_IR 
                                                    >> 7U)
                                                    : 
                                                   ((3U 
                                                     != 
                                                     (7U 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 0xfU))) 
                                                    & ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 0xfU))) 
                                                       & (vlTOPp->CoreMS__DOT__FD_IR 
                                                          >> 0x14U))))) 
                                                 << 0xbU)));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xfff00fffU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0xff000U & (
                                                   ((((0U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                           >> 0xfU))) 
                                                      | (1U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                             >> 0xfU)))) 
                                                     | (2U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 0xfU))))
                                                     ? 
                                                    VL_NEGATE_I((IData)(
                                                                        (1U 
                                                                         & (vlTOPp->CoreMS__DOT__FD_IR 
                                                                            >> 0x1fU))))
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 0xfU)))
                                                      ? 
                                                     (vlTOPp->CoreMS__DOT__FD_IR 
                                                      >> 0xcU)
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                           >> 0xfU)))
                                                       ? 
                                                      (vlTOPp->CoreMS__DOT__FD_IR 
                                                       >> 0xcU)
                                                       : 0U))) 
                                                   << 0xcU)));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0x800fffffU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0x7ff00000U 
                                       & ((((((0U == 
                                               (7U 
                                                & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                   >> 0xfU))) 
                                              | (1U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                     >> 0xfU)))) 
                                             | (2U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 0xfU)))) 
                                            | (4U == 
                                               (7U 
                                                & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                   >> 0xfU))))
                                            ? VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->CoreMS__DOT__FD_IR 
                                                                      >> 0x1fU))))
                                            : ((3U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 0xfU)))
                                                ? (vlTOPp->CoreMS__DOT__FD_IR 
                                                   >> 0x14U)
                                                : 0U)) 
                                          << 0x14U)));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0x7fffffffU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0x80000000U 
                                       & (((((((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 0xfU))) 
                                               | (1U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 0xfU)))) 
                                              | (2U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                     >> 0xfU)))) 
                                             | (3U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 0xfU)))) 
                                            | (4U == 
                                               (7U 
                                                & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                   >> 0xfU)))) 
                                           << 0x1fU) 
                                          & vlTOPp->CoreMS__DOT__FD_IR)));
    vlTOPp->CoreMS__DOT__ALU_IN1 = ((0x80U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                                     ? vlTOPp->CoreMS__DOT__DE_PC
                                     : vlTOPp->CoreMS__DOT__DE_SRC1);
    vlTOPp->CoreMS__DOT__ALU_IN2 = ((0x40U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                                     ? vlTOPp->CoreMS__DOT__DE_IMM_EXT
                                     : vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->CoreMS__DOT__DataMemory__DOT__LH = (0xffffU 
                                                & ((1U 
                                                    & ((~ vlTOPp->CoreMS__DOT__EM_ALUOUT) 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 5U)))
                                                    ? 
                                                   (0xffffU 
                                                    & vlTOPp->CoreMS__DOT__DataMemory__DOT__LW)
                                                    : 
                                                   ((1U 
                                                     & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                                        & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                           >> 5U)))
                                                     ? 
                                                    (0xffffU 
                                                     & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                        >> 0x10U))
                                                     : 0U)));
    vlTOPp->CoreMS__DOT__DataMemory__DOT__LB = (0xffU 
                                                & (((0U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                    & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                       >> 5U))
                                                    ? 
                                                   (0xffU 
                                                    & vlTOPp->CoreMS__DOT__DataMemory__DOT__LW)
                                                    : 
                                                   (((1U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 5U))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                        >> 8U))
                                                     : 
                                                    (((2U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 5U))
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                         >> 0x10U))
                                                      : 
                                                     (((3U 
                                                        == 
                                                        (3U 
                                                         & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 5U))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                          >> 0x18U))
                                                       : 0U)))));
    vlTOPp->CoreMS__DOT__PC_sig = ((IData)(vlTOPp->CoreMS__DOT__WF_JUMP)
                                    ? vlTOPp->CoreMS__DOT__WF_JUMP_BRANCH_TARGET
                                    : ((IData)(vlTOPp->CoreMS__DOT__WF_JUMPR)
                                        ? vlTOPp->CoreMS__DOT__WF_JUMPREG_TARGET
                                        : ((IData)(vlTOPp->CoreMS__DOT__EF_BRNEN)
                                            ? vlTOPp->CoreMS__DOT__WF_JUMP_BRANCH_TARGET
                                            : ((IData)(4U) 
                                               + vlTOPp->CoreMS__DOT__FD_PC))));
    vlTOPp->CoreMS__DOT__ALUOUT = ((0U == (0xfU & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                   >> 8U)))
                                    ? (vlTOPp->CoreMS__DOT__ALU_IN1 
                                       + vlTOPp->CoreMS__DOT__ALU_IN2)
                                    : ((1U == (0xfU 
                                               & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                  >> 8U)))
                                        ? (vlTOPp->CoreMS__DOT__ALU_IN1 
                                           - vlTOPp->CoreMS__DOT__ALU_IN2)
                                        : ((2U == (0xfU 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 8U)))
                                            ? (vlTOPp->CoreMS__DOT__ALU_IN1 
                                               & vlTOPp->CoreMS__DOT__ALU_IN2)
                                            : ((3U 
                                                == 
                                                (0xfU 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 8U)))
                                                ? (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                   | vlTOPp->CoreMS__DOT__ALU_IN2)
                                                : (
                                                   (4U 
                                                    == 
                                                    (0xfU 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 8U)))
                                                    ? 
                                                   (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                    ^ vlTOPp->CoreMS__DOT__ALU_IN2)
                                                    : 
                                                   (((5U 
                                                      == 
                                                      (0xfU 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 8U))) 
                                                     & VL_LTS_III(1,32,32, vlTOPp->CoreMS__DOT__ALU_IN1, vlTOPp->CoreMS__DOT__ALU_IN2))
                                                     ? 1U
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (0xfU 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 8U)))
                                                      ? 
                                                     (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                      << 
                                                      (0x1fU 
                                                       & vlTOPp->CoreMS__DOT__ALU_IN2))
                                                      : 
                                                     (((7U 
                                                        == 
                                                        (0xfU 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 8U))) 
                                                       & (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                          < vlTOPp->CoreMS__DOT__ALU_IN2))
                                                       ? 1U
                                                       : 
                                                      ((8U 
                                                        == 
                                                        (0xfU 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 8U)))
                                                        ? 
                                                       (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                        >> 
                                                        (0x1fU 
                                                         & vlTOPp->CoreMS__DOT__ALU_IN2))
                                                        : 
                                                       ((9U 
                                                         == 
                                                         (0xfU 
                                                          & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                             >> 8U)))
                                                         ? 
                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->CoreMS__DOT__ALU_IN1, 
                                                                       (0x1fU 
                                                                        & vlTOPp->CoreMS__DOT__ALU_IN2))
                                                         : 
                                                        ((0xaU 
                                                          == 
                                                          (0xfU 
                                                           & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                              >> 8U)))
                                                          ? vlTOPp->CoreMS__DOT__ALU_IN1
                                                          : 
                                                         ((0xbU 
                                                           == 
                                                           (0xfU 
                                                            & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                               >> 8U)))
                                                           ? vlTOPp->CoreMS__DOT__ALU_IN2
                                                           : 0U))))))))))));
    vlTOPp->CoreMS__DOT__R_DATA = (((2U == (7U & (vlTOPp->CoreMS__DOT__EM_IR 
                                                  >> 0xcU))) 
                                    & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                       >> 5U)) ? vlTOPp->CoreMS__DOT__DataMemory__DOT__LW
                                    : ((((0U == (7U 
                                                 & (vlTOPp->CoreMS__DOT__EM_IR 
                                                    >> 0xcU))) 
                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                            >> 5U)) 
                                        & VL_LTES_III(1,32,32, 0U, 
                                                      VL_EXTENDS_II(32,8, (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LB))))
                                        ? (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LB)
                                        : ((((0U == 
                                              (7U & 
                                               (vlTOPp->CoreMS__DOT__EM_IR 
                                                >> 0xcU))) 
                                             & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                >> 5U)) 
                                            & VL_GTS_III(1,32,32, 0U, 
                                                         VL_EXTENDS_II(32,8, (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LB))))
                                            ? ((IData)(0xffffff00U) 
                                               + (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LB))
                                            : ((((1U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CoreMS__DOT__EM_IR 
                                                      >> 0xcU))) 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 5U)) 
                                                & VL_LTES_III(1,32,32, 0U, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LH))))
                                                ? (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LH)
                                                : (
                                                   (((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__EM_IR 
                                                          >> 0xcU))) 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 5U)) 
                                                    & VL_GTS_III(1,32,32, 0U, 
                                                                 VL_EXTENDS_II(32,16, (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LH))))
                                                    ? 
                                                   ((IData)(0xffff0000U) 
                                                    + (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LH))
                                                    : 
                                                   (((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__EM_IR 
                                                          >> 0xcU))) 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 5U))
                                                     ? 
                                                    (((0U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 5U))
                                                      ? 
                                                     (0xffU 
                                                      & vlTOPp->CoreMS__DOT__DataMemory__DOT__LW)
                                                      : 
                                                     (((1U 
                                                        == 
                                                        (3U 
                                                         & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 5U))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                          >> 8U))
                                                       : 
                                                      (((2U 
                                                         == 
                                                         (3U 
                                                          & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                        & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                           >> 5U))
                                                        ? 
                                                       (0xffU 
                                                        & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                           >> 0x10U))
                                                        : 
                                                       (((3U 
                                                          == 
                                                          (3U 
                                                           & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 5U))
                                                         ? 
                                                        (0xffU 
                                                         & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                            >> 0x18U))
                                                         : 0U))))
                                                     : 
                                                    (((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CoreMS__DOT__EM_IR 
                                                           >> 0xcU))) 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 5U))
                                                      ? 
                                                     ((1U 
                                                       & ((~ vlTOPp->CoreMS__DOT__EM_ALUOUT) 
                                                          & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                             >> 5U)))
                                                       ? 
                                                      (0xffffU 
                                                       & vlTOPp->CoreMS__DOT__DataMemory__DOT__LW)
                                                       : 
                                                      ((1U 
                                                        & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                                           & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                              >> 5U)))
                                                        ? 
                                                       (0xffffU 
                                                        & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                           >> 0x10U))
                                                        : 0U))
                                                      : 0U)))))));
    vlTOPp->CoreMS__DOT__INSTRUCTION = (VL_GTS_III(1,32,32, 0U, vlTOPp->CoreMS__DOT__PC_sig)
                                         ? 0U : vlTOPp->CoreMS__DOT__InstMemory__DOT__I_MEM
                                        [(0x1ffffffU 
                                          & (vlTOPp->CoreMS__DOT__PC_sig 
                                             >> 2U))]);
    vlTOPp->CoreMS__DOT__ControlMS__DOT__INSTRUCTION 
        = ((1U == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__state))
            ? vlTOPp->CoreMS__DOT__INSTRUCTION : vlTOPp->CoreMS__DOT__FD_IR);
    vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR = 
        ((0x400U & (vlTOPp->CoreMS__DOT__ControlMS__DOT__INSTRUCTION 
                    >> 0x14U)) | ((0x380U & (vlTOPp->CoreMS__DOT__ControlMS__DOT__INSTRUCTION 
                                             >> 5U)) 
                                  | (0x7fU & vlTOPp->CoreMS__DOT__ControlMS__DOT__INSTRUCTION)));
}

void VCoreMS::_settle__TOP__3(VCoreMS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_settle__TOP__3\n"); );
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PRINT_VAL = vlTOPp->CoreMS__DOT__EM_SRC2;
    vlTOPp->CoreMS__DOT__DataMemory__DOT__BYTE_WR = 
        ((~ ((0x1fU >= (((IData)(3U) - (3U & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                        << 3U)) ? (0xff000000U >> (
                                                   ((IData)(3U) 
                                                    - 
                                                    (3U 
                                                     & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                   << 3U))
              : 0U)) & vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM
         [(0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                         >> 2U))]);
    vlTOPp->CoreMS__DOT__DataMemory__DOT__HALF_WR = 
        ((~ ((0x1fU >= (((IData)(1U) - (1U & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                        << 4U)) ? (0xffff0000U >> (
                                                   ((IData)(1U) 
                                                    - 
                                                    (1U 
                                                     & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                   << 4U))
              : 0U)) & vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM
         [(0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                         >> 2U))]);
    vlTOPp->CoreMS__DOT__DataMemory__DOT__LW = vlTOPp->CoreMS__DOT__DataMemory__DOT__D_MEM
        [(0x1ffffffU & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                        >> 2U))];
    vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_equal 
        = (vlTOPp->CoreMS__DOT__DE_SRC1 == vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_signed 
        = VL_LTS_III(1,32,32, vlTOPp->CoreMS__DOT__DE_SRC1, vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->CoreMS__DOT__BranchLogic__DOT__w_unsigned 
        = (vlTOPp->CoreMS__DOT__DE_SRC1 < vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->PRINT_EN = ((0x3800040cU == (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                         >> 2U)) & 
                        (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                         >> 4U));
    vlTOPp->CoreMS__DOT__ALU_IN1 = ((0x80U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                                     ? vlTOPp->CoreMS__DOT__DE_PC
                                     : vlTOPp->CoreMS__DOT__DE_SRC1);
    vlTOPp->CoreMS__DOT__ALU_IN2 = ((0x40U & vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG)
                                     ? vlTOPp->CoreMS__DOT__DE_IMM_EXT
                                     : vlTOPp->CoreMS__DOT__DE_SRC2);
    vlTOPp->CoreMS__DOT__PC_sig = ((IData)(vlTOPp->CoreMS__DOT__WF_JUMP)
                                    ? vlTOPp->CoreMS__DOT__WF_JUMP_BRANCH_TARGET
                                    : ((IData)(vlTOPp->CoreMS__DOT__WF_JUMPR)
                                        ? vlTOPp->CoreMS__DOT__WF_JUMPREG_TARGET
                                        : ((IData)(vlTOPp->CoreMS__DOT__EF_BRNEN)
                                            ? vlTOPp->CoreMS__DOT__WF_JUMP_BRANCH_TARGET
                                            : ((IData)(4U) 
                                               + vlTOPp->CoreMS__DOT__FD_PC))));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xfffffffeU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (1U & ((0U == 
                                              (7U & 
                                               (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                >> 0xfU)))
                                              ? (vlTOPp->CoreMS__DOT__FD_IR 
                                                 >> 0x14U)
                                              : ((1U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 0xfU))) 
                                                 & (vlTOPp->CoreMS__DOT__FD_IR 
                                                    >> 7U)))));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xffffffe1U & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0x1eU & ((((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                       >> 0xfU))) 
                                                  | (4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 0xfU))))
                                                  ? 
                                                 (vlTOPp->CoreMS__DOT__FD_IR 
                                                  >> 0x15U)
                                                  : 
                                                 (((1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 0xfU))) 
                                                   | (2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 0xfU))))
                                                   ? 
                                                  (vlTOPp->CoreMS__DOT__FD_IR 
                                                   >> 8U)
                                                   : 0U)) 
                                                << 1U)));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xfffff81fU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | ((((((0U == (7U 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 0xfU))) 
                                           | (1U == 
                                              (7U & 
                                               (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                >> 0xfU)))) 
                                          | (2U == 
                                             (7U & 
                                              (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                               >> 0xfU)))) 
                                         | (4U == (7U 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 0xfU))))
                                         ? (0x3fU & 
                                            (vlTOPp->CoreMS__DOT__FD_IR 
                                             >> 0x19U))
                                         : 0U) << 5U));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xfffff7ffU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0x800U & (((
                                                   (0U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 0xfU))) 
                                                   | (1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 0xfU))))
                                                   ? 
                                                  (vlTOPp->CoreMS__DOT__FD_IR 
                                                   >> 0x1fU)
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 0xfU)))
                                                    ? 
                                                   (vlTOPp->CoreMS__DOT__FD_IR 
                                                    >> 7U)
                                                    : 
                                                   ((3U 
                                                     != 
                                                     (7U 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 0xfU))) 
                                                    & ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 0xfU))) 
                                                       & (vlTOPp->CoreMS__DOT__FD_IR 
                                                          >> 0x14U))))) 
                                                 << 0xbU)));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0xfff00fffU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0xff000U & (
                                                   ((((0U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                           >> 0xfU))) 
                                                      | (1U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                             >> 0xfU)))) 
                                                     | (2U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 0xfU))))
                                                     ? 
                                                    VL_NEGATE_I((IData)(
                                                                        (1U 
                                                                         & (vlTOPp->CoreMS__DOT__FD_IR 
                                                                            >> 0x1fU))))
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 0xfU)))
                                                      ? 
                                                     (vlTOPp->CoreMS__DOT__FD_IR 
                                                      >> 0xcU)
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                           >> 0xfU)))
                                                       ? 
                                                      (vlTOPp->CoreMS__DOT__FD_IR 
                                                       >> 0xcU)
                                                       : 0U))) 
                                                   << 0xcU)));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0x800fffffU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0x7ff00000U 
                                       & ((((((0U == 
                                               (7U 
                                                & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                   >> 0xfU))) 
                                              | (1U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                     >> 0xfU)))) 
                                             | (2U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 0xfU)))) 
                                            | (4U == 
                                               (7U 
                                                & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                   >> 0xfU))))
                                            ? VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->CoreMS__DOT__FD_IR 
                                                                      >> 0x1fU))))
                                            : ((3U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 0xfU)))
                                                ? (vlTOPp->CoreMS__DOT__FD_IR 
                                                   >> 0x14U)
                                                : 0U)) 
                                          << 0x14U)));
    vlTOPp->CoreMS__DOT__IMM_EXT = ((0x7fffffffU & vlTOPp->CoreMS__DOT__IMM_EXT) 
                                    | (0x80000000U 
                                       & (((((((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 0xfU))) 
                                               | (1U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 0xfU)))) 
                                              | (2U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                     >> 0xfU)))) 
                                             | (3U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 0xfU)))) 
                                            | (4U == 
                                               (7U 
                                                & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                   >> 0xfU)))) 
                                           << 0x1fU) 
                                          & vlTOPp->CoreMS__DOT__FD_IR)));
    vlTOPp->CoreMS__DOT__DataMemory__DOT__LH = (0xffffU 
                                                & ((1U 
                                                    & ((~ vlTOPp->CoreMS__DOT__EM_ALUOUT) 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 5U)))
                                                    ? 
                                                   (0xffffU 
                                                    & vlTOPp->CoreMS__DOT__DataMemory__DOT__LW)
                                                    : 
                                                   ((1U 
                                                     & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                                        & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                           >> 5U)))
                                                     ? 
                                                    (0xffffU 
                                                     & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                        >> 0x10U))
                                                     : 0U)));
    vlTOPp->CoreMS__DOT__DataMemory__DOT__LB = (0xffU 
                                                & (((0U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                    & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                       >> 5U))
                                                    ? 
                                                   (0xffU 
                                                    & vlTOPp->CoreMS__DOT__DataMemory__DOT__LW)
                                                    : 
                                                   (((1U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 5U))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                        >> 8U))
                                                     : 
                                                    (((2U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 5U))
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                         >> 0x10U))
                                                      : 
                                                     (((3U 
                                                        == 
                                                        (3U 
                                                         & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 5U))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                          >> 0x18U))
                                                       : 0U)))));
    vlTOPp->CoreMS__DOT__ALUOUT = ((0U == (0xfU & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                   >> 8U)))
                                    ? (vlTOPp->CoreMS__DOT__ALU_IN1 
                                       + vlTOPp->CoreMS__DOT__ALU_IN2)
                                    : ((1U == (0xfU 
                                               & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                  >> 8U)))
                                        ? (vlTOPp->CoreMS__DOT__ALU_IN1 
                                           - vlTOPp->CoreMS__DOT__ALU_IN2)
                                        : ((2U == (0xfU 
                                                   & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                      >> 8U)))
                                            ? (vlTOPp->CoreMS__DOT__ALU_IN1 
                                               & vlTOPp->CoreMS__DOT__ALU_IN2)
                                            : ((3U 
                                                == 
                                                (0xfU 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 8U)))
                                                ? (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                   | vlTOPp->CoreMS__DOT__ALU_IN2)
                                                : (
                                                   (4U 
                                                    == 
                                                    (0xfU 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 8U)))
                                                    ? 
                                                   (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                    ^ vlTOPp->CoreMS__DOT__ALU_IN2)
                                                    : 
                                                   (((5U 
                                                      == 
                                                      (0xfU 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 8U))) 
                                                     & VL_LTS_III(1,32,32, vlTOPp->CoreMS__DOT__ALU_IN1, vlTOPp->CoreMS__DOT__ALU_IN2))
                                                     ? 1U
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (0xfU 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 8U)))
                                                      ? 
                                                     (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                      << 
                                                      (0x1fU 
                                                       & vlTOPp->CoreMS__DOT__ALU_IN2))
                                                      : 
                                                     (((7U 
                                                        == 
                                                        (0xfU 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 8U))) 
                                                       & (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                          < vlTOPp->CoreMS__DOT__ALU_IN2))
                                                       ? 1U
                                                       : 
                                                      ((8U 
                                                        == 
                                                        (0xfU 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 8U)))
                                                        ? 
                                                       (vlTOPp->CoreMS__DOT__ALU_IN1 
                                                        >> 
                                                        (0x1fU 
                                                         & vlTOPp->CoreMS__DOT__ALU_IN2))
                                                        : 
                                                       ((9U 
                                                         == 
                                                         (0xfU 
                                                          & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                             >> 8U)))
                                                         ? 
                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->CoreMS__DOT__ALU_IN1, 
                                                                       (0x1fU 
                                                                        & vlTOPp->CoreMS__DOT__ALU_IN2))
                                                         : 
                                                        ((0xaU 
                                                          == 
                                                          (0xfU 
                                                           & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                              >> 8U)))
                                                          ? vlTOPp->CoreMS__DOT__ALU_IN1
                                                          : 
                                                         ((0xbU 
                                                           == 
                                                           (0xfU 
                                                            & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                               >> 8U)))
                                                           ? vlTOPp->CoreMS__DOT__ALU_IN2
                                                           : 0U))))))))))));
    vlTOPp->CoreMS__DOT__INSTRUCTION = (VL_GTS_III(1,32,32, 0U, vlTOPp->CoreMS__DOT__PC_sig)
                                         ? 0U : vlTOPp->CoreMS__DOT__InstMemory__DOT__I_MEM
                                        [(0x1ffffffU 
                                          & (vlTOPp->CoreMS__DOT__PC_sig 
                                             >> 2U))]);
    vlTOPp->CoreMS__DOT__R_DATA = (((2U == (7U & (vlTOPp->CoreMS__DOT__EM_IR 
                                                  >> 0xcU))) 
                                    & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                       >> 5U)) ? vlTOPp->CoreMS__DOT__DataMemory__DOT__LW
                                    : ((((0U == (7U 
                                                 & (vlTOPp->CoreMS__DOT__EM_IR 
                                                    >> 0xcU))) 
                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                            >> 5U)) 
                                        & VL_LTES_III(1,32,32, 0U, 
                                                      VL_EXTENDS_II(32,8, (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LB))))
                                        ? (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LB)
                                        : ((((0U == 
                                              (7U & 
                                               (vlTOPp->CoreMS__DOT__EM_IR 
                                                >> 0xcU))) 
                                             & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                >> 5U)) 
                                            & VL_GTS_III(1,32,32, 0U, 
                                                         VL_EXTENDS_II(32,8, (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LB))))
                                            ? ((IData)(0xffffff00U) 
                                               + (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LB))
                                            : ((((1U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->CoreMS__DOT__EM_IR 
                                                      >> 0xcU))) 
                                                 & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                    >> 5U)) 
                                                & VL_LTES_III(1,32,32, 0U, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LH))))
                                                ? (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LH)
                                                : (
                                                   (((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__EM_IR 
                                                          >> 0xcU))) 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 5U)) 
                                                    & VL_GTS_III(1,32,32, 0U, 
                                                                 VL_EXTENDS_II(32,16, (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LH))))
                                                    ? 
                                                   ((IData)(0xffff0000U) 
                                                    + (IData)(vlTOPp->CoreMS__DOT__DataMemory__DOT__LH))
                                                    : 
                                                   (((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CoreMS__DOT__EM_IR 
                                                          >> 0xcU))) 
                                                     & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                        >> 5U))
                                                     ? 
                                                    (((0U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 5U))
                                                      ? 
                                                     (0xffU 
                                                      & vlTOPp->CoreMS__DOT__DataMemory__DOT__LW)
                                                      : 
                                                     (((1U 
                                                        == 
                                                        (3U 
                                                         & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                       & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                          >> 5U))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                          >> 8U))
                                                       : 
                                                      (((2U 
                                                         == 
                                                         (3U 
                                                          & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                        & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                           >> 5U))
                                                        ? 
                                                       (0xffU 
                                                        & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                           >> 0x10U))
                                                        : 
                                                       (((3U 
                                                          == 
                                                          (3U 
                                                           & vlTOPp->CoreMS__DOT__EM_ALUOUT)) 
                                                         & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                            >> 5U))
                                                         ? 
                                                        (0xffU 
                                                         & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                            >> 0x18U))
                                                         : 0U))))
                                                     : 
                                                    (((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CoreMS__DOT__EM_IR 
                                                           >> 0xcU))) 
                                                      & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                         >> 5U))
                                                      ? 
                                                     ((1U 
                                                       & ((~ vlTOPp->CoreMS__DOT__EM_ALUOUT) 
                                                          & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                             >> 5U)))
                                                       ? 
                                                      (0xffffU 
                                                       & vlTOPp->CoreMS__DOT__DataMemory__DOT__LW)
                                                       : 
                                                      ((1U 
                                                        & (vlTOPp->CoreMS__DOT__EM_ALUOUT 
                                                           & (vlTOPp->CoreMS__DOT__ControlMS__DOT__CTRL_SIG 
                                                              >> 5U)))
                                                        ? 
                                                       (0xffffU 
                                                        & (vlTOPp->CoreMS__DOT__DataMemory__DOT__LW 
                                                           >> 0x10U))
                                                        : 0U))
                                                      : 0U)))))));
    vlTOPp->CoreMS__DOT__ControlMS__DOT__INSTRUCTION 
        = ((1U == (IData)(vlTOPp->CoreMS__DOT__ControlMS__DOT__state))
            ? vlTOPp->CoreMS__DOT__INSTRUCTION : vlTOPp->CoreMS__DOT__FD_IR);
    vlTOPp->CoreMS__DOT__ControlMS__DOT__INS_ARR = 
        ((0x400U & (vlTOPp->CoreMS__DOT__ControlMS__DOT__INSTRUCTION 
                    >> 0x14U)) | ((0x380U & (vlTOPp->CoreMS__DOT__ControlMS__DOT__INSTRUCTION 
                                             >> 5U)) 
                                  | (0x7fU & vlTOPp->CoreMS__DOT__ControlMS__DOT__INSTRUCTION)));
}

void VCoreMS::_eval(VCoreMS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_eval\n"); );
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VCoreMS::_eval_initial(VCoreMS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_eval_initial\n"); );
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VCoreMS::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::final\n"); );
    // Variables
    VCoreMS__Syms* __restrict vlSymsp = this->__VlSymsp;
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VCoreMS::_eval_settle(VCoreMS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_eval_settle\n"); );
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData VCoreMS::_change_request(VCoreMS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_change_request\n"); );
    VCoreMS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCoreMS::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RESET & 0xfeU))) {
        Verilated::overWidthError("RESET");}
}
#endif  // VL_DEBUG

void VCoreMS::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreMS::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    RESET = VL_RAND_RESET_I(1);
    PRINT_VAL = VL_RAND_RESET_I(32);
    PRINT_EN = VL_RAND_RESET_I(1);
    CoreMS__DOT__INSTRUCTION = VL_RAND_RESET_I(32);
    CoreMS__DOT__IMM_EXT = VL_RAND_RESET_I(32);
    CoreMS__DOT__PC_sig = VL_RAND_RESET_I(32);
    CoreMS__DOT__ALUOUT = VL_RAND_RESET_I(32);
    CoreMS__DOT__R_DATA = VL_RAND_RESET_I(32);
    CoreMS__DOT__ALU_IN1 = VL_RAND_RESET_I(32);
    CoreMS__DOT__ALU_IN2 = VL_RAND_RESET_I(32);
    CoreMS__DOT__EF_BRNEN = VL_RAND_RESET_I(1);
    CoreMS__DOT__WF_JUMP = VL_RAND_RESET_I(1);
    CoreMS__DOT__WF_JUMPR = VL_RAND_RESET_I(1);
    CoreMS__DOT__WF_JUMP_BRANCH_TARGET = VL_RAND_RESET_I(32);
    CoreMS__DOT__WF_JUMPREG_TARGET = VL_RAND_RESET_I(32);
    CoreMS__DOT__FD_PC = VL_RAND_RESET_I(32);
    CoreMS__DOT__FD_IR = VL_RAND_RESET_I(32);
    CoreMS__DOT__DE_PC = VL_RAND_RESET_I(32);
    CoreMS__DOT__DE_IR = VL_RAND_RESET_I(32);
    CoreMS__DOT__DE_PC_PLUSFOUR = VL_RAND_RESET_I(32);
    CoreMS__DOT__DE_SRC1 = VL_RAND_RESET_I(32);
    CoreMS__DOT__DE_SRC2 = VL_RAND_RESET_I(32);
    CoreMS__DOT__DE_IMM_EXT = VL_RAND_RESET_I(32);
    CoreMS__DOT__EM_PC_PLUSFOUR = VL_RAND_RESET_I(32);
    CoreMS__DOT__EM_SRC2 = VL_RAND_RESET_I(32);
    CoreMS__DOT__EM_IR = VL_RAND_RESET_I(32);
    CoreMS__DOT__EM_ALUOUT = VL_RAND_RESET_I(32);
    CoreMS__DOT__EM_JUMP = VL_RAND_RESET_I(1);
    CoreMS__DOT__EM_JUMPR = VL_RAND_RESET_I(1);
    CoreMS__DOT__EM_JUMP_BRANCH_TARGET = VL_RAND_RESET_I(32);
    CoreMS__DOT__EM_JUMPREG_TARGET = VL_RAND_RESET_I(32);
    CoreMS__DOT__MW_PC_PLUSFOUR = VL_RAND_RESET_I(32);
    CoreMS__DOT__MW_ALUOUT = VL_RAND_RESET_I(32);
    CoreMS__DOT__MW_R_DATA = VL_RAND_RESET_I(32);
    CoreMS__DOT__MW_JUMP = VL_RAND_RESET_I(1);
    CoreMS__DOT__MW_JUMPR = VL_RAND_RESET_I(1);
    CoreMS__DOT__MW_JUMP_BRANCH_TARGET = VL_RAND_RESET_I(32);
    CoreMS__DOT__MW_JUMPREG_TARGET = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<33554432; ++__Vi0) {
            CoreMS__DOT__InstMemory__DOT__I_MEM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<31; ++__Vi0) {
            CoreMS__DOT__RegFile__DOT__REG[__Vi0] = VL_RAND_RESET_I(32);
    }}
    CoreMS__DOT__RegFile__DOT____Vlvbound2 = VL_RAND_RESET_I(32);
    CoreMS__DOT__ControlMS__DOT__INS_ARR = VL_RAND_RESET_I(11);
    CoreMS__DOT__ControlMS__DOT__CTRL_SIG = VL_RAND_RESET_I(19);
    CoreMS__DOT__ControlMS__DOT__INSTRUCTION = VL_RAND_RESET_I(32);
    CoreMS__DOT__ControlMS__DOT__state = VL_RAND_RESET_I(3);
    CoreMS__DOT__BranchLogic__DOT__w_equal = VL_RAND_RESET_I(1);
    CoreMS__DOT__BranchLogic__DOT__w_signed = VL_RAND_RESET_I(1);
    CoreMS__DOT__BranchLogic__DOT__w_unsigned = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<33554432; ++__Vi0) {
            CoreMS__DOT__DataMemory__DOT__D_MEM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    CoreMS__DOT__DataMemory__DOT__LW = VL_RAND_RESET_I(32);
    CoreMS__DOT__DataMemory__DOT__LH = VL_RAND_RESET_I(16);
    CoreMS__DOT__DataMemory__DOT__LB = VL_RAND_RESET_I(8);
    CoreMS__DOT__DataMemory__DOT__BYTE_WR = VL_RAND_RESET_I(32);
    CoreMS__DOT__DataMemory__DOT__HALF_WR = VL_RAND_RESET_I(32);
}
