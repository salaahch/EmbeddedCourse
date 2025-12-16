#include <stdio.h>
#include "stats.h"

void print_statistics(unsigned char *array, unsigned int length) {
    if (array == NULL || length == 0) {
        printf("Error: Array is empty or NULL.\n");
        return;
    }

    unsigned char minimum = find_minimum(array, length);
    unsigned char maximum = find_maximum(array, length);
    float mean = find_mean(array, length);
    float median = find_median(array, length);

    printf("--- Array Statistics ---\n");
    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);
    printf("Mean:    %.2f\n", mean);
    printf("Median:  %.2f\n", median);
    printf("------------------------\n");
}

void print_array(unsigned char *array, unsigned int length) {
    if (array == NULL || length == 0) {
        printf("[]\n");
        return;
    }

    printf("Array (%d elements):\n", length);
    for (unsigned int i = 0; i < length; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

float find_median(unsigned char *array, unsigned int length) {
    if (array == NULL || length == 0) {
        return 0.0f;
    }

    if (length % 2 == 0) {
        unsigned int mid_idx_1 = length / 2 - 1;
        unsigned int mid_idx_2 = length / 2;
        return (float)(array[mid_idx_1] + array[mid_idx_2]) / 2.0f;
    } else {
        return (float)array[length / 2];
    }
}

float find_mean(unsigned char *array, unsigned int length) {
    if (array == NULL || length == 0) {
        return 0.0f;
    }

    unsigned int sum = 0;
    for (unsigned int i = 0; i < length; i++) {
        sum += array[i];
    }

    return (float)sum / (float)length;
}

unsigned char find_maximum(unsigned char *array, unsigned int length) {
    if (array == NULL || length == 0) {
        return 0;
    }

    unsigned char max_val = array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
    }
    return max_val;
}

unsigned char find_minimum(unsigned char *array, unsigned int length) {
    if (array == NULL || length == 0) {
        return 0;
    }

    unsigned char min_val = array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] < min_val) {
            min_val = array[i];
        }
    }
    return min_val;
}

void sort_array(unsigned char *array, unsigned int length) {
    if (array == NULL || length <= 1) {
        return;
    }

    unsigned int i, j, max_idx;
    unsigned char temp;

    for (i = 0; i < length - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < length; j++) {
            if (array[j] > array[max_idx]) {
                max_idx = j;
            }
        }

        if (max_idx != i) {
            temp = array[i];
            array[i] = array[max_idx];
            array[max_idx] = temp;
        }
    }
}

int main() {
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                 114, 88,   45,  76, 123,  87,  25,  23,
                                 192, 126, 173,  73,  83,  49, 117, 189,
                                  63, 222, 100,   1,  37, 107,  19,  78,
                                  26,  56,  99, 110, 218, 137,   7,  52 };

    printf("C Statistical Analysis Program\n");

    printf("\n--- Step 1: Initial Array ---\n");
    print_array(test, SIZE);

    sort_array(test, SIZE);

    printf("\n--- Step 2: Sorted Array (Largest to Smallest) ---\n");
    print_array(test, SIZE);

    printf("\n--- Step 3: Calculation and Printing Statistics ---\n");
    print_statistics(test, SIZE);

    return 0;
}

