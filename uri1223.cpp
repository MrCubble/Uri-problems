#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

struct haste{
	double m, n;
	int xi, yi, xf, yf;
	haste(){xi = xf = yi = yf = 0;}
	haste(int a, int b, int c, int d):xi(a), yi(b), xf(c), yf(d){
		m = (double)(yf - yi)/(xf - xi);
		n = yi - m*xi;
	}
	double dist(haste o){
		return fabs(o.yf - m*o.xf - n)/sqrt(pow(m, 2) + 1.0);
	}
	double distpp(haste o){
		return sqrt((xf - o.xf)*(xf - o.xf) + (yf - o.yf)*(yf - o.yf));
	}
};

int main(){
	int n;
	haste v[MAXN];
	while(scanf("%d", &n) != EOF){
		int l, h; scanf("%d %d", &l, &h);
		for(int i=0; i<n; i++){
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			v[i] = haste((i&1)*l, a, b, c);
		}
		double dim = (n&1)? fabs(l - v[n-1].xf) : v[n-1].xf;
		for(int i=0; i<(n-1); i++){
			if(i&1){
				dim = fmin(dim, fmin(v[i].xf, (v[i].xf - v[i+1].xf <= 0)? (v[i+1].dist(v[i])) : (v[i].distpp(v[i+1]))));
				//printf("%.2lf - %.2lf\n", (double)v[i].xf, (v[i].xf - v[i+1].xf >= 0)? (v[i+1].dist(v[i])) : (v[i].distpp(v[i+1])));
			}
			else{
				//printf("%.2lf - %.2lf\n",(double)l - v[i].xf, (v[i].xf - v[i+1].xf >= 0)? (v[i+1].dist(v[i])) : (v[i].distpp(v[i+1])));
				dim = fmin(dim, fmin((double)l - v[i].xf, (v[i].xf - v[i+1].xf >= 0)? (v[i+1].dist(v[i])) : (v[i].distpp(v[i+1]))));
			}		}
		printf("%.2lf\n", dim);
	}
	return 0;
}
