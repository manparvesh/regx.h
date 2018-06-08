/*********************************************************
 *           Created by manparvesh on 7/6/18.
 *********************************************************/

#include <assert.h>
#include "regx.h"

int main(){
    char *pattern = ".*";
    char *text = "abcdfseirjhewo34434jj";
    assert(search(pattern, text));

    pattern = "1.";
    text = "as34434jj";
    assert(!search(pattern, text));

    pattern = "^3.";
    text = "34434jj";
    assert(search(pattern, text));

    pattern = "^a3.";
    text = "as34434jj";
    assert(!search(pattern, text));

    pattern = "jj$";
    text = "as34434jj";
    assert(search(pattern, text));
}