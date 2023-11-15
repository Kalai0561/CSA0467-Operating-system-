#include <stdio.h>
#include <string.h>

#define MAX 256

int main() {
    FILE *fp;
    char filename[] = "test.txt";
    char str[MAX], temp[MAX];
    char search[] = "Hello";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error in opening the file.\n");
        return 1;
    }

    while (fgets(str, MAX, fp) != NULL) {
        if (strstr(str, search)) {
            printf("String found: %s", str);
            break;
        }
    }

    fclose(fp);

    return 0;
}

