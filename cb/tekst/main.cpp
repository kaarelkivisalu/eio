#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream sis;
    ofstream val;

    int n;
    sis.open("tekstsis.txt");
    sis>>n;

    vector <string> teemad(n);
    vector <string> var;
    int ans=0;

    for (int i=0;i<n ;i++ )
    {
        sis>>teemad[i];
    }

    string juku;
    sis>>juku;
    int pikk = juku.length();

    for (int i=0;i<n ; i++)
    {
        if (juku.length()==teemad[i].length())
        {
            for (int j=0;j<pikk ;j++ )
            {
                if (juku[j]!='*')
                {
                    if (juku[j]!=teemad[i][j])
                    {
                        goto stop;
                    }
                }
            }
            ans++;
            var.push_back(teemad[i]);
        }
        stop:;
    }

    sis.close();
    val.open("tekstval.txt");

    val<<ans<<endl;
    for (int i=0;i<var.size() ;i++ )
    {
        val<<var[i]<<endl;
    }

    val.close();
}
