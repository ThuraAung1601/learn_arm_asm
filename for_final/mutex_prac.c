#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Mutex for thread synchronization
pthread_mutex_t file_mutex;

// Function that writes log entries to a file
void* write_log_entry(void* thread_id) {
    long tid = (long) thread_id;
    FILE* file;

    // Lock the mutex before writing to the file
    pthread_mutex_lock(&file_mutex);

    // Open file in append mode
    file = fopen("log.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        pthread_mutex_unlock(&file_mutex);
        return NULL;
    }

    // Write log entry
    fprintf(file, "Thread %ld is writing to the log.\n", tid);

    // Close file and unlock the mutex
    fclose(file);
    pthread_mutex_unlock(&file_mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    long t;
    
    // Initialize the mutex
    pthread_mutex_init(&file_mutex, NULL);

    // Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        pthread_create(&threads[t], NULL, write_log_entry, (void*) t);
    }

    // Wait for all threads to complete
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&file_mutex);

    printf("All threads have finished writing.\n");
    return 0;
}
