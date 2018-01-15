#ifndef RESTRICTR_RESTRICTR_H
#define RESTRICTR_RESTRICTR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Rinternals.h>

SEXP create_restrictr();
SEXP destroy_restrictr(SEXP restrictr);

#ifdef __cplusplus
}
#endif

#endif //RESTRICTR_RESTRICTR_H
