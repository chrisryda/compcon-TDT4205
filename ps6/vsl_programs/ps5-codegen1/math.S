.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "num = "
string1: 	.asciz "num*3 = "
string2: 	.asciz "num+5 = "
string3: 	.asciz "num/5 = "
string4: 	.asciz "4*-num = "
string5: 	.asciz "(num-1)*(num+1)*(num+3) = "
.section .bss
.align 8
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	pushq %rax
	movq $3, %rax
	popq %rcx
	imulq %rcx, %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	leaq strout(%rip), %rdi
	leaq string2(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	pushq %rax
	movq $5, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	leaq strout(%rip), %rdi
	leaq string3(%rip), %rsi
	call safe_printf
	movq $5, %rax
	pushq %rax
	movq -8(%rbp), %rax
	cqo
	popq %rcx
	idivq %rcx
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	leaq strout(%rip), %rdi
	leaq string4(%rip), %rsi
	call safe_printf
	movq $4, %rax
	pushq %rax
	movq -8(%rbp), %rax
	negq %rax
	popq %rcx
	imulq %rcx, %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	leaq strout(%rip), %rdi
	leaq string5(%rip), %rsi
	call safe_printf
	movq $1, %rax
	pushq %rax
	movq -8(%rbp), %rax
	popq %rcx
	subq %rcx, %rax
	pushq %rax
	movq -8(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	popq %rcx
	imulq %rcx, %rax
	pushq %rax
	movq -8(%rbp), %rax
	pushq %rax
	movq $3, %rax
	popq %rcx
	addq %rcx, %rax
	popq %rcx
	imulq %rcx, %rax
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
	cmpq $1, %rdi
	jne ABORT
	addq $8, %rsi
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
