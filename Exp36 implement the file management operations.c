#include <stdio.h>

int main() {
    FILE *fp;
    char filename[] = "sample.txt";
    char ch;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error in opening the file.\n");
        return 1;
    }
    fprintf(fp, "Hello, World!\n");
    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error in opening the file.\n");
        return 1;
    }
    printf("Reading the file:\n");
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
    fclose(fp);

    // Deleting a file
    if (remove(filename) == 0)
        printf("\nFile deleted successfully.\n");
    else
        printf("\nError in deleting the file.\n");

    return 0;
}

