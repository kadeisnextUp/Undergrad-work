.ORIG x4000
; TRAP x40 - Input 4-digit hex value
; Returns value in R0 (or x0000 if invalid)
INPUT_HEX
    ST R1, SAVE_R1
    ST R2, SAVE_R2
    ST R3, SAVE_R3
    ST R4, SAVE_R4
    ST R5, SAVE_R5
    ST R7, SAVE_R7
    
    AND R0, R0, #0      ; Clear result
    AND R2, R2, #0      ; Character counter
    ADD R2, R2, #4      ; We need exactly 4 characters
    
INPUT_LOOP
    GETC                ; Read character
    OUT                 ; Echo character
    
    ; Check for Enter (shouldn't happen until 4 chars)
    ADD R1, R0, #-10
    BRz INVALID_INPUT
    
    ; Convert ASCII to hex digit
    JSR CONVERT_DIGIT
    ADD R5, R5, #0      ; Check if valid
    BRn INVALID_INPUT   ; Invalid digit
    
    ; Shift and add digit
    JSR COMBINE_DIGIT
    
    ; Next character
    ADD R2, R2, #-1
    BRp INPUT_LOOP
    
    ; Success - value is in R0
    BRnzp INPUT_DONE
    
INVALID_INPUT
    AND R0, R0, #0      ; Return x0000
    
INPUT_DONE
    LD R1, SAVE_R1
    LD R2, SAVE_R2
    LD R3, SAVE_R3
    LD R4, SAVE_R4
    LD R5, SAVE_R5
    LD R7, SAVE_R7
    RET

; Subroutine: Convert ASCII character to hex digit
; Input: R0 - ASCII character
; Output: R5 - hex value (0-15) or -1 if invalid
CONVERT_DIGIT
    AND R5, R5, #0      ; Clear result
    
    LD R3, ASCII_0_OFFSET
    ADD R1, R0, R3      ; R1 = R0 - '0'
    BRn INVALID_DIGIT   ; If less than '0', invalid
    ADD R1, R1, #-10
    BRn IS_DIGIT        ; If 0-9, valid

    LD R3, ASCII_A_OFFSET
    ADD R1, R0, R3      ; R1 = R0 - 'A'
    BRn INVALID_DIGIT
    ADD R1, R1, #-6
    BRp IS_UPPER        ; If A-F, valid

    LD R3, ASCII_a_OFFSET
    ADD R1, R0, R3      ; R1 = R0 - 'a'
    BRn INVALID_DIGIT
    ADD R1, R1, #-6
    BRn IS_LOWER        ; If a-f, valid

    BRnzp INVALID_DIGIT

IS_DIGIT
    LD R3, ASCII_0_OFFSET
    ADD R5, R0, R3      ; Convert to 0-9
    BRnzp DIGIT_DONE

IS_UPPER
    LD R3, ASCII_A_OFFSET
    ADD R5, R0, R3      ; Convert to 10-15
    BRnzp DIGIT_DONE

IS_LOWER
    LD R3, ASCII_a_OFFSET
    ADD R5, R0, R3      ; Convert to 10-15

DIGIT_DONE
    RET

INVALID_DIGIT
    AND R5, R5, #0      ; Return -1 for invalid
    ADD R5, R5, #-1
    RET

; Subroutine: Shift and add digit to accumulated value
; Input: R0 - current value, R5 - new digit (0-15)
; Output: R0 - updated value
COMBINE_DIGIT
    ST R1, SAVE_R1_TMP
    ST R2, SAVE_R2_TMP
    
    ; Shift left by 4 bits (multiply by 16)
    AND R1, R1, #0
    ADD R1, R1, #4      ; Counter for 4 shifts


SHIFT_LOOP
    ADD R0, R0, R0      ; Shift left
    ADD R1, R1, #-1
    BRp SHIFT_LOOP
    
    ; add new digit
    ADD R0, R0, R5
    
    LD R1, SAVE_R1_TMP
    LD R2, SAVE_R2_TMP
    RET

; variables
ASCII_0_OFFSET .FILL #-48    ; ASCII '0'
ASCII_A_OFFSET .FILL #-55    ; ASCII 'A' - 10

SAVE_R1    .BLKW 1
SAVE_R2    .BLKW 1
SAVE_R3    .BLKW 1
SAVE_R4    .BLKW 1
SAVE_R5    .BLKW 1
SAVE_R7    .BLKW 1
SAVE_R1_TMP .BLKW 1
SAVE_R2_TMP .BLKW 1
.END
