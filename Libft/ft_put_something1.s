	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_ft_put_int             ## -- Begin function ft_put_int
	.p2align	4, 0x90
_ft_put_int:                            ## @ft_put_int
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movslq	-8(%rbp), %rsi
	movq	%rsi, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jge	LBB0_4
## %bb.1:
	imulq	$-1, -32(%rbp), %rax
	movq	%rax, -32(%rbp)
	movl	$1, %edi
	leaq	L_.str(%rip), %rsi
	movl	$1, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB0_3
## %bb.2:
	movl	$-1, -4(%rbp)
	jmp	LBB0_10
LBB0_3:
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
LBB0_4:
	movl	$10, %eax
	cmpq	-32(%rbp), %rax
	jg	LBB0_6
## %bb.5:
	movq	-32(%rbp), %rax
	cqto
	movl	$10, %ecx
	idivq	%rcx
	movl	%eax, %esi
	movq	-16(%rbp), %rax
	movl	%esi, %edi
	movq	%rax, %rsi
	callq	_ft_put_int
	movl	%eax, -36(%rbp)         ## 4-byte Spill
LBB0_6:
	movq	-32(%rbp), %rax
	cqto
	movl	$10, %ecx
	idivq	%rcx
	addq	$48, %rdx
	movb	%dl, %sil
	movb	%sil, -17(%rbp)
	movq	-16(%rbp), %rcx
	cmpl	$-1, (%rcx)
	je	LBB0_8
## %bb.7:
	movl	$1, %edi
	leaq	-17(%rbp), %rsi
	movl	$1, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB0_9
LBB0_8:
	movq	-16(%rbp), %rax
	movl	$-1, (%rax)
	movl	$-1, -4(%rbp)
	jmp	LBB0_10
LBB0_9:
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -4(%rbp)
LBB0_10:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_put_unsigned_int    ## -- Begin function ft_put_unsigned_int
	.p2align	4, 0x90
_ft_put_unsigned_int:                   ## @ft_put_unsigned_int
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$10, %edi
	cmpl	-8(%rbp), %edi
	ja	LBB1_2
## %bb.1:
	movl	-8(%rbp), %eax
	xorl	%edx, %edx
	movl	$10, %ecx
	divl	%ecx
	movq	-16(%rbp), %rsi
	movl	%eax, %edi
	callq	_ft_put_unsigned_int
	movl	%eax, -24(%rbp)         ## 4-byte Spill
LBB1_2:
	movl	-8(%rbp), %eax
	xorl	%edx, %edx
	movl	$10, %ecx
	divl	%ecx
	addl	$48, %edx
	movb	%dl, %sil
	movb	%sil, -17(%rbp)
	movq	-16(%rbp), %rdi
	cmpl	$-1, (%rdi)
	je	LBB1_4
## %bb.3:
	movl	$1, %edi
	leaq	-17(%rbp), %rsi
	movl	$1, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB1_5
LBB1_4:
	movq	-16(%rbp), %rax
	movl	$-1, (%rax)
	movl	$-1, -4(%rbp)
	jmp	LBB1_6
LBB1_5:
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -4(%rbp)
LBB1_6:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"-"


.subsections_via_symbols
