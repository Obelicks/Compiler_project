.text
.section	.data
.DEFS:
.string	"%i\n"
.p2align 4,,15
.globl	main
.type	main, @function
main:
leaq	.DEFS(%rip), %rsi	#,
subq	$8, %rsp
movq	$2, %rdx
movq	$1, %rdi
xorq	%rax, %rax
call	__printf_chk@PLT
xorq	%rax, %rax
addq	$8, %rsp
ret
.size	main, .-main
