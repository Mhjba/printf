#include "main.h"

/**
 * extract_size - Determines the size of the argument data type.
 * @formatSpecifier: Format specifier string.
 * @currentIndex: Current index within the formatSpecifier string.
 *
 * Return: Size of the argument (e.g., S_LONG for 'l', S_SHORT for 'h', or 0 if no size modifier).
 */
int extract_size(const char *formatSpecifier, int *currentIndex)
{
    int nextIndex = *currentIndex + 1;  /* Move to the next character in the formatSpecifier string. */
    int argumentSize = 0;  /* Initialize the argument size to zero. */

    /* Check if the next character in the formatSpecifier is 'l' (long). */
    if (formatSpecifier[nextIndex] == 'l') {
        argumentSize = SIZE_LONG;  /* Set the argument size to SIZE_LONG. */
    }
    /* Check if the next character in the formatSpecifier is 'h' (short). */
    else if (formatSpecifier[nextIndex] == 'h') {
        argumentSize = SIZE_SHORT;  /* Set the argument size to SIZE_SHORT. */
    }

    /* Update the currentIndex to the next index. */
    if (argumentSize == 0) {
        *currentIndex = nextIndex - 1;  /* No size modifier found, so revert the currentIndex. */
    } else {
        *currentIndex = nextIndex;  /* Update currentIndex to the next index. */
    }

    return argumentSize;  /* Return the determined argument size. */
}
#include "main.h"

/**
 * extract_width - Calculate the width for printing.
 * @formatString: The format string to analyze.
 * @currentIndex: Pointer to the current index within the format string.
 * @argsList: List of arguments to be printed.
 *
 * Return: Calculated width.
 */
int extract_width(const char *formatString, int *currentIndex, va_list argsList)
{
    int index = *currentIndex + 1; /* Start checking after the '%' */
    int width = 0;

    /* Loop through the format string to find the width value */
    for (; formatString[index] != '\0'; index++)
    {
        /* Check if the character is a digit */
        if (is_digit_character(formatString[index]))
        {
            width *= 10;
            width += formatString[index] - '0';
        }
        /* Check if width is specified as an asterisk (*) */
        else if (formatString[index] == '*')
        {
            index++; /* Move past the asterisk */
            width = va_arg(argsList, int); /* Get width from arguments */
            break;
        }
        else
        {
            break; /* Stop if a non-digit, non-asterisk character is encountered */
        }
    }

    /* Update the current index to point to the last processed character */
    *currentIndex = index - 1;

    return width;
}
