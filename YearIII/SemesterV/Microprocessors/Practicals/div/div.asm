; Perform 32 bit division (user input)
; 1234 1234 4321 4321 ÷ AAAA BBBB = 1B4E 1893 Remainder : 5583 EEC0
.MODEL SMALL
.stack
.486
.DATA

divisor dd ?
remainder dd ?
quotient dd ?
msg db 13, 10, "Enter the first number(divisor 32-bit): $"
msg1 db 13, 10, "Enter the second number(dividend 64-bit): $"
msg2 db 13, 10, "Quotient(32-bit): $"
msg3 db 13, 10, "Remainder(32-bit): $"
msg4 db 13, 10, "Divisor(32-bit): $"

.CODE
.STARTUP

; taking input 32-bit number (divisor)
MOV DX, OFFSET msg
MOV AH, 9
INT 21H

; initialize EBX to 0 to store the divisor
MOV EBX, 0

; store counter 4 in CX for 32-bit number (1 byte at a time)
MOV CX, 4
startInput1:
    SHL EBX, 8

    MOV SI, CX
    MOV DI, 2       ; to take input 4-bits at a time
    MOV CX, DI
    ; take input the 1st digit of first number(4-MSB of 1 byte)
    startDigitInput1:
        MOV AH, 1
        INT 21H     ; entered digit is stored in AL in HEXA, i.e., for 0 => 30H and A => 41H

        ; check if number is entered or alphabet is entered
        CMP AL, 39H     ; 39H => 9
        JBE ab1         ; jump to ab1 if entered value is a number
        SUB AL, 37H     ; else convert to alphabet

        ; store the number in EBX register
        ab1:
        AND AL, 0FH     ; convert the hexa value of input number/alphabet to number/alphabet
        CMP CX, 1       ; check whether to store number in one's or ten's place
        JE ab2
        SHL AL, 4       ; shift the number/alphabet to ten's place
        MOV BL, AL      ; store the result in EBX(BL)
        MOV AL, 0H

        ab2: ADD BL, AL ; to store number in one's place

    ; take input the 2nd digit of first number(4-LSB of 1 byte)
    LOOP startDigitInput1

    MOV CX, SI
; take input the second number
LOOP startInput1

; store the first 32-bit number (divisor) in ad variable
MOV divisor, EBX

; ----------------------------------------------------------------------------------

; taking input 64-bit number (dividend)
MOV DX, OFFSET msg1
MOV AH, 9
INT 21H

; store counter 4 in CX for 32-bit number
MOV CX, 2       ; to take input 2 times 32-bit
startInput64bit:
    MOV SP, CX
    ; store counter 4 in CX for 32-bit number (1 byte at a time)
    MOV CX, 4
    startInput2:
        SHL EBX, 8

        MOV SI, CX
        MOV DI, 2       ; to take input 4-bits at a time
        MOV CX, DI
        ; take input the 1st digit of first number(4-MSB of 1 byte)
        startDigitInput2:
            MOV AH, 1
            INT 21H     ; entered digit is stored in AL in HEXA, i.e., for 0 => 30H and A => 41H

            ; check if number is entered or alphabet is entered
            CMP AL, 39H     ; 39H => 9
            JBE ab3         ; jump to ab1 if entered value is a number
            SUB AL, 37H     ; else convert to alphabet

            ; store the number in EBX register
            ab3:
            AND AL, 0FH     ; convert the hexa value of input number/alphabet to number/alphabet
            CMP CX, 1       ; check whether to store number in one's or ten's place
            JE ab4
            SHL AL, 4       ; shift the number/alphabet to ten's place
            MOV BL, AL      ; store the result in EBX(BL)
            MOV AL, 0H

            ab4: ADD BL, AL ; to store number in one's place

        ; take input the 2nd digit of first number(4-LSB of 1 byte)
        LOOP startDigitInput2

        MOV CX, SI
    ; take input the second number
    LOOP startInput2

    CMP SP, 1
    JE ab5
    MOV EDX, EBX

    ab5: MOV CX, SP

LOOP startInput64bit

MOV EAX, EBX

MOV EBX, divisor
DIV EBX

MOV remainder, EDX
MOV quotient, EAX

; Printing the divisor

MOV DX,OFFSET MSG4
MOV AH,09
INT 21H

MOV EBX,divisor
MOV CX,4

PRINT1 :ROL EBX,8

    MOV AL,BL
    AND AL,0F0H
    SHR AL,4
    ADD AL,30H

    CMP AL,39H
    JBE AB7

    ADD AL,07H

    AB7:
    MOV DL,AL
    MOV AH,02
    INT 21H


    MOV AL,BL
    AND AL,00FH
    ADD AL,30H

    CMP AL,39H
    JBE AB8

    ADD AL,07H

    AB8:

    MOV DL,AL
    MOV AH,02
    INT 21H

LOOP PRINT1

;Printing the quotient

MOV DX,OFFSET MSG2
MOV AH,09
INT 21H

MOV EBX,quotient
MOV CX,4

PRINT3 :ROL EBX,8

    MOV AL,BL
    AND AL,0F0H
    SHR AL,4
    ADD AL,30H

    CMP AL,39H
    JBE AB11

    ADD AL,07H

    AB11:
    MOV DL,AL
    MOV AH,02
    INT 21H


    MOV AL,BL
    AND AL,00FH
    ADD AL,30H

    CMP AL,39H
    JBE AB12

    ADD AL,07H

    AB12:

    MOV DL,AL
    MOV AH,02
    INT 21H

LOOP PRINT3


;Printing the remainder

MOV DX,OFFSET MSG3
MOV AH,09H
INT 21H

MOV EBX,remainder

MOV CX,4

PRINT2 :ROL EBX,8

    MOV AL,BL
    AND AL,0F0H
    SHR AL,4
    ADD AL,30H

    CMP AL,39H
    JBE AB9

    ADD AL,07H

    AB9:
    MOV DL,AL
    MOV AH,02
    INT 21H

    MOV AL,BL
    AND AL,00FH
    ADD AL,30H

    CMP AL,39H
    JBE AB10

    ADD AL,07H

    AB10:

    MOV DL,AL
    MOV AH,02
    INT 21H

LOOP PRINT2

.EXIT
END