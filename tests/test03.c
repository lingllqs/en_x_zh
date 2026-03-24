#include <stdio.h>
#include <string.h>

int utf8_strlen(const char *s) {
	int count = 0;
	unsigned char c;

	while (*s) {
		c = (unsigned char)*s;

		if ((c & 0xc0) != 0x80) {
			count++;
		}
		s++;
	}
	
	return count;
}

int main() {
	const char *s = "hello 世界";
	printf("%ld\n", strlen(s));
	printf("字符数: %d\n", utf8_strlen(s));
	return 0;
}
