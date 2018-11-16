# DSA_HW1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sort(int n, int* arr)
{
    for(int i = 0; i < n - 1; i++)
    {
       for(int j = i + 1; j < n; j++)
       {
           if(arr[j] > arr[i])
           {
               int temp = arr[j];
               arr[j] = arr[i];
               arr[i] = temp;
           }
       } 
    }
}

int minSum(int n, int k, vector<int> ints)
{
    int sum = 0;
    if(k > n || k < 0)
    {
        for(int i = 0; i < n; i++)
        {
            sum += ints[i];
        }
        return sum;
    }
    int counter = 1;
    for(int i=0;i<n;i++)
    {
        if(counter<k)
        {
            sum+=ints[i];
        }
        if(counter == k)
        {
            counter=1;
        }
        else{counter++;}
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    vector<int> ints;
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        ints.push_back(num);
    }
    sort(ints.rbegin(), ints.rend());
    cout<<minSum(n,k,ints)<<endl;
    return 0;
}
