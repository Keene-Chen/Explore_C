#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NAME "key_app"

static struct option long_options[] = { { "path", required_argument, 0, 'p' },
                                        { "version", no_argument, 0, 'v' },
                                        { "help", no_argument, 0, 'h' },
                                        { 0, 0, 0, 0 } };

static void usage(const char* name)
{
    int i = 0;
    printf("Debug the driven application.\n\n");
    printf("\e[4;1;33mUsage:\e[0m\n");
    printf("\e[1;31m  %s [OPTIONS]\e[0m\n\n", NAME);
    printf("\e[4;1;33mOptions:\e[0m\n");

    printf("  -%c, --%-7s Driver path name\n", long_options[i].val, long_options[i].name);
    i++;
    printf("  -%c, --%-7s Print %s version\n", long_options[i].val, long_options[i].name, NAME);
    i++;
    printf("  -%c, --%-7s Print help\n", long_options[i].val, long_options[i].name);
    i++;
}

int main(int argc, char** argv)
{
    int ch;
    int option_index = 0;

    while (1) {
        ch = getopt_long_only(argc, argv, "p:vh", long_options, &option_index);
        if (ch == -1)
            break;
        switch (ch) {
        case 'p':
            printf("option c with value \"%s\"\n", optarg);
            break;
        case 'v':
            printf("%s v1.0.0\n", argv[0]);
            break;
        case 'h':
            usage(argv[0]);
            break;
        case '?':
            break;
        default:
            printf("?? getopt returned character code 0%o ??\n", ch);
        }
    }

    /*
    if (optind < argc) {
            printf("non-option: ");
            while (optind < argc)
                printf("%s ", argv[optind++]);
            printf("\n");
            usage(NAME);
        }
    */

    return 0;
}
