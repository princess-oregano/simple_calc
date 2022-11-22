#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <assert.h>
#include "file.h"
#include "log.h"

char *
parse_args(int argc, char *argv[])
{
        if (argc > 2) {
                log("Error: too many arguments.\n");
                return nullptr;
        } else {
                return argv[1];
        }
}

int
get_file(const char *filename, file_t *file, const char *mode)
{
        log("Entering %s.\n", __PRETTY_FUNCTION__);

        if ((file->stream = fopen(filename, mode)) == nullptr) {
                log("Error: Couldn't open %s.\n", filename);

                return ERR_OPEN;
        }

        if (stat(filename, &file->stats) != 0) {
                log("Error: Coudn't get stats of %s.\n", filename);
                return ERR_STATS;
        }

        log("Exiting %s.\n", __PRETTY_FUNCTION__);

        return ERR_NO_ERR;
}

int
read_file(char **buffer, file_t *file)
{
        log("Entering %s.\n", __PRETTY_FUNCTION__);

        assert(file);

        *buffer = (char *) mmap(NULL, (size_t) file->stats.st_size, PROT_READ,
                               MAP_PRIVATE, fileno(file->stream), 0);

        if (*buffer == MAP_FAILED) {
                log("Error: Couldn't allocate memory.\n");
                return ERR_ALLOC;
        }

        log("Exiting %s.\n", __PRETTY_FUNCTION__);

        return ERR_NO_ERR;
}

void
close_file(file_t *file)
{
        fclose(file->stream);
}

