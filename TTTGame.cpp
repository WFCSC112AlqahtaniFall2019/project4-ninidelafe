/* Class: TicTacToe
 * Author: Alexa (Nini) de la Fe
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    // declares necessary variables, instantiates the TicTacToe object, and places a seed for the random number generator to work
    TicTacToe game;
    int row;
    int col;
    int numPlayers;
    char rePlay = 'y';
    srand(time(0));
    int switchPlayer=1;
    cout<<"Welcome to the Tic Tack Toe Game!"<<endl;


    cout<<"Would you like to play a 1 or 2 person game? A 1 player game will allow you to play against the computer."<<endl;
    cin>>numPlayers;

    // checks to make sure the user inputted the correct number of players and if not asks the user to try again
    while (numPlayers!=1 && numPlayers!=2){
        cout<<"You did not enter a valid number of players. Please try again. Remember you can only play a 1 or 2 person game."<<endl;
        cin>>numPlayers;
    }

   //if the user choose to play against a computer this will run
    if (numPlayers==1) {
        //while loop that allows the user to play again if they choose to; asked at the end of their game
        while (rePlay != 'n') {
            int firstMove=rand()%2+1;//randomly selects a number to see which player will go first
            game.initializeBoard(); //clears board
            cout<<"You will be playing against the computer.";
            cout << "This is your game board: " << endl;
            game.printBoard();//prints board
               //takes the player 1's inputs and creates a random generated number while there is not a winner
                while (!game.checkForWin()) {
                    //prints a message telling the user that the computer is going first
                    if (firstMove==2){
                        cout<<"The computer was selected to start first"<<endl;
                        game.changePlayer();
                    }
                    //this will run when it is player 1's turn and then will increment firstMove at the end of the turn to allow the computer a turn
                    if (firstMove==1) {
                        cout << "Player 1: you are 'x'" << endl;
                        cout << "Please pick a row (1, 2, 3):" << endl;
                        cin >> row;
                        cout << "Please pick a column (1, 2, 3):" << endl;
                        cin >> col;
                        //checks to make sure the input is within the bounds and the box is not full if it is asks for another number
                        //while loop so that if an incorrect number is entered it will keep asking for a new number
                        while (!game.placeMark(row - 1, col - 1)) {
                            cout << "Please pick a row and column number that are within the bounds and not full. Enter row (1,2,3): "<< endl;
                            cin >> row;
                            cout << "Please enter column (1,2,3): " << endl;
                            cin >> col;
                        }
                        game.placeMark(row - 1, col - 1);
                        game.printBoard();
                        cout<<"Computer selected row: "<< row<<" and column: "<<col<<endl;
                        game.changePlayer();
                        firstMove++;
                    }
                    if (game.checkForWin()) {
                        break;
                    }
                    if (game.isBoardFull()) {
                        break;
                    }
                    //this will run when it is the computers turn and then will decrease firstMove at the end of the turn to allow player 1 a turn
                    if (firstMove==2) {
                        //Computer inputs (randomly generated)
                        row = rand() % 3 + 1;
                        col = rand() % 3 + 1;
                        //checks to make sure the input is within the bounds and the box is not full if it is creates a new one
                        //while loop so that if an incorrect number is entered again it will keep asking for a new number
                        while (!game.placeMark(row - 1, col - 1)) {
                            row = rand() % 3 + 1;
                            col = rand() % 3 + 1;
                        }
                        game.placeMark(row - 1, col - 1);
                        game.printBoard();
                        game.changePlayer();
                        firstMove--;
                        if (game.isBoardFull()) {
                            break;
                        }
                        if (game.checkForWin()) {
                            break;
                        }
                    }
            }
            // prints the winner, the board, and asks if the user wants to play again
            if (game.checkForWin()) {
                game.changePlayer();//switches player to winner because it is changed at the end of the while loop
                if (game.getCurrentPlayerNumber()==1) {
                    cout << "Congrats Player " << game.getCurrentPlayerNumber() << "! You won!" << endl;
                    game.printBoard();
                    cout << "Would you like to play again? ('y' for yes and 'n' for no)" << endl;
                    cin >> rePlay;
                }
                else{
                    cout<< "The computer beat you! "<<endl;
                    game.printBoard();
                    cout<<"Would you like to play again? ('y' for yes and 'n' for no)"<<endl;
                    cin>>rePlay;
                }
            }
            //prints that there was a tie and asks if the user wants to play again
            else if (game.isBoardFull()) {
                cout << "The game was a tie! Would you like to play again? ('y' for yes and 'n' for no)" << endl;
                cin>>rePlay;
            }
        }
    }

    //if the user chose to play with two players this will run
    else if (numPlayers==2) {
        //while loop that allows the user to play again if they choose to; asked at the end of their game
        while (rePlay != 'n') {
            game.initializeBoard();
            cout << "This is your game board: " << endl;
            game.printBoard();
            //takes the players inputs and prints them on the board
            while (!game.checkForWin()) {
                //prints a message telling the user that player 2 is going first
                if (switchPlayer==2){
                    cout<<"Player 2 you will now go first."<<endl;
                    game.changePlayer();
                }
                //this will run when it is player 1's turn and then will increment firstMove at the end of the turn to allow player 2 a turn
                if (switchPlayer == 1) {
                    cout << "Player 1: you are 'x'" << endl;
                    cout << "Please pick a row (1, 2, 3):" << endl;
                    cin >> row;
                    cout << "Please pick a column (1, 2, 3):" << endl;
                    cin >> col;
                    //checks to make sure the input is within the bounds and the box is not full if it is asks for another number
                    //while loop so that if an incorrect number is entered again it will keep asking for a new number
                    while (!game.placeMark(row - 1, col - 1)) {
                        cout
                                << "Please pick a row and column number that are within the bounds and not full. Enter row (1,2,3): "
                                << endl;
                        cin >> row;
                        cout << "Please enter column (1,2,3): " << endl;
                        cin >> col;
                    }
                    game.placeMark(row - 1, col - 1);
                    game.printBoard();
                    game.changePlayer();
                    switchPlayer++;
                }
                if (game.checkForWin()) {
                    break;
                }
                if (game.isBoardFull()) {
                    break;
                }
                //this will run when it is Player 2's turn and then will decrease firstMove at the end of the turn to allow player 1 a turn
                if (switchPlayer == 2) {
                    cout << "Player 2: you are 'o'" << endl;
                    cout << "Please pick a row (1, 2, 3):" << endl;
                    cin >> row;
                    cout << "Please pick a column (1, 2, 3):" << endl;
                    cin >> col;
                    //checks to make sure the input is within the bounds and the box is not full if it is asks for another number
                    while (!game.placeMark(row - 1, col - 1)) {
                        cout
                                << "Please pick a row and column number that are within the bounds and nor full. Enter row (1,2,3): "
                                << endl;
                        cin >> row;
                        cout << "Please enter column (1,2,3): " << endl;
                        cin >> col;
                    }
                    game.placeMark(row - 1, col - 1);
                    game.printBoard();
                    game.changePlayer();
                    switchPlayer--;
                    if (game.isBoardFull()) {
                        break;
                    }
                    if (game.checkForWin()) {
                        break;
                    }
                }
            }

            // prints the winner and asks if the user wants to play again
            if (game.checkForWin()) {
                game.changePlayer(); //since we switch players at the end of the while loop, we must switch back for the winner
                cout << "Congrats Player " << game.getCurrentPlayerNumber() << "! You won!" << endl;
                game.printBoard();
                cout << "Would you like to play again? ('y' for yes and 'n' for no)" << endl;
                cin >> rePlay;
            }
                //prints that there was a tie and asks if the user wants to play again
            else if (game.isBoardFull()) {
                cout << "The game was a tie! Would you like to play again? ('y' for yes and 'n' for no)" << endl;
                cin >> rePlay;
            }
        }
    }

    cout<< "Thank you for playing Tic Tac Toe! Come again soon!"<<endl;

    return 0;
}
