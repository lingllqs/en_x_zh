#ifndef QUERY_H
#define QUERY_H

#include <sqlite3.h>

void query_en_to_zh(sqlite3 *db, const char *word);
void query_zh_to_en(sqlite3 *db, const char *zh);
void query_prefix(sqlite3 *db, const char *prefix);


#endif
