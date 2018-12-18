#include <bits/stdc++.h>
#define valor second 
#define peso first
#define MAXN 1010
using namespace std;
typedef pair<int, int> pii;

pii v[MAXN];
int m[MAXN][MAXN];

int mochila(int n, int C){
	int c;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=C; j++){
			if(i==0 || j==0)
				m[i][j] = 0;
			else if(v[i-1].peso <= j){
				c = j/v[i-1].peso;
				m[i][j] = max(m[i-1][j], c*v[i-1].valor + m[i-1][j-c*v[i-1].peso]);
			}
			else
				m[i][j] = m[i-1][j];
		}
	}
	return m[n][C];
}

int main(){
	int n, c, t;
	t = 0;
	while(scanf("%d%d", &n, &c) && n && c){
		for(int i=0; i<n; i++)
			scanf("%d%d", &v[i].peso, &v[i].valor);
		sort(v, v+n);
		int ans = mochila(n,c);
		printf("Instancia %d\n%d\n\n", ++t, ans);
	}
	return 0;
}
