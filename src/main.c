#include "db.h"
#include "cli.h"

int main() {
    sqlite3 *db = db_open("data/stardict.db");
    if (!db) return 1;

    run_cli(db);

    db_close(db);
    return 0;
}
