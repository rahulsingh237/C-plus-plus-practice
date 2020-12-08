#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    int x;
    double y;
    string z;
    cin>>x;
    cin>>y;
    cin.ignore();
    getline(cin,z);
    x=x+i;
    y=y+d;
    cout<<x<<endl;
    cout<<fixed<<setprecision(1)<<y<<endl;
    cout<<s+z;
    return 0;
}
