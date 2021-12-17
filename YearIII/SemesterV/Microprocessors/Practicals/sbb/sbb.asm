; Using four 16 bit register subtract two 32-bit number.
; 1100 A111 - 0010 B000
.MODEL TINY
.CODE
.STARTUP

; move 2-LSB bytes of first number in AX and
; 2-MSB bytes of first number in BX and
; 2-LSB bytes of second number in DI and
; 2-MSB bytes of second number in SI
MOV AX, 0A111H    ;   0 F F  16          borrow
MOV BX, 1100H     ; 1 1 0 0  A 1 1 1     BX      AX
MOV DI, 0B000H    ; 0 0 1 0  B 0 0 0     SI      DI
MOV SI, 0010H     ; 1 0 E F  F 1 1 1     BX      AX    result

; perform SUBtraction on 2-LSB bytes of first and second number, i.e., AX = AX + DI
SUB AX, DI

; perform SuBtraction with Borrow on 2-MSB bytes of first and second number, i.e., BX = BX + SI
SBB BX, SI    ; final answer is stored in register BX AX, i.e., 10EF F111
.EXIT
END