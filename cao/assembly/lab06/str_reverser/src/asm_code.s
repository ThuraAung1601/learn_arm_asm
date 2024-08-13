.syntax unified
.thumb

.global reverse_string
.type reverse_string, %function

reverse_string:
    push {r4, r5, r6, r7, lr}         // Save registers that will be used 

    // Arguments:
    // r0 - pointer to the string (s)
    // r1 - length of the string (len)

    cmp r1, #0                        // Compare length with 0
    beq done                          // If length is 0, return

    // Set up pointers for the start and end of the string
    mov r4, r0                        // r4 = s (start of the string)
    add r5, r0, r1                    // r5 = s + len
    subs r5, #1                       // Move to the last character (end - 1)

    // Reverse the string
reverse_loop:
    cmp r4, r5                        // Compare start pointer with end pointer
    bge done                          // If start >= end, we're done

    // Swap characters at r4 and r5
    ldrb r6, [r4]                     // Load byte from start
    ldrb r7, [r5]                     // Load byte from end
    strb r7, [r4]                     // Store end byte at start
    strb r6, [r5]                     // Store start byte at end

    // Move pointers
    add r4, #1                       // Increment start pointer
    subs r5, #1                      // Decrement end pointer

    b reverse_loop                   // Repeat loop

done:
    pop {r4, r5, r6, r7, pc}        // Restore registers and return
