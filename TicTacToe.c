#include<stdio.h>
#include<stdlib.h>

int Board[3][3];

int gameMenu()
{
    int choice;
    printf("\nChoose:");
    printf("\n1.Play");
    printf("\n2.Exit Game\n");
    scanf("%d",&choice);
    return choice;
}

void resetGame()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            Board[i][j]=2;
        }
    }
}

void displayBoard()
{
    int i,j,k=1;
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(Board[i][j]==2)
                printf("%3d",k);
            else if(Board[i][j]==3)
                printf("%3c",'X');
            else if(Board[i][j]==5)
                printf("%3c",'O');
            k++;
        }
        printf("\n\n");
    }
}

int isMoveValid(int move)
{
    switch(move)
    {
        case 1:
            if(Board[0][0]=2)
                return 1;
            break;
        case 2:
            if(Board[0][1]==2)
                return 1;
            break;
        case 3:
            if(Board[0][2]==2)
                return 1;
            break;
        case 4:
            if(Board[1][0]==2)
                return 1;
            break;
        case 5:
            if(Board[1][1]==2)
                return 1;
            break;
        case 6:
            if(Board[1][2]==2)
                return 1;
            break;
        case 7:
            if(Board[2][0]==2)
                return 1;
            break;
        case 8:
            if(Board[2][1]==2)
                return 1;
            break;
        case 9:
            if(Board[2][2]==2)
                return 1;
            break;
    }
    return 0;
}

int inputMove(int Player)
{
    int move;
    do{
        printf("Player %d (Type square number to mark your move):",Player);
        scanf("%d",&move);
    }while(!isMoveValid(move));
    return move;    
}

void makeMove(int player,int move)
{
    int mark;
    mark=(player==1)?3:5;
    switch(move)
    {
        case 1:
            Board[0][0]=mark;
            break;
        case 2:
            Board[0][1]=mark;
            break;
        case 3:
            Board[0][2]=mark;
            break;
        case 4:
            Board[1][0]=mark;
            break;
        case 5:
            Board[1][1]=mark;
            break;
        case 6:
            Board[1][2]=mark;
            break;
        case 7:
            Board[2][0]=mark;
            break;
        case 8:
            Board[2][1]=mark;
            break;
        case 9:
            Board[2][2]=mark;
            break;
    }
}

int checkWin(int player)
{
    int winmark;
    winmark=(player==1)?27:125;
    int i,j;
    for(i=0;i<3;i++)
        if(Board[i][0]*Board[i][1]*Board[i][2]==winmark)
            return 1;
    for(j=0;j<3;j++)
        if(Board[0][j]*Board[1][j]*Board[2][j]==winmark)
            return 1;
    if(Board[0][0]*Board[1][1]*Board[2][2]==winmark)
        return 1;
    if(Board[2][0]*Board[1][1]*Board[0][2]==winmark)
        return 1;
    return 0;
}
int main()
{
    int turn,player,move,result;
    while(1)
    {
        switch(gameMenu())
        {
            case 1:
                resetGame();
                displayBoard();
                for(turn=1,player=1;turn<=9;turn++)
                {
                    move=inputMove(player);
                    makeMove(player,move);
                    system("cls");
                    displayBoard();
                    if(checkWin(player))
                    {
                        printf("\nPlayer %d won the game.",player);
                        break;
                    }
                    player=(player==1)?2:1;
                }
                if(turn==10)
                    printf("\nGame is drawn.");
                break;
            case 2:
                exit(0);
            default:
                printf("\nInvalid Choice, retry.");
        }
    }
    return 0;
}