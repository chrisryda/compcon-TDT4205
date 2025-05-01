/*
define i64 @ssa_function(i32 %key, ptr %array, i64 %length) {
    entry:
      br label %loop
    
    loop: ; preds = %13, %1
      %lb = phi i64 [ -1, %entry ], [ %lb.next, %13 ]               // If %entry was exla lb = -1, else %13 exla lb = lb.next 
      %ub = phi i64 [ %length, %entry ], [ %ub.next, %13 ]          // If %entry was exla ub = length, else %13 exla lb = ub.next
      %add.1 = add i64 %lb, %ub                                     // add.1 = lb + ub
      %mid = udiv i64 %add.1, 2                                     // mid = add.1 / 2 (unsigned)
      %elemptr.1 = getelementptr inbounds i32, ptr %array, i64 %mid // elemptr.1 = (address of, i.e.) &array[mid] 
      %elem = load i32, ptr %elemptr.1, align 4                     // elem = array[mid]
      %cmp.1 = icmp slt i32 %elem, %key                             // cmp.1 = (elem < key)
      br i1 %cmp.1, label %10, label %11                            // if cmp.1 --> jump to %10, else jump to %11
    
    10: ; preds = %4
      br label %12                                                  // jump to %12
    
    11: ; preds = %4
      br label %12                                                  // jump to %12
    
    12: ; preds = %11, %10
      %lb.next = phi i64 [ %mid, %10 ], [ %lb, %11 ]                // if %10 exla lb.next = mid, else %11 exla lb.next = lb 
      %ub.next = phi i64 [ %ub, %10 ], [ %mid, %11 ]                // if %10 exla ub.next = ub, else %11 exla ub.next = mid
      br label %13                                                  // jump to %13
    
    13: ; preds = %12
      %add.2 = add i64 %lb.next, 1                                  // add.2 = lb.next + 1
      %cmp.2 = icmp ult i64 %add.2, %ub.next                        // cmp.2 = (add.2 < ub.next)
      br i1 %cmp.2, label %loop, label %exit                        // if cmp.2 --> jump to %loop, else jump to %exit
    
    exit: ; preds = %13
      ret i64 %ub.next                                              // ret ub.next
}
*/

#include <stddef.h>
#include <stdio.h>

size_t c_function(int key, int* array, size_t length) 
{
    size_t lb = -1;
    size_t ub = length;
    size_t add, elem;
    unsigned int mid;
    for (int i = (lb+1); i < ub; i++)
    {
        mid = (lb + ub) / 2;
        elem = array[mid];
        if (elem < key) {
            lb = mid;
        }
        else {
            ub = mid;
        }
    }
    return ub;
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("\n\n\n%d", c_function(4, arr, 10));
    return 0;
}
