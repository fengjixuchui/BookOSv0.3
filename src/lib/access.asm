[bits 32]
[section .text]

INT_VECTOR_SYS_CALL equ 0x80

_NR_ACCESS EQU 28

global access
access:
	mov eax, _NR_ACCESS
	mov ebx, [esp + 4]
	mov ecx, [esp + 8]
	int INT_VECTOR_SYS_CALL
	ret