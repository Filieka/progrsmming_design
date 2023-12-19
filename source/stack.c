#include<stdio.h>
#include<stdlib.h>
#define road x>=0&&x<n*n&&map[x]==0

int stap(int n,int* map,int x,int* memory,int* count){
    int i;
    if(x==n*n-1){
        return 1;
    }
    for(i=0;i<n*n;i++){
        if(memory[i]==x){
            return 0;
        }
    }
    if(road){
        memory[*count]=x;
        (*count)++;
        if((x+1)%n!=0){
            if(stap(n,map,x+1,memory,count)){
                return 1;
            }
        }       
        if(stap(n,map,x+n,memory,count)){
            return 1;
        }
        if((x-1)%n!=n-1){
            if(stap(n,map,x-1,memory,count)){
                return 1;
            }
        }
        if(stap(n,map,x-n,memory,count)){
            return 1;
        }
    }
    return 0;
}

int main(){
    unsigned int n;
    int i,k,num=0;
    int* count=&num;
    scanf("%d",&n);
    int* map=(int*)malloc(n*n*sizeof(int));
    int* memory=(int*)malloc(n*n*sizeof(int));
    for(i=0;i<n*n;i++){
        memory[i]=-1;
    }
    for(i=0;i<n*n;i++){
        scanf("%d",&map[i]);
    }
    if(stap(n,map,0,memory,count)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    free(map);

    return 0;
}
