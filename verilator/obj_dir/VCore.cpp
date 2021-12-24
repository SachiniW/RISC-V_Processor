// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCore.h for the primary calling header

#include "VCore.h"
#include "VCore__Syms.h"

//==========

VL_CTOR_IMP(VCore) {
    VCore__Syms* __restrict vlSymsp = __VlSymsp = new VCore__Syms(this, name());
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VCore::__Vconfigure(VCore__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VCore::~VCore() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VCore::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCore::eval\n"); );
    VCore__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Core.v", 5, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCore::_eval_initial_loop(VCore__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Core.v", 5, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCore::_initial__TOP__1(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_initial__TOP__1\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
    VL_READMEM_N(true, 32, 16777217, 0, VL_CVT_PACK_STR_NW(6, __Vtemp1)
                 , vlTOPp->Core__DOT__DataMemory__DOT__D_MEM
                 , 0, ~VL_ULL(0));
    __Vtemp2[0U] = 0x2e6d656dU;
    __Vtemp2[1U] = 0x6d6f7279U;
    __Vtemp2[2U] = 0x6e5f6d65U;
    __Vtemp2[3U] = 0x6374696fU;
    __Vtemp2[4U] = 0x73747275U;
    __Vtemp2[5U] = 0x696eU;
    VL_READMEM_N(true, 32, 16777217, 0, VL_CVT_PACK_STR_NW(6, __Vtemp2)
                 , vlTOPp->Core__DOT__InstMemory__DOT__I_MEM
                 , 0, ~VL_ULL(0));
    vlTOPp->Core__DOT__PC = 0xfffffffcU;
}

VL_INLINE_OPT void VCore::_sequent__TOP__2(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_sequent__TOP__2\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__Core__DOT__RegFile__DOT__REG__v0;
    CData/*4:0*/ __Vdlyvdim0__Core__DOT__RegFile__DOT__REG__v31;
    CData/*0:0*/ __Vdlyvset__Core__DOT__RegFile__DOT__REG__v31;
    CData/*0:0*/ __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v0;
    CData/*0:0*/ __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v1;
    CData/*0:0*/ __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v2;
    IData/*31:0*/ __Vdlyvval__Core__DOT__RegFile__DOT__REG__v31;
    IData/*24:0*/ __Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v0;
    IData/*31:0*/ __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v0;
    IData/*24:0*/ __Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v1;
    IData/*31:0*/ __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v1;
    IData/*24:0*/ __Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v2;
    IData/*31:0*/ __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v2;
    // Body
    __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v0 = 0U;
    __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v1 = 0U;
    __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v2 = 0U;
    __Vdlyvset__Core__DOT__RegFile__DOT__REG__v0 = 0U;
    __Vdlyvset__Core__DOT__RegFile__DOT__REG__v31 = 0U;
    if ((1U & ((~ (IData)(vlTOPp->RESET)) & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                             >> 3U)))) {
        if ((2U == (7U & (vlTOPp->Core__DOT__INSTRUCTION 
                          >> 0xcU)))) {
            vlTOPp->Core__DOT__DataMemory__DOT____Vlvbound1 
                = vlTOPp->Core__DOT__SRC2;
            if ((0x1000000U >= (0x1ffffffU & (vlTOPp->Core__DOT__ALUOUT 
                                              >> 2U)))) {
                __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v0 
                    = vlTOPp->Core__DOT__DataMemory__DOT____Vlvbound1;
                __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v0 = 1U;
                __Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v0 
                    = (0x1ffffffU & (vlTOPp->Core__DOT__ALUOUT 
                                     >> 2U));
            }
        } else {
            if ((0U == (7U & (vlTOPp->Core__DOT__INSTRUCTION 
                              >> 0xcU)))) {
                vlTOPp->Core__DOT__DataMemory__DOT____Vlvbound2 
                    = (((0x1fU >= (0x18U & (vlTOPp->Core__DOT__ALUOUT 
                                            << 3U)))
                         ? ((0xffU & vlTOPp->Core__DOT__SRC2) 
                            << (0x18U & (vlTOPp->Core__DOT__ALUOUT 
                                         << 3U))) : 0U) 
                       | vlTOPp->Core__DOT__DataMemory__DOT__BYTE_WR);
                if ((0x1000000U >= (0x1ffffffU & (vlTOPp->Core__DOT__ALUOUT 
                                                  >> 2U)))) {
                    __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v1 
                        = vlTOPp->Core__DOT__DataMemory__DOT____Vlvbound2;
                    __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v1 = 1U;
                    __Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v1 
                        = (0x1ffffffU & (vlTOPp->Core__DOT__ALUOUT 
                                         >> 2U));
                }
            } else {
                if ((1U == (7U & (vlTOPp->Core__DOT__INSTRUCTION 
                                  >> 0xcU)))) {
                    vlTOPp->Core__DOT__DataMemory__DOT____Vlvbound3 
                        = (((0x1fU >= (0x10U & (vlTOPp->Core__DOT__ALUOUT 
                                                << 4U)))
                             ? ((0xffffU & vlTOPp->Core__DOT__SRC2) 
                                << (0x10U & (vlTOPp->Core__DOT__ALUOUT 
                                             << 4U)))
                             : 0U) | vlTOPp->Core__DOT__DataMemory__DOT__HALF_WR);
                    if ((0x1000000U >= (0x1ffffffU 
                                        & (vlTOPp->Core__DOT__ALUOUT 
                                           >> 2U)))) {
                        __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v2 
                            = vlTOPp->Core__DOT__DataMemory__DOT____Vlvbound3;
                        __Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v2 = 1U;
                        __Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v2 
                            = (0x1ffffffU & (vlTOPp->Core__DOT__ALUOUT 
                                             >> 2U));
                    }
                }
            }
        }
    }
    if (vlTOPp->RESET) {
        __Vdlyvset__Core__DOT__RegFile__DOT__REG__v0 = 1U;
    } else {
        if ((vlTOPp->Core__DOT__Control__DOT__control_sig 
             & (0U != (0x1fU & (vlTOPp->Core__DOT__INSTRUCTION 
                                >> 7U))))) {
            vlTOPp->Core__DOT__RegFile__DOT____Vlvbound2 
                = ((2U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                    ? ((4U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                        ? vlTOPp->Core__DOT__R_DATA
                        : vlTOPp->Core__DOT__ALUOUT)
                    : ((IData)(4U) + vlTOPp->Core__DOT__PC));
            if ((0x1eU >= (0x1fU & ((vlTOPp->Core__DOT__INSTRUCTION 
                                     >> 7U) - (IData)(1U))))) {
                __Vdlyvval__Core__DOT__RegFile__DOT__REG__v31 
                    = vlTOPp->Core__DOT__RegFile__DOT____Vlvbound2;
                __Vdlyvset__Core__DOT__RegFile__DOT__REG__v31 = 1U;
                __Vdlyvdim0__Core__DOT__RegFile__DOT__REG__v31 
                    = (0x1fU & ((vlTOPp->Core__DOT__INSTRUCTION 
                                 >> 7U) - (IData)(1U)));
            }
        }
    }
    if (__Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v0) {
        vlTOPp->Core__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v0] 
            = __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v0;
    }
    if (__Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v1) {
        vlTOPp->Core__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v1] 
            = __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v1;
    }
    if (__Vdlyvset__Core__DOT__DataMemory__DOT__D_MEM__v2) {
        vlTOPp->Core__DOT__DataMemory__DOT__D_MEM[__Vdlyvdim0__Core__DOT__DataMemory__DOT__D_MEM__v2] 
            = __Vdlyvval__Core__DOT__DataMemory__DOT__D_MEM__v2;
    }
    if (__Vdlyvset__Core__DOT__RegFile__DOT__REG__v0) {
        vlTOPp->Core__DOT__RegFile__DOT__REG[0U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[1U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[2U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[3U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[4U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[5U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[6U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[7U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[8U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[9U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0xaU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0xbU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0xcU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0xdU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0xeU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0xfU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x10U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x11U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x12U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x13U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x14U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x15U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x16U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x17U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x18U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x19U] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x1aU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x1bU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x1cU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x1dU] = 0U;
        vlTOPp->Core__DOT__RegFile__DOT__REG[0x1eU] = 0U;
    }
    if (__Vdlyvset__Core__DOT__RegFile__DOT__REG__v31) {
        vlTOPp->Core__DOT__RegFile__DOT__REG[__Vdlyvdim0__Core__DOT__RegFile__DOT__REG__v31] 
            = __Vdlyvval__Core__DOT__RegFile__DOT__REG__v31;
    }
    vlTOPp->Core__DOT__PC = ((IData)(vlTOPp->RESET)
                              ? 0xfffffffcU : vlTOPp->Core__DOT__PC_sig);
    vlTOPp->Core__DOT__INSTRUCTION = (VL_GTS_III(1,32,32, 0U, vlTOPp->Core__DOT__PC)
                                       ? 0U : ((0x1000000U 
                                                >= 
                                                (0x1ffffffU 
                                                 & (vlTOPp->Core__DOT__PC 
                                                    >> 2U)))
                                                ? vlTOPp->Core__DOT__InstMemory__DOT__I_MEM
                                               [(0x1ffffffU 
                                                 & (vlTOPp->Core__DOT__PC 
                                                    >> 2U))]
                                                : 0U));
    vlTOPp->Core__DOT__SRC2 = ((0U == (0x1fU & (vlTOPp->Core__DOT__INSTRUCTION 
                                                >> 0x14U)))
                                ? 0U : ((0x1eU >= (0x1fU 
                                                   & ((vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 0x14U) 
                                                      - (IData)(1U))))
                                         ? vlTOPp->Core__DOT__RegFile__DOT__REG
                                        [(0x1fU & (
                                                   (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0x14U) 
                                                   - (IData)(1U)))]
                                         : 0U));
    vlTOPp->Core__DOT__SRC1 = ((0U == (0x1fU & (vlTOPp->Core__DOT__INSTRUCTION 
                                                >> 0xfU)))
                                ? 0U : ((0x1eU >= (0x1fU 
                                                   & ((vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 0xfU) 
                                                      - (IData)(1U))))
                                         ? vlTOPp->Core__DOT__RegFile__DOT__REG
                                        [(0x1fU & (
                                                   (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0xfU) 
                                                   - (IData)(1U)))]
                                         : 0U));
    vlTOPp->Core__DOT__Control__DOT__INS_ARR = ((0x400U 
                                                 & (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0x14U)) 
                                                | ((0x380U 
                                                    & (vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 5U)) 
                                                   | (0x7fU 
                                                      & vlTOPp->Core__DOT__INSTRUCTION)));
    vlTOPp->PRINT_VAL = vlTOPp->Core__DOT__SRC2;
    vlTOPp->Core__DOT__BranchLogic__DOT__w_equal = 
        (vlTOPp->Core__DOT__SRC1 == vlTOPp->Core__DOT__SRC2);
    vlTOPp->Core__DOT__BranchLogic__DOT__w_signed = 
        VL_LTS_III(1,32,32, vlTOPp->Core__DOT__SRC1, vlTOPp->Core__DOT__SRC2);
    vlTOPp->Core__DOT__BranchLogic__DOT__w_unsigned 
        = (vlTOPp->Core__DOT__SRC1 < vlTOPp->Core__DOT__SRC2);
    vlTOPp->Core__DOT__Control__DOT__control_sig = 
        ((0x37U == (0x7fU & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
          ? 0xc5a3U : ((0x17U == (0x7fU & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                        ? 0xc063U : ((0x6fU == (0x7fU 
                                                & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                      ? 0x12001U : 
                                     ((0x67U == (0x3ffU 
                                                 & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                       ? 0x1001U : 
                                      ((0x63U == (0x7fU 
                                                  & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                        ? 0x8800U : 
                                       ((0x103U == 
                                         (0x3ffU & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                         ? 0x37U : 
                                        ((3U == (0x3ffU 
                                                 & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                          ? 0x37U : 
                                         ((0x83U == 
                                           (0x3ffU 
                                            & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                           ? 0x37U : 
                                          ((0x203U 
                                            == (0x3ffU 
                                                & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                            ? 0x37U
                                            : ((0x283U 
                                                == 
                                                (0x3ffU 
                                                 & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                ? 0x37U
                                                : (
                                                   (0x123U 
                                                    == 
                                                    (0x3ffU 
                                                     & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                    ? 0x4028U
                                                    : 
                                                   ((0x23U 
                                                     == 
                                                     (0x3ffU 
                                                      & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                     ? 0x4028U
                                                     : 
                                                    ((0xa3U 
                                                      == 
                                                      (0x3ffU 
                                                       & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                      ? 0x4028U
                                                      : 
                                                     ((0x13U 
                                                       == 
                                                       (0x3ffU 
                                                        & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                       ? 0x23U
                                                       : 
                                                      ((0x113U 
                                                        == 
                                                        (0x3ffU 
                                                         & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                        ? 0x2a3U
                                                        : 
                                                       ((0x193U 
                                                         == 
                                                         (0x3ffU 
                                                          & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                         ? 0x3a3U
                                                         : 
                                                        ((0x213U 
                                                          == 
                                                          (0x3ffU 
                                                           & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                          ? 0x223U
                                                          : 
                                                         ((0x313U 
                                                           == 
                                                           (0x3ffU 
                                                            & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                           ? 0x1a3U
                                                           : 
                                                          ((0x393U 
                                                            == 
                                                            (0x3ffU 
                                                             & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                            ? 0x123U
                                                            : 
                                                           ((0x93U 
                                                             == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                             ? 0x323U
                                                             : 
                                                            ((0x293U 
                                                              == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                              ? 0x423U
                                                              : 
                                                             ((0x693U 
                                                               == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                               ? 0x4a3U
                                                               : 
                                                              ((0x33U 
                                                                == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                ? 0x14003U
                                                                : 
                                                               ((0x433U 
                                                                 == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                 ? 0x14083U
                                                                 : 
                                                                ((0xb3U 
                                                                  == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                  ? 0x14303U
                                                                  : 
                                                                 ((0x133U 
                                                                   == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                   ? 0x14283U
                                                                   : 
                                                                  ((0x1b3U 
                                                                    == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                    ? 0x14383U
                                                                    : 
                                                                   ((0x233U 
                                                                     == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                     ? 0x14203U
                                                                     : 
                                                                    ((0x2b3U 
                                                                      == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                      ? 0x14403U
                                                                      : 
                                                                     ((0x6b3U 
                                                                       == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                       ? 0x14483U
                                                                       : 
                                                                      ((0x333U 
                                                                        == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                        ? 0x14183U
                                                                        : 
                                                                       ((0x3b3U 
                                                                         == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                         ? 0x14103U
                                                                         : 0U))))))))))))))))))))))))))))))));
    vlTOPp->Core__DOT__ALU_IN1 = ((0x40U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                                   ? vlTOPp->Core__DOT__PC
                                   : vlTOPp->Core__DOT__SRC1);
    vlTOPp->Core__DOT__IMM_EXT = ((0xfffffffeU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (1U & ((0U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))
                                            ? (vlTOPp->Core__DOT__INSTRUCTION 
                                               >> 0x14U)
                                            : ((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                    >> 0xeU))) 
                                               & (vlTOPp->Core__DOT__INSTRUCTION 
                                                  >> 7U)))));
    vlTOPp->Core__DOT__IMM_EXT = ((0xffffffe1U & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0x1eU & ((((0U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))) 
                                                | (4U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 0xeU))))
                                                ? (vlTOPp->Core__DOT__INSTRUCTION 
                                                   >> 0x15U)
                                                : (
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 0xeU))) 
                                                    | (2U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                           >> 0xeU))))
                                                    ? 
                                                   (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 8U)
                                                    : 0U)) 
                                              << 1U)));
    vlTOPp->Core__DOT__IMM_EXT = ((0xfffff81fU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | ((((((0U == (7U 
                                                 & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                    >> 0xeU))) 
                                         | (1U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                        | (2U == (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU)))) 
                                       | (4U == (7U 
                                                 & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                    >> 0xeU))))
                                       ? (0x3fU & (vlTOPp->Core__DOT__INSTRUCTION 
                                                   >> 0x19U))
                                       : 0U) << 5U));
    vlTOPp->Core__DOT__IMM_EXT = ((0xfffff7ffU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0x800U & ((((0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU))) 
                                                 | (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 0xeU))))
                                                 ? 
                                                (vlTOPp->Core__DOT__INSTRUCTION 
                                                 >> 0x1fU)
                                                 : 
                                                ((2U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))
                                                  ? 
                                                 (vlTOPp->Core__DOT__INSTRUCTION 
                                                  >> 7U)
                                                  : 
                                                 ((3U 
                                                   != 
                                                   (7U 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 0xeU))) 
                                                  & ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 0xeU))) 
                                                     & (vlTOPp->Core__DOT__INSTRUCTION 
                                                        >> 0x14U))))) 
                                               << 0xbU)));
    vlTOPp->Core__DOT__IMM_EXT = ((0xfff00fffU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0xff000U & (((
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 0xeU))) 
                                                    | (1U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                           >> 0xeU)))) 
                                                   | (2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 0xeU))))
                                                   ? 
                                                  VL_NEGATE_I((IData)(
                                                                      (1U 
                                                                       & (vlTOPp->Core__DOT__INSTRUCTION 
                                                                          >> 0x1fU))))
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 0xeU)))
                                                    ? 
                                                   (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0xcU)
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 0xeU)))
                                                     ? 
                                                    (vlTOPp->Core__DOT__INSTRUCTION 
                                                     >> 0xcU)
                                                     : 0U))) 
                                                 << 0xcU)));
    vlTOPp->Core__DOT__IMM_EXT = ((0x800fffffU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0x7ff00000U & 
                                     ((((((0U == (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))) 
                                          | (1U == 
                                             (7U & 
                                              (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                               >> 0xeU)))) 
                                         | (2U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                        | (4U == (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))))
                                        ? VL_NEGATE_I((IData)(
                                                              (1U 
                                                               & (vlTOPp->Core__DOT__INSTRUCTION 
                                                                  >> 0x1fU))))
                                        : ((3U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))
                                            ? (vlTOPp->Core__DOT__INSTRUCTION 
                                               >> 0x14U)
                                            : 0U)) 
                                      << 0x14U)));
    vlTOPp->Core__DOT__IMM_EXT = ((0x7fffffffU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0x80000000U & 
                                     (((((((0U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU))) 
                                           | (1U == 
                                              (7U & 
                                               (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                >> 0xeU)))) 
                                          | (2U == 
                                             (7U & 
                                              (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                               >> 0xeU)))) 
                                         | (3U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                        | (4U == (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU)))) 
                                       << 0x1fU) & vlTOPp->Core__DOT__INSTRUCTION)));
    vlTOPp->Core__DOT__JUMP_BRANCH_TARGET = (vlTOPp->Core__DOT__PC 
                                             + vlTOPp->Core__DOT__IMM_EXT);
    vlTOPp->Core__DOT__ALU_IN2 = ((0x20U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                                   ? vlTOPp->Core__DOT__IMM_EXT
                                   : vlTOPp->Core__DOT__SRC2);
    vlTOPp->Core__DOT__PC_sig = ((0x2000U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                                  ? vlTOPp->Core__DOT__JUMP_BRANCH_TARGET
                                  : ((0x1000U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                                      ? (vlTOPp->Core__DOT__SRC1 
                                         + vlTOPp->Core__DOT__IMM_EXT)
                                      : (((vlTOPp->Core__DOT__Control__DOT__control_sig 
                                           >> 0xbU) 
                                          & (((((((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 0xcU))) 
                                                  & (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_equal)) 
                                                 | ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__INSTRUCTION 
                                                         >> 0xcU))) 
                                                    & (~ (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_equal)))) 
                                                | ((4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__INSTRUCTION 
                                                        >> 0xcU))) 
                                                   & (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_signed))) 
                                               | ((5U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 0xcU))) 
                                                  & (~ (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_signed)))) 
                                              | ((6U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->Core__DOT__INSTRUCTION 
                                                      >> 0xcU))) 
                                                 & (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_unsigned))) 
                                             | ((7U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->Core__DOT__INSTRUCTION 
                                                     >> 0xcU))) 
                                                & (~ (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_unsigned)))))
                                          ? vlTOPp->Core__DOT__JUMP_BRANCH_TARGET
                                          : ((IData)(4U) 
                                             + vlTOPp->Core__DOT__PC))));
    vlTOPp->Core__DOT__ALUOUT = ((0U == (0xfU & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                 >> 7U)))
                                  ? (vlTOPp->Core__DOT__ALU_IN1 
                                     + vlTOPp->Core__DOT__ALU_IN2)
                                  : ((1U == (0xfU & 
                                             (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                              >> 7U)))
                                      ? (vlTOPp->Core__DOT__ALU_IN1 
                                         - vlTOPp->Core__DOT__ALU_IN2)
                                      : ((2U == (0xfU 
                                                 & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                    >> 7U)))
                                          ? (vlTOPp->Core__DOT__ALU_IN1 
                                             & vlTOPp->Core__DOT__ALU_IN2)
                                          : ((3U == 
                                              (0xfU 
                                               & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                  >> 7U)))
                                              ? (vlTOPp->Core__DOT__ALU_IN1 
                                                 | vlTOPp->Core__DOT__ALU_IN2)
                                              : ((4U 
                                                  == 
                                                  (0xfU 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 7U)))
                                                  ? 
                                                 (vlTOPp->Core__DOT__ALU_IN1 
                                                  ^ vlTOPp->Core__DOT__ALU_IN2)
                                                  : 
                                                 (((5U 
                                                    == 
                                                    (0xfU 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 7U))) 
                                                   & VL_LTS_III(1,32,32, vlTOPp->Core__DOT__ALU_IN1, vlTOPp->Core__DOT__ALU_IN2))
                                                   ? 1U
                                                   : 
                                                  ((6U 
                                                    == 
                                                    (0xfU 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 7U)))
                                                    ? 
                                                   (vlTOPp->Core__DOT__ALU_IN1 
                                                    << 
                                                    (0x1fU 
                                                     & vlTOPp->Core__DOT__ALU_IN2))
                                                    : 
                                                   (((7U 
                                                      == 
                                                      (0xfU 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 7U))) 
                                                     & (vlTOPp->Core__DOT__ALU_IN1 
                                                        < vlTOPp->Core__DOT__ALU_IN2))
                                                     ? 1U
                                                     : 
                                                    ((8U 
                                                      == 
                                                      (0xfU 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 7U)))
                                                      ? 
                                                     (vlTOPp->Core__DOT__ALU_IN1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlTOPp->Core__DOT__ALU_IN2))
                                                      : 
                                                     ((9U 
                                                       == 
                                                       (0xfU 
                                                        & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                           >> 7U)))
                                                       ? 
                                                      (vlTOPp->Core__DOT__ALU_IN1 
                                                       >> 
                                                       (0x1fU 
                                                        & vlTOPp->Core__DOT__ALU_IN2))
                                                       : 
                                                      ((0xaU 
                                                        == 
                                                        (0xfU 
                                                         & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                            >> 7U)))
                                                        ? vlTOPp->Core__DOT__ALU_IN1
                                                        : 
                                                       ((0xbU 
                                                         == 
                                                         (0xfU 
                                                          & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                             >> 7U)))
                                                         ? vlTOPp->Core__DOT__ALU_IN2
                                                         : 0U))))))))))));
    vlTOPp->Core__DOT__DataMemory__DOT__BYTE_WR = (
                                                   (~ 
                                                    ((0x1fU 
                                                      >= 
                                                      (((IData)(3U) 
                                                        - 
                                                        (3U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       << 3U))
                                                      ? 
                                                     (0xff000000U 
                                                      >> 
                                                      (((IData)(3U) 
                                                        - 
                                                        (3U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       << 3U))
                                                      : 0U)) 
                                                   & ((0x1000000U 
                                                       >= 
                                                       (0x1ffffffU 
                                                        & (vlTOPp->Core__DOT__ALUOUT 
                                                           >> 2U)))
                                                       ? 
                                                      vlTOPp->Core__DOT__DataMemory__DOT__D_MEM
                                                      [
                                                      (0x1ffffffU 
                                                       & (vlTOPp->Core__DOT__ALUOUT 
                                                          >> 2U))]
                                                       : 0U));
    vlTOPp->Core__DOT__DataMemory__DOT__HALF_WR = (
                                                   (~ 
                                                    ((0x1fU 
                                                      >= 
                                                      (((IData)(1U) 
                                                        - 
                                                        (1U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       << 4U))
                                                      ? 
                                                     (0xffff0000U 
                                                      >> 
                                                      (((IData)(1U) 
                                                        - 
                                                        (1U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       << 4U))
                                                      : 0U)) 
                                                   & ((0x1000000U 
                                                       >= 
                                                       (0x1ffffffU 
                                                        & (vlTOPp->Core__DOT__ALUOUT 
                                                           >> 2U)))
                                                       ? 
                                                      vlTOPp->Core__DOT__DataMemory__DOT__D_MEM
                                                      [
                                                      (0x1ffffffU 
                                                       & (vlTOPp->Core__DOT__ALUOUT 
                                                          >> 2U))]
                                                       : 0U));
    vlTOPp->PRINT_EN = ((0xe0001030U == (vlTOPp->Core__DOT__ALUOUT 
                                         >> 2U)) & 
                        (vlTOPp->Core__DOT__Control__DOT__control_sig 
                         >> 3U));
    vlTOPp->Core__DOT__DataMemory__DOT__LW = ((0x1000000U 
                                               >= (0x1ffffffU 
                                                   & (vlTOPp->Core__DOT__ALUOUT 
                                                      >> 2U)))
                                               ? vlTOPp->Core__DOT__DataMemory__DOT__D_MEM
                                              [(0x1ffffffU 
                                                & (vlTOPp->Core__DOT__ALUOUT 
                                                   >> 2U))]
                                               : 0U);
    vlTOPp->Core__DOT__DataMemory__DOT__LH = (0xffffU 
                                              & ((1U 
                                                  & ((~ vlTOPp->Core__DOT__ALUOUT) 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 4U)))
                                                  ? 
                                                 (0xffffU 
                                                  & vlTOPp->Core__DOT__DataMemory__DOT__LW)
                                                  : 
                                                 ((1U 
                                                   & (vlTOPp->Core__DOT__ALUOUT 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 4U)))
                                                   ? 
                                                  (0xffffU 
                                                   & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                      >> 0x10U))
                                                   : 0U)));
    vlTOPp->Core__DOT__DataMemory__DOT__LB = (0xffU 
                                              & (((0U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->Core__DOT__ALUOUT)) 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 4U))
                                                  ? 
                                                 (0xffU 
                                                  & vlTOPp->Core__DOT__DataMemory__DOT__LW)
                                                  : 
                                                 (((1U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->Core__DOT__ALUOUT)) 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 4U))
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                      >> 8U))
                                                   : 
                                                  (((2U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->Core__DOT__ALUOUT)) 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 4U))
                                                    ? 
                                                   (0xffU 
                                                    & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                       >> 0x10U))
                                                    : 
                                                   (((3U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->Core__DOT__ALUOUT)) 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 4U))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                        >> 0x18U))
                                                     : 0U)))));
    vlTOPp->Core__DOT__R_DATA = (((2U == (7U & (vlTOPp->Core__DOT__INSTRUCTION 
                                                >> 0xcU))) 
                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                     >> 4U)) ? vlTOPp->Core__DOT__DataMemory__DOT__LW
                                  : ((((0U == (7U & 
                                               (vlTOPp->Core__DOT__INSTRUCTION 
                                                >> 0xcU))) 
                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                          >> 4U)) & 
                                      VL_LTES_III(1,32,32, 0U, 
                                                  VL_EXTENDS_II(32,8, (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LB))))
                                      ? (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LB)
                                      : ((((0U == (7U 
                                                   & (vlTOPp->Core__DOT__INSTRUCTION 
                                                      >> 0xcU))) 
                                           & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                              >> 4U)) 
                                          & VL_GTS_III(1,32,32, 0U, 
                                                       VL_EXTENDS_II(32,8, (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LB))))
                                          ? ((IData)(0xffffff00U) 
                                             + (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LB))
                                          : ((((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0xcU))) 
                                               & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                  >> 4U)) 
                                              & VL_LTES_III(1,32,32, 0U, 
                                                            VL_EXTENDS_II(32,16, (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LH))))
                                              ? (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LH)
                                              : (((
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__INSTRUCTION 
                                                        >> 0xcU))) 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 4U)) 
                                                  & VL_GTS_III(1,32,32, 0U, 
                                                               VL_EXTENDS_II(32,16, (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LH))))
                                                  ? 
                                                 ((IData)(0xffff0000U) 
                                                  + (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LH))
                                                  : 
                                                 (((4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__INSTRUCTION 
                                                        >> 0xcU))) 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 4U))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->Core__DOT__ALUOUT)) 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 4U))
                                                    ? 
                                                   (0xffU 
                                                    & vlTOPp->Core__DOT__DataMemory__DOT__LW)
                                                    : 
                                                   (((1U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->Core__DOT__ALUOUT)) 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 4U))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                        >> 8U))
                                                     : 
                                                    (((2U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->Core__DOT__ALUOUT)) 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 4U))
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                         >> 0x10U))
                                                      : 
                                                     (((3U 
                                                        == 
                                                        (3U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 4U))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                          >> 0x18U))
                                                       : 0U))))
                                                   : 
                                                  (((5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__INSTRUCTION 
                                                         >> 0xcU))) 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 4U))
                                                    ? 
                                                   ((1U 
                                                     & ((~ vlTOPp->Core__DOT__ALUOUT) 
                                                        & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                           >> 4U)))
                                                     ? 
                                                    (0xffffU 
                                                     & vlTOPp->Core__DOT__DataMemory__DOT__LW)
                                                     : 
                                                    ((1U 
                                                      & (vlTOPp->Core__DOT__ALUOUT 
                                                         & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                            >> 4U)))
                                                      ? 
                                                     (0xffffU 
                                                      & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                         >> 0x10U))
                                                      : 0U))
                                                    : 0U)))))));
}

