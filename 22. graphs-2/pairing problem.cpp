#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

const int N=100001;

int parent[N],sz[N];

// gives superparent of the component
int get_parent(int x){
    if(x==parent[x]){
        return x;
    }
    else{
        // path compression
        return parent[x]=get_parent(parent[x]);
    }
}

// joins two disjoint components
void unite(int x, int y){
    int root_x=get_parent(x);
    int root_y=get_parent(y);
    if(root_x != root_y){
        parent[root_y]=root_x;
        sz[root_x]+=sz[root_y];
        sz[root_y]=0;
    }
}

void init(){
    for(int i=0;i<N;i++){
        parent[i]=i;
        sz[i]=1;
    }
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //  code starts
    init();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        unite(x,y);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(n-sz[get_parent(i)]);
    }
    // every edge is counted twice
    cout<<ans/2;
}
