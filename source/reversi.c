#include<stdio.h>
#include<stdlib.h>

void select(int plate[8][8],int player){
    int count=0,i,j,selectx,selecty;
    int save[16];
    int* answer;
    printf("You can step at:");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(plate[i][j]==0){
                answer=step(i,j,plate,player);
                if(answer!=NULL){
                    printf("(%d,%d)",i,j);
                    save[count]=i;
                    save[count+1]=j;
                    count+=2;
                }
            }
        }
    }
    free(answer);
    if(count==0){
        printf("no where\n");
    }
    else{
        printf("\n");
        scanf("%d%d",&selectx,&selecty);
        count/=2;
    }
}

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

int* black(int i,int j,int plate[8][8]){
    int i,j,motion=0;
    int* ans,answer;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            answer=step(i,j,plate,1);
            if(answer!=NULL){
                ans[motion]=i;
                ans[motion+1]=j;
                motion+=2;
            }
            free(answer);
        }
    }
    return ans;
}

int* white(int i,int j,int plate[8][8]){
    int i,j,motion=0;
    int* ans,answer;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            answer=step(i,j,plate,2);
            if(answer!=NULL){
                ans[motion]=i;
                ans[motion+1]=j;
                motion+=2;
            }
            free(answer);
        }
    }
    return ans;
}

int main(){
    int plate[8][8],save[16];
    int i,j,player;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            scanf("%d",&plate[i][j]);
        }
    }
    printf("Player 1 first\n");
    select(plate,1);

    return 0;
}