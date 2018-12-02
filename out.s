format: 
 .string "%d\n"
.text
.globl main
main:
movq %rsp, %r8
add $-8, %r8
movq %rsp, %r9
jmp .0
.factorial:
pop %r12
push %r8
push %r9
push %r11
push %r12
push %r15
movq %rsp, %r15
movq %rsp, %r8
add $-8, %r8
push $110
push $7
push $0
movq %rsp, %r9
movq 64(%rsp), %r10
movq %r10, 0(%rsp)
movq $110, %r12
movq %r8, %r11
.8:
cmp (%r11), %r12
je .7
add $-24, %r11
jmp .8
.7:
push -16(%r11)
push $0
pop %r13
pop %r14
cmp %r14, %r13
jne .5
movq $0, %r13
jmp .6
.5:
movq $1, %r13
.6:
push %r13
movq $110, %r12
movq %r8, %r11
.12:
cmp (%r11), %r12
je .11
add $-24, %r11
jmp .12
.11:
push -16(%r11)
push $1
pop %r13
pop %r14
cmp %r14, %r13
jne .9
movq $0, %r13
jmp .10
.9:
movq $1, %r13
.10:
push %r13
pop %r13
pop %r14
cmp $0, %r13
je .3
cmp $0, %r14
je .3
movq $1, %r13
jmp .4
.3:
movq $0, %r13
.4:
push %r13
pop %r14
cmp $0, %r14
jne .1
push $1
jmp .2
.1:
movq $110, %r12
movq %r8, %r11
.14:
cmp (%r11), %r12
je .13
add $-24, %r11
jmp .14
.13:
push -16(%r11)
movq $110, %r12
movq %r8, %r11
.16:
cmp (%r11), %r12
je .15
add $-24, %r11
jmp .16
.15:
push -16(%r11)
push $1
pop %r14
pop %r13
sub %r14, %r13
push %r13
call .factorial
pop %r13
pop %r14
movq %r13, %rax
mul %r14
movq %rax, %r13
push %r13
.2:
pop %r10
movq %r15, %rsp
pop %r15
pop %r12
pop %r11
pop %r9
pop %r8
add $8, %rsp
push %r10
push %r12
ret
.0:
push $5
call .factorial
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
