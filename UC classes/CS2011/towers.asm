.ORIG x3000
LD R6, STACK_PTR

; Start the Hanoi solver with 3 disks from post 1 to post 3
AND R0, R0, #0
ADD R0, R0, #3      ; n = 3
AND R1, R1, #0
ADD R1, R1, #1      ; from_post = 1
AND R2, R2, #0
ADD R2, R2, #3      ; to_post = 3

; Push arguments in reverse: to_post, from_post, n
ADD R6, R6, #-1
STR R2, R6, #0
ADD R6, R6, #-1
STR R1, R6, #0
ADD R6, R6, #-1
STR R0, R6, #0

JSR HANOI
HALT

; -------------------------------------------------------------------
; HANOI subroutine (recursive)
; expects: n (R0), from_post (R1), to_post (R2)
; temporary: uses R3 for temp post
HANOI
    ; Save return address
    ADD R6, R6, #-1
    STR R7, R6, #0

    ; Compute temp_post = 6 - from_post - to_post
    AND R3, R3, #0
    ADD R3, R3, #6
    NOT R4, R1
    ADD R4, R4, #1
    ADD R3, R3, R4
    NOT R4, R2
    ADD R4, R4, #1
    ADD R3, R3, R4

    ADD R0, R0, #0      ; Check if n == 1
    ADD R4, R0, #-1
    BRz BASE_CASE

    ; Recursive call: HANOI(n-1, from, temp)
    ADD R0, R0, #-1
    ADD R6, R6, #-1
    STR R2, R6, #0      ; to = temp
    ADD R6, R6, #-1
    STR R1, R6, #0      ; from
    ADD R6, R6, #-1
    STR R0, R6, #0      ; n-1
    JSR HANOI
    ADD R0, R0, #1      ; restore n

    ; MOVE_DISK(n, from, to)
    ADD R6, R6, #-1
    STR R0, R6, #0
    ADD R6, R6, #-1
    STR R1, R6, #0
    ADD R6, R6, #-1
    STR R2, R6, #0
    JSR MOVE_DISK

    ; Recursive call: HANOI(n-1, temp, to)
    ADD R0, R0, #-1
    ADD R6, R6, #-1
    STR R2, R6, #0      ; to
    ADD R6, R6, #-1
    STR R3, R6, #0      ; from = temp
    ADD R6, R6, #-1
    STR R0, R6, #0      ; n-1
    JSR HANOI
    ADD R0, R0, #1      ; restore n

    ; Restore return address and return
    LDR R7, R6, #0
    ADD R6, R6, #1
    RET

; -------------------------------------------------------------------
BASE_CASE
    ; Print "Move disk n from post a to post b"
    ADD R6, R6, #-1
    STR R0, R6, #0
    ADD R6, R6, #-1
    STR R1, R6, #0
    ADD R6, R6, #-1
    STR R2, R6, #0
    JSR PSOLSTEP
    ADD R6, R6, #3
    LDR R7, R6, #0
    ADD R6, R6, #1
    RET

; -------------------------------------------------------------------
MOVE_DISK
    ; Print "Move disk n from post a to post b"
    ADD R6, R6, #-1
    STR R0, R6, #0
    ADD R6, R6, #-1
    STR R1, R6, #0
    ADD R6, R6, #-1
    STR R2, R6, #0
    JSR PSOLSTEP
    ADD R6, R6, #3
    RET

; -------------------------------------------------------------------
; PSOLSTEP - Print solution step
; Stack:
;   R6+4 → disk #
;   R6+3 → from post
;   R6+2 → to post
PSOLSTEP
    ADD R6, R6, #-1
    STR R7, R6, #0

    LDR R0, R6, #4      ; disk
    LDR R1, R6, #3      ; from
    LDR R2, R6, #2      ; to

    ; Disk
    LEA R3, moveDisk
    LD R4, hex30
    ADD R5, R0, R4
    STR R5, R3, #10
    LEA R0, moveDisk
    PUTS

    ; From
    LEA R3, fromPost
    LD R4, hex30
    ADD R5, R1, R4
    STR R5, R3, #10
    LEA R0, fromPost
    PUTS

    ; To
    LEA R3, toPost
    LD R4, hex30
    ADD R5, R2, R4
    STR R5, R3, #8
    LEA R0, toPost
    PUTS

    ; Restore and return
    LDR R7, R6, #0
    ADD R6, R6, #1
    RET

; -------------------------------------------------------------------
; Data
moveDisk .STRINGZ "Move disk n"
fromPost .STRINGZ " from post n"
toPost   .STRINGZ " to post n\n"
hex30    .FILL x0030
STACK_PTR .FILL x4000
.END
