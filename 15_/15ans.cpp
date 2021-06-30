// #include <iostream>
// #include <time.h>
// #include <conio.h>

// using namespace std;


// // 숫자퍼즐게임
// // 1부터 25칸까지 있고 마지막 25칸은 빈칸이다.
// // 이 빈칸을 이용해 퍼즐을 한칸씩 움직여 풀 수 있고
// // 1부터 24까지 순서대로 배열되면 게임이 끝난다.

// int main(){
//     srand((unsigned int)time(0));
    
//     int iNumber[25] = {};
//     for(int i = 0; i < 25; ++i)
//     {
//         iNumber[i] = i + 1;
//     }
    
//     // 가장 마지막 칸은 공백으로 비워둔다.
//     // 공백을 의미하는 값으로 특수한 값을 사용하는데,
//     // INT_MAX라는 값을 사용한다.
//     // INT_MAX는 이미 정의되어있는 값으로
//     // int로 표현할 수 있는 최대값이다.
//     iNumber[24] = INT_MAX;

//     // 별이 있는 위치를 저장할 변수를 만들어준다.
//     int iStarIndex = 24; // 초기값 24

//     // 마지막 공백 [24]를 제외하고 1~24까지의 숫자만 섞어준다.
//     // 즉 인덱스는 0~23번 인덱스까지만 채워준다.

//     int itemp, idx1, idx2;
//     for(int i = 0; i < 100; ++i)
//     {
//         idx1 = rand() % 24; // 0 ~ 23
//         idx2 = rand() % 24;

//         itemp = iNumber[idx1];
//         iNumber[idx1] = iNumber[idx2];
//         iNumber[idx2] = itemp;
//     }


//     while (true)
//     {
//         // i for문 = 세로칸
//         for(int i = 0; i < 5; ++i)
//         {
//             // j for문 = 가로칸
//             for(int j = 0; j < 5; ++j)
//             {
//                 // 특정 문자로 표시되게 하기.
//                 if(iNumber[i*5 +j] == INT_MAX)
//                 {
//                     cout << "*\t";
//                 }
//                 else
//                 {
//                     cout << iNumber[i*5 +j] << "\t";
//                 }
//             }
//             cout << endl;
//         }

//     bool bWin = true;

//     // 퍼즐을 맞추었는지 체크한다.
//     for (int i = 0; i < 24; ++i)
//     {
//         if (iNumber[i] != i + 1)
//         {
//             bWin = false;
//             break;
//         }
//     }
//     if(bWin == true)
//     {
//         cout << "숫자를 모드 맞췄습니다" << endl;
//         break; // 게임 종료
//     }


// cout << "w: 위, s:아래, a: 왼쪽, d: 오른쪽, q: 종료";
// /*_getch() 함수는 문자 1개를 입력받는 함수이다. 
// 이 함수는 enter 값을 치지 않더라도 문자를 누르는 순간
// 바로 그 문자를 반환하고 종료된다.
// */
// char cInput = _getch();
// if(cInput == 'q' || cInput == 'Q')
//     break;

// switch (cInput)
// {
//     case 'w' :
//     case 'W' :
//         // 가장 윗줄일 때는 w를 눌러도 동작하지 않아야 한다.
//         if(iStarIndex > 4)
//         {
//         // 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
//         iNumber[iStarIndex] = iNumber[iStarIndex - 5];
//         // 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
//         iNumber[iStarIndex - 5] = INT_MAX;
//         // 별이 한 칸 위로 올라갔으므로 한 칸 위의 인덱스로 만들어준다.
//         iStarIndex -= 5;
//         }
//         break;
//     case 's' :
//     case 'S' :
//         if(iStarIndex < 20)
//         {
//         iNumber[iStarIndex] = iNumber[iStarIndex + 5];
//         iNumber[iStarIndex + 5] = INT_MAX;
//         iStarIndex += 5;
//         }
//         break;
//     case 'a' :
//     case 'A' :
//         if(iStarIndex % 5 != 0 )
//         {
//         iNumber[iStarIndex] = iNumber[iStarIndex - 1];
//         iNumber[iStarIndex - 1] = INT_MAX;
//         // iStarIndex -= 1;
//         --iStarIndex;
//         }
//         break;
//     case 'd' :
//     case 'D' :
//         if(iStarIndex % 5 != 4 )
//         {
//         iNumber[iStarIndex] = iNumber[iStarIndex + 1];
//         iNumber[iStarIndex + 1] = INT_MAX;
//         // iStarIndex -= 1;
//         ++iStarIndex;
//         }
//         break;

// }

//         }
//     }