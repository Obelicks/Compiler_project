.data
format: .ascii "%d\n"
.text
.globl main
main:
subq $8, %rsp
movq $0, %rdi
push %r13
push %r14
push %rax
movq $5, %r13
push %r13
movq $4229495, %r13
push %r13
mov $format, %rdi
pop %rsi
mov $0, %eax
call printf
pop %rax
pop %r13
pop %r14
call _exit
