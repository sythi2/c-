#include <stdio.h>

int main() {
	char arr[100] = { "abcbabcabcbabcbabcbbcbcbcbcbabababaababaabaaabbccbbcabcbacbbabcbcbbcbcbbbbbccaaabaabaabcab" };
	//char arr[100] = { "abcbabcabcbabcba" };
	char find[100] = { "aabaabaa" };
	int ps_list[100];
	int cnt;

	int arrlen = 0;
	while (arr[++arrlen]) {};
	//printf("len = %d\n", len);

	int fail[100];
	for (;;) {
		scanf("%s", find);
		int len = 0;
		while (find[++len]) {};
		for (int i = 0; i < 100; i++) {
			fail[i] = 0;
		}
		int i;
		int j = 0;
		printf("fail[0] = %d\n", fail[0]);
		for (i = 1; i < len; i++) {
			if (find[i] == find[j]) {
				fail[i] = fail[i - 1] + 1;
				j++;
			}
			else {
				fail[i] = 0;
				j = 0;
			}
			printf("fail[%d] = %d\n", i, fail[i]);
		}

		cnt = 0;
		i = 0;
		j = 0;
		printf("%d. %d\n", arrlen, len);
		for (; i < arrlen && j < len;) {
			printf("i = %d, j = %d\n", i, j);
			if (arr[i] == find[j]) {
				if (j == len - 1) {
					ps_list[cnt++] = i - len + 1;
					if (j == 0) {
						i++;
					}
					else {
						j = fail[j - 1];
					}
				}
				else {
					i++;
					j++;
				}
			}
			else {
				if (j == 0) {
					i++;
				}
				else {
					j = fail[j - 1];
				}
			}
		}

		for (i = 0; i < cnt; i++) {
			printf("%d ", ps_list[i]);
		}
		printf("\n");
	}
	return 0;
}
