	.file	"main.c"
	.text
.Ltext0:
	.globl	main
	.type	main, @function
main:
.LFB6:
	.file 1 "main.c"
	.loc 1 9 1
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	.loc 1 9 1
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 10 16
	movb	$-126, -9(%rbp)
	.loc 1 11 9
	movq	$1, -40(%rbp)
	.loc 1 13 24
	movl	$1, %edi
	call	malloc@PLT
	movq	%rax, -24(%rbp)
	.loc 1 14 9
	movq	$5, -32(%rbp)
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 16 2
	movb	%al, -9(%rbp)
	.loc 1 17 2
	leaq	-32(%rbp), %rdx
	leaq	-40(%rbp), %rcx
	leaq	-9(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	__shift_left_big_num@PLT
	.loc 1 19 9
	movl	$0, %eax
	.loc 1 20 1
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/include/stddef.h"
	.file 3 "/usr/include/stdlib.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x161
	.value	0x5
	.byte	0x1
	.byte	0x8
	.long	.Ldebug_abbrev0
	.uleb128 0x6
	.long	.LASF19
	.byte	0x1d
	.long	.LASF0
	.long	.LASF1
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x1
	.byte	0x8
	.byte	0x5
	.long	.LASF2
	.uleb128 0x7
	.long	.LASF20
	.byte	0x2
	.byte	0xd1
	.byte	0x17
	.long	0x46
	.uleb128 0x8
	.long	0x35
	.uleb128 0x1
	.byte	0x8
	.byte	0x7
	.long	.LASF3
	.uleb128 0x9
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x1
	.byte	0x8
	.byte	0x5
	.long	.LASF4
	.uleb128 0x1
	.byte	0x10
	.byte	0x4
	.long	.LASF5
	.uleb128 0x1
	.byte	0x2
	.byte	0x7
	.long	.LASF6
	.uleb128 0x1
	.byte	0x1
	.byte	0x6
	.long	.LASF7
	.uleb128 0x1
	.byte	0x1
	.byte	0x8
	.long	.LASF8
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.long	.LASF9
	.uleb128 0x1
	.byte	0x1
	.byte	0x6
	.long	.LASF10
	.uleb128 0x1
	.byte	0x2
	.byte	0x5
	.long	.LASF11
	.uleb128 0xa
	.byte	0x8
	.uleb128 0x2
	.long	0x69
	.uleb128 0x1
	.byte	0x8
	.byte	0x7
	.long	.LASF12
	.uleb128 0xb
	.long	.LASF21
	.byte	0x1
	.byte	0x5
	.byte	0x6
	.long	0xb6
	.uleb128 0x3
	.long	0xb6
	.uleb128 0x3
	.long	0xbb
	.uleb128 0x3
	.long	0xc0
	.byte	0
	.uleb128 0x2
	.long	0x70
	.uleb128 0x2
	.long	0x35
	.uleb128 0x2
	.long	0x41
	.uleb128 0xc
	.long	.LASF22
	.byte	0x3
	.value	0x21b
	.byte	0xe
	.long	0x8c
	.long	0xdc
	.uleb128 0x3
	.long	0x35
	.byte	0
	.uleb128 0xd
	.long	.LASF23
	.byte	0x1
	.byte	0x8
	.byte	0x5
	.long	0x4d
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x153
	.uleb128 0x5
	.long	.LASF13
	.byte	0xe
	.long	0x4d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -68
	.uleb128 0x5
	.long	.LASF14
	.byte	0x1b
	.long	0x153
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x4
	.long	.LASF15
	.byte	0xa
	.byte	0x10
	.long	0x158
	.uleb128 0x2
	.byte	0x91
	.sleb128 -25
	.uleb128 0x4
	.long	.LASF16
	.byte	0xb
	.byte	0x9
	.long	0x35
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x4
	.long	.LASF17
	.byte	0xd
	.byte	0x11
	.long	0xb6
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x4
	.long	.LASF18
	.byte	0xe
	.byte	0x9
	.long	0x35
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.uleb128 0x2
	.long	0x8e
	.uleb128 0xe
	.long	0x70
	.uleb128 0xf
	.long	0x46
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.file 0 "/home/foralost/code/algorithms_training/asm-big-mult" "main.c"
	.section	.debug_str,"MS",@progbits,1
.LASF4:
	.string	"long long int"
.LASF19:
	.string	"GNU C17 11.1.0 -mtune=generic -march=x86-64 -g"
.LASF15:
	.string	"numb"
.LASF20:
	.string	"size_t"
.LASF17:
	.string	"dest"
.LASF23:
	.string	"main"
.LASF18:
	.string	"places"
.LASF16:
	.string	"size_num"
.LASF3:
	.string	"long unsigned int"
.LASF12:
	.string	"long long unsigned int"
.LASF8:
	.string	"unsigned char"
.LASF7:
	.string	"char"
.LASF2:
	.string	"long int"
.LASF13:
	.string	"argc"
.LASF6:
	.string	"short unsigned int"
.LASF10:
	.string	"signed char"
.LASF14:
	.string	"argv"
.LASF5:
	.string	"long double"
.LASF11:
	.string	"short int"
.LASF21:
	.string	"__shift_left_big_num"
.LASF9:
	.string	"unsigned int"
.LASF22:
	.string	"malloc"
	.section	.debug_line_str,"MS",@progbits,1
.LASF1:
	.string	"/home/foralost/code/algorithms_training/asm-big-mult"
.LASF0:
	.string	"main.c"
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
