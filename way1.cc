#include <bits/stdc++.h>
using namespace std;
int Solution::solve(vector<int> &A, int B)
{
    vector<int> mn(A.size() + 3, -1), mx(A.size() + 3, -1);
    int i = 0, j = -1, odd = 0, tmp = 0;
    //mn
    while (i < A.size())
    {
        //tmp is the next point to consider
        tmp = max(i, j);
        if (tmp == j)
            tmp++;
        while (tmp < A.size() && odd < B)
        {
            if (A[tmp] % 2)
            {
                odd++;
            }
            //taking this point in the current window
            j = tmp;
            tmp++;
        }
        if (j >= i && odd == B)
            mn[i] = j;
        //special case
        if (B == 0 && A[i] % 2 == 0)
        {
            mn[i] = i;
        }

        if (A[i] % 2 && j >= i)
        {
            odd--;
        }
        i++;
    }

    i = 0, j = -1, odd = 0, tmp = 0;
    //mx
    while (i < A.size())
    {
        tmp = max(i, j);
        //tmp is the next point to consider
        if (tmp == j)
            tmp++;
        while (tmp < A.size() && odd <= B)
        {
            if (A[tmp] % 2)
            {
                if (odd == B)
                {
                    //if we take this point then odd in the current window will be greater than B
                    break;
                }
                odd++;
            }
            //taking this point in the current window
            j = tmp;
            tmp++;
        }
        if (j >= i && odd == B)
            mx[i] = j;

        if (A[i] % 2 && j >= i)
        {
            odd--;
        }
        i++;
    }
    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (mx[i] != -1 && mn[i] != -1)
            cnt += mx[i] - mn[i] + 1;
    }
    return cnt;
}