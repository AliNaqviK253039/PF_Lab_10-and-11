#include <stdio.h>

int countVowels(char str[], int index) {
    if (str[index] == '\0')
        return 0;

    char ch = str[index];
    int isVowel =
        (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
         ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

    return isVowel + countVowels(str, index + 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    int total = countVowels(str, 0);

    printf("Total vowels: %d\n", total);

    return 0;
}

