#include <iostream>
#include <time.h>

using namespace std;

// 난이도 설정
enum AI_MODE
{
    AM_EASY = 1,
    AM_HARD
};

enum LINE_NUMBER
{
    LN_H1, // 가로
    LN_H2,
    LN_H3,
    LN_H4,
    LN_H5,

    LN_V1, // 세로
    LN_V2,
    LN_V3,
    LN_V4,
    LN_V5,

    LN_LT, // 대각선
    LN_RT
};

// 함수는 선언과 정의부분으로 나눌 수 있다.
void SetNumber(int *pArray);
void Suffle(int *pArray);
AI_MODE SelectAiMode();
void OutputNumber(int *pArray, int iBingo);
bool ChangeNumber(int *pArray, int iInput);
int SelectAINumber(int *pArray, AI_MODE eMode);
int BingoCounting(int *pArray);
int BingoCountingH(int *pArray);
int BingoCountingV(int *pArray);
int BingoCountingRTD(int *pArray);
int BingoCountingLTD(int *pArray);

int main(){
    srand((unsigned int)time(0));

    int iNumber[25];
    int iAi[25];

    SetNumber(iNumber);
    SetNumber(iAi);

    Suffle(iNumber);
    Suffle(iAi);

   int iBingo = 0, iAiBingo = 0;

    // AI 난이도를 선택한다.
    //int iAiMode = SelectAiMode();
   AI_MODE eAIMode = SelectAiMode();
    

    /*
    AI Easy 모드는 현재 AI의 숫자목록 중 
    *로 바뀌지 않은 숫자목록을 만들어서
    그 목록 중 하나를 랜덤선택한다.
    */

    // 게임시작
    while (true)
    {
        system("clear");
         // 빙고판 보여주기
    cout << "=======Player======" << endl;

    OutputNumber(iNumber, iBingo);

        // AI 빙고판 출력
    cout << "=======   AI  ======" << endl;
    switch (eAIMode)
    {
    case AM_EASY:
        cout << "AIMode : Easy" << endl;
        break;
    case AM_HARD:
        cout << "AIMode : Hard" << endl;
        break;
    }

    OutputNumber(iAi, iAiBingo);
    

        // 줄 수가 5이상일 경우 게임을 종료한다.
        if(iBingo >=5)
        { 
            cout << " Player 승리 ! 축하합니다 ~ " << endl;
            break;
        }

        else if(iAiBingo >=5)
        { 
            cout << " AI 승리 " << endl;
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
    bool bAcc = ChangeNumber(iNumber, iInput);

    // bAcc변수가 true일 경우 중복된 숫자를 입력해서
    // 숫자를 *로 바꾸지 못했으므로 다시 입력받게 continue.
    if (bAcc)
    {
        continue;
    }

    //중복이 아니라면 AI의 숫자도 찾아서 *로 바꾼다.
    ChangeNumber(iAi, iInput);

    // AI가 숫자를 선택한다. AI모드에 맞춰서 선택되도록 함수가 구성되어있다.
    iInput = SelectAINumber(iAi, eAIMode);

    // AI가 숫자를 선택했으므로 플레이어와 AI의 숫자를 *로 바꾼다.
    // AI 숫자를 바꿔준다.
    ChangeNumber(iNumber, iInput);
    ChangeNumber(iAi, iInput);

    // 빙고 줄 수를 체크하는 것은 매번 숫자를 입력할 때마다
    // 처음부터 새로 카운트를 할 것이다.
    // 그러므로 iBingo 변수를 0으로 매번
    // 초기화하고 새롭게 줄 수를 체크해서 구한다.
    iBingo = BingoCounting(iNumber);
    iAiBingo = BingoCounting(iAi);
}
}

void SetNumber(int *pArray)
{
    for(int i = 0; i < 25; ++i)
    {
        pArray[i] = i + 1;
    }
}

void Suffle(int *pArray)
{
    int iTemp, idx1, idx2;
    for(int i = 0; i < 100; ++i)
    {
        idx1 = rand()% 25;
        idx2 = rand()% 25;

        iTemp = pArray[idx1];
        pArray[idx1] = pArray[idx2];
        pArray[idx2] = iTemp;
    }
}

AI_MODE SelectAiMode()
{
    int iAiMode;
    while (true)
    {
    system("clear");
    cout << "1. Easy" << endl;
    cout << "2. Hard" << endl;
    cout << "Ai 모드를 선택하세요 : ";
    cin >> iAiMode;
    if(iAiMode >= AM_EASY && iAiMode <= AM_HARD)
        break;
    }
    // iAiMode는 int타입이지만
    // (AI_MODE)타입으로 형변환!
    return (AI_MODE)iAiMode;
}

void OutputNumber(int *pArray, int iBingo)
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(pArray[i*5 + j]==INT_MAX)
            {
                cout << " *\t";
            }
            else
            {
                cout << pArray[i*5 +j] << "\t";
            }
        }
        cout << endl;
    }
    cout << "Bingo Line : " << iBingo << endl << endl;

}

