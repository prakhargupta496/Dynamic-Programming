#include<stdio.h>

void permute(int n,int k){
    int p[n+1][k+1];
    for(int i = 1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j == 0){
                p[i][j] = 1;
            }else if(j == 1){
                p[i][j] = i;
            }else if(j > i){
                p[i][j] = 0;
            }
            else {
                 p[i][j] = p[i - 1][j] +
                          (j * p[i - 1][j - 1]);
            }
        }
    }
    printf("%d",p[n][k]);
}

int main()
{
    permute(4,2);
}
