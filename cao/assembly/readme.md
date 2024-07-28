```
.global _start
_start:
	MOV R0, #30
	
	MOV R7, #1
	SWI 0
```

_start marks the beginning of the program
Moves immediate value 30 to the register R0
R0 - R3 is for load four arguments
R4 - R6 and R8 - R12 for additional variables (need to restore the original values before returning)
R7 is for system call number
R0 to R3 are typically used for passing arguments, R7 specifies the system call number, and other registers can be used for temporary storage and intermediate calculations.
Load 1 in R7 means exit
SWI 0 is Software Interprut that take value in R7 in our case 1.
