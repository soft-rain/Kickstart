#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countMax(vector<int> &a, int n, int b){
    sort(a.begin(), a.end());
    int count = 0;

    for(int i=0; i<a.size(); i++){
        if(b>0 && b>=a[i]){
            b-=a[i];
            count++;
        }
        else{
            break;
        }
    }
    return count;
}
int main(){
    int t, n, b;
    cin >> t;
    for(int j=0; j<t; j++){
        cin >> n >> b;
        vector<int> a(n, 0);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        cout << "Case #"<<j+1<<": "<< countMax(a, n, b)<<'\n';
    }
    return 0;
}