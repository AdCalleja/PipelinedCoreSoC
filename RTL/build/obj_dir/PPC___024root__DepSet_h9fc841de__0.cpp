// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See PPC.h for the primary calling header

#include "verilated.h"

#include "PPC___024root.h"

extern const VlUnpacked<CData/*0:0*/, 2048> PPC__ConstPool__TABLE_hfbf9e803_0;
extern const VlUnpacked<CData/*1:0*/, 2048> PPC__ConstPool__TABLE_ha1704891_0;
extern const VlUnpacked<CData/*2:0*/, 2048> PPC__ConstPool__TABLE_ha99b22a6_0;
extern const VlUnpacked<CData/*0:0*/, 2048> PPC__ConstPool__TABLE_he1b5f03a_0;
extern const VlUnpacked<CData/*0:0*/, 2048> PPC__ConstPool__TABLE_hddf9a7d3_0;
extern const VlUnpacked<CData/*0:0*/, 2048> PPC__ConstPool__TABLE_h2f62ad89_0;
extern const VlUnpacked<CData/*0:0*/, 2048> PPC__ConstPool__TABLE_h5e8fd388_0;
extern const VlUnpacked<CData/*1:0*/, 2048> PPC__ConstPool__TABLE_h19d5dad5_0;
extern const VlUnpacked<CData/*0:0*/, 2048> PPC__ConstPool__TABLE_h251d302e_0;
extern const VlUnpacked<CData/*4:0*/, 2048> PPC__ConstPool__TABLE_h59e31b33_0;

