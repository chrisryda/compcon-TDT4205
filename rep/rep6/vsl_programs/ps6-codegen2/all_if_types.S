.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "try:"
string1: 	.asciz "try2:"
.section .bss
.align 8
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $-44, %rax
	pushq %rax
	popq %rdi
	call .try
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $-20, %rax
	pushq %rax
	popq %rdi
	call .try
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $45, %rax
	pushq %rax
	popq %rdi
	call .try
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $40, %rax
	pushq %rax
	popq %rdi
	call .try
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $5, %rax
	pushq %rax
	popq %rdi
	call .try
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $7, %rax
	pushq %rax
	popq %rdi
	call .try
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $10, %rax
	pushq %rax
	popq %rdi
	call .try
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $-44, %rax
	pushq %rax
	popq %rdi
	call .try2
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $-20, %rax
	pushq %rax
	popq %rdi
	call .try2
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $45, %rax
	pushq %rax
	popq %rdi
	call .try2
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $40, %rax
	pushq %rax
	popq %rdi
	call .try2
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $5, %rax
	pushq %rax
	popq %rdi
	call .try2
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $7, %rax
	pushq %rax
	popq %rdi
	call .try2
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $10, %rax
	pushq %rax
	popq %rdi
	call .try2
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
.try:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	movq -8(%rbp), %rax
	pushq %rax
	movq $-20, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_0
	movq $0, %rax
	jmp .try.epilogue
	jmp END_IF_0
END_IF_0:
	movq -8(%rbp), %rax
	pushq %rax
	movq $-20, %rax
	popq %rcx
	cmpq %rax, %rcx
	setle %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_1
	movq $1, %rax
	jmp .try.epilogue
	jmp END_IF_1
END_IF_1:
	movq -8(%rbp), %rax
	pushq %rax
	movq $40, %rax
	popq %rcx
	cmpq %rax, %rcx
	setg %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_2
	movq $2, %rax
	jmp .try.epilogue
	jmp END_IF_2
END_IF_2:
	movq -8(%rbp), %rax
	pushq %rax
	movq $40, %rax
	popq %rcx
	cmpq %rax, %rcx
	setge %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_3
	movq $3, %rax
	jmp .try.epilogue
	jmp END_IF_3
END_IF_3:
	movq -8(%rbp), %rax
	pushq %rax
	movq $5, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_4
	movq $4, %rax
	jmp .try.epilogue
	jmp END_IF_4
END_IF_4:
	movq -8(%rbp), %rax
	pushq %rax
	movq $10, %rax
	popq %rcx
	cmpq %rax, %rcx
	setne %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_5
	movq $5, %rax
	jmp .try.epilogue
	jmp END_IF_5
END_IF_5:
	movq $6, %rax
	jmp .try.epilogue
.try.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
.try2:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	movq -8(%rbp), %rax
	pushq %rax
	movq $-20, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_6
	movq $0, %rax
	jmp .try2.epilogue
	jmp END_IF_6
ELSE_IF_6:
	movq -8(%rbp), %rax
	pushq %rax
	movq $-20, %rax
	popq %rcx
	cmpq %rax, %rcx
	setle %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_7
	movq $1, %rax
	jmp .try2.epilogue
	jmp END_IF_7
ELSE_IF_7:
	movq -8(%rbp), %rax
	pushq %rax
	movq $40, %rax
	popq %rcx
	cmpq %rax, %rcx
	setg %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_8
	movq $2, %rax
	jmp .try2.epilogue
	jmp END_IF_8
ELSE_IF_8:
	movq -8(%rbp), %rax
	pushq %rax
	movq $40, %rax
	popq %rcx
	cmpq %rax, %rcx
	setge %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_9
	movq $3, %rax
	jmp .try2.epilogue
	jmp END_IF_9
ELSE_IF_9:
	movq -8(%rbp), %rax
	pushq %rax
	movq $5, %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_a
	movq $4, %rax
	jmp .try2.epilogue
	jmp END_IF_a
ELSE_IF_a:
	movq -8(%rbp), %rax
	pushq %rax
	movq $10, %rax
	popq %rcx
	cmpq %rax, %rcx
	setne %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_b
	movq $5, %rax
	jmp .try2.epilogue
	jmp END_IF_b
ELSE_IF_b:
	movq $6, %rax
	jmp .try2.epilogue
END_IF_b:
END_IF_a:
END_IF_9:
END_IF_8:
END_IF_7:
END_IF_6:
.try2.epilogue:
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
