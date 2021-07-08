#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <windows.h>
#include <cstdlib>
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

    cout << " " << j + 1;

    if (j == 7) {
        cout<< "\t\t\t" << "����� � ����";
    }
    if (j == 6) {
        cout<< "\t" << "������� ����:";
    }
    if (j == 5) {
        cout<< "\t" << "2)����� ����� �� ���� 1 ������ �� ���������, �� ������ �����";
    }
    if (j == 4) {
        cout<< "\t" << "4)����� ��������, ����� ���� �� ����� ������ ������";
    }
    if (j == 3) {
        cout<< "\t" << "���� ��� ������ �������";
    }

    if (j == 2) {
        cout<< "\t" << "������ ���� ������ ������� ��� � ����� '-' ���� �� ������ �������";
    }

    if (j == 1) {
        cout<< "\t\t\t " << "������ �����:";
    }
    if (j == 0) {
        cout<< "\t" << "Ob8-c7                               Bh1-g2  ";
    }

    cout << endl;
    cout << "|___|___|___|___|___|___|___|___|__";


    if (j == 6) {
        cout<< "\t" << "1)���� ����� ������ �� 1 ������ �� ���������";
    }
    if (j == 5) {
        cout<< "\t" << "3)���� ���������, ����� ������� �� 1 �����";
    }
    if (j == 4) {
        cout<< "\t" << "5)����� ������� ��� �� ����, ���������� ������ ������,";
    }

    if (j == 3) {
        cout<< "\t" << "6)����� ������� ��� �� �����, ���������� ������ ������,";
    }
    if (j == 1) {
        cout<< "\t" << "����� ����:                          ����� ����:  ";
    }

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

    //cout << "O";



    char input[6];//���������� ������� ��������

    if (animal == 1){
        cout << 'O';
        cout << (char)(sheep[0] + 'a');
        cout << (char)(sheep[1] + '1');
        cout << '-';
        char symbol = getchar();

        int number = 4;
        while(symbol != '\n'){
            for(int i = 4; i < 6; i++){
                if (number == i){
                    input[i] = symbol;
                }

            }
            number++;
            symbol = getchar();
        }
        input[0] = 'O';
        input[1] = (char)(sheep[0] + 'a');
        input[2] = (char)(sheep[1] + '1');
        input[3] = '-';
    }

    if (animal == 2){
        cout << 'B';
        char symbol = getchar();

        int number = 1;
        while(symbol != '\n'){
            for(int i = 1; i < 6; i++){
                if (number == i){
                    input[i] = symbol;
                }

            }
            number++;
            symbol = getchar();
        }
        input[0] = 'B';
    }

    //cout << input[0] << input[1] << input[2] << input[3] << input[4] << input[5] <<endl;

    if((input[0] == 'O') && (animal == 1) && (input[3] == '-')){//�������� ��� ����
        mStep[0] = animal;
        mStep[1] = let(input[1]);
        mStep[2] = numb(input[2]);
        mStep[3] = let(input[4]);
        mStep[4] = numb(input[5]);
    }
    if((input[0] == 'B') && (animal == 2) && (input[3] == '-')){//�������� ��� �����
        mStep[0] = animal;
        mStep[1] = let(input[1]);
        mStep[2] = numb(input[2]);
        mStep[3] = let(input[4]);
        mStep[4] = numb(input[5]);
    }

    //cout << mStep[0] << mStep[1] << mStep[2] << mStep[3] << mStep[4] <<endl;

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
    //cout << erorr << endl;

}

void outputStepTest(){
    for (int i = 0; i < 5; i++){
        cout << mStep[i] << " ";
    }
    cout << endl;
}

