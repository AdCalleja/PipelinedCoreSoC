// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See PPC.h for the primary calling header

#include "verilated.h"

#include "PPC__Syms.h"
#include "PPC___024root.h"

void PPC___024root___ctor_var_reset(PPC___024root* vlSelf);

PPC___024root::PPC___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    PPC___024root___ctor_var_reset(this);
}

void PPC___024root::__Vconfigure(PPC__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

PPC___024root::~PPC___024root() {
}
