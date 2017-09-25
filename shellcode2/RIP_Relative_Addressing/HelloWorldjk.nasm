global start

section .text

_start:
	jmp _realstart
	hello_world: db "Hello SLAE-64",0xa

_realstart:

	;print to screen

	xor rax, rax
	add rax, 1
	xor rdi, rdi
	add rdi, 1
	lea rsi, [rel hello_world]
	mov rdx, 15
	syscall

	;exit gracefully
	xor rax, rax
	add rax, 60
	xor rdi, rdi
	add rdi, 11
	syscall


