#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    while(true){
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        if(x > y) swap(x, y);
        printf("%d %d\n", x, y);
    }
}