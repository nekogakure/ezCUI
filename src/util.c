#include <stdio.h>
#include "ez_cui.h"
#include <conio.h>

void underline(const char* str) {
    printf("\033[4m%s\033[0m\n", str);
}

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