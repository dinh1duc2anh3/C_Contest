#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Read input
    int n;
    scanf("%d", &n);

    int sequence[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    // Perform sorting using quicksort
    quickSort(sequence, 0, n - 1);

    // Print the sorted sequence
    for (int i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }

    return 0;
}
