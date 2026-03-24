#include "cli.h"

#include <stdio.h>
#include <string.h>

#include "query.h"

#define MAX 128

void run_cli(sqlite3 *db) {
    char input[MAX];

    printf("📚 Stardict CLI (输入 q 退出)\n");

    while (1) {
        printf("\n输入: ");

        if (!fgets(input, MAX, stdin)) break;

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "q") == 0) break;

        if (strlen(input) == 0) continue;

        query_en(db, input);
    }
}
