#include <bits/stdc++.h>
using namespace std;

int p;
struct node
{
    int val;
    node *child[2];
};

void insert(node *trie, int x, int ind)
{   
    if(ind < 0) {
        return;
    }
    int k=(x>>ind)&1;

    if(!trie->child[k]) {
        trie->child[k]=new node;
    }
    insert(trie->child[k], x, ind-1);
}

void find(node *trie, int x, int ind)
{   
    if(ind<0) {
        return;
    }

    int k=(x>>ind)&1;
    k^=1;

    if(!trie->child[k]) {
        k^=1;
    }
    p=p<<1|k;
    find(trie->child[k], x, ind-1);
}

int main()
{
    int n,i,x;
    cin>>n;

    int a[n];
    for(i=0;i<n;++i) {
        cin>>a[i];
    }

    node *trie = new node;
    for(i=0;i<n;++i) {
        // max 32 bits
        insert(trie,a[i],31);
    }

    int t;
    cin>>t;
    while(t--) {
        cin>>x;
        p=0;
        find(trie,x,31);
        cout<<(p^x)<<endl;
    }

    return 0;
}
