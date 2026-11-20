#include <stdlib.h>
#include "dog.h"

/**
 * str_len - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of s
 */
int str_len(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * str_cpy - Copies a string
 * @dest: The buffer to copy to
 * @src: The string to copy
 *
 * Return: A pointer to dest
 */
char *str_cpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - Creates a new dog with copies of name and owner
 * @name: The dog's name
 * @age: The dog's age
 * @owner: The dog's owner
 *
 * Return: A pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);
	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	d->name = malloc(sizeof(char) * (str_len(name) + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	d->owner = malloc(sizeof(char) * (str_len(owner) + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	str_cpy(d->name, name);
	str_cpy(d->owner, owner);
	d->age = age;
	return (d);
}
