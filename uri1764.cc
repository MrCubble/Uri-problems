#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

struct aresta{
	int x, y;
	long long d;
	aresta(){
		d = x = y = 0;
	}
	aresta(int _x, int _y, long long _d):x(_x),y(_y),d(_d){}
	bool operator<(aresta other){
		return d<other.d;
	}
};

aresta v[MAXN];
int pai[MAXN], peso[MAXN];

int find(int x){
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	if(peso[a] < peso[b]) pai[a] = b;
	else if(peso[b] < peso[a]) pai[b] = a;
	else{
		pai[a] = b;
		peso[b]++;
	}
}

long long kruskal(int n, int m){
	for(int i=0; i<=n; i++){
		pai[i] = i;
		peso[i] = 0;
	}
	sort(v, v+m);
	long long ans = 0LL;
	for(int i=0; i<m; i++){
		if(find(v[i].x) != find(v[i].y)){
			join(v[i].x, v[i].y);
			ans += v[i].d;
		}
	}
	return ans;
}

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) && n && m){
		for(int i=0; i<m; i++)
			cin>>v[i].x>>v[i].y>>v[i].d;
		cout<<kruskal(n, m)<<endl;
	}
	return 0;
}
