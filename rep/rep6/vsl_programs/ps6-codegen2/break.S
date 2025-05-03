.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz " <= "
string1: 	.asciz "===="
.section .bss
.align 8
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq $0
	pushq $0
WHILE_0:
	movq $1, %rax
	cmpq $0, %rax
	je END_WHILE_0
	movq -8(%rbp), %rax
	movq %rax, -16(%rbp)
WHILE_1:
	movq $1, %rax
	cmpq $0, %rax
	je END_WHILE_1
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $1, %rax
	pushq %rax
	movq -16(%rbp), %rax
	popq %rcx
	subq %rcx, %rax
	movq %rax, -16(%rbp)
	movq -16(%rbp), %rax
	pushq %rax
	movq $0, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_0
	jmp END_WHILE_1
	jmp END_IF_0
END_IF_0:
	jmp WHILE_1
END_WHILE_1:
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq -8(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -8(%rbp)
	movq -8(%rbp), %rax
	pushq %rax
	movq $5, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_1
	jmp END_WHILE_0
	jmp END_IF_1
END_IF_1:
	jmp WHILE_0
END_WHILE_0:
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
