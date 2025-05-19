.ORIG x5000
; TRAP x41 - Output 4-digit hex value using right shift TRAP x42
; Input: R0 - value to display
; Couldn't figure out where the issue was between this file and input as to why it wasn't working right
TRAP41
    ST R0, SAVE_R0       ; Save original value
    ST R1, SAVE_R1       ; Save registers
    ST R2, SAVE_R2
    ST R3, SAVE_R3
    ST R7, SAVE_R7
    
    ; Print leading 'x'
    LD R0, X_CHAR
    OUT
    
    LD R1, SAVE_R0       ; Reload original value
    AND R2, R2, #0       ; Digit counter (4 digits)
    ADD R2, R2, #4
    
OUTPUT_LOOP
    ; Copy current value to R0 for shifting
    ADD R0, R1, #0
    
    ; Right shift 12 times to get leftmost nibble
    AND R3, R3, #0
    ADD R3, R3, #12
SHIFT_LOOP
    TRAP x42             ; Right shift by 1
    ADD R3, R3, #-1
    BRp SHIFT_LOOP
    
    ; Mask to get lowest 4 bits
    AND R0, R0, #15
    
    ; Convert to ASCII
    ADD R0, R0, #-10
    BRn DIGIT_0_9
    LD R0, A_CHAR
    ADD R0, R0, #10
    BRnzp PRINT_DIGIT
    
DIGIT_0_9
    LD R0, ZERO_CHAR
    ADD R0, R0, R1
    
PRINT_DIGIT
    OUT
    
    ; Shift original value left by 4 for next nibble
    AND R3, R3, #0
    ADD R3, R3, #4
SHIFT_LEFT_LOOP
    ADD R1, R1, R1
    ADD R3, R3, #-1
    BRp SHIFT_LEFT_LOOP
    
    ; Next digit
    ADD R2, R2, #-1
    BRp OUTPUT_LOOP
    
    ; Restore registers
    LD R0, SAVE_R0
    LD R1, SAVE_R1
    LD R2, SAVE_R2
    LD R3, SAVE_R3
    LD R7, SAVE_R7
    RET

; Constants
X_CHAR    .FILL x0078    ; 'x'
ZERO_CHAR .FILL x0030    ; '0'
A_CHAR    .FILL x0041    ; 'A'
SAVE_R0   .BLKW 1
SAVE_R1   .BLKW 1
SAVE_R2   .BLKW 1
SAVE_R3   .BLKW 1
SAVE_R7   .BLKW 1
.END