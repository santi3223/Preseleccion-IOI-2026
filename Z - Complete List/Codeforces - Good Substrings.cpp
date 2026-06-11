//10 de Junio 2026 21:36
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
const long double PI = acos(-1.0);

struct Trie{
	struct Node{
		vl nxt;
		Node(){
			nxt = vl(26, -1);
		}
	};

	vector<Node> trie;
	Trie(){
		trie.pb(Node());
	}
	ll newNode(){
		trie.pb(Node());
		return (ll)trie.size() - 1;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, p;
	ll k;
	cin >> s >> p >> k;
	vb bad(26, 0);
	ll n = s.size();
	ff(i, 0, 26) if(p[i] == '0') bad[i] = 1;
	Trie T;
	ll ans = 0;

	ff(i, 0, n){
		ll cur = 0, q = 0;
		ff(j, i, n){
			if(bad[s[j] - 'a']) q++;
			if(q > k) break;

			ll c = s[j] - 'a';
			if(T.trie[cur].nxt[c] == -1){
				T.trie[cur].nxt[c] = T.newNode();
				ans++;
			}
			cur = T.trie[cur].nxt[c];
		}
	}
	cout << ans;
	
}
