#include "main.h"
/**
 * wildcmp - Compares two strings and checks for wildcard '*'
 * @s1: The first string
 * @s2: The second string with possible wildcards
 *
 * Return: 1 if the strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0') /* Both strings reached the end */
		return (1);

	if (*s1 == *s2) /* Characters match, move to next */
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*') /* Wildcard found */
	{
		if (*s1 == '\0') /* Check if s1 reached the end */
			return (wildcmp(s1, s2 + 1));

		if (wildcmp(s1 + 1, s2) == 1) /* Skip character in s1 */
			return (1);

		return (wildcmp(s1, s2 + 1)); /* Skip wildcard in s2 */
	}

	return (0); /* Characters are different */
}
