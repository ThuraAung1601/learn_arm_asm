.global _start
_start:
	LDR R0, =list 			@ load data (list) from the stack to R0 - R0 stores address
	LDR R1, [R0]			@ load into R1 the value that exist at R0 - [] means at
	@ In our case 4 is in R0 so next step 4 will be in R1
	@ We have to add an offset to move to next memory location, in our case we need to add 4
	LDR R2, [R0, #4]		@ Takes value at R0 and add 4 -> moves to next index (memory location)
	LDR R3, [R0, #8]
	LDR R4, [R0, #12]
	LDR R5, [R0, #16]
	LDR R6, [R0, #20]
	LDR R8, [R0, #20]
.data 						@ label 'data' means data declare section
list: 						@ list is name - list of data
	.word 	4, 5, -1, 10, 12, 1	@ each is treated as word (i.e, 32 bits for 32-bit assembler)