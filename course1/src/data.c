#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {

    uint8_t *p = ptr;
    int is_negative = 0;
    if (data < 0 && base == 10) {
        is_negative = 1;
        data = -data;
    }
    uint8_t *start = p;
    do {
        int32_t rem = data % base;
        if (rem < 10) {
            *p = '0' + rem;
        } else {
            *p = 'A' + (rem - 10);
        }
        p++;
        data /= base;
    } while (data > 0);

    if (is_negative) {
        *p = '-';
        p++;
    }

    *p = '\0';
    p++;
    uint8_t *end = p - 2;
    while (start < end) {
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return (uint8_t)(p - ptr);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int sign = 1;
    if (*ptr == '-') {
        sign = -1;
        ptr++;
        digits--;
    }
    while (digits > 0) {
        uint8_t c = *ptr;
        int32_t value;

        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = 10 + (c - 'A');
        } else if (c >= 'a' && c <= 'f') {
            value = 10 + (c - 'a');
        } else {
            value = 0;
        }
        result = result * base + value;
        ptr++;
        digits--;
    }

    return result * sign;
}
