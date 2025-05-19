.ORIG x3000

MAIN	
	LEA R0,towersOfHanoi    ;says "Tower of Hanoi"
	PUTS 				

	LEA R0,numberOfDisks    ;prompt for input
	PUTS				
	GETC				
	OUT				

	LD R1,hex30             ;this block of code is to get the hexidecimal for the input
	NOT R1,R1			
	ADD R1,R1,#1			
	ADD R0,R1,R0			
							
	LEA R1,instructionsPrompt	
	AND R3,R3,#0			
	ADD R3,R3,#11			
	AND R4,R4,#0			
	ADD R4,R4,#11			
	ADD R5,R4,R3			
	ADD R1,R1,R5			
	LD R2,bottomOfStack		
	STR R0,R2,#0
	LD R5,hex30			
	ADD R0,R0,R5			
	STR R0,R1,#0			
	LEA R0,instructionsPrompt		
	PUTS				
					
numberOfDisks		.STRINGZ "How many disks (1-9)?"	;

;caller's portion of stack building from MAIN()	
;activation record is being built

; loading pointers and arguments in R5 and R6 				
	LD R5,bottomOfStack		
	LD R6,R6Pointer	
	
	;arguments start at 1,2,3 respectively
	LD R1,startingPost			
	LD R2,endPost			
	LD R3,middlePost			
	
	;push middlePost onto the stack.				
	ADD R6,R6,#-1				
	STR R3,R6,#0			
					
	;push endPost onto the stack.
	ADD R6,R6,#-1			
	STR R2,R6,#0			

	;push startingPost onto the stack.	
	ADD R6,R6,#-1			
	STR R1,R6,#0			

	;push n onto the stack.
	LDR R0,R5,#0			
	ADD R6,R6,#-1			
	STR R0,R6,#0			
	JSR MOVE_DISK			
	HALT				    ;base case can't work without this



;caller's portion of stack building  MAIN()
;callee's portion of stack building MOVE_DISK()
;callee moveDisk(n,1,3,2)
MOVE_DISK
	
	;pushing return address onto the stack.
	ADD R6,R6,#-1			
	STR R7,R6,#0			
				
	;loading arguments from the activation record into correct registers
	LDR R3,R6,#4			
	LDR R2,R6,#3			
	LDR R1,R6,#2			
	LDR R0,R6,#1		

	;R0 is diskNum		
	ADD R0,R0,#-1
	 
	;if adding -1 to my disk number results in a zero, then diskNum is 1 and it should go to base case
	BRz PSOLSTEP

;if(diskNum > 1)	
NOT_BASE_CASE 
	
	ADD R0,R0,#1 	;Reset R0 back to what it was
		    			

;caller's portion of stack buidling MOVE_DISK()
;activation record being build for recursive call 
;The first recursive caller moveDisk(diskNum - 1,starting, middle ,end) the slots in the stack
;for the argumentscontain different values.
;Now diskNum will be diskNum -1, starting will be the same, but the value of middlePost is in the 
;slot for the endPost.The value for the endPost is in the middlePost slot.

	;lodaing the proper numbers into the right arguments and storing into the stack
	ADD R6,R6,#-1			; 3 into middlePost
	STR R2,R6,#0			
	ADD R6,R6,#-1			; 2 into endPost
	STR R3,R6,#0			
	ADD R6,R6,#-1			; 1 into startingPost
	STR R1,R6,#0			
					

	;Loading diskNum = 3 into R0 and store in the stack
	ADD R6,R6,#-1		
	ADD R0,R0,#-1			
	STR R0,R6,#0
	
	;go back to MOVE_DISK and do the callee portion
	JSR MOVE_DISK

	
	
	;move disk string.	
	AND R0,R0,#0		
	AND R1,R1,#0		
	AND R2,R2,#0
	AND R3,R3,#0

	LEA R1,moveDisk	
	
	ADD R6,R6,#1	
	LDR R0,R6,#0
	
	LD R3,hex30
	ADD R0,R0,R3

	ADD R2,R2,#10	
	ADD R1,R1,R2

	STR R0,R1,#0
	LEA R0,moveDisk
	PUTS

	;from post string.
	AND R0,R0,#0
	AND R1,R1,#0
	AND R2,R2,#0
	AND R3,R3,#0

	LEA R1,fromPost	
	
	ADD R6,R6,#1	
	LDR R0,R6,#0
	
	LD R3,hex30
	ADD R0,R0,R3

	ADD R2,R2,#10	
	ADD R1,R1,R2

	STR R0,R1,#0
	LEA R0,fromPost
	PUTS


	;to post string.
	AND R0,R0,#0
	AND R1,R1,#0
	AND R2,R2,#0
	AND R3,R3,#0

	LEA R1,toPost	
	
	ADD R6,R6,#1	
	LDR R0,R6,#0

	LD R3,hex30
	ADD R0,R0,R3

	ADD R2,R2,#8	
	ADD R1,R1,R2

	STR R0,R1,#0
	LEA R0,toPost	
	PUTS
	
	;point R6 back to what it was originally pointing at
	ADD R6,R6,#-3	
	
	;load what is in the middle,end,and starting post arguments and diskNum slots of the activation record 
	;into these registers
	LDR R3,R6,#4	
	LDR R2,R6,#3	
	LDR R1,R6,#2
	LDR R0,R6,#1
			
	
	
	
	
