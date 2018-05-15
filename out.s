extern printf
.text
.globl _main
_main:
push %rbp
movq %rbp, %rsp
push %rbx
push %r12
push %r13
push %r14
push %rbx
push 3
push 4
pop %r13
pop %r14
add %r14, %r13
push %r13
push 3
push 7
pop %r13
pop %r14
movq %r13, %rax
div %r14
movq %rax, %r13
push %r13
push 94
pop %r13
pop %r14
movq %r13, %rax
mul %r14
movq %rax, %r13
push %r13
pop %r13
pop %r14
sub %r14, %r13
push %r13
call _prinf
pop %rbx
pop %r14
pop %r13
pop %r12
pop %rbx
movq %rbp, %rsp
pop %rbp
movq 0, %rax
ret