VL_INLINE_OPT void PPC___024root___sequent__TOP__2(PPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    PPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    PPC___024root___sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ALUA;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ALUB;
    CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__ForwardALUA;
    CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__ForwardALUB;
    CData/*4:0*/ PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte0;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte1;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte2;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte3;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half0;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half1;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Word;
    SData/*10:0*/ __Vtableidx1;
    IData/*31:0*/ __Vdly__PPCSoC__DOT__PipelinedCore__DOT__PCtemp;
    // Body
    __Vdly__PPCSoC__DOT__PipelinedCore__DOT__PCtemp 
        = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCtemp;
    if (vlSelf->original_rst) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regImmediate = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regReadData1 = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regReadData2 = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl = 0U;
    } else {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regImmediate 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Immediate;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData2Forw;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regReadData1 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData1;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regReadData2 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData2;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID;
    }
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUSrc 
        = ((~ (IData)(vlSelf->original_rst)) & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUSrcID));
    if (vlSelf->original_rst) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regLuiAuipcSel = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regDataOutput = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regPC = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regWriteDataSrc = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regALUOutput = 0U;
    } else {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regLuiAuipcSel 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LuiAuipcSelID;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regStoreLoadSel;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regDataOutput 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DataOutput;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regPC 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regPC;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regWriteDataSrc 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regWriteDataSrc;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regALUOutput 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput;
    }
    vlSelf->PPCSoC__DOT__io_rdata = ((1U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput)
                                      ? (IData)(vlSelf->PPCSoC__DOT__LEDDriverPPCSoC__DOT__led_state)
                                      : 0U);
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRegWrite 
        = ((~ (IData)(vlSelf->original_rst)) & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRegWrite));
    if (vlSelf->original_rst) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs1 = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs2 = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd = 0U;
        __Vdly__PPCSoC__DOT__PipelinedCore__DOT__PCtemp = 0x800U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regStoreLoadSel = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regPC = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regWriteDataSrc = 0U;
    } else {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs1 
            = (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                        >> 0xfU));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs2 
            = (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                        >> 0x14U));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd;
        if ((1U & (~ ((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemRead) 
                        & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                            == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                         >> 0xfU))) 
                           | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                              == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                           >> 0x14U))))) 
                       | (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DoBranch) 
                           & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRegWrite)) 
                          & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                              == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                           >> 0xfU))) 
                             | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                                == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                             >> 0x14U)))))) 
                      | (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DoBranch) 
                          & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemRead)) 
                         & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                             == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                          >> 0xfU))) 
                            | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                               == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                            >> 0x14U))))))))) {
            __Vdly__PPCSoC__DOT__PipelinedCore__DOT__PCtemp 
                = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCNext;
        }
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regStoreLoadSel 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreLoadSelID;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regPC 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regPC;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regWriteDataSrc 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regWriteDataSrc;
    }
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteData 
        = ((2U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regWriteDataSrc))
            ? ((1U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regWriteDataSrc))
                ? 0U : ((IData)(4U) + vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regPC))
            : ((1U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regWriteDataSrc))
                ? vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regDataOutput
                : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regALUOutput));
    if ((vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
         & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemWrite) 
            & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
               >> 0xdU)))) {
        vlSelf->PPCSoC__DOT__LEDDriverPPCSoC__DOT__led_state 
            = (0xffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreFixed 
                        >> 8U));
    }
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRegWrite 
        = ((~ (IData)(vlSelf->original_rst)) & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRegWrite));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemRead 
        = ((~ (IData)(vlSelf->original_rst)) & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemRead));
    if (vlSelf->original_rst) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regPC = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regWriteDataSrc = 0U;
    } else {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regPC 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regPC;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regWriteDataSrc 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteDataSrcID;
    }
    vlSelf->leds = vlSelf->PPCSoC__DOT__LEDDriverPPCSoC__DOT__led_state;
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemWrite 
        = ((~ (IData)(vlSelf->original_rst)) & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemWrite));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
        = ((IData)(vlSelf->original_rst) ? 0U : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUOutput);
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRegWrite 
        = (1U & ((~ (IData)(vlSelf->original_rst)) 
                 & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Stall)
                     ? 0U : (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegWriteIDtoStall))));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemRead 
        = ((~ (IData)(vlSelf->original_rst)) & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemReadID));
    PPCSoC__DOT__PipelinedCore__DOT__ForwardALUA = 
        (((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRegWrite) 
            & (0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd))) 
           & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
              == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs1))) 
          & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
             == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs1)))
          ? 1U : (((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRegWrite) 
                     & (0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd))) 
                    & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd) 
                       == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs1))) 
                   & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd) 
                      == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs1)))
                   ? 2U : 0U));
    PPCSoC__DOT__PipelinedCore__DOT__ForwardALUB = 
        (((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRegWrite) 
            & (0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd))) 
           & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
              == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs2))) 
          & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
             == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs2)))
          ? 1U : (((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRegWrite) 
                     & (0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd))) 
                    & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd) 
                       == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs2))) 
                   & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd) 
                      == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs2)))
                   ? 2U : 0U));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd 
        = ((IData)(vlSelf->original_rst) ? 0U : (0x1fU 
                                                 & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                    >> 7U)));
    if (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRst) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regPC = 0U;
    } else if (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDWrite) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regPC 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCtemp;
    }
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemWrite 
        = (1U & ((~ (IData)(vlSelf->original_rst)) 
                 & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Stall)
                     ? 0U : (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemWriteIDtoStall))));
    vlSelf->PPCSoC__DOT____Vcellinp__DataMemoryPPC__we 
        = ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemWrite) 
           & (~ (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                 >> 0xdU)));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel 
        = ((0U == (3U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))
            ? ((0U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                ? 1U : ((1U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                         ? 2U : ((2U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                                  ? 4U : ((3U == (3U 
                                                  & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                                           ? 8U : 0U))))
            : ((1U == (3U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))
                ? ((0U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                    ? 3U : ((2U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                             ? 0xcU : 0U)) : ((2U == 
                                               (3U 
                                                & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))
                                               ? 0xfU
                                               : 0U)));
    PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte0 
        = (0xffU & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw);
    PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte1 
        = (0xff00U & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw 
                      << 8U));
    PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte2 
        = (0xff0000U & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw 
                        << 0x10U));
    PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte3 
        = (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw 
           << 0x18U);
    PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half0 
        = (0xffffU & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw);
    PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half1 
        = (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw 
           << 0x10U);
    PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Word 
        = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw;
    if ((0U == (3U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte 
            = ((0U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                ? PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte0
                : ((1U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                    ? PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte1
                    : ((2U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                        ? PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte2
                        : ((3U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                            ? PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte3
                            : 0U))));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreFixed 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte;
    } else if ((1U == (3U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half 
            = ((0U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                ? PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half0
                : ((2U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                    ? PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half1
                    : 0U));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreFixed 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half;
    } else {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreFixed 
            = ((2U == (3U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))
                ? PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Word
                : 0U);
    }
    PPCSoC__DOT__PipelinedCore__DOT__ALUA = ((2U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regLuiAuipcSel))
                                              ? ((1U 
                                                  & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regLuiAuipcSel))
                                                  ? 0U
                                                  : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regPC)
                                              : ((1U 
                                                  & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regLuiAuipcSel))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & (IData)(PPCSoC__DOT__PipelinedCore__DOT__ForwardALUA))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(PPCSoC__DOT__PipelinedCore__DOT__ForwardALUA))
                                                    ? 0U
                                                    : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteData)
                                                   : 
                                                  ((1U 
                                                    & (IData)(PPCSoC__DOT__PipelinedCore__DOT__ForwardALUA))
                                                    ? vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput
                                                    : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regReadData1))));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData2Forw 
        = ((2U & (IData)(PPCSoC__DOT__PipelinedCore__DOT__ForwardALUB))
            ? ((1U & (IData)(PPCSoC__DOT__PipelinedCore__DOT__ForwardALUB))
                ? 0U : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteData)
            : ((1U & (IData)(PPCSoC__DOT__PipelinedCore__DOT__ForwardALUB))
                ? vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput
                : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regReadData2));
    if (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRst) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction = 0U;
    } else if (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDWrite) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__TextMemoryPPC__DOT__rom
            [(0xfffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCtemp 
                        >> 2U))];
    }
    PPCSoC__DOT__PipelinedCore__DOT__ALUB = ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUSrc)
                                              ? vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regImmediate
                                              : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData2Forw);
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCtemp 
        = __Vdly__PPCSoC__DOT__PipelinedCore__DOT__PCtemp;
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUOutput 
        = (((((((((0U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl)) 
                  | (1U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))) 
                 | (2U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))) 
                | (3U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))) 
               | (4U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))) 
              | (5U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))) 
             | (6U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))) 
            | (7U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl)))
            ? ((0U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                ? (PPCSoC__DOT__PipelinedCore__DOT__ALUA 
                   + PPCSoC__DOT__PipelinedCore__DOT__ALUB)
                : ((1U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                    ? (PPCSoC__DOT__PipelinedCore__DOT__ALUA 
                       - PPCSoC__DOT__PipelinedCore__DOT__ALUB)
                    : ((2U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                        ? (PPCSoC__DOT__PipelinedCore__DOT__ALUA 
                           << (0x1fU & PPCSoC__DOT__PipelinedCore__DOT__ALUB))
                        : ((3U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                            ? (VL_LTS_III(1,32,32, PPCSoC__DOT__PipelinedCore__DOT__ALUA, PPCSoC__DOT__PipelinedCore__DOT__ALUB)
                                ? 1U : 0U) : ((4U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                                               ? ((PPCSoC__DOT__PipelinedCore__DOT__ALUA 
                                                   < PPCSoC__DOT__PipelinedCore__DOT__ALUB)
                                                   ? 1U
                                                   : 0U)
                                               : ((5U 
                                                   == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                                                   ? 
                                                  (PPCSoC__DOT__PipelinedCore__DOT__ALUA 
                                                   ^ PPCSoC__DOT__PipelinedCore__DOT__ALUB)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                                                    ? 
                                                   (PPCSoC__DOT__PipelinedCore__DOT__ALUA 
                                                    >> 
                                                    (0x1fU 
                                                     & PPCSoC__DOT__PipelinedCore__DOT__ALUB))
                                                    : 
                                                   VL_SHIFTRS_III(32,32,5, PPCSoC__DOT__PipelinedCore__DOT__ALUA, 
                                                                  (0x1fU 
                                                                   & PPCSoC__DOT__PipelinedCore__DOT__ALUB)))))))))
            : ((8U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                ? (PPCSoC__DOT__PipelinedCore__DOT__ALUA 
                   | PPCSoC__DOT__PipelinedCore__DOT__ALUB)
                : ((9U == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl))
                    ? (PPCSoC__DOT__PipelinedCore__DOT__ALUA 
                       & PPCSoC__DOT__PipelinedCore__DOT__ALUB)
                    : 0U)));
    PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode 
        = (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                    >> 2U));
    if ((8U == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Simm 
            = (((- (IData)((vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                            >> 0x1fU))) << 0xbU) | 
               ((0x7e0U & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                           >> 0x14U)) | (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                  >> 7U))));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Immediate 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Simm;
    } else if ((0x18U == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Bimm 
            = (((- (IData)((vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                            >> 0x1fU))) << 0xcU) | 
               ((0x800U & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                           << 4U)) | ((0x7e0U & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                 >> 0x14U)) 
                                      | (0x1eU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                  >> 7U)))));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Immediate 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Bimm;
    } else if (((5U == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode)) 
                | (0xdU == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode)))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Uimm 
            = (0xfffff000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction);
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Immediate 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Uimm;
    } else if ((0x1bU == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Jimm 
            = (((- (IData)((vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                            >> 0x1fU))) << 0x14U) | 
               ((0xff000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction) 
                | ((0x800U & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                              >> 9U)) | (0x7feU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                   >> 0x14U)))));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Immediate 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Jimm;
    } else if ((((((0U == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode)) 
                   | (3U == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode))) 
                  | (4U == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode))) 
                 | (0x19U == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode))) 
                | (0x1cU == (IData)(PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Opcode)))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Iimm 
            = (((- (IData)((vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                            >> 0x1fU))) << 0xcU) | 
               (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                >> 0x14U));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Immediate 
            = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Iimm;
    } else {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Immediate = 0U;
    }
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchA 
        = (((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRegWrite) 
              & (0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd))) 
             & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                             >> 0xfU)))) & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                                            == (0x1fU 
                                                & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                   >> 0xfU))))
            ? 1U : (((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRegWrite) 
                       & (0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd))) 
                      & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd) 
                         == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                      >> 0xfU)))) & 
                     ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd) 
                      == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                   >> 0xfU)))) ? 2U
                     : 0U));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchB 
        = (((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRegWrite) 
              & (0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd))) 
             & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                             >> 0x14U)))) & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                                             == (0x1fU 
                                                 & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                    >> 0x14U))))
            ? 1U : (((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRegWrite) 
                       & (0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd))) 
                      & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd) 
                         == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                      >> 0x14U)))) 
                     & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd) 
                        == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                     >> 0x14U)))) ? 2U
                     : 0U));
    __Vtableidx1 = ((0x400U & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                               >> 0x14U)) | ((0x380U 
                                              & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                 >> 5U)) 
                                             | (0x7fU 
                                                & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction)));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegWriteIDtoStall 
        = PPC__ConstPool__TABLE_hfbf9e803_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteDataSrcID 
        = PPC__ConstPool__TABLE_ha1704891_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreLoadSelID 
        = PPC__ConstPool__TABLE_ha99b22a6_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemWriteIDtoStall 
        = PPC__ConstPool__TABLE_he1b5f03a_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemReadID 
        = PPC__ConstPool__TABLE_hddf9a7d3_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUSrcID 
        = PPC__ConstPool__TABLE_h2f62ad89_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCJumpSrc 
        = PPC__ConstPool__TABLE_h5e8fd388_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LuiAuipcSelID 
        = PPC__ConstPool__TABLE_h19d5dad5_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DoBranch 
        = PPC__ConstPool__TABLE_h251d302e_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID 
        = PPC__ConstPool__TABLE_h59e31b33_0[__Vtableidx1];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDWrite 
        = (1U & (~ ((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemRead) 
                      & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                          == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                       >> 0xfU))) | 
                         ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                          == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                       >> 0x14U))))) 
                     | (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DoBranch) 
                         & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRegWrite)) 
                        & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                            == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                         >> 0xfU))) 
                           | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                              == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                           >> 0x14U)))))) 
                    | (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DoBranch) 
                        & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemRead)) 
                       & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                           == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                        >> 0xfU))) 
                          | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                             == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                          >> 0x14U))))))));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Stall 
        = ((((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemRead) 
             & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                 == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                              >> 0xfU))) | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                                            == (0x1fU 
                                                & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                   >> 0x14U))))) 
            | (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DoBranch) 
                & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRegWrite)) 
               & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                   == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                >> 0xfU))) | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd) 
                                              == (0x1fU 
                                                  & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                     >> 0x14U)))))) 
           | (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DoBranch) 
               & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemRead)) 
              & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                  == (0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                               >> 0xfU))) | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd) 
                                             == (0x1fU 
                                                 & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                                                    >> 0x14U))))));
}

