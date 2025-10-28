#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

#define PI  3.14159
#define e 2.71828

bool GuideCheck = false;
double Inf;
vector<string> history;
vector<long double> history1;
int textcolor = 7;
int backgroundcolor = 0;

void setConsoleColor(int textColor, int backgroundColor) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int colorAttribute = (backgroundColor << 4) | textColor;
        SetConsoleTextAttribute(hConsole, colorAttribute);
}
void SimpleGuide(){
    cout << "                              ";
    for (int i=0 ; i < 49 ; i++){
        if (i==0){
            cout << "┌";
            continue;
        }
        if (i==48){
            cout << "┐";
            continue;
        }
            cout << "─";
    }
    cout << endl;
    cout << "                              │ * * * * * * * * * * * * * * * * * * * * * * * │" << endl;
    cout << "                              │ *            (Expert  Calculator)           * │" << endl;
    cout << "                              │ *  For Showing History : 'History'          * │" << endl;
    cout << "                              │ *  For Showing Guide : 'SGuide'             * │" << endl;
    cout << "                              │ *  For Resetting calculator : 'Reset'       * │" << endl;
    cout << "                              ╞═══════════════════════════════════════════════╡" << endl;
    cout << "                              │ *               Developed By:               * │" << endl;
    cout << "                              │ *              Seyed Ali Yasini             * │" << endl;
    cout << "                              │ *        MohammadParsa Khorrammanesh        * │" << endl;
    cout << "                              │ *                                           * │" << endl;
    cout << "                              │ * * * * * * * * * * * * * * * * * * * * * * * │" << endl;
    cout << "                              ";
    for (int i=0 ; i < 49 ; i++){
        if (i==0){
            cout << "└";
            continue;
        }
        if (i==48){
            cout << "┘";
            continue;
        }
        cout << "─";
    }
    cout << endl << endl << endl;
}

void Guide(){
    cout << "                              ";
    for (int i=0 ; i < 49 ; i++){
        if (i==0){
            cout << "┌";
            continue;
        }
        if (i==48){
            cout << "┐";
            continue;
        }
            cout << "─";
    }  // ∂∑√∞∫⌠⌡ℓ½¾±
    cout << endl;
    cout << "                              │ * * * * * * * * * * * * * * * * * * * * * * * │" << endl;
    cout << "                              │ *             (Calculator Manual)           * │" << endl;
    cout << "                              │ *                                           * │" << endl;
    cout << "                              │ *   Power --> a^b (a power b)               * │" << endl;
    cout << "                              │ *  Rad√⎺ --> rad b(a) (b is index)          * │" << endl;
    cout << "                              │ *   log  --> log b(a) (b is base)           * │" << endl;
    cout << "                              │ *    n!  --> fac(a) (Factoriel)             * │" << endl;
    cout << "                              │ *   sin  --> sin (a) (radian or degree)     * │" << endl;
    cout << "                              │ *   cos  --> cos (a) (radian or degree)     * │" << endl;
    cout << "                              │ *   tan  --> tan (a) (radian or degree)     * │" << endl;
    cout << "                              │ *   cot  --> cot (a) (radian or degree)     * │" << endl;
    cout << "                              │ *    e   --> For Euler's number = 2.71828   * │" << endl;
    cout << "                              │ *    p   --> For The value of Pi (π=3.14)   * │" << endl;
    cout << "                              │ *    a(b)=a*(b) (a)(b)=(a)*(b) (a)b≠(a)*b   * │" << endl;
    cout << "                              │ *                                           * │" << endl;
    cout << "                              │ *  For Showing History : 'History'          * │" << endl;
    cout << "                              │ *                                           * │" << endl;
    cout << "                              │ *  For Changing Angle type:                 * │" << endl;
    cout << "                              │ *  For Degree : 'Degree'                    * │" << endl;
    cout << "                              │ *  For Radian : 'Radian'                    * │" << endl;
    cout << "                              │ *                                           * │" << endl;
    cout << "                              │ *  For Setting Percision: (default is 3)    * │" << endl;
    cout << "                              │ *  Type : 'Percision'                       * │" << endl;
    cout << "                              │ *                                           * │" << endl;
    cout << "                              │ *  For Changing Theme : 'CTheme'            * │" << endl;
    cout << "                              │ *  For Resetting history : 'ReHistory'      * │" << endl;
    cout << "                              │ *  For Showing Guide : 'SGuide'             * │" << endl;
    cout << "                              │ *  For Deleting Guide : 'DGuide'            * │" << endl;
    cout << "                              │ *  For Clear Inputs : 'Clear'               * │" << endl;
    cout << "                              │ *  For Resetting calculator : 'Reset'       * │" << endl;
    cout << "                              │ *                                           * │" << endl;
    cout << "                              │ * * * * * * * * * * * * * * * * * * * * * * * │" << endl;
    cout << "                              ";
    for (int i=0 ; i < 49 ; i++){
        if (i==0){
            cout << "└";
            continue;
        }
        if (i==48){
            cout << "┘";
            continue;
        }
        cout << "─";
    }
    cout << endl << endl << endl;

}

