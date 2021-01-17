#include<stdio.h>

void solve(int n,int m,int a[n][m])
{
    int res[n][m];
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(j == m-1){
                res[i][j] = a[i][j];
            }else if(i == 0 && j != m-1){
                res[i][j] = max(res[i][j+1],res[i+1][j+1]) + a[i][j];
            }else if(i == n-1 && j != m-1){
                res[i][j] = max(res[i][j+1],res[i-1][j+1]) + a[i][j];
            }else{
                res[i][j] = max(res[i][j+1],max(res[i+1][j+1],res[i-1][j+1])) + a[i][j];

            }
        }
    }
    int maxi = 0;
    for(int i=0;i<n;i++){
            printf("%d\n",res[i][0]);
        if(res[i][0] > maxi){
            maxi = res[i][0];
        }
    }
    printf("%d\n[______________________\n",maxi);
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
}

int max(int a,int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
    return 0;
}

int main()
{
    int gold[4][4]= { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    solve(4,4,gold);
}
