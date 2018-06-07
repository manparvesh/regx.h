/*********************************************************
 *           Created by manparvesh on 7/6/18.
 *********************************************************/

#ifndef REGX_H_REGX_H
#define REGX_H_REGX_H
#include <stdbool.h>

/**
 * Search for a regex pattern in the text
 * */
bool search(char *pattern, char *text);

/**
 * Search for all matches for a regex pattern in the text
 * */
char **search_all(char *pattern, char *text);

#endif //REGX_H_REGX_H
