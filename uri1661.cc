#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
typedef long long int ll;

ll v[MAXN];

int main(){
	int n;
	while(scanf("%d", &n) && n){
		ll ans = 0LL;
		for(int i=0; i<n; i++)
			cin>>v[i];
		for(int i=1; i<n; i++){
			if(v[i-1]<0)
				ans += (-1)*v[i-1];
			else
				ans += v[i-1];
			v[i] += v[i-1];
		}
		cout<<ans<<endl;
	}
	return 0;
}

//Gasto (i - j + 1)*v[i] para levar v[i] garrafa(s) do indice i até o indice j
