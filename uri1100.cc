#include <bits/stdc++.h>
#define MAXN 10
using namespace std; 

int vis[MAXN][MAXN];
int mov[8][2] = {{-2,1},{-2,-1},{2,-1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2}};

void bfs(int x, int y){
	queue<pair<int, int> > f;
	memset(vis, -1, sizeof(vis));
	f.push({x, y});
	vis[x][y] = 0;
	while(!f.empty()){
		pair<int, int> act = f.front();
		f.pop();
		for(int i=0; i<8; i++){
			int I = act.first + mov[i][0], J = act.second + mov[i][1];
			if(I>0 && I<=8 && J>0 && J<=8 && vis[I][J] == -1){
				vis[I][J] = vis[act.first][act.second] + 1;
				f.push({I,J});
			}
		}
	}
}

int main(){
	char a, c;
	int b, d;
	while(scanf("%c%d %c%d ", &a, &b, &c, &d) != EOF){
		int aa = a - 'a' + 1;
		int cc = c - 'a' + 1;
		bfs(aa, b);
		printf("To get from %c%d to %c%d takes %d knight moves.\n", a, b, c, d, vis[cc][d]);
	}
	return 0;
}
