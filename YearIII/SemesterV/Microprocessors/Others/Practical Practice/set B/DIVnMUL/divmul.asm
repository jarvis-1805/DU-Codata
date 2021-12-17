; Write a program that divides the number in CL by the number in BL and then multiply the
; result by 4. The final answer must be a 16-bit number stored the DX register.
.MODEL SMALL
.STACK
.CODE
.STARTUP

MOV CL, 04H
MOV BL, 02H
MOV AL, CL
DIV BL
MOV CL, 04H
MUL CL
MOV DX, AX

.EXIT
END