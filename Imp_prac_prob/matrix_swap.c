#include <stdio.h>

void form_matrix(int matrix[3][4], int row, int col) {
    //1printf("Enter matrix elements for 3 * 3 matrix: ");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("Enter matrix elements for 3 * 3 matrix: ");
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");
}

void display_matrix(int matrix[3][4], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");
}

void swap_matrix(int matrix1[3][4], int matrix2[3][4], int row, int col) {
    int tmp = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            tmp = matrix1[i][j];
            matrix1[i][j] = matrix2[i][j];
            matrix2[i][j] = tmp;
        }
    }
}

// Function to transpose a matrix
void transpose(int matrix[3][4], int result[4][3], int row, int col) {
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result[j][i] = matrix[i][j];
}

/*
// Function to add two matrices
void add_matrices(int rows, int cols, double a[rows][cols], double b[rows][cols], double result[rows][cols]) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

// Function to multiply two matrices
void multiply_matrices(int r1, int c1, int c2, double a[r1][c1], double b[c1][c2], double result[r1][c2]) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

// Function to get the determinant of a 2x2 or 3x3 matrix
double determinant_2x2(double m[2][2]) {
    return m[0][0]*m[1][1] - m[0][1]*m[1][0];
}

// Function to invert a 2x2 matrix
int invert_2x2(double m[2][2], double result[2][2]) {
    double det = determinant_2x2(m);
    if(det == 0) return 0; // Not invertible

    result[0][0] = m[1][1]/det;
    result[0][1] = -m[0][1]/det;
    result[1][0] = -m[1][0]/det;
    result[1][1] = m[0][0]/det;
    return 1; // Success
}
*/

int main() {
    int row = 3, col = 4;
    int matrix1[row][col], matrix2[row][col];
    int transpose_res[col][row];

    form_matrix(matrix1, row, col);
    display_matrix(matrix1, row, col);
    form_matrix(matrix2, row, col);
    display_matrix(matrix2, row, col);

    printf("\n");

    swap_matrix(matrix1, matrix2, row, col);
    display_matrix(matrix1, row, col);
    display_matrix(matrix2, row, col);

    printf("\n");

    transpose(matrix2, transpose_res, row, col);
    display_matrix(transpose_res, row, col);

    return 0;
}