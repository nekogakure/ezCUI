#ifndef EZ_CUI_H
#define EZ_CUI_H

#include "helper.h"

void c_register_command(command_t * cmd);

int c_run(int argc, char **argv);

void c_set_version(const char *version);

void c_set_appname(const char *appname);

void c_set_author(const char *author);

#endif // EZ_CUI_H