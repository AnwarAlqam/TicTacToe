#include <iostream> // For basic cpp stuff
#include <string> // For string and to_string
#include <cctype> // isdigit

using namespace std;

struct positionInfo 
{
    string player;
    int place;
    bool taken = false;
};

// Draw the board
void drawBoard(positionInfo* spot) {

    system("CLS");

    cout << "/////////////////////////////" << endl << endl;
    cout << "         TIC TAC TOE" << endl;
    cout << "        BY ANWAR ALQAM" << endl << endl;
    cout << "/////////////////////////////" << endl;
    cout << endl;

    cout << "       " << " " << spot[0].player << " | " << spot[1].player << " | " << spot[2].player << endl;
    cout << "       " << "-----------" << endl;
    cout << "       " << " " << spot[3].player << " | " << spot[4].player << " | " << spot[5].player << endl;
    cout << "       " << "-----------" << endl;
    cout << "       " << " " << spot[6].player << " | " << spot[7].player << " | " << spot[8].player << endl;
    cout << endl;

    return;
}


void fillBoard(positionInfo* spot) {

    int counter = 1;
    for (int i = 0; i < 9; i++) {
        spot[i].player = to_string(counter);
        counter++;
    }

}


// Check if there was a winner
bool winnerCheck(positionInfo* spot) {

    // Check for horizontal wins
    if ((spot[0].player == spot[1].player) && (spot[0].player == spot[2].player)) {
        cout << "Winner Winner Chicken Dinner. Player " << spot[0].player << " has won!!" << endl;
        return true;
    }  else if ((spot[3].player == spot[4].player) && (spot[3].player == spot[5].player)) {
        cout << "Winner Winner Chicken Dinner. Player " << spot[3].player << " has won!!" << endl;
        return true;
    } else if ((spot[6].player == spot[7].player) && (spot[6].player == spot[8].player)) {
        cout << "Winner Winner Chicken Dinner. Player " << spot[6].player << " has won!!" << endl;
        return true;
    }

    // Check for vertical wins
    else if ((spot[0].player ==  spot[3].player) && (spot[0].player ==  spot[6].player)) {
        cout << "Winner Winner Chicken Dinner. Player " << spot[0].player << " has won!!" << endl;
        return true;
    } else if ((spot[1].player ==  spot[4].player) && (spot[1].player ==  spot[7].player)) {
        cout << "Winner Winner Chicken Dinner. Player " << spot[1].player << " has won!!" << endl;
        return true;
    } else if ((spot[2].player ==  spot[5].player) && (spot[2].player ==  spot[8].player)){
        cout << "Winner Winner Chicken Dinner. Player " << spot[2].player << " has won!!" << endl;
        return true;
    }
    
    // Check for diagonal wins
    else if ((spot[0].player == spot[4].player) && (spot[0].player == spot[8].player)) {
        cout << "Winner Winner Chicken Dinner. Player " << spot[0].player << " has won!!" << endl;
        return true;
    } else if ((spot[2].player == spot[4].player) && (spot[2].player == spot[6].player)) {
        cout << "Winner Winner Chicken Dinner. Player " << spot[2].player << " has won!!" << endl;
        return true;
    }

    return false;
}

bool doesItContainOnlyNumbers(string string) {
    for (int i = 0; i < string.length(); i++) {
        if (isalpha(string[i])) {
            return false;
        }
    }
    return true;
}

