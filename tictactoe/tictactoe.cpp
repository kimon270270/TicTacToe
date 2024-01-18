#include <iostream>
#include <random>
#include <cstdlib>

using namespace std;

/*
X -- +1
O -- -1
? -- 0

numbering scheme for the board:

[0] | [1] | [2]
[3] | [4] | [5]
[6] | [7] | [8]


*/

int
    board[9];

int score(int cell1,int cell2,int cell3)
{
   return (board[cell1] + board[cell2] + board[cell3]);
}

bool playerWins(int playerNum)
{

    if ((score(0,1,2) == 3 && playerNum == 1) || score(0,1,2) == -3 && playerNum == -1)
        return true;
       
    else if ((score(3,4,5) == 3 && playerNum == 1) || score(3,4,5) == -3 && playerNum == -1)
        return true;

    else if ((score(6,7,8) == 3 && playerNum == 1) || score(6,7,8) == -3 && playerNum == -1)
        return true;

    else if ((score(0,3,6) == 3 && playerNum == 1) || score(0,3,6) == -3 && playerNum == -1)
        return true;
       
    else if ((score(1,4,7) == 3 && playerNum == 1) || score(1,4,7) == -3 && playerNum == -1)
        return true;
       
    else if ((score(2,5,8) == 3 && playerNum == 1) || score(2,5,8) == -3 && playerNum == -1)
        return true;
       
    else if ((score(0,4,8) == 3 && playerNum == 1) || score(0,4,8) == -3 && playerNum == -1)
        return true;
       
    else if ((score(2,4,6) == 3 && playerNum == 1) || score(2,4,6) == -3 && playerNum == -1)
        return true;  

    return false;
}

bool canWin(int playerNum,int &winningSquare)
{

    if ((score(0,1,2) == 2 && playerNum == 1) || (score(0,1,2) == -2 && playerNum == -1))
    {
        if (board[0] == 0)
            winningSquare = 0;
           
        if (board[1] == 0)
            winningSquare = 1;
           
        if (board[2] == 0)
            winningSquare = 2;
           
        return true;
    }
     
     if ((score(3,4,5) == 2 && playerNum == 1) || (score(3,4,5) == -2 && playerNum == -1))
    {
        if (board[3] == 0)
            winningSquare = 3;
           
        if (board[4] == 0)
            winningSquare = 4;
           
        if (board[5] == 0)
            winningSquare = 5;
           
        return true;
    }
   
    if ((score(6,7,8) == 2 && playerNum == 1) || (score(6,7,8) == -2 && playerNum == -1))
    {
        if (board[6] == 0)
            winningSquare = 6;
           
        if (board[7] == 0)
            winningSquare = 7;
           
        if (board[8] == 0)
            winningSquare = 8;
           
        return true;
    }
   
    if ((score(0,3,6) == 2 && playerNum == 1) || (score(0,3,6) == -2 && playerNum == -1))
    {
        if (board[0] == 0)
            winningSquare = 0;
           
        if (board[3] == 0)
            winningSquare = 3;
           
        if (board[6] == 0)
            winningSquare = 6;
           
        return true;
    }
   
    if ((score(1,4,7) == 2 && playerNum == 1) || (score(1,4,7) == -2 && playerNum == -1))
    {
        if (board[1] == 0)
            winningSquare = 1;
           
        if (board[4] == 0)
            winningSquare = 4;
           
        if (board[7] == 0)
            winningSquare = 7;
           
        return true;
    }
   
    if ((score(2,5,8) == 2 && playerNum == 1) || (score(2,5,8) == -2 && playerNum == -1))
    {
        if (board[2] == 0)
            winningSquare = 2;
           
        if (board[5] == 0)
            winningSquare = 5;
           
        if (board[8] == 0)
            winningSquare = 8;
           
        return true;
    }
   
    if ((score(0,4,8) == 2 && playerNum == 1) || (score(0,4,8) == -2 && playerNum == -1))
    {
        if (board[0] == 0)
            winningSquare = 0;
           
        if (board[4] == 0)
            winningSquare = 4;
           
        if (board[8] == 0)
            winningSquare = 8;
           
        return true;
    }
   
    if ((score(2,4,6) == 2 && playerNum == 1) || (score(2,4,6) == -2 && playerNum == -1))
    {
        if (board[2] == 0)
            winningSquare = 2;
           
        if (board[4] == 0)
            winningSquare = 4;
           
        if (board[6] == 0)
            winningSquare = 6;
           
        return true;
    }

    return false;
}

