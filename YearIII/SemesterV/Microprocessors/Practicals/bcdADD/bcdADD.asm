; Perform BCD addition on two 32-bit numbers.
; 12345678H + 94562145H
.MODEL TINY
.486
.CODE
.STARTUP

; initialize registers
MOV EBX, 12345678H    ; BH  = 56H   BL = 78H
MOV EDX, 94562145H    ; DH  = 21H   DL = 45H

; perform ADDition
ADD DL, BL            ; DL  = 45H + 78H = BDH

; perform Decimal Adjust after Addition
MOV AL, DL            ; AL  = BDH
DAA                   ; AL  = 23H   C = 1

; store result in ECX(CL)
MOV CL, AL            ; CL  = 23H   ECX = 00000023H

; perform ADdition with Carry
ADC DH, BH            ; DH  = 21H + 56H + 1 = 78H   C = 0

; perform Decimal Adjust after Addition
MOV AL, DH            ; AL  = 78H
DAA                   ; AL  = 78H   C = 0

; store result in ECX(CH)
MOV CH, AL            ; CH  = 43H   ECX = 00007823H

; swap EBX, EDX, ECX to perform calculation on higher bits
BSWAP EBX             ; EBX = 78563412H  BH  = 34H  BL = 12H
BSWAP EDX             ; EDX = 45215694H  DH  = 56H  DL = 94H
BSWAP ECX             ; ECX = 23780000H

; perform ADdition with Carry
ADC DH, BH            ; DH  = 56H + 34H + 0 = 8AH   C = 0

; perform Decimal Adjust after Addition
MOV AL, DH            ; AL  = 8AH
DAA                   ; AL  = 90H   C = 0

; store result in ECX(CH)
MOV CH, AL            ; CH  = 90H   ECX = 23789000H

; perform ADdition with Carry
ADC DL, BL            ; DL  = 94H + 12H + 0 = A6H   C = 0

; perform Decimal Adjust after Addition
MOV AL, DL            ; AL  = A6H
DAA                   ; AL  = 06H   C = 1

; store result in ECX(CL)
MOV CL, AL            ; CL  = 06H   ECX = 23789006H

; swap ECX to get final result
BSWAP ECX             ; ECX = 06907823H
.EXIT
END