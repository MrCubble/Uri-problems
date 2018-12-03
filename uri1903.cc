#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, m, pp[MAXN], nn, grau[MAXN];
vector<int> nb[MAXN], lista;
set<int> nbhd[MAXN];
//Kosaraju -> para encontrar vértices fortemente conexos
bool vis[MAXN];
vector<int> adj[MAXN], adjt[MAXN];

void fillOrder(int v, stack<int> &st){
	vis[v] = true;
	for(int i=0; i<(int)adj[v].size(); i++)
		if(!vis[adj[v][i]])
			fillOrder(adj[v][i], st);
	st.push(v);
}

void dfs(int v, int tt){
	vis[v] = true;
	pp[v] = tt;
	//cout<<v<<" ";
	for(int i=0; i<(int)adjt[v].size(); i++)
		if(!vis[adjt[v][i]])
			dfs(adjt[v][i], tt);
}

void kosaraju(){
	stack<int> st;
	for(int i=0; i<n; i++) vis[i] = false;
	for(int i=0; i<n; i++)
		if(!vis[i])
			fillOrder(i, st);
	for(int i=0; i<n; i++) vis[i] = false;
	int tt = 0;
	while(!st.empty()){
		int v  = st.top();
		st.pop();
		if(!vis[v]){
			//printf("Scc %d: ", tt);
			dfs(v, tt++);
			//cout<<endl;
		}
	}
	nn = tt;	
}
//fimKosaraju

void toNewGraph(){
	set<pair <int, int> > edge;
	for(int i=0; i<n; i++){
		int l  = (int)adj[i].size();
		for(int j=0; j<l; j++){
			int u = adj[i][j];
			if(pp[u] == pp[i]) continue;
			if(!edge.count({pp[i],pp[u]})){
				nb[pp[i]].push_back(pp[u]);
				edge.insert({pp[i],pp[u]});
				nbhd[pp[i]].insert(pp[u]);
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++){
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		adj[x].push_back(y);
		adjt[y].push_back(x);
	}
	kosaraju();
	toNewGraph();
	for(int i=0; i<nn; i++)
		for(int j=0; j<(int)nb[i].size(); j++)
			grau[nb[i][j]]++;
	for(int i=0; i<nn; i++)
		if(!grau[i])
			lista.push_back(i);
	int ini = 0;
	while(ini<(int)lista.size()){
		int act = lista[ini];
		ini++;
		for(int i=0; i<(int)nb[act].size(); i++){
			int u = nb[act][i];
			grau[u]--;
			if(!grau[u])
				lista.push_back(u);
		}
	}
	bool ans = true;
	for(int i=0; i<(ini-1); i++){
		if(nbhd[lista[i]].count(lista[i+1])==0){
			ans = false;
			break;
		}
	}
	printf("%s\n", ans?"Bolada":"Nao Bolada");
	//for(int i=0; i<n; i++) printf("%d = %d\n", i, pp[i]);
	return 0;
}
