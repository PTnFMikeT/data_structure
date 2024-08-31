#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n[10], i, j, pc,s;
	char *num=argv[1];
	for (i=0;i<=20;i++)
		if(i%2==0)
			n[(i/2)-1]=i;
	for (j=0;j<10;j++)
	{
		fprintf(stdout,"| %d |\t", n[j]);
	}
	fprintf(stdout,"\n");
	s=strlen(argv[1]);
	pc=num[s-1]-48;
	n[pc]=-1;
	for (j=0;j<10;j++)
	{
		fprintf(stdout,"| %d |\t", n[j]);
	}
	system ("pause");
	return 0;
}
