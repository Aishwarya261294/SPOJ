//small factorials
#include <stdio.h>

#define BASE 1000

int main()
{
	int t, n, i, j, m, x;
	unsigned int out[160];
	unsigned int res, temp;

	scanf("%d", &t);

	for (i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		out[0] = 1; m=1;
		for (j=2; j<=n; j++)
		{
			temp = 0;
			for (x = 0; x < m; x++)
			{
				res = out[x] * j + temp;
				out[x] = res % BASE;
				temp = res / BASE;
			}
			while (temp != 0)
			{
				out[m++] = temp % BASE;
				temp /= BASE;
			}
		}
		printf("%d",out[m-1]);
		for (j = m-2 ; j >= 0; j--)
			printf("%.3d",out[j]);
		printf("\n");
	}

	return 0;
}
