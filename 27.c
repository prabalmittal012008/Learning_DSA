#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hash map using array (for prefix sum frequency)
    int *freq = (int *)calloc(MAX, sizeof(int));

    int prefix_sum = 0;
    int count = 0;

    // Important: prefix sum 0 occurs once initially
    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Handle negative index by shifting
        int index = prefix_sum + MAX / 2;

        if (index >= 0 && index < MAX) {
            count += freq[index];
            freq[index]++;
        }
    }

    printf("%d\n", count);

    free(freq);
    return 0;
}