;  Task 1.3: Correct LLVM IR 

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @my_factorial(i32 noundef %param) #0 {
    1:
    %iszerocmp = icmp eq i32 %param, 0
    
    br i1 %iszerocmp, label %5, label %2
    
    2:
    %islessthanzerocmp = icmp slt i32 %param, 0
    
    br i1 %islessthanzerocmp, label %5, label %3
    
    3:
    %.01 = phi i32 [ %inc, %4 ], [ 1, %2 ]
    
    %.0 = phi i32 [ %mul_result, %4 ], [ 1, %2 ]
    
    %continue = icmp sle i32 %.01, %param
    
    br i1 %continue, label %4, label %5
    
    4:
    %mul_result = mul nsw i32 %.0, %.01
    
    %inc = add nsw i32 %.01, 1
    
    br label %3
    
    5:
    %.2 = phi i32 [ -1, %1 ], [ -2, %2 ], [ %.0, %3 ]
    
    ret i32 %.2
}
