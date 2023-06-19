#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int i;

bool isSubsetSum(int set[], int n, int sum, int currSum, int index, bool selected[]) {
    if (currSum == sum) {
        printf("Subset found: ");
        for (i = 0; i < n; i++) {
            if (selected[i]) {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
        return true;
    }

    if (index == n) {
        return false;
    }

    selected[index] = true;
    bool include = isSubsetSum(set, n, sum, currSum + set[index], index + 1, selected);
    selected[index] = false;
    bool exclude = isSubsetSum(set, n, sum, currSum, index + 1, selected);

    return include || exclude;
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    bool selected[MAX_SIZE] = {false};

    if (!isSubsetSum(set, n, sum, 0, 0, selected)) {
        printf("No subset with given sum\n");
    }

    return 0;
}

