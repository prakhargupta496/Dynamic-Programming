//This code is for the problem https://www.geeksforgeeks.org/gold-mine-problem/
//This code does not use DP but still has the same time complexity.

#include<stdio.h>

void solve(int n,int m,int a[n][m]){
    int way[n];
    for(int i=0;i<n;i++){
        int first = a[i][0];
        int sum = first;
        int current = i;
        for(int j=1;j<m;j++){
            int greatest = 0;
            if(current == 0){
                greatest = greater(a[current][j],0,a[current+1][j]);
            }else if(current == n-1){
                greatest = greater(a[current][j],a[current-1][j],0);
            }else{
                greatest = greater(a[current][j],a[current-1][j],a[current+1][j]);
            }


            if(greatest == a[i][j]){
                current = current;
            }else if(greatest == a[i-1][j]){
                current = current-1;
            }else{
                current = current+1;
            }
            sum += greatest;

        }
        way[i] = sum;
    }
    int big = 0;
    for(int i=0;i<n;i++){
        if(way[i] > big){
                big = way[i];
        }
       }
       printf("%d",big);
    }



int greater(int a,int b,int c)
{
    if(a>=b && a>=c)
    {
        return a;
    }else if(b>=a && b>=c){
        return b;
    }else if(c>=a && c>=b){
        return c;
    }
    return 0;
}

int main()
{
    int mat[4][4] = {{1,3,1,5},
                   {2,2,4,1},
                   {5,0,2,3},
                   {0,6,1,2}};
    solve(4,4,mat);
}

