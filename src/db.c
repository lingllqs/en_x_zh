#include "db.h"

#include <sqlite3.h>
#include <stdio.h>


sqlite3 *db_open(const char *path) {
	sqlite3 *db;
	if (sqlite3_open(path, &db) != SQLITE_OK) {
		fprintf(stderr, "打开数据库失败: %s\n", sqlite3_errmsg(db));
		return NULL;
	}

	return db;
}

void db_close(sqlite3 *db) {
    if (db) {
        sqlite3_close(db);
    }
}
