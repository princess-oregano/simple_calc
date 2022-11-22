#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <sys/stat.h>

enum file_err {
        ERR_NO_ERR = 0,
        ERR_ALLOC  = 1,
        ERR_STATS  = 2,
        ERR_OPEN   = 3,
};

struct file_t {
        FILE *stream;
        struct stat stats {};
};

// Parses cmd-line arguments.
char *
parse_args(int argc, char *argv[]);
// Opens file and gets info about it.
int
get_file(const char *filename, file_t *file, const char *mode);
// Reads file into a buffer.
int
read_file(char **buffer, file_t *file);
// Closes file stream and free allocated for text buffer space.
void
close_file(file_t *file);

#endif // FILE_H