;2nd caller's portion of stack building MOVE_DISK().
;similar to the first recursive call except the (diskNum,startingPost,endPost,middlePost) 
;slots in the stack of the activation record contain different values based off of the first activation record created.
	
	;point R6 at the neccessary argument slot and push the neccessary value
	ADD R6,R6,#-1	;R6 points at middlePost 
	STR R1,R6,#0	
	
	ADD R6,R6,#-1	;R6 points at endPost
	STR R2,R6,#0	

	ADD R6,R6,#-1	;R6 points at startingPost slot.
	STR R3,R6,#0	

	ADD R6,R6,#-1	;R6 points at diskNum slot.
	ADD R0,R0,#-1	;Decrement one from diskNum.
	STR R0,R6,#0	;push diskNum value here.
	
	;go back to MOVE_DISK so it can do the callee portion
	JSR MOVE_DISK
	
	;R6 is pointg into R7 and pop off the arguments and Ra off the stack
	LDR R7,R6,#0	
	ADD R6,R6,#1	
	ADD R6,R6,#4	
	RET		        ;return to what is in R7.
	
;if(diskNum ==1)
PSOLSTEP
;I am breaking the string "Move disk n, from post a, to post b," into three parts which made it easier.
;Each part has the same process except when certain numbers are added to change the character.
;The process for the printing is:
;1.clear R0-R3
;2.load string into R1
;3.add 1 to R6 to give the parameter I want to repace the character I want to replace.
;4.load hex30 and add to parameter to give correct representation.
;5.add x number of characters to a register, add to string.
;6.store the character into this spot in memory for R1.
;7.load the new string into R0 and display it
			
	;clearing R0-R3 because I will use these registers for printing
	AND R0,R0,#0	
	AND R1,R1,#0	
	AND R2,R2,#0	
	AND R3,R3,#0	

			
	LEA R1,moveDisk	
	
	ADD R6,R6,#1	; add one to the R6 pointer to give me the diskNum arg from the activation record
	LDR R0,R6,#0	;replace the n character.

	LD R3,hex30	    ;loading x0030 and add this to R0 
	ADD R0,R0,R3	 
			

	ADD R2,R2,#10	;the 10th character n needs to be replaced
	ADD R1,R1,R2	;replace the 10th slot of memory which has n with the character 
	                ;I want being the disk number.
			
    ;store the diskNumber and then display it
	STR R0,R1,#0	
	LEA R0,moveDisk	
	PUTS		
	
	;"from post a"
	AND R0,R0,#0
	AND R1,R1,#0	
	AND R2,R2,#0
	AND R3,R3,#0

	LEA R1,fromPost
		
	ADD R6,R6,#1
	LDR R0,R6,#0

	LD R3,hex30
	ADD R0,R0,R3

	ADD R2,R2,#10	
	ADD R1,R1,R2

	STR R0,R1,#0
	LEA R0,fromPost
	PUTS


	;"to post b"
	AND R0,R0,#0
	AND R1,R1,#0
	AND R2,R2,#0
	AND R3,R3,#0

	LEA R1,toPost
		
	ADD R6,R6,#1	
	LDR R0,R6,#0

	LD R3,hex30
	ADD R0,R0,R3

	ADD R2,R2,#8	
	ADD R1,R1,R2

	STR R0,R1,#0
	LEA R0,toPost	
	PUTS
		
	ADD R6,R6,#-3	;R6 pointing to return address
	;load the return address into R7 and pop off the address to get R6 to point at diskNum slot
	LDR R7,R6,#0	
	ADD R6,R6,#1	
	ADD R6,R6,#4
			
	RET	      	;return to the address in R7

	
;variables
hex30			.FILL x0030
startingPost	.FILL 1	;starts as 1
middlePost		.FILL 2	;starts as 2
endPost			.FILL 3 ;starts as 3
R6Pointer		.FILL x5000 ;address at bottom of stack to hold my R6 pointer
bottomOfStack	.FILL x5000 ;address at bottom of stack to hold my R5 pointer
;strings
instructionsPrompt	    .STRINGZ "\nInstructions to move n disks from post 1 to post 3: \n"
towersOfHanoi	.STRINGZ "-----Towers of Hanoi-----\n"
moveDisk		.STRINGZ "Move disk n "
fromPost		.STRINGZ "From post a "
toPost			.STRINGZ "To post b \n"
notInBaseCase   .STRINGZ "This is not in base case..."

.end