enum DorR {
    radian,
    degree
};

void Check(vector<string> &history){
        history.pop_back();
        cout << endl << "History Not Saved!" << endl;
}

long double Calculate (string str){
    // 1.^ 2*&/ 3.+&-
    for(int i=str.length()-1;i>=0;i--){
        if(str[i] == '^'){
            string base = "",exp = "";
            for(int j = i + 1;str[j] != '+' and str[j] != '*' and str[j] != '/' and str[j] != '^' and j < str.length();j++){
                exp += str[j];
                if(str[j+1] == '-')
                    break;
            }
            for(int j = i - 1;str[j] != '+' and str[j] != '*' and str[j] != '/' and str[j] != '^' and j >= 0;j--){
                base += str[j];
                if(str[j - 1] == '-' and isdigit(str[j-2]))
                    break;
            }
            reverse(base.begin(),base.end());
            str.replace(i - base.length(),base.length() + exp.length() + 1,to_string(pow(stod(base), stod(exp))));
        }
    }
    for(int i=0;i<str.length();i++){
        if(str[i] == '/' or str[i] == '*'){
            char op = str[i];
            string num1 = "",num2 = "";
            for(int j = i + 1;str[j] != '+' and str[j] != '*' and str[j] != '/' and j < str.length();j++){
                num2 += str[j];
                if(str[j+1] == '-')
                    break;
            }
            for(int j = i - 1;str[j] != '+' and str[j] != '*' and str[j] != '/' and j >= 0;j--){
                num1 += str[j];
                if(str[j - 1] == '-' and isdigit(str[j-2]))
                    break;
            }
            reverse(num1.begin(),num1.end());
            if(op == '/'){
                if (stod(num2)==0){
                    cout << endl << "Divided by Zero is Undefined , Please Try again!" << endl;
                    Check(history);
                    return 0;
                }
                str.replace(i - num1.length(),num1.length() + num2.length() + 1,to_string(stod(num1) / stod(num2)));
            }
            else{
                str.replace(i - num1.length(),num1.length() + num2.length() + 1,to_string(stod(num1) * stod(num2)));
            }
            i = 0;
        }
    }
    for(int i=str.length()-1;i>=0;i--){
        if(str[i] == '+'){
            string num1 = "",num2 = "";
            for(int j = i + 1;str[j] != '+' and j < str.length();j++){
                num2 += str[j];
                if(str[j+1] == '-')
                    break;
            }
            for(int j = i - 1;str[j] != '+' and j >= 0;j--){
                num1 += str[j];
                if(str[j - 1] == '-' and isdigit(str[j-2]))
                    break;
            }
            reverse(num1.begin(),num1.end());
            str.replace(i - num1.length(),num1.length() + num2.length() + 1,to_string(stod(num1) + stod(num2)));
        }
    }
    for(int i=str.length()-1;i>=1;i--){
        if(str[i] == '-'){
            string num1 = "",num2 = "";
            for(int j = i + 1;str[j] != '+' and j < str.length() ;j++){
                num2 += str[j];
                if(str[j+1] == '-')
                    break;
            }
            for(int j = i - 1;str[j] != '+' and j >= 0;j--){
            num1 += str[j];
                if(str[j - 1] == '-' and isdigit(str[j-2]))
                    break;
            }
            reverse(num1.begin(),num1.end());
            str.replace(i - num1.length(),num1.length() + num2.length() + 1,to_string(stod(num1) - stod(num2)));
        }
    }
    return stod(str);
}


