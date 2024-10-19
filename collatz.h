



#ifndef COLLATZ_CONJECTURE_H
#define COLLATZ_CONJECTURE_H

#define ERROR_VALUE -1

typedef struct {
    int current;
    int steps;
} step_t;

int steps(int start);
step_t* stepthing(step_t* runner);

#endif