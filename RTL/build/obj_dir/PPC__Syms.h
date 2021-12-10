// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_PPC__SYMS_H_
#define VERILATED_PPC__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "PPC.h"

// INCLUDE MODULE CLASSES
#include "PPC___024root.h"

// SYMS CLASS (contains all model state)
class PPC__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    PPC* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    PPC___024root                  TOP;

    // CONSTRUCTORS
    PPC__Syms(VerilatedContext* contextp, const char* namep, PPC* modelp);
    ~PPC__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