void VCore::_settle__TOP__3(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_settle__TOP__3\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Core__DOT__INSTRUCTION = (VL_GTS_III(1,32,32, 0U, vlTOPp->Core__DOT__PC)
                                       ? 0U : ((0x1000000U 
                                                >= 
                                                (0x1ffffffU 
                                                 & (vlTOPp->Core__DOT__PC 
                                                    >> 2U)))
                                                ? vlTOPp->Core__DOT__InstMemory__DOT__I_MEM
                                               [(0x1ffffffU 
                                                 & (vlTOPp->Core__DOT__PC 
                                                    >> 2U))]
                                                : 0U));
    vlTOPp->Core__DOT__SRC2 = ((0U == (0x1fU & (vlTOPp->Core__DOT__INSTRUCTION 
                                                >> 0x14U)))
                                ? 0U : ((0x1eU >= (0x1fU 
                                                   & ((vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 0x14U) 
                                                      - (IData)(1U))))
                                         ? vlTOPp->Core__DOT__RegFile__DOT__REG
                                        [(0x1fU & (
                                                   (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0x14U) 
                                                   - (IData)(1U)))]
                                         : 0U));
    vlTOPp->Core__DOT__SRC1 = ((0U == (0x1fU & (vlTOPp->Core__DOT__INSTRUCTION 
                                                >> 0xfU)))
                                ? 0U : ((0x1eU >= (0x1fU 
                                                   & ((vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 0xfU) 
                                                      - (IData)(1U))))
                                         ? vlTOPp->Core__DOT__RegFile__DOT__REG
                                        [(0x1fU & (
                                                   (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0xfU) 
                                                   - (IData)(1U)))]
                                         : 0U));
    vlTOPp->Core__DOT__Control__DOT__INS_ARR = ((0x400U 
                                                 & (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0x14U)) 
                                                | ((0x380U 
                                                    & (vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 5U)) 
                                                   | (0x7fU 
                                                      & vlTOPp->Core__DOT__INSTRUCTION)));
    vlTOPp->PRINT_VAL = vlTOPp->Core__DOT__SRC2;
    vlTOPp->Core__DOT__BranchLogic__DOT__w_equal = 
        (vlTOPp->Core__DOT__SRC1 == vlTOPp->Core__DOT__SRC2);
    vlTOPp->Core__DOT__BranchLogic__DOT__w_signed = 
        VL_LTS_III(1,32,32, vlTOPp->Core__DOT__SRC1, vlTOPp->Core__DOT__SRC2);
    vlTOPp->Core__DOT__BranchLogic__DOT__w_unsigned 
        = (vlTOPp->Core__DOT__SRC1 < vlTOPp->Core__DOT__SRC2);
    vlTOPp->Core__DOT__Control__DOT__control_sig = 
        ((0x37U == (0x7fU & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
          ? 0xc5a3U : ((0x17U == (0x7fU & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                        ? 0xc063U : ((0x6fU == (0x7fU 
                                                & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                      ? 0x12001U : 
                                     ((0x67U == (0x3ffU 
                                                 & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                       ? 0x1001U : 
                                      ((0x63U == (0x7fU 
                                                  & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                        ? 0x8800U : 
                                       ((0x103U == 
                                         (0x3ffU & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                         ? 0x37U : 
                                        ((3U == (0x3ffU 
                                                 & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                          ? 0x37U : 
                                         ((0x83U == 
                                           (0x3ffU 
                                            & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                           ? 0x37U : 
                                          ((0x203U 
                                            == (0x3ffU 
                                                & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                            ? 0x37U
                                            : ((0x283U 
                                                == 
                                                (0x3ffU 
                                                 & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                ? 0x37U
                                                : (
                                                   (0x123U 
                                                    == 
                                                    (0x3ffU 
                                                     & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                    ? 0x4028U
                                                    : 
                                                   ((0x23U 
                                                     == 
                                                     (0x3ffU 
                                                      & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                     ? 0x4028U
                                                     : 
                                                    ((0xa3U 
                                                      == 
                                                      (0x3ffU 
                                                       & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                      ? 0x4028U
                                                      : 
                                                     ((0x13U 
                                                       == 
                                                       (0x3ffU 
                                                        & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                       ? 0x23U
                                                       : 
                                                      ((0x113U 
                                                        == 
                                                        (0x3ffU 
                                                         & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                        ? 0x2a3U
                                                        : 
                                                       ((0x193U 
                                                         == 
                                                         (0x3ffU 
                                                          & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                         ? 0x3a3U
                                                         : 
                                                        ((0x213U 
                                                          == 
                                                          (0x3ffU 
                                                           & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                          ? 0x223U
                                                          : 
                                                         ((0x313U 
                                                           == 
                                                           (0x3ffU 
                                                            & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                           ? 0x1a3U
                                                           : 
                                                          ((0x393U 
                                                            == 
                                                            (0x3ffU 
                                                             & (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR)))
                                                            ? 0x123U
                                                            : 
                                                           ((0x93U 
                                                             == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                             ? 0x323U
                                                             : 
                                                            ((0x293U 
                                                              == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                              ? 0x423U
                                                              : 
                                                             ((0x693U 
                                                               == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                               ? 0x4a3U
                                                               : 
                                                              ((0x33U 
                                                                == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                ? 0x14003U
                                                                : 
                                                               ((0x433U 
                                                                 == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                 ? 0x14083U
                                                                 : 
                                                                ((0xb3U 
                                                                  == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                  ? 0x14303U
                                                                  : 
                                                                 ((0x133U 
                                                                   == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                   ? 0x14283U
                                                                   : 
                                                                  ((0x1b3U 
                                                                    == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                    ? 0x14383U
                                                                    : 
                                                                   ((0x233U 
                                                                     == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                     ? 0x14203U
                                                                     : 
                                                                    ((0x2b3U 
                                                                      == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                      ? 0x14403U
                                                                      : 
                                                                     ((0x6b3U 
                                                                       == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                       ? 0x14483U
                                                                       : 
                                                                      ((0x333U 
                                                                        == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                        ? 0x14183U
                                                                        : 
                                                                       ((0x3b3U 
                                                                         == (IData)(vlTOPp->Core__DOT__Control__DOT__INS_ARR))
                                                                         ? 0x14103U
                                                                         : 0U))))))))))))))))))))))))))))))));
    vlTOPp->Core__DOT__ALU_IN1 = ((0x40U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                                   ? vlTOPp->Core__DOT__PC
                                   : vlTOPp->Core__DOT__SRC1);
    vlTOPp->Core__DOT__IMM_EXT = ((0xfffffffeU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (1U & ((0U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))
                                            ? (vlTOPp->Core__DOT__INSTRUCTION 
                                               >> 0x14U)
                                            : ((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                    >> 0xeU))) 
                                               & (vlTOPp->Core__DOT__INSTRUCTION 
                                                  >> 7U)))));
    vlTOPp->Core__DOT__IMM_EXT = ((0xffffffe1U & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0x1eU & ((((0U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))) 
                                                | (4U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 0xeU))))
                                                ? (vlTOPp->Core__DOT__INSTRUCTION 
                                                   >> 0x15U)
                                                : (
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 0xeU))) 
                                                    | (2U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                           >> 0xeU))))
                                                    ? 
                                                   (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 8U)
                                                    : 0U)) 
                                              << 1U)));
    vlTOPp->Core__DOT__IMM_EXT = ((0xfffff81fU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | ((((((0U == (7U 
                                                 & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                    >> 0xeU))) 
                                         | (1U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                        | (2U == (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU)))) 
                                       | (4U == (7U 
                                                 & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                    >> 0xeU))))
                                       ? (0x3fU & (vlTOPp->Core__DOT__INSTRUCTION 
                                                   >> 0x19U))
                                       : 0U) << 5U));
    vlTOPp->Core__DOT__IMM_EXT = ((0xfffff7ffU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0x800U & ((((0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU))) 
                                                 | (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 0xeU))))
                                                 ? 
                                                (vlTOPp->Core__DOT__INSTRUCTION 
                                                 >> 0x1fU)
                                                 : 
                                                ((2U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))
                                                  ? 
                                                 (vlTOPp->Core__DOT__INSTRUCTION 
                                                  >> 7U)
                                                  : 
                                                 ((3U 
                                                   != 
                                                   (7U 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 0xeU))) 
                                                  & ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 0xeU))) 
                                                     & (vlTOPp->Core__DOT__INSTRUCTION 
                                                        >> 0x14U))))) 
                                               << 0xbU)));
    vlTOPp->Core__DOT__IMM_EXT = ((0xfff00fffU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0xff000U & (((
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 0xeU))) 
                                                    | (1U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                           >> 0xeU)))) 
                                                   | (2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 0xeU))))
                                                   ? 
                                                  VL_NEGATE_I((IData)(
                                                                      (1U 
                                                                       & (vlTOPp->Core__DOT__INSTRUCTION 
                                                                          >> 0x1fU))))
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 0xeU)))
                                                    ? 
                                                   (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0xcU)
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 0xeU)))
                                                     ? 
                                                    (vlTOPp->Core__DOT__INSTRUCTION 
                                                     >> 0xcU)
                                                     : 0U))) 
                                                 << 0xcU)));
    vlTOPp->Core__DOT__IMM_EXT = ((0x800fffffU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0x7ff00000U & 
                                     ((((((0U == (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))) 
                                          | (1U == 
                                             (7U & 
                                              (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                               >> 0xeU)))) 
                                         | (2U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                        | (4U == (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU))))
                                        ? VL_NEGATE_I((IData)(
                                                              (1U 
                                                               & (vlTOPp->Core__DOT__INSTRUCTION 
                                                                  >> 0x1fU))))
                                        : ((3U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))
                                            ? (vlTOPp->Core__DOT__INSTRUCTION 
                                               >> 0x14U)
                                            : 0U)) 
                                      << 0x14U)));
    vlTOPp->Core__DOT__IMM_EXT = ((0x7fffffffU & vlTOPp->Core__DOT__IMM_EXT) 
                                  | (0x80000000U & 
                                     (((((((0U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU))) 
                                           | (1U == 
                                              (7U & 
                                               (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                >> 0xeU)))) 
                                          | (2U == 
                                             (7U & 
                                              (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                               >> 0xeU)))) 
                                         | (3U == (7U 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 0xeU)))) 
                                        | (4U == (7U 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 0xeU)))) 
                                       << 0x1fU) & vlTOPp->Core__DOT__INSTRUCTION)));
    vlTOPp->Core__DOT__JUMP_BRANCH_TARGET = (vlTOPp->Core__DOT__PC 
                                             + vlTOPp->Core__DOT__IMM_EXT);
    vlTOPp->Core__DOT__ALU_IN2 = ((0x20U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                                   ? vlTOPp->Core__DOT__IMM_EXT
                                   : vlTOPp->Core__DOT__SRC2);
    vlTOPp->Core__DOT__PC_sig = ((0x2000U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                                  ? vlTOPp->Core__DOT__JUMP_BRANCH_TARGET
                                  : ((0x1000U & vlTOPp->Core__DOT__Control__DOT__control_sig)
                                      ? (vlTOPp->Core__DOT__SRC1 
                                         + vlTOPp->Core__DOT__IMM_EXT)
                                      : (((vlTOPp->Core__DOT__Control__DOT__control_sig 
                                           >> 0xbU) 
                                          & (((((((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 0xcU))) 
                                                  & (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_equal)) 
                                                 | ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__INSTRUCTION 
                                                         >> 0xcU))) 
                                                    & (~ (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_equal)))) 
                                                | ((4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__INSTRUCTION 
                                                        >> 0xcU))) 
                                                   & (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_signed))) 
                                               | ((5U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->Core__DOT__INSTRUCTION 
                                                       >> 0xcU))) 
                                                  & (~ (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_signed)))) 
                                              | ((6U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->Core__DOT__INSTRUCTION 
                                                      >> 0xcU))) 
                                                 & (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_unsigned))) 
                                             | ((7U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->Core__DOT__INSTRUCTION 
                                                     >> 0xcU))) 
                                                & (~ (IData)(vlTOPp->Core__DOT__BranchLogic__DOT__w_unsigned)))))
                                          ? vlTOPp->Core__DOT__JUMP_BRANCH_TARGET
                                          : ((IData)(4U) 
                                             + vlTOPp->Core__DOT__PC))));
    vlTOPp->Core__DOT__ALUOUT = ((0U == (0xfU & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                 >> 7U)))
                                  ? (vlTOPp->Core__DOT__ALU_IN1 
                                     + vlTOPp->Core__DOT__ALU_IN2)
                                  : ((1U == (0xfU & 
                                             (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                              >> 7U)))
                                      ? (vlTOPp->Core__DOT__ALU_IN1 
                                         - vlTOPp->Core__DOT__ALU_IN2)
                                      : ((2U == (0xfU 
                                                 & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                    >> 7U)))
                                          ? (vlTOPp->Core__DOT__ALU_IN1 
                                             & vlTOPp->Core__DOT__ALU_IN2)
                                          : ((3U == 
                                              (0xfU 
                                               & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                  >> 7U)))
                                              ? (vlTOPp->Core__DOT__ALU_IN1 
                                                 | vlTOPp->Core__DOT__ALU_IN2)
                                              : ((4U 
                                                  == 
                                                  (0xfU 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 7U)))
                                                  ? 
                                                 (vlTOPp->Core__DOT__ALU_IN1 
                                                  ^ vlTOPp->Core__DOT__ALU_IN2)
                                                  : 
                                                 (((5U 
                                                    == 
                                                    (0xfU 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 7U))) 
                                                   & VL_LTS_III(1,32,32, vlTOPp->Core__DOT__ALU_IN1, vlTOPp->Core__DOT__ALU_IN2))
                                                   ? 1U
                                                   : 
                                                  ((6U 
                                                    == 
                                                    (0xfU 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 7U)))
                                                    ? 
                                                   (vlTOPp->Core__DOT__ALU_IN1 
                                                    << 
                                                    (0x1fU 
                                                     & vlTOPp->Core__DOT__ALU_IN2))
                                                    : 
                                                   (((7U 
                                                      == 
                                                      (0xfU 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 7U))) 
                                                     & (vlTOPp->Core__DOT__ALU_IN1 
                                                        < vlTOPp->Core__DOT__ALU_IN2))
                                                     ? 1U
                                                     : 
                                                    ((8U 
                                                      == 
                                                      (0xfU 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 7U)))
                                                      ? 
                                                     (vlTOPp->Core__DOT__ALU_IN1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlTOPp->Core__DOT__ALU_IN2))
                                                      : 
                                                     ((9U 
                                                       == 
                                                       (0xfU 
                                                        & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                           >> 7U)))
                                                       ? 
                                                      (vlTOPp->Core__DOT__ALU_IN1 
                                                       >> 
                                                       (0x1fU 
                                                        & vlTOPp->Core__DOT__ALU_IN2))
                                                       : 
                                                      ((0xaU 
                                                        == 
                                                        (0xfU 
                                                         & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                            >> 7U)))
                                                        ? vlTOPp->Core__DOT__ALU_IN1
                                                        : 
                                                       ((0xbU 
                                                         == 
                                                         (0xfU 
                                                          & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                             >> 7U)))
                                                         ? vlTOPp->Core__DOT__ALU_IN2
                                                         : 0U))))))))))));
    vlTOPp->Core__DOT__DataMemory__DOT__BYTE_WR = (
                                                   (~ 
                                                    ((0x1fU 
                                                      >= 
                                                      (((IData)(3U) 
                                                        - 
                                                        (3U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       << 3U))
                                                      ? 
                                                     (0xff000000U 
                                                      >> 
                                                      (((IData)(3U) 
                                                        - 
                                                        (3U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       << 3U))
                                                      : 0U)) 
                                                   & ((0x1000000U 
                                                       >= 
                                                       (0x1ffffffU 
                                                        & (vlTOPp->Core__DOT__ALUOUT 
                                                           >> 2U)))
                                                       ? 
                                                      vlTOPp->Core__DOT__DataMemory__DOT__D_MEM
                                                      [
                                                      (0x1ffffffU 
                                                       & (vlTOPp->Core__DOT__ALUOUT 
                                                          >> 2U))]
                                                       : 0U));
    vlTOPp->Core__DOT__DataMemory__DOT__HALF_WR = (
                                                   (~ 
                                                    ((0x1fU 
                                                      >= 
                                                      (((IData)(1U) 
                                                        - 
                                                        (1U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       << 4U))
                                                      ? 
                                                     (0xffff0000U 
                                                      >> 
                                                      (((IData)(1U) 
                                                        - 
                                                        (1U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       << 4U))
                                                      : 0U)) 
                                                   & ((0x1000000U 
                                                       >= 
                                                       (0x1ffffffU 
                                                        & (vlTOPp->Core__DOT__ALUOUT 
                                                           >> 2U)))
                                                       ? 
                                                      vlTOPp->Core__DOT__DataMemory__DOT__D_MEM
                                                      [
                                                      (0x1ffffffU 
                                                       & (vlTOPp->Core__DOT__ALUOUT 
                                                          >> 2U))]
                                                       : 0U));
    vlTOPp->PRINT_EN = ((0xe0001030U == (vlTOPp->Core__DOT__ALUOUT 
                                         >> 2U)) & 
                        (vlTOPp->Core__DOT__Control__DOT__control_sig 
                         >> 3U));
    vlTOPp->Core__DOT__DataMemory__DOT__LW = ((0x1000000U 
                                               >= (0x1ffffffU 
                                                   & (vlTOPp->Core__DOT__ALUOUT 
                                                      >> 2U)))
                                               ? vlTOPp->Core__DOT__DataMemory__DOT__D_MEM
                                              [(0x1ffffffU 
                                                & (vlTOPp->Core__DOT__ALUOUT 
                                                   >> 2U))]
                                               : 0U);
    vlTOPp->Core__DOT__DataMemory__DOT__LH = (0xffffU 
                                              & ((1U 
                                                  & ((~ vlTOPp->Core__DOT__ALUOUT) 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 4U)))
                                                  ? 
                                                 (0xffffU 
                                                  & vlTOPp->Core__DOT__DataMemory__DOT__LW)
                                                  : 
                                                 ((1U 
                                                   & (vlTOPp->Core__DOT__ALUOUT 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 4U)))
                                                   ? 
                                                  (0xffffU 
                                                   & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                      >> 0x10U))
                                                   : 0U)));
    vlTOPp->Core__DOT__DataMemory__DOT__LB = (0xffU 
                                              & (((0U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->Core__DOT__ALUOUT)) 
                                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                     >> 4U))
                                                  ? 
                                                 (0xffU 
                                                  & vlTOPp->Core__DOT__DataMemory__DOT__LW)
                                                  : 
                                                 (((1U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->Core__DOT__ALUOUT)) 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 4U))
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                      >> 8U))
                                                   : 
                                                  (((2U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->Core__DOT__ALUOUT)) 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 4U))
                                                    ? 
                                                   (0xffU 
                                                    & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                       >> 0x10U))
                                                    : 
                                                   (((3U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->Core__DOT__ALUOUT)) 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 4U))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                        >> 0x18U))
                                                     : 0U)))));
    vlTOPp->Core__DOT__R_DATA = (((2U == (7U & (vlTOPp->Core__DOT__INSTRUCTION 
                                                >> 0xcU))) 
                                  & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                     >> 4U)) ? vlTOPp->Core__DOT__DataMemory__DOT__LW
                                  : ((((0U == (7U & 
                                               (vlTOPp->Core__DOT__INSTRUCTION 
                                                >> 0xcU))) 
                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                          >> 4U)) & 
                                      VL_LTES_III(1,32,32, 0U, 
                                                  VL_EXTENDS_II(32,8, (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LB))))
                                      ? (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LB)
                                      : ((((0U == (7U 
                                                   & (vlTOPp->Core__DOT__INSTRUCTION 
                                                      >> 0xcU))) 
                                           & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                              >> 4U)) 
                                          & VL_GTS_III(1,32,32, 0U, 
                                                       VL_EXTENDS_II(32,8, (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LB))))
                                          ? ((IData)(0xffffff00U) 
                                             + (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LB))
                                          : ((((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->Core__DOT__INSTRUCTION 
                                                    >> 0xcU))) 
                                               & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                  >> 4U)) 
                                              & VL_LTES_III(1,32,32, 0U, 
                                                            VL_EXTENDS_II(32,16, (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LH))))
                                              ? (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LH)
                                              : (((
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__INSTRUCTION 
                                                        >> 0xcU))) 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 4U)) 
                                                  & VL_GTS_III(1,32,32, 0U, 
                                                               VL_EXTENDS_II(32,16, (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LH))))
                                                  ? 
                                                 ((IData)(0xffff0000U) 
                                                  + (IData)(vlTOPp->Core__DOT__DataMemory__DOT__LH))
                                                  : 
                                                 (((4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->Core__DOT__INSTRUCTION 
                                                        >> 0xcU))) 
                                                   & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                      >> 4U))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->Core__DOT__ALUOUT)) 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 4U))
                                                    ? 
                                                   (0xffU 
                                                    & vlTOPp->Core__DOT__DataMemory__DOT__LW)
                                                    : 
                                                   (((1U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->Core__DOT__ALUOUT)) 
                                                     & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                        >> 4U))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                        >> 8U))
                                                     : 
                                                    (((2U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->Core__DOT__ALUOUT)) 
                                                      & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                         >> 4U))
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                         >> 0x10U))
                                                      : 
                                                     (((3U 
                                                        == 
                                                        (3U 
                                                         & vlTOPp->Core__DOT__ALUOUT)) 
                                                       & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                          >> 4U))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                          >> 0x18U))
                                                       : 0U))))
                                                   : 
                                                  (((5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->Core__DOT__INSTRUCTION 
                                                         >> 0xcU))) 
                                                    & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                       >> 4U))
                                                    ? 
                                                   ((1U 
                                                     & ((~ vlTOPp->Core__DOT__ALUOUT) 
                                                        & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                           >> 4U)))
                                                     ? 
                                                    (0xffffU 
                                                     & vlTOPp->Core__DOT__DataMemory__DOT__LW)
                                                     : 
                                                    ((1U 
                                                      & (vlTOPp->Core__DOT__ALUOUT 
                                                         & (vlTOPp->Core__DOT__Control__DOT__control_sig 
                                                            >> 4U)))
                                                      ? 
                                                     (0xffffU 
                                                      & (vlTOPp->Core__DOT__DataMemory__DOT__LW 
                                                         >> 0x10U))
                                                      : 0U))
                                                    : 0U)))))));
}

