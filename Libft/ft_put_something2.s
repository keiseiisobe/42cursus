	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_ft_put_address         ## -- Begin function ft_put_address
	.p2align	4, 0x90
_ft_put_address:                        ## @ft_put_address
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	leaq	L_.str(%rip), %rax
	movq	%rax, -72(%rbp)
	movl	$0, -76(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-72(%rbp), %rax
	movl	-76(%rbp), %ecx
	movl	%ecx, %edx
	cmpb	$0, (%rax,%rdx)
	je	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	-72(%rbp), %rax
	movl	-76(%rbp), %ecx
	movl	%ecx, %edx
	movb	(%rax,%rdx), %sil
	movl	-76(%rbp), %ecx
	movl	%ecx, %eax
	movb	%sil, -32(%rbp,%rax)
	movl	-76(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -76(%rbp)
	jmp	LBB0_1
LBB0_3:
	movl	$16, %eax
	cmpq	-48(%rbp), %rax
	ja	LBB0_5
## %bb.4:
	movq	-48(%rbp), %rax
	shrq	$4, %rax
	movq	-56(%rbp), %rsi
	movq	%rax, %rdi
	callq	_ft_put_address
	movl	%eax, -80(%rbp)         ## 4-byte Spill
LBB0_5:
	movq	-48(%rbp), %rax
	andq	$15, %rax
	movb	-32(%rbp,%rax), %cl
	movb	%cl, -57(%rbp)
	movq	-56(%rbp), %rax
	cmpl	$-1, (%rax)
	je	LBB0_7
## %bb.6:
	movl	$1, %edi
	leaq	-57(%rbp), %rsi
	movl	$1, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB0_8
LBB0_7:
	movq	-56(%rbp), %rax
	movl	$-1, (%rax)
	movl	$-1, -36(%rbp)
	jmp	LBB0_9
LBB0_8:
	movq	-56(%rbp), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	movq	-56(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -36(%rbp)
LBB0_9:
	movl	-36(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	jne	LBB0_11
## %bb.10:
	movl	-84(%rbp), %eax         ## 4-byte Reload
	addq	$96, %rsp
	popq	%rbp
	retq
LBB0_11:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_put_hexadec_low     ## -- Begin function ft_put_hexadec_low
	.p2align	4, 0x90
_ft_put_hexadec_low:                    ## @ft_put_hexadec_low
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	%edi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	leaq	L_.str(%rip), %rax
	movq	%rax, -64(%rbp)
	movl	$0, -68(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-64(%rbp), %rax
	movl	-68(%rbp), %ecx
	movl	%ecx, %edx
	cmpb	$0, (%rax,%rdx)
	je	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movq	-64(%rbp), %rax
	movl	-68(%rbp), %ecx
	movl	%ecx, %edx
	movb	(%rax,%rdx), %sil
	movl	-68(%rbp), %ecx
	movl	%ecx, %eax
	movb	%sil, -32(%rbp,%rax)
	movl	-68(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -68(%rbp)
	jmp	LBB1_1
LBB1_3:
	movl	$16, %eax
	cmpl	-40(%rbp), %eax
	ja	LBB1_5
## %bb.4:
	movl	-40(%rbp), %eax
	shrl	$4, %eax
	movq	-48(%rbp), %rsi
	movl	%eax, %edi
	callq	_ft_put_hexadec_low
	movl	%eax, -72(%rbp)         ## 4-byte Spill
LBB1_5:
	movl	-40(%rbp), %eax
	andl	$15, %eax
	movl	%eax, %eax
	movl	%eax, %ecx
	movb	-32(%rbp,%rcx), %dl
	movb	%dl, -49(%rbp)
	movq	-48(%rbp), %rcx
	cmpl	$-1, (%rcx)
	je	LBB1_7
## %bb.6:
	movl	$1, %edi
	leaq	-49(%rbp), %rsi
	movl	$1, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB1_8
LBB1_7:
	movq	-48(%rbp), %rax
	movl	$-1, (%rax)
	movl	$-1, -36(%rbp)
	jmp	LBB1_9
LBB1_8:
	movq	-48(%rbp), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	movq	-48(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -36(%rbp)
LBB1_9:
	movl	-36(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	jne	LBB1_11
## %bb.10:
	movl	-76(%rbp), %eax         ## 4-byte Reload
	addq	$80, %rsp
	popq	%rbp
	retq
LBB1_11:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_put_hexadec_up      ## -- Begin function ft_put_hexadec_up
	.p2align	4, 0x90
_ft_put_hexadec_up:                     ## @ft_put_hexadec_up
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	%edi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	leaq	L_.str.1(%rip), %rax
	movq	%rax, -64(%rbp)
	movl	$0, -68(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-64(%rbp), %rax
	movl	-68(%rbp), %ecx
	movl	%ecx, %edx
	cmpb	$0, (%rax,%rdx)
	je	LBB2_3
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movq	-64(%rbp), %rax
	movl	-68(%rbp), %ecx
	movl	%ecx, %edx
	movb	(%rax,%rdx), %sil
	movl	-68(%rbp), %ecx
	movl	%ecx, %eax
	movb	%sil, -32(%rbp,%rax)
	movl	-68(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -68(%rbp)
	jmp	LBB2_1
LBB2_3:
	movl	$16, %eax
	cmpl	-40(%rbp), %eax
	ja	LBB2_5
## %bb.4:
	movl	-40(%rbp), %eax
	shrl	$4, %eax
	movq	-48(%rbp), %rsi
	movl	%eax, %edi
	callq	_ft_put_hexadec_up
	movl	%eax, -72(%rbp)         ## 4-byte Spill
LBB2_5:
	movl	-40(%rbp), %eax
	andl	$15, %eax
	movl	%eax, %eax
	movl	%eax, %ecx
	movb	-32(%rbp,%rcx), %dl
	movb	%dl, -49(%rbp)
	movq	-48(%rbp), %rcx
	cmpl	$-1, (%rcx)
	je	LBB2_7
## %bb.6:
	movl	$1, %edi
	leaq	-49(%rbp), %rsi
	movl	$1, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB2_8
LBB2_7:
	movq	-48(%rbp), %rax
	movl	$-1, (%rax)
	movl	$-1, -36(%rbp)
	jmp	LBB2_9
LBB2_8:
	movq	-48(%rbp), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	movq	-48(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -36(%rbp)
LBB2_9:
	movl	-36(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	jne	LBB2_11
## %bb.10:
	movl	-76(%rbp), %eax         ## 4-byte Reload
	addq	$80, %rsp
	popq	%rbp
	retq
LBB2_11:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"0123456789abcdef"

L_.str.1:                               ## @.str.1
	.asciz	"0123456789ABCDEF"


.subsections_via_symbols
