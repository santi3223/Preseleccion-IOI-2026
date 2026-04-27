//9 de Febrero 2026 22:54
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
#define ed "\n"
#define vb vector<bool>

int main(){
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	//cout << a << " " << b << " " << c << " " << d << ed;
	if(a > c){
		swap(a, c);
		swap(b, d);
	}
	else if(a == c && d < b){
		swap(b, d);
	}
	//cout << a << " " << b << " " << c << " " << d << ed;
	if(b < c){
		cout << b-a+d-c;
	}
	else if(c <= b && b <= d){
		cout << d-a;
	}
	else{
		cout << b-a;
	}
}
