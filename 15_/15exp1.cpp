#include <iostream>
#include <time.h>
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

    
}