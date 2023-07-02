#include "main.h"


/**
 * strtow - function that splits a string into words
 * Description: function that splits a string into words
 * @str: The string to split
 * @count_words: count words
 *
 * Return: Pointer to an array of strings (words), or NULL on failure
 */
int count_words(char *str)
{
	int count = 0;
	int i = 0;
	int in_word = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

char **strtow(char *str)
{
	int i, j, k, len, word_count;
	char **words;

	if (str == NULL || strlen(str) == 0)
		return (NULL);

	word_count = count_words(str);
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		len = 0;
		while (str[i + len] != ' ' && str[i + len] != '\0')
			len++;

		words[j] = (char *)malloc((len + 1) * sizeof(char));
		if (words[j] == NULL)
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (k = 0; k < len; k++)
			words[j][k] = str[i + k];
		words[j][k] = '\0';
		j++;
		i += len;
	}

	words[j] = NULL;
	return (words);
}

