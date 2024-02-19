#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int parent[1000000];


int root(int a){

    if (a == parent[a]) return a;
    
    return parent[a] = root(parent[a]);
}

void connect(int a, int b){
    a = root(a);
    b = root(b);
    if (a != b) parent[b] = a;
    
}

void connectedComponents(int n) {
    set<int> s;
    
    for (int i = 0; i < n; i++)  s.insert(root(parent[i]));

    cout << s.size() << '\n';
}
 
void printAnswer(int N, vector<vector<int> > edges){
 

    for (int i = 0; i <= N; i++)  parent[i] = i;
  
    for (int i = 0; i < edges.size(); i++) connect(edges[i][0], edges[i][1]);

    connectedComponents(N);
}
int main()
{
    int n,m,idx=2;
    cin>>n>>m;
    map<string,int> pessoas;
    bool primeiro = 1;
    while(m--){
        cerr<<"oi\n";
      string p1,c,p2;
      cin>>p1>>c>>p2;  
      if(primeiro){
          pessoas[p1]=0;
          pessoas[p2]=1;
          adj.push_back({0,1});
          adj.push_back({1,0});
        //  cout<<0<<" "<<1<<"\n";
          primeiro=0;
      }else{
          int n1,n2;
          if(pessoas.find(p1)!=pessoas.end()){
              n1=pessoas[p1];
          } else{
              pessoas[p1]=idx;
              n1=idx;
              idx++;
              
          }
          if(pessoas.find(p2)!=pessoas.end()){
              n2=pessoas[p2];
          } else{
              pessoas[p2]=idx;
              n2=idx;
              idx++;
              
          }
         // cout<<n1<<" "<<n2<<"\n";
          adj.push_back({n1,n2});
          adj.push_back({n2,n1});
      }
      
       
    }
    printAnswer(n, adj);
    

    return 0;
}