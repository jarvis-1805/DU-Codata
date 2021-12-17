; Write a program that loads SI with address of DATA1 and DI with the address of DATA2.
; Then exchange the content of these memory location.
; (Make use of LEA and OFFSET directive)
.MODEL SMALL
.DATA
DATA1 DW 5000H
DATA2 DW 7000H
.CODE
.STARTUP
LEA SI, DATA1
MOV DI, OFFSET DATA2
MOV BX, [SI]
MOV DX, [DI]
MOV [SI], DX
MOV [DI], BX
.EXIT
END