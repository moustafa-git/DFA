#include<stdio.h>
#include<string.h>

#define fl(i,a,b) for(i=a; i<b; i++)
#define scan(a) scanf("%d", &a)
#define nline printf("\n")

#define MAX 1000

int states, symbols, symdir[20], final_states, mark[20], mat[20][20];

int main()
{
	int i, j, k;
	printf("Enter the number of states : ");
	scan(states);
	printf("Enter the number of symbols : ");
	scan(symbols);

	printf("Enter the symbols : ");
	nline;
	fl(i,0,symbols)
	{
		printf("Enter the symbol number %d : ", i);
		scan(symdir[i]);
	}

	printf("Enter the number of final states : ");
	scan(final_states);

	printf("Enter the number of the states which are final : ");
	nline;
	fl(i,0,final_states)
	{
		int temp;
		scan(temp);
		mark[temp]=1;
	}

	printf("Define the relations for the states and symbols : ");
	nline;
	fl(i,0,states)
	{
		fl(j,0,symbols)
		{
			printf("Enter the relation for Q(%d) -> %d : ", i, symdir[j]);
			scan(mat[i][symdir[j]]);
		}
	}



	//--------------------------------------------------------//
	int cases;
	printf("Enter the number of strings to be tested : ");
	scan(cases);
	fl(k,0,cases)
	{
		printf("Enter the string to be tested : ");
		char str1[MAX];
		scanf("%s", &str1);
		int curr=0;
		int limit=strlen(str1);
		fl(i,0,limit)
		{
			int ele=(int)(str1[i]-'0');
			curr=mat[curr][ele];
		}
		printf("The entered string is ");
		if(mark[curr]==1)
			printf("Accepted");
		else
			printf("Rejected");
		nline;
	}

	return 0;

}
