#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int s, i, n, j;
	char *num=argv[1];
	s=strlen(argv[1]);
	int **mn=(int**)malloc(s*sizeof(int*));
	for (i=0;i<s;i++)
	{
		n=num[i]-48;
		mn[i]=(int*)malloc(n*sizeof(int));
		for (j=0;j<n;j++)
		{
			mn[i][j]=n;
		}
			
	}
	for (i=0;i<s;i++)
	{
		n=num[i]-48;
		for (j=0;j<n;j++)
			fprintf(stdout, "|%d| ", mn[i][j]);
		fprintf(stdout, "\n");
	}
	system ("pause");
	return 0;
}
