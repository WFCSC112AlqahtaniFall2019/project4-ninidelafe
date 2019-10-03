/* Class: TicTacToe
 * Author: Alexa (Nini) de la Fe
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {

    cout<<"Welcome to the Tic Tack Toe Game!"<<endl;
    cout<<"Would you like to play a 1 or 2 person game?"<<endl;
    int numPlayers;
    cin>>numPlayers;

    TicTacToe game;

    game.initializeBoard();
    bool winner=false;

    if (numPlayers==1){


    }
    else if (numPlayers==2){
        while(!game.checkForWin()) {
            


            }
        }

    // FINISH ME

    return 0;
}