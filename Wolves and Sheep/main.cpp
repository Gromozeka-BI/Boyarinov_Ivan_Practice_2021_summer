#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
//#include <system>

using namespace std;

int board[8][8];
int mStep[5];
int sheep[2];

void clearBoard(int board[8][8]){
   for(int j = 7; j > -1; j--){
        for(int i = 0; i < 8; i++){
                board[i][j] = 0;
        }
    }
}

void outputBoardTest(int board[8][8]){
   cout << endl;
    for(int j = 7; j > -1; j--){
        for(int i = 0; i < 8; i++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void outputChessBoard(int board[8][8]){
   //cout << endl;
   cout << "___________________________________" << endl;


    for(int j = 7; j > -1; j--){
        cout << "|";
        for(int i = 0; i < 8; i++){

                if (board[i][j] == 1){
                    cout << " " << "O" << " ";
                }
                if (board[i][j] == 2){
                    cout << " " << "B" << " ";
                }
                if (board[i][j] == 0){
                    cout << "   ";
                }
                cout << "|";
        }

    cout << " " << j + 1 <<endl;
    cout << "|___|___|___|___|___|___|___|___|__";
    cout << endl;
    }
    cout << "  a   b   c   d   e   f   g   h";
    cout << endl;
}

void inputStart(int Ostart){
    if(Ostart == 1){
        board[1][7] = 1;
        sheep[0] = 1;
        sheep[1] = 7;
    }
    if(Ostart == 2){
        board[3][7] = 1;
        sheep[0] = 3;
        sheep[1] = 7;
    }
    if(Ostart == 3){
        board[5][7] = 1;
        sheep[0] = 5;
        sheep[1] = 7;
    }
    if(Ostart == 4){
        board[7][7] = 1;
        sheep[0] = 7;
        sheep[1] = 7;
    }
    for(int i = 0; i < 8; i += 2){
        board[i][0] = 2;
    }

}

int locate(){

    int start = -1;
    char input[3];

    char symbol = getchar();
    int number = 0;
    while(symbol != '\n'){
        for(int i = 0; i < 3; i++){
            if (number == i){
                input[i] = symbol;
            }

        }
        number++;
        symbol = getchar();
    }

    if((input[0] == 'b') && (input[1] == '8')  && (number == 2)){
       start = 1;
    }
    if((input[0] == 'd') && (input[1] == '8')  && (number == 2)){
       start = 2;
    }
    if((input[0] == 'f') && (input[1] == '8')  && (number == 2)){
       start = 3;
    }
    if((input[0] == 'h') && (input[1] == '8')  && (number == 2)){
       start = 4;
    }

	return start;
}

int numb(char number){
    int output = -1;
    if((number >= '1') && (number <= '8')){
        output = number - '1';
    }
    return output;
}

int let(char letter){
    int output = -1;
    if((letter >= 'a') && (letter <= 'h')){
        output = letter - 'a';
    }
    return output;
}

void step(int animal){

    for (int i = 0; i < 5; i++){
        mStep[i] = -1;
    }

    char input[6];//количество введёных символов

    char symbol = getchar();
    int number = 0;
    while(symbol != '\n'){
        for(int i = 0; i < 6; i++){
            if (number == i){
                input[i] = symbol;
            }

        }
        number++;
        symbol = getchar();
    }

    if((input[0] == 'O') && (animal == 1) && (input[3] == '-')){//проверка для овцы
        mStep[0] = animal;
        mStep[1] = let(input[1]);
        mStep[2] = numb(input[2]);
        mStep[3] = let(input[4]);
        mStep[4] = numb(input[5]);
    }
    if((input[0] == 'B') && (animal == 2) && (input[3] == '-')){//проверка для волка
        mStep[0] = animal;
        mStep[1] = let(input[1]);
        mStep[2] = numb(input[2]);
        mStep[3] = let(input[4]);
        mStep[4] = numb(input[5]);
    }

    int erorr = 0;
    for (int i = 0; i < 5; i++){
        if (mStep[i] == -1){
            erorr = -1;
        }
    }
    if (erorr != 0){
        for (int i = 0; i < 5; i++){
        mStep[i] = -1;
        }
    }

}

void outputStepTest(){
    for (int i = 0; i < 5; i++){
        cout << mStep[i] << " ";
    }
    cout << endl;
}

int whoWin(){
    if (sheep[0] == 0){//если находится слева и зажата, то проигрышь
            if (board[sheep[0] + 1][sheep[1] - 1] == 2){
                return 2;
            }
        }
        if (sheep[0] == 7){//если находится справа и зажата, то проигрышь
            if (board[sheep[0] - 1][sheep[1] - 1] == 2){
                return 2;
            }
        }

        if ((board[sheep[0] + 1][sheep[1] - 1] == 2) && (board[sheep[0] - 1][sheep[1] - 1] == 2)){// если зажата по бокам
            return 2;
        }


        for (int i = 0; i < 8; i++){// если овца дошла до конца, то она победила
            if (board[i][0] == 1){
                return 1;
            }
        }
    return 0;
}

int PVP(){


    int winner = -1;
    bool stop = true;
    int shOrWolf = 0;//счетчик ходов


    while (stop){
        system ("cls");
        outputChessBoard(board);
        if (shOrWolf % 2 == 0){//ход Овцы
            cout << "Sheep move:" << endl;
            bool correct = false;
            step(1);
            while (!correct){
                if (mStep[0] != -1){
                    if((board[mStep[1]][mStep[2]] == 1) && (board[mStep[3]][mStep[4]] == 0) && ((mStep[2] == mStep[4] + 1) || (mStep[2] == mStep[4] - 1)) && ((mStep[1] == mStep[3] - 1) || (mStep[1] == mStep[3] + 1))){
                        board[mStep[1]][mStep[2]] = 0;
                        board[mStep[3]][mStep[4]] = 1;
                        sheep[0] = mStep[3];
                        sheep[1] = mStep[4];
                        correct = !correct;
                    }else{
                        step(1);
                    }
                }else{
                    step(1);
                }
            }
        }else{//ход волка
            cout << "Wolf move:" << endl;
            bool correct = false;
            step(2);
            while (!correct){
                if (mStep[0] != -1){
                    if((board[mStep[1]][mStep[2]] == 2) && (board[mStep[3]][mStep[4]] == 0) && (mStep[2] == mStep[4] - 1) && ((mStep[1] == mStep[3] - 1) || (mStep[1] == mStep[3] + 1))){
                        board[mStep[1]][mStep[2]] = 0;
                        board[mStep[3]][mStep[4]] = 2;
                        correct = !correct;
                    }else{
                        step(2);
                    }
                }else{
                    step(2);
                }
            }
        }


        winner = whoWin();// проверяем на победу и в случае чего выходим
        if ((winner == 1) || (winner == 2) || (winner == -1)){
            stop = !stop;
        }

        shOrWolf++;
    }


    return winner;
}

int main(){
    clearBoard(board);

    //Выбор клетки, с которой начинает ходить овца
    int OStart = -1;
    int inputError = 0;
    //OStart = 1; // b8
    //OStart = 2; // d8
    //OStart = 3; // f8
    //OStart = 4; // h8

    while(OStart == -1){
        if (inputError == 0){
            cout << "Enter the value at which the sheep begins to walk" << endl;
            cout << "Possible starting cells: 'b8', 'd8', 'f8', 'h8'" << endl;
        }else{
            cout << "Do you missing the buttons?" << endl;
            cout << "Possible starting cells: 'b8', 'd8', 'f8', 'h8'" << endl;
        }
        OStart = locate();
        inputError++;
    }
    inputError = 0;
    inputStart(OStart);

    /*
    board[0][6] = 1;
    board[1][5] = 2;
    sheep[0] = 0;
    sheep[1] = 6;
    outputBoardTest(board);
    outputChessBoard(board);
    */


    int endd = PVP();

    if (endd == 1){
        system ("cls");
        outputChessBoard(board);
        cout << "Sheep winner" << endl;
    }
    if (endd == 2){
        system ("cls");
        outputChessBoard(board);
        cout << "Wolfs winner" << endl;
    }
    if (endd == -1){
        system ("cls");
        outputChessBoard(board);
        cout << "Erorr" << endl;
    }

    step(1);// ход овцы
    outputStepTest();

    //step(2);// ход волка
    //outputStepTest();


    return 0;
}
