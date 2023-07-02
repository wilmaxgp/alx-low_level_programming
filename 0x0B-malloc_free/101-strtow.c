#include "main.h"

int count_words(char *str);
char **strtow(char *str);
char *extract_word(char *str);
char *trim_start(char *str);


/**
 * count_words - takes a string as input and counts words in string.
 * Description: takes a string str as input and
 * counts the number of words in the string.
 * @str: String input
 *
 * Return: total count of words.
 */
int count_words(char *str)
{
	int count = 0;
	int word_started = 0;

	while (*str)
	{
		if (*str != ' ')
		{
			if (!word_started)
			{
				count++;
				word_started = 1;
			}
		}
		else
		{
			word_started = 0;
		}

		str++;
	}
	return (count);
}

/**
 * extract_word - takes a string as input and extracts a word from it
 * Description: function takes a string as input and extracts a word from it
 * @str: String input
 *
 * Return:  pointer to the extracted word
 */
char *extract_word(char *str)
{
	char *start = str;
	int length = 0;
	char *word;

	while (*str && *str != ' ')
	{
		str++;
		length++;
	}

	word = malloc((length + 1) * sizeof(char));
	if (word == NULL)
	{
		return (NULL);
	}

	strncpy(word, start, length);
	word[length] = '\0';
	
	return (word);
}

/**
 * trim_start -  takes a string as input and removes leading spaces from it
 * Description: This Function takes a string as input
 * and removes leading spaces from it
 * @str: String input
 *
 * Return: pointer to the string
 */
char *trim_start(char *str)
{
	while (*str && *str == ' ')
	{
		str++;
	}

	return (str);
}


/**
 * strtow - function that splits the input string str into words
 * Description: function that splits the input string str into words
 * @str: string input
 *
 * Return: void
 */
char **strtow(char *str)
{
	int i;
	int j;
	int word_count;
	char **words;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	word_count = count_words(str);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}

	i = 0;
	str = trim_start(str);

	while (*str)
	{
		if (*str != ' ')
		{
			char *word = extract_word(str);
			if (word == NULL)
			{
				for (j = 0; j < i; j++)
				{
					free(words[j]);
				}
				free(words);
				return (NULL);
			}
			words[i] = word;
			i++;
			str += strlen(word);
		}
		else
		{
			str++;
		}
		str = trim_start(str);
	}

	words[i] = NULL;
	return (words);
}
