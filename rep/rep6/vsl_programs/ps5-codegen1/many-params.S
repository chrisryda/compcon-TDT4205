.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "Inside main, the arguments are: "
string1: 	.asciz " "
string2: 	.asciz " "
string3: 	.asciz " "
string4: 	.asciz " "
string5: 	.asciz " "
string6: 	.asciz " "
string7: 	.asciz " "
string8: 	.asciz "Sum plus 5: "
string9: 	.asciz "Also sum plus 5: "
string10: 	.asciz "At the end of main, the arguments are: "
string11: 	.asciz " "
string12: 	.asciz " "
string13: 	.asciz " "
string14: 	.asciz " "
string15: 	.asciz " "
string16: 	.asciz " "
string17: 	.asciz " "
string18: 	.asciz "Inside otherFunc, the arguments are: "
string19: 	.asciz " "
string20: 	.asciz " "
string21: 	.asciz " "
string22: 	.asciz " "
string23: 	.asciz " "
string24: 	.asciz " "
string25: 	.asciz " "
.section .bss
.align 8
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	pushq %rsi
	pushq %rdx
	pushq %rcx
	pushq %r8
	pushq %r9
	pushq $0
	pushq $0
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string2(%rip), %rsi
	call safe_printf
	movq -24(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string3(%rip), %rsi
	call safe_printf
	movq -32(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string4(%rip), %rsi
	call safe_printf
	movq -40(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string5(%rip), %rsi
	call safe_printf
	movq -48(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string6(%rip), %rsi
	call safe_printf
	movq 16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string7(%rip), %rsi
	call safe_printf
	movq 24(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $5, %rax
	pushq %rax
	movq 24(%rbp), %rax
	pushq %rax
	movq 16(%rbp), %rax
	pushq %rax
	movq -48(%rbp), %rax
	pushq %rax
	movq -40(%rbp), %rax
	pushq %rax
	movq -32(%rbp), %rax
	pushq %rax
	movq -24(%rbp), %rax
	pushq %rax
	movq -16(%rbp), %rax
	pushq %rax
	movq -8(%rbp), %rax
	pushq %rax
	popq %rdi
	popq %rsi
	popq %rdx
	popq %rcx
	popq %r8
	popq %r9
	call .otherFunc
	addq $16, %rsp
	popq %rcx
	addq %rcx, %rax
	movq %rax, -56(%rbp)
	leaq strout(%rip), %rdi
	leaq string8(%rip), %rsi
	call safe_printf
	movq -56(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq 24(%rbp), %rax
	pushq %rax
	movq 16(%rbp), %rax
	pushq %rax
	movq $2, %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq -48(%rbp), %rax
	pushq %rax
	movq -40(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq -32(%rbp), %rax
	pushq %rax
	movq -24(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq -16(%rbp), %rax
	pushq %rax
	movq -8(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	popq %rdi
	popq %rsi
	popq %rdx
	popq %rcx
	popq %r8
	popq %r9
	call .otherFunc
	addq $16, %rsp
	movq %rax, -64(%rbp)
	leaq strout(%rip), %rdi
	leaq string9(%rip), %rsi
	call safe_printf
	movq -64(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	leaq strout(%rip), %rdi
	leaq string10(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string11(%rip), %rsi
	call safe_printf
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string12(%rip), %rsi
	call safe_printf
	movq -24(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string13(%rip), %rsi
	call safe_printf
	movq -32(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string14(%rip), %rsi
	call safe_printf
	movq -40(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string15(%rip), %rsi
	call safe_printf
	movq -48(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string16(%rip), %rsi
	call safe_printf
	movq 16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string17(%rip), %rsi
	call safe_printf
	movq 24(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $0, %rax
	jmp .main.epilogue
.main.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
.otherFunc:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	pushq %rsi
	pushq %rdx
	pushq %rcx
	pushq %r8
	pushq %r9
	pushq $0
	movq -8(%rbp), %rax
	pushq %rax
	movq -16(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq -24(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq -32(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -56(%rbp)
	leaq strout(%rip), %rdi
	leaq string18(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string19(%rip), %rsi
	call safe_printf
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string20(%rip), %rsi
	call safe_printf
	movq -24(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string21(%rip), %rsi
	call safe_printf
	movq -32(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string22(%rip), %rsi
	call safe_printf
	movq -40(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string23(%rip), %rsi
	call safe_printf
	movq -48(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string24(%rip), %rsi
	call safe_printf
	movq 16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string25(%rip), %rsi
	call safe_printf
	movq 24(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq -56(%rbp), %rax
	pushq %rax
	movq -40(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq -48(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq 16(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq 24(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -56(%rbp)
	movq -56(%rbp), %rax
	jmp .otherFunc.epilogue
.otherFunc.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $1, %rdi
	cmpq $8, %rdi
	jne ABORT
	addq $64, %rsi
	movq %rdi, %rcx
PARSE_ARGV:
	pushq %rsi
	pushq %rcx
	movq (%rsi), %rdi
	movq $0, %rsi
	movq $10, %rdx
	call strtol
	popq %rcx
	popq %rsi
	pushq %rax
	subq $8, %rsi
	loop PARSE_ARGV
	popq %rdi
	popq %rsi
	popq %rdx
	popq %rcx
	popq %r8
	popq %r9
	call .main
	movq %rax, %rdi
	call exit
ABORT:
	leaq errout(%rip), %rdi
	call puts
	movq $1, %rdi
	call exit
safe_printf:
	pushq %rbp
	movq %rsp, %rbp
	andq $-16, %rsp
	call printf
	movq %rbp, %rsp
	popq %rbp
	ret
safe_putchar:
	pushq %rbp
	movq %rsp, %rbp
	andq $-16, %rsp
	call putchar
	movq %rbp, %rsp
	popq %rbp
	ret
.global main
