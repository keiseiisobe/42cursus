	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_if_unsigned_decimal    ## -- Begin function if_unsigned_decimal
	.p2align	4, 0x90
_if_unsigned_decimal:                   ## @if_unsigned_decimal
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movl	$0, -16(%rbp)
	leaq	-16(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movq	-8(%rbp), %rdi
	movl	(%rdi), %eax
	cmpl	$40, %eax
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	ja	LBB0_2
## %bb.1:
	movl	-36(%rbp), %eax         ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	jmp	LBB0_3
LBB0_2:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -48(%rbp)         ## 8-byte Spill
LBB0_3:
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movl	(%rax), %ecx
	movl	%ecx, -12(%rbp)
	movl	-12(%rbp), %edi
	movq	-24(%rbp), %rsi
	callq	_ft_put_unsigned_int
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_if_hexadec_low         ## -- Begin function if_hexadec_low
	.p2align	4, 0x90
_if_hexadec_low:                        ## @if_hexadec_low
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movl	$0, -16(%rbp)
	leaq	-16(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movq	-8(%rbp), %rdi
	movl	(%rdi), %eax
	cmpl	$40, %eax
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	ja	LBB1_2
## %bb.1:
	movl	-36(%rbp), %eax         ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	jmp	LBB1_3
LBB1_2:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -48(%rbp)         ## 8-byte Spill
LBB1_3:
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movl	(%rax), %ecx
	movl	%ecx, -12(%rbp)
	movl	-12(%rbp), %edi
	movq	-24(%rbp), %rsi
	callq	_ft_put_hexadec_low
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_if_hexadec_up          ## -- Begin function if_hexadec_up
	.p2align	4, 0x90
_if_hexadec_up:                         ## @if_hexadec_up
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movl	$0, -16(%rbp)
	leaq	-16(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movq	-8(%rbp), %rdi
	movl	(%rdi), %eax
	cmpl	$40, %eax
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	ja	LBB2_2
## %bb.1:
	movl	-36(%rbp), %eax         ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	jmp	LBB2_3
LBB2_2:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -48(%rbp)         ## 8-byte Spill
LBB2_3:
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movl	(%rax), %ecx
	movl	%ecx, -12(%rbp)
	movl	-12(%rbp), %edi
	movq	-24(%rbp), %rsi
	callq	_ft_put_hexadec_up
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