char toLetter(int cell)
{

    if (cell == 1)
        return 'X';
    else if (cell == -1)
        return 'O';
    else
        return ' ';
}

void printBoard()
{

    cout << "   |   |   " << endl;
    cout << ' ' << toLetter(board[0]) << " | " << toLetter(board[1]) << " | "
         << toLetter(board[2]) << ' ' << endl;
    cout << "   |   |   \n"
            "---+---+---\n"
            "   |   |   " << endl;
    cout << ' ' << toLetter(board[3]) << " | " << toLetter(board[4]) << " | "
         << toLetter(board[5]) << ' ' << endl;
    cout << "   |   |   \n"
            "---+---+---\n"
            "   |   |   " << endl;
    cout << ' ' << toLetter(board[6]) << " | " << toLetter(board[7]) << " | "
         << toLetter(board[8]) << ' ' << endl;
    cout << "   |   |   " << endl;
}

int getComputerMove(int computerNum)
{
   
    /*
     * number in description is as per human understanding for our program we use number-1
     * if you can win win
     * if you can block block
     * if you can take the center take the center
     * if you can take the square 1,3,7,9 (human format) take it
     * if you can take square 2,4,6,8 (human format) take it
     */
   
    // this program if the computer can win and if there is positon to block computer will block and not win
   
    int
        winningSquare;
       
    if (canWin(computerNum,winningSquare))
        return winningSquare;

    
    else if (canWin(-computerNum, winningSquare))        //if you can block block
        return winningSquare;
       
    else if (board[4] == 0)
        return 4;
       
    else if (board[0] == 0)
        return 0;
       
    else if (board[2] == 0)
        return 2;
       
    else if (board[6] == 0)
        return 6;
       
    else if (board[8] == 0)
        return 8;
       
    else if (board[1] == 0)
        return 1;
       
    else if (board[3] == 0)
        return 3;
       
    else if (board[5] == 0)
        return 5;
       
    else if (board[7] == 0)
        return 7;
       
    return 0;
       
}

int getHumanMove(int playerNum)
{
   
    //number provided by human is as per human understanding use number-1 for our project
   
    int index, position;
   
    cout << "Enter the cell (1 -- 9) you want to occupy: ";
    cin >> index;
    cout << endl;
   
    position = index - 1;
   
    if (board[position] != 0 || index < 1 || index > 9)
    {
        cout << "Invalid Input.\n"
            "Try Again or Enter 100 to quit." << endl;
           
        do
        {
            cin >> index;
           
            if (index == 100)
               exit(0);

            position = index -1;
        }
        while (board[position] != 0 || index < 1 || index > 9);
    }
   
    return position;
}

int main()
{
    random_device
        rd;
       
    mt19937
        mt(rd());
       
    uniform_int_distribution<>
        dis(0,1);
       
    int
        currentPlayer = 1,
        winningSquare,
        computerNum;
   
    computerNum = dis(mt) * 2 - 1;      //this will give us -1 or 1 which is the numbers we want
   
    for (int i = 0 ; i < 9 ; i++)
    {
        if (computerNum == currentPlayer)
            board[getComputerMove(computerNum)] = computerNum;
           
        if (playerWins(computerNum))
        {
            cout << "Computer Won!!" << endl << endl;
            printBoard();
            return 0;
        }    
           
        if (computerNum != currentPlayer)
        {
             printBoard();
             if (canWin(-computerNum, winningSquare))
             {
                 cout << "You can win in this move.\n"
                         "Occupy: " << winningSquare+1 << endl << endl;
             }
             
             if (canWin(computerNum, winningSquare))
             {
                 cout << "Computer can win in this move\n"
                         "Block: " << winningSquare+1 << endl << endl;
             }
             board[getHumanMove(-computerNum)] = -computerNum;
        }
       
        if(playerWins(-computerNum))
        {
            cout << "You Won!!" << endl << endl;
            printBoard();
            return 0;
        }
       
        currentPlayer *= -1;
    }
   
    printBoard();
    cout << "Game Draw!!" << endl << endl;
                   
}