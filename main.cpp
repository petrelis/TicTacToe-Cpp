#include <iostream>
#include <string>

using namespace std;

int arr[3][3];

void PrintBoard();

void ResetArrayValues();

void PlaceXO(int index);

bool Won(int index);

bool IsNumber(string input);

int StringToInt(string input);

void Play();

void PlayAgain();

int main()
{
    Play();
    PlayAgain();

    return 0;
}

void PrintBoard()
{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << " ";
            if(arr[i][j]==1) cout << "X";
            else if(arr[i][j]==2) cout << "O";
            else cout << " ";
            cout << " ";
            if(j<2){
               cout << "|";
            }
        }
        if(i<2){
            cout << endl << "---+---+---" << endl;
        }
    }
    cout << endl << endl;
}

void ResetArrayValues()
{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j] = 0;
        }
    }
}

void PlaceXO(int index)
{
    string posInput;
    cout << "Choose a position (1-9): ";
    int pos = StringToInt(posInput);
    int y, x;
    y=(pos-1)/3;
    x=(pos-1)%3;
    while(pos < 1 || pos > 9|| arr[y][x] != 0){
            cout << "Choose a valid position: ";
            pos = StringToInt(posInput);
            y=(pos-1)/3;
            x=(pos-1)%3;
            }

    if(index%2 == 1) arr[y][x] = 1;
    else arr[y][x] = 2;
}

bool Won(int index)
{
    int xCountD=0;
    int xCountDBack=0;
    int oCountD=0;
    int oCountDBack=0;

    for(int i=0; i<3; i++){
        int xCountH=0;
        int xCountV=0;
        int oCountH=0;
        int oCountV=0;
        if(arr[i][i] == 1) xCountD++;
        if(arr[2-i][i] == 1) xCountDBack++;
        if(arr[i][i] == 2) oCountD++;
        if(arr[2-i][i] == 2) oCountDBack++;

        for(int j=0; j<3; j++){
            if(arr[i][j] == 1) xCountH++;
            if(arr[j][i] == 1) xCountV++;
            if(arr[i][j] == 2) oCountH++;
            if(arr[j][i] == 2) oCountV++;
            if (xCountH == 3 || xCountV == 3 || xCountD == 3 || xCountDBack == 3){
                    cout << "X WON!";
                    return true;
            }
            if (oCountH == 3 || oCountV == 3 || oCountD == 3 || oCountDBack == 3){
                    cout << "O WON!";
                    return true;
            }

        }
    }
    if(index>8)
        {
            cout << "DRAW!";
            return true;
        }
    return false;
}

bool IsNumber(string input)
{
    for(int i=0; i<input.length(); i++)
        if(isdigit(input[i]) == false) return false;
        return true;
}

int StringToInt(string input)
{
    bool running = true;
    while(running == true)
    {
        cin >> input;
        if(IsNumber(input)==true)
            {
                return stoi(input);
            }
        cout << "Position must be a number, try again: ";

    }

}

void PlayAgain()
{
    char input;
    cout << endl << "Play again? (y/n): ";
    cin >> input;
    if(input == 'y') Play();
}

void Play()
{
    int index=0;
        bool running = true;
        while (running == true)
            {
                PrintBoard();
                if(Won(index)) running = false;
                else
                    {
                        index++;
                        PlaceXO(index);
                    }
            }
        ResetArrayValues();
}
