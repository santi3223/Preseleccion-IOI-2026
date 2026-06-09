//8 de Junio 2026 11:51
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	ll n = s.size();
	ll maxx = 0, c = 0, lst = 0;
	vl cur;
	ff(i, 0, n){
		if(s[i] == '('){
			cur.pb(i+1);
		}
		else{
			if(cur.size()){
				cur.pop_back();
				ll sz = i+1;
				if(cur.size()) sz -= cur.back();
				else sz -= lst;
				if(sz == maxx){
					c++;
				}
				else if(sz > maxx){
					maxx = sz;
					c = 1;
				}
			}
			else lst = i+1;
		}
	}
	if(maxx == 0) c = 1;
	cout << maxx << ' ' << c;
}
