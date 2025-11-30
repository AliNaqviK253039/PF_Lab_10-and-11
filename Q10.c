#include <stdio.h>

int isPalindrome(char word[]) {
    int start = 0, end = 0;

    while (word[end] != '\0') {
        end++;
    }
    end--;
    while (start < end) {
        if (word[start] != word[end])
            return 0;  
        start++;
        end--;
    }

    return 1;  
}

int main() {
    char words[5][20];
    int i;

    printf("Enter 5 words:\n");

    for (i = 0; i < 5; i++) {
        scanf("%s", words[i]);
    }

    printf("\nResults:\n");
    for (i = 0; i < 5; i++) {
        if (isPalindrome(words[i]))
            printf("%s : Palindrome\n", words[i]);
        else
            printf("%s : Not Palindrome\n", words[i]);
    }

    return 0;
}

