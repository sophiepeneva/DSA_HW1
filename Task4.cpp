# DSA_HW1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> sockDifferenceSorter(vector<int> ints)
{
    vector<int> diff;
    for (int i = 0;i < ints.size() - 1;i++) 
    {
        for (int j = i + 1;j < ints.size();j++) 
        {
            if (j != i) 
            {
                if (j > i)diff.push_back(ints[j] - ints[i]);
                else { diff.push_back(ints[i] - ints[j]); }
            }
        }
    }
    sort(diff.begin(), diff.end());
    return diff;
}

void findSockForDayK(int k, vector<int> ints, vector<int> diff) 
{
    int differenceForDayK = diff[k - 1];
    int counter = 0;
    for (int i = 0;i < k;i++) 
    {
        if (diff[i] == differenceForDayK)counter++;
    }
    for (int i = 0;i < ints.size() - 1; i++) 
    {
        for (int j = i + 1;j < ints.size();j++) 
        {
            if (ints[j] - ints[i] == differenceForDayK || ints[i] - ints[j] == differenceForDayK) 
            {
                if (counter == 1) 
                {
                    if (j > i)cout << ints[i] << " " << ints[j];
                    if (i > j)cout << ints[j] << " " << ints[i];
                    return;
                }
                counter--;
            }
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    vector<int> ints;
    for (int i = 0;i < n;i++) {
        int num;
        cin >> num;
        ints.push_back(num);
    }
    vector<int> sockDifference = sockDifferenceSorter(ints);
    findSockForDayK(k, ints, sockDifference);
    
    return 0;
}
