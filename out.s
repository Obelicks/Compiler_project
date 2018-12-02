format: 
 .string "%d\n"
.text
.globl main
main:
movq %rsp, %r8
add $-8, %r8
movq %rsp, %r9
jmp .0
.myFunc:
pop %r12
push %r8
push %r9
push %r11
push %r12
push %r15
movq %rsp, %r15
movq %rsp, %r8
add $-8, %r8
push $94881 
push $1
push $0 
push $95842 
push $1
push $0 
push $96803
push $7
push $0
movq %rsp, %r9
movq 128(%rsp), %r10
movq %r10, 48(%rsp)
movq 120(%rsp), %r10
movq %r10, 24(%rsp)
movq 112(%rsp), %r10
movq %r10, 0(%rsp)
movq $94881, %r12
movq %r8, %r11
.2:
cmp (%r11), %r12
je .1
add $-24, %r11
jmp .2
.1:
push -16(%r11)
movq $95842, %r12
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
movq $96803, %r12
movq %r8, %r11
.6:
cmp (%r11), %r12
je .5
add $-24, %r11
jmp .6
.5:
push -16(%r11)
pop %r13
pop %r14
add %r14, %r13
push %r13
pop %r10
movq %r15, %rsp
pop %r15
pop %r12
pop %r11
pop %r9
pop %r8
add $24, %rsp
push %r10
push %r12
ret
.0:
push $4
push $2
push $4
call .myFunc
movq $format, %rdi
pop %rsi
xorq	%rax, %rax
push %r15
push %r12
push %r11
push %r9
push %r8
push %rdx
call	printf
pop %rdx
pop %r8
pop %r9
pop %r11
pop %r12
pop %r15
movq %r9, %rsp
call _exit
