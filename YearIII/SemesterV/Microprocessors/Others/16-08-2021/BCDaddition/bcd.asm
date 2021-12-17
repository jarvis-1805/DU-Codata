; Perform BCD addition on two 16-bit numbers.
.MODEL TINY
.CODE
.STARTUP
MOV BX, 1234H    ; BH = 12H   BL = 34H
MOV DX, 3099H    ; DH = 30H   DL = 99H
ADD DL, BL       ; DL = 99H + 34H = CDH
MOV AL, DL       ; AL = CDH
DAA              ; AL = 33H   C = 1
MOV CL, AL       ; CL = 33H   CX = 0033H
ADC DH, BH       ; DH = 30H + 12H + 1 = 43H   C = 0
MOV AL, DH       ; AL = 43H
DAA              ; AL = 43H
MOV CH, AL       ; CH = 43H   CX = 4333H
.EXIT
END