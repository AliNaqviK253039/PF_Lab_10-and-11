#include <stdio.h>

int main() {
    FILE *f1 = fopen("input.txt", "r");
    FILE *f2 = fopen("log.txt", "r");
    FILE *fd = fopen("data.txt", "w");
    char ch;

    if (!f1 || !f2 || !fd) {
        printf("Error opening files.\n");
        return 1;
    }

    while ((ch = fgetc(f1)) != EOF)
        fputc(ch, fd);
    fclose(f1);

    while ((ch = fgetc(f2)) != EOF)
        fputc(ch, fd);
    fclose(f2);

    fclose(fd);
    printf("Files merged into data.txt\n");
    return 0;
}

