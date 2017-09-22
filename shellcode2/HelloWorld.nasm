global start

section .text

_start:


	;print to screen

	mov rax, 1
	mov rdi, 1
	mov rsi, hello_world
	mov rdx, length
	syscall

	;exit gracefully
	mov rax, 60
	mov rdi, 11
	syscall

section .data

	hello_world: db "Hello World to the SLAE-64 Course",0xa
	length: equ $-hello_world
