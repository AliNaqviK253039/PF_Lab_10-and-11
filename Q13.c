#include <stdio.h>

int main() {
    FILE *fp;
    int ch, empty = 1;

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fclose(fp);

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    ch = fgetc(fp);
    if (ch != EOF)
        empty = 0;

    fclose(fp);

    if (empty)
        printf("File is empty.\n");
    else
        printf("File is not empty.\n");

    return 0;
}

