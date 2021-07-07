#include <iostream>

using namespace std;

// 문자열 크기
#define NAME_SIZE 32
#define ADDRESS_SIZE 128 
#define PHONE_SIZE 14

#define STUDENT_MAX 10 // 최대 10명

struct  _tagStudent
{
    char strName[NAME_SIZE];
    char strAddress[ADDRESS_SIZE];
    char strPhoneNumber[PHONE_SIZE];
    int iNumber;
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
    _tagStudent tStudentArr[STUDENT_MAX] = {};
    // 배열에 추가된 개수를 저장할 변수를 만들어준다.
    int iStudentCount = 0;
    int iStdNumber = 1;

    char strName[NAME_SIZE] = {};

    while (true)
    {
        // system("clear");

        //메뉴를 출력한다.
        cout << "1. 학생등록" << endl;
        cout << "2. 학생삭제" << endl;
        cout << "3. 학생탐색" << endl;
        cout << "4. 학생출력" << endl;
        cout << "5. 종료" << endl;
        cout << "메뉴를 선택하세요 :" ;
        int iMenu;
        cin >> iMenu;

/*
        cin : 오른쪽에 해당 자료형이 아닌 값이 오면 에러 발생.
        (ex) int변수여서 정수를 넣어줘야하는데 문자가 들어가는 경우)
        그렇기에 예외처리로 에러가 발생했는지를 여기에서 체크하여 
        에러가 발생하면 cin 내부의 에러버퍼를 비워주고
        cin 내부에 입력버퍼가 있는데 입력버퍼는 입력한 값을 저장 후
        그 값을 변수에 넣어주는 역할을 한다.

        이 입력버퍼에 \n이 남아있으므로 버퍼를 순회하여 \n을 지워준다.
        버퍼: 임시저장공간
        먼저 에러를 체크한다. cin.fail()을 했을 때 
        입력에러가 발생하면 true를 반환한다.
*/
    if(cin.fail()) // "입력실패"가 true인 경우 if문 반환
    {
        // 에러버퍼를 비워준다.
        cin.clear();
        cout << "========== 학생추가 =========" << endl;

        // 등록학생 수 최대치일 경우 더이상 등록되지 않게한다.
        if(iStudentCount == STUDENT_MAX)
            break;

        // 입력버퍼에 \n이 남아있으므로 입력버퍼를 검색하여 \n을 지워준다.

        // cin.ignore( , );
        // 첫번째는 검색하고자하는 버퍼 크기를 지정한다.
        // 넉넉하게 1024byte정도 지정해주었다.
        // 2번째는 찾고자하는 문자를 넣어준다.
        // 그래서 입력버퍼 처음부터 \n이 있는 곳까지 찾아서
        // 그 부분을 모두 지워주어 다시 입력받을 수 있도록 해준다.
        cin.ignore(1024, '\n');
        continue;
    }
    
    // 종료문은 if문으로. switch break는 switch문만 탈출.
        if(iMenu == MENU_EXIT)
            break;
        
        switch (iMenu)
        {
        case MENU_INSERT:
            cout << "======== 학생추가 ==========" << endl;
            // 학생정보를 추가한다. 학생정보는 이름, 주소, 전화번호
            // 국어, 영어, 수학점수는 입력받고 
            // 학번, 총점, 평균은 연산을 통해 계산해준다.
            // 이름을 입력받는다.
            cout << "이름 : ";
            cin >> tStudentArr[iStudentCount].strName;
            // ignore로 엔터 삭제
            // cin과 ignore 사이에 넣어주어야 한다.
            cin.ignore(1024, '\n');
            cout << "주소 :";
            // getling : 스페이스바까지 인식하게함
            cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

            cout << "전화번호 :";
            cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);
            
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
            tStudentArr[iStudentCount].fAvg =
                tStudentArr[iStudentCount].iTotal / 3.f;
            
            tStudentArr[iStudentCount].iNumber = iStdNumber;

            ++iStdNumber;
            ++iStudentCount;

            cout << "학생 추가 완료" << endl;
            break;
        case MENU_DELETE:
            system("clear");
            cout << "========== 학생탐색 =========" << endl;
            cin.ignore(1024, '\n');
            cout << "삭제할 이름을 입력하세요 : " ;
            cin.getline(strName, NAME_SIZE);
            
            for(int i = 0; i < iStudentCount; ++i)
            {
                // 학생을 찾았을 경우
                if(strcmp(tStudentArr[i].strName, strName) == 0)
                {
                    for(int j = i; j < iStudentCount -1; ++j)
                    {
                        tStudentArr[i] = tStudentArr[i + 1];
                    }
                    --iStudentCount;

                    cout << " 학생이 삭제되었습니다" << endl;
                    break;
                }
            }
            break;
        case MENU_SEARCH:
            system("clear");
            cout << "========== 학생탐색 =========" << endl;

        // case 안에 선언과 동시에 초기화를 하는 경우
        // 문제가 발생될 소지가 있으므로 switch 밖에서 선언한다.
            // char strName[NAME_SIZE] = {};

            cin.ignore(1024, '\n');
            cout << "탐색할 이름을 입력하세요 : " ;
            cin.getline(strName, NAME_SIZE);

            // 등록되어있는 학생 수만큼 반복하여 학생을 찾는다.
            for(int i = 0; i < iStudentCount; ++i)
            {
                // 학생을 찾았을 경우
                if(strcmp(tStudentArr[i].strName, strName) == 0)
                {
                cout << "이름 : " << tStudentArr[i].strName << endl;
                cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
                cout << "주소 : " << tStudentArr[i].strAddress << endl;
                cout << "학번 : " << tStudentArr[i].iNumber << endl;
                cout << "국어 : " << tStudentArr[i].iKor << endl;
                cout << "영어 : " << tStudentArr[i].iEng << endl;
                cout << "수학 : " << tStudentArr[i].iMath << endl;
                cout << "총점 : " << tStudentArr[i].iTotal << endl;
                cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
                break;
                }
            }

            break;
        case MENU_OUTPUT:
            // system("clear");

            cout << "=======학생출력=======" << endl;
            // 등록된 학생 수만큼 반복하며 학생정보 출력
            for(int i = 0; i < iStudentCount; ++i)
            {
                cout << "이름 : " << tStudentArr[i].strName << endl;
                cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
                cout << "주소 : " << tStudentArr[i].strAddress << endl;
                cout << "학번 : " << tStudentArr[i].iNumber << endl;
                cout << "국어 : " << tStudentArr[i].iKor << endl;
                cout << "영어 : " << tStudentArr[i].iEng << endl;
                cout << "수학 : " << tStudentArr[i].iMath << endl;
                cout << "총점 : " << tStudentArr[i].iTotal << endl;
                cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
            }
            break;
        
        default:
                cout << "메뉴를 잘못입력했습니다. 아무키나 누르세요" << endl;
                getchar(); // system pause 대체
            break;
        }
        // getchar();
    }
    


}


/*
관리프로그램 만들기
도서대여 프로그램 만들기
1. 책등록
2. 책 대여
3. 책 반납
4. 책 목록
5. 종료

책 구조체는 이름, 대여금액, 책 번호, 대여여부가 필요하다.
책 목록을 선택하면 책 정보를 출력한다.
*/
