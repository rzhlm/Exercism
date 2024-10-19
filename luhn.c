#include "luhn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int valid = 1;

char* cleanstring(const char* inputstring) {
    int len = (int)strlen(inputstring);
    char* output = malloc((len + 1) * sizeof(char));
    int runner = 0;
    for (int i = 0; i < len; i++) {
        if (inputstring[i] == ' ') {
            continue; // Skip spaces
        } if (isdigit(inputstring[i]) == false ) {
            valid = 0;
            break;
        } else {
            output[runner] = inputstring[i];
            runner++;
        }
    }
    output[runner] = '\0';
    return output;
}

int char_to_int(char input) {
    int output;
    output = input - '0';
    return output;
}

bool luhn(const char *num) {
    valid = 1;
    int sum_total = 0;
    int intermediate = 0;
    char* cleaned_string;
    
    if (strlen(num) <= 0) {
        return false;
    } if (strlen(num) == 1 && num[0] == '0') return false;

    cleaned_string = cleanstring(num);
    
    if (valid == 0) {
        free(cleaned_string);
        return false;
    }
    if (strlen(cleaned_string) <= 0) {
        free(cleaned_string);
        return false;
    }
    int clean_len = (int)strlen(cleaned_string);
    // 0 - 1 - 2: total 3
    //     X
    // 0 - 1: total 2
    // X
    // 0 - 1 - 2 - 3: total 4
    // X       X
    // 0 - 1 - 2 - 3 - 4: total 5
    //     X       X
    for (int i=(clean_len-1); i >= 0 ; i--) {
        if (((i % 2 != 0) && (clean_len % 2 != 0))
           || ((i % 2 == 0 || i == 0) && (clean_len % 2 == 0))) {
            // do if multiple of second
            intermediate = 2 * char_to_int(cleaned_string[i]);
            if (intermediate > 9) {
                intermediate -= 9;
            }
            sum_total += intermediate;
        } else {
            //if not 
            sum_total += char_to_int(cleaned_string[i]);
        }
    }
    if (clean_len == 1 && cleaned_string[0] == '0') return false;
    free(cleaned_string);
    if (sum_total % 10 == 0) {
        return true;
    } else {
        return false;
    }    
    return false;
}