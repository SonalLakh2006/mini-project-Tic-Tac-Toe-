#include<iostream>
using namespace std;

char board[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard()
{
    cout << "\n";

    for(int i=0;i<3;i++)
    {
        cout << " ";

        for(int j=0;j<3;j++)
        {
            cout << board[i][j];

            if(j<2)
                cout << " | ";
        }

        cout << "\n";

        if(i<2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

bool checkWin(char player)
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==player &&
           board[i][1]==player &&
           board[i][2]==player)
           return true;
    }

    for(int i=0;i<3;i++)
    {
        if(board[0][i]==player &&
           board[1][i]==player &&
           board[2][i]==player)
           return true;
    }

    if(board[0][0]==player &&
       board[1][1]==player &&
       board[2][2]==player)
       return true;

    if(board[0][2]==player &&
       board[1][1]==player &&
       board[2][0]==player)
       return true;

    return false;
}

bool boardFull()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
               return false;
        }
    }

    return true;
}

int main()
{
    char currentPlayer = 'X';
    int choice;
    char again;

    do
    {
        board[0][0]='1';
        board[0][1]='2';
        board[0][2]='3';
        board[1][0]='4';
        board[1][1]='5';
        board[1][2]='6';
        board[2][0]='7';
        board[2][1]='8';
        board[2][2]='9';

        currentPlayer='X';

        while(true)
        {
            displayBoard();

            cout << "Player "
                 << currentPlayer
                 << ", Enter Position : ";

            cin >> choice;

            bool validMove = true;

            switch(choice)
            {
                case 1:
                    if(board[0][0]=='1')
                        board[0][0]=currentPlayer;
                    else
                        validMove=false;
                    break;

                case 2:
                    if(board[0][1]=='2')
                        board[0][1]=currentPlayer;
                    else
                        validMove=false;
                    break;

                case 3:
                    if(board[0][2]=='3')
                        board[0][2]=currentPlayer;
                    else
                        validMove=false;
                    break;

                case 4:
                    if(board[1][0]=='4')
                        board[1][0]=currentPlayer;
                    else
                        validMove=false;
                    break;

                case 5:
                    if(board[1][1]=='5')
                        board[1][1]=currentPlayer;
                    else
                        validMove=false;
                    break;

                case 6:
                    if(board[1][2]=='6')
                        board[1][2]=currentPlayer;
                    else
                        validMove=false;
                    break;

                case 7:
                    if(board[2][0]=='7')
                        board[2][0]=currentPlayer;
                    else
                        validMove=false;
                    break;

                case 8:
                    if(board[2][1]=='8')
                        board[2][1]=currentPlayer;
                    else
                        validMove=false;
                    break;

                case 9:
                    if(board[2][2]=='9')
                        board[2][2]=currentPlayer;
                    else
                        validMove=false;
                    break;

                default:
                    validMove=false;
            }

            if(!validMove)
            {
                cout << "\nInvalid Move! Try Again.\n";
                continue;
            }

            if(checkWin(currentPlayer))
            {
                displayBoard();

                cout << "\nPlayer "
                     << currentPlayer
                     << " Wins!\n";

                break;
            }

            if(boardFull())
            {
                displayBoard();

                cout << "\nMatch Draw!\n";

                break;
            }

            if(currentPlayer=='X')
                currentPlayer='O';
            else
                currentPlayer='X';
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> again;

    }while(again=='Y' || again=='y');

    cout << "\nThank You For Playing!\n";

    return 0;
}