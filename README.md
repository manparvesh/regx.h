<div align="center">
  <h1>regx.h</h1>

  <a href="https://travis-ci.org/manparvesh/regx.h/builds" target="_blank"><img src="https://img.shields.io/travis-ci/manparvesh/regx.h.svg?style=for-the-badge" alt="Build Status"></a> 
  <a href="https://manparvesh.mit-license.org/" target="_blank"><img src="https://img.shields.io/badge/license-MIT-blue.svg?longCache=true&style=for-the-badge" alt="License"></a> 

  <p>Simple Regular Expression library written in C, inspired by <a href="https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html">this post<a></p>
</div>


### Supported operators
- `^` is the start anchor, matches the beginning of the string
- `.` matches with any character
- `$` matches end of string


### How to use
```c
char *pattern = ".*";
char *text = "abcdfseirjhewo34434jj";
assert(search(pattern, text));
```

Look at [tests/test.c](https://github.com/manparvesh/regx.h/blob/master/tests/test.c) for more examples.
