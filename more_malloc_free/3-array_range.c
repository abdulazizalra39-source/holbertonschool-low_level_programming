#include "main.h"

/**
 * array_range - Creates an array of integers from min to max
 * @min: The first value
 * @max: The last value
 *
 * Return: A pointer to the array, or NULL if min > max or on failure
 */
int *array_range(int min, int max)
{
	int *arr;
	int i;

	if (min > max)
		return (NULL);
	arr = malloc(sizeof(int) * (max - min + 1));
	if (arr == NULL)
		return (NULL);
	for (i = 0; i <= max - min; i++)
		arr[i] = min + i;
	return (arr);
}
