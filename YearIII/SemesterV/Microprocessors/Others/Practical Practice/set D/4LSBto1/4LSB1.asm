; WAP to set (1) in the rightmost 4 bits of BX.
.MODEL TINY
.CODE
.STARTUP

MOV BX, 0H
OR BX, 0001H

.EXIT
END