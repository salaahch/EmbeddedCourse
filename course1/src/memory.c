#include "memory.h"

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
    if (dst > src && dst < src + length) {
        size_t i = length; 
        while (i > 0) 
        { 
            *(dst + i - 1) = *(src + i - 1); 
            i--; 
        } 
    }
    else {
        size_t i=0;
        while (i < length)
        {   
        *(dst+i)=*(src+i);
        i++;
        }   
    }
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
     size_t i=0;
        while (i < length)
        {   
        *(dst+i)=*(src+i);
        i++;
        }
        return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
    size_t i = 0;
    while ( i < length)
    {
        *(src+i)=value;
        i++;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
    size_t i = 0;
    while ( i < length)
    {
        *(src+i)=0;
        i++;
    }
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
    size_t i = 0;
    while ( i < length/2) {
        uint8_t temp=*(src+i);
        *(src+i)=*(src+length-1-i);
        *(src+length-1-i)=temp;
        i++;
    }
    return src;
}

int32_t * reserve_words(size_t length) {
    int32_t *var=(int32_t *) malloc(length * sizeof(int32_t));
    return var;
}

void free_words(int32_t * src) {
    free(src);
}