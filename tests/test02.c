#include <stdio.h>

int utf8_char_len(unsigned char c) {
    if ((c & 0x80) == 0x00) return 1;
    else if ((c & 0xE0) == 0xC0) return 2;
    else if ((c & 0xF0) == 0xE0) return 3;
    else if ((c & 0xF8) == 0xF0) return 4;
    else return -1;
}

int main() {
    const char *s = "Hello 世界";

    while (*s) {
        int len = utf8_char_len((unsigned char)*s);
        printf("字符长度: %d\n", len);
        s += len;
    }
}
