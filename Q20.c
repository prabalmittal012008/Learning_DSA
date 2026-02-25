#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int sum;
    int freq;
} HashNode;

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    HashNode *map = (HashNode *)malloc((n + 1) * sizeof(HashNode));
    int mapSize = 0;

    long long count = 0;
    int prefixSum = 0;

    
    map[mapSize].sum = 0;
    map[mapSize].freq = 1;
    mapSize++;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        
        int found = 0;
        for(int j = 0; j < mapSize; j++) {
            if(map[j].sum == prefixSum) {
                count += map[j].freq;
                map[j].freq++;
                found = 1;
                break;
            }
        }

        
        if(!found) {
            map[mapSize].sum = prefixSum;
            map[mapSize].freq = 1;
            mapSize++;
        }
    }

    printf("%lld", count);

    free(arr);
    free(map);
    return 0;
}
