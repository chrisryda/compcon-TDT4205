.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
.section .bss
.align 8
.myArray: 	.zero 80
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	movq $5, %rax
	pushq %rax
	movq $1, %rax
	leaq .myArray(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq $0, %rax
	leaq .myArray(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $1, %rax
	leaq .myArray(%rip), %rcx
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
