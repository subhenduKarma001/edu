#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> positions, v;

bool good(double t){
    double right = 1e20;
    double left = -1e20;
    for (int i = 0; i < n; i++) {
        right = min(right, positions[i] + t * v[i]);
        left = max(left, positions[i] - t * v[i]);
    }
    return right >= left;
}

int32_t main(){
    cin>>n;
    positions.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> positions[i] >> v[i];

    // Binary Search the time 
    double l = 0;       // bad
    double r = 1;    // good
    while(!good(r)) r *= 2;

    for(int i=0; i<100; i++) {
        // double mid = l + (r-l)/2;
        double mid = (l + r) / 2;
        if (good(mid))
            r = mid;
        else 
            l = mid;
    }

    cout << setprecision(20) << r <<endl;
    return 0;
}
