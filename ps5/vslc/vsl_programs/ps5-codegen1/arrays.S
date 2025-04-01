.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "The values of the array are: "
string1: 	.asciz " "
string2: 	.asciz " "
string3: 	.asciz " "
string4: 	.asciz "array[3] = "
.section .bss
.align 8
.scalar: 	.zero 8
.array: 	.zero 80
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	movq $1, %rax
	pushq %rax
	movq $0, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq $0, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq $1, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq $3, %rax
	pushq %rax
	movq $1, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq $0, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq $1, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string2(%rip), %rsi
	call safe_printf
	movq $2, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string3(%rip), %rsi
	call safe_printf
	movq $3, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $1, %rax
	pushq %rax
	movq $3, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq $2, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	pushq %rax
	movq $2, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	pushq %rax
	popq %rdi
	popq %rsi
	call .sum
	pushq %rax
	movq $1, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	pushq %rax
	movq $0, %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	pushq %rax
	popq %rdi
	popq %rsi
	call .sum
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	leaq strout(%rip), %rdi
	leaq string4(%rip), %rsi
	call safe_printf
	movq $3, %rax
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
.sum:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	pushq %rsi
	movq -8(%rbp), %rax
	pushq %rax
	movq -16(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	jmp .sum.epilogue
.sum.epilogue:
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
