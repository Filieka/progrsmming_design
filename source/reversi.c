#include<stdio.h>
#include<stdlib.h>

int* step(int i,int j,int plate[8][8],int player){
    int x,y,distance,legal,a=0;
    int* ans=(int*)malloc(16*sizeof(int));
    for(x=-1;x<=1;x++){
        for(y=-1;y<=1;y++){            
            if(!(x==0&&y==0)&&plate[i+x][j+y]!=0&&plate[i+x][j+y]!=player){
                for(distance=2;plate[i+(x*distance)][j+(y*distance)]!=0&&plate[i+(x*distance)][j+(y*distance)]!=player;distance++){}
                if(plate[i+(x*distance)][j+(y*distance)]==player){
                    ans[a]=i+(x*distance);
                    ans[a+1]=j+(y*distance);
                    a+=2;
                }
            }
        }
    }
    return ans;
}

int main(){
    int plate[8][8];
    int i,j,player;
    int* answer;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            scanf("%d",&plate[i][j]);
        }
    }
    scanf("%d %d %d",&i,&j,&player);
    switch(plate[i+1][j+1]){
        case 0:
            printf("null\n");
            answer=step(i,j,plate,player);
            if(answer==NULL){
                printf("you can't step here\n");
            }
            else{
                printf("you can step here\n");
            }
            free(answer);
            break;
        case 1:
            printf("black\n");
            break;
        case 2:
            printf("white\n");
            break;
    }

    return 0;
}