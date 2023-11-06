#include <stdio.h>
#define SIZE 8

char board[SIZE][SIZE];
int validMoves[SIZE][SIZE];

void initBoard(){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            board[i][j]='0';
        }
    }
    board[3][3]=board[4][4]='1';
    board[3][4]=board[4][3]='2';
}

void clearValidMoves(){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            validMoves[i][j]=0;
        }
    }
}

void printBoard(){
    int i,j;
    printf("  0 1 2 3 4 5 6 7\n");
    for(i=0;i<SIZE;i++){
        printf("%d ",i);
        for(j=0;j<SIZE;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int row,int col,char player){
    int x,y,r,c,valid=0;
    if(row<0||row>=SIZE||col<0||col>=SIZE||board[row][col]!='0'){
        return 0;
    }
    for(x=-1;x<2;x++){
        for(y=-1;y<2;y++){
            if(!(x==0&&y==0)){
                r=row+x;
                c=col+y;
                while(r>=0&&r<SIZE&&c>0&&c<SIZE&&board[r][c]!='0'&&board[r][c]!=player){
                    r+=x;
                    c+=y;
                    if(r>=0&&r<SIZE&&c>=0&&c<SIZE&&board[r][c]==player){
                        valid=1;
                        break;
                    }
                }
            }
        }
    }

    return valid;
}

void makeMove(int row,int col,char player){
    int x,y,r,c;
    if(!isValidMove(row,col,player)){
        return;
    }
    board[row][col]=player;
    for(x=-1;x<2;x++){
        for(y=-1;y<2;y++){
            if(!(x==0&&y==0)){
                r=row+x;
                c=col+y;
                while(r>=0&&r<SIZE&&c>0&&c<SIZE&&board[r][c]!=0&&board[r][c]!=player){
                    r+=x;
                    c+=y;
                    if(r>=0&&r<SIZE&&c>=0&&c<SIZE&&board[r][c]==player){
                        while(r!=row||c!=col){
                            r-=x;
                            c-=y;
                            board[r][c]=player;
                        }
                    }
                }
            }
        }
    }
}

void updateValidMoves(char currentPlayer){
    int i,j;
    clearValidMoves();
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(isValidMove(i,j,currentPlayer)){
                validMoves[i][j]=1;
            }
        }
    }
}

int main(){
    char currentPlayer='1';
    int gameOver=0,i,j,row,col,total1=0,total2=0,count=0;
    initBoard();
    while(!gameOver){
        updateValidMoves(currentPlayer);
        printBoard();
        printf("player%c,can step at:",currentPlayer);
        count=0;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(validMoves[i][j]==1){
                    printf("(%d %d)",i,j);
                    count++;
                }
            }
        }
        if(count==0){
            printf("null\n");
            printf("player%c can't step\n",currentPlayer);
            if(currentPlayer=='2'){
                currentPlayer='1';
            }
            else{
                currentPlayer='2';
            }
        }
        else{
            printf("\nyou want to step at:");
            scanf("%d %d",&row,&col);
            if(validMoves[row][col]){
                makeMove(row,col,currentPlayer);
                if(currentPlayer=='2'){
                    currentPlayer='1';
                } else{
                    currentPlayer='2';
                }
                gameOver=1;
                for(i=0;i<SIZE;i++){
                    for(j=0;j<SIZE;j++){
                        if(board[i][j]=='0'){
                            if(isValidMove(i,j,'2')||isValidMove(i,j,'1')){
                                gameOver=0;
                                break;
                            }
                        }
                    }
                }
            }
            else{
                printf("you can't step here\n");
            }
        }
    }
    printBoard();
    printf("gameover\n");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]=='1'){
                total1++;
            }
            else{
                total2++;
            }
        }
    }
    printf("1vs2 %d:%d\n",total1,total2);
    
    return 0;
}