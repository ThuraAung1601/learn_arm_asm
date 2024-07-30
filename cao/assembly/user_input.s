.global _start
_start:
	MOV R7, #3 			@ System call to allow Keyboard input
	MOV R0, #0 			@ Input stream from keyboard
	MOV R2, #10 		@ Length of string to write
	LDR R1, =message	@ Load a message to display in R1
	SWI 0				@ Software Interupt that takes value in R7

_write:					@ Create another label
	MOV R7, #4 			@ System call to output the screen
	MOV R0, #1 			@ Output stream to monitor
	MOV R2, #5 			@ Length of string to print out
	LDR R1, =message	@ Load a message to display in R1
	SWI 0				@ Software Interupt that takes value in R7


end:	
	MOV R7, #1			@ Jump to the terminal
	SWI 0				@ Software Interupt that takes value in R7
	
.data					@ Define our data
message:
	.ascii " "