void VCore::_eval(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_eval\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VCore::_eval_initial(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_eval_initial\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VCore::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::final\n"); );
    // Variables
    VCore__Syms* __restrict vlSymsp = this->__VlSymsp;
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VCore::_eval_settle(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_eval_settle\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData VCore::_change_request(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_change_request\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCore::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RESET & 0xfeU))) {
        Verilated::overWidthError("RESET");}
}
#endif  // VL_DEBUG

void VCore::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    RESET = VL_RAND_RESET_I(1);
    PRINT_VAL = VL_RAND_RESET_I(32);
    PRINT_EN = VL_RAND_RESET_I(1);
    Core__DOT__INSTRUCTION = VL_RAND_RESET_I(32);
    Core__DOT__JUMP_BRANCH_TARGET = VL_RAND_RESET_I(32);
    Core__DOT__SRC1 = VL_RAND_RESET_I(32);
    Core__DOT__SRC2 = VL_RAND_RESET_I(32);
    Core__DOT__IMM_EXT = VL_RAND_RESET_I(32);
    Core__DOT__PC_sig = VL_RAND_RESET_I(32);
    Core__DOT__ALUOUT = VL_RAND_RESET_I(32);
    Core__DOT__R_DATA = VL_RAND_RESET_I(32);
    Core__DOT__ALU_IN1 = VL_RAND_RESET_I(32);
    Core__DOT__ALU_IN2 = VL_RAND_RESET_I(32);
    Core__DOT__PC = VL_RAND_RESET_I(32);
    Core__DOT__BranchLogic__DOT__w_equal = VL_RAND_RESET_I(1);
    Core__DOT__BranchLogic__DOT__w_signed = VL_RAND_RESET_I(1);
    Core__DOT__BranchLogic__DOT__w_unsigned = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16777217; ++__Vi0) {
            Core__DOT__InstMemory__DOT__I_MEM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Core__DOT__Control__DOT__INS_ARR = VL_RAND_RESET_I(11);
    Core__DOT__Control__DOT__control_sig = VL_RAND_RESET_I(17);
    { int __Vi0=0; for (; __Vi0<31; ++__Vi0) {
            Core__DOT__RegFile__DOT__REG[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Core__DOT__RegFile__DOT____Vlvbound2 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<16777217; ++__Vi0) {
            Core__DOT__DataMemory__DOT__D_MEM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Core__DOT__DataMemory__DOT__LW = VL_RAND_RESET_I(32);
    Core__DOT__DataMemory__DOT__LH = VL_RAND_RESET_I(16);
    Core__DOT__DataMemory__DOT__LB = VL_RAND_RESET_I(8);
    Core__DOT__DataMemory__DOT__BYTE_WR = VL_RAND_RESET_I(32);
    Core__DOT__DataMemory__DOT__HALF_WR = VL_RAND_RESET_I(32);
    Core__DOT__DataMemory__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    Core__DOT__DataMemory__DOT____Vlvbound2 = VL_RAND_RESET_I(32);
    Core__DOT__DataMemory__DOT____Vlvbound3 = VL_RAND_RESET_I(32);
}
