### Mutex Code - Final Exam Notes

1. **Mutex Basics:**
   - **Mutex (Mutual Exclusion)** is used in multithreading to prevent race conditions by ensuring only one thread accesses a critical section at a time.
   
2. **Initializing a Mutex:**
   ```c
   pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
   ```
   - Mutexes need to be initialized before use. You can also use `pthread_mutex_init()`.

3. **Locking a Mutex (Entering Critical Section):**
   ```c
   pthread_mutex_lock(&mutex);
   ```
   - Before accessing shared resources, a thread must lock the mutex to gain exclusive access to the critical section.
   
4. **Unlocking a Mutex (Exiting Critical Section):**
   ```c
   pthread_mutex_unlock(&mutex);
   ```
   - Once the critical section is completed, the thread must unlock the mutex to allow other threads to enter.

5. **Destroying a Mutex:**
   ```c
   pthread_mutex_destroy(&mutex);
   ```
   - After all threads have finished using the mutex, it should be destroyed to release system resources.

6. **Handling Deadlocks:**
   - Avoid locking multiple mutexes in different orders across threads to prevent deadlocks.

---

### NEON Code - Final Exam Notes

1. **NEON (Advanced SIMD) Overview:**
   - ARM NEON is used for **data parallelism** to speed up operations on arrays or vectors by processing multiple data points simultaneously.

2. **Loading Data into NEON Registers:**
   - Use `vld1q_f32()` to load a **vector** of floating-point values into a NEON register:
   ```c
   float32x4_t vec = vld1q_f32(array);
   ```

3. **Performing NEON Operations:**
   - **Vectorized Multiply (vmulq_f32):**
     ```c
     result = vmulq_f32(vec1, vec2);
     ```
   - **Vector Multiply-Add (vmlaq_f32):**
     ```c
     result = vmlaq_f32(result, vec1, vec2);
     ```
   - These operations perform element-wise multiplication or multiply-add on vectors.

4. **Storing NEON Results:**
   - Use `vst1q_lane_f32()` to store an element (lane) from a NEON vector back into memory:
   ```c
   vst1q_lane_f32(&array[i], result, 0);
   ```

5. **Optimizing Matrix Operations with NEON:**
   - NEON allows matrix operations (e.g., multiplication) to be vectorized, improving speed significantly in linear algebra and graphics tasks.

---

### Key Exam Concepts:
- **Mutex:** Ensure correct usage of `pthread_mutex_lock()` and `pthread_mutex_unlock()` to manage critical sections.
- **NEON:** Understand vectorized operations like `vmulq_f32` and `vmlaq_f32` to optimize matrix computations or any parallel data processing tasks.
