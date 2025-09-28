#ifndef EZ_CUI_HELPER_H
#define EZ_CUI_HELPER_H

typedef struct args {
    // 必要なら引数情報を追加
} args;

typedef struct {
    char *name;                   // コマンド名
    char *description;            // コマンド説明
    struct option *options;       // オプション配列
    int option_count;             // オプション数
    struct command *subcommands;  // サブコマンド配列
    int subcommand_count;         // サブコマンド数
    void (*action)(void *context, struct args *args); // 実行関数
} command_t;

#endif //EZ_CUI_HELPER_H