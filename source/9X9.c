#include<stdio.h>

int main(){
    int i,j;
    for(i=1;i<10;i++){
        for(j=1;j<10;j++){
            printf("%d x %d = %d",j,i,i*j);
            if(i*j<10){
                printf(" ");
            }
            printf("    ");
        }
        printf("\n");
    }

    return 0;
}