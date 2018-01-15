#ifdef __cplusplus
extern "C" {
#endif
#include <R.h>
#define USE_RINTERNALS
#include <Rinternals.h>
#undef TRUE
#undef FALSE
#undef length
#undef eval
#undef error

#include <config.h>
#include <stdint.h>
#define HAVE_DECL_SIZE_MAX 1
#define R_USE_SIGNALS 1
#include <Defn.h>
#include <Rdyntrace.h>

#include <Rinterface.h>
#include <Internal.h>

#ifdef __cplusplus
}
#endif

#include "restrictr.h"
#include <iostream>
#include <Rdyntrace.h>


extern "C" {

SEXP forcePromise(SEXP); // The one from eval.c

void promise_created(dyntrace_context_t *context, const SEXP promise, const SEXP environment) {
    forcePromise(promise);
}

void begin(dyntrace_context_t *context, const SEXP promise) {
    dyntrace_check_reentrancy = 0;
}

void end(dyntrace_context_t *context) {
    dyntrace_check_reentrancy = 1;
}

SEXP create_restrictr() {
    try {
        /* calloc initializes the memory to zero. This ensures that probes not
           attached will be NULL. Replacing calloc with malloc will cause
           segfaults. */
        dyntracer_t *dyntracer = (dyntracer_t *) calloc(1, sizeof(dyntracer_t));
        dyntracer->probe_promise_created = promise_created;
        dyntracer->probe_begin = begin;
        dyntracer->probe_end = end;
        return dyntracer_to_sexp(dyntracer, "dyntracer.restrtictor");
    } catch (const std::runtime_error &e) {
        Rf_error(e.what());
        return R_NilValue;
    }
}

static void destroy_promise_restrictr(dyntracer_t *restrictr) {
    /* free dyntracer iff it has not already been freed.
       this check ensures that multiple calls to destroy_dyntracer on the same
       object do not crash the process. */
    if (restrictr) {
        // delete (static_cast<Context *>(dyntracer->context)); // nothing there though
        free(restrictr);
    }
}

SEXP destroy_restrictr(SEXP restrictr) {
    return dyntracer_destroy_sexp(restrictr, destroy_promise_restrictr);
}

} // extern "C"
