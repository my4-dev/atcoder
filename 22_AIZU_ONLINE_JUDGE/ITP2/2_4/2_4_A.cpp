#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"
*/

/*
input 

8
1 2 3 4 5 6 7 8
*/

int main()
{
    int n; cin >> n;
    vector<int> A;
    rep(i,n){
        int Ai; cin >> Ai;
        A.push_back(Ai);
    }
    int q; cin >> q;
    rep(i,q){
        int b, e; cin >> b >> e;
        reverse(A.begin()+b, A.begin()+e);
    }
    rep(i,n){
        cout << A[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
}