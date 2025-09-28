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

void underline(const char* str);

char* input_field(const char* prompt, int max_len);

#endif //EZ_CUI_UTIL_H