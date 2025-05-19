    .ORIG   x3000       ;start at x3000 the user program area
    
    LEA R0, PROMPT      ;load prompt string into R0
    TRAP    x22         ;(PUTS)
    LEA R1, INPUT       ;loading the address into R1

THE_LOOP
    TRAP    x20         ;(GETC)
    TRAP    x22
    ADD R3, R0, #-10    ;compares the input with "Enter"
    BRz     STOP_IT     ;if the comparison is True then the loop stops
    
    STR R0, R1, #0      ;if the comparison is False store the inputted character into the memory located in R1
    ADD R1, R1, #1      ;moves to the next memory location 
    BR      THE_LOOP    ;repeat the loop

STOP_IT
    AND R0, R0, #0      ;clear the memory at R0
    STR R0, R1, #0      ;store null terminator at current position
    
    ;displaying the output
    LEA R0, INPUT  
    TRAP x22            
    
    LD R0,NEWLINE
    TRAP x21            ;(OUT)
    
    
    HALT
    

;varaibles
PROMPT .STRINGZ "Enter a string: "
INPUT   .BLKW   #50       ;Reserve space for 50 characters
NEWLINE .FILL   x0A

    

    .END