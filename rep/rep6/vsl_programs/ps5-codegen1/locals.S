.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "Now, a b c are "
string1: 	.asciz " "
string2: 	.asciz " "
string3: 	.asciz "In here, a b c are "
string4: 	.asciz " "
string5: 	.asciz " "
string6: 	.asciz "Out here, a b c are "
string7: 	.asciz " "
string8: 	.asciz " "
.section .bss
.align 8
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq $0
	pushq $0
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
	movq $'\n', %rdi
	call safe_putchar
	movq $6, %rax
	movq %rax, -8(%rbp)
	movq $20, %rax
	movq %rax, -16(%rbp)
	movq $100, %rax
	movq %rax, -32(%rbp)
	leaq strout(%rip), %rdi
	leaq string3(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string4(%rip), %rsi
	call safe_printf
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string5(%rip), %rsi
	call safe_printf
	movq -32(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	leaq strout(%rip), %rdi
	leaq string6(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string7(%rip), %rsi
	call safe_printf
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string8(%rip), %rsi
	call safe_printf
	movq -24(%rbp), %rax
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
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $1, %rdi
	cmpq $0, %rdi
	jne ABORT
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
