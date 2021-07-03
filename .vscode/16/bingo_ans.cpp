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

   int iBingo = 0;
    // 게임시작
    while (true)
    {
         // 빙고판 보여주기
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(iNumber[i*5 + j]==INT_MAX)
            {
                cout << " *\t";
            }
            else
            {
                cout << iNumber[i*5 +j] << "\t";
            }
        }
        cout << endl;
    }

        cout << "Bingo Line : " << iBingo << endl;

        // 줄 수가 5이상일 경우 게임을 종료한다.
        if(iBingo >=5)
        { 
            cout << " 축하합니다 ~ " << endl;
            break;
        }

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

    // 중복입력을 체크하기 위한 변수이다.
    // 기본적으로 " 중복되었다 "라고 하기 위해 true로 잡아줌
    bool bAcc = true;

    // 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지 찾는다
    // 한개도 빠짐없이 ~ 해야하는 조건이 있을 때 bool 타입을 쓴다.
    for(int i = 0; i < 25; ++i)
    {
        // 같은 숫자가 있을 경우
        if (iInput == iNumber[i])
        {
            // 숫자를 찾았을 경우 중복된 숫자가 아니므로
            // bAcc 변수를 false으로 만들어준다.
            bAcc = false;
            // 숫자를 *로 변경하기 위해 INT_MAX로 해준다.
            iNumber[i] = INT_MAX;
            
            // 더이상 다른 숫자를 찾아볼 필요가 없으므로
            // for 문을 빠져나간다.
            break;
        }
    }

    // bAcc변수가 true일 경우 중복된 숫자를 입력해서
    // 숫자를 *로 바꾸지 못했으므로 다시 입력받게 continue.
    if (bAcc)
    {
        continue;
    }
    
    // 빙고 줄 수를 체크하는 것은 매번 숫자를 입력할 때마다
    // 처음부터 새로 카운트를 할 것이다.
    // 그러므로 iBingo 변수를 0으로 매번
    // 초기화하고 새롭게 줄 수를 체크해서 구한다.
    iBingo = 0;

    // 가로, 세로 줄 수를 구해준다.
    int iStar1 = 0, iStar2 = 0;
    for(int i = 0; i < 5; ++i)
    {
        // 한 줄을 체크하기 전에 별 갯수를 먼저 0으로 초기화
        iStar1 = iStar2 = 0;
        for(int j = 0; j < 5; ++j)
        {
            // 가로 별 개수를 구한다.
            if(iNumber[i*5 +j] == INT_MAX)
                ++iStar1;
            // 세로 별 개수를 구해준다.
            if(iNumber[j*5 + i] == INT_MAX)
                ++iStar2;
        }
        // j for문을 빠져나오고 나면 현재 줄의 가로 별 개수가
        // 몇 개인지 iStar1 변수에 들어가게 된다.
        // iStar1의 값이 5이면 한줄에 모두 *이라는 의미,
        // 즉 빙고 줄 카운트를 추가해준다.
        if(iStar1 == 5)
            ++iBingo;
        if(iStar2 == 5)
            ++iBingo;
    }
    
    // 왼쪽 상단 > 오른쪽 하단 대각선 체크
    iStar1 = 0;
    for(int i = 0; i < 25; i +=6)
    {
        if(iNumber[i] == INT_MAX)
            ++iStar1;
    }
    if(iStar1 == 5)
        ++iBingo;

    // 오른쪽 상단 > 왼쪽 하단 대각선 체크
    for(int i = 4; i <= 20; i +=4)
    {
        if(iNumber[i] == INT_MAX)
            ++iStar1;
    }
    if(iStar2 ==5)
        ++iBingo;
   
}
}