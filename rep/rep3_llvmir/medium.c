/*
define i32 @ssa_function(i32 %a) {
    1:
      br label %2
    
    2: ; preds = %7, %1
      %i = phi i32 [ 0, %1 ], [ %i.next, %7 ]       //  if %1 was executed last, i = 0 else %7 ex last i = i.next
      %x = phi i32 [ 0, %1 ], [ %x.next, %7 ]       //  if %1 was executed last, x = 0 else %7 ex last x = x.next
      %3 = icmp slt i32 %i, %a                      // r3 = (i < a) 
      br i1 %3, label %4, label %9                  // if (r3) --> jump to %4, else jump to %9
    
    4: ; preds = %2
      %5 = mul nsw i32 %i, %i                       // r5 = i*i
      %x.next = add nsw i32 %x, %5                  // x.next = x + r5
      br label %7                                   // jump to %7
    
    7: ; preds = %4
      %i.next = add nsw i32 %i, 1                   // i.next = i + 1
      br label %2                                   // jump to % 2
    
    9: ; preds = %2
      ret i32 %x
}
*/
#include <stdio.h>

int c_function(int a)
{
    int r5, x_next;
    int x = 0;

    for (int i = 0; i < a; i++) 
    {
        r5 = i*i;
        x += r5;
        printf("i: %d, x: %d\n", i, x);
    }
    return x;
}

int main() {
    c_function(10);
    return 0;
}
