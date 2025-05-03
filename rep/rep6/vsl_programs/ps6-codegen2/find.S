.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "Filling up array with \"random\" values"
string1: 	.asciz "Looking for all occurances of "
string2: 	.asciz "Found at: "
string3: 	.asciz "Done!"
.section .bss
.align 8
.pos: 	.zero 8
.array: 	.zero 800
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	call .initialize
	movq -8(%rbp), %rax
	pushq %rax
	popq %rdi
	call .find
	movq $0, %rax
	jmp .main.epilogue
.main.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
.initialize:
	pushq %rbp
	movq %rsp, %rbp
	pushq $0
	pushq $0
	pushq $0
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
WHILE_0:
	movq $1, %rax
	cmpq $0, %rax
	je END_WHILE_0
	movq -8(%rbp), %rax
	pushq %rax
	movq $21, %rax
	popq %rcx
	imulq %rcx, %rax
	pushq %rax
	movq $31, %rax
	pushq %rax
	movq -8(%rbp), %rax
	cqo
	popq %rcx
	idivq %rcx
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq $7, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -8(%rbp)
	movq -16(%rbp), %rax
	pushq %rax
	movq $16, %rax
	popq %rcx
	imulq %rcx, %rax
	pushq %rax
	movq $13, %rax
	pushq %rax
	movq -16(%rbp), %rax
	cqo
	popq %rcx
	idivq %rcx
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq $18, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -16(%rbp)
	movq -8(%rbp), %rax
	pushq %rax
	movq -16(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -24(%rbp)
	movq -24(%rbp), %rax
	pushq %rax
	movq $0, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_0
	movq -24(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	subq %rcx, %rax
	movq %rax, -24(%rbp)
	jmp END_IF_0
END_IF_0:
	movq $100, %rax
	pushq %rax
	movq -24(%rbp), %rax
	cqo
	popq %rcx
	idivq %rcx
	pushq %rax
	movq $100, %rax
	popq %rcx
	imulq %rcx, %rax
	pushq %rax
	movq -24(%rbp), %rax
	popq %rcx
	subq %rcx, %rax
	movq %rax, -24(%rbp)
	movq -24(%rbp), %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	pushq %rax
	movq -24(%rbp), %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq -24(%rbp), %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	pushq %rax
	movq $10, %rax
	popq %rcx
	cmpq %rax, %rcx
	setge %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_1
	jmp END_WHILE_0
	jmp END_IF_1
END_IF_1:
	jmp WHILE_0
END_WHILE_0:
	movq $0, %rax
	jmp .initialize.epilogue
.initialize.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
.nextPos:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
WHILE_1:
	movq .pos(%rip), %rax
	pushq %rax
	movq $100, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_WHILE_1
	movq .pos(%rip), %rax
	leaq .array(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	pushq %rax
	movq -8(%rbp), %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_2
	movq $1, %rax
	jmp .nextPos.epilogue
	jmp END_IF_2
END_IF_2:
	movq .pos(%rip), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, .pos(%rip)
	jmp WHILE_1
END_WHILE_1:
	movq $0, %rax
	jmp .nextPos.epilogue
.nextPos.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
.find:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $0, %rax
	movq %rax, .pos(%rip)
WHILE_2:
	movq -8(%rbp), %rax
	pushq %rax
	popq %rdi
	call .nextPos
	cmpq $0, %rax
	je END_WHILE_2
	leaq strout(%rip), %rdi
	leaq string2(%rip), %rsi
	call safe_printf
	movq .pos(%rip), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq .pos(%rip), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, .pos(%rip)
	jmp WHILE_2
END_WHILE_2:
	leaq strout(%rip), %rdi
	leaq string3(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $0, %rax
	jmp .find.epilogue
.find.epilogue:
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
