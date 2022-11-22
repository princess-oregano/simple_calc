#include <stdio.h>
#include "file.h"
#include "calc.h"
#include "log.h"

int 
main(int argv, char *argc[])
{
        open_log("log.html");

        char *filename = parse_args(argv, argc);
        if (filename == nullptr) {
                log("Error: coulnd't get the filename.\n");
                return 1;
        }

        file_t file {};
        if (get_file(filename, &file, "r") != ERR_NO_ERR)
                return 1;

        char *buffer = nullptr;
        if (read_file(&buffer, &file) != ERR_NO_ERR)
                return 1;

        int val = get_g(&buffer);

        printf("Result: %d\n", val);

        close_file(&file);
        close_log();

        return 0;
}
