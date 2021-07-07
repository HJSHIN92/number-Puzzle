#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

enum MAIN_MENU
{
    MM_NONE,
    MM_MAP,
    MM_STORE,
    MM_INVENTORY,
    MM_EXIT
};

enum MAP_TYPE
{
    MT_NONE,
    MT_EASY,
    MT_NORMAL,
    MT_HARD,
    MT_BACK
};
 
enum JOB
{
    JOB_NONE,
    JOB_NIGHT,
    JOB_ARCHER,
    JOB_WIZARD,
    JOB_END
};

enum BATTLE
{
    BATTLE_NONE,
    BATTLE_ATTACK,
    BATTLE_BACK
};

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3

enum ITEM_TYPE
{
    IT_NONE,
    IT_WEAPON,
    IT_ARMOR,
    IT_BACK
};

enum STORE_MENU
{
    SM_NONE,
    SM_WEAPON,
    SM_ARMOR,
    SM_BACK
};

enum STORE_BUY_MENU
{
    SB_NONE,
    SB_READ,
    SB_BUY,
    SB_SELL,
    SB_BACK
};

enum STORE_WEAPON_MENU
{
    SW_NONE,
    SW_SHORT_SWORD,
    SW_SHORT_BOW,
    SW_SHORT_STICK,
    SW_BACK
};

enum STORE_ARMOR_MENU
{
    SA_NONE,
    SA_SOFT_ARMOR,
    SA_HARD_ARMOR,
    SA_LEGEND_ARMOR,
    SA_BACK
};

struct _tagItem
{
    char strName[NAME_SIZE];
    char strTypeName[NAME_SIZE];
    ITEM_TYPE eType;
    int iMin;
    int iMax;
    int iPrice;
    int iSell;
    char strDesc[ITEM_DESC_LENGTH];
};


struct _tagInventory
{
    _tagItem tItem[INVENTORY_MAX];
    int iItemCount;
    int iGold;
};

struct _tagPlayer 
{
    char strName[NAME_SIZE];
    char strJobName[NAME_SIZE];
    JOB eJob;
    int iAttackMin;
    int iAttackMax;
    int iArmorMin;
    int iArmorMax;
    int iHP;
    int iHPMax;
    int iMP;
    int iMPMax;
    int iExp;
    int iLevel;
    _tagInventory tInventory; //구조체도 변수타입!
};

struct _tagMonster
{
    char strName[NAME_SIZE];
    int iAttackMin;
    int iAttackMax;
    int iArmorMin;
    int iArmorMax;
    int iHP;
    int iHPMax;
    int iMP;
    int iMPMax;
    int iExp;
    int iLevel;
    int iGoldMin; 
    int iGoldMax;
};


