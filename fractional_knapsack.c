#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

float fractionalKnapsack(int W, struct Item items[], int n) {
    float max_value = 0.0;
    int i;
    qsort(items, n, sizeof(items[0]), compare);
    for (i = 0; i < n; i++) {
        if (W == 0) {
            return max_value;
        }
        if (items[i].weight <= W) {
            W -= items[i].weight;
            max_value += items[i].value;
        } else {
            max_value += (W * items[i].ratio);
            W = 0;
        }
    }
    return max_value;
}

int main() {
    int W = 50; // Knapsack capacity
    int n = 3; // Number of items
    struct Item items[n];

    // Items
    items[0].value = 60;
    items[0].weight = 10;
    items[0].ratio = (float)items[0].value / items[0].weight;

    items[1].value = 100;
    items[1].weight = 20;
    items[1].ratio = (float)items[1].value / items[1].weight;

    items[2].value = 120;
    items[2].weight = 30;
    items[2].ratio = (float)items[2].value / items[2].weight;

    float max_value = fractionalKnapsack(W, items, n);
    printf("Maximum value in Knapsack = %f", max_value);
    return 0;
}
