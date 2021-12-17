; Using four 16 bit register add two 32-bit number.
; 1100 A111 + 0010 B000
.MODEL TINY
.CODE
.STARTUP

; move 2-LSB bytes of first number in AX and
; 2-MSB bytes of first number in BX and
; 2-LSB bytes of second number in CX and
; 2-MSB bytes of second number in DX
MOV AX, 0A111H    ;       1              carry
MOV BX, 1100H     ; 1 1 0 0  A 1 1 1     BX      AX
MOV CX, 0B000H    ; 0 0 1 0  B 0 0 0     DX      CX
MOV DX, 0010H     ; 1 1 1 1  5 1 1 1     BX      AX    result

; perform ADDition on 2-LSB bytes of first and second number, i.e., AX = AX + CX
ADD AX, CX

; perform ADition with Carry on 2-MSB bytes of first and second number, i.e., BX = BX + DX
ADC BX, DX    ; final answer is stored in register BX AX, i.e., 1111 5111
.EXIT
END