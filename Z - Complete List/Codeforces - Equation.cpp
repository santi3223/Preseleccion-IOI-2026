//4 de Mayo 2026 12:20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed endl
#define vs vector<string>
 
int main(){
	long double a, b, c;
	cin >> a >> b >> c;
	if(a == 0){
		if(b == 0){
			if(c == 0) cout << -1;
			else cout << 0;
		}
		else{
			long double x = 0.0;
			if(c != 0){
				x = c/(-b);
			}
			cout << 1 << ed;
			cout << fixed << setprecision(10) << x;
		}
	}
	else{
		long double disc = b*b-(4.0*a*c);
		if(disc < 0.0){
			cout << 0;
		}
		else if(disc == 0.0){
			cout << 1 << ed;
			a *= 2.0;
			long double x = -b/a;
			cout << fixed << setprecision(10) << x;
		}
		else{
			cout << 2 << ed;
			long double sq = sqrt(disc);
			a *= 2.0;
			long double p1 = (-b+sq)/a, p2 = (-b-sq)/a;
			if(p1 > p2) swap(p1, p2);
			cout << fixed << setprecision(10) << p1 << ed;
			cout << fixed << setprecision(10) << p2 << ed;
			
		}
	}
}
