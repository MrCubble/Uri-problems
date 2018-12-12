#include <bits/stdc++.h>
#define MAXN 60
#define weight first
#define value second
using namespace std;
typedef pair<int, int> pii;

pii v[MAXN];

int mochila(int n, int C){
	int m[n+1][C+1];
	memset(m, 0, sizeof(m));
	for(int i=0; i<=n; i++){
		for(int j=0; j<=C; j++){
			if(i == 0 || j == 0)
				m[i][j] = 0;
			else if(v[i].weight <= j)
				m[i][j] = max(m[i-1][j], v[i].value + m[i-1][j - v[i].weight]);
			else
				m[i][j] = m[i-1][j]; 
		}
	}
	return m[n][C];
}

int main(){
	int k, t, ans, n, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d%d", &v[i].value, &v[i].weight);
		sort(v+1, v+n+1);
		scanf("%d", &c);
		scanf("%d", &k);
		ans = mochila(n, c);
		if(ans >= k)
			printf("Missao completada com sucesso\n");
		else
			printf("Falha na missao\n");
	}
	return 0;
}
