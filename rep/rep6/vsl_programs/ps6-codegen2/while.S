.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "First printing every power of two less than 1000"
string1: 	.asciz "i is now "
string2: 	.asciz "Now printing every product with factors less than 6"
string3: 	.asciz " * "
string4: 	.asciz " = "
.section .bss
.align 8
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq $0
	pushq $0
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $1, %rax
	movq %rax, -8(%rbp)
WHILE_0:
	movq -8(%rbp), %rax
	pushq %rax
	movq $1000, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_WHILE_0
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq -8(%rbp), %rax
	pushq %rax
	movq $2, %rax
	popq %rcx
	imulq %rcx, %rax
	movq %rax, -8(%rbp)
	jmp WHILE_0
END_WHILE_0:
	leaq strout(%rip), %rdi
	leaq string2(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $1, %rax
	movq %rax, -8(%rbp)
WHILE_1:
	movq -8(%rbp), %rax
	pushq %rax
	movq $6, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_WHILE_1
	movq $1, %rax
	movq %rax, -16(%rbp)
WHILE_2:
	movq -16(%rbp), %rax
	pushq %rax
	movq -8(%rbp), %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_WHILE_2
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
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
	movq -8(%rbp), %rax
	pushq %rax
	movq -16(%rbp), %rax
	popq %rcx
	imulq %rcx, %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq -16(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -16(%rbp)
	jmp WHILE_2
END_WHILE_2:
	movq -8(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -8(%rbp)
	jmp WHILE_1
END_WHILE_1:
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
