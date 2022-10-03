#include <stdio.h>
#include "tools/color.h"
#include "tools/hint.h"

// all kinds of visual hints
static const char *BANNER = "\
██╗  ██╗███████╗███████╗███╗   ██╗███████╗ ██████╗██╗  ██╗███████╗███╗   ██╗\n\
██║ ██╔╝██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝██║  ██║██╔════╝████╗  ██║\n\
█████╔╝ █████╗  █████╗  ██╔██╗ ██║█████╗  ██║     ███████║█████╗  ██╔██╗ ██║\n\
██╔═██╗ ██╔══╝  ██╔══╝  ██║╚██╗██║██╔══╝  ██║     ██╔══██║██╔══╝  ██║╚██╗██║\n\
██║  ██╗███████╗███████╗██║ ╚████║███████╗╚██████╗██║  ██║███████╗██║ ╚████║\n\
╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═══╝\n\
";

static const char *SUCCESS = "==> Operation Successful! <==";
static const char *FAILURE = "==> Operation Failed! <==";
static const char *ILLEGAL = "==> Illegal Input! <==";
static const char *LOADING = "==> Loading ... <==";
static const char *EXITING = "==> Exiting ... <==";

static const char *INVALID = "\
██╗███╗   ██╗██╗   ██╗ █████╗ ██╗     ██╗██████╗ \n\
██║████╗  ██║██║   ██║██╔══██╗██║     ██║██╔══██╗\n\
██║██╔██╗ ██║██║   ██║███████║██║     ██║██║  ██║\n\
██║██║╚██╗██║╚██╗ ██╔╝██╔══██║██║     ██║██║  ██║\n\
██║██║ ╚████║ ╚████╔╝ ██║  ██║███████╗██║██████╔╝\n\
╚═╝╚═╝  ╚═══╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝╚═╝╚═════╝ \n\
";

void WelcomeMessage()
{
    printf("\n%s%sWelcome to%s\n", BOLD, FRONT_RED, RESET);
    printf("%s%s%s%s\n", FRONT_BLUE, BOLD, BANNER, RESET);
}

void SuccessMessage() { printf("\n%s%s%s\n\n", FRONT_GREEN, SUCCESS, RESET); }
void FailureMessage() { printf("\n%s%s%s\a\n\n", FRONT_RED, FAILURE, RESET); }
void IllegalMessage() { printf("\n%s%s%s\a\n\n", FRONT_RED, ILLEGAL, RESET); }
void LoadingMessage() { printf("\n%s%s%s\n\n", FRONT_BLUE, LOADING, RESET); }
void ExitingMessage() { printf("\n%s%s%s\n\n", FRONT_RED, EXITING, RESET); }
void InvalidMessage()
{
    printf("\n%s%s%s\n\n", FRONT_RED, INVALID, RESET);
    printf("\n%s%sThis Function is Waiting For you to Implement ...%s\n\n",
           FRONT_RED, BOLD, RESET);
}
