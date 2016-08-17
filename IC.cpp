#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

/*********************************************/
/* uncmment this to show lengthy DFS details */
/*                                           */
/*             #define DETAIL ON             */
/*                                           */
/*********************************************/


#define MAX 100

int v[MAX];
vector<int>G[MAX];
vector<int>ans;
bool in[MAX];


void DFS(int s, int val, int target, int n)
{
	in[s] = true;
	if(val == target){
		int find = 0;
		for(int i = 0; i < ans.size(); i++)
			if(ans[i] == val)
				find = 1;
		if(!find)
			ans.push_back(val);		

		#ifdef DETAIL
		#define DETAIL_MODE
			printf("%3d|", val);
			for(int i = 0; i < n; i++)
				if(in[i])
					printf("%3d", i);
			printf("\n");
		#endif
	}

	for(int i = 0; i < n; i++){
		if(!in[i])
			DFS(i, val + v[i], target, n);
	}
	in[s] = false;
}

int main()
{
	int n = 4;
	int m = 6;

	#ifdef DETAIL 
	#define DETAIL_MODE
	printf("n: ");
	#endif
	scanf("%d", &n);

	#ifdef DETAIL
	#define DETAIL_MODE
	printf("m: ");
	#endif
	scanf("%d", &m);

	#ifdef DETAIL
	#define DETAIL_MODE
	printf("%d vertex values:\n", n);
	#endif
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	
	#ifdef DETAIL
	#define DETAIL_MODE
	printf("%d edges:\n", m);
	#endif
	for(int i = 0; i < m; i++){
		int b, t;
		scanf("%d%d", &b, &t);
		G[b].push_back(t);
		G[t].push_back(b);
	}
	
	/* change sup at your own wish */
	int sup = 200;
	for(int i = 0; i < sup; i++){
		for(int j = 0; j < n; j++)
			DFS(j, v[j], i, n);
	}
	for(int i = 0; i < ans.size(); i++){
		printf("%4d", ans[i]);
		if(i % 10 == 9)
			printf("\n");
	}	
	printf("\n");

	return 0;
}
