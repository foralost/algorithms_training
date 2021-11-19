.section .text
.global __shift_left_big_num
# RDI	<- NUM
# RSI 	<- SIZE
# RDX	<- N
# RCX <- NEW_SIZE
__shift_left_big_num:
	push %rbp
	mov %rsp, %rbp 
	sub $128, %rsp 
	
	mov %rdi, -8(%rbp)
	mov %rsi, -16(%rbp)
	mov %rdx, -24(%rbp)
	mov %rcx, -120(%rbp)
__check_last_bits:
	mov (%rsi), %rsi
	dec %rsi
	mov (%rdi, %rsi, 1), %al
	xor %rcx, %rcx 
__check_last_bits_cmp:
	cmp $0, %al
	je __check_last_bits_end
	shr $1, %al 
	inc %rcx 
	jmp __check_last_bits_cmp 
__check_last_bits_end:
	sub $8, %rcx
	xor $-1, %rcx
	inc %rcx
	mov (%rdx), %rdx
	mov %rdx, %rax 
	shr $3, %rdx 	# liczba dodatkowych bajtów
	mov %rdx, -32(%rbp)

	and $7, %rax 
	movq $0, -40(%rbp)
	cmp %rcx, %rax 
	jle __check_last_bits_fin
	movq $1, -40(%rbp) 
__check_last_bits_fin:
	mov %rdx, -48(%rbp) # LICZBA DODATKOWYCH BAJTÓW
__assign_memory:
	inc %rsi 
	add -40(%rbp), %rdx
	add %rsi, %rdx
	mov $1, %rsi
	mov %rdx, -112(%rbp)
	mov %rdx, %rdi 
	call calloc
	mov %rax, -56(%rbp) # DESTINATION ADDRESS
__copy_mem:
	mov %rax, %r8
	xor %rcx, %rcx
	mov -8(%rbp), %rdi  
	mov -16(%rbp), %rsi
	mov (%rsi), %rsi 
	mov -32(%rbp), %rbx 
__copy_mem_cmp:
	cmp %rcx, %rsi
	je __create_non_carry
	mov (%rdi, %rcx, 1), %al
	mov %al, (%r8, %rbx, 1) 
	inc %rcx
	inc %rbx 
	jmp __copy_mem_cmp 
__create_non_carry:
	clc 
	pushf
	mov (%rsp), %rcx
	mov %rcx, -64(%rbp)
	popf
__start_shift:
	mov -40(%rbp), %r8 
	mov -16(%rbp), %rsi
	mov -56(%rbp), %r10
	mov (%rsi), %rsi 
	add %rsi, %r8 
	mov -24(%rbp), %rdx 
	mov (%rdx), %rdx
	mov -32(%rbp), %r9
	xor %rcx, %rcx
	
	shl $3, %r9
	sub %r9, %rdx
	shr $3, %r9 
__start_shift_cmp:
	cmp %rcx, %rdx  
	je __start_shift_end 
	xor %rax, %rax
__do_shift_cmp:
	cmp %rax, %r8
	je __do_shift_cmp_end 
	mov (%r10, %r9, 1), %bl
	shl %bl 

	pushf 
	mov (%rsp), %r11
	mov %r11, -72(%rbp) 
	
	mov -64(%rbp), %r11
	mov %r11, (%rsp)

	popf

	adc $0, %bl  
	
	mov %bl, (%r10, %r9, 1)	

	mov -72(%rbp), %r11
	mov %r11, -64(%rbp)	
	
	inc %r9 	
	inc %rax
	jmp __do_shift_cmp 
__do_shift_cmp_end:	
	inc %rcx
	xor %r9, %r9
	jmp __start_shift_cmp 
__start_shift_end:
	mov -112(%rbp), %rdi
	mov -120(%rbp), %rsi  
	mov %rdi, (%rsi) 	
	# END - PRZESUWANIE
	mov %r10, %rax
	mov %rbp, %rsp	
	pop %rbp
	ret
