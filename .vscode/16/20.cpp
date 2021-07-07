#include <iostream>

using namespace std;

// 유지보수 측면에서 define을 사용한다.
#define NAME_SIZE 32

/*
구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능
사용자정의 변수 타입.
형태 : struct 구조체명 {};
배열과 구조체의 공통점 :
1) 데이터의 집합이다.
2) 연속된 메모리 블럭에 할당된다. 
   구조체 멤버들은 연속된 메모리 블럭으로 잡힌다.
3) 
*/

struct  _tagStudent
{
    char strName[NAME_SIZE];
    int iNumber;
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvg;
};

int main(){
    _tagStudent tStudent = {}; // 0으로 초기화
    _tagStudent tStudentArr[100] = {};
    
    // 구조체 멤버에 접근할 때는 . 을 이용해서 접근한다.
    tStudent.iKor = 100;

    // tStudent.strName = " abC 가나다";
    // 문자열을 배열에 넣어줄 때는 단순 대입으로는 불가

    // strcpy 라는 함수로 문자열을 복사해야한다.
    strcpy(tStudent.strName, "가나다");

    // strcat 함수는 문자열을 붙여주는 기능
    strcat(tStudent.strName, "문자열 붙이기");

    // strcmp 함수는 두 문자열을 비교하여 같을 경우 0을 반환,
    // 다를 경우 0이 아닌 값을 반환한다.
    strcpy(tStudent.strName, "홍길동");

    cout << "비교할 이름을 입력하세요 : ";
    char strName[NAME_SIZE] = {};
    cin >> strName;

    if(strcmp(tStudent.strName, strName) == 0)
    {
        cout << "학생을 찾았습니다" << endl;
    }
    else
    {
        cout << "학생이 없습니다" << endl;
    }


    // strlen은 문자열의 길이
    cout << " 이름 길이 : " << strlen(tStudent.strName) << endl;
    
    /*
    문자열의 끝은 항상 0(NULL)로 끝나야 한다.
    그런데 쓰레기값이 들어있는 상태에서 각 배열 요소에 값을 넣어주면
    넣어주지 않은 부분은 쓰레기값으로 그대로 출력된다.
    strcpy 함수를 사용하는 경우에는 자동으로 NULL이 끝에 들어간다.
    */

    cout << tStudent.strName << endl;
    
}
