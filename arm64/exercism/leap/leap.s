.text
.globl leap_year

leap_year:
        MOV x1, x0
        // Check Divisibility by 4:
        TST x1, #3 
        B.NE .done // If not divisible by 4 (B.NE), immediately return 0.

        // Check Divisibility by 100:
        MOV x2, #100
        UDIV x3, x1, x2
        MUL x5, x3, x2
        SUB x4, x1, x5
        CMP x4, #0
        B.NE is_leap_year // If not divisible by 100 (B.NE), it's a standard leap year! Return 1

        // Check Divisibility by 400 (Only reached if it is divisible by 100)
        MOV x2, #400
        UDIV x3, x1, x2
        MUL x5, x3, x2
        SUB x4, x1, x5
        CMP x4, #0
        B.NE .done
is_leap_year:
        MOV x0, #1
        ret
.done:
        MOV x0, #0
        ret
