#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main() {
    int W = 50; // Knapsack capacity
    int n = 3; // Number of items
    int weights[] = {10, 20, 30}; // Weights of items
    int values[] = {60, 100, 120}; // Values of items

    int max_value = knapsack(W, weights, values, n);
    printf("Maximum value in Knapsack = %d", max_value);
    return 0;
}
