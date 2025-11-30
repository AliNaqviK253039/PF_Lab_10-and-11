#include <stdio.h>

int compare(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return 0;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

int main() {
    char words[5][20];
    char input[20];
    int i, found = 0;

    printf("Enter 5 words:\n");
    for ( i = 0; i < 5; i++)
        scanf("%s", words[i]);

    printf("Enter a word to search: ");
    scanf("%s", input);

    for (i = 0; i < 5; i++) {
        if (compare(words[i], input)) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}