bool ChangeNumber(int *pArray, int iInput)
{
// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지 찾는다
    // 한개도 빠짐없이 ~ 해야하는 조건이 있을 때 bool 타입을 쓴다.
    for(int i = 0; i < 25; ++i)
    {
        // 같은 숫자가 있을 경우
        if (iInput == pArray[i])
        {
            // 숫자를 찾았을 경우 중복된 숫자가 아니므로
            // bAcc 변수를 false으로 만들어준다.
            // 숫자를 *로 변경하기 위해 INT_MAX로 해준다.
            pArray[i] = INT_MAX;
            
            // 더이상 다른 숫자를 찾아볼 필요가 없으므로
            // for 문을 빠져나간다.
            return false;
        }
    }
    // 여기까지 오게되면 return false가 동작안된 것이므로
    // 같은 숫자가 없다는 것이다.
    // 즉, 중복된 숫자를 입력했기에 true를 리턴한다.
    return true;
}

int SelectAINumber(int *pArray, AI_MODE eMode)
{
    // 선택안된 목록 배열
   int iNoneSelect[25] = {};
   // 선택안된 숫자 개수 저장
   int iNoneSelectCount = 0;

    // AI가 선택을 한다. AI가 선택을 하는 것은 모드에 따라 달라진다.
    switch (eMode)
    {
    case AM_EASY:
        // 선택 안된 숫자목록을 만들어준다.
        // 선택 안된 숫자 개수는 목록을 만들때 카운팅.
        iNoneSelectCount = 0;
        for(int i = 0; i < 25; ++i)
        {
            // 현재 숫자가 *이 아닐 경우
            if( pArray[i] != INT_MAX)
            {
                // *이 아닌 경우 iNoneSelectCount를 인덱스로 사용
                // 선택 안된 목록에 추가할 때마다 개수 1씩 증가
                // 총 선택 안된 개수를 구해준다.
                // 그런데, 0부터 카운트가 시작이므로 0번에 ++해서 1개추가
                // 그 다음엔 1, 2, 3... 추가
                iNoneSelect[iNoneSelectCount] = pArray[i];
                ++iNoneSelectCount;
            }
        }
    // for문을 빠져나오게되면 선택안된 목록이 만들어지고
    // 선택안된 목록의 개수가 만들어진다.
    // 선택안된 목록의 숫자 중 랜덤한 하나의 숫자를 얻어오기 위해
    // 인덱스를 랜덤하게 구해준다.
        return iNoneSelect[rand() % iNoneSelectCount];
    // break; 리턴해주면 break가 필요없다.
    case AM_HARD:
        // 하드모드는 현재 숫자 중 빙고완성 가능성이
        // 가장 높은 줄의 숫자 하나를 *로 만들어준다.
        int iLine =0;
        int iStarCount =0;
        int iSaveCount =0;

        // 가로  라인 중 가장 *이 많은 라인을 찾아낸다.
        for(int i = 0; i < 5; ++i)
        {
            iStarCount = 0;
            for(int j = 0; j <5; ++j)
            {
                if(pArray[i*5 + j] == INT_MAX)
                    ++iStarCount;
            }
            // 5가 되어버리면 빙고가 된거니까 선택 x
            // 기존 가장 별이 많은 라인(iSaveCount)보다
            // 큰 라인을 골라야 하므로 iSaveCount => iStarCount
            // 로 교체해주고 저장된 별 수를 교체한다.
            if(iStarCount < 5 && iSaveCount < iStarCount)
            {
                // 여기는 가로라인 중 가장 별이 많은 라인을 체크
                // 가로라인은 0 ~4로 의미를 부여한다.
                iLine = i;
                iSaveCount = iStarCount;
            }
        }


        // 가로 라인 중 가장 별이 많은 라인을 이미 구했다.
        // 이 값을 세로 라인과 비교하여 별이 가장 많은 라인을 구한다.
        for (int i = 0; i < 5; ++i)
        {
            iStarCount = 0;
            for (int j = 0; j < 5; ++j)
            {
                if(pArray[j*5 + i] == INT_MAX)
                    ++iStarCount;
            }
            if(iStarCount < 5 && iSaveCount < iStarCount)
            {
                // 세로라인은 5 ~ 9로 의미부여. (그냥 enum 줄번호임)
                iLine = i + 5;
                iSaveCount = iStarCount;
            }
        }
        
        // 왼->오른쪽 대각선 체크
        iStarCount = 0;
        for(int i = 0; i > 25; i +=6)
        {
            if(pArray[i] == INT_MAX)
                ++iStarCount;
        }

        if(iStarCount < 5 && iSaveCount < iStarCount)
        {
            iLine = LN_LT;
            iSaveCount = iStarCount;
        }

        // 오->왼쪽 대각선 체크
        iStarCount = 0;
        for(int i = 4; i <=20; i +=4)
        {
            if(pArray[i == INT_MAX])
                ++iStarCount;
        }

        if(iStarCount < 5 && iSaveCount < iStarCount)
        {
            iLine = LN_RT;
            iSaveCount = iStarCount;
        }
        // 모든 라인을 조사했으면 iLine에
        // 가장 가능성이 높은 줄번호가 저장된다.
        // 그 줄에 있는 *이 아닌 숫자 하나를 선택한다.
        // 가로줄일 경우
        if(iLine <= LN_H5)
        {
            // 가로줄일 경우 iLine이 0 ~ 4 사이의 값
            for(int i =0; i<5; ++i)
            {
                // 현재 줄에서 *이 아닌 숫자를 찾아낸다.
                if(pArray[iLine*5 + i] != INT_MAX)
                {
                    return pArray[iLine*5 + i];
                }
            }
        }

        else if (iLine >= LN_V5)
        {
            // 세로줄일 경우 iLine 5-9 사이값 (enum)
            for(int i = 0; i < 5; ++i)
            {
                if(pArray[i*5 + (iLine -5)] != INT_MAX)
                {
                    return pArray[i*5 + (iLine -5)];
                }
            }
        }

        else if(iLine == LN_LT)
        {
            for (int i = 0; i < 25; i +=6)
            {
                if(pArray[i] != INT_MAX)
                {
                   return  pArray[i];
                  
                }
            }
        }

        else if(iLine == LN_RT )
        {
            for(int i = 4; i <= 20; i +=4)
            {
                if(pArray[i] != INT_MAX)
                {
                   return pArray[i];
              
                }
            }
        }

        break;
    }

    return -1;
    // 여기까지 왔으면 잘못된 값.
}

