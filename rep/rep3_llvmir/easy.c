/*
define i32 @ssa_function(i32 %a) {
    1:
      %cmp.0 = icmp slt i32 %a, 0                               // if a < 0       --> cmp.0 = 1
      br i1 %cmp.0, label %ifTrue, label %ifFalse               // if cmp.0 == 1  --> jump to %ifTrue 
    
    ifTrue: ; preds = %1
      %sub.0 = sub nsw i32 0, %a                                // sub.0 = 0 - a
      br label %ifEnd
    
    ifFalse: ; preds = %1
      br label %ifEnd
    
    ifEnd: ; preds = %ifTrue, %ifFalse
      %phi.0 = phi i32 [ %sub.0, %ifTrue ], [ %a, %ifFalse ]    // if %ifTrue was executed last, phi.0 = sub.0,
      ret i32 %phi.0                                            // but if %ifFalse was executed last, phi.0 = a
}
*/


int abs(int a)
{
    if (a < 0 ) 
    { 
        return -a; 
    }
    else 
    { 
        return a; 
    }
}

int main() {
    return 0;
}
