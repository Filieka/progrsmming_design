#include<stdio.h>

int main(){
    int i,j;
    for(i=1;i<10;i++){
        for(j=1;j<10;j++){
            printf("%d x %d =\t%d",j,i,i*j);
            printf("    ");
        }
        printf("\n");
    }

    return 0;
}
