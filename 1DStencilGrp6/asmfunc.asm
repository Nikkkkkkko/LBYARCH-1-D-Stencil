section .data
section .text
default rel
global stencilAsm
extern printf
stencilAsm:
	
	; Process:  y[i] = x[i-3] + x[i-2] + x[i-1] + x[i] + x[i+1]+ x[i+2] +x[i+3]

	; rcx = n, rdx = X* ,r8 = Y* ,r9 = z
	; stencilAsm(n, Xasm, Yasm, z);

	xor rbx, rbx ;; k = 0
	xor rax, rax ;; l = 0
	xor r11, r11 ;; j = 0
	xor r10, r10 ;; k+7
	xor r12, r12 
	xor r13, r13 
	xor r14, r14 
	xor r15, r15 
	xor rdi, rdi  
	xor r9, r9

	OUTER:

		cmp rbx, rcx ;; k < n
		jge OUTER_END

		movss xmm0, [rdx + rax*4] ;; xmm0 = X[0] = 1
			
		mov r11, rax
		mov r12, rax
		mov r13, rax
		mov r14, rax
		mov r15, rax
		mov rdi, rax


		add r11,1
		addss xmm0, [rdx + r11*4] ;; 1 + 2 
		add r12,2
		addss xmm0, [rdx + r12*4] ;; 1 + 2 
		add r13,3
		addss xmm0, [rdx + r13*4] ;; 1 + 2 
		add r14,4
		addss xmm0, [rdx + r14*4] ;; 1 + 2 
		add r15,5
		addss xmm0, [rdx + r15*4] ;; 1 + 2 
		add rdi,6
		addss xmm0, [rdx + rdi*4] ;; 1 + 2
			

		movss [r8 + rax*4], xmm0 ;; Y[l] = X[j]
		inc rax
		loop OUTER

	OUTER_END:
		
		xor rax, rax
		ret