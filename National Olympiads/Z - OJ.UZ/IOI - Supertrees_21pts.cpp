//29 de Marzo 2026 17:18
#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;
#define ll int
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

class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

ll construct(vector<vl> arr){
	ll n = arr[0].size();
	vector<vl> ans(n, vl(n, 0));
	DisjointSets dsu(n);
	ff(i, 0, n){
		ff(j, 0, n){
			if(arr[i][j] == 3) return 0;
			if(arr[i][j] == 1) dsu.unite(i, j);
		}
	}
	ff(i, 0, n){
		ff(j, i+1, n){
			if(!arr[i][j] && dsu.find(i) == dsu.find(j)) return 0;
		}
	}
	DisjointSets dsu2(n);
	ff(i, 0, n){
		vl conexiones;
		ff(j, 0, n) if(dsu.find(j) == i) conexiones.pb(j);
		if(conexiones.size() <= 1) continue;
		ff(j, 0, conexiones.size())ff(k, j+1, conexiones.size()){
			if(arr[conexiones[j]][conexiones[k]] == 1 && dsu2.unite(conexiones[j], conexiones[k])){
				ans[conexiones[j]][conexiones[k]] = 1;
				ans[conexiones[k]][conexiones[j]] = 1;
			}
		}
	}
	build(ans);
	return 1;

}
