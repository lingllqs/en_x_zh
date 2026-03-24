#include "../src/print.h"

int main() {
	const char *s1 = "hello world";
	const char *s2 = "你好世界";
	const char *s3 = "hello 世界";

	print(s1);
	print(s2);
	print(s3);
	return 0;
}
