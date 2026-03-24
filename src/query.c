#include "query.h"
#include "render.h"
#include <stdio.h>
#include <string.h>

void query_en(sqlite3 *db, const char *word) {
    const char *sql =
        "SELECT word, phonetic, definition, translation "
        "FROM stardict WHERE word = ? COLLATE NOCASE;";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, word, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {

        render_entry(
            (const char*)sqlite3_column_text(stmt, 0),
            (const char*)sqlite3_column_text(stmt, 1),
            (const char*)sqlite3_column_text(stmt, 2),
            (const char*)sqlite3_column_text(stmt, 3)
        );

    } else {
        printf("❌ 未找到单词\n");
    }

    sqlite3_finalize(stmt);
}

