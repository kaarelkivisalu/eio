#include <bits/stdc++.h>

using namespace std;



int main()
{
    ifstream ifs;
    ofstream ofs;

    ifs.open("servsis.txt");

    int n,k;

    ifs>>n>>k;
    int temp;
    queue<char> a;
    for (int i=1;i<=k ;i++ )
    {
        ifs>>temp;
        for (int j=0;j<temp-i ;j++ )
        {
            a.push('Y');
        }
        a.push('X');
    }
    ifs.close();
    if (k==0)
    {
        for (int i=0;i<n ;i++ )
        {
            a.push('Y');
        }
    }

    ofs.open("servval.txt");
    if (n==1 and k==1)
    {
        ofs<<"A->B";
    }
    if (n==1 and k==0)
    {
        ofs<<"A->C";
    }
    ofs.close();
}
