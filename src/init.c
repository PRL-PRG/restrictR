#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>
#include "restrictr.h"

static const R_CallMethodDef CallEntries[] = {
    {"create_restrictr", (DL_FUNC) &create_restrictr, 0},
    {"destroy_restrictr", (DL_FUNC) &destroy_restrictr, 1},
    {NULL, NULL, 0}
};

void attribute_visible R_init_restrictr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
    R_forceSymbols(dll, TRUE);
}
