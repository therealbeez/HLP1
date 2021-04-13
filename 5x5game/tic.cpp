// This is a trial for tic tac toe in C++
#include <iostream>
#include <string>
using namespace std;

string squares[25] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14"," 15","16","17","18","19"," 20","21","22","23","24"," 25"};

void play();
void getBoard();
void clearSquares();
int checkWin();

int main()
{

    string playAgain;
    do
    {
        play();
        cout << "Do you want to play again(y/n): ";
        cin >> playAgain;
        clearSquares();
        cout << "dantheman";
        

    } while ((playAgain) == "y");
    cin.get();
    
    return 0;

    return 0;
}

void clearSquares()
{
    int i = 1;
    for (auto& x: squares)
    {
        x = std::to_string(i);
        i++;
    }
}
//Play the game
void play()
{
    int *i = new int;
    int player = 1;
    int *choice = new int;
    string *mark = new string;

    do
    {
        getBoard();
        player = (player%2) ? 1 : 2;
        cout << "Enter your choice: ";
        cin >> *choice;
        *mark = (player == 1) ? 'X' : 'O';

        if (*choice >= 1 && *choice <= 25) {
            if (((squares[*choice - 1] == "X")))
            { 
                cout << "This field is already taken! Please choose another one \n";
                cin >> *choice;
                squares[*choice - 1] = *mark;
            }
            else
            {
                squares[*choice - 1] = *mark;
            }
            
            }
        else if (*choice == 77)
        {
            cout << "THANKS FOR PLAYING!!!";
            exit(1);
        }
        else if (*choice == 88)
        {
            cout << "restart";
            clearSquares();
            play();
        }
        else if (*choice == 99)
        {
            cout << "THE RULES \n 1, Players plays in turns \n 2, On their turn player put x (player 1) or o (player 2) in an empty cell. \n 3, That player loses who have 3 of their pieces in adjacent form (either row,column or diagonal) \n 4, If all the cells have been filled and no player has won then game is tied.";
        }
        
        else
        {
            cout << "Invalid move! only integers between 1 and 9 are accepted. Please choose another one \n";
            player--;
            cin.clear();
            cin.ignore();
            cin.get();
            cin >> *choice;
            squares[*choice - 1] = *mark;


        }

        *i = checkWin();
        player++;

    } while (*i == -1);
    getBoard();
    if (*i == 1)
    {
        cout << "\aPlayer " << --player << " Loses" << endl;
        delete mark, choice, i;
    }
    else
    {
        cout << "\aGame Draw" << endl;
        delete mark, choice, i;
    }
}

// Print the board
void getBoard()
{
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "\n input 77 to quit game";
    cout << "\n input 88 to reset game";
    cout << "\n input 99 to see the rules \n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl
        << endl;
    cout << endl;

    cout << "     |     |     |     |" << endl;
    cout << "  " << squares[0] << "     " << squares[1] << "     " << squares[2] <<"     " << squares[3] << "     " << squares[4] <<endl;

    cout << "_____|_____|_____|_____|_____" << endl;
    cout << "     |     |     |     |     " << endl;

    cout << "  " << squares[5] << "     " << squares[6] << "     " << squares[7] <<"     " << squares[8] << "     " << squares[9] <<endl;


    cout << "_____|_____|_____|_____|_____" << endl;
    cout << "     |     |     |     |     " << endl;

    cout << "  " << squares[10] << "    " << squares[11] << "    " << squares[12] <<"    " << squares[13] << "    " << squares[14] <<endl;

    
    cout << "_____|_____|_____|_____|_____" << endl;
    cout << "     |     |     |     |     " << endl;

    cout << "  " << squares[15] << "    " << squares[16] << "    " << squares[17] <<"    " << squares[18] << "    " << squares[19] <<endl;

    
    cout << "_____|_____|_____|_____|_____" << endl;
    cout << "     |     |     |     |     " << endl;

    cout << "  " << squares[20] << "    " << squares[21] << "    " << squares[22] <<"    " << squares[23] << "    " << squares[24] <<endl;


    cout << "     |     |     |     |" << endl
        << endl;
}

/**********************************************************************************************************
Return 1 if some one loses
Return -1 if the game is not over
***********************************************************************************************************/

