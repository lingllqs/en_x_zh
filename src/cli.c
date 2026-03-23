#include "cli.h"
#include "query.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 128

static int is_chinese(const char *str) {
    while (*str) {
        if ((unsigned char)*str > 127) return 1;
        str++;
    }
    return 0;
}

void run_cli(sqlite3 *db) {
    char input[MAX_INPUT];

    printf("📚 Stardict CLI (q退出)\n");

    while (1) {
        printf("\n请输入: ");
        if (!fgets(input, sizeof(input), stdin)) break;

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "q") == 0) break;

        if (strlen(input) == 0) continue;

        if (is_chinese(input)) {
            query_zh_to_en(db, input);
        } else {
            query_en_to_zh(db, input);
            query_prefix(db, input);
        }
    }
}