VL_INLINE_OPT void PPC___024root___sequent__TOP__3(PPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    PPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    PPC___024root___sequent__TOP__3\n"); );
    // Init
    SData/*10:0*/ __Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0;
    SData/*10:0*/ __Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0;
    SData/*10:0*/ __Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0;
    SData/*10:0*/ __Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v0;
    CData/*4:0*/ __Vdlyvdim0__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32;
    IData/*31:0*/ __Vdlyvval__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32;
    CData/*0:0*/ __Vdlyvset__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32;
    // Body
    __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0 = 0U;
    __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0 = 0U;
    __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0 = 0U;
    __Vdlyvset__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v0 = 0U;
    __Vdlyvset__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32 = 0U;
    if (((IData)(vlSelf->PPCSoC__DOT____Vcellinp__DataMemoryPPC__we) 
         & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel) 
            >> 3U))) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT____Vlvbound_h0c9a6012__0 
            = (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreFixed 
               >> 0x18U);
        if ((0x400U >= (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                                  >> 2U)))) {
            __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0 
                = vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT____Vlvbound_h0c9a6012__0;
            __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0 = 1U;
            __Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0 
                = (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                             >> 2U));
        }
    }
    if (((IData)(vlSelf->PPCSoC__DOT____Vcellinp__DataMemoryPPC__we) 
         & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel) 
            >> 2U))) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT____Vlvbound_h0c9a6012__0 
            = (0xffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreFixed 
                        >> 0x10U));
        if ((0x400U >= (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                                  >> 2U)))) {
            __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0 
                = vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT____Vlvbound_h0c9a6012__0;
            __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0 = 1U;
            __Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0 
                = (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                             >> 2U));
        }
    }
    if (((IData)(vlSelf->PPCSoC__DOT____Vcellinp__DataMemoryPPC__we) 
         & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel) 
            >> 1U))) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT____Vlvbound_h0c9a6012__0 
            = (0xffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreFixed 
                        >> 8U));
        if ((0x400U >= (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                                  >> 2U)))) {
            __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0 
                = vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT____Vlvbound_h0c9a6012__0;
            __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0 = 1U;
            __Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0 
                = (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                             >> 2U));
        }
    }
    if (((IData)(vlSelf->PPCSoC__DOT____Vcellinp__DataMemoryPPC__we) 
         & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel))) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT____Vlvbound_h0c9a6012__0 
            = (0xffU & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__StoreFixed);
        if ((0x400U >= (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                                  >> 2U)))) {
            __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0 
                = vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT____Vlvbound_h0c9a6012__0;
            __Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0 = 1U;
            __Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0 
                = (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                             >> 2U));
        }
    }
    if ((8U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel))) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram3__DOUT 
            = ((0x400U >= (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                                     >> 2U))) ? vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem
               [(0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                           >> 2U))] : 0U);
    }
    if ((4U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel))) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram2__DOUT 
            = ((0x400U >= (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                                     >> 2U))) ? vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem
               [(0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                           >> 2U))] : 0U);
    }
    if ((2U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel))) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram1__DOUT 
            = ((0x400U >= (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                                     >> 2U))) ? vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem
               [(0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                           >> 2U))] : 0U);
    }
    if ((1U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel))) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram0__DOUT 
            = ((0x400U >= (0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                                     >> 2U))) ? vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem
               [(0x7ffU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput 
                           >> 2U))] : 0U);
    }
    if (vlSelf->original_rst) {
        __Vdlyvset__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v0 = 1U;
    } else if (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRegWrite) {
        if ((0U != (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd))) {
            __Vdlyvval__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32 
                = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteData;
            __Vdlyvset__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32 = 1U;
            __Vdlyvdim0__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32 
                = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd;
        }
    }
    if (__Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem[__Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0] 
            = __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem__v0;
    }
    if (__Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem[__Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0] 
            = __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem__v0;
    }
    if (__Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem[__Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0] 
            = __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0) {
        vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem[__Vdlyvdim0__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0] 
            = __Vdlyvval__PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem__v0;
    }
    if (__Vdlyvset__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v0) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[1U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[2U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[3U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[4U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[5U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[6U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[7U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[8U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[9U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0xaU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0xbU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0xcU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0xdU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0xeU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0xfU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x10U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x11U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x12U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x13U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x14U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x15U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x16U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x17U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x18U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x19U] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x1aU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x1bU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x1cU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x1dU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x1eU] = 0U;
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[0x1fU] = 0U;
    }
    if (__Vdlyvset__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank[__Vdlyvdim0__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32] 
            = __Vdlyvval__PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank__v32;
    }
    vlSelf->PPCSoC__DOT__ram_rdata = (((IData)(vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram3__DOUT) 
                                       << 0x18U) | 
                                      (((IData)(vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram2__DOUT) 
                                        << 0x10U) | 
                                       (((IData)(vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram1__DOUT) 
                                         << 8U) | (IData)(vlSelf->PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram0__DOUT))));
}

VL_INLINE_OPT void PPC___024root___multiclk__TOP__5(PPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    PPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    PPC___024root___multiclk__TOP__5\n"); );
    // Init
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__BranchA;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__BranchB;
    CData/*7:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte0;
    CData/*7:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte1;
    CData/*7:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte2;
    CData/*7:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte3;
    SData/*15:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half0;
    SData/*15:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half1;
    IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Word;
    // Body
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData2 
        = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank
        [(0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                   >> 0x14U))];
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData1 
        = vlSelf->PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank
        [(0x1fU & (vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction 
                   >> 0xfU))];
    PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte0 
        = (0xffU & ((0x2000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput)
                     ? vlSelf->PPCSoC__DOT__io_rdata
                     : vlSelf->PPCSoC__DOT__ram_rdata));
    PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte1 
        = (0xffU & (((0x2000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput)
                      ? vlSelf->PPCSoC__DOT__io_rdata
                      : vlSelf->PPCSoC__DOT__ram_rdata) 
                    >> 8U));
    PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte2 
        = (0xffU & (((0x2000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput)
                      ? vlSelf->PPCSoC__DOT__io_rdata
                      : vlSelf->PPCSoC__DOT__ram_rdata) 
                    >> 0x10U));
    PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte3 
        = (((0x2000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput)
             ? vlSelf->PPCSoC__DOT__io_rdata : vlSelf->PPCSoC__DOT__ram_rdata) 
           >> 0x18U);
    PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half0 
        = (0xffffU & ((0x2000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput)
                       ? vlSelf->PPCSoC__DOT__io_rdata
                       : vlSelf->PPCSoC__DOT__ram_rdata));
    PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half1 
        = (((0x2000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput)
             ? vlSelf->PPCSoC__DOT__io_rdata : vlSelf->PPCSoC__DOT__ram_rdata) 
           >> 0x10U);
    PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Word 
        = ((0x2000U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput)
            ? vlSelf->PPCSoC__DOT__io_rdata : vlSelf->PPCSoC__DOT__ram_rdata);
    if ((0U == (3U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte 
            = ((0U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                ? (IData)(PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte0)
                : ((1U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                    ? (IData)(PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte1)
                    : ((2U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                        ? (IData)(PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte2)
                        : ((3U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                            ? (IData)(PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte3)
                            : 0U))));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DataOutput 
            = ((4U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel))
                ? (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte)
                : (((- (IData)((1U & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte) 
                                      >> 7U)))) << 8U) 
                   | (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte)));
    } else if ((1U == (3U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))) {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half 
            = ((0U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                ? (IData)(PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half0)
                : ((2U == (3U & vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput))
                    ? (IData)(PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half1)
                    : 0U));
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DataOutput 
            = ((4U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel))
                ? (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half)
                : (((- (IData)((1U & ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half) 
                                      >> 0xfU)))) << 0x10U) 
                   | (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half)));
    } else {
        vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DataOutput 
            = ((2U == (3U & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel)))
                ? PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Word
                : 0U);
    }
    PPCSoC__DOT__PipelinedCore__DOT__BranchB = ((2U 
                                                 & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchB))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchB))
                                                  ? 0U
                                                  : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteData)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchB))
                                                  ? vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput
                                                  : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData2));
    PPCSoC__DOT__PipelinedCore__DOT__BranchA = ((2U 
                                                 & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchA))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchA))
                                                  ? 0U
                                                  : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteData)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchA))
                                                  ? vlSelf->PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput
                                                  : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData1));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCSrc 
        = (1U & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__WriteDataSrcID) 
                  >> 1U) | (((0x1aU == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID))
                              ? (PPCSoC__DOT__PipelinedCore__DOT__BranchA 
                                 == PPCSoC__DOT__PipelinedCore__DOT__BranchB)
                              : ((0x1bU == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID))
                                  ? (PPCSoC__DOT__PipelinedCore__DOT__BranchA 
                                     != PPCSoC__DOT__PipelinedCore__DOT__BranchB)
                                  : ((0x1cU == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID))
                                      ? VL_LTS_III(1,32,32, PPCSoC__DOT__PipelinedCore__DOT__BranchA, PPCSoC__DOT__PipelinedCore__DOT__BranchB)
                                      : ((0x1dU == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID))
                                          ? VL_GTES_III(1,32,32, PPCSoC__DOT__PipelinedCore__DOT__BranchA, PPCSoC__DOT__PipelinedCore__DOT__BranchB)
                                          : ((0x1eU 
                                              == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID))
                                              ? (PPCSoC__DOT__PipelinedCore__DOT__BranchA 
                                                 < PPCSoC__DOT__PipelinedCore__DOT__BranchB)
                                              : ((0x1fU 
                                                  == (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID)) 
                                                 & (PPCSoC__DOT__PipelinedCore__DOT__BranchA 
                                                    >= PPCSoC__DOT__PipelinedCore__DOT__BranchB))))))) 
                            & (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__DoBranch))));
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCNext 
        = ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCSrc)
            ? (0xfffffffeU & (((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCJumpSrc)
                                ? vlSelf->PPCSoC__DOT__PipelinedCore__DOT__ReadData1
                                : vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regPC) 
                              + vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Immediate))
            : ((IData)(4U) + vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCtemp));
}

VL_INLINE_OPT void PPC___024root___combo__TOP__6(PPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    PPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    PPC___024root___combo__TOP__6\n"); );
    // Body
    vlSelf->PPCSoC__DOT__PipelinedCore__DOT__IFIDRst 
        = (1U & ((IData)(vlSelf->original_rst) | ((IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__Stall)
                                                   ? 0U
                                                   : (IData)(vlSelf->PPCSoC__DOT__PipelinedCore__DOT__PCSrc))));
}

void PPC___024root___eval(PPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    PPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    PPC___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->original_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__original_clk)))) {
        PPC___024root___sequent__TOP__2(vlSelf);
    }
    if (((~ (IData)(vlSelf->original_clk)) & (IData)(vlSelf->__Vclklast__TOP__original_clk))) {
        PPC___024root___sequent__TOP__3(vlSelf);
    }
    if (((IData)(vlSelf->original_clk) ^ (IData)(vlSelf->__Vclklast__TOP__original_clk))) {
        PPC___024root___multiclk__TOP__5(vlSelf);
    }
    PPC___024root___combo__TOP__6(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__original_clk = vlSelf->original_clk;
}

#ifdef VL_DEBUG
void PPC___024root___eval_debug_assertions(PPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    PPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    PPC___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->original_clk & 0xfeU))) {
        Verilated::overWidthError("original_clk");}
    if (VL_UNLIKELY((vlSelf->original_rst & 0xfeU))) {
        Verilated::overWidthError("original_rst");}
}
#endif  // VL_DEBUG
