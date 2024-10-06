#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 1000 // Matrix size
#define BLOCK_SIZE 50 // Block size for cache blocking

int (*matrixA)[SIZE];
int (*matrixB)[SIZE];
int (*result)[SIZE];

typedef struct {
    int thread_id;
    int start_row;
    int end_row;
} thread_data_t;

void *multiply_block(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int start_row = data->start_row;
    int end_row = data->end_row;

    for (int i = start_row; i < end_row; i += BLOCK_SIZE) {
        for (int j = 0; j < SIZE; j += BLOCK_SIZE) {
            for (int k = 0; k < SIZE; k += BLOCK_SIZE) {
                // Multiply sub-blocks
                for (int ii = i; ii < i + BLOCK_SIZE && ii < end_row; ii++) {
                    for (int jj = j; jj < j + BLOCK_SIZE && jj < SIZE; jj++) {
                        for (int kk = k; kk < k + BLOCK_SIZE && kk < SIZE; kk++) {
                            result[ii][jj] += matrixA[ii][kk] * matrixB[kk][jj];
                        }
                    }
                }
            }
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);

    matrixA = malloc(SIZE * sizeof(*matrixA));
    matrixB = malloc(SIZE * sizeof(*matrixB));
    result = malloc(SIZE * sizeof(*result));

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrixA[i][j] = rand() % 10;
            matrixB[i][j] = rand() % 10;
            result[i][j] = 0;
        }
    }

    pthread_t threads[num_threads];
    thread_data_t thread_data[num_threads];

    int rows_per_thread = SIZE / num_threads;
    int remaining_rows = SIZE % num_threads;

    clock_t start = clock();

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].start_row = i * rows_per_thread + (i < remaining_rows ? i : remaining_rows);
        thread_data[i].end_row = (i + 1) * rows_per_thread + (i < remaining_rows ? i + 1 : remaining_rows);
        pthread_create(&threads[i], NULL, multiply_block, (void *)&thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time with %d threads: %.2f seconds\n", num_threads, time_taken);

    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}
