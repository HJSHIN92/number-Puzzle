#include <iostream>
#include <time.h>
// 맥이라서 오류남 ; 윈도우에서만 사용가능.
// #include <conio.h>

using namespace std;


// 숫자퍼즐게임
// 1부터 25칸까지 있고 마지막 25칸은 빈칸이다.
// 이 빈칸을 이용해 퍼즐을 한칸씩 움직여 풀 수 있고
// 1부터 24까지 순서대로 배열되면 게임이 끝난다.

int main(){
    srand((unsigned int)time(0));
    
    int iNumber[25] = {};
    for(int i = 0; i < 25; ++i)
    {
        iNumber[i] = i + 1;
    }
    
    // 가장 마지막 칸은 공백으로 비워둔다.
    // 공백을 의미하는 값으로 특수한 값을 사용하는데,
    // INT_MAX라는 값을 사용한다.
    // INT_MAX는 이미 정의되어있는 값으로
    // int로 표현할 수 있는 최대값이다.
    iNumber[24] = INT_MAX;

    // 마지막 공백 [24]를 제외하고 1~24까지의 숫자만 섞어준다.
    // 즉 인덱스는 0~23번 인덱스까지만 채워준다.

    int itemp, idx1, idx2;
    for(int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 24; // 0 ~ 23
        idx2 = rand() % 24;

        itemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = itemp;
    }


    while (true)
    {
        // i for문 = 세로칸
        for(int i = 0; i < 5; ++i)
        {
            // j for문 = 가로칸
            for(int j = 0; j < 5; ++j)
            {
                // 특정 문자로 표시되게 하기.
                if(iNumber[i*5 +j] == INT_MAX)
                {
                    cout << "*\t";
                }
                else
                {
                    cout << iNumber[i*5 +j] << "\t";
                }
            }
            cout << endl;
        }

        cout << "옮기고 싶은 퍼즐과 빈칸위치를 입력하세요. (종료 : 00)" << endl;
        // 퍼즐은 INT_MAX 값을 갖는 퍼즐위치로만 이동할 수 있다.
        
        int iPlayer;
        int iBlank = INT_MAX;
        
        cin >> iPlayer >> iBlank;
        if(iPlayer==00){
            cout << "게임을 종료합니다" << endl;
            exit(0);
        }
        // 1) INT_MAX값이 있지 않으면 바꿀 수 없다.
        else if(iNumber[iBlank] != INT_MAX)
        {
            cout << " 빈 칸이 아닙니다. 다시 선택해주십시오. " << endl;
            continue;
        }
        else if(!(iPlayer >= 0 && iPlayer <= 24 && iBlank >= 0 && iBlank <= 24))
        {
            cout << "0~24 사이의 값으로 다시 입력해주세요" << endl;
            continue;
        }

        // 위치바꾸기
        iNumber[iBlank] = iNumber[iPlayer];
        iNumber[iPlayer] = INT_MAX;

        }
    }