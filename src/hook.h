#pragma once
#include "types.h"

// -------------------------
// Minimal hook interface
// -------------------------

// A "hook" replaces a TXT pointer at a given ESR (print/wait function) in RAM
static inline void hook_txt_replacement(s32** txt_ptr_slot, s32* replacement) {
    // replace the pointer in the scenario code array
    *txt_ptr_slot = replacement;
}
