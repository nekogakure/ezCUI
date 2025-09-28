#ifndef EZ_CUI_UTIL_H
#define EZ_CUI_UTIL_H

#include <stdio.h>

/**
 * @def INFO
 * @brief 情報メッセージを表示するマクロ
 * @param format フォーマット文字列
 * @param ... 可変引数
 */
#define INFO(format, ...)  printf("\033[32m###\033[0m\t" format "\n", ##__VA_ARGS__)

/**
 * @def ERROR
 * @brief エラーメッセージを表示するマクロ
 * @param format フォーマット文字列
 * @param ... 可変引数
 */
#define ERROR(format, ...) fprintf(stderr, "\033[31mERR\033[0m\t" format "\n", ##__VA_ARGS__)

/**
 * @def WARN
 * @brief 警告メッセージを表示するマクロ
 * @param format フォーマット文字列
 * @param ... 可変引数
 */
#define WARN(format, ...)  fprintf(stderr, "\033[33m///\033[0m\t" format "\n", ##__VA_ARGS__)


#ifndef DEV
/**
 * @def DEBUG
 * @brief デバッグメッセージを表示するマクロ
 * @param format フォーマット文字列
 * @param ... 可変引数
 * @note DEBUGマクロは定数DEVが定義されている場合にのみ有効になります。
 */
#define DEBUG(format, ...) fprintf(stderr, "\033[34m***\033[0m\t" format "\n", ##__VA_ARGS__)

#else
#define DEBUG(format, ...) ;
#endif // DEV

/**
 * @brief 文字列を下線付きで表示
 */
void underline(const char* str);

/**
 * @fn menu_select
 * @brief メニュー選択を表示し、ユーザーの選択を取得
 * @param title メニューのタイトル
 * @param items メニュー項目の配列ポインタ
 * @param count メニュー項目の数
 * @return 選択された項目のインデックス番号
 */
int menu_select(const char* title, const char* items[], int count);

#endif //EZ_CUI_UTIL_H