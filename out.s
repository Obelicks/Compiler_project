format: 
 .string "%d\n"
.text
.globl main
main:
movq %rsp, %r8
add $-8, %r8
movq %rsp, %r9
push $98
push $7
push $0
movq %r8, %r11
movq $98, %r12
.1:
cmp (%r11), %r12
je .0
add $-24, %r11
jmp .1
.0:
push $0
pop -16(%r11)
movq $98, %r12
movq %r8, %r11
.5:
cmp (%r11), %r12
je .4
add $-24, %r11
jmp .5
.4:
push -16(%r11)
pop %r14
cmp $0, %r14
jne .2
push $0
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
jmp .3
.2:
push $1
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
.3:
movq $98, %r12
movq %r8, %r11
.8:
cmp (%r11), %r12
je .7
add $-24, %r11
jmp .8
.7:
push -16(%r11)
pop %r14
cmp $0, %r14
jne .6
push $1
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
.6:
movq %r9, %rsp
call _exit
