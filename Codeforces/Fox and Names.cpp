//15 de Marzo 2026 22:15
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

vl cuant, ans;
vector<vl> conexiones;

void ok(){
	queue<ll> q;
	ff(i, 0, 26){
		if(cuant[i] == 0) q.push(i);
	}
	while(!q.empty()){
		ll cur = q.front();
		q.pop();
		ans.pb(cur);
		for(auto &x : conexiones[cur]){
			cuant[x]--;
			if(cuant[x] == 0) q.push(x);
		}
	}
	
}

int main(){
	ll n;
	string str;
	cin >> n >> str;
	cuant = vl(26, 0);
	conexiones = vector<vl>(26);
	ff(id, 0, n-1){
		string cur;
		cin >> cur;
		ll i = 0;
		ll sz = min(cur.size(), str.size());
		while(i < sz){
			if(cur[i] != str[i]){
				ll c = cur[i]-'a', s = str[i]-'a';
				cuant[c]++;
				conexiones[s].pb(c);
				break;
			}
			i++;
		}
		if(i == sz && str.size() > cur.size()){
			cout << "Impossible";
			return 0;
		}
		str = cur;
	}
	
	ok();
	
	if(ans.size() < 26){
		cout << "Impossible";
	}
	else{
		ff(i, 0, 26){
			cout << char (ans[i]+'a');
		}
	}
}
