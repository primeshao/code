#include <stdio.h>
 
int main(void)
{
	int n,m;
	int i,j,k;
	int A[31][31], B[31][31], C[31][31];
	scanf("%d %d",&n,&m);
	for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= n - 1; j++) {
			scanf("%d", &A[i][j]);
			}
		}
	if(m==0)
	{
		for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= n - 1; j++) {
			A[i][j] = 0;
			}
		}
		for (i = 0; i <= n - 1; i++) A[i][i] = 1;
		m++;
	}
	for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= n - 1; j++) {
			B[i][j] = A[i][j];
			}
		}
	while(--m)
	{
		for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= n - 1; j++) {
			C[i][j] = 0;
			}
		}
		for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= n - 1; j++) {
			for (k = 0; k <= n - 1; k++) {
				C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= n - 1; j++) {
			A[i][j] = C[i][j];
			}
		}
	}
 
	
	for (i = 0; i <= n - 1; i++) {
		printf("%d", A[i][0]);
		for (j = 1; j <= n - 1; j++) {
			printf(" %d", A[i][j]);
			}
			printf("\n");
		}
 
	return 0;
}
