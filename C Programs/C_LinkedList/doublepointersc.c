#include <stdio.h>

void foo(int** p) {
      *p = 0;  /* set pointer to null */
 }
 void foo2(int* p) {
      p = 0;  /* makes copy of p and copy is set to null*/
 }

 int main() {
     int* k;
     foo2(k);   /* k unchanged */
     foo(&k);   /* NOW k == 0 */
 }
