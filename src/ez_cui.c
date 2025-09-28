#include "../include/ez_cui.h"
#include <stdio.h>
#include <string.h>

#define MAX_COMMANDS 32
static command_t *commands[MAX_COMMANDS];
static int command_count = 0;
static const char *version_str = "unknown";
static const char *appname_str = "unknown";
static const char *author_str = "unknown";

void c_set_appname(const char *appname) {
    appname_str = appname;
}

void c_set_version(const char *version) {
    version_str = version;
}

void c_set_author(const char *author) {
    author_str = author;
}

static void help_action(void *context, struct args *args) {
    int max_name_len = 4; // "name" の長さ
    for (int i = 0; i < command_count; ++i) {
        int len = strlen(commands[i]->name);
        if (len > max_name_len) max_name_len = len;
    }

    if (max_name_len < 4) max_name_len = 4;
    if (max_name_len < 12) max_name_len = 12;

    printf("\n Available Commands\n");
    printf("------------------------------\n");
    printf(" %-*s | %s\n", max_name_len, "name", "description");
    printf("------------------------------\n");
    for (int i = 0; i < command_count; ++i) {
        printf(" %-*s | %s\n", max_name_len, commands[i]->name, commands[i]->description ? commands[i]->description : "");
    }
    printf(" %-*s | %s\n", max_name_len, "help", "Show this help message");
    printf("\n\n");
}

static void version_action(void *context, struct args *args) {
    printf("%s\n\n", appname_str);
    printf("Build: %s %s\n", __DATE__, __TIME__);
    printf("Version: %s\n", version_str);

    printf("\nAuthor: %s\n", author_str);
}

void c_register_command(command_t *cmd) {
    if (command_count < MAX_COMMANDS) {
        commands[command_count++] = cmd;
    }
}

int c_run(int argc, char **argv) {
    if (argc < 2) {
        help_action(NULL, NULL);
        return 1;
    }
    if (strcmp(argv[1], "help") == 0) {
        help_action(NULL, NULL);
        return 0;
    }
    if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        version_action(NULL, NULL);
        return 0;
    }
    for (int i = 0; i < command_count; ++i) {
        if (strcmp(argv[1], commands[i]->name) == 0) {
            if (commands[i]->action) {
                commands[i]->action(NULL, NULL);
                return 0;
            }
        }
    }
    printf("\x1b[31mcommand '%s' is not found.\x1b[0m\n please 'help' command to check commands", argv[1]);
    return 1;
}
