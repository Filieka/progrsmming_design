#include<stdio.h>
#include<stdlib.h>
#define road top[1]>=0&&top[1]<n*n&&map[top[1]]==0
#define end *top>0&&&&(*top<n||*top>n*(n-1)||*top%n==0||*top%n==n-1)

int check(int* memory,int n,int x){
    int i,count=0;
    for(i=0;i<n*n;i++){
        if(memory[i]==-1){
            return 0;
        }
        if(memory[i]==x){
            count++;
            if(count==2){
                return 1;
            }
        }
    }
    return 0;
}  

int main(){
    unsigned int n;
    int i,enter;
    scanf("%d",&n);
    int* map=(int*)malloc(n*n*sizeof(int));
    int* memory=(int*)malloc(n*n*sizeof(int));
    int* top=memory;
    for(i=0;i<n*n;i++){
        memory[i]=-1;
    }
    for(i=0;i<n*n;i++){
        scanf("%d",&map[i]);
    }
    scanf("%d",&enter);
    enter*=n;
    scanf("%d",&i);
    enter+=i;
    *top=enter;
    while(1){
        top[1]=*top+1;
        if(check(memory,n,top[1])){
            top[1]=-1;
        }
        else if(road){
            top++;
            if(end){
                break;
            }
            continue;
        }
        top[1]=*top+n;
        if(check(memory,n,top[1])){
            top[1]=-1;
        }
        else if(road){
            top++;
            if(end){
                break;
            }
            continue;
        }
        top[1]=*top-1;
        if(check(memory,n,top[1])){
            top[1]=-1;
        }
        else if(road){
            top++;
            if(end){
                break;
            }
            continue;
        }
        top[1]=*top-n;
        if(check(memory,n,top[1])){
            top[1]=-1;
        }
        else if(road){
            top++;
            if(end){
                break;
            }
            continue;
        }
        map[*top]=1;
        top--;
    }
    i=0;
    while(memory[i]!=-1){
        printf("%d %d\n",memory[i]/n,memory[i]%n);
        i++;
    }
    if(memory[0]==-1){
        printf("No way out\n");
    }  
    free(map);
    free(memory);

    return 0;
}
