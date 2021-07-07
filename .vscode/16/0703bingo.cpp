#include <iostream>
#include <time.h>
using namespace std;


int main(){
    srand((unsigned int)time(0));

    int iNumber[25] = {};
    for(int i = 0 ; i < 25; ++i)
    {
        iNumber[i] = i + 1;
    }

    int iTemp, idx1, idx2;
    for(int i = 0 ; i < 100 ; ++i)
    {
        idx1 = rand()%25;
        idx2 = rand()%25;

        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }

    int iInput;
    int iBingo;
    iBingo = 0;

    while (true)
    {

        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(iNumber[5*i +j] == INT_MAX)
                {
                    cout << "*" << "\t";
                }
                else
                {
                    cout << iNumber[5*i +j] << "\t";
                }
            }
            cout << endl;
        }

        cout << " 빙고 수 : " << iBingo << endl << endl;
        if(iBingo >= 5)
        {
            cout << " 5개의 빙고를 모두 구했어요 축하합니다" << endl;
            break;
        }
        cout << "1 ~ 25 사이 숫자를 골라주세요 ( 종료: 0 )"<< endl;
        cin >> iInput;

        if(iInput == 0)
        {
            cout << "종료합니다" << endl;
            break;
        }
        else if(iInput < 1 || iInput > 25)
        {
            cout << " 1 ~ 25 사이의 숫자를 입력하세요" << endl;
            continue;
        }
        
        // 
        bool bAcc = true;

        for(int i = 0; i < 25; ++i)
        {
            if(iInput == iNumber[i])
            {
                bAcc = false;
                iNumber[i] = INT_MAX;
                break;
            }
        }
        if(bAcc)
        {
            continue;
        }



        // for(int i = 0 ; i < 25; ++i)
        // {
        //     if(iInput == iNumber[i])
        //     {
        //         iNumber[i] = INT_MAX;
        //     }
        // }

        int iStar1;
        int iStar2;
        iBingo = 0;

        for(int i = 0; i < 5; ++i)
        {
            iStar1 = 0;
            iStar2 = 0;
            for(int j = 0; j < 5; ++j)
            {
                if(iNumber[i*5 + j] == INT_MAX)
                {
                    ++iStar1;
                    if(iStar1 == 5)
                    {
                        ++iBingo;
                    }
                }

                if(iNumber[j*5 +i] == INT_MAX)
                {
                    ++iStar2;
                    if(iStar2 == 5)
                    {
                        ++iBingo;
                    }
                }
            }
        }

        iStar1 =0;
        iStar2 =0;
        for(int i = 0; i < 25; i += 6)
        {
            if (iNumber[i] == INT_MAX)
            {
                ++iStar1;
                if(iStar1 == 5)
                {
                    ++iBingo;
                }
            }
        }

        for(int i = 4; i < 25; i += 4)
        {
            if (iNumber[i] == INT_MAX)
            {
                ++iStar2;
                if(iStar2 == 5)
                {
                    ++iBingo;
                }
            }
        }
    }
}