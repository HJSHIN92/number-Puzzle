#include <iostream>
using namespace std;


#define NAME_SIZE 32
#define ADDRESS_SIZE 100
#define PHONENUMBER_SIZE 14

#define STUDENT_MAX 10

struct _tagStudent
{
    char strName[NAME_SIZE];
    char strAddress[ADDRESS_SIZE];
    char strPhoneNumber[PHONENUMBER_SIZE];
    int iNumber;
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvr;
};

enum MENU
{
    MENU_NULL,
    MENU_INSERT,
    MENU_DELETE,
    MENU_SEARCH,
    MENU_OUTPUT,
    MENU_EXIT
};

int main(){
_tagStudent tStudentArr[STUDENT_MAX] = {};
int iStudentCount = 0;
int iStdNumber = 1;

char strName[NAME_SIZE] = {};

while (true)
{
    cout << "1. 학생 입력" << endl;
    cout << "2. 학생 삭제" << endl;
    cout << "3. 학생 검색" << endl;
    cout << "4. 학생 조회" << endl;
    cout << "5. 종료" << endl;
    int iMenu;
    cin >> iMenu;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1024, '\n');
        continue;
    }

    if(iMenu == MENU_EXIT)
    {
        break;
    }

    switch (iMenu)
    {
    case MENU_INSERT:
        cout << "학생 등록" << endl;
        cout << "이름 :";
        cin >> tStudentArr[iStudentCount].strName;

        cin.ignore(1024, '\n');
        
        cout << "주소 :";
        cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

        cout << "전화번호 :";
        cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONENUMBER_SIZE);

        cout << "국어 :";
        cin >> tStudentArr[iStudentCount].iKor;
        cout << "영어 :";
        cin >> tStudentArr[iStudentCount].iEng;
        cout << "수학 :";
        cin >> tStudentArr[iStudentCount].iMath;

        tStudentArr[iStudentCount].iTotal =
            tStudentArr[iStudentCount].iKor +
            tStudentArr[iStudentCount].iEng +
            tStudentArr[iStudentCount].iMath;

        tStudentArr[iStudentCount].fAvr =
            tStudentArr[iStudentCount].iTotal / 3.f;

        ++ iStudentCount;
        ++ iStdNumber;
        break;

    case MENU_DELETE:
        system("clear");
        cout << "삭제하고싶은 학생이름을 입력하세요" << endl;
        cin.ignore(1024, '\n');
        cin.getline(strName, NAME_SIZE);

        for(int i = 0; i < iStudentCount; ++i)
        {
        if(strcmp(tStudentArr[i].strName, strName)==0)
        {
            for(int j = i; j < iStudentCount -1; ++j)
            {
                tStudentArr[i] = tStudentArr[ i + 1 ];
            }
            --iStudentCount;
            cout << "학생이 삭제되었습니다" << endl;
                break;
        }
        }
        break;

    case MENU_SEARCH:
        cout << "찾고싶은 학생이름을 입력하세요" << endl;
        // cin >> strName;
        cin.ignore(1024, '\n');
        cin.getline(strName, NAME_SIZE);

        for(int i = 0; i < iStudentCount; ++i)
        {
        if(strcmp(tStudentArr[i].strName, strName)==0)
        {
                cout << "이름 : " << tStudentArr[i].strName << endl;
                cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
                cout << "주소 : " << tStudentArr[i].strAddress << endl;
                cout << "학번 : " << tStudentArr[i].iNumber << endl;
                cout << "국어 : " << tStudentArr[i].iKor << endl;
                cout << "영어 : " << tStudentArr[i].iEng << endl;
                cout << "수학 : " << tStudentArr[i].iMath << endl;
                cout << "총점 : " << tStudentArr[i].iTotal << endl;
                cout << "평균 : " << tStudentArr[i].fAvr << endl << endl;
                break;
        }
        }
        break;

    case MENU_OUTPUT:
        system("clear");
        cout << "학생출력" << endl;
        for(int i = 0; i < iStudentCount; ++i)
        {
            cout << "이름 : " << tStudentArr[i].strName << endl;
            cout << "주소 : " << tStudentArr[i].strAddress << endl;
            cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
            cout << "국어 : " << tStudentArr[i].iKor << endl;
            cout << "영어 : " << tStudentArr[i].iEng << endl;
            cout << "수학 : " << tStudentArr[i].iMath << endl;
            cout << "총점 : " << tStudentArr[i].iTotal << endl;
            cout << "평균 : " << tStudentArr[i].fAvr << endl << endl;
        }
        break;
    
    default: 
    cout << "잘못된 값을 입력했습니다. 다시입력하세요" << endl;
    getchar();
        break;
    }
}


}