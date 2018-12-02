#include <bits/stdc++.h>
using namespace std;
/*	Problemas:
		Pega os pontos que estão na borda do Convex hull
		Ler inteiros  long long 
*/
struct pt{
	long long x, y;
	pt(){ x = y = 0;}
	pt(long long _x, long long _y):x(_x), y(_y){}
	bool operator<(const pt &a)const{
		return x < a.x || (x == a.x) && y < a.y;
	}
	bool operator==(const pt &a)const{
		return x == a.x && y == a.y; 
	}
};

long long cross(pt o, pt a, pt b){
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

vector<pt> convex_hull(vector<pt> p){
	int n = (int)p.size(), k=0;
	vector<pt> h(2*n);
	sort(p.begin(), p.end());
	//build lower
	for(int i=0; i<n; i++){
		while(k>=2 && cross(h[k-2], h[k-1], p[i]) < 0LL) k--;
		h[k++] = p[i];
	}
	//build upper
	for(int i=n-2, t=k+1; i>=0; i--){
		while(k>=t && cross(h[k-2], h[k-1], p[i]) < 0LL) k--;
		h[k++] = p[i];
	}
	h.resize(k);
	return h;
}

int main(){
	int n, ans;
	while(cin>>n && n){
		vector<pt> t(n);
		for(auto &i : t)
			cin >> i.x >> i.y;
		ans = 0;
		while(t.size()){
			//printf("%d\n", ans);
			ans++;
			vector<pt> p = convex_hull(t);
			set<pt> ch;
			for(auto &k : p)
				ch.insert(k);
			vector<pt> tt;
			for(auto &k : t)
				if(!ch.count(k))
					tt.push_back(k);
			t = tt;
		}
		if (ans & 1)
     		cout << "Take this onion to the lab!" << endl;
    	else
      		cout << "Do not take this onion to the lab!" << endl;
	}
	return 0;
}