void Paranteces(string &str){
    for (int i=str.length() - 1 ; i >= 0; i--){
        string Bin = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        int f = 0;
        int check2 = 0;
        if (str[i]=='('){
            for (int w=i+1 ;str[w]!= ')' ; w++){
                Bin[f] = str[w];
                f++;
                check2 = w + 1;
            }
        Bin = Bin.substr(0,f);
        str.replace(i , check2 - i + 1 , to_string(Calculate(Bin)));
        }
    }
}

void Factoriel(string &str){
    long int Num = stoi(str);
    long long int fact = 1;
    for (int i=1 ; i < Num+1 ; i++){
        fact *= i;
    }
    str = to_string(fact);
}

int main(){
    string Input , Bin;
    string ezcalculate;
    long double answer=16116554646.16151616;
    int Per=3 , check1 , check2;
    enum DorR Angle = radian;
    string keychars[] = {"log", "rad"};
    string keychars1[] = {"sin(", "cos(", "tan(", "cot(", "fac("};
    char Operator[] = {'+', '-', '*', '/', '^'};

    SimpleGuide();
    jump:
    cout << endl << "Please Enter Some Input:" << endl;
    jump1:
    getline(cin, Input);
    ezcalculate = "";
    for(int i = 0;i<Input.length();i++)
        Input[i] = tolower(Input[i]);

    while (Input.empty()){
        cout << "No Input , Please Try Again!" << endl;
        goto jump;
    }
    if (Input=="history"){
        if (history.size() == 0){
            cout << endl << "History is Empty" << endl;
            goto jump;
        }
        else{
            cout << endl << "History : " << endl << endl;
            for (int i=0 ; i < history.size() ; i++){
                    cout << i+1 << ". " << history[i] << endl;
                    cout << "      =" << history1[i] << endl << endl;
            }
            goto jump;
        }
    }
    else if (Input == "dguide"){
        system("cls");
        SimpleGuide();
        GuideCheck = false;
        goto jump;
    }
    else if (Input == "sguide"){
        system("cls");
        Guide();
        GuideCheck = true;
        goto jump;
    }
    else if (Input=="percision"){
        cout << endl << "Percision can be any Arithmetic number";
        cout << endl << "Percision: ";
        string per;
        getline(cin, per);
        Per = stoi(per);
        if (Per < 0){
            Per = -Per;
        }
        cout << endl << "Percision set to " << Per << endl;
        goto jump;
    }
    else if (Input=="degree"){
        if (Angle==0){
            Angle = degree;
            cout << endl <<"Angle type 'Changed' to Degree" << endl;
            goto jump;
        }
        else{
            cout << endl <<"Angle type 'Already' is Degree" << endl;
            goto jump;
        }
    }
    else if(Input == "game"){
        system("cls");
        system("C:\\Users\\asus\\Desktop\\GitHub\\Myworks\\Term1Project\\2048.exe");
    }
    else if (Input=="radian"){
        if (Angle==0){
            cout << endl <<"Angle type 'Already' is Radian" << endl;
            goto jump;
        }
        else{
            Angle = radian;
            cout << endl <<"Angle type 'Changed' to Radian" << endl;
            goto jump;
        }
    }
    else if (Input=="rehistory"){
        history.clear();
        history1.clear();
        cout << endl <<"History Deleted!" << endl;
        goto jump;
    }
    else if (Input=="reset"){
        system("cls");
        SimpleGuide();
        GuideCheck = false;
        history.clear();
        history1.clear();
        Per=3;
        Angle = radian;
        backgroundcolor = 0;
        textcolor = 7;
        setConsoleColor(textcolor, 0);
        setConsoleColor(7,backgroundcolor);
        answer=16116554646.16151616 ;
        system("cls");
        SimpleGuide();
        GuideCheck = false;
        history.clear();
        history1.clear();
        Per=3;
        Angle = radian;
        backgroundcolor = 0;
        textcolor = 7;
        setConsoleColor(textcolor, 0);
        setConsoleColor(7,backgroundcolor);
        cout << endl <<"Calculator Reseted!" << endl;
        goto jump;
    }
    else if (Input == "clear"){
        system("cls");
        if (GuideCheck){
            Guide();
        }
        else{
            SimpleGuide();
        }
        goto jump;
    }
    else if (Input == "ctheme"){
        cout << "What Do You Wanna Change?" << endl;
        cout << "1.Console BackGround Color" << endl << "2.Console Text Color" << endl;
        string num2;
        getline(cin, num2);
        char num;
        num = num2[0];
        if(num == '1'){
            cout << "Select Your Background Color :" << endl << "0. Black" << endl << "1. Dark Blue" << endl << "2. Green";
            cout << endl << "3. Aqua (Cyan)" << endl << "4. Red" << endl << "5. Purple" << endl << "6. Yellow";
            cout << endl << "7. White" << endl << "8. Gray" << endl << "9. Light Blue" << endl;
            string num;
            getline(cin, num);
            char num2 = num[0];
            cout << num2;
            switch(num2){
                case '1':
                    backgroundcolor = 1;
                    setConsoleColor(textcolor, 1);
                    break;
                case '2':
                    backgroundcolor = 2;
                    setConsoleColor(textcolor, 2);
                    break;
                case '3':
                    backgroundcolor = 3;
                    setConsoleColor(textcolor, 3);
                    break;
                case '4':
                    backgroundcolor = 4;
                    setConsoleColor(textcolor, 4);
                    break;
                case '5':
                    backgroundcolor = 5;
                    setConsoleColor(textcolor, 5);
                    break;
                case '6':
                    backgroundcolor = 6;
                    setConsoleColor(textcolor, 6);
                    break;
                case '7':
                    backgroundcolor = 7;
                    setConsoleColor(textcolor, 7);
                    break;
                case '8':
                    backgroundcolor = 8;
                    setConsoleColor(textcolor, 8);
                    break;
                case '9':
                    backgroundcolor = 9;
                    setConsoleColor(textcolor, 9);
                    break;
                case '0':
                    backgroundcolor = 0;
                    setConsoleColor(textcolor, 0);
                    break;

            }
            system("cls");
            if (GuideCheck){
                Guide();
            }
            else{
                SimpleGuide();
            }
            goto jump;
        }
        else if(num == '2'){
            cout << "Select Your Text Color :" << endl << "0. Black" << endl << "1. Dark Blue" << endl << "2. Green";
            cout << endl << "3. Aqua (Cyan)" << endl << "4. Red" << endl << "5. Purple" << endl << "6. Yellow";
            cout << endl << "7. White" << endl << "8. Gray" << endl << "9. Light Blue" << endl;
            string num;
            getline(cin, num);
            char num2 = num[0];
            cout << num2;
            switch(num2){
                case '1':
                    textcolor = 1;
                    setConsoleColor(1,backgroundcolor);
                    break;
                case '2':
                    textcolor = 2;
                    setConsoleColor(2,backgroundcolor);
                    break;
                case '3':
                    textcolor = 3;
                    setConsoleColor(3,backgroundcolor);
                    break;
                case '4':
                    textcolor = 4;
                    setConsoleColor(4,backgroundcolor);
                    break;
                case '5':
                    textcolor = 5;
                    setConsoleColor(5,backgroundcolor);
                    break;
                case '6':
                    textcolor = 6;
                    setConsoleColor(6,backgroundcolor);
                    break;
                case '7':
                    textcolor = 7;
                    setConsoleColor(7,backgroundcolor);
                    break;
                case '8':
                    textcolor = 8;
                    setConsoleColor(8,backgroundcolor);
                    break;
                case '9':
                    textcolor = 9;
                    setConsoleColor(9,backgroundcolor);
                    break;
                case '0':
                    textcolor = 0;
                    setConsoleColor(0,backgroundcolor);
                    break;

            }
            system("cls");
            if (GuideCheck){
                Guide();
            }
            else{
                SimpleGuide();
            }
            goto jump;
        }
    }
    else{
        Input.erase(remove_if(Input.begin(), Input.end(), ::isspace),Input.end());
        bool checkKC = false;
        bool checkKC1 = false;
        bool checkOP = false;
        for (int i=0 ; i < Input.length() ; i++){
            for (char j : Operator){
                if (Input[i]==j){
                    if(i == Input.length()-1){
                        checkOP = false;
                        break;
                    }
                    checkOP = true;
                    for (char k : Operator){
                        if (Input[i+1]==k and Input[i+1]!='-'){
                            checkOP = false;
                            break;
                        }
                    }
                    if(Input[i-1]=='(' and Input[i]!='-'){
                        checkOP = false;
                    }
                    if(Input[i]=='-' and Input[i+1]=='-'){
                        Input.replace(i,2,"+");
                        i=0;
                        j=0;
                    }
                    break;
                }
            }
            if (i < Input.length()-3){
                string key = Input.substr(i,3);
                for(string j : keychars){
                    if(j == key){
                        checkKC = true;
                        i = i+2;
                        break;
                    }
                }

                string key1 = Input.substr(i,4);
                for(string j : keychars1){
                    if(j == key1){
                        checkKC1 = true;
                        i = i+3;
                        break;
                    }
                }
            }
            if (isdigit(Input[i]) or Input[i] == 'e' or Input[i] == 'p' or Input[i]=='.' or Input[i]=='(' or Input[i]==')' or checkOP or checkKC or checkKC1){
                continue;
            }
            else{
                cout << endl <<"Invalid Input , Please Try again!" << endl;
                goto jump;
            }
        }
    }

    history.push_back(Input);

    if((Input[0] == '*' or Input[0] == '/' or Input[0] == '^' or Input[0] == '+' or Input[0] == '-') and answer != 16116554646.16151616){
        ezcalculate = to_string(answer);
    }

    //BEFORE KEY CHARS
    for (int i=0 ; i < Input.length() ; i++){
        if (Input[i]== 'e' or Input[i] == 'p' or Input[i] == 'c' or Input[i] == 's' or Input[i] == 't' or Input[i] == 'r' or Input[i] == 'f' or Input[i] == 'l'){
            if (isdigit(Input[i-1]) or Input[i-1] == 'e' or Input[i-1] == 'p' or Input[i-1] == ')'){
                Input.insert(i , "*");
                break;
            }
            else{
                break;
            }
        }
    }

    //AFTER KEY CHARS
    for (int i=0 ; i < Input.length()-1 ; i++){
        if (Input[i]==')'){
            if (isdigit(Input[i+1])){
                cout << endl << "Who the hell put number after ')' !!!" << endl;
                Check(history);
                goto jump;
            }
            else {
                break;
            }
        }
        if (Input[i]=='e'){
            if (isdigit(Input[i+1])){
                cout << endl << "Who the hell put number after 'e' !!!" << endl;
                Check(history);
                goto jump;
            }
            else {
                break;
            }
        }
        if (Input[i]=='p'){
            if (isdigit(Input[i+1])){
                cout << endl << "Who the hell put number after 'p' !!!" << endl;
                Check(history);
                goto jump;
            }
            else {
                break;
            }
        }
    }

    //E AND P
    for(int i = 0; i<Input.length();i++){
        if(Input[i] == 'e'){
            Input.replace(i,1,to_string(e));
        }
        if(Input[i] == 'p'){
            Input.replace(i,1,to_string(PI));
        }
    }

    //BEFORE PARANTECES
    for (int i=1 ; i < Input.length() ; i++) {
        if (Input[i] == '(') {
            if (isdigit(Input[i - 1]) or Input[i - 1]==')') {
                if (isdigit(Input[i-1]) and i - 1> 0) {
                    for (int k = i - 1 - 1 ; k >= 0 ; k--) {
                        if (isdigit(Input[k]) or Input[k-1] == 'g' or Input[k-1] == 'c' or Input[k] == '.'){
                            continue;
                        }
                        else if (Input[k] != 'c' and Input[k] != 'g') {
                            Input.insert(i , "*");
                            break;
                        }
                        else {
                            break;
                        }
                    }
                }
                else{
                    Input.insert(i , "*");
                    continue;
                }
            }
            else {
                continue;
            }
        }
    }

    //Key Chars For
    for (int i=Input.length() - 1 ; i >= 0 ; i--){
        int f = 0;
        string subx;
        if(i>1)
        subx = Input.substr(i-2,3);
        Bin = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

        if (subx == "log"){
            double base = 10;
            double index = 0;
            check1 = i - 2;
            check2 = i + 1;
            log:
            if (Input[check2]=='('){
                f = 0;
                int pcounter = 0;
                int pecounter = 0;
                for (int w=check2 + 1 ;  ; w++){
                    if(Input[w] == '(')
                        pcounter++;
                    if(Input[w] == ')')
                        pecounter++;
                    if(pecounter-1 == pcounter)
                       break;

                    Bin[f] = Input[w];
                    f++;

                }
                check2 += f ;
                string h = Bin.substr(0,f);
                Paranteces(h);
                index = Calculate(h);
            }
            else {
                for (int w=check2 ;Input[w]!= '(' ; w++){
                    Bin[f] = Input[w];
                    f++;
                    check2 = w + 1;
                }
                base =  Calculate(Bin.substr(0,f));
                goto log;
            }
            if (base == 1){
                cout << endl << "The Base of log can't be 1" << endl;
                Check(history);
                goto jump;
            }
            else if (base <= 0){
                cout << endl << "The Base of log Should Be 'Positive' Number" << endl;
                Check(history);
                goto jump;
            }
            else if (index <= 0){
                cout << endl << "The index of log Should Be 'Positive' Number" << endl;
                Check(history);
                goto jump;
            }
            Input.replace(check1,check2-check1+2,to_string(log(index) / log(base)));
        }
        else if (subx == "sin"){
            check1 = i - 2;
            check2 = i + 1;
            if (Input[check2]=='('){
                int pcounter = 0;
                int pecounter = 0;
                for (int w=check2+1 ; ; w++){
                    if(Input[w] == '(')
                        pcounter++;
                    if(Input[w] == ')')
                        pecounter++;
                    if(pecounter-1 == pcounter)
                       break;
                    Bin[f] = Input[w];
                    f++;

                }
                check2 += f ;
                string h = Bin.substr(0,f);
                Paranteces(h);
                if (Angle==0){
                    Input.replace(check1 , check2 - check1 + 2, to_string(sin(Calculate(h))));
                }
                else{
                    Input.replace(check1 , check2 - check1 + 2, to_string(sin(Calculate(h) * PI / 180)));
                }
            }
        }
        else if (subx == "cos"){
            check1 = i - 2;
            check2 = i + 1;
            if (Input[check2]=='('){
                int pcounter = 0;
                int pecounter = 0;
                for (int w=check2+1 ; ; w++){
                    if(Input[w] == '(')
                        pcounter++;
                    if(Input[w] == ')')
                        pecounter++;
                    if(pecounter-1 == pcounter)
                       break;
                    Bin[f] = Input[w];
                    f++;
                }
                check2 += f ;
                string h = Bin.substr(0,f);
                Paranteces(h);
                if (Angle==0){
                    Input.replace(check1 , check2 - check1 + 2, to_string(cos(Calculate(h))));
                }
                else{
                    Input.replace(check1 , check2 - check1 + 2, to_string(cos(Calculate(h) * PI / 180)));
                }
            }
        }
        else if (subx == "tan"){
            check1 = i - 2;
            check2 = i + 1;
            int pcounter = 0;
            int pecounter = 0;
            if (Input[check2]=='('){

                for (int w=check2+1 ; ; w++){
                    if(Input[w] == '(')
                        pcounter++;
                    if(Input[w] == ')')
                        pecounter++;
                    if(pecounter-1 == pcounter)
                       break;
                    Bin[f] = Input[w];
                    f++;
                }
                check2 += f;
                string h = Bin.substr(0,f);
                Paranteces(h);
                Inf = Calculate(h);
                if (Inf < 0){
                    Inf = -Inf;
                }
                if (Angle==0){
                    while (Inf > 0){
                        if (Inf ==(PI/2) or Inf ==(3*PI/2)){
                            cout << endl << "The answer of Tan is Infinity" << endl;
                            Check(history);
                            goto jump;
                        }
                        else
                            Inf -= PI;
                    }
                    Input.replace(check1 , check2 - check1 +2, to_string(tan(Calculate(h))));
                }
                else{
                    while (Inf > 0){
                        if (Inf == 90 or Inf == (270)){
                            cout << endl << "The answer of Tan is Infinity" << endl;
                            Check(history);
                            goto jump;
                        }
                        else
                            Inf -= (180);
                    }
                    Input.replace(check1 , check2 - check1 +2, to_string(tan(Calculate(h) * PI / 180)));
                }
            }
        }
        else if (subx == "cot"){
            check1 = i - 2;
            check2 = i + 1;
            if (Input[check2]=='('){
                int pcounter = 0;
                int pecounter = 0;
                for (int w=check2+1 ;Input[w]!= ')' ; w++){
                    if(Input[w] == '(')
                        pcounter++;
                    if(Input[w] == ')')
                        pecounter++;
                    if(pecounter-1 == pcounter)
                       break;
                    Bin[f] = Input[w];
                    f++;
                }
                check2 += f;
                string h = Bin.substr(0,f);
                Paranteces(h);
                Inf = Calculate(h);
                if (Inf < 0){
                    Inf = -Inf;
                }
                if (Angle==0){
                    while (Inf >= 0){
                        if (Inf ==(PI) or Inf == 0){
                            cout << endl << "The answer of Cot is Infinity" << endl;
                            Check(history);
                            goto jump;
                        }
                        Inf -= PI;
                    }
                    Input.replace(check1 , check2 - check1 + 2, to_string(tan(1/(Calculate(h)))));
                }
                else{
                    while (Inf >= 0){
                        if (Inf == 180 or Inf == 0){
                            cout << endl << "The answer of Cot is Infinity" << endl;
                            Check(history);
                            goto jump;
                        }
                        Inf -= (180);
                    }
                    Input.replace(check1 , check2 - check1 + 2, to_string(tan(1/(Calculate(h) * PI / 180))));
                }
            }
        }
        else if (subx == "rad"){
            double index = 2;
            int index1 = index;
            double Exp = 0;
            check1 = i - 2;
            check2 = i + 1;
            rad:
            if (Input[check2]=='('){
                f = 0;
                int pcounter = 0;
                int pecounter = 0;
                for (int w=check2+1 ; ; w++){
                    if(Input[w] == '(')
                        pcounter++;
                    if(Input[w] == ')')
                        pecounter++;
                    if(pecounter-1 == pcounter)
                       break;
                    Bin[f] = Input[w];
                    f++;
                }
                check2 += f;
                string h = Bin.substr(0,f);
                Paranteces(h);
                Exp = Calculate(h);
            }
            else {
                for (int w=check2 ;Input[w]!= '(' ; w++){
                    Bin[f] = Input[w];
                    f++;
                    check2 = w + 1;
                }
                index =  Calculate(Bin.substr(0,f));
                index1 = index;
                goto rad;
            }

            if (index < 0){
                cout << endl << "The Route of Radical Should Be 'Positive' Number" << endl;
                Check(history);
                goto jump;
            }
            else if (Exp < 0 and index1%2==0 ){
                cout << endl << "The Sub Radical Shouldn't Be 'Negative' Number When The Route is Even" << endl;
                Check(history);
                goto jump;
            }
            else if (index1%2==1 and Exp < 0){
                Input.replace(check1 , check2 - check1 +2 , to_string((-1)*pow(-Exp , 1/index)));
            }
            else{
                Input.replace(check1 , check2 - check1 +2 , to_string(pow(Exp , 1/index)));
            }
        }
        else if (subx == "fac"){
            Bin = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
            check1 = i - 2;
            check2 = i + 1;
            if (Input[check2]=='('){
                f = 0;
                int pcounter = 0;
                int pecounter = 0;
                for (int w=check2 + 1 ;  ; w++){
                    if(Input[w] == '(')
                        pcounter++;
                    if(Input[w] == ')')
                        pecounter++;
                    if(pecounter-1 == pcounter)
                       break;

                    Bin[f] = Input[w];
                    f++;
                }
                check2 += f + pcounter;
                string h = Bin.substr(0,f+pcounter);
                for (int i=0 ; i < h.length() ; i++){
                    if (h[i]=='.'){
                        cout << endl << "The Number of Factoriel shoulde be 'posetive Integer'" << endl;
                        Check(history);
                        goto jump;
                    }
                }
                if (stod(h) < 0){
                    cout << endl << "The Number of Factoriel shoulde be 'posetive Integer'" << endl;
                    Check(history);
                    goto jump;
                }
                Paranteces(h);
                Bin = to_string(Calculate(h));
                Factoriel(Bin);
                Input.replace(check1 , check2 - check1 + 1 , Bin);
            }
        }
    }

    //Main For
    for(int i = 0; i<Input.length();i++){
            ezcalculate += Input[i];
            Input.replace(i,1," ");
    }
    Paranteces(ezcalculate);
    answer = Calculate(ezcalculate);
    cout.precision(Per);
    cout << fixed << " =  " <<answer << endl;
    history1.push_back(answer);
    goto jump1;
}


/*
Bug of Calculator:
1. Sum of PI(p) and (e) numbers with * and / like p+2p .
2. Add * before e and p and key chars like p+p/4 .
3. The answer of sin , cos , tan , cot in radian like tan(5p/2) .
4. The infinite result in tan and cot .
5. Handling infinite number like 1+tan(p/2)= ∞ but 1+1/tan(p/2)= 1 .
6. The max precision of PI and e number .
More idea for Calculator;
1. Add the symbol of Factorial (!) .
2. Add the Graph and solving Problem like Input:'2x - 1 = 0' --> Output: 'x=½' .
3. Add solving Integral (∫) .
4. Add Difranciel (dx) .
*/
