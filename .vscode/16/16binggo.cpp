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

   int vertical, horizon, diagonal, iTotal;
    // 게임시작
    while (true)
    {
        cout << "1 ~ 25까지의 숫자를 입력해주세요. (종료 : 0)" << endl;
        int iInput; // 플레이어의 입력값
        cin >> iInput;
    // 게임이 진행되지않는 예외사항을 먼저 적는다.
    // 1. 0을 입력해 종료하는 경우.
    if(iInput == 0)
    {
        cout << " 게임을 종료합니다 " << endl;
        break;
    }
    // 2. 1~25 사이의 숫자가 아닌 경우
    else if(!(iInput > 0 && iInput < 26))
    {
        cout << "1부터 25까지의 숫자로 다시 입력하세요" << endl;
        continue;
    }

    // 빙고판 보여주기
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if((iNumber[i*5 + j]==iInput)||(iNumber[i*5 + j]==INT_MAX))
            {
                cout << " * " << "\t";
                iNumber[i*5 + j] = INT_MAX;
            }
            else if(iNumber[i*5 + j] != INT_MAX)
            {
                cout << iNumber[i*5 +j] << "\t";
            }
        }
        cout << endl;
    }

    // * 갯수를 체크해서 빙고 줄 수를 체크한다.
    // boolean을 사용해서 true로 선언한 뒤
    // 해당 조건을 만족해야 true, 아니면 false
    // if( bool == true ) { ++ ver, ho, dia }
 
 
    vertical = horizon = diagonal= 0;

    // 1) 세로빙고
    for(int i = 0; i < 5; ++i)     // 0, 1, 2, 3, 4
    {   
        if(iNumber[i] == iNumber[i+5] == iNumber[i+10]== iNumber[i+15]== iNumber[i+20])
        {
            ++vertical;
        }
/*
0  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24
*/
// 2) 가로빙고
    if( (i%5==0)
    && (iNumber[i]==iNumber[i+1]==iNumber[i+2]==iNumber[i+3]==iNumber[i+4] ))
        {
            ++horizon;
        }
//대각선 빙고

    }
    if(iNumber[0] == iNumber[6] == iNumber[12] == iNumber[18] == iNumber[24])
        {
            ++diagonal;
        }
    if(iNumber[4] == iNumber[8] == iNumber[12] == iNumber[16] == iNumber[20])
        {
            ++diagonal;
        }

    // 빙고 결과 체크
    iTotal = vertical + horizon + diagonal;
    cout << "가로 :" << horizon << "\t" << "세로 :" << vertical << "\t" << "대각선 :" << diagonal 
    << "\t" << "총 :" << iTotal << endl;

    if(iTotal >= 5)
    {
        cout << "축하합니다, 게임을 종료합니다" << endl;
        break;
    }
}
}