.equ INVALID_NUMBER, -1
.text
.globl steps
steps:
        CMP x0, 0
        B.LE exit 
        MOV x1, x0
        MOV x2, #3
        MOV x3, #0
loop:
        CMP x1, #1
        B.EQ done
        TST x1, #1
        B.EQ handle_even
        B handle_odd
handle_even:
        LSR x1, x1, #1
        ADD x3, x3, #1
        B loop
handle_odd:
        MUL x1, x1, x2
        ADD x1, x1, #1
        ADD x3, x3, #1
        B loop
exit:
        MOV x0, #-1
        MOV x3, x0
        ret
done:
        MOV x0, x3
        ret