#include "query.h"

#include <sqlite3.h>
#include <stdio.h>

void query_en_to_zh(sqlite3 *db, const char *word) {
    const char *sql = "SELECT word,phonetic,definition,translation "
                      "FROM stardict WHERE word = ? COLLATE NOCASE;";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, word, -1, SQLITE_STATIC);

    int found = 0;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        found = 1;
        printf("\n%s\n", sqlite3_column_text(stmt, 0));

        const unsigned char *phonetic = sqlite3_column_text(stmt, 1);
        if (phonetic) {
            printf("%s\n", phonetic);
        }

        printf("%s\n", sqlite3_column_text(stmt, 2));
        printf("%s\n", sqlite3_column_text(stmt, 3));
    }

    if (!found) {
        fprintf(stderr, "未找到\n");
    }

    sqlite3_finalize(stmt);
}

void query_zh_to_en(sqlite3 *db, const char *zh) {
    const char *sql = "SELECT word, translation FROM stardict "
                      "WHERE translation LIKE ? LIMIT 10;";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    char pattern[256];
    snprintf(pattern, sizeof(pattern), "%%%s%%", zh);

    sqlite3_bind_text(stmt, 1, pattern, -1, SQLITE_STATIC);

    printf("\n🔍 中文匹配:\n");

    int count = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%s -> %s\n", sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1));
        count++;
    }

    if (!count) printf("无匹配\n");

    sqlite3_finalize(stmt);
}

void query_prefix(sqlite3 *db, const char *prefix) {
    const char *sql = "SELECT word FROM stardict WHERE word LIKE ? LIMIT 5;";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    char pattern[128];
    snprintf(pattern, sizeof(pattern), "%s%%", prefix);

    sqlite3_bind_text(stmt, 1, pattern, -1, SQLITE_STATIC);

    printf("\n💡 可能的单词:\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("  %s\n", sqlite3_column_text(stmt, 0));
    }

    sqlite3_finalize(stmt);
}
