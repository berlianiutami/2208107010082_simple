#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
void generateNumbers(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Generate random numbers between 0 to 999999
    }
}

// Function to perform bubble sort
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform selection sort
void selectionSort(int *arr, int n) {
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[minIndex] and arr[i]
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform insertion sort
void insertionSort(int *arr, int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to write array elements to a file (unsorted)
void writeUnsortedToFile(int *arr, int start, int end, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = start; i < end; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

// Function to write array elements to a file (sorted)
void writeSortedToFile(int *arr, int start, int end, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = start; i < end; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int maxNumbers = 1000000; // Maximum number of integers
    int step = 100000; // Step size for increasing the number of elements
    int *arr = (int *)malloc(maxNumbers * sizeof(int));

    printf("Jenis Algoritma\tJumlah Bilangan\tWaktu Eksekusi (ms)\n");

    for (int n = step; n <= maxNumbers; n += step) {
        printf("Bubble Sort\t%dk\t", n / 1000);
        generateNumbers(arr, n);

        char unsortedFilename[20];
        sprintf(unsortedFilename, "unsorted_%dk.txt", n / 1000);
        writeUnsortedToFile(arr, 0, n, unsortedFilename);

        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC; // in milliseconds
        printf("%.2f\n", time_taken);

        char sortedFilename[20];
        sprintf(sortedFilename, "bubble_sorted_%dk.txt", n / 1000);
        writeSortedToFile(arr, 0, n, sortedFilename);
    }

    for (int n = step; n <= maxNumbers; n += step) {
        printf("Selection Sort\t%dk\t", n / 1000);
        generateNumbers(arr, n);

        char unsortedFilename[20];
        sprintf(unsortedFilename, "unsorted_%dk.txt", n / 1000);
        writeUnsortedToFile(arr, 0, n, unsortedFilename);

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC; // in milliseconds
        printf("%.2f\n", time_taken);

        char sortedFilename[20];
        sprintf(sortedFilename, "selection_sorted_%dk.txt", n / 1000);
        writeSortedToFile(arr, 0, n, sortedFilename);
    }

    for (int n = step; n <= maxNumbers; n += step) {
        printf("Insertion Sort\t%dk\t", n / 1000);
        generateNumbers(arr, n);

        char unsortedFilename[20];
        sprintf(unsortedFilename, "unsorted_%dk.txt", n / 1000);
        writeUnsortedToFile(arr, 0, n, unsortedFilename);

        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC; // in milliseconds
        printf("%.2f\n", time_taken);

        char sortedFilename[20];
        sprintf(sortedFilename, "insertion_sorted_%dk.txt", n / 1000);
        writeSortedToFile(arr, 0, n, sortedFilename);
    }

    free(arr); // Free dynamically allocated memory

    return 0;
}
