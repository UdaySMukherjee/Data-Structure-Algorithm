#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool dp[MAX_SIZE][MAX_SIZE];
int path[MAX_SIZE];

void printSubset(int arr[], int n, int sum) {
    int i = n, j = sum, k = 0;
    while (i > 0 && j > 0) {
        if (dp[i - 1][j]) {
            i--;
        } else {
            path[k++] = arr[i - 1];
            j -= arr[i - 1];
            i--;
        }
    }
    printf("Subset with sum %d: ", sum);
    for (i = k - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

bool isThereSubsetSum(int arr[], int n, int sum) {
    int i, j;
    for (i = 0; i <= n; i++)
        dp[i][0] = true;

    for (i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    if (dp[n][sum]) {
        printSubset(arr, n, sum);
    }

    return dp[n][sum];
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isThereSubsetSum(set, n, sum) == true) {
        printf("Subset found\n");
    } else {
        printf("No subset with given sum\n");
    }
    return 0;
}

