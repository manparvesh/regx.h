/*********************************************************
*           Created by manparvesh on 7/6/18.
*********************************************************/

#include <stdlib.h>
#include <string.h>
#include "regx.h"

/*********************************************************
*           Private methods declarations
*********************************************************/
bool match(char *pattern, char *text);

bool match_at_beginning(char *pattern, char *text);

bool match_star(int c, char *pattern, char *text);

char *string_concat(const char *s1, const char *s2);

/*********************************************************
*           Public methods implementations
*********************************************************/
/**
 * Search for a regex pattern in the text
 * */
char **search_all(char *pattern, char *text) {
    return NULL;
}

/**
 * Search for all matches for a regex pattern in the text
 * */
bool search(char *pattern, char *text) {
    if (pattern[0] == '^') {
        return match(pattern + 1, text);
    }
    return match(string_concat(".*", pattern), text);
}

/*********************************************************
*           Private methods implementations
*********************************************************/

bool match(char *pattern, char *text) {
    if (pattern[0] == '^')
        return match_at_beginning(pattern + 1, text);
    do {
        // must look even if string is empty
        if (match_at_beginning(pattern, text))
            return true;
    } while (*text++ != '\0');
    return false;
}

bool match_at_beginning(char *pattern, char *text) {
    if (pattern[0] == '\0') {
        return true;
    }
    if (pattern[1] == '*') {
        return match_star(pattern[0], pattern + 2, text);
    }
    if (pattern[0] == '$' && pattern[1] == '\0') {
        return *text == '\0';
    }
    if (*text != '\0' && (pattern[0] == '.' || pattern[0] == *text))
        return match_at_beginning(pattern + 1, text + 1);
    return false;
}

bool match_star(int c, char *pattern, char *text) {
    do {
        // a `*` matches zero or more instances
        if (match_at_beginning(pattern, text))
            return true;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return false;
}

char *string_concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
