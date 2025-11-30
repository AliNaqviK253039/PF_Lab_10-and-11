#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index) {
    if (index == size)
        return -1;              
    if (arr[index] == target)
        return index;           
    return linearSearch(arr, size, target, index + 1);
}

int main() {
    int i;
	int arr[10], n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for ( i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target, 0);

    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}