int whoWin(){

    for (int i = 0; i < 8; i++){// ���� ���� ����� �� �����, �� ��� ��������
            if (board[i][0] == 1){
                //cout << "win1";
                return 1;
            }
        }

    if (sheep[1] < 7){
        if (sheep[0] == 0){//���� ��������� ����� (�� �� 8 ������) � ������, �� ���������
            if ((board[sheep[0] + 1][sheep[1] - 1] == 2) && (board[sheep[0] + 1][sheep[1] + 1] == 2)){
                //cout << "win2";
                return 2;
            }
        }
    }else{
        if (sheep[0] == 0){//���� ��������� ����� (�� 8 ������) � ������, �� ���������
            if (board[sheep[0] + 1][sheep[1] - 1] == 2){
                //cout << "win3";
                return 2;
            }
        }
    }

    if (sheep[1] < 7){
        if (sheep[0] == 7){//���� ��������� ������ (�� �� 8 ������) � ������, �� ���������
            if ((board[sheep[0] - 1][sheep[1] - 1] == 2) && (board[sheep[0] - 1][sheep[1] + 1] == 2)){
                //cout << "win4";
                return 2;
            }
        }
    }else{
        if (sheep[0] == 7){//���� ��������� ������ (�� 8 ������) � ������, �� ���������
            if (board[sheep[0] - 1][sheep[1] - 1] == 2){
                //cout << "win5";
                return 2;
            }
        }
    }

    if (sheep[1] < 7){
        if ((board[sheep[0] + 1][sheep[1] - 1] == 2) && (board[sheep[0] - 1][sheep[1] - 1] == 2) && (board[sheep[0] + 1][sheep[1] + 1] == 2) && (board[sheep[0] - 1][sheep[1] + 1] == 2)){// ���� ������ �� ����� �� 8 �����
            //cout << "win6";
            return 2;
        }
    }else{
        if ((board[sheep[0] + 1][sheep[1] - 1] == 2) && (board[sheep[0] - 1][sheep[1] - 1] == 2)){// ���� ������ �� ����� �� 8 �����
            //cout << "win7";
            return 2;
        }
    }
    return 0;
}

int PVP(int shOrWolf){


    int winner = -1;
    bool stop = true;
    //shOrWolf = 0;//������� �����


    while (stop){
        system ("cls");
        outputChessBoard(board);
        if (shOrWolf % 2 == 0){//��� ����
            cout << "����� ����:" << endl;
            bool correct = false;
            step(1);
            int inputError = 0;
            while (!correct){
                if (mStep[0] != -1){
                    if((board[mStep[1]][mStep[2]] == 1) && (board[mStep[3]][mStep[4]] == 0) && ((mStep[2] == mStep[4] + 1) || (mStep[2] == mStep[4] - 1)) && ((mStep[1] == mStep[3] - 1) || (mStep[1] == mStep[3] + 1))){
                        board[mStep[1]][mStep[2]] = 0;
                        board[mStep[3]][mStep[4]] = 1;
                        sheep[0] = mStep[3];
                        sheep[1] = mStep[4];
                        correct = !correct;
                    }else{
                        inputError++;
                        system ("cls");
                        outputChessBoard(board);
                        cout << "������� ������������� �����: " << inputError << endl;
                        cout << "��������� ����" << endl;
                        cout << "����� ����:" << endl;
                        step(1);
                        //cout << "erorr1" << endl;
                    }
                }else{
                    //cout << "erorr2" << endl;
                        inputError++;
                        system ("cls");
                        outputChessBoard(board);
                        cout << "������� ������������� �����: " << inputError << endl;
                        cout << "��������� ����" << endl;
                        cout << "����� ����:" << endl;
                        step(1);
                }
            }
        }else{//��� �����
            cout << "����� ����:" << endl;
            bool correct = false;
            step(2);
            int inputError = 0;
            while (!correct){
                if (mStep[0] != -1){
                    if((board[mStep[1]][mStep[2]] == 2) && (board[mStep[3]][mStep[4]] == 0) && (mStep[2] == mStep[4] - 1) && ((mStep[1] == mStep[3] - 1) || (mStep[1] == mStep[3] + 1))){
                        board[mStep[1]][mStep[2]] = 0;
                        board[mStep[3]][mStep[4]] = 2;
                        correct = !correct;
                    }else{
                        inputError++;
                        system ("cls");
                        outputChessBoard(board);
                        cout << "������� ������������� �����: " << inputError << endl;
                        cout << "��������� ����" << endl;
                        cout << "����� ����:" << endl;
                        step(2);
                    }
                }else{
                    inputError++;
                    system ("cls");
                    outputChessBoard(board);
                    cout << "������� ������������� �����: " << inputError << endl;
                    cout << "��������� ����" << endl;
                    cout << "����� ����:" << endl;
                    step(2);
                }
            }
        }


        winner = whoWin();// ��������� �� ������ � � ������ ���� �������
        if ((winner == 1) || (winner == 2) || (winner == -1)){
            stop = !stop;
        }

        shOrWolf++;
    }


    return winner;
}

