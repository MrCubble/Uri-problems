#include <bits/stdc++.h>
#define qtd second
#define peso first
#define MAXN 1010 
using namespace std;
typedef pair<int, int> pii;

pii v[MAXN];
int m[MAXN][MAXN];

int mochila(int n, int C){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=C; j++){
			if(i==0 || j==0)
				m[i][j] = 0;
			else if(v[i-1].peso <= j)
				m[i][j] = max(m[i-1][j], v[i-1].qtd + m[i-1][j-v[i-1].peso]);
			else
				m[i][j] = m[i-1][j];
		}
	}
	return m[n][C];
}

pii recuperandoMochila(int n, int C){
	int x = m[n][C], y = C, ans = 0;
	for(int i=n; i>0 && x>0; i--){
		if(x == m[i-1][y])
			continue;
		else{
			ans++;
			x = x - v[i-1].qtd;
			y = y - v[i-1].peso; 
		}
	}
	return pii(ans, y);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d%d", &v[i].qtd, &v[i].peso);
		sort(v, v+n);
		int ans = mochila(n, 50);
		printf("%d brinquedos\n", ans);
		pii res = recuperandoMochila(n,50);
		printf("Peso: %d kg\nsobra(m) %d pacote(s)\n\n", 50-res.second, n-res.first);
	}
	return 0;
}
