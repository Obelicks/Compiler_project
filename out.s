.data
format: .ascii "%d\n"
.bss
.lcomm heap, 1064
.text
.globl main
main:
subq $8, %rsp
movq $0, %rdi
push %r13
push %r14
push %rax
push %r8
push %r9
push %r10
push %rax
leaq heap, %r8
leaq heap, %r9
leaq heap, %r10
add $1064, %r10
movq $97, (%r9)
movq $1, 64(%r9)
movq $0, 128(%r9)
add $192, %r9
movq %r8, %r11
movq $97, %r12
cmp (%r11), %r12
je .+11
add $192, %r11
jmp .-12
push $5
pop 128(%r11)
movq $97, %r12
movq %r8, %r11
cmp (%r11), %r12
je .+11
add $192, %r11
jmp .-12
push 128(%r11)
movq $format, %rdi
pop %rsi
movq $0, %rax
push %r13
push %r14
push %rax
push %r8
push %r9
push %r10
push %r11
push %r12
push %rsi
push %rax
call printf
pop %rax
pop %rsi
pop %r12
pop %r11
pop %r10
pop %r9
pop %r8
pop %r14
pop %r13
pop %rax
pop %r10
pop %r9
pop %r8
pop %r14
pop %r13
call _exit
