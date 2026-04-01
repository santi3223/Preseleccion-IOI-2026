//10 de Febrero 2026 18:34
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"
vs ans;

void p3(ll a, ll b, ll c, ll d, ll e, ll f, char c1, char c2, char c3){
	
	ll n = ans.size();
	vs cur(n, string(n, '.'));
	ff(i, 0, b){
		ff(j, 0, a){
			cur[i][j] = c1;
		}
	}
	ll s1 = 0, s2 = 0;
	if(a < n){
		s2 = a;
	}
	else{
		s1 = b;
	}
	if(s1+d > n) return;
	if(s2+c > n) return;
	ff(i, s1, s1+d){
		ff(j, s2, s2+c){
			cur[i][j] = c2;
		}
	}
	s1 = -1;
	ff(i, 0, n){
		ff(j, 0, n){
			if(cur[i][j] == '.'){
				s1 = i;
				s2 = j;
				break;
			}
		}
		if(s1 != -1) break;
	}
	if(s1 == -1) return;
	
	if(s1+f > n) return;
	if(s2+e > n) return;
	ff(i, s1, s1+f){
		ff(j, s2, s2+e){
			if(cur[i][j] != '.') return;
			cur[i][j] = c3;
		}
	}
	ans = cur;
}

void p2(ll a, ll b, ll c, ll d, ll e, ll f){
	p3(a, b, c, d, e, f, 'A', 'B', 'C');
	p3(a, b, e, f, c, d, 'A', 'C', 'B');
	p3(c, d, a, b, e, f, 'B', 'A', 'C');
	p3(c, d, e, f, a, b, 'B', 'C', 'A');
	p3(e, f, a, b, c, d, 'C', 'A', 'B');
	p3(e, f, c, d, a, b, 'C', 'B', 'A');
}

void p1(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	ll a = x1, b = y1, c = x2, d = y2, e = x3, f = y3;
	p2(a, b, c, d, e, f);
	p2(a, b, c, d, f, e);
	p2(a, b, d, c, e, f);
	p2(a, b, d, c, f, e);
	p2(b, a, c, d, e, f);
	p2(b, a, c, d, f, e);
	p2(b, a, d, c, e, f);
	p2(b, a, d, c, f, e);
}

int main(){
	ll x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	ll qq = (x1*y1)+(x2*y2)+(x3*y3), n = sqrt(qq);
	if(n*n != qq){
		cout << -1;
		return 0;
	}
	ans = vs(n, string(n, '.'));
	p1(x1, y1, x2, y2, x3, y3);
	if(ans[0][0] == '.'){
		cout << -1;
		return 0;
	}
	cout << n << ed;
	ff(i, 0, n){
		cout << ans[i] << ed;
	}
}
