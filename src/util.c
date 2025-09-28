#include <stdio.h>
#include "ez_cui.h"
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @fn underline
 * @brief 文字列を下線付きで表示する
 * @param str 表示する文字列
 */
void underline(const char* str) {
    printf("\033[4m%s\033[0m\n", str);
}

/**
 * @fn menu_select
 * @brief メニューを表示し、ユーザーに選択させる
 * @param title メニューのタイトル
 * @param items メニュー項目の配列
 * @param count 項目数
 * @return 選択された項目のインデックス
 */
int menu_select(const char* title, const char* items[], const int count) {
    printf("\n\n\n");
    if (count <= 0) return -1;
    int selected = 0;
    const int menu_lines = 1 + count; // タイトル+項目数

    underline(title);
    for (int i = 0; i < count; ++i) {
        if (i == selected) {
            printf("\t> %s <\n", items[i]);
        } else {
            printf("\t  %s  \n", items[i]);
        }
    }
    while (1) {
        // カーソルをメニュー範囲の先頭に戻す
        printf("\033[%dA", menu_lines);
        // メニュー部分を消去（空行で上書き）
        for (int i = 0; i < menu_lines; ++i) {
            printf("\r%80s\n", "");
        }
        // 再度カーソルをメニュー範囲の先頭に戻す
        printf("\033[%dA", menu_lines);
        // タイトル表示
        printf("\033[34m???\033[0m\t");
        underline(title);
        // 項目表示
        for (int i = 0; i < count; ++i) {
            if (i == selected) {
                printf("> %s <\n", items[i]);
            } else {
                printf("  %s  \n", items[i]);
            }
        }
        // キー入力取得
        int ch = _getch();
        if (ch == 224 || ch == 0) {
            ch = _getch();
            if (ch == 72) {
                selected = (selected - 1 + count) % count;
            } else if (ch == 80) {
                selected = (selected + 1) % count;
            }
        } else if (ch == '\r') {
            // カーソルをメニュー範囲の先頭に戻す
            printf("\033[%dA", menu_lines);
            // メニュー部分を消去（空行で上書き）
            for (int i = 0; i < menu_lines; ++i) {
                printf("\r%80s\n", "");
            }
            printf("\t> %s <\n", items[selected]);
            return selected;
        }
    }
}

/**
 * @fn input_field
 * @brief ユーザーからの入力を取得するフィールドを表示(
 * @param prompt プロンプトメッセージ
 * @param max_len 入力可能な最大文字数
 * @return 入力された文字列
 * @note 現在バグります
 */
char* input_field(const char* prompt, const int max_len) {
    printf("%s\n", prompt);
    int term_width = 80;
    const char* env = getenv("COLUMNS");
    if (env) {
        const int w = atoi(env);
        if (w > 20) term_width = w;
    }
    int field_width = term_width - 4;
    if (field_width > max_len) field_width = max_len;
    // Unicode枠線でボックス描画
    printf("┌");
    for (int i = 0; i < field_width; ++i) printf("─");
    printf("┐\n");
    printf("│");
    for (int i = 0; i < field_width; ++i) printf(" ");
    printf("│\n");
    fflush(stdout);
    char* buffer = (char*)malloc(field_width + 1);
    if (!buffer) return NULL;
    int len = 0;
    while (1) {
        // 入力欄の行にカーソルを戻す
        printf("\033[A");
        int ch = getchar();
        if (ch == '\n' || ch == '\r') {
            // 入力終了時は下の行にカーソルを移動
            printf("\033[B");
            break;
        } else if ((ch == '\b' || ch == 127) && len > 0) {
            len--;
            buffer[len] = '\0';
        } else if (ch >= 32 && ch <= 126 && len < field_width) {
            buffer[len++] = (char)ch;
            buffer[len] = '\0';
        }
        // 入力欄を上書き表示
        printf("\r│%.*s%*s│\n", field_width, buffer, field_width - len, "");
        fflush(stdout);
        // 下の行にカーソルを戻す
        printf("\033[B");
    }
    printf("└");
    for (int i = 0; i < field_width; ++i) printf("─");
    printf("┘\n");
    return buffer;
}
