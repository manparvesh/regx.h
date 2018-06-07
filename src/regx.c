/*********************************************************
*           Created by manparvesh on 7/6/18.
*********************************************************/

#include <stdlib.h>
#include "regx.h"

/*********************************************************
*           Private methods declarations
*********************************************************/
bool match_one(char *pattern, char *text);

bool match(char *pattern, char *text);

bool match_at_beginning(char *pattern, char *text);

bool match_star(int c, char *pattern, char *text);

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

// todo complete/remove this method. will probably not be used
bool match_one(char *pattern, char *text) {
    if (pattern[0] == '\0') {
        return true;
    }
    if (text[0] == '\0') {
        return false;
    }
    if (pattern[0] == '*' && pattern[1] == '\n') {
        return true;
    }
    if (pattern[0] == '$' && pattern[1] == '\n') {
        return *text == '\0';
    }
    if (*text != '\0' && (pattern[0] == '.' || pattern[0] == *text))
        return match_at_beginning(pattern + 1, text + 1);
    return false;
}

bool match_at_beginning(char *pattern, char *text) {
    if (pattern[0] == '\0') {
        return true;
    }
    if (pattern[1] == '*') {
        return match_star(pattern[0], pattern + 2, text);
    }
    if (pattern[0] == '$' && pattern[1] == '\n') {
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