int BingoCounting(int *pArray)
{
    int iBingo = 0;
    //가로줄 체크
    iBingo += BingoCountingH(pArray);
    //세로줄 체크
    iBingo += BingoCountingV(pArray);
    //우 대각선줄 체크
    iBingo += BingoCountingRTD(pArray);
    //좌 가로줄 체크
    iBingo += BingoCountingLTD(pArray);

    return iBingo;
}
int BingoCountingH(int *pArray)
{
  // 가로 줄 수를 구해준다.
    int iStar1 = 0, iBingo = 0;

    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            // 가로 별 개수를 구한다.
            if(pArray[i*5 +j] == INT_MAX)
                ++iStar1;
        }
        // j for문을 빠져나오고 나면 현재 줄의 가로 별 개수가
        // 몇 개인지 iStar1 변수에 들어가게 된다.
        // iStar1의 값이 5이면 한줄에 모두 *이라는 의미,
        // 즉 빙고 줄 카운트를 추가해준다.
        if(iStar1 == 5)
            ++iBingo;
    }
    return iBingo;
}
int BingoCountingV(int *pArray)
{
  // 가로 줄 수를 구해준다.
    int iStar1 = 0, iBingo = 0;

    for(int i = 0; i < 5; ++i)
    {
        // 한 줄을 체크하기 전에 별 갯수를 먼저 0으로 초기화
        for(int j = 0; j < 5; ++j)
        {
            // 가로 별 개수를 구한다.
            if(pArray[j*5 +i] == INT_MAX)
                ++iStar1;
        }
        // j for문을 빠져나오고 나면 현재 줄의 가로 별 개수가
        // 몇 개인지 iStar1 변수에 들어가게 된다.
        // iStar1의 값이 5이면 한줄에 모두 *이라는 의미,
        // 즉 빙고 줄 카운트를 추가해준다.
        if(iStar1 == 5)
            ++iBingo;
    }
    return iBingo;
}


int BingoCountingRTD(int *pArray)
{
    // 가로 줄 수를 구해준다.
    int iStar1 = 0, iBingo = 0;

    // 오른쪽 상단 > 왼쪽 하단 대각선 체크
    for(int i = 4; i < 21; i +=4)
    {
        if(pArray[i] == INT_MAX)
            ++iStar1;
    }
    if(iStar1 ==5)
        ++iBingo;

    return iBingo;
}

int BingoCountingLTD(int *pArray)
{
    // 가로 줄 수를 구해준다.
    int iStar1 = 0, iBingo = 0;

    // 오른쪽 상단 > 왼쪽 하단 대각선 체크
    for(int i = 0; i < 25; i +=6)
    {
        if(pArray[i] == INT_MAX)
            ++iStar1;
    }
    if(iStar1 ==5)
        ++iBingo;

    return iBingo;
}