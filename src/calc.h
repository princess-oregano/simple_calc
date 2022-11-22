// Later wright explanation to everything.

#ifndef CALC_H
#define CALC_H

// Main rule.
int
get_g(char **buffer);
// Add/sub rule.
int
get_e(char **buffer);
// Mul/div rule.
int
get_t(char **buffer);
// Brackets rule.
int
get_p(char **buffer);
// Numbers rule.
int
get_n(char **buffer);

#endif // CALC_H

