#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to print the matrix for verification
void printMatrix(uint8_t *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 1. Invert: (255 - pixel_value)
// This is often used for simple image effects or UI masking.
void invert(uint8_t *data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = 255 - data[i];
    }
}

// 2. Transpose: Swap rows and columns
// Logic: target[j][i] = source[i][j]
void transpose(uint8_t *src, uint8_t *dst, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dst[j * rows + i] = src[i * cols + j];
        }
    }
}

// 3. Rotate 90 Degrees Clockwise
// Logic: Transpose the matrix, then reverse each row.
// Alternatively, mapping directly: target_col = (rows - 1 - original_row)
void rotate90(uint8_t *src, uint8_t *dst, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // New row index = j
            // New column index = (rows - 1 - i)
            dst[j * rows + (rows - 1 - i)] = src[i * cols + j];
        }
    }
}

int main() {
    int rows = 3, cols = 4;
    uint8_t *image = (uint8_t *)malloc(rows * cols * sizeof(uint8_t));
    uint8_t *result = (uint8_t *)malloc(rows * cols * sizeof(uint8_t));

    // Initialize with dummy pixel data (0 to 11)
    for (int i = 0; i < rows * cols; i++) image[i] = i;

    printf("Original 3x4 Matrix:\n");
    printMatrix(image, rows, cols);

    // --- Invert ---
    invert(image, rows * cols);
    printf("Inverted Matrix:\n");
    printMatrix(image, rows, cols);
    
    // Revert for next operations
    invert(image, rows * cols);

    // --- Transpose ---
    // Target will be 4x3
    transpose(image, result, rows, cols);
    printf("Transposed Matrix (4x3):\n");
    printMatrix(result, cols, rows);

    // --- Rotate 90 Clockwise ---
    // Target will be 4x3
    rotate90(image, result, rows, cols);
    printf("Rotated 90 Degrees Clockwise (4x3):\n");
    printMatrix(result, cols, rows);

    free(image);
    free(result);
    return 0;
}
