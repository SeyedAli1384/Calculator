#include <iostream>
#include <unistd.h>
#include <string>
#include <ctime>
#include <windows.h>
#include <vector>
#include <iomanip>


using namespace std;

int counter = 0;
int highscore = 0;
int boardnum = 0;
vector<int> scores;
vector<string> name;

void showhistory() {
    system("cls");

    for (int i = 0; i < scores.size(); i++) {
        for (int j = i + 1; j < scores.size(); j++) {
            if (scores[i] < scores[j]) {

                int temp1 = scores[i];
                scores[i] = scores[j];
                scores[j] = temp1;

                string temp2 = name[i];
                name[i] = name[j];
                name[j] = temp2;
            }
        }
    }

    cout << "+----+------------------------+--------+" << endl;
    cout << "| No | Name                   | Score  |" << endl;
    cout << "+----+------------------------+--------+" << endl;

    for (int i = 0; i < scores.size(); i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(22) << left << name[i] << " | "
             << setw(6) << left << scores[i] << " |" << endl;
    }

    cout << "+----+------------------------+--------+" << endl;

    cout << "Press M To Return To Game";
}


int main(){
    class game{
    public :
        bool running = true;
        int board[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};


        int score = 0;
        bool win = false;
        bool loose = false;
        int textcolor = 7;
        int backgroundcolor = 0;
        bool checkbort = true;

        void setConsoleColor(int textColor, int backgroundColor) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int colorAttribute = (backgroundColor << 4) | textColor;
            SetConsoleTextAttribute(hConsole, colorAttribute);
        }

        void showboard(game obj) {
            if (boardnum == 0) {
                cout << "\n\n";
                cout << "                                            ┌─────┬─────┬─────┬─────┐" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << "                                            │";
                    for (int j = 0; j < 4; j++) {
                        if (obj.board[i][j] == 0)
                            cout << "     │";
                        else if (obj.board[i][j] < 10)
                            cout << "  " << obj.board[i][j] << "  │";
                        else if (obj.board[i][j] < 100)
                            cout << " " << obj.board[i][j] << "  │";
                        else if (obj.board[i][j] < 1000)
                            cout << " " << obj.board[i][j] << " │";
                        else
                            cout << obj.board[i][j] << "│";
                    }
                    if (i < 3)
                        cout << "\n                                            ├─────┼─────┼─────┼─────┤" << endl;
                }
                cout << "\n                                            └─────┴─────┴─────┴─────┘" << endl;
                cout << "\n\n";
            }
            else if (boardnum == 1) {
                cout << "\n\n";
                cout << "                                            ╔═════╦═════╦═════╦═════╗" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << "                                            ║";
                    for (int j = 0; j < 4; j++) {
                        if (obj.board[i][j] == 0)
                            cout << "     ║";
                        else if (obj.board[i][j] < 10)
                            cout << "  " << obj.board[i][j] << "  ║";
                        else if (obj.board[i][j] < 100)
                            cout << "  " << obj.board[i][j] << " ║";
                        else if (obj.board[i][j] < 1000)
                            cout << " " << obj.board[i][j] << " ║";
                        else
                            cout << obj.board[i][j] << "║";
                    }
                    if (i < 3)
                        cout << "\n                                            ╠═════╬═════╬═════╬═════╣" << endl;
                }
                cout << "\n                                            ╚═════╩═════╩═════╩═════╝" << endl;
                cout << "\n\n";
            }
            else if (boardnum == 2) {
                cout << "\n\n";
                cout << "                                            ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << "                                            ▓";
                    for (int j = 0; j < 4; j++) {
                        if (obj.board[i][j] == 0)
                            cout << "     ▓";
                        else if (obj.board[i][j] < 10)
                            cout << "  " << obj.board[i][j] << "  ▓";
                        else if (obj.board[i][j] < 100)
                            cout << "  " << obj.board[i][j] << " ▓";
                        else if (obj.board[i][j] < 1000)
                            cout << " " << obj.board[i][j] << " ▓";
                        else
                            cout << obj.board[i][j] << "▓";
                    }
                    if (i < 3)
                        cout << "\n                                            ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
                }
                cout << "\n                                            ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
                cout << "\n\n";
            }
        }
        void hello(game &obj){
            cout << "Welcome To 2048 : A CPP Console Game" << endl;
            sleep(3);
            cout << "Press (s/S) For Start And Press (e/E) For Exit : ";
            while(true){
                  char se;
                  cin >> se;
                  se = toupper(se);
                  if(se == 'S'){
                    system("cls");
                    string nam;
                    cout << "Please Enter Your Name : ";
                    cin >> nam;
                    name.push_back(nam);
                    system("cls");
                    cout << "The Game Start In : " << endl;
                    for(int i = 3; i>=1 ;i--){
                        sleep(1);
                        cout << i << endl;
                    }
                    sleep(1);
                    system("cls");
                    obj.random(obj);
                    obj.run(obj);
                  }
                  else if(se == 'E'){
                    cout << "Then ";
                    sleep(1);
                    cout << "Goodbye";
                    sleep(1);
                    system("cls");
                    obj.credit();
                    return;
                  }
                  else{
                     system("cls");
                     cout << "Wrong Input" << endl;
                     cout << "Press (s/S) For Start And Press (e/E) For Exit : ";
                  }
              }
        }
        void random(game &obj){
            bool checking = true;
            while(checking){
                int randx = rand() % 4;
                int randy = rand() % 4;
                int rand24 = rand() % 2;
                if(obj.board[randx][randy] == 0){
                    obj.board[randx][randy] = (rand24 == 0) ? 2 : 4;
                    checking = false;
                }
            }
        }

        bool check(game obj) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (obj.board[i][j] == 2048) {
                        win = true;
                        return false;
                    }
                }
            }
            bool checkmove = false;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (obj.board[i][j] == 0) {
                        checkmove = true;
                        break;
                    }
                    if (i < 3 && obj.board[i][j] == obj.board[i + 1][j]) {
                        checkmove = true;
                        break;
                    }
                    if (j < 3 && obj.board[i][j] == obj.board[i][j + 1]) {
                        checkmove = true;
                        break;
                    }
                }
                if (checkmove) break;
            }
                if (!checkmove) {
                    loose = true;
                    return false;
                }
                return true;
            }

        void run(game &obj){

            if(obj.check(obj)){

                bool randcheck = true;
                for(int i = 0;i<4;i++){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i][j] == 0){
                            obj.random(obj);
                            randcheck = false;
                            break;
                        }
                    }
                    if(not randcheck)
                        break;
                }
                score = 0;
                for(int i = 0;i<4;i++){
                    for(int j = 0;j<4;j++){
                        score += obj.board[i][j];
                    }
                }
                run:
                obj.setConsoleColor(obj.textcolor,obj.backgroundcolor);

                //Game Control
                system("cls");
                cout << "                              ┌────────────────────────────────────────────────────┐" << endl;
                cout << "                              │                  GAME CONTROLS                     │" << endl;
                cout << "                              ├────────────────────────────────────────────────────┤" << endl;
                cout << "                              │ Press w/W For Up    │ Press s/S For Down           │" << endl;
                cout << "                              │ Press a/A For Left  │ Press d/D For Right          │" << endl;
                cout << "                              │ Press c/C For Change Theme                         │" << endl;
                cout << "                              │ Press h/H For Show History                         │" << endl;
                cout << "                              │ Press r/R For Rset The Board                       │" << endl;
                cout << "                              ├────────────────────────────────────────────────────┤" << endl;
                cout << "                              │ Highest Score Is: " << setw(33) << left << highscore << "│" << endl;
                cout << "                              │ Your Score Is: " << setw(36)<< left << obj.score << "│" << endl;
                cout << "                              └────────────────────────────────────────────────────┘" << endl;


                showboard(obj);
                Sleep(300);
                bool check = true;
                char asdw;
                while(check){
                    if(GetKeyState('A') & 0x8000){
                        bool checkm = false;
                        for(int i = 0;i<4;i++){
                            for(int j = 1;j<4;j++){
                                if((obj.board[i][j] == obj.board[i][j - 1] and obj.board[i][j] != 0) or (obj.board[i][j] != 0 and obj.board[i][j - 1] == 0)){
                                    checkm = true;
                                    break;
                                }
                            }
                            if(checkm)
                                break;
                        }
                        if(checkm){
                            system("cls");
                            asdw = 'a';
                            check = false;
                        }

                    }
                    else if(GetKeyState('S') & 0x8000){
                        bool checkm = false;
                        for(int i =0;i<3;i++){
                            for(int j = 0;j<4;j++){
                                if((obj.board[i][j] == obj.board[i+1][j] and obj.board[i][j] != 0) or (obj.board[i][j] != 0 and obj.board[i+1][j] == 0)){
                                    checkm = true;
                                    break;
                                }
                            }
                            if(checkm)
                                break;
                        }
                        if(checkm){
                            system("cls");
                            asdw = 's';
                            check = false;
                        }

                    }
                    else if(GetKeyState('D') & 0x8000){
                        bool checkm = false;
                        for(int i = 0;i<4;i++){
                            for(int j = 0;j<3;j++){
                                if((obj.board[i][j] == obj.board[i][j + 1] and obj.board[i][j] != 0) or (obj.board[i][j] != 0 and obj.board[i][j + 1] == 0)){
                                    checkm = true;
                                    break;
                                }
                            }
                            if(checkm)
                                break;
                        }
                        if(checkm){
                            system("cls");
                            asdw = 'd';
                            check = false;
                        }

                    }
                    else if(GetKeyState('W') & 0x8000){
                        bool checkm = false;
                        for(int i = 1;i<4;i++){
                            for(int j = 0;j<4;j++){
                                if((obj.board[i][j] == obj.board[i - 1][j] and obj.board[i][j] != 0) or (obj.board[i][j] != 0 and obj.board[i - 1][j] == 0)){
                                    checkm = true;
                                    break;
                                }
                            }
                            if(checkm)
                                break;
                        }
                        if(checkm){
                            system("cls");
                            asdw = 'w';
                            check = false;
                        }

                    }
                    else if(GetKeyState('E') & 0x8000){
                        system("cls");
                        sleep(1);
                        system("C:\\Users\\asus\\Desktop\\GitHub\\Myworks\\Term1Project\\ExpertCalculator.exe");
                    }
                    else if(GetKeyState('H') & 0x8000){
                        showhistory();
                    }
                    else if(GetKeyState('L') & 0x8000){
                        system("cls");
                        cout << "Choose Your Board : " << endl;
                        cout << "1.(Press K)";
                        boardnum = 0;
                        showboard(obj);
                        cout << "2.(Press N)";
                        boardnum = 1;
                        showboard(obj);
                        cout << "3.(Press O)";
                        boardnum = 2;
                        showboard(obj);
                    }
                    else if(GetKeyState('K') & 0x8000){
                        boardnum = 0;
                        goto run;
                    }
                    else if(GetKeyState('N') & 0x8000){
                        boardnum = 1;
                        goto run;
                    }
                    else if(GetKeyState('O') & 0x8000){
                        boardnum = 2;
                        goto run;
                    }
                    else if(GetKeyState('B') & 0x8000){
                        obj.checkbort = true;
                        system("cls");
                        cout << "Select Your Text Color :" << endl << "0. Black" << endl << "1. Dark Blue" << endl << "2. Green";
                        cout << endl << "3. Aqua (Cyan)" << endl << "4. Red" << endl << "5. Purple" << endl << "6. Yellow";
                        cout << endl << "7. White" << endl << "8. Gray" << endl << "9. Light Blue" << endl << endl;
                        cout << "Press M To Return To Game    |    Press C To Return To Change Style";
                    }
                    else if(GetKeyState('T') & 0x8000){
                        obj.checkbort = false;
                        system("cls");
                        cout << "Select Your Text Color :" << endl << "0. Black" << endl << "1. Dark Blue" << endl << "2. Green";
                        cout << endl << "3. Aqua (Cyan)" << endl << "4. Red" << endl << "5. Purple" << endl << "6. Yellow";
                        cout << endl << "7. White" << endl << "8. Gray" << endl << "9. Light Blue" << endl << endl;
                        cout << "Press M To Return To Game    |    Press C To Return To Change Style";
                    }
                    else if(GetKeyState('C') & 0x8000){
                        system("cls");
                        cout << "What Do You Wanna Change?" << endl;
                        cout << "1.Board Style(Press L)" << endl << "2.Console BackGround Color(Press B)" << endl << "3.Console Text Color(Press T)";
                        cout << endl <<"Press M To Return To Game";
                    }
                    else if(GetKeyState('M') & 0x8000){
                            system("cls");
                            goto run;
                    }
                    else if(GetKeyState('R') & 0x8000){
                        for(int i = 0;i<4;i++){
                            for(int j = 0;j<4;j++){
                                obj.board[i][j] = 0;
                            }
                        }
                        obj.random(obj);
                        obj.random(obj);
                        goto run;
                    }
                    else if(GetKeyState('Z') & 0x8000){
                        if(obj.checkbort)
                            obj.checkbort = false;
                        else
                            obj.checkbort = true;
                    }
                    else if (GetKeyState('1') & 0x8000){
                        if (obj.checkbort) {
                            obj.backgroundcolor = 1;
                        } else {
                            obj.textcolor = 1;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('2') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 2;
                        } else {
                            obj.textcolor = 2;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('3') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 3;
                        } else {
                            obj.textcolor = 3;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('4') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 4;
                        } else {
                            obj.textcolor = 4;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('5') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 5;
                        } else {
                            obj.textcolor = 5;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('6') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 6;
                        } else {
                            obj.textcolor = 6;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('7') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 7;
                        } else {
                            obj.textcolor = 7;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('8') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 8;
                        } else {
                            obj.textcolor = 8;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('9') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 9;
                        } else {
                            obj.textcolor = 9;
                        }
                        system("cls");
                        goto run;
                    }
                    else if (GetKeyState('0') & 0x8000) {
                        if (obj.checkbort) {
                            obj.backgroundcolor = 0;
                        } else {
                            obj.textcolor = 0;
                        }
                        system("cls");
                        goto run;
                    }



                }
                switch(asdw){
                        case 'w': obj.up(obj);
                        break;
                        case 's': obj.down(obj);
                        break;
                        case 'a': obj.lefts(obj);
                        break;
                        case 'd': obj.right(obj);
                        break;
                }
            }
            else{
                if(score > highscore){
                    highscore = score;
                }
                scores.push_back(score);
                cout << "Waiting For Results...";
                showboard(obj);
                Sleep(4000);
                system("cls");
                if(win){
                    cout << "Guess What!!?" << endl;
                    sleep(1);
                    cout << "You Won!" << endl;
                    sleep(1);
                    cout << "Do You Wanna Play Again Champ(y/Y For Play Again, Anything Else For Quit)? " << endl;
                    cout << "Your Inputs Are (Delete And Enter Answer) : " ;
                    char yn;
                    cin >> yn;
                    if(tolower(yn) == 'y'){
                        system("cls");
                        main();
                    }
                    else{
                        cout << "Goodbye Champ!";
                        system("cls");
                        obj.credit();
                    }

                }
                else{
                    cout << "Game Over! You Lost!" << endl;
                    sleep(1);
                    cout << "Maybe Next Time" << endl;
                    sleep(1);
                    cout << "Do You Wanna Play Again Champ(y/Y For Play Again, Anything Else For Quit)? " << endl;
                    cout << "Your Inputs Are (Delete And Enter Answer) : " ;
                    char yn;
                    cin >> yn;
                    if(tolower(yn) == 'y'){
                        system("cls");
                        main();
                    }
                    else{
                        cout << "Goodbye";
                        system("cls");
                        obj.credit();
                    }
                }


            }
        }

        void right(game &obj){
                for(int i = 0;i<4;i++){
                    int j = 0;
                    if(obj.board[i][j + 1] == 0 and obj.board[i][j + 2] == 0 and obj.board[i][j + 3] == obj.board[i][j]){
                        obj.board[i][j + 3] *= 2;
                        obj.board[i][j] = 0;
                    }
                    else if(obj.board[i][j + 1] == 0 and obj.board[i][j + 2] == obj.board[i][j] and obj.board[i][j + 3] == 0){
                        obj.board[i][j + 3] = obj.board[i][j] * 2;
                        obj.board[i][j + 2] = 0;
                        obj.board[i][j] = 0;
                    }
                }
                for(int i = 0;i<4;i++){
                    for(int j = 2;j>=0;j--){
                        if(obj.board[i][j + 1] == 0){
                            obj.board[i][j + 1] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 0;i<4;i++){
                    for(int j = 2;j>=0;j--){
                        if(obj.board[i][j + 1] == obj.board[i][j]){
                            obj.board[i][j + 1] *= 2;
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 0;i<4;i++){
                    for(int j = 2;j>=0;j--){
                        if(obj.board[i][j + 1] == 0){
                            obj.board[i][j + 1] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 0;i<4;i++){
                    for(int j = 2;j>=0;j--){
                        if(obj.board[i][j + 1] == 0){
                            obj.board[i][j + 1] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }

            run(obj);
        }
        void lefts(game &obj){
                for(int i = 0;i<4;i++){
                    int j = 3;
                    if(obj.board[i][j - 1] == 0 and obj.board[i][j - 2] == 0 and obj.board[i][j - 3] == obj.board[i][j]){
                        obj.board[i][j - 3] *= 2;
                        obj.board[i][j] = 0;
                    }
                    else if(obj.board[i][j - 1] == 0 and obj.board[i][j - 2] == obj.board[i][j] and obj.board[i][j - 3] == 0){
                        obj.board[i][j - 3] = obj.board[i][j] * 2;
                        obj.board[i][j - 2] = 0;
                        obj.board[i][j] = 0;
                    }
                }
                for(int i = 0;i<4;i++){
                    for(int j = 1;j<4;j++){
                        if(obj.board[i][j - 1] == 0){
                            obj.board[i][j - 1] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 0;i<4;i++){
                    for(int j = 1;j<4;j++){
                        if(obj.board[i][j - 1] == obj.board[i][j]){
                            obj.board[i][j - 1] *= 2;
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 0;i<4;i++){
                    for(int j = 1;j<4;j++){
                        if(obj.board[i][j - 1] == 0){
                            obj.board[i][j - 1] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 0;i<4;i++){
                    for(int j = 1;j<4;j++){
                        if(obj.board[i][j - 1] == 0){
                            obj.board[i][j - 1] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
            run(obj);
        }
        void up(game &obj){
                for(int i = 0;i<4;i++){
                    int j = 3;
                    if(obj.board[j - 1][i] == 0 and obj.board[j - 2][i] == 0 and obj.board[j - 3][i] == obj.board[j][i]){
                        obj.board[j - 3][i] *= 2;
                        obj.board[j][i] = 0;
                    }
                    else if(obj.board[j - 1][i] == 0 and obj.board[j - 2][i] == obj.board[j][i] and obj.board[j - 3][i] == 0){
                        obj.board[j - 3][i] = obj.board[j - 2][i] * 2;
                        obj.board[j - 2][i] = 0;
                        obj.board[j][i] = 0;
                    }
                }
                for(int i = 1;i < 4;i++){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i - 1][j] == 0){
                            obj.board[i - 1][j] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 1;i < 4;i++){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i - 1][j] == obj.board[i][j]){
                            obj.board[i - 1][j] *= 2;
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 1;i < 4;i++){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i - 1][j] == 0){
                            obj.board[i - 1][j] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 1;i < 4;i++){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i - 1][j] == 0){
                            obj.board[i - 1][j] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
            run(obj);
        }
        void down(game &obj){
                for(int i = 0;i<4;i++){
                    int j = 0;
                    if(obj.board[j + 1][i] == 0 and obj.board[j + 2][i] == 0 and obj.board[j + 3][i] == obj.board[j][i]){
                        obj.board[j + 3][i] *= 2;
                        obj.board[j][i] = 0;
                    }
                    else if(obj.board[j + 1][i] == 0 and obj.board[j + 2][i] == obj.board[j][i] and obj.board[j + 3][i] == 0){
                        obj.board[j + 3][i] = obj.board[j + 2][i] * 2;
                        obj.board[j + 2][i] = 0;
                        obj.board[j][i] = 0;
                    }
                }
                for(int i = 2;i >= 0;i--){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i + 1][j] == 0){
                            obj.board[i + 1][j] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 2;i >= 0;i--){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i + 1][j] == obj.board[i][j]){
                            obj.board[i + 1][j] *= 2;
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 2;i >= 0;i--){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i + 1][j] == 0){
                            obj.board[i + 1][j] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
                for(int i = 2;i >= 0;i--){
                    for(int j = 0;j<4;j++){
                        if(obj.board[i + 1][j] == 0){
                            obj.board[i + 1][j] = obj.board[i][j];
                            obj.board[i][j] = 0;
                        }
                    }
                }
            run(obj);
        }
        void credit(){
            cout << "Developed By :" << endl << "         MohammadParsa Khorrammanesh" << endl << "         Seyed Ali Yasini" << endl << "         Alireza Shahriari";
            exit(0);


        }
};



      //main function
      game x2048;
      srand(time(0));
      if(counter == 0){
        counter ++;
        x2048.hello(x2048);
      }
      else{
        system("cls");
            string nam;
            cout << "Please Enter You Name : ";
            cin >> nam;
            name.push_back(nam);
            system("cls");
            cout << "The Game Start In : " << endl;
            for(int i = 3; i>=1 ;i--){
                sleep(1);
                cout << i << endl;
            }
            sleep(1);
            system("cls");
            x2048.random(x2048);
            x2048.run(x2048);
      }



}
