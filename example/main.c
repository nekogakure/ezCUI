#include "ez_cui.h"
#include <stdio.h>

#define DEV

void test(void *context, struct args *args) {
    INFO("Hello, ezCUI!");
    WARN("This is a warning message.");
    ERROR("This is an error message.");
    DEBUG("This is a debug message.");

    printf("\n\n\n");
    underline("This is an underlined text.");

    const char* fruits[] = {"apple", "orange", "banana"};
    const int selected = menu_select("Which do you like fruit?", fruits, 3);
    INFO("you select: %s", fruits[selected]);
}

int main(const int argc, char **argv) {

    c_init();

    c_set_appname("Test App");
    c_set_author("nekogakure");
    c_set_version("v1.0.0");

    command_t test_cmd = {
        .name = "test",
        .description = "run test",
        .options = NULL,
        .option_count = 0,
        .subcommands = NULL,
        .subcommand_count = 0,
        .action = test
    };
    c_register_command(&test_cmd);

    return c_run(argc, argv);
}