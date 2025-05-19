; DO NOT PUT THIS CODE ON CHEGG OR ANY OTHER "INFO" WEBSITE.  IT'S FOR 
; US ONLY.

; For you amusement, I wrote a trap function that I'm registering
; as trap number x42.  This trap do a SINGLE BIT right shift of the 
; value in R0 and put that shifted value right back into R0.  
; The trap code backs up all registers (except R0, in which it returns
; an answer) and restores them correctly before executing the RTI
; (Return from Interrupt)
            
            
; Here's some test code that tests the trap.  You can change the TEST_VAL
; to anything you want for testing purposes.
;
; Note that in the LC3, the HALT trap is VERY MESSY.  It craps all over
; registers.  IF you run HALT, it WILL mess up your registers with its
; own junk on the way to "halting" the machine.  If you want to actually
; look at register contents without having HALT mess with them, you'll need
; to put a dummy instrution before the halt and single step to that dummy
; instruction to examine the registers BEFORE the HALT trap clobbers them.

            .ORIG   x3000
             LD       R0, TEST_VAL      ; Load a test value into R0
             
             TRAP     x42               ; call the right shift trap
             
             AND      R5, R5, R5        ; dummy instruction so you can single step
                                        ; to this and LOOK at the other registers
                                        ; before runnint the HALT.  Note that this
                                        ; instruction literally does nothing -- it doesn't
                                        ; even really change the contents of R5 ;)
                                        
             HALT                       ; here's the halt
             
TEST_VAL    .FILL   xA0A0               ; here's the value we'll load into R0 for 
                                        ; shifting
            .END
           
           
; HERE'S THE CODE FOR THE RIGHT SHIFT TRAP.  I'll COMMENT SOME OF IT
; THE REST IS FOR YOU TO PONDER.  YOU MAY USE THIS TRAP CODE IN YOUR
; HW ASSIGNMENT.  ADD A THIRD TRAP TO YOUR HOMEWORK CODE (THIS ONE)
; AND CALL IT FROM INSIDE THE TRAPS YOU'RE WRITING AS NEEDED.

           .ORIG    x6000
            ; back up all the registers by pushing them on the system stack
            ADD     R6, R6, #-1
            STR     R1, R6, #0
            ADD     R6, R6, #-1
            STR     R2, R6, #0
            ADD     R6, R6, #-1
            STR     R3, R6, #0
            ADD     R6, R6, #-1
            STR     R4, R6, #0
            ADD     R6, R6, #-1
            STR     R5, R6, #0
            
            ; move R0 into R3.  We'll keep the copy of the 
            ; unshifted value in R3 as R0 gets used for all kinds
            ; of scratch stuff and/or sending parameters to other
            ; traps
            
            AND     R3, R3, #0
            ADD     R3, R3, R0
   
            LD      R1, MASK_TEST
            LD      R5, MASK_WRITE
            AND     R4, R4, #0       ; I'm going to assembble the answer in R4.
                                     ; it should be cleared initally 
                                     
            
            LD      R2, LOOP_COUNT
LOOP        AND     R0, R3, R1
            BRz     ELSE
            JSR     P1
            BRnzp   CONTINUE
ELSE        JSR     P0
CONTINUE    ADD     R1, R1, R1
            ADD     R5, R5, R5
            ADD     R2, R2, #-1
            BRnp     LOOP

            ; I'm done.  Copy the created answer into R0 so it can be
            ; "returned" to the caller.  Restore all the other registers
            ; from the system stack and then return from TRAP call
DONE        AND     R0, R0, #0
            ADD     R0, R0, R4
            LDR     R5, R6, #0
            ADD     R6, R6, #1
            LDR     R4, R6, #0
            ADD     R6, R6, #1
            LDR     R3, R6, #0
            ADD     R6, R6, #1
            LDR     R2, R6, #0
            ADD     R6, R6, #1
            LDR     R1, R6, #0
            ADD     R6, R6, #1
            RTI

P0          ; debug code LD      R0, ASCII_0
            ; debug code OUT     
            RET

P1          ; debug code LD      R0, ASCII_1
            ; debug code OUT
            ADD     R4, R4, R5
            RET
            
ASCII_0     .FILL   #48
ASCII_1     .FILL   #49
MASK_TEST   .FILL   x0002
MASK_WRITE  .FILL   x0001
LOOP_COUNT  .FILL   xF
            .END
            
           .ORIG   x42
            .FILL   x6000
            .END