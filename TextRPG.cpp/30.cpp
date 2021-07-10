#include <iostream>
using namespace std;

struct _tagStudent
{
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvg;
};

int main(){
/*
포인터 : 가리키다.
일반 변수는 일반적인 값을 저장하게 되지만
포인터 변수는 메모리 주소를 저장하게 된다.
모든 변수 타입은 포인터 타입을 선언할 수 있다.
int 변수의 주소는 int 포인터 변수에 저장을 해야한다.
포인터는 메모리 주소를 담아놓는 변수이기 때문에
x86으로 개발할 때는 무조건 4byte가 나온다.
x64일 때는 8byte.
(VSC에서는 64)

포인터는 자기스스로 아무런 일도 할 수 없다.
반드시 다른 변수의 메모리주소를 가지고 있어야하며,
가지고 있는 메모리주소에 접근해서 값을 제어한다.

형태 : 변수타입 * 변수명

*/
int iNumber = 100;

// 변수 선언 시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.
// 변수 앞에 &을 붙여주면 해당 변수의 메모리 주소가 된다.
// pNum은 iNumber 변수의 메모리 주소를 갖게 됐다.
// pNum을 이용해서 iNumber 값을 제어할 수 있다.
int * pNum = &iNumber;

cout << sizeof(*pNum) << endl; //4
cout << sizeof(int*) << endl;  //8
cout << sizeof(char*) << endl; //8
cout << sizeof(double*) << endl << endl; //8

// pNum을 이용해서 iNumber의 값을 제어해본다.
// 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
// 역참조는 포인터변수 앞에 *을 붙이게 되면 역참조가 된다.
cout << *pNum << endl; // 100
*pNum = 1234;

cout << iNumber << endl; // 1234
cout << &iNumber << endl; //0x16ef4b66c
cout << pNum << endl; //0x16ef4b66c
cout << &pNum << endl; //0x16ef4b660


/*
포인터와 배열의 관계 : 배열명은 포인터다.
배열명 자체가 해당 배열 메모리에서의 시작점 주소를 의미.
*/
int iArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
cout << iArray << endl; //0x16fa93640
cout << &iArray[0] << endl; //0x16fa93640

int *pArray = iArray;
cout << pArray[2] << endl; //3

/*
포인터 연산 : +. - 연산을 제공한다.
++, --도 가능한데 1을 증가하게 되면
단순히 메모리주소값이 1 증가하는 것이 아니다.

int 포인터의 경우 int 타입의 메모리주소를 갖게되는데
메모리주소에 1을 더해주면 1 증가가 아닌
가리키는 해당 포인터타입의 변수타입 크기만큼 증가한다.
int 포인터의 경우 Int 크기인 4가 증가한다.
*/
cout << pArray << endl;        // 0x16fabb640
cout << pArray + 2 << endl;    // 0x16fabb648
cout << *pArray << endl;       // 1
cout << *(pArray + 2) << endl; // 3
cout << *pArray + 100 << endl; // 101

// 변경될 여지가 없을 때만 이렇게 쓴다.
// 문자열은 배열로 나타내어 사용한다.
char *pText = "테스트문자열"; 
cout << pText << endl; //테스트문자열
cout << (int*)pText << endl; //0x100a9bef4




//구조체 포인터

_tagStudent tStudent = {};
tStudent.iKor = 100;

_tagStudent *pStudent = &tStudent;
// 연산자 우선순위 때문에 .을 먼저 인식하게 된다.
// 메모리주소. 은 잘못된 문법이다.
// 때문에 *pStudent를 괄호로 감싸준 후에
// .을 이용해서 가리키는 대상의 멤버변수에 접근한다.
(*pStudent).iKor = 50;

// 메모리주소->를 이용해서 가리키는 멤버변수에 접근할 수 있다.
pStudent->iKor = 80;

cout << tStudent.iKor << endl;




// void 포인터
// void : 타입이 없다.
// void* 변수를 선언하게 되면
// 어떤 타입의 메모리주소든 모두 저장가능하다.
// 단, 역참조가 불가능하고 메모리주소만 저장가능하다.

void* pVoid = &iNumber;
cout << pVoid << endl;


// *pVoid =10;
int* pConvert = (int*)pVoid;
//*pConvert = 101010;
 *((int*)pVoid) = 101010; // 위 코드와 같다.
cout << iNumber << endl; // 101010

pVoid = &tStudent;

cout << "tStudent address : " << pVoid << endl;

int iNumber1 =  1111;
iNumber = 2222;
pNum = &iNumber;

// 이중포인터 : *을 2개 붙인다. 
// 일반 포인터변수가 일반 변수의 메모리주소를 저장하는 포인터라면
// 이중포인터는 포인터의 포인터이다.
// 즉, 이중포인터는 포인터변수의 메모리주소를 저장하는 포인터이다.

int **ppNum = &pNum;
*pNum = 3333;

cout << iNumber << endl; // 3333
cout << &iNumber << endl; // 주소1 
cout << *pNum << endl; // 3333
cout << pNum << endl; // 주소1
cout << &pNum << endl; // 주소2

cout << ppNum << endl; // 주소2
cout << *ppNum << endl; // 주소1
cout << **ppNum << endl; // 3333
}