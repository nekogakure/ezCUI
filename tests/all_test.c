#include "../include/ez_cui.h"
#include <stdio.h>

void hello_action(void *context, struct args *args) {
    printf("Hello, ezCUI!\n");
}

int main(int argc, char **argv) {

    c_set_appname("Test App");
    c_set_author("nekogakure");
    c_set_version("v1.0.0");

    command_t hello_cmd = {
        .name = "hello",
        .description = "Print hello message",
        .options = NULL,
        .option_count = 0,
        .subcommands = NULL,
        .subcommand_count = 0,
        .action = hello_action
    };
    c_register_command(&hello_cmd);

    return c_run(argc, argv);
}