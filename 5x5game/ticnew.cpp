#include "std_lib_facilities.h"

string squares[25] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14"," 15","16","17","18","19","20","21","22","23","24"," 25"};

int gamestate = -1;
int player = 1;
int choice = 0;
int choiceindex;
string mark = "a";

void play();
char checklegal();
void getboard();
void clearSquares();
int checkwin();


int main(){

    string playAgain;
    do
    {
        cout << "THE RULES \n 1, Players plays in turns \n 2, On their turn player put x (player 1) or o (player 2) in an empty cell. \n 3, That player loses who have 3 of their pieces in adjacent form (either row,column or diagonal) \n 4, If all the cells have been filled and no player has won then game is tied.";
        play();
        cout << "Do you want to play again(y/n): ";
        cin >> playAgain;
        clearSquares();
        

    } while ((playAgain) == "y");

    return 0;
}

//function to handle gamestate
void play(){   

    do
    {
        getboard();
        player = (player%2) ? 1 : 2;
        cout << "Enter your choice: ";
        cin >> choice;
        choiceindex = choice - 1;
        mark = (player == 1) ? "x" : "o";
        do
        {
            checklegal();
        } while (checklegal() != 'v');
        squares[choice - 1] = mark;
        gamestate = checkwin();
        player++;
        

    } while (gamestate == -1);

    getboard();
    if (gamestate == 1)
    {
        cout << "\aPlayer " << --player << " Loses" << endl;
        
    }
    else
    {
        cout << "\aGame Draw" << endl;
        
    }
    
}
//function to check wether user input is valid
char checklegal(){

    //checks if input is an integer
    if (cin.fail())
    {
        cout<<"Input is not an integer, please try again"<<endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
    }
    else{
        if( choice >= 1 && choice <= 25 ){

            //checks if user selected space is taken
            while (squares[choice - 1] == "x"||squares[choice - 1] == "o")
            {
                cout << "This field is already taken! Please choose another one \n";
                cin >> choice;
            }
            return 'v'; 
            }
        //checks for in-game options: rules, quit, and restart
        else if (choice == 77){
            cout << "THANKS FOR PLAYING!!!";
            exit(1);
        }
        else if (choice == 88){
            cout << "RESTART";
            clearSquares();
            player = 1;
            play();
        }
        else if (choice == 99){
            cout << "THE RULES \n 1, Players plays in turns \n 2, On their turn player put x (player 1) or o (player 2) in an empty cell. \n 3, That player loses who have 3 of their pieces in adjacent form (either row,column or diagonal) \n 4, If all the cells have been filled and no player has won then game is tied.";
            cout << endl;
            cout <<"Enter your choice"<<endl;
            cin.clear();
            cin >> choice;
        }
        else{
            cout << "Invalid move! Integers between 1 and 25 are accepted for board input.\n 77 to quit, 88 to restart, 99 to see the rules.\n Please input again \n";
            cin.clear();
            cin >> choice;
        }
    }
    return 'g';
}
//function to draw the board
void getboard(){

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
//resets the array that holds input back to the labels of 1-25
void clearSquares(){
    int i = 1;
    for (auto& x: squares)
    {
        x = std::to_string(i);
        i++;
    }
}

int checkwin(){

    //checks for accross match
    if((squares[choiceindex] == mark)&&(squares[choiceindex - 1] == mark)&&(squares[choiceindex - 2] == mark)){
        return 1;
    }
    else if((squares[choiceindex] == mark)&&(squares[choiceindex - 1] == mark)&&(squares[choiceindex + 1] == mark)){
        return 1;
    }
    else if((squares[choiceindex] == mark)&&(squares[choiceindex + 1] == mark)&&(squares[choiceindex + 2] == mark)){
        return 1;
    }
    //checks for down match
    if((squares[choiceindex] == mark)&&(squares[choiceindex - 5] == mark)&&(squares[choiceindex - 10] == mark)){
        return 1;
    }
    else if((squares[choiceindex] == mark)&&(squares[choiceindex - 5] == mark)&&(squares[choiceindex + 5] == mark)){
        return 1;
    }
    else if((squares[choiceindex] == mark)&&(squares[choiceindex + 5] == mark)&&(squares[choiceindex + 10] == mark)){
        return 1;
    }
    //checks for diagonal 1
    if((squares[choiceindex] == mark)&&(squares[choiceindex - 6] == mark)&&(squares[choiceindex - 12] == mark)){
        return 1;
    }
    else if((squares[choiceindex] == mark)&&(squares[choiceindex - 6] == mark)&&(squares[choiceindex + 6] == mark)){
        return 1;
    }
    else if((squares[choiceindex] == mark)&&(squares[choiceindex + 6] == mark)&&(squares[choiceindex + 12] == mark)){
        return 1;
    }
    //checks for other diagonal
    if((squares[choiceindex] == mark)&&(squares[choiceindex - 4] == mark)&&(squares[choiceindex - 8] == mark)){
        return 1;
    }
    else if((squares[choiceindex] == mark)&&(squares[choiceindex - 4] == mark)&&(squares[choiceindex + 4] == mark)){
        return 1;
    }
    else if((squares[choiceindex] == mark)&&(squares[choiceindex + 4] == mark)&&(squares[choiceindex + 8] == mark)){
        return 1;
    }
    else{
        return -1;
    }
    


}
