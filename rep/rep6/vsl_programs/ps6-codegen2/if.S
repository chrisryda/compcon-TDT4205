.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "a is less than 10"
string1: 	.asciz "a is more than -5"
string2: 	.asciz "a is less than or equal to -5"
string3: 	.asciz "a is equal to 5"
string4: 	.asciz "a is neither 0 nor 4"
string5: 	.asciz "a is not equal to 0"
string6: 	.asciz "a is however 6"
string7: 	.asciz "a is however 7"
string8: 	.asciz "a is however 10"
string9: 	.asciz "a is neither 0, 6, 7 or 10, but "
string10: 	.asciz "10 is my favorite"
string11: 	.asciz "I'm not happy about it either"
string12: 	.asciz "FIN?"
string13: 	.asciz "FIN."
.section .bss
.align 8
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	movq -8(%rbp), %rax
	pushq %rax
	movq $10, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_0
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_0
END_IF_0:
	movq -8(%rbp), %rax
	pushq %rax
	movq $-5, %rax
	popq %rcx
	cmpq %rax, %rcx
	setg %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_1
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_1
ELSE_IF_1:
	leaq strout(%rip), %rdi
	leaq string2(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
END_IF_1:
	movq -8(%rbp), %rax
	pushq %rax
	movq $5, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_2
	leaq strout(%rip), %rdi
	leaq string3(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_2
END_IF_2:
	movq -8(%rbp), %rax
	pushq %rax
	movq $0, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	pushq %rax
	movq -8(%rbp), %rax
	pushq %rax
	movq $4, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	popq %rcx
	addq %rcx, %rax
	cmpq $0, %rax
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_3
	leaq strout(%rip), %rdi
	leaq string4(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_3
END_IF_3:
	movq -8(%rbp), %rax
	pushq %rax
	movq $0, %rax
	popq %rcx
	cmpq %rax, %rcx
	setne %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_4
	leaq strout(%rip), %rdi
	leaq string5(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq -8(%rbp), %rax
	pushq %rax
	movq $6, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_5
	leaq strout(%rip), %rdi
	leaq string6(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_5
ELSE_IF_5:
	movq -8(%rbp), %rax
	pushq %rax
	movq $7, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_6
	leaq strout(%rip), %rdi
	leaq string7(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_6
ELSE_IF_6:
	movq -8(%rbp), %rax
	pushq %rax
	movq $10, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_7
	leaq strout(%rip), %rdi
	leaq string8(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_7
ELSE_IF_7:
	leaq strout(%rip), %rdi
	leaq string9(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
END_IF_7:
END_IF_6:
END_IF_5:
	movq -8(%rbp), %rax
	pushq %rax
	movq $10, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_8
	leaq strout(%rip), %rdi
	leaq string10(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_8
ELSE_IF_8:
	leaq strout(%rip), %rdi
	leaq string11(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
END_IF_8:
	leaq strout(%rip), %rdi
	leaq string12(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_4
END_IF_4:
	leaq strout(%rip), %rdi
	leaq string13(%rip), %rsi
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
