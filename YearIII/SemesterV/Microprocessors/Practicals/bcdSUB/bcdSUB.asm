; Perform BCD subtraction on two 32-bit numbers.
; 45218907H - 37829156H
.MODEL TINY
.486
.CODE
.STARTUP

; initialize registers
MOV EBX, 37829156H    ; BH  = 91H   BL = 56H
MOV EDX, 45218907H    ; DH  = 89H   DL = 07H

; perform SUBtraction
SUB DL, BL            ; DL  = 07H - 56H = B1H

; perform Decimal Adjust after Subtraction
MOV AL, DL            ; AL  = B1H
DAS                   ; AL  = 51H   C = 1

; store result in ECX(CL)
MOV CL, AL            ; CL  = 51H   ECX = 00000051H

; perform SuBtraction with Borrow
SBB DH, BH            ; DH  = 89H - 91H - 1 = F7H   C = 1

; perform Decimal Adjust after Subtraction
MOV AL, DH            ; AL  = F7H
DAS                   ; AL  = 97H   C = 1

; store result in ECX(CH)
MOV CH, AL            ; CH  = 97H   ECX = 00009751H

; swap EBX, EDX, ECX to perform calculation on higher bits
BSWAP EBX             ; EBX = 56918237H  BH  = 82H  BL = 37H
BSWAP EDX             ; EDX = B1F72145H  DH  = 21H  DL = 45H
BSWAP ECX             ; ECX = 51970000H

; perform SuBtraction with Borrow
SBB DH, BH            ; DH  = 21H - 82H - 1 = 9EH   C = 1

; perform Decimal Adjust after Subtraction
MOV AL, DH            ; AL  = 9EH
DAS                   ; AL  = (9|3)8H   C = 1

; store result in ECX(CH)
MOV CH, AL            ; CH  = (9|3)8H   ECX = 5197(9|3)800H

; perform SuBtraction with Borrow
SBB DL, BL            ; DL  = 45H - 37H - 1 = 0DH   C = 0

; perform Decimal Adjust after Subtraction
MOV AL, DL            ; AL  = 0DH
DAS                   ; AL  = 07H   C = 0

; store result in ECX(CL)
MOV CL, AL            ; CL  = 07H   ECX = 5197(9|3)807H

; swap ECX to get final result
BSWAP ECX             ; ECX = 07(9|3)89751H
.EXIT
END