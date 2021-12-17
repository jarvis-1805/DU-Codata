;32 bit binary multiplication
.model small
.stack
.486
.data

ad dd ?
ad1 dd ?
msg db 13,10,"Enter the first number(32 Bit): $"
msg1 db 13,10,"Enter the second number(32 Bit): $"
msg2 db 13,10,"Product: $"


.code
.startup

;input of 32 bit no.

mov dx,offset msg
mov ah,09
int 21h


mov ebx,0
mov cx,4
abc: shl ebx,8

;1st DIGIT OF FIRST NO.

mov ah,01
int 21h

cmp al,39h
jbe ab1

sub al,37h

ab1:
and al,00fh
shl al,4
mov bl,al

;2nd  DIGIT OF FIRST NO.

mov ah,01
int 21h

cmp al,39h
jbe ab2

sub al,37h

ab2:
and al,00fh
add bl,al

loop abc

mov ad,ebx

;input of  second 32 bit no.

mov dx,offset msg1
mov ah,09
int 21h

mov ebx,0
mov cx,4
abc1: shl ebx,8

;1st DIGIT OF FIRST NO.

mov ah,01
int 21h

cmp al,39h
jbe ab3

sub al,37h

ab3:
and al,00fh
shl al,4
mov bl,al

;2nd  DIGIT OF FIRST NO.

mov ah,01
int 21h

cmp al,39h
jbe ab4

sub al,37h

ab4:
and al,00fh
add bl,al

loop abc1

mov eax,ad

mul ebx

mov ad,eax
mov ad1,edx


; printing 

mov dx,offset msg2
mov ah,09
int 21h

mov ebx,ad1
mov cx,4

abc3 :rol ebx,8

mov al,bl
and al,0f0h
shr al,4
add al,30h

cmp al,39h
jbe ab5

add al,07h

ab5:
mov dl,al
mov ah,02
int 21h


mov al,bl
and al,00fh
add al,30h

cmp al,39h
jbe ab6

add al,07h

ab6:

mov dl,al
mov ah,02
int 21h

loop abc3


; printing 

mov ebx,ad
mov cx,4

abc4 :rol ebx,8

mov al,bl
and al,0f0h
shr al,4
add al,30h

cmp al,39h
jbe ab7

add al,07h

ab7:
mov dl,al
mov ah,02
int 21h

mov al,bl
and al,00fh
add al,30h

cmp al,39h
jbe ab8

add al,07h

ab8:

mov dl,al
mov ah,02
int 21h

loop abc4

.exit
End
