#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];

    // Input string
    scanf("%s", str);   // reads single word (no spaces)

    int len = strlen(str);

    // Mirror (reverse)
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
