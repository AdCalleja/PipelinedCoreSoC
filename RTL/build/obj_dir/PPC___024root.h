// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See PPC.h for the primary calling header

#ifndef VERILATED_PPC___024ROOT_H_
#define VERILATED_PPC___024ROOT_H_  // guard

#include "verilated.h"

class PPC__Syms;
VL_MODULE(PPC___024root) {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(original_clk,0,0);
        VL_IN8(original_rst,0,0);
        VL_OUT8(leds,7,0);
        CData/*0:0*/ PPCSoC__DOT____Vcellinp__DataMemoryPPC__we;
        CData/*7:0*/ PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram0__DOUT;
        CData/*7:0*/ PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram1__DOUT;
        CData/*7:0*/ PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram2__DOUT;
        CData/*7:0*/ PPCSoC__DOT__DataMemoryPPC__DOT____Vcellout__ram3__DOUT;
        CData/*7:0*/ PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT____Vlvbound_h0c9a6012__0;
        CData/*7:0*/ PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT____Vlvbound_h0c9a6012__0;
        CData/*7:0*/ PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT____Vlvbound_h0c9a6012__0;
        CData/*7:0*/ PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT____Vlvbound_h0c9a6012__0;
        CData/*7:0*/ PPCSoC__DOT__LEDDriverPPCSoC__DOT__led_state;
        CData/*3:0*/ PPCSoC__DOT__PipelinedCore__DOT__MemoryByteSel;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__PCSrc;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__IFIDWrite;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__IFIDRst;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__Stall;
        CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchA;
        CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__ForwardBranchB;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__RegWriteIDtoStall;
        CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__WriteDataSrcID;
        CData/*2:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLoadSelID;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__MemWriteIDtoStall;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__MemReadID;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__ALUSrcID;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__PCJumpSrc;
        CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__LuiAuipcSelID;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__DoBranch;
        CData/*4:0*/ PPCSoC__DOT__PipelinedCore__DOT__ALUCtrlID;
        CData/*4:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRd;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRegWrite;
        CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regWriteDataSrc;
        CData/*2:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regStoreLoadSel;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemWrite;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regMemRead;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUSrc;
        CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regLuiAuipcSel;
        CData/*4:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regALUCtrl;
        CData/*4:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs1;
        CData/*4:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regRs2;
        CData/*4:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRd;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regRegWrite;
        CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regWriteDataSrc;
        CData/*2:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regStoreLoadSel;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemWrite;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regMemRead;
        CData/*7:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Byte;
        CData/*4:0*/ PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRd;
        CData/*0:0*/ PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regRegWrite;
        CData/*1:0*/ PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regWriteDataSrc;
        CData/*0:0*/ __Vclklast__TOP__original_clk;
        SData/*15:0*/ PPCSoC__DOT__PipelinedCore__DOT__LoadLogicPPC__DOT__Half;
        IData/*31:0*/ PPCSoC__DOT__io_rdata;
        IData/*31:0*/ PPCSoC__DOT__ram_rdata;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__PCNext;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ReadData1;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ReadData2;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__Immediate;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ReadData2Forw;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ALUOutput;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreFixed;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__DataOutput;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__WriteData;
    };
    struct {
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__PCtemp;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regPC;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__IFIDRegsPPC__DOT__regInstruction;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Simm;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Bimm;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Uimm;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Jimm;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__ImmGenPPC__DOT__Iimm;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regPC;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regReadData1;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regReadData2;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__IDEXRegsPPC__DOT__regImmediate;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regPC;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regALUOutput;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__EXMEMRegsPPC__DOT__regReadData2Forw;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Byte;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__StoreLogicPPC__DOT__Half;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regPC;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regALUOutput;
        IData/*31:0*/ PPCSoC__DOT__PipelinedCore__DOT__MEMWBRegsPPC__DOT__regDataOutput;
        VlUnpacked<CData/*7:0*/, 1025> PPCSoC__DOT__DataMemoryPPC__DOT__ram0__DOT__mem;
        VlUnpacked<CData/*7:0*/, 1025> PPCSoC__DOT__DataMemoryPPC__DOT__ram1__DOT__mem;
        VlUnpacked<CData/*7:0*/, 1025> PPCSoC__DOT__DataMemoryPPC__DOT__ram2__DOT__mem;
        VlUnpacked<CData/*7:0*/, 1025> PPCSoC__DOT__DataMemoryPPC__DOT__ram3__DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> PPCSoC__DOT__PipelinedCore__DOT__TextMemoryPPC__DOT__rom;
        VlUnpacked<IData/*31:0*/, 32> PPCSoC__DOT__PipelinedCore__DOT__RegisterFilePPC__DOT__bank;
    };

    // INTERNAL VARIABLES
    PPC__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    PPC___024root(const char* name);
    ~PPC___024root();
    VL_UNCOPYABLE(PPC___024root);

    // INTERNAL METHODS
    void __Vconfigure(PPC__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
