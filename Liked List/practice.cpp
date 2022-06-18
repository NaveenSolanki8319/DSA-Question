#include<bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r)
{
    if (l == r)         // Base case
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);    // Swapping done
            permute(a, l+1, r);     // Recursion called
            swap(a[l], a[i]);   //backtrack
        }
    }
}
int main()
{
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);
    return 0;
}