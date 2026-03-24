#include "render.h"

#include <stdio.h>

static void line() {
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

// 自动分行打印（按 ; . 换行）
static void print_list(const char *text) {
    if (!text) return;

    printf("  • ");

    for (const char *p = text; *p; p++) {
        if (*p == ';' || *p == '\n') {
            printf("\n  • ");
            continue;
        }
        putchar(*p);
    }

    printf("\n");
}

void render_entry(const char *word, const char *phonetic, const char *definition, const char *translation) {
    line();

    printf("📖 WORD: %s\n", word ? word : "");

    if (phonetic) {
        printf("🔊 PHONETIC: %s\n", phonetic);
    }

    printf("\n📘 ENGLISH:\n");
    print_list(definition);

    printf("\n📗 CHINESE:\n");
    print_list(translation);

    line();
}
