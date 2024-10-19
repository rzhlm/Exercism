#include "collatz.h"
#include <stdio.h>


step_t* stepthing(step_t* runner) {
    //printf("stepthing called\n");
    while (runner->current != 1)
    {
        if (runner->current % 2 == 0) { // even
            runner->steps++;
            runner->current /= 2;
            //printf("even-step: %d, current: %d\n",runner->current,runner->steps);
            
        } else { //odd
            runner->steps++;
            runner->current = (runner->current * 3) + 1;
            //printf("odd-step: %d, current: %d\n",runner->current,runner->steps);
        }
    }
    return runner;
}

int steps(int start) {
    if (start <= 0) return -1; 
    printf("startval: %d\n",start);
    // init runner
    step_t runner;
    //step_t *output;
    runner.current = start;
    runner.steps = 0;
    printf("initialized\n");
    //output = stepthing(&runner);
    stepthing(&runner);

    //return (int)output->steps;
    printf("returning: %d\n",runner.steps);
    return runner.steps;
}
