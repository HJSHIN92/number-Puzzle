#include <iostream>
#include <time.h>

using namespace std;

int main(){
    srand((unsigned int)time(0));

    int iNumber[25];
    for(int i = 0; i < 25; ++i)
    {
        iNumber[i] = i + 1;
    }

    // suffle
    int iTemp, idx1, idx2;
    for(int i = 0; i < 100; ++i)
    {
        idx1 = rand()% 25;
        idx2 = rand()% 25;

        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }


    // 게임시작
    while (true)
    {
        cout << "1 ~ 24까지의 숫자를 입력해주세요. (종료 : 0)" << endl;
        int iInput; // 플레이어의 입력값
        cin >> iInput;
    // 게임이 진행되지않는 예외사항을 먼저 적는다.
    // 1. 0을 입력해 종료하는 경우.
    if(iInput == 0)
    {
        cout << " 게임을 종료합니다 " << endl;
        break;
    }
    // 2. 1~24 사이의 숫자가 아닌 경우
    else if(!(iInput > 0 && iInput < 25))
    {
        cout << "1부터 24까지의 숫자로 다시 입력하세요" << endl;
        continue;
    }

    // 빙고판 보여주기
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(iNumber[i*5 + j]==iInput)
            {
                cout << " * " << "\t";
            }
            else
            {
                cout << iNumber[i*5 +j] << "\t";
            }
        }
        cout << endl;
    }
            
        }        
    }