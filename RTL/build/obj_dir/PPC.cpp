// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "PPC.h"
#include "PPC__Syms.h"

//============================================================
// Constructors

PPC::PPC(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new PPC__Syms(_vcontextp__, _vcname__, this)}
    , original_clk{vlSymsp->TOP.original_clk}
    , original_rst{vlSymsp->TOP.original_rst}
    , leds{vlSymsp->TOP.leds}
    , rootp{&(vlSymsp->TOP)}
{
}

PPC::PPC(const char* _vcname__)
    : PPC(nullptr, _vcname__)
{
}

//============================================================
// Destructor

PPC::~PPC() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void PPC___024root___eval_initial(PPC___024root* vlSelf);
void PPC___024root___eval_settle(PPC___024root* vlSelf);
void PPC___024root___eval(PPC___024root* vlSelf);
#ifdef VL_DEBUG
void PPC___024root___eval_debug_assertions(PPC___024root* vlSelf);
#endif  // VL_DEBUG
void PPC___024root___final(PPC___024root* vlSelf);

static void _eval_initial_loop(PPC__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    PPC___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        PPC___024root___eval_settle(&(vlSymsp->TOP));
        PPC___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void PPC::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate PPC::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    PPC___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        PPC___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Invoke final blocks

void PPC::final() {
    PPC___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* PPC::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* PPC::name() const {
    return vlSymsp->name();
}