int main(){
    srand((unsigned int)time(0));
    // 게임을 시작할 때 플레이어 정보를 설정하게 된다.
    _tagPlayer tPlayer = {};

    // 플레이어 이름을 입력받는다.
    cout << "이름 :";
    // \n 의 자리를 만들어주기 위해 NAME_SIZE -1 해준다.
    cin.getline(tPlayer.strName, NAME_SIZE -1);

    int iJob = JOB_NONE;
    while (iJob == JOB_NONE)
    {
        system("clear");
        cout << "1. 기사" << endl;
        cout << "2. 궁수" << endl;
        cout << "3. 마법사" << endl;
        cout << "직업을 선택하세요" << endl;
        cin >> iJob;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        else if(iJob <= JOB_NONE || iJob >= JOB_END)
            iJob = JOB_NONE;
    }
    
    tPlayer.iLevel = 1;
    tPlayer.iExp = 0;
    tPlayer.eJob = (JOB)iJob;
    tPlayer.tInventory.iGold = 10000;

    switch (tPlayer.eJob)
    {
    case JOB_NIGHT:
        strcpy(tPlayer.strJobName, "기사");
        tPlayer.iAttackMin = 5;
        tPlayer.iAttackMax = 10;
        tPlayer.iArmorMin = 15;
        tPlayer.iArmorMax = 20;
        tPlayer.iHPMax = 500;
        tPlayer.iHP = 500;
        tPlayer.iMP = 100;
        tPlayer.iMPMax = 100;
        break;
    case JOB_ARCHER:
        strcpy(tPlayer.strJobName, "궁수");
        tPlayer.iAttackMin = 10;
        tPlayer.iAttackMax = 15;
        tPlayer.iArmorMin = 10;
        tPlayer.iArmorMax = 15;
        tPlayer.iHPMax = 400;
        tPlayer.iHP = 400;
        tPlayer.iMP = 200;
        tPlayer.iMPMax = 200;
        break;
    case JOB_WIZARD:
        strcpy(tPlayer.strJobName, "마법사");
        tPlayer.iAttackMin = 15;
        tPlayer.iAttackMax = 20;
        tPlayer.iArmorMin = 5;
        tPlayer.iArmorMax = 10;
        tPlayer.iHPMax = 300;
        tPlayer.iHP = 300;
        tPlayer.iMP = 300;
        tPlayer.iMPMax = 300;
        break;
    }

    // 몬스터를 생성한다.
    _tagMonster tMonsterArr[MT_BACK -1] = {};

    // 고블린 생성
    strcpy (tMonsterArr[0].strName, "고블린");
    tMonsterArr[0].iAttackMin = 20;
    tMonsterArr[0].iAttackMax = 30;
    tMonsterArr[0].iArmorMax = 2;
    tMonsterArr[0].iArmorMin = 5;
    tMonsterArr[0].iHP = 100;
    tMonsterArr[0].iHPMax = 100;
    tMonsterArr[0].iMP = 10;
    tMonsterArr[0].iMPMax = 10;
    tMonsterArr[0].iLevel = 1;
    tMonsterArr[0].iExp =  1000;
    tMonsterArr[0].iGoldMin =  500;
    tMonsterArr[0].iGoldMax =  1500;
    // 트롤 생성
    strcpy (tMonsterArr[1].strName, "트롤");
    tMonsterArr[1].iAttackMin = 80;
    tMonsterArr[1].iAttackMax = 130;
    tMonsterArr[1].iArmorMax = 60;
    tMonsterArr[1].iArmorMin = 90;
    tMonsterArr[1].iHP = 2000;
    tMonsterArr[1].iHPMax = 2000;
    tMonsterArr[1].iMP = 100;
    tMonsterArr[1].iMPMax = 100;
    tMonsterArr[1].iLevel = 5;
    tMonsterArr[1].iExp =  7000;
    tMonsterArr[1].iGoldMin = 6000;
    tMonsterArr[1].iGoldMax =  8000;
    // 드래곤 생성
    strcpy (tMonsterArr[2].strName, "드래곤");
    tMonsterArr[2].iAttackMin = 250;
    tMonsterArr[2].iAttackMax = 500;
    tMonsterArr[2].iArmorMax = 200;
    tMonsterArr[2].iArmorMin = 400;
    tMonsterArr[2].iHP = 30000;
    tMonsterArr[2].iHPMax = 30000;
    tMonsterArr[2].iMP = 20000;
    tMonsterArr[2].iMPMax = 20000;
    tMonsterArr[2].iLevel = 10;
    tMonsterArr[2].iExp =  30000;
    tMonsterArr[2].iGoldMin = 20000;
    tMonsterArr[2].iGoldMax = 50000;

// 상점에서 판매할 아이템 목록을 생성한다.
    _tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
    _tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

// 각 아이템 정보들을 설정해준다.


    while (true)
    {
        system("clear");
        cout << " +++++++++++++++ 로비 ++++++++++++++++" << endl;
        cout << "1. 맵" << endl;
        cout << "2. 상점" << endl;
        cout << "3. 가방" << endl;
        cout << "4. 종료" << endl;
        cout << "메뉴를 선택하세요 : ";
        int iMenu;
        cin >> iMenu;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        
        if(iMenu == MM_EXIT)
            break;

        switch (iMenu)
        {
        case MM_MAP:
            while (true)
            {
                system("clear");
                cout << " +++++++++++++++ 맵 ++++++++++++++++" << endl;
                cout << "1. 쉬움 " << endl;
                cout << "2. 보통 " << endl;
                cout << "3. 어려움 " << endl;
                cout << "4. 뒤로가기 " << endl;
                cout << "맵을 선택하세요 :";
                cin >> iMenu;

                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }

                // 이 if문에 속한 break는 맵 메뉴를 돌려주기 위한
                // while에 속해있으므로 이 while문을 빠져나간다.
                if(iMenu == MT_BACK)
                    break;
                
                // 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
                // 그렇게 해서 해당 맵의 몬스터를 생성한다.
                _tagMonster tMonster = tMonsterArr[iMenu -1];

                while (true)
                {
                    system("clear");
                    switch (iMenu)
                    {
                    case MT_EASY:
                        cout << " +++++++++++++++ 쉬움 ++++++++++++++++" << endl;
                        break;
                    case MT_NORMAL:
                        cout << " +++++++++++++++ 보통 ++++++++++++++++" << endl;
                        break;
                    case MT_HARD:
                        cout << " +++++++++++++++ 어려움 ++++++++++++++++" << endl;
                        break;
                    }
                    
                    //플레이어 정보를 출력한다.
                    cout << "이름 : " << tPlayer.strName << "\t직업 : " <<
                        tPlayer.strJobName << endl;
                    cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : "<<
                        tPlayer.iExp << endl;
                    cout << "공격력 :" << tPlayer.iAttackMin << " - " <<
                        tPlayer.iAttackMax << "\t방어력 : " << tPlayer.iArmorMin <<
                        " - " << tPlayer.iArmorMax << endl;
                    cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
                        "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax<< endl;
                    cout << "보유 골드 : " << tPlayer.tInventory.iGold << "골드" << endl << endl;

                    // 몬스터 정보 출력
                    cout << "============== Monster ===============" << endl;
                    cout << "이름 : " << tMonster.strName << "레벨 : " << 
                    tPlayer.iLevel << endl;
                    cout << "공격력 :" << tMonster.iAttackMin << " - " <<
                        tMonster.iAttackMax << "\t방어력 : " << tMonster.iArmorMin <<
                        " - " << tPlayer.iArmorMax << endl;
                    cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax <<
                        "\t마나 : " << tMonster.iMP << " / " << tMonster.iMPMax<< endl;
                    cout << "획득 경험치 : " << tMonster.iExp << "\t획득 골드 : " <<
                     tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl << endl;

                cout << " 1. 공격 " << endl;
                cout << " 2. 도망 " << endl;
                cout << "메뉴를 선택하세요" << endl;
                cin >> iMenu;

                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }

                else if(iMenu == BATTLE_BACK)
                    break;

                switch (iMenu)
                {
                
                case BATTLE_ATTACK:
                {
                    // max = 15, min = 5일 때 max-min = +1 => (11) => ( 0 ~ 10)
                    // 여기서 + min 해주면 ( 5 ~ 15 )
                    int iAttack = rand()% (tPlayer.iAttackMax - tPlayer.iAttackMin + 1)
                                         + (tPlayer.iAttackMin);
                    int iArmor = rand()% (tMonster.iArmorMax - tMonster.iArmorMin + 1)
                                        + (tMonster.iArmorMin);

                    int iDamage = iAttack - iArmor;
                    // 삼항연산자 : 조건식 ? true일 때 값 : false일 때 값;
                    iDamage = iDamage < 1 ? 1 : iDamage;

                    // 몬스터 hp를 감소시킨다.
                    tMonster.iHP -= iDamage;
                    cout << tPlayer.strName <<"가" << tMonster.strName <<
                    "에게" << iDamage << "피해를 입혔습니다." << endl;
                    getchar();

                    // 몬스터 사망
                    if(tMonster.iHP <= 0)
                    {
                        cout << tMonster.strName << "몬스터가 사망하였습니다" << endl;

                        tPlayer.iExp += tMonster.iExp;
                        int iGold = (rand()% (tMonster.iGoldMax - tMonster.iGoldMin + 1)
                                                            + tMonster.iGoldMin);
                        tPlayer.tInventory.iGold += iGold;

                        cout << tMonster.iExp << "경험치를 획득하였습니다." << endl;
                        cout << iGold << "골드를 획득하였습니다" << endl;

                        // 몬스터의 최대 hp, mp를 다시 복구한다
                        tMonster.iHP = tMonster.iHPMax;
                        tMonster.iMP = tMonster.iMPMax;

                        getchar();
                        break;                                
                    }

                    // 몬스터가 살아있다면 플레이어를 공격한다.
                    iAttack = rand()% (tMonster.iAttackMax - tMonster.iAttackMin + 1)
                                         + (tMonster.iAttackMin);
                    iArmor = rand()% (tPlayer.iArmorMax - tPlayer.iArmorMin + 1)
                                        + (tPlayer.iArmorMin);

                    iDamage = iAttack - iArmor;
                    // 삼항연산자 : 조건식 ? true일 때 값 : false일 때 값;
                    iDamage = iDamage < 1 ? 1 : iDamage;

                    // 플레이어의 HP를 감소시킨다.
                    tPlayer.iHP -= iDamage;
                    cout << tMonster.strName <<"가 " << tPlayer.strName <<
                    "에게 " << iDamage << " 피해를 입혔습니다." << endl;
                    getchar();
                    // 플레이어가 죽었을 경우
                    if(tPlayer.iHP <= 0)
                    {
                        cout << tPlayer.strName << "플레이어가 사망하였습니다" << endl;
                        int iExp = tPlayer.iExp * 0.1f;
                        int iGold = tPlayer.tInventory.iGold * 0.1f;

                        tPlayer.iExp -= iExp;
                        tPlayer.tInventory.iGold -= iGold;

                        cout << iExp << "경험치를 잃었습니다" << endl;
                        cout << iGold << "Gold를 잃었습니다" << endl;


                        // 플레이어의 최대 hp, mp를 다시 복구한다
                        tPlayer.iHP = tPlayer.iHPMax;
                        tPlayer.iMP = tPlayer.iMPMax;

                    }
                        break;

                }
                    break;

                default:
                    break;
                }

                }
                
            }
            // 이 브레이크는 switch 문을 빠져나간다.
            break;
        case MM_STORE:
            while (true)
            {
                system("clear");
                cout << "============== 상점 ===============" << endl;
                cout << "1. 무기상점" << endl;
                cout << "2. 방어구 상점" << endl;
                cout << "3. 뒤로가기" << endl;
                cout << "상점을 선택하세요" << endl;

                cin >> iMenu;

                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }

                else if (iMenu == SM_BACK)
                {
                    break;
                }

                _tagItem tStoreItmes = {};
                
                switch (iMenu)
                {
                case SM_WEAPON:
                    while (true)
                    {
                        system("clear");
                        cout << "============== 무기 상점 ===============" << endl;
                        // 판매 목록을 보여준다
                        cout<<  "1. 숏소드 "<< endl;
                        cout<<  "2. 숏보우"<< endl;
                        cout<<  "3. 숏스틱"<< endl;
                        cout<<  "4. 뒤로가기"<< endl;
                        cout << " 메뉴를 골라주세요 " << endl;
                        cin >> iMenu;

                        if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }

                        if(iMenu == SW_BACK)
                            break;
                        
                        switch (iMenu)
                        {
                        case SW_SHORT_SWORD:
                            strcpy(tStoreItmes.strName, "숏 소드");
                            strcpy(tStoreItmes.strTypeName, "한손검");
                            tStoreItmes.eType = IT_WEAPON;
                            tStoreItmes.iMin = 20;
                            tStoreItmes.iMax = 40;
                            tStoreItmes.iPrice = 7000;
                            tStoreItmes.iSell = 3500;
                            strcpy(tStoreItmes.strDesc, "기사가 사용할 수 있는 한손 검이다. 가격이 저렴하다");

                            cout << "장비 이름 : " << tStoreItmes.strName << endl;
                            cout << "장비 타입 : " << tStoreItmes.strTypeName << endl;
                            cout << "최소 데미지 : " << tStoreItmes.iMin << endl;
                            cout << "최대 데미지 : " << tStoreItmes.iMax << endl;
                            cout << "살 때 가격 : " << tStoreItmes.iPrice << endl;
                            cout << "팔 때 가격 : " << tStoreItmes.iSell << endl << endl;

                            cout << "장비착용 전 후 비교"<< endl;
                            cout << "공격력(전) : " << tPlayer.iAttackMin << " ~ " << tPlayer.iAttackMax << endl;
                            cout << "공격력(후) : " << tPlayer.iAttackMin + tStoreItmes.iMin << " ~ " << tPlayer.iAttackMax + tStoreItmes.iMax << endl << endl << endl;

                            cout <<"현재 소지금액 :" << tPlayer.tInventory.iGold << endl;
                            cout << " 1. 구매한다 " << endl;
                            cout << " 2. 판매한다 " << endl;
                            cout << " 3. 뒤로가기 " << endl;
                            cin >> iMenu;

                            if(iMenu == 1)
                            {
                                if(tPlayer.tInventory.iGold >= tStoreItmes.iPrice)
                                {
                                    tPlayer.tInventory.iGold -= tStoreItmes.iPrice;
                                    cout << "물건을 구매했습니다. 현재 골드 : " << tPlayer.tInventory.iGold << endl;
                                    ++tPlayer.tInventory.iItemCount;
                                    // tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount];
                                    cout << "다음과 같은 능력치 변화가 있었습니다" << endl;
                                    tPlayer.iAttackMin += tStoreItmes.iMin;
                                    tPlayer.iAttackMax += tStoreItmes.iMax;
                                    cout << "공격력 : " << tPlayer.iAttackMin << " ~ " << tPlayer.iAttackMax << endl;
 
                                    cout << "다시 상점으로 돌아가려면 1을 눌러주세요"<< endl;
                                    cin >> iMenu;
                                    if(iMenu == 1)
                                        continue;
                                }
                                else if(tPlayer.tInventory.iGold < tStoreItmes.iPrice)
                                {
                                    cout << "골드가 부족합니다 "<< endl;
                                    cout << "다시 상점으로 돌아가려면 1을 눌러주세요"<< endl;
                                    cin >> iMenu;
                                    if(iMenu == 1)
                                        continue;
                                }
                            }

                        case SW_SHORT_BOW:
                            /* code */
                            break;
                        case SW_SHORT_STICK:
                            /* code */
                            break;
                        
                        default:
                            break;
                        }
                        
                        
                    }
                    
                    break;

                case SM_ARMOR:
                    /* code */
                    break;
                
                default:
                    break;
                }

            }
            
            break;
        case MM_INVENTORY:
            while (true)
            {
                system("clear");
                cout << "============== 인벤토리 ===============" << endl;
                cout << "1. 가방을 본다" << endl;
                cout << "2. 뒤로가기" << endl;
                cin >> iMenu;

                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }

                if(iMenu == 1)
                {
                system("clear");
                cout << "현재 인벤토리 : " << tPlayer.tInventory.iItemCount << " / " << INVENTORY_MAX << endl;
                cout << "아이템 목록" << endl;
                 _tagItem tItem[INVENTORY_MAX]= {};

                // for(int i = 0; i < INVENTORY_MAX; ++i)
                // {
                //     cout << i << "번째 " << tPlayer.tInventory.tItem[i] << endl;
                // }

                cout << "뒤로 가려면 1을 눌러주세요" << endl;
                cin >> iMenu;
                if(iMenu==1)
                {
                    continue;
                }}else if(iMenu==2)
                {
                    break;
                }


                

            }
            
            break;
        
        default:
            cout << "잘못 선택했습니다. 다시 골라주세요" << endl;
            break;
        }
    }
    
}