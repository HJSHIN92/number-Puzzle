#include <iostream>
using namespace std;

#define NAME_SIZE 10
#define PHONE_SIZE 14
#define ADDRESS_SIZE 130

#define STUDENT_MAX 10

struct _tagStudent
{
    char strName[NAME_SIZE];
    char strAddress[ADDRESS_SIZE];
    char strPhone[PHONE_SIZE];

    int iKor;
    int iEng;
    int iMath;

    int iTotal;
    float fAvg;
};


enum MENU
{
    MENU_NONE,
    MENU_INSERT,
    MENU_DELETE,
    MENU_SEARCH,
    MENU_OUTPUT,
    MENU_EXIT
};

int main(){
    _tagStudent tStudentArray[STUDENT_MAX] = {};
    int iStudentCount = 0;
    int iStrNumber = 1;
    char strName[NAME_MAX];

    while (true)
    {
    cout << "1. 학생입력" << endl;
    cout << "2. 학생삭제" << endl;
    cout << "3. 학생검색" << endl;
    cout << "4. 학생조회" << endl;
    cout << "5. 종료" << endl << endl;

    cout << "메뉴를 골라주세요" << endl;
    int iMenu;
    cin >> iMenu;

    if(iMenu == MENU_EXIT)
        break;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1024, '\n');
        continue;
    }

    switch (iMenu)
    {
    case MENU_INSERT:
        cout << "학생 정보를 입력해주세요 " << endl;
        cout << "이름 : ";
        cin >> tStudentArray[iStudentCount].strName;
        
        cin.ignore(1024, '\n');

        cout << "주소 :";
        cin.getline(tStudentArray[iStudentCount].strAddress, ADDRESS_SIZE);
        
        cout << "전화번호 :";
        cin.getline(tStudentArray[iStudentCount].strPhone, PHONE_SIZE);

        cout << "국어 :";
        cin >> tStudentArray[iStudentCount].iKor;
        cout << "영어 :";
        cin >> tStudentArray[iStudentCount].iEng;
        cout << "수학 :";
        cin >> tStudentArray[iStudentCount].iMath;

        tStudentArray[iStudentCount].iTotal =
        tStudentArray[iStudentCount].iKor +
        tStudentArray[iStudentCount].iEng +
        tStudentArray[iStudentCount].iMath;

        tStudentArray[iStudentCount].fAvg =
        tStudentArray[iStudentCount].iTotal / 3.f;

        ++iStudentCount;
        ++iStrNumber;
        break;

    case MENU_DELETE:
        cout << "삭제 할 학생이름을 입력해주세요" << endl;
        cin >> strName;
        // 스페이스 허용하는 경우 아래와 같이 쓴다.
        // cin.ignore(1024, '\n');
        // cin.getline(strName, NAME_SIZE);
        for(int i = 0; i < iStudentCount; ++i)
        {
            if(strcmp(tStudentArray[i].strName,strName)==0)
            {
                for(int j = i; j < iStudentCount -1; ++j)
                {
                    tStudentArray[i] = tStudentArray[ i+1 ];
                }
            }
        }
        --iStudentCount;
        break;

    case MENU_SEARCH:
        cout << "조회 할 학생이름을 입력해주세요" << endl;
        cin >> strName;
        for(int i = 0; i < iStudentCount; ++i)
        {
            if(strcmp(tStudentArray[i].strName,strName)==0)
            {
                cout << "이름 : "<< tStudentArray[i].strName << endl;
                cout << "주소 : "<< tStudentArray[i].strAddress << endl;
                cout << "전화번호 : "<< tStudentArray[i].strPhone << endl;
                cout << "국어 : "<< tStudentArray[i].iKor << endl;
                cout << "영어 : "<< tStudentArray[i].iEng << endl;
                cout << "수학 : "<< tStudentArray[i].iMath << endl;
                cout << "총점 : "<< tStudentArray[i].iTotal << endl;
                cout << "평균 : "<< tStudentArray[i].fAvg << endl << endl;
                break;
            }
        }
        break;

    case MENU_OUTPUT:
        cout << "학생 목록을 조회합니다" << endl;
        for(int i = 0; i < iStudentCount; ++i)
        {
                cout << "이름 : "<< tStudentArray[i].strName << endl;
                cout << "주소 : "<< tStudentArray[i].strAddress << endl;
                cout << "전화번호 : "<< tStudentArray[i].strPhone << endl;
                cout << "국어 : "<< tStudentArray[i].iKor << endl;
                cout << "영어 : "<< tStudentArray[i].iEng << endl;
                cout << "수학 : "<< tStudentArray[i].iMath << endl;
                cout << "총점 : "<< tStudentArray[i].iTotal << endl;
                cout << "평균 : "<< tStudentArray[i].fAvg << endl << endl;
        }
        break;
    
    default:
        cout << "잘못입력하셨습니다" << endl;
        break;
    }
    
    }


}