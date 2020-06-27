/* f1.c */
#include "f1.h"
void put (T *t, int x) {
  t->a = x; }
int get (T *t) {
    return t->a;
}
void exch (T *t) {
  int x = t->a;
  t->a = t->b;
  t->b = x;
}