int main () {

    positionInfo spot[9];
    
    fillBoard(spot);
    drawBoard(spot);

    int move = 0;
    string place;
    int placeInt = 0;
    while (true) {

        cout << "Player X, choose your spot" << endl;
        cin >> place;

        // Making sure it that the user input only has numbers
        if (doesItContainOnlyNumbers(place)) {
            placeInt = stoi(place);
        } else {
            while (true) {
                cout << "Please do not input letters, only numbers between 1-9 are accepted. Please try again..." << endl;
                cin >> place;

                if (doesItContainOnlyNumbers(place)) {
                    placeInt = stoi(place);
                    break;
                }
            }
        }


        // Making sure that the user input is between the numbers 1-9
        if (placeInt < 0 || placeInt > 9) {
            while (true) {
                cout << "Please enter a number between 1-9" << endl;
                cin >> place;

            // Making sure it that the user input only has numbers
            if (doesItContainOnlyNumbers(place)) {
                placeInt = stoi(place);
            } else {
                while (true) {
                    cout << "Please do not input letters, only numbers between 1-9 are accepted. Please try again..." << endl;
                    cin >> place;

                    if (doesItContainOnlyNumbers(place)) {
                        placeInt = stoi(place);
                        break;
                    }
                }
            }

                if (placeInt >= 0 && placeInt <= 9) {
                    break;
                }
            }
        }

        // Check if the spot is taken or not
        if (!spot[placeInt - 1].taken) {
            spot[placeInt - 1].player = "X";
            spot[placeInt - 1].taken = true;
            move++;
        } else {

            while (spot[placeInt - 1].taken) {
                cout << "That current spot is already being taken by " << spot[placeInt - 1].player << ". Please select another one..." << endl;
                cin >> place;

                // Making sure it that the user input only has numbers
                if (doesItContainOnlyNumbers(place)) {
                    placeInt = stoi(place);
                } else {
                    while (true) {
                        cout << "Please do not input letters, only numbers between 1-9 are accepted. Please try again..." << endl;
                        cin >> place;

                        if (doesItContainOnlyNumbers(place)) {
                            placeInt = stoi(place);
                            break;
                        }
                    }
                }

                if (spot[placeInt - 1].taken == false) {
                    spot[placeInt - 1].player = "X";
                    spot[placeInt - 1].taken = true;
                    move++;
                    break;
                }
            }
        }

        // Lets draw the current board.
        drawBoard(spot);

        // Check if there is a winner yet or not
        if (winnerCheck(spot)) {
            break;
        }

        // Check for tie
        if (move == 9) {
            cout << "TIE!!" << endl;
            break;
        } 

        cout << "Player O, choose your spot" << endl;
        cin >> place;

        // Making sure it that the user input only has numbers
        if (doesItContainOnlyNumbers(place)) {
            placeInt = stoi(place);
        } else {
            while (true) {
                cout << "Please do not input letters, only numbers between 1-9 are accepted. Please try again..." << endl;
                cin >> place;

                if (doesItContainOnlyNumbers(place)) {
                    placeInt = stoi(place);
                    break;
                }
            }
        }

        // Making sure that the user input is between the numbers 1-9
        if (placeInt < 0 || placeInt > 9) {
            while (true) {
                cout << "Please enter a number between 1-9" << endl;
                cin >> place;

            // Making sure it that the user input only has numbers
            if (doesItContainOnlyNumbers(place)) {
                placeInt = stoi(place);
            } else {
                while (true) {
                    cout << "Please do not input letters, only numbers between 1-9 are accepted. Please try again..." << endl;
                    cin >> place;

                    if (doesItContainOnlyNumbers(place)) {
                        placeInt = stoi(place);
                        break;
                    }
                }
            }

                if (placeInt >= 0 && placeInt <= 9) {
                    break;
                }
            }
        }

        // Check if the spot is taken or not
        if (!spot[placeInt - 1].taken) {
            spot[placeInt - 1].player = "O";
            spot[placeInt - 1].taken = true;
            move++;
        } else {

            while (spot[placeInt - 1].taken) {
                cout << "That current spot is already being taken by " << spot[placeInt - 1].player << ". Please select another one..." << endl;
                cin >> place;

                // Making sure it that the user input only has numbers
                if (doesItContainOnlyNumbers(place)) {
                    placeInt = stoi(place);
                } else {
                    while (true) {
                        cout << "Please do not input letters, only numbers between 1-9 are accepted. Please try again..." << endl;
                        cin >> place;

                        if (doesItContainOnlyNumbers(place)) {
                            placeInt = stoi(place);
                            break;
                        }
                    }
                }

                if (spot[placeInt - 1].taken == false) {
                    spot[placeInt - 1].player = "O";
                    spot[placeInt - 1].taken = true;
                    move++;
                    break;
                }
            }
        }

        // Lets draw the current board
        drawBoard(spot);

        // Check if there is a winner yet or not
        if (winnerCheck(spot)) {
            break;
        }

        // Check for tie
        if (move == 9) {
            cout << "TIE!!" << endl;
            break;
        } 

    }
   
    cout << "Thank you for playing." << endl;
    system("pause");

    return 0;
}