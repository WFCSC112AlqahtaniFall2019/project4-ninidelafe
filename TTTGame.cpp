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
    cout<<"Welcome to the Tic Tack Toe Game!"<<endl;


    cout<<"Would you like to play a 1 or 2 person game?"<<endl;
    cin>>numPlayers;

   //if the user choose to play against a computer this will run
    if (numPlayers==1) {
        //while loop that allows the user to play again if they choose to; asked at the end of their game
        while (rePlay != 'n') {
            game.initializeBoard(); //clears board
            cout<<"You will be playing against the computer.";
            cout << "This is your game board: " << endl;
            game.printBoard();//prints board
               //takes the player 1's inputs and creates a random generated number until there is a winner
                while (!game.checkForWin()) {
                    cout << "Player 1: you are 'x'" << endl;
                    cout << "Please pick a row (1, 2, 3):" << endl;
                    cin >> row;
                    cout << "Please pick a column (1, 2, 3):" << endl;
                    cin >> col;
                    //checks to make sure the input is within the bounds and the box is not full if it is asks for another number
                    while (!game.placeMark(row - 1, col - 1)) {
                        cout<< "Please pick a row and column number that are within the bounds and not full. Enter row (1,2,3): "<< endl;
                        cin >> row;
                        cout << "Please enter column (1,2,3): " << endl;
                        cin >> col;
                    }
                    game.placeMark(row - 1, col - 1);
                    game.changePlayer();
                    if (game.checkForWin()) {
                        break;
                    }
                    if (game.isBoardFull()) {
                        break;
                    }
                    //Computer inputs (randomly generated)
                    row=rand()%3+1;
                    col=rand()%3+1;
                    //checks to make sure the input is within the bounds and the box is not full if it is creates a new one
                    while (!game.placeMark(row - 1, col - 1)) {
                        row=rand()%3+1;
                        col=rand()%3+1;
                    }
                    game.placeMark(row - 1, col - 1);
                    game.printBoard();
                    game.changePlayer();
                    if (game.isBoardFull()) {
                        break;
                    }
                    if (game.checkForWin()) {
                        break;
                    }
            }
            // prints the winner and asks if the user wants to play again
            if (game.checkForWin()) {
                game.changePlayer();//switches player to winner because it is changed at the end of the while loop
                if (game.getCurrentPlayerNumber()==1) {
                    cout << "Congrats Player " << game.getCurrentPlayerNumber() << "! You won!" << endl;
                    cout << "Would you like to play again? ('y' for yes and 'n' for no)" << endl;
                    cin >> rePlay;
                }
                else{
                    cout<< "The computer beat you! Would you like to play again? ('y' for yes and 'n' for no)"<<endl;
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
                cout << "Player 1: you are 'x'" << endl;
                cout << "Please pick a row (1, 2, 3):" << endl;
                cin >> row;
                cout << "Please pick a column (1, 2, 3):" << endl;
                cin >> col;
                //checks to make sure the input is within the bounds and the box is not full if it is asks for another number
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
                if (game.checkForWin()) {
                    break;
                }
                if (game.isBoardFull()) {
                    break;
                }
                // asks for player #2's inputs
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
                if (game.isBoardFull()) {
                    break;
                }
                if (game.checkForWin()) {
                    break;
                }
            }
            // prints the winner and asks if the user wants to play again
            if (game.checkForWin()) {
                game.changePlayer(); //since we switch players at the end of the while loop, we must switch back for the winner
                cout << "Congrats Player " << game.getCurrentPlayerNumber() << "! You won!" << endl;
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
