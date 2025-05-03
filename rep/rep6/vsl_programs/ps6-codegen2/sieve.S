.section .rodata
intout: .asciz "%ld"
strout: .asciz "%s"
errout: .asciz "Wrong number of arguments"
string0: 	.asciz "Now printing every prime between 2 and "
string1: 	.asciz "Sorry, this program can only print primes up to 499"
string2: 	.asciz " is prime"
.section .bss
.align 8
.notPrime: 	.zero 4000
.text
.main:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	pushq $0
	leaq strout(%rip), %rdi
	leaq string0(%rip), %rsi
	call safe_printf
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq -8(%rbp), %rax
	pushq %rax
	movq $499, %rax
	popq %rcx
	cmpq %rax, %rcx
	setg %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_0
	leaq strout(%rip), %rdi
	leaq string1(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	movq $0, %rax
	jmp .main.epilogue
	jmp END_IF_0
END_IF_0:
	movq $1, %rax
	pushq %rax
	movq $0, %rax
	leaq .notPrime(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq $1, %rax
	pushq %rax
	movq $1, %rax
	leaq .notPrime(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq $2, %rax
	movq %rax, -16(%rbp)
WHILE_0:
	movq -16(%rbp), %rax
	pushq %rax
	movq $2, %rax
	pushq %rax
	movq -8(%rbp), %rax
	cqo
	popq %rcx
	idivq %rcx
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_WHILE_0
	movq -16(%rbp), %rax
	leaq .notPrime(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	cmpq $0, %rax
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_1
	movq -8(%rbp), %rax
	pushq %rax
	movq -16(%rbp), %rax
	pushq %rax
	popq %rdi
	popq %rsi
	call .doSieve
	jmp END_IF_1
END_IF_1:
	movq -16(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -16(%rbp)
	jmp WHILE_0
END_WHILE_0:
	movq -8(%rbp), %rax
	pushq %rax
	popq %rdi
	call .printPrimes
	movq $0, %rax
	jmp .main.epilogue
.main.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
.doSieve:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	pushq %rsi
	pushq $0
	movq -8(%rbp), %rax
	pushq %rax
	movq $2, %rax
	popq %rcx
	imulq %rcx, %rax
	movq %rax, -24(%rbp)
WHILE_1:
	movq -24(%rbp), %rax
	pushq %rax
	movq -16(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	popq %rcx
	cmpq %rax, %rcx
	setl %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_WHILE_1
	movq $1, %rax
	pushq %rax
	movq -24(%rbp), %rax
	leaq .notPrime(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	popq %rax
	movq %rax, (%rcx)
	movq -24(%rbp), %rax
	pushq %rax
	movq -8(%rbp), %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -24(%rbp)
	jmp WHILE_1
END_WHILE_1:
	movq $0, %rax
	jmp .doSieve.epilogue
.doSieve.epilogue:
	movq %rbp, %rsp
	popq %rbp
	ret
.printPrimes:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rdi
	pushq $0
	movq $0, %rax
	movq %rax, -16(%rbp)
WHILE_2:
	movq $1, %rax
	cmpq $0, %rax
	je END_WHILE_2
	movq -16(%rbp), %rax
	leaq .notPrime(%rip), %rcx
	leaq (%rcx, %rax, 8), %rcx
	movq (%rcx), %rax
	cmpq $0, %rax
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je END_IF_2
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq intout(%rip), %rdi
	call safe_printf
	leaq strout(%rip), %rdi
	leaq string2(%rip), %rsi
	call safe_printf
	movq $'\n', %rdi
	call safe_putchar
	jmp END_IF_2
END_IF_2:
	movq -16(%rbp), %rax
	pushq %rax
	movq -8(%rbp), %rax
	popq %rcx
	cmpq %rax, %rcx
	sete %al
	movzbq %al, %rax
	cmpq $0, %rax
	je ELSE_IF_3
	jmp END_WHILE_2
	jmp END_IF_3
ELSE_IF_3:
	movq -16(%rbp), %rax
	pushq %rax
	movq $1, %rax
	popq %rcx
	addq %rcx, %rax
	movq %rax, -16(%rbp)
END_IF_3:
	jmp WHILE_2
END_WHILE_2:
	movq $0, %rax
	jmp .printPrimes.epilogue
.printPrimes.epilogue:
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
