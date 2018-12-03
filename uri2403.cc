#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

int grau[MAXN], cp[MAXN];
set<int> cj;
vector<int> adj[MAXN], lista;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++){
		int x, y; scanf("%d%d", &x, &y);
		grau[y]++;
		adj[x].push_back(y);
	}
	for(int i=0; i<n; i++)
		if(!grau[i])
			cj.insert(i);
	int ini  = 0, act;
	while(!cj.empty()){
		auto it = cj.begin();
		act = *it;
		lista.push_back(act);
		ini++;
		for(int i=0; i<(int)adj[act].size(); i++){
			int u = adj[act][i];
			grau[u]--;
			if(grau[u] == 0){
				cj.insert(u);
			}
		}
		cj.erase(act);
	}
	if((int)lista.size() == n)
		for(auto i:lista)
			printf("%d\n", i);
	else
		printf("*\n");
	return 0;
}
