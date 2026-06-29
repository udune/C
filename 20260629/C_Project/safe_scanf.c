#include "common.h"
#include <stdarg.h>

int safe_scanf(const char* format, ...) {
	int expected = 0;
	for (const char* p = format; *p; p++) {
		if (*p == '%') {
			if (*(p + 1) == '%') {
				p++;
			}
			else {
				expected++;
			}
		}
	}

	va_list args;
	while (1) {
		va_start(args, format);
		int ret = vscanf(format, args);
		va_end(args);

		if (ret == expected) {
			return ret;
		}
		if (ret == EOF || feof(stdin) || ferror(stdin)) {
			return ret;
		}

		printf("잘못된 입력입니다. 다시 입력해주세요.\n");
		int c;
		while ((c = getchar()) != '\n' && c != EOF) { }
	}
}
