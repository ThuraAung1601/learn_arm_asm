### 1. Mutex: File Write-Back Operation
**Question:**  
You are tasked with implementing a program in C that writes to a shared log file from multiple threads. Use a mutex to ensure that each thread safely writes its log entry to the file without any race conditions. Implement the function `write_log_entry()` that each thread calls to write its message to the file, ensuring thread safety.

**Instructions:**
- Create and initialize a mutex.
- Ensure that each thread writes to the file in a safe manner using the mutex.
- Ensure that no two threads write at the same time.

**Sample Solution Outline:**
- Use the `pthread` library in C.
- Use `pthread_mutex_t` for the mutex.
- Lock the mutex before writing and unlock it after writing.

---

### 2. NEON: Matrix Multiplication
**Question:**  
You are given two 3x3 matrices of `float32_t` type. Write an ARM NEON assembly function that performs matrix multiplication using NEON instructions. Optimize the code to take advantage of NEON vectorization to speed up the matrix operations.

**Instructions:**
- Use NEON vector load and store instructions to load matrix rows.
- Use NEON multiplication (`vmul`) and addition (`vmla`) instructions to perform vectorized matrix multiplication.
- Return the result as a 3x3 matrix.

**Sample Solution Outline:**
- Use NEON intrinsics (or inline assembly) to load matrix rows into NEON registers.
- Perform vectorized multiply-add operations.
- Store the results back into the output matrix.
