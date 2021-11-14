#include <iostream>

#include <string>

using namespace std;

void drow();
void turn();
void check_winner();
bool logic(int inp);

string numbers[9] = {
  "1",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9"
};
int input;
int num;
string player;
int counter = 0;
int start;
bool cont = true;

int main() {
    while (true) {
        cont = true;
        cout << "enter 1 to start , 0 to exit " << endl;
        cin >> start;
        if (start != 0) {
            while (cont) {


                drow();
                turn();
                cout << "chose number for player" << player << ": ";

                cin >> input;

                if (input > 0 && logic(input)) {
                    numbers[input - 1] = player;

                    check_winner();
                    if (cont == false) {

                        int reset = 0;
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 3; j++) {
                                numbers[reset] = to_string(reset + 1);
                                reset++;
                            }
                        }
                        counter = 0;
                        break;

                    }
                    counter++;
                    if (counter == 9) {
                        int reset = 0;
                        drow();
                        cont = false;
                        cout << "draw" << endl;;
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 3; j++) {
                                numbers[reset] = to_string(reset + 1);
                                reset++;
                            }
                        }

                        counter = 0;

                    }
                }
                else if (input < 1 || input > 10 || !logic(input)) {
                    cout << endl << "please enter a vaild number" << endl;
                }
            }
        }
        else if (start == 0) {
            cout << endl << "goodbye" << endl;;
            break;

        }

    }
}

void drow() {
    num = 0;
    for (int i = 0; i < 3; i++) { //y-axix loop
        for (int j = 0; j < 3; j++) {
            cout << "|| \t" << numbers[num] << "\t || \t";
            num++;
        }
        cout << endl;
        for (int y = 0; y < 3; y++) { // | loop
            cout << "|| \t" << "\t || \t";
        }
        cout << endl;

    }
}

void turn() {
    if (counter % 2 == 0) {
        player = "X";

    }
    else {
        player = "O";
    }

}

void check_winner() {
    if (numbers[1 - 1] == numbers[2 - 1] && numbers[2 - 1] == numbers[3 - 1] && counter != 9) {
        drow();
        cout << endl << "player " << player << " won" << endl << endl;
        cont = false;

    }
    if (numbers[4 - 1] == numbers[5 - 1] && numbers[5 - 1] == numbers[6 - 1] && counter != 9) {
        drow();
        cout << endl << "player " << player << " won" << endl << endl;
        cont = false;

    }
    if (numbers[7 - 1] == numbers[8 - 1] && numbers[8 - 1] == numbers[9 - 1] && counter != 9) {
        drow();
        cout << endl << "player " << player << " won" << endl << endl;
        cont = false;

    }
    if (numbers[1 - 1] == numbers[5 - 1] && numbers[5 - 1] == numbers[9 - 1] && counter != 9) {
        drow();
        cout << endl << "player " << player << " won" << endl << endl;
        cont = false;

    }
    if (numbers[3 - 1] == numbers[5 - 1] && numbers[5 - 1] == numbers[7 - 1] && counter != 9) {
        drow();
        cout << endl << "player " << player << " won" << endl << endl;
        cont = false;

    }
    if (numbers[1 - 1] == numbers[4 - 1] && numbers[4 - 1] == numbers[7 - 1] && counter != 9) {
        drow();
        cout << endl << "player " << player << " won" << endl << endl;
        cont = false;


    }
    if (numbers[2 - 1] == numbers[5 - 1] && numbers[5 - 1] == numbers[8 - 1] && counter != 9) {
        cout << endl << "player " << player << " won" << endl << endl;
        cont = false;
        drow();
    }
    if (numbers[3 - 1] == numbers[6 - 1] && numbers[6 - 1] == numbers[9 - 1] && counter != 9) {
        drow();
        cout << endl << "player " << player << " won" << endl << endl;
        cont = false;

    }

}
bool logic(int inp) {

    if (numbers[inp - 1] == "X" || numbers[inp - 1] == "O") {
        return false;
    }
    else return true;

}