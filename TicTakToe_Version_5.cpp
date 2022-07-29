#include<stdio.h>
#include<bits/stdc++.h>
#include <iostream>


using namespace std;
char a[3][3];
int b[3][3];
const char PLAYER = 'X';
const char Computer = '0';

void resetBoard();
void print();
int freeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char );
int minimax();
int maxSearch();
int minSearch();
int max(int,int);
int min(int,int);


int main()
{

    char winner=' ';
    resetBoard();
    while(winner==' ' && freeSpaces()!=0)
    {
            print();
            playerMove();
            winner=checkWinner();
            if(winner!=' ' || freeSpaces()==0)
            {
                break;
            }
            print();
            computerMove();
            winner=checkWinner();
            if(winner!=' ' || freeSpaces()==0)
            {
                break;
            }
    }
    print();
    printWinner(winner);


}
void resetBoard()
{
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j]=' ';
        }
    }

}
void print()
{
    cout<<" "<<a[0][0]<<" | "<<a[0][1]<<" | "<<a[0][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<a[1][0]<<" | "<<a[1][1]<<" | "<<a[1][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<a[2][0]<<" | "<<a[2][1]<<" | "<<a[2][2]<<endl;

    cout<<endl;


}
int freeSpaces()
{
    int cnt=9;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!=' ')
            {
                cnt--;
            }
        }
    }
    return cnt;

}
void playerMove()
{

   int x;
int row, cell;
   do
   {
  cout<<"Enter the box number,where you want to put the X :";
   cin>> x;
   cout<<endl;
   x--;
   row = x/3;
cell = x%3;
   if(a[row][cell]!=' ')
   {
       for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==' ')
            {
                b[i][j]=(i+1)*(j+1);
            }
        }





       }
    cout<<" "<<b[0][0]<<" | "<<b[0][1]<<" | "<<b[0][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<b[1][0]<<" | "<<b[1][1]<<" | "<<b[1][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<b[2][0]<<" | "<<b[2][1]<<" | "<<b[2][2]<<endl;

    cout<<endl;
       cout<<" Try to enter a valid Box Number & check whats available  ! ";

   }
   else
    {
        cout<<" Player Move "<<endl;
        a[row][cell]=PLAYER;
        break;
    }

   }
   while(a[row][cell]!=' ');

}
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
        return y;
}
int min(int x,int y)
{
    if(x<y)
    {
        return x;
    }
    else
        return y;
}
int minimax()
{
    int x=-1;
    int score=+1111111;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           if(a[i][j]==' ')
        {
            a[i][j]=Computer;
            int tem = maxSearch();
            if(tem < score)
            {
                score = tem;
                x = i;
            }
            a[i][j] = ' '; //Reseting the board to previous place
        }
        }

    }
    return x;

}
int maxSearch() //maximize the player
{
    if(checkWinner()==PLAYER) //Base Case
    {
        return 10;
    }
    else if(checkWinner()==Computer)  //base case
    {
        return -10;
    }
    else if(freeSpaces()==0)
    {
        return 0;
    }
        int score = -99999;
        for(int i =0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
            if(a[i][j]==' ')
            {
                a[i][j]=PLAYER;
                int x=minSearch();
                score = max(score , x);
                a[i][j]=' ';
            }
        }
        }
        return score;

}
int minSearch() //minimize the computer value
{
    if(checkWinner()==PLAYER)
    {
        return 10;
    }
    else if(checkWinner()==Computer)
    {
        return -10;
    }
    else if(freeSpaces()==0)
    {
        return 0;
    }
    int score = +1000000000;
    for(int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
        if(a[i][j]==' ')
        {
            a[i][j]=Computer;
            score = min(score,maxSearch());
            a[i][j]=' ';
        }
        }
    }
    return score;
}
void computerMove()
{
    if(freeSpaces()>0)
    {

    int x = minimax();
    int row=x/3;
    int cell = x%3;
    cout<<"Computer Move :";
    cout<<x+1<<endl;
    a[row][cell]=Computer;
    }
    else
    {
        printWinner(' ');
    }



}
char checkWinner()
{
 if(a[0][0]==a[0][1] && a[0][1]==a[0][2])             // 0 0 0
    {                                // 0 1 0
        return a[0][0];
    }
    else if(a[1][0]==a[1][1] &&  a[1][2]==a[1][0])
    {
        return a[1][0];
    }
    else if(a[2][0]==a[2][1] && a[2][0]==a[2][2])
    {
        return a[2][0];
    }
   else if(a[0][0]==a[1][0] && a[0][0]==a[2][0])
    {
        return a[0][0];
    }
    else if(a[0][1]==a[1][1] && a[2][1]==a[1][1])
    {
        return a[0][1];
    }
   else if(a[0][2]==a[1][2] &&a[0][2]==a[2][2])
    {
        return a[0][2];
    }
   else if(a[0][0]==a[1][1] &&a[2][2]==a[1][1])
    {
        return a[0][0];
    }
    else if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
    {
        return a[0][2];
    }

    else
    {
        return ' ';
    }


}
void printWinner(char x)
{
    if(x==PLAYER)
    {
        cout<<" You Win "<<endl;
    }
    else if(x==Computer)
    {
        cout<<" YOU Lose "<<endl;
    }
    else
    {
        cout<<" Its a Tie "<<endl;
    }
}