bool repeat(){
    int inputError = 0;
    bool erorr = true;
        while(erorr){
            //system ("cls");
            if (inputError == 0){
                cout << "����� ������ ���� ������ �������: '1'" << endl;
                cout << "����� ������� ���� �������: '0'" << endl;
            }else{
                system ("cls");
                cout << "������� ������������� �����: " << inputError << endl;
                cout << "��������� �������" << endl;
                cout << "����� ������ ���� ������ �������: '1'" << endl;
                cout << "����� ������� ���� �������: '0'" << endl;
            }

            char input[1];
            char symbol = getchar();
            int number = 0;
            while(symbol != '\n'){
                for(int i = 0; i < 1; i++){
                    if (number == i){
                        input[i] = symbol;
                    }

                }
                number++;
                symbol = getchar();
            }
            if (input[0] == '0'){
                system ("cls");
                return false;
            }
            if (input[0] == '1'){
                system ("cls");
                return true;
            }

            inputError++;
        }
}

int main(){
    bool rep = true;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    //rep = repeat();

    while (rep){
        clearBoard(board);

        //����� ������, � ������� �������� ������ ����
        int OStart = -1;
        int inputError = 0;
        //OStart = 1; // b8
        //OStart = 2; // d8
        //OStart = 3; // f8
        //OStart = 4; // h8


        ///*
        while(OStart == -1){
            if (inputError == 0){
                system ("cls");
                cout<< "����� � ����"<< endl;
                cout << endl;
                cout << "������� ������, � ������� ���� ������ ������" << endl;
                cout << "��������� ��������: 'b8', 'd8', 'f8', 'h8'" << endl;
            }else{
                system ("cls");
                cout << "������� ������������� �����: " << inputError << endl;
                cout << "��������� �������" << endl;
                cout << "������� ������, � ������� ���� ������ ������" << endl;
                cout << "��������� ��������: 'b8', 'd8', 'f8', 'h8'" << endl;
            }
            OStart = locate();
            inputError++;
        }

        inputError = 0;
        inputStart(OStart);
        //*/


           /*
        board[0][6] = 1;
        board[1][5] = 2;
        board[2][6] = 2;
        sheep[0] = 0;
        sheep[1] = 6;
        //outputBoardTest(board);
        //outputChessBoard(board);
        */


        int endd = PVP(0);

        if (endd == 1){
            system ("cls");
            outputChessBoard(board);
            cout << "�������� ����" << endl;
            cout << endl;
            rep = repeat();
        }
        if (endd == 2){
            system ("cls");
            outputChessBoard(board);
            cout << "�������� �����" << endl;
            cout << endl;
            rep = repeat();
        }
        if (endd == -1){
            system ("cls");
            outputChessBoard(board);
            cout << "Erorr output" << endl;
            cout << endl;
            rep = repeat();
        }

        //step(1);// ��� ����
        //outputStepTest();

        //step(2);// ��� �����
        //outputStepTest();
    }



    return 0;
    exit(0);
}
