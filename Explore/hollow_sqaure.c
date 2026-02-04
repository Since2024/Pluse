#include <stdio.h>
int main(){
    int i, j, n;
    n = 5;
    for(i=1; i<=n; i++){ //row loop
        for(j=1; j<=n; j++){ //column loop
            //Logic: if we are on any of the 4 boundaries, print a star
            if(i==1 || i==n || j==1 || j==n){
                printf("*");
            }else{ //otherwise print a space
                printf(" ");
            }
        }
        printf("\n"); //after each row is finished, move to the next line
    }
    return 0;
}