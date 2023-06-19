#include <stdio.h>
#include <limits.h>

int matrix_chain_multiplication(int dims[], int n) {
    int m[n][n];
    int i, j, k, l, q;
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (l = 2; l < n; l++) {
        for (i = 1; i < n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int dims[] = {10, 20, 30, 40, 30};
    int n = sizeof(dims) / sizeof(int);
    int min_multiplications = matrix_chain_multiplication(dims, n);
    printf("Minimum number of multiplications = %d", min_multiplications);
    return 0;
}
