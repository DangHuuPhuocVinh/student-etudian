#include "f1.h"  
#include "f2.h" 
#include "f4.h"
int main(){
  T u;
  put (&u, 2);
  exch (&u);
  put (&u, 4);
  affi_i(min(get(&u),3));
  
  return 0;
}
