	.text
	.file	"AllocaInstruction.ll"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$0, -116(%rsp)
	movl	$1, -120(%rsp)
	movq	.L__const.main.b(%rip), %rax
	movq	%rax, -96(%rsp)
	movl	.L__const.main.b+8(%rip), %eax
	movl	%eax, -88(%rsp)
	movaps	.L__const.main.c(%rip), %xmm0
	movaps	%xmm0, -32(%rsp)
	movaps	.L__const.main.c+16(%rip), %xmm0
	movaps	%xmm0, -16(%rsp)
	movl	.L__const.main.c+32(%rip), %eax
	movl	%eax, (%rsp)
	movl	$1065353216, -124(%rsp) # imm = 0x3F800000
	movq	.L__const.main.e(%rip), %rax
	movq	%rax, -112(%rsp)
	movl	.L__const.main.e+8(%rip), %eax
	movl	%eax, -104(%rsp)
	movaps	.L__const.main.f(%rip), %xmm0
	movaps	%xmm0, -80(%rsp)
	movaps	.L__const.main.f+16(%rip), %xmm0
	movaps	%xmm0, -64(%rsp)
	movl	.L__const.main.f+32(%rip), %eax
	movl	%eax, -48(%rsp)
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L__const.main.b,@object # @__const.main.b
	.section	.rodata,"a",@progbits
	.p2align	2
.L__const.main.b:
	.long	1                       # 0x1
	.long	2                       # 0x2
	.long	3                       # 0x3
	.size	.L__const.main.b, 12

	.type	.L__const.main.c,@object # @__const.main.c
	.p2align	4
.L__const.main.c:
	.long	1                       # 0x1
	.long	2                       # 0x2
	.long	3                       # 0x3
	.long	2                       # 0x2
	.long	3                       # 0x3
	.long	4                       # 0x4
	.long	3                       # 0x3
	.long	4                       # 0x4
	.long	5                       # 0x5
	.size	.L__const.main.c, 36

	.type	.L__const.main.e,@object # @__const.main.e
	.p2align	2
.L__const.main.e:
	.long	1065353216              # float 1
	.long	1073741824              # float 2
	.long	1077936128              # float 3
	.size	.L__const.main.e, 12

	.type	.L__const.main.f,@object # @__const.main.f
	.p2align	4
.L__const.main.f:
	.long	1065353216              # float 1
	.long	1073741824              # float 2
	.long	1077936128              # float 3
	.long	1073741824              # float 2
	.long	1077936128              # float 3
	.long	1082130432              # float 4
	.long	1077936128              # float 3
	.long	1082130432              # float 4
	.long	1084227584              # float 5
	.size	.L__const.main.f, 36

	.section	".note.GNU-stack","",@progbits
