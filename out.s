format: 
 .string "%d\n"
.text
.globl main
main:
movq %rsp, %r8
add $-8, %r8
movq %rsp, %r9
push $105 
push $1
push $0 
push $106
push $7
push $0
movq %rsp, %r9
movq %r8, %r11
movq $105, %r12
movq %r9, %r10
.1:
cmp (%r11), %r12
je .0
add $-24, %r11
cmp %r11, %r10
jg .2
jmp .1
.0:
push $10
pop -16(%r11)
jmp .3
.2:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .1
.3:
movq %r8, %r11
movq $106, %r12
movq %r9, %r10
.5:
cmp (%r11), %r12
je .4
add $-24, %r11
cmp %r11, %r10
jg .6
jmp .5
.4:
push $1
pop -16(%r11)
jmp .7
.6:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .5
.7:
movq $105, %r12
movq %r8, %r11
movq %r9, %r10
.11:
cmp (%r11), %r12
je .10
add $-24, %r11
cmp %r11, %r10
jg .12
jmp .11
.10:
push -16(%r11)
jmp .13
.12:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .11
.13:
push $20
pop %r13
pop %r14
cmp %r13, %r14
jl .8
movq $1, %r13
jmp .9
.8:
movq $0, %r13
.9:
push %r13
pop %r14
cmp $0, %r14
jne .14
.15:
movq $106, %r12
movq %r8, %r11
movq %r9, %r10
.19:
cmp (%r11), %r12
je .18
add $-24, %r11
cmp %r11, %r10
jg .20
jmp .19
.18:
push -16(%r11)
jmp .21
.20:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .19
.21:
push $5
pop %r13
pop %r14
cmp %r13, %r14
jl .16
movq $1, %r13
jmp .17
.16:
movq $0, %r13
.17:
push %r13
pop %r14
cmp $0, %r14
jne .22
.23:
movq %r8, %r11
movq $106, %r12
movq %r9, %r10
.25:
cmp (%r11), %r12
je .24
add $-24, %r11
cmp %r11, %r10
jg .26
jmp .25
.24:
movq $106, %r12
movq %r8, %r11
movq %r9, %r10
.29:
cmp (%r11), %r12
je .28
add $-24, %r11
cmp %r11, %r10
jg .30
jmp .29
.28:
push -16(%r11)
jmp .31
.30:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .29
.31:
push $1
pop %r13
pop %r14
add %r14, %r13
push %r13
pop -16(%r11)
jmp .27
.26:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .25
.27:
movq $106, %r12
movq %r8, %r11
movq %r9, %r10
.33:
cmp (%r11), %r12
je .32
add $-24, %r11
cmp %r11, %r10
jg .34
jmp .33
.32:
push -16(%r11)
jmp .35
.34:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .33
.35:
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
movq $106, %r12
movq %r8, %r11
movq %r9, %r10
.39:
cmp (%r11), %r12
je .38
add $-24, %r11
cmp %r11, %r10
jg .40
jmp .39
.38:
push -16(%r11)
jmp .41
.40:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .39
.41:
push $5
pop %r13
pop %r14
cmp %r13, %r14
jl .36
movq $1, %r13
jmp .37
.36:
movq $0, %r13
.37:
push %r13
pop %r14
cmp $0, %r14
je .23
.22:
movq %r8, %r11
movq $105, %r12
movq %r9, %r10
.43:
cmp (%r11), %r12
je .42
add $-24, %r11
cmp %r11, %r10
jg .44
jmp .43
.42:
movq $105, %r12
movq %r8, %r11
movq %r9, %r10
.47:
cmp (%r11), %r12
je .46
add $-24, %r11
cmp %r11, %r10
jg .48
jmp .47
.46:
push -16(%r11)
jmp .49
.48:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .47
.49:
push $1
pop %r13
pop %r14
add %r14, %r13
push %r13
pop -16(%r11)
jmp .45
.44:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .43
.45:
movq $105, %r12
movq %r8, %r11
movq %r9, %r10
.51:
cmp (%r11), %r12
je .50
add $-24, %r11
cmp %r11, %r10
jg .52
jmp .51
.50:
push -16(%r11)
jmp .53
.52:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .51
.53:
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
movq $105, %r12
movq %r8, %r11
movq %r9, %r10
.57:
cmp (%r11), %r12
je .56
add $-24, %r11
cmp %r11, %r10
jg .58
jmp .57
.56:
push -16(%r11)
jmp .59
.58:
movq 40(%r8), %r11
movq 32(%r8), %r10
jmp .57
.59:
push $20
pop %r13
pop %r14
cmp %r13, %r14
jl .54
movq $1, %r13
jmp .55
.54:
movq $0, %r13
.55:
push %r13
pop %r14
cmp $0, %r14
je .15
.14:
movq %r9, %rsp
call _exit
