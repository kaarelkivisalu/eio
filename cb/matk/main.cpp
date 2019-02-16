#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream ifs;
    ofstream ofs;
    ifs.open("matksis.txt");
    int h, w;

    ifs>>h>>w;

    vector <string> kaart(h);

    for (int i=0; i<h ; i++ )
    {
        ifs>>kaart[i];
    }
    ifs.close();

//    ofs.open("matkval.txt");
//    if (h==2 or w==2)
//    {
//        ofs<<0<<endl;
//        for (int i=0;i<h ;i++ )
//        {
//            ofs<<kaart[i]<<endl;
//        }
//    }
//    else
//    {
//        ofs<<"-1"<<endl;
//        for (int i=0;i<h ;i++ )
//        {
//            ofs<<kaart[i]<<endl;
//        }
//    }
//    ofs.close();
    vector <pair<int, int>> al[100][100];
    pair <int, int> algus;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if (kaart[i][j]=='.')
            {
                if(i+1<h and (kaart[i+1][j]=='.' or kaart[i+1][j]=='@'))
                {
                    al[i][j].push_back(make_pair(i+1, j));
//                    cout<<kaart[i+1][j]<<" "<<i+1<<" "<<100*(i+1)+j<<endl;
//                    cout<<"xxx"<<i<<endl;
                }
                if(i-1>0 and (kaart[i-1][j]=='.' or kaart[i-1][j]=='@'))
                {
                    al[i][j].push_back(make_pair(i-1, j));
                }
                if(j+1<w and (kaart[i][j+1]=='.' or kaart[i][j-1]=='@'))
                {
                    al[i][j].push_back(make_pair(i, j+1));
                }
                if(j-1>0 and (kaart[i][j-1]=='.' or kaart[i][j-1]=='@'))
                {
                    al[i][j].push_back(make_pair(i, j-1));
                }
            }

            if (kaart[i][j]=='@')
            {
                algus=make_pair(i,j);
                if((i+1)<h and kaart[i+1][j]=='.')
                {
                    al[i][j].push_back(make_pair(i+1, j));
//                    cout<<kaart[i+1][j]<<" "<<i+1<<" "<<100*(i+1)+j<<endl;
//                    cout<<"xxx"<<i<<endl;
                }
                if(i-1>0 and kaart[i-1][j]=='.')
                {
                    al[i][j].push_back(make_pair(i-1, j));
                }
                if(j+1<w and kaart[i][j+1]=='.')
                {
                    al[i][j].push_back(make_pair(i, j+1));
                }
                if(j-1>0 and kaart[i][j-1]=='.')
                {
                    al[i][j].push_back(make_pair(i, j-1));
                }
            }
        }
    }

    stack <pair <pair <int,int>,int>> bfs;
    bool visited[100][100];
    for (int i=0; i<100 ; i++ )
    {
        for (int j=0; j<100 ; j++ )
        {
            visited[i][j]=false;
        }
    }

    visited[algus.first][algus.second]=true;
    for (int i=0; i<al[algus.first][algus.second].size(); i++)
    {
        bfs.push(make_pair(al[algus.first][algus.second][i], 1));
        visited[bfs.top().first.first][bfs.top().first.second]=true;
        visited[bfs.top().first.first][bfs.top().first.second]=true;
    }
    ofs.open("matkval.txt");
    vector <int> vastused;
    while (bfs.size()>0)
    {
//        if (al[bfs.top().first.first][bfs.top().first.second].size()<=1)
//        {
//            bfs.pop();
//        }
//        else
//        {
        pair <pair <int,int>, int> tempx = bfs.top();
        int k=0;
        for (int i=0; i< al[tempx.first.first][tempx.first.second].size(); i++)
        {
            if (visited [al[tempx.first.first][tempx.first.second][i].first] [al[tempx.first.first][tempx.first.second][i].second]==false)
            {
                bfs.push(make_pair(al[tempx.first.first][tempx.first.second][i], tempx.second+1));
                visited[bfs.top().first.first][bfs.top().first.second]=true;
                k++;
            }
            if (bfs.top().first.first==0 or bfs.top().first.first==h-1 or bfs.top().first.second==0 or bfs.top().first.first==w-1)
            {
                //vastused.push_back(bfs.top().second);
                ofs<<bfs.top().second;
                for (int m=0; m<h ; m++ )
                {
                    ofs<<kaart[i]<<endl;
                }
                goto stop;
            }
        }
        if (k==0)
        {
            bfs.pop();
        }
//        }
    }
    ofs<<"-1"<<endl;
    for (int i=0; i<h ; i++ )
    {
        ofs<<kaart[i]<<endl;
    }
stop:

    ofs.close();
}
