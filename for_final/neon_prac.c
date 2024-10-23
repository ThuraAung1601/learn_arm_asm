#include <arm_neon.h>
#include <stdio.h>

void neon_matrix_multiply(float32_t A[3][3], float32_t B[3][3], float32_t C[3][3]) {
    float32x4_t row1, row2, row3, col;

    for (int i = 0; i < 3; i++) {
        // Load rows of matrix A into NEON registers
        row1 = vld1q_f32(A[0]);
        row2 = vld1q_f32(A[1]);
        row3 = vld1q_f32(A[2]);

        for (int j = 0; j < 3; j++) {
            // Load a column from matrix B
            col = vld1q_f32((float32_t[4]) { B[0][j], B[1][j], B[2][j], 0 });

            // Perform vectorized multiplication and accumulate the results
            float32x4_t result = vmulq_f32(row1, col);
            result = vmlaq_f32(result, row2, col);
            result = vmlaq_f32(result, row3, col);

            // Store the result back into matrix C
            vst1q_lane_f32(&C[i][j], result, 0);
        }
    }
}

int main() {
    // Example matrices A and B
    float32_t A[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    float32_t B[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    float32_t C[3][3];

    // Perform matrix multiplication using NEON
    neon_matrix_multiply(A, B, C);

    // Print the result
    printf("Resultant Matrix C:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
