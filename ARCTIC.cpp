#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RINT		register int
#define MAXN		100
#define sSum(A, B)	((A)*(A)+(B)*(B))

struct NODE {
	int p;
	NODE* next;
};
NODE a[2 * MAXN];

int nCnt;
NODE* myalloc(int p) {
	a[nCnt].p = p;
	a[nCnt].next = NULL;
	return &a[nCnt++];
}

struct POINT {
	double x, y;
	int color;
	NODE* next;
};
POINT base[MAXN];

struct EDGE {
	int p, q;
	double sLen;
};
EDGE edge[MAXN*MAXN];
int eCnt;

int adj[MAXN][MAXN];

int static compare(const void* first, const void* second)
{
	if ((*(EDGE*)first).sLen > (*(EDGE*)second).sLen)
		return 1;
	else if ((*(EDGE*)first).sLen < (*(EDGE*)second).sLen)
		return -1;
	else
		return 0;
}

int bCnt;
int bCheck[MAXN];
void bfs(int p, int color) {
	base[p].color = color;
	bCheck[p] = bCnt;
	//printf("%d-", p);
	for (NODE* pp = base[p].next; pp != NULL; pp = pp->next) {
		if (bCheck[pp->p] != bCnt) {
			bfs(pp->p, color);
		}
	}
	return;
}

void insertNode(int p, int q) {
	NODE* newnode = myalloc(q);
	newnode->next = base[p].next;
	base[p].next = newnode;
	return;
}

int main()
{
	int T, tc;
	int N;
	double ret = 0;

	scanf("%d", &T);
	bCnt = 0;

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		nCnt = 0;
		eCnt = 0;

		for (RINT i = 0; i < N; i++) {
			scanf("%lf %lf", &base[i].x, &base[i].y);
			base[i].color = i;
			base[i].next = NULL;

			adj[i][i] = 1;
			for (RINT k = 0; k < i; k++) {
				edge[eCnt].p = k;
				edge[eCnt].q = i;
				edge[eCnt++].sLen = sSum(base[i].x - base[k].x, base[i].y - base[k].y);
			}
		}

		if (N == 1) {
			printf("%.2f\n", ret);
			continue;
		}

		qsort(edge, eCnt, sizeof(EDGE), compare);
		for (RINT i = 0; i < eCnt; i++) {
			//printf("\n");
			//printf("p : %d, %d, sLen : %.2f\n", edge[i].p, edge[i].q, edge[i].sLen);
			int p = edge[i].p;
			int q = edge[i].q;
			if (base[p].color == base[q].color) {
				continue;
			}
			bfs(p, base[q].color);
			//printf("\n");
			bCnt++;

			//for (NODE* pp = base[p].next; pp != NUL; pp = pp->next) {
			//	printf("%d->", pp->p);
			//}
			//printf("\n");
			insertNode(p, q);
			insertNode(q, p);

			ret = edge[i].sLen;
		}
		
		ret = sqrt(ret);
		printf("%.2f\n", ret);
	}
	return 0;
}
