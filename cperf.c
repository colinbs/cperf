#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <arpa/inet.h>

#include "log.h"

static struct option long_opts[] = {
    {"help", no_argument, 0, 'h'},
    {"output", required_argument, 0, 'o'},
    {0, 0, 0, 0}
};

static void print_usage(void)
{
    printf("Usage: cperf [OPTIONS]...\n");
    printf("\n");
    printf("  -h, --help\t\tshow this help.\n");
    printf("  -o, --output\t\tname of the output file. If used with together -d the\n\
            \t\t  output will be appended to the file.\n");
}

int main(int argc, char *argv[])
{
    int opt;
    int option_index = 0;
    int exit_val = EXIT_SUCCESS;
    char *error_reason = NULL;
    char *outfile = NULL;
    FILE *output_f = NULL;

    do {
        opt = getopt_long(argc, argv, "ho:", long_opts, &option_index);

        switch (opt) {
        case 'h':
            print_usage();
            exit(EXIT_FAILURE);
            break;
        case 'o':
            outfile = optarg;
            break;
        case -1:
            break;
        default:
            print_usage();
            exit(EXIT_SUCCESS);
        }
    } while (opt != -1);

    if (outfile) {
        output_f = fopen(outfile, "w");
        if (!output_f) {
            CPERF_DBG("Error opening output file");
            exit_val = EXIT_FAILURE;
            goto err;
        }
    }

err:
    if (output_f) {
        fclose(output_f);
    }

    if (error_reason) {
        CPERF_DBG(error_reason);
    }

    return exit_val;
}
