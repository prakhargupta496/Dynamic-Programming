// This code is the solution for the problem https://www.geeksforgeeks.org/friends-pairing-problem/

#include<stdio.h>

void solve(int n){
    int arr[n+1];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1] + (i-1)*arr[i-2];
    }
    printf("%d",arr[n]);
}

int main()
{
    solve(4);
}
