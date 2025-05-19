    .ORIG   x3000               ;start the program at memory location x3000
    
    LEA     R0, PROMPT          ;prompt the user
    TRAP    x22

    LEA     R4, INPUT           ;load the address of the input into R4
    AND     R3, R3, #0          ;clear R3 to store packed characters

READ_LOOP
    TRAP    x20                 ;(GETC) this reads a character into R0
    TRAP    x21                 ;(OUT) displaying input at the same time
    ADD     R2, R0, #-10        ;check if the character is "Enter" 
    BRz     END_READ            ; end the loop if enter is pressed

    ADD     R5, R3, #0          ;copy R3 to R5 to check if R3 is empty
    BRz     FIRST_CHAR          ;if R3 is empty, this is the first character of the pair

    ; Second character of the pair
    AND     R6, R6, #0          
    ADD     R6, R6, #8          ;8 is the number of bits to shift
SHIFT_LOOP
    ADD     R0, R0, R0          ;shift R0 left by 1 bit 
    ADD     R6, R6, #-1         ;decrement the shift counter
    BRp     SHIFT_LOOP          ;repeat until R6 is 0

    ADD     R3, R3, R0          ;combine the first and second characters into R3
    STR     R3, R4, #0          ;store the packed pair into memory
    ADD     R4, R4, #1          ;go to next memory location
    AND     R3, R3, #0      
    BR  READ_LOOP               

FIRST_CHAR
    ; First character of the pair (lower 8 bits)
    ADD     R3, R0, #0          
    BR  READ_LOOP           

END_READ
    ; odd number case
    ADD     R5, R3, #0          ;check if R3 contains a character
    BRz     DONE                ;if R3 is empty, the string length is even
    STR     R3, R4, #0          ;store the last character in memory (lower 8 bits)

DONE
    
    
    LEA     R0, INPUT           ;load the address of the input to be printed
    TRAP    x24                 ;print the packed string (PUTS) 
    
    LD      R0,NEWLINE          ;load newline character to display the packed string on the next line
    TRAP    x21
    

    HALT                

;variable
PROMPT .STRINGZ "Enter a string: " 
NEWLINE .FILL   x0A
TEST    .STRINGZ "TEST"
INPUT .BLKW #50                 ; Reserve 50 memory locations

    .END