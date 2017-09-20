global start

section .text

_start:


	jmp Call_shellcode


shellcode:
	
	pop rsi
	;xor rax, rax
	;mov al, 1
	mov rax, 1
	;xor rdi, rdi
	mov rdi, 1
	;mov dil, 1
	mov rdx, 35
	;mov dl, 35
	syscall

	xor rax, rax
	mov al, 60
	xor rdi, rdi
	mov dil, 11
	syscall


Call_shellcode:
	call shellcode
	hello_world: db "Hello World to the SLAE-64 Course",0xa