int checkWin()
{
//rules for accross
    //row1    
    if (squares[0] == squares[1] && squares[1] == squares[2])
    {
        return 1;
    }
    else if (squares[1] == squares[2] && squares[2] == squares[3])
    {
        return 1;
    }
    if (squares[2] == squares[3] && squares[3] == squares[4])
    {
        return 1;
    }
    //row2
    if (squares[5] == squares[6] && squares[6] == squares[7])
    {
        return 1;
    }
    if (squares[6] == squares[7] && squares[7] == squares[8])
    {
        return 1;
    }
    if (squares[7] == squares[8] && squares[8] == squares[9])
    {
        return 1;
    }
    //row3
    if (squares[10] == squares[11] && squares[11] == squares[12])
    {
        return 1;
    }
    if (squares[11] == squares[12] && squares[12] == squares[13])
    {
        return 1;
    }
    if (squares[12] == squares[13] && squares[13] == squares[14])
    {
        return 1;
    }
    //row4
    if (squares[15] == squares[16] && squares[16] == squares[17])
    {
        return 1;
    }
    if (squares[16] == squares[17] && squares[17] == squares[18])
    {
        return 1;
    }
    if (squares[17] == squares[18] && squares[18] == squares[19])
    {
        return 1;
    }
    //row5
    if (squares[20] == squares[21] && squares[21] == squares[22])
    {
        return 1;
    }
    if (squares[21] == squares[22] && squares[22] == squares[23])
    {
        return 1;
    }
    if (squares[22] == squares[23] && squares[23] == squares[24])
    {
        return 1;
    }
//down
    //col1
    if (squares[0] == squares[5] && squares[5] == squares[10])
    {
        return 1;
    }
    if (squares[5] == squares[10] && squares[10] == squares[15])
    {
        return 1;
    }
    if (squares[10] == squares[15] && squares[15] == squares[20])
    {
        return 1;
    }
    //col2
    if (squares[1] == squares[6] && squares[6] == squares[11])
    {
        return 1;
    }
    if (squares[6] == squares[11] && squares[11] == squares[16])
    {
        return 1;
    }
    if (squares[11] == squares[16] && squares[16] == squares[21])
    {
        return 1;
    }
    //col3
    if (squares[2] == squares[7] && squares[7] == squares[12])
    {
        return 1;
    }
    if (squares[7] == squares[12] && squares[12] == squares[17])
    {
        return 1;
    }
    if (squares[12] == squares[17] && squares[17] == squares[22])
    {
        return 1;
    }
    //col4
    if (squares[3] == squares[8] && squares[8] == squares[13])
    {
        return 1;
    }
    if (squares[8] == squares[13] && squares[13] == squares[18])
    {
        return 1;
    }
    if (squares[13] == squares[18] && squares[18] == squares[23])
    {
        return 1;
    }
    //col5
    if (squares[4] == squares[9] && squares[9] == squares[14])
    {
        return 1;
    }
    if (squares[9] == squares[14] && squares[14] == squares[19])
    {
        return 1;
    }
    if (squares[14] == squares[19] && squares[19] == squares[24])
    {
        return 1;
    }

//DiagonalsL
    if (squares[2] == squares[6] && squares[6] == squares[10])
    {
        return 1;
    }
    if (squares[3] == squares[7] && squares[7] == squares[11])
    {
        return 1;
    }
    if (squares[7] == squares[11] && squares[11] == squares[15])
    {
        return 1;
    }

    if (squares[4] == squares[8] && squares[8] == squares[12])
    {
        return 1;
    }
    if (squares[8] == squares[12] && squares[12] == squares[16])
    {
        return 1;
    }
    if (squares[12] == squares[16] && squares[16] == squares[20])
    {
        return 1;
    }

    if (squares[9] == squares[13] && squares[13] == squares[17])
    {
        return 1;
    }
    if (squares[13] == squares[17] && squares[17] == squares[21])
    {
        return 1;
    }
    if (squares[14] == squares[18] && squares[18] == squares[22])
    {
        return 1;
    }

    //DiagonalsR
    if (squares[2] == squares[8] && squares[8] == squares[14])
    {
        return 1;
    }
    if (squares[1] == squares[7] && squares[7] == squares[13])
    {
        return 1;
    }
    if (squares[7] == squares[13] && squares[13] == squares[19])
    {
        return 1;
    }

    if (squares[0] == squares[6] && squares[6] == squares[12])
    {
        return 1;
    }
    if (squares[6] == squares[12] && squares[12] == squares[18])
    {
        return 1;
    }
    if (squares[12] == squares[18] && squares[18] == squares[24])
    {
        return 1;
    }

    if (squares[5] == squares[11] && squares[11] == squares[17])
    {
        return 1;
    }
    if (squares[11] == squares[17]&& squares[17] == squares[23])
    {
        return 1;
    }
    if (squares[10] == squares[16] && squares[16] == squares[22])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}