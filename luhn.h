
#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

char* cleanstring(const char* inputstring);
int char_to_int(char input);
bool luhn(const char *num);

#endif