//26 de Mayo 2026 15:33
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

ll n;

void calc(ll cur, ll from, ll to, ll aux){
	if(cur == 1){
		cout << from << ' ' << to << ed;
		return;
	}
	calc(cur-1, from, aux, to);
	cout << from << ' ' << to << ed;
	calc(cur-1, aux, to, from);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cout << (1LL << n)-1 << ed;
	calc(n, 1, 3, 2);
}
