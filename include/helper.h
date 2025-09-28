#ifndef EZ_CUI_HELPER_H
#define EZ_CUI_HELPER_H

/**
 * @struct args
 * @brief コマンド引数情報構造体
 */
typedef struct args {
    // 必要なら引数情報を追加
} args;

/**
 * @struct command_t
 * @brief コマンド情報構造体
 */
typedef struct {
    char *name; /// コマンド名
    char *description; /// コマンド説明
    struct option *options; /// オプション配列
    int option_count; /// オプション数
    struct command *subcommands; /// サブコマンド配列
    int subcommand_count; /// サブコマンド数
    void (*action)(void *context, struct args *args); /// 実行関数（コマンドが呼び出されたときに実行される関数）
} command_t;

#endif //EZ_CUI_HELPER_H
