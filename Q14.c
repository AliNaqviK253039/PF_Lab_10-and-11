#include <stdio.h>

int main() {
    FILE *fp;
    int runCount = 0;

    fp = fopen("log.txt", "r");
    if (fp != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), fp) != NULL) {
            runCount++;
        }
        fclose(fp);
    }

    fp = fopen("log.txt", "a");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(fp, "Program run number %d\n", runCount + 1);
    fclose(fp);

    printf("Run recorded in log.txt\n");

    return 0;
}

