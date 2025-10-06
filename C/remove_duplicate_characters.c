#include <stdio.h>
#include <string.h>

void rm(char str[]) {
    int n = strlen(str);
    int i, j, k;
    for(i = 0; i < n; i++) {
        for(j = i + 1; str[j] != '\0'; ) {
            if(str[i] == str[j]) {
                for(k = j; str[k] != '\0'; k++) {
                    str[k] = str[k+1];
                }
            } else {
                j++;
            }
        }
    }
    printf("%s", str);
}

int main() {
    char str[100];
    scanf("%99s", str);
    rm(str);
    return 0;
}
