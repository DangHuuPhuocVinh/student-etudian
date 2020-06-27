/* f3.c */
#include "f2.h"
#include "f3.h"
void affi_t (T *t) {
    affi_i (get (t));
    exch (t);
    affi_i (get (t));
    exch (t);
}
