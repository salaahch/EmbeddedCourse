/******************************************************************************
 * Copyright (C) 2025 by Gemini Coder
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Gemini Coder is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Header file for basic statistical analysis functions.
 * * Contains function declarations for calculating and printing statistics 
 * (min, max, mean, median) for an array of unsigned characters. 
 * Also includes sorting and array printing functions.
 *
 * @author Salah Eddine Jamel
 * @date October 14, 2025
 *
 */

#ifndef __STATS_H__
#define __STATS_H__
#include "platform.h"
/* The fixed array size for testing */
#define SIZE (40)

/**
 * @brief Prints the statistics of an array.
 *
 * Prints the minimum, maximum, mean, and median of the data set.
 * NOTE: For the median to be accurate, the array must be sorted descending 
 * before calling this function.
 *
 * @param array The array of unsigned chars to analyze.
 * @param length The number of elements in the array.
 * @return void
 */
void print_statistics(unsigned char *array, unsigned int length);


/**
 * @brief Prints the array elements.
 *
 * Given an array of data and a length, prints the array elements to the screen.
 *
 * @param array The array of unsigned chars to print.
 * @param length The number of elements in the array.
 * @return void
 */
void print_array(unsigned char *array, unsigned int length);


/**
 * @brief Finds the median of the array.
 *
 * Given a SORTED array of data and a length, calculates and returns the median.
 *
 * @param array The array of unsigned chars (must be sorted descending).
 * @param length The number of elements in the array.
 * @return float The calculated median value.
 */
float find_median(unsigned char *array, unsigned int length);


/**
 * @brief Finds the mean of the array.
 *
 * Given an array of data and a length, calculates and returns the mean.
 *
 * @param array The array of unsigned chars to analyze.
 * @param length The number of elements in the array.
 * @return float The calculated mean value.
 */
float find_mean(unsigned char *array, unsigned int length);


/**
 * @brief Finds the maximum value in the array.
 *
 * Given an array of data and a length, finds and returns the maximum value.
 *
 * @param array The array of unsigned chars to analyze.
 * @param length The number of elements in the array.
 * @return unsigned char The maximum value found.
 */
unsigned char find_maximum(unsigned char *array, unsigned int length);


/**
 * @brief Finds the minimum value in the array.
 *
 * Given an array of data and a length, finds and returns the minimum value.
 *
 * @param array The array of unsigned chars to analyze.
 * @param length The number of elements in the array.
 * @return unsigned char The minimum value found.
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);


/**
 * @brief Sorts the array in descending order.
 *
 * Sorts the array from largest to smallest. The zeroth element will be the largest.
 * The sort is performed in place.
 *
 * @param array The array of unsigned chars to sort.
 * @param length The number of elements in the array.
 * @return void
 */
void sort_array(unsigned char *array, unsigned int length);

#endif /* __STATS_H__ */

