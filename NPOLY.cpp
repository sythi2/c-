#include <stdio.h>
#define RINT	register int
#define MOD		20090711
#define MAXN	100

int p[MAXN + 1][MAXN + 1];
int s[MAXN + 1][MAXN + 1];
int poly[MAXN + 1];
int spoly[MAXN + 1];

int main()
{
	int T, tc;
	int N;

	for (RINT n = 1; n <= MAXN; n++) {
		for (RINT k = 1; k < n; k++) {
			for (RINT i = 1; i <= n - k; i++) {
				p[n][k] = (p[n][k] + p[n - k][i] * (k + i - 1)) % MOD;
			}
			poly[n] = (poly[n] + p[n][k]) % MOD;
		}
		for (RINT k = 1; k <= (n - 1) / 2; k++) {
			for (RINT i = 1; i <= n / 2 - k; i++) {
				s[n][k] = (s[n][k] + s[n - 2 * k][i] * (k + i - 1)) % MOD;
			}
			s[n][k] += n - k - 1;
			spoly[n] = (spoly[n] + s[n][k]) % MOD;
		}
		if ((n % 2) == 0) {
			s[n][n / 2] = 1;
			spoly[n]++;
		}
		p[n][n] = 1;
		s[n][n] = 1;
		poly[n] = poly[n] + 3 * MOD + 1;
		spoly[n]++;
	}

	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		printf("%d\n", (poly[N] - spoly[N]) % MOD);
	}
	return 0;
}
