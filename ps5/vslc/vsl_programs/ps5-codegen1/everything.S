.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz " "
.section .bss
.align 8
.X: 	.zero 8
.Y: 	.zero 8
.array: 	.zero 80
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	pushq %rsi
	movq -8(%rbp), %rax
	movq %rax, .X(%rip)
	movq -16(%rbp), %rax
	movq %rax, .Y(%rip)
	movq $1000, %rax
	pushq %rax
	movq -8(%rbp), %rax
	pushq %rax
	movq -8(%rbp), %rax
	cqo
	popq %rcx
	idivq %rcx
	pushq %rax
	popq %rdi
	popq %rsi
	call .mulAndAdd
	pushq %rax
	movq $0, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	call .swap
	movq $1000, %rax
	pushq %rax
	movq $1, %rax
	pushq %rax
	popq %rdi
	popq %rsi
	call .mulAndAdd
	pushq %rax
	movq $1, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq $0, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq $1, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
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
.mulAndAdd:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	pushq %rsi
	movq -8(%rbp), %rax
	pushq %rax
	movq .X(%rip), %rax
	popq %rcx
	imulq %rcx, %rax
	pushq %rax
	movq -16(%rbp), %rax
	pushq %rax
	movq .Y(%rip), %rax
	popq %rcx
	imulq %rcx, %rax
	popq %rcx
	addq %rcx, %rax
	jmp .mulAndAdd.epilogue
.mulAndAdd.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
.swap:
	pushq %rbp
	movq %rsp, %rbp
	pushq $0
	movq .X(%rip), %rax
	movq %rax, -8(%rbp)
	movq .Y(%rip), %rax
	movq %rax, .X(%rip)
	movq -8(%rbp), %rax
	movq %rax, .Y(%rip)
	movq $0, %rax
	jmp .swap.epilogue
.swap.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $1, %rdi
	cmpq $2, %rdi
	jne ABORT
	addq $16, %rsi
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
