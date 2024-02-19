#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n, k;
int l;
vector<int> c[1010]; //cidades em cada linha (indexadas em 0)

vector<int> g[10100]; //o grafo (cidades indexadas em 1 pq input)
int d[10100]; //distancia de cada cidadde p origem
queue<int> q; //fila de cidades 

int aux;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(d, -1, sizeof(d));

  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> l;
    for (int j = 0; j < l; j++) {
      cin >> aux;
      c[i].pb(aux);
    }
  }


  for (int i = 0; i < k; i++) {
    //crio as cliques com quem esta em uma mesma linha
    //pode acabar com arestas repetidas, mas vai ser no maximo 10^7 total
    for (auto u: c[i]) {
      for (auto v: c[i]) {
        g[u].pb(v);
      }
    }
  }

  //comeco colocando cidade 1 como a primeira
  q.push(1);
  d[1] = 0;
  //e ai vou processando as outras
  while (! q.empty()) {
    aux = q.front();
    q.pop();
    
    //cada vizinho do atual entra na fila sse ainda nao tiver sido visitado
    for (auto x: g[aux]) {
      if (d[x] == -1) {
        d[x] = d[aux]+1;
        q.push(x);
      }
    }
  }

  /*
  for (int i = 1; i <= n; i++) {
    cerr << i << ": ";
    for (auto x: g[i]) cerr << x << ' ';
    cerr << '\n';
  }
  
  for (int i = 1; i <= n; i++) cerr << d[i] << ' ';
  cerr << '\n';
  */

  cout << d[n] << '\n';

  return 0;

}
