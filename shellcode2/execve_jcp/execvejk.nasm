global start

section .text

_start:


	;execve system call

	; first null push on stack
	xor rax, rax
	push rax

	;push hexed '/bin//sh' in reverse order, use python interactive to create string
	mov rbx, 0x68732f2f6e69622f
	push rbx

	; store /bin//sh address in RSI
	mov rdi, rsp

	; second null push
	push rax

	;set RDX to the address location of the second null
	mov rdx, rsp

	;push address of /bin//sh
	push rdi

	;set RSI
	mov rsi, rsp

	;call the execve syscall
	add rax, 59
	syscall


