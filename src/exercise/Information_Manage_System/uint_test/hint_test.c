/**
 * Author:   KeeneChen
 * DateTime: 2022.02.06-21:39:26
 * Description: hint module uint testing
 * command: xmake && xmake r hint
 */

#include <stdio.h>
#include "tools/color.h"
#include "tools/hint.h"

int main(void)
{
    WelcomeMessage();
    SuccessMessage();
    FailureMessage();
    IllegalMessage();
    LoadingMessage();
    ExitingMessage();
    InvalidMessage();

    return 0;
}