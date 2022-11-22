#include <stdio.h>
#include "calc.h"
#include "log.h"

int
get_g(char **buffer)
{
        int val = get_e(buffer);
        if (**buffer != '\n') {
                log("Error: last character is not null-terminating.\n");
                return -1;
        }

        return val;
}

int
get_e(char **buffer)
{
        int val = get_t(buffer);
        while (**buffer == '-' || **buffer == '+') {
                char op = **buffer;
                *buffer += 1;
                int val2 = get_t(buffer);
                if (op == '+') 
                        val += val2;
                else 
                        val -=val2;
        }

        return val;
}

int
get_t(char **buffer)
{
        int val = get_n(buffer);
        while (**buffer == '*' || **buffer == '/') {
                char op = **buffer;
                *buffer += 1;
                int val2 = get_p(buffer);
                if (op == '*') 
                        val *= val2;
                else 
                        val /=val2;
        }

        return val;
}

int
get_p(char **buffer)
{
        int val = 0;

        if (**buffer == '(') {
                *buffer += 1;
                val = get_e(buffer);
                if (**buffer != ')') {
                        log("Error: invalid usage of brackets.\n");
                        return -1;
                }

                *buffer += 1;
        } else {
                val = get_n(buffer);
        }

        return val;
}

int
get_n(char **buffer)
{
        int val = 0;
        char *old = *buffer;
        if ('0' <= **buffer && **buffer <= '9') {
                val = val * 10 + **buffer - '0';
                *buffer += 1;
        }

        if (old == *buffer) {
                log("Error: invalid usage.\n");
                return -1;
        }

        return val;
}

