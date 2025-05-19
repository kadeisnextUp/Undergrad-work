.ORIG x3000
MAIN
    ; get starting address
    LEA R0, START_PROMPT
    PUTS
    TRAP x40
    ST R0, START_ADDR
    
    LD R0, NEWLINE
    OUT
    ; get ending address
    LEA R0, END_PROMPT
    PUTS
    TRAP x40
    ST R0, END_ADDR
    
    ; validate addresses
    LD R1, START_ADDR
    LD R2, END_ADDR
    NOT R3, R2
    ADD R3, R3, #1     ; Two's complement of end
    ADD R3, R1, R3    
    BRnz ADDR_VALID
    
    ; swap if start > end
    ST R1, END_ADDR
    ST R2, START_ADDR
    
ADDR_VALID
    ; display header
    LEA R0, MEM_HEADER
    PUTS
    LD R0, START_ADDR
    TRAP x41
    LEA R0, TO_STRING
    PUTS
    LD R0, END_ADDR
    TRAP x41
    LEA R0, NEWLINE
    PUTS
    
    ; memory dump loop
    LD R1, START_ADDR
    
DUMP_LOOP
    ; display address
    ADD R0, R1, #0
    TRAP x41
    LEA R0, COLON_SPACE
    PUTS
    
    ; display contents
    LDR R0, R1, #0
    TRAP x41
    LEA R0, NEWLINE
    PUTS
    
    ; next address
    ADD R1, R1, #1
    
    ; check if done
    LD R2, END_ADDR
    NOT R3, R2
    ADD R3, R3, #1
    ADD R3, R1, R3     ; current - end
    BRnz DUMP_LOOP
    
    HALT

START_PROMPT .STRINGZ "Enter starting memory address: "
END_PROMPT   .STRINGZ "Enter ending memory address: "
MEM_HEADER   .STRINGZ "\nMemory contents "
TO_STRING    .STRINGZ " to "
NEWLINE      .STRINGZ "\n"
COLON_SPACE  .STRINGZ ": "
START_ADDR   .BLKW 1
END_ADDR     .BLKW 1
.END