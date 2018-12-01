format: 
 .string "%d\n"
.text
.globl main
main:
movq %rsp, %r8
add $-8, %r8
movq %rsp, %r9
jmp .0
adder:
add $-8, %rsp
push %r8
push %r9
push %r11
push %r12
movq %rsp, %r15
movq %rsp, %r8
add $-8, %r8
push $105
push $7
push $0
push $106
push $7
push $0
movq %rsp, %r9
movq 88(%rsp), %r10
movq %r10, 24(%rsp)
movq 80(%rsp), %r10
movq %r10, 0(%rsp)
movq $105, %r12
movq %r8, %r11
.2:
cmp (%r11), %r12
je .1
add $-24, %r11
jmp .2
.1:
push -16(%r11)
movq $106, %r12
movq %r8, %r11
.4:
cmp (%r11), %r12
je .3
add $-24, %r11
jmp .4
.3:
push -16(%r11)
pop %r13
pop %r14
add %r14, %r13
push %r13
pop %rax
movq %r15, %rsp
pop %r12
pop %r11
pop %r9
pop %r8
add $8, %rsp
ret
.0:
push $11
push $34
call adder
movq $format, %rdi
pop %rsi
xorq	%rax, %rax
push %r8
push %r9
push %rdx
call	printf
pop %rdx
pop %r9
pop %r8
push $0
push $43
pop %r14
pop %r13
sub %r14, %r13
push %r13
push $50
call adder
movq $format, %rdi
pop %rsi
xorq	%rax, %rax
push %r8
push %r9
push %rdx
call	printf
pop %rdx
pop %r9
pop %r8
push $0
push $0
call adder
movq $format, %rdi
pop %rsi
xorq	%rax, %rax
push %r8
push %r9
push %rdx
call	printf
pop %rdx
pop %r9
pop %r8
push $1023
push $765
call adder
movq $format, %rdi
pop %rsi
xorq	%rax, %rax
push %r8
push %r9
push %rdx
call	printf
pop %rdx
pop %r9
pop %r8
movq %r9, %rsp
call _exit
