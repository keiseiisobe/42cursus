	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_if_char                ## -- Begin function if_char
	.p2align	4, 0x90
_if_char:                               ## @if_char
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	(%rdi), %eax
	cmpl	$40, %eax
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	ja	LBB0_2
## %bb.1:
	movl	-28(%rbp), %eax         ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-24(%rbp), %rdx         ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -40(%rbp)         ## 8-byte Spill
	jmp	LBB0_3
LBB0_2:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -40(%rbp)         ## 8-byte Spill
LBB0_3:
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movl	(%rax), %ecx
	movl	%ecx, -12(%rbp)
	leaq	-12(%rbp), %rax
	movl	$1, %edi
	movq	%rax, %rsi
	movl	$1, %edx
	callq	_write
	movl	%eax, %ecx
	movl	%ecx, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_if_char_p              ## -- Begin function if_char_p
	.p2align	4, 0x90
_if_char_p:                             ## @if_char_p
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movl	(%rdi), %eax
	cmpl	$40, %eax
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	ja	LBB1_2
## %bb.1:
	movl	-44(%rbp), %eax         ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-40(%rbp), %rdx         ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -56(%rbp)         ## 8-byte Spill
	jmp	LBB1_3
LBB1_2:
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -56(%rbp)         ## 8-byte Spill
LBB1_3:
	movq	-56(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB1_7
## %bb.4:
	movl	$1, %edi
	leaq	L_.str(%rip), %rsi
	movl	$6, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB1_6
## %bb.5:
	movl	$-1, -4(%rbp)
	jmp	LBB1_13
LBB1_6:
	movl	$6, -4(%rbp)
	jmp	LBB1_13
LBB1_7:
	movl	$0, -20(%rbp)
LBB1_8:                                 ## =>This Inner Loop Header: Depth=1
	movq	-32(%rbp), %rax
	movl	-20(%rbp), %ecx
	movl	%ecx, %edx
	cmpb	$0, (%rax,%rdx)
	je	LBB1_12
## %bb.9:                               ##   in Loop: Header=BB1_8 Depth=1
	movq	-32(%rbp), %rax
	movl	-20(%rbp), %ecx
	movl	%ecx, %edx
	addq	%rdx, %rax
	movl	$1, %edi
	movq	%rax, %rsi
	movl	$1, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB1_11
## %bb.10:
	movl	$-1, -4(%rbp)
	jmp	LBB1_13
LBB1_11:                                ##   in Loop: Header=BB1_8 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB1_8
LBB1_12:
	movl	-20(%rbp), %eax
	movl	%eax, -4(%rbp)
LBB1_13:
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_if_void_p              ## -- Begin function if_void_p
	.p2align	4, 0x90
_if_void_p:                             ## @if_void_p
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -16(%rbp)
	movl	$0, -28(%rbp)
	leaq	-28(%rbp), %rdi
	movq	%rdi, -40(%rbp)
	movq	-16(%rbp), %rdi
	movl	(%rdi), %eax
	cmpl	$40, %eax
	movq	%rdi, -48(%rbp)         ## 8-byte Spill
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	ja	LBB2_2
## %bb.1:
	movl	-52(%rbp), %eax         ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-48(%rbp), %rdx         ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -64(%rbp)         ## 8-byte Spill
	jmp	LBB2_3
LBB2_2:
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -64(%rbp)         ## 8-byte Spill
LBB2_3:
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	movl	$1, %edi
	leaq	L_.str.1(%rip), %rsi
	movl	$2, %edx
	callq	_write
	cmpq	$0, %rax
	jge	LBB2_5
## %bb.4:
	movl	$-1, -4(%rbp)
	jmp	LBB2_6
LBB2_5:
	movl	-28(%rbp), %eax
	addl	$2, %eax
	movl	%eax, -28(%rbp)
	movq	-24(%rbp), %rdi
	movq	-40(%rbp), %rsi
	callq	_ft_put_address
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -4(%rbp)
LBB2_6:
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_if_decimal             ## -- Begin function if_decimal
	.p2align	4, 0x90
_if_decimal:                            ## @if_decimal
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
	ja	LBB3_2
## %bb.1:
	movl	-36(%rbp), %eax         ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	jmp	LBB3_3
LBB3_2:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -48(%rbp)         ## 8-byte Spill
LBB3_3:
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movl	(%rax), %ecx
	movl	%ecx, -12(%rbp)
	movl	-12(%rbp), %edi
	movq	-24(%rbp), %rsi
	callq	_ft_put_int
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"(null)"

L_.str.1:                               ## @.str.1
	.asciz	"0x"


.subsections_via_symbols
