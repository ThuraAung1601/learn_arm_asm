.global _start
_start:
	MOV R7, #4 			@ Write information to the screen
	MOV R0, #1 			@ Output stream to the monitor
	MOV R2, #12 		@ Length of string to print out
	LDR R1, =message	@ Load a message to display in R1
	SWI 0				@ Software Interupt that takes value in R7
	
end:	
	MOV R7, #1			@ Jump to the terminal
	SWI 0				@ Software Interupt that takes value in R7
	
.data					@ Define our data
message:
	.ascii "Hello world\n"