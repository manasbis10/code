#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9+7;
int mod_add(int a, int b, int m) {return (a % m + b % m) % m;}
int mod_mul(int a, int b, int m) {return (a % m * b % m) % m;}
int mod_sub(int a, int b, int m) {return ((a % m - b % m) + m) % m;}
int bin_exp(int base, int exp, int m) {
    if (exp == 0) return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0) {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) {return bin_exp(a, m - 2, m);}
/*---------------------------------------------------------------------------------------*/
#define F first
#define S second

vector<pair<int, int>>dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>>grid(n+1, vector<int>(m+1,1));
    vector<vector<int>>monsterGrid(n+1, vector<int>(m+1,1e9));
    vector<vector<int>>personGrid(n+1, vector<int>(m+1,1e9));
    queue<pair<int, int>>monsterQ, personQ;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            char ch;
            cin>>ch;
            if(ch == '#')
            {
                grid[i][j] = 0;
            }
            else if(ch == 'M')
            {
                monsterGrid[i][j] = 0;
                monsterQ.push({i, j});
            }
            else if(ch == 'A')
            {
                personGrid[i][j] = 0;
                personQ.push({i,j});
            }
        }
    }

    while(!monsterQ.empty())
    {
        auto top = monsterQ.front();
        monsterQ.pop();

        for(auto i : dir)
        {
            int nx = i.F + top.F;
            int ny = i.S + top.S;

            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(grid[nx][ny] && monsterGrid[nx][ny]> 1 + monsterGrid[top.F][top.S])
                {
                    monsterGrid[nx][ny] = 1 + monsterGrid[top.F][top.S];
                    monsterQ.push({nx, ny});
                }
            }
        }
    }

    while(!personQ.empty())
    {
        auto top = personQ.front();
        personQ.pop();

        for(auto i : dir)
        {
            int nx = i.F + top.F;
            int ny = i.S + top.S;

            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(grid[nx][ny] && personGrid[nx][ny]> 1 + personGrid[top.F][top.S])
                {
                    personGrid[nx][ny] = 1 + personGrid[top.F][top.S];
                    personQ.push({nx, ny});
                }
            }
        }
    }

   
    int dist = 1e9;
    for(int i = 0;i<n;i++)
    {
        if(grid[i][0] == 1 && personGrid[i][0] != 1e9 && (personGrid[i][0] < monsterGrid[i][0]))
        {
            dist = min(dist, personGrid[i][0]);
        }

        if(grid[i][m-1] == 1 && personGrid[i][m-1] != 1e9 && (personGrid[i][m-1] < monsterGrid[i][m-1]))
        {
            dist = min(dist, personGrid[i][m-1]);
        }
    }

     for(int i = 0;i<m;i++)
    {
        if(grid[0][i] == 1 && personGrid[0][i] != 1e9 && (personGrid[0][i] < monsterGrid[0][i]))
        {
            dist = min(dist, personGrid[0][i]);
        }

        if(grid[n-1][i] == 1 && personGrid[n-1][i] != 1e9 && (personGrid[n-1][i] < monsterGrid[n-1][i]))
        {
            dist = min(dist, personGrid[n-1][i]);
        }
    }

    if(dist == 1e9)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<dist<<endl;
        return;
    }

  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

     
        solve();
    

    return 0;
}