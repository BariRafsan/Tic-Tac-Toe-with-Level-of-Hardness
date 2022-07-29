#include<stdio.h>
#include<bits/stdc++.h>
#include <iostream>

using namespace std;
char a[9];
int b[9];
const char PLAYER = 'X';
const char Computer = '0';

void resetBoard();
void print();
int freeSpaces();
void playerMove();
void computerMove(int);
char checkWinner();
void printWinner(char );
int minimax();
int minimaxEasy();
int minimaxMedium();
int maxSearch();
int minSearch();
int max(int,int);
int min(int,int);


int main()
{

    cout<<"                                              OXOX Let's Play Tic Tac Toe XOXO                  "<<endl<<endl;;;
    char x;
    do{
    cout<<"                                             Select Your complicated level :"<<endl;
    cout<<"                                    Press 1 for Easy , Press 2 for Medium , Press 3 for Hard :";
    int j;
    cin>>j;
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
            computerMove(j);
            winner=checkWinner();
            if(winner!=' ' || freeSpaces()==0)
            {
                break;
            }
    }
    print();
    printWinner(winner);

    cout<<"want to play again y/n :";
    cin>>x;
    if(x=='n')
    {
        cout<<endl;
        cout<<"                        Thanks For Playing the game! This was developed By Rafsan Bari Shafin";
        break;
    }
    else if(x=='y')
    {

    }
    else
        cout<<"                                Enter a valid character again from y/n :";
        cin>>x;
    }
    while(x=='y');
}
void resetBoard()
{
    for(int i=0;i<9;i++)
    {
        a[i]=' ';
    }
}
void print()
{
    cout<<"                                          "<<a[0]<<" | "<<a[1]<<" | "<<a[2]<<endl;
    cout<<"                                         ---|---|---"<<endl;
    cout<<"                                          "<<a[3]<<" | "<<a[4]<<" | "<<a[5]<<endl;
    cout<<"                                         ---|---|---"<<endl;
    cout<<"                                          "<<a[6]<<" | "<<a[7]<<" | "<<a[8]<<endl;
    cout<<endl;


}
int freeSpaces()
{
    int cnt=9;
    for(int i=0;i<9;i++)
    {
        if(a[i]!=' ')
        {
            cnt--;
        }
    }
    return cnt;
}
void playerMove()
{

   int x;
   do
   {
    cout<<"Enter the box number,where you want to put the X :";
   cin>> x;
   cout<<endl;
   x--;
   if(a[x]!=' ')
   {

       for(int i=0;i<9;i++)
       {
           if(a[i]==' ')
           {
               b[i]=i+1;
           }
           else
           {

              // b[i]=;
           }
       }
    cout<<"                                          "<<b[0]<<" | "<<b[1]<<" | "<<b[2]<<endl;
    cout<<"                                         ---|---|---"<<endl;
    cout<<"                                          "<<b[3]<<" | "<<b[4]<<" | "<<b[5]<<endl;
    cout<<"                                         ---|---|---"<<endl;
    cout<<"                                          "<<b[6]<<" | "<<b[7]<<" | "<<b[8]<<endl;
    cout<<endl;
       cout<<" Try to enter a valid Box Number & check whats available  ! ";

   }
   else
    {
        cout<<" Player Move "<<endl;
        a[x]=PLAYER;
        break;
    }

   }
   while(a[x]!=' ');

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
int minimaxMedium()
{
    int x=-1;
    int score=+1111111;
    for(int i=0;i<9;i++)
    {
        if(a[i]==' ')
        {
            a[i]=Computer;
            int tem = minSearch();
            if(tem < score)
            {
                score = tem;
                x = i;
            }
            a[i] = ' '; //Reseting the board to previous place
        }
    }
    return x;
}
int minimaxEasy()
{
    int x=-1;
    int score=-1111111;
    for(int i=0;i<9;i++)
    {
        if(a[i]==' ')
        {
            a[i]=Computer;
            int tem = maxSearch();
            if(tem > score)
            {
                score = tem;
                x = i;
            }
            a[i] = ' '; //Reseting the board to previous place
        }
    }
    return x;
}
int minimax()
{
    int x=-1;
    int score=+1111111;
    for(int i=0;i<9;i++)
    {
        if(a[i]==' ')
        {
            a[i]=Computer;
            int tem = maxSearch();
            if(tem <score)
            {
                score = tem;
                x = i;
            }
            a[i] = ' '; //Reseting the board to previous place
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
        for(int i =0;i<9;i++)
        {
            if(a[i]==' ')
            {
                a[i]=PLAYER;
                int x=minSearch();
                score = max(score , x);
                a[i]=' ';
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
    for(int i = 0;i<9;i++)
    {
        if(a[i]==' ')
        {
            a[i]=Computer;
            score = min(score,maxSearch());
            a[i]=' ';
        }
    }
    return score;
}
void computerMove(int j)
{
    if(j==1)
    {
        if(freeSpaces()>0)
        {


        int x = minimaxEasy();
        cout<<"Computer Move :";
        cout<<x+1<<endl;
        a[x]=Computer;
        }
        else
        {
        printWinner(' ');
    }

    }
    else if(j==2)
    {
        if(freeSpaces()>0)
        {


        int x = minimaxMedium();
        cout<<"Computer Move :";
        cout<<x+1<<endl;
        a[x]=Computer;
        }
        else
        {
        printWinner(' ');
    }
    }
    else{
    if(freeSpaces()>0)
    {
    int x = minimax();
    cout<<"Computer Move :";
    cout<<x+1<<endl;
    a[x]=Computer;
    }

    else
    {
        printWinner(' ');
    }
    }

}
char checkWinner()
{
 if(a[0]==a[1] && a[1]==a[2])
    {
        return a[0];
    }
    else if(a[3]==a[4] &&  a[4]==a[5])
    {
        return a[3];
    }
    else if(a[6]==a[7] && a[7]==a[8])
    {
        return a[6];
    }
   else if(a[0]==a[4] && a[4]==a[8])
    {
        return a[0];
    }
    else if(a[0]==a[3] && a[3]==a[6])
    {
        return a[0];
    }
   else if(a[1]==a[4] &&a[4]==a[7])
    {
        return a[1];
    }
   else if(a[2]==a[5] &&a[5]==a[8])
    {
        return a[2];
    }
    else if(a[2]==a[4] && a[4]==a[6])
    {
        return a[2];
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
        cout<<"                                          You Win "<<endl;
    }
    else if(x==Computer)
    {
        cout<<"                                          YOU Lose "<<endl;
    }
    else
    {
        cout<<"                                          Its a Tie "<<endl;
    }
}
