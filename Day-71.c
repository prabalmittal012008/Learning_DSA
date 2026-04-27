#include <stdio.h>

#define SIZE 7

int table[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

void insert(int key) {
    int h = key % SIZE;
    int i = 0;

    while(i < SIZE) {
        int index = (h + i*i) % SIZE;
        if(table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }
}

int search(int key) {
    int h = key % SIZE;

    for(int i = 0; i < SIZE; i++) {
        int index = (h + i*i) % SIZE;

        if(table[index] == key)
            return 1;

        if(table[index] == -1)
            return 0;
    }
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    init();

    for (int i = 0; i < n; i++) {
        int key;
        if (scanf("%d", &key) != 1) {
            return 0;
        }
        insert(key);
    }

    int q;
    if (scanf("%d", &q) != 1) {
        return 0;
    }

    for (int i = 0; i < q; i++) {
        int key;
        if (scanf("%d", &key) != 1) {
            return 0;
        }
        printf("%d", search(key));
        if (i + 1 < q) {
            printf(" ");
        }
    }

    return 0;
}