#include <iostream>
#include <time.h>
#include <stdlib.h>

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

enum CLASS
{
	CLASS_NONE,
	CLASS_KNIGHT,
	CLASS_ARCHER,
	CLASS_WIZARD,
	CLASS_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

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

enum STORE_MENU_2
{
	SM2_NONE,
	SM2_LIST1,
	SM2_LIST2,
	SM2_LIST3,
	SM2_BACK
};

#define NAME_SIZE			32
#define ITEM_DESC_LENGTH	512
#define INVENTORY_MAX		6
#define STORE_WEAPON_MAX	3
#define STORE_ARMOR_MAX		3

struct _tagItem
{
	char	  name[NAME_SIZE];
	char	  typeName[NAME_SIZE];
	ITEM_TYPE type;
	int		  min;
	int		  max;
	int		  price;
	int		  sell;
	char	  description[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem itemArr[INVENTORY_MAX];
	int		itemCount;
	int		gold;
	_tagItem weapon;
	_tagItem armor;
};

struct _tagPlayer
{
	char	name[NAME_SIZE];
	char	className[NAME_SIZE];
	CLASS	Class;
	int		attackMin;
	int		attackMax;
	int		armorMin;
	int		armorMax;
	int		hp;
	int		hpMax;
	int		mp;
	int		mpMax;
	int		exp;
	int		level;
	_tagInventory inventory;
};


struct _tagMonster
{
	char	name[NAME_SIZE];
	int		attackMin;
	int		attackMax;
	int		armorMin;
	int		armorMax;
	int		hp;
	int		hpMax;
	int		mp;
	int		mpMax;
	int		level;
	int		exp;
	int		goldMin;
	int		goldMax;

};

int main()
{
	srand((unsigned int)time(0));

	// 플레이어 정보 설정
	_tagPlayer player = {};

	cout << "이름 : ";
	cin.getline(player.name, NAME_SIZE - 1);

	int selectedClass = CLASS_NONE;
	while (true)
	{
		system("clear");
		cout << "1. 기사" << endl;
		cout << "2. 궁사" << endl;
		cout << "3. 마법사" << endl;
		cout << "클래스를 고르시오 : ";
		cin >> selectedClass;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (selectedClass <= CLASS_NONE || selectedClass >= CLASS_END)
		{
			selectedClass = CLASS_NONE;
			continue;
		}
		
		break;
	}
	
	player.level = 1;
	player.exp = 0;
	player.inventory.gold = 1000000;
	player.Class = (CLASS)selectedClass;

	
	switch (player.Class)
	{
	case CLASS_KNIGHT:
		strcpy(player.className, "기사");
		player.attackMin = 5;
		player.attackMax = 10;
		player.armorMin = 15;
		player.armorMax = 20;
		player.hpMax = 500;
		player.hp = 500;
		player.mpMax = 100;
		player.mp = 100;
		break;
	case CLASS_ARCHER:
		strcpy(player.className, "궁수");
		player.attackMin = 10;
		player.attackMax = 15;
		player.armorMin = 10;
		player.armorMax = 15;
		player.hpMax = 400;
		player.hp = 400;
		player.mpMax = 200;
		player.mp = 200;
		break;
	case CLASS_WIZARD:
		strcpy(player.className, "마법사");
		player.attackMin = 15;
		player.attackMax = 20;
		player.armorMin = 5;
		player.armorMax = 10;
		player.hpMax = 300;
		player.hp = 300;
		player.mpMax = 300;
		player.mp = 300;
		break;
	}

	// 몬스터 생성
	_tagMonster	monsterArr[MT_BACK - 1] = {};

	// 고블린 생성
	strcpy(monsterArr[0].name, "고블린");
	monsterArr[0].attackMin = 20;
	monsterArr[0].attackMax = 30;
	monsterArr[0].armorMin = 2;
	monsterArr[0].armorMax = 5;
	monsterArr[0].hpMax = 100;
	monsterArr[0].hp = 100;
	monsterArr[0].mpMax = 10;
	monsterArr[0].mp = 10;
	monsterArr[0].level = 1;
	monsterArr[0].exp = 10;
	monsterArr[0].goldMin = 500;
	monsterArr[0].goldMax = 800;

	// 트롤
	strcpy(monsterArr[1].name, "트롤");
	monsterArr[1].attackMin = 80;
	monsterArr[1].attackMax = 130;
	monsterArr[1].armorMin = 60;
	monsterArr[1].armorMax = 90;
	monsterArr[1].hpMax = 2000;
	monsterArr[1].hp = 2000;
	monsterArr[1].mpMax = 100;
	monsterArr[1].mp = 100;
	monsterArr[1].level = 5;
	monsterArr[1].exp = 80;
	monsterArr[1].goldMin = 4000;
	monsterArr[1].goldMax = 7000;

	// 드래곤
	strcpy(monsterArr[2].name, "드래곤");
	monsterArr[2].attackMin = 250;
	monsterArr[2].attackMax = 500;
	monsterArr[2].armorMin = 200;
	monsterArr[2].armorMax = 400;
	monsterArr[2].hpMax = 30000;
	monsterArr[2].hp = 30000;
	monsterArr[2].mpMax = 20000;
	monsterArr[2].mp = 20000;
	monsterArr[2].level = 10;
	monsterArr[2].exp = 30000;
	monsterArr[2].goldMin = 30000;
	monsterArr[2].goldMax = 70000;

	// 상점에서 판매할 아에팀 목록을 생성한다.

	// 무기 리스트
	_tagItem	storeWeaponArr[STORE_WEAPON_MAX] = {};
	// 요우무의 단검
	strcpy(storeWeaponArr[0].name, "요우무의 단검");
	strcpy(storeWeaponArr[0].typeName, "무기");
	storeWeaponArr[0].type = IT_WEAPON;
	storeWeaponArr[0].min = 100;
	storeWeaponArr[0].max = 500;
	storeWeaponArr[0].price = 1000;
	storeWeaponArr[0].sell = storeWeaponArr[0].price * 0.6f;
	strcpy(storeWeaponArr[0].description, 
		"요우무라는 장인이 발레리안 스틸로 만든 고급 단검"
	);
	// 슈렐리아의 장검
	strcpy(storeWeaponArr[1].name, "슈렐리아의 장검");
	strcpy(storeWeaponArr[1].typeName, "무기");
	storeWeaponArr[1].type = IT_WEAPON;
	storeWeaponArr[1].min = 1000;
	storeWeaponArr[1].max = 1500;
	storeWeaponArr[1].price = 20000;
	storeWeaponArr[1].sell = storeWeaponArr[1].price * 0.6f;
	strcpy(storeWeaponArr[1].description,
		"슈렐리아라는 나라에서 황실 경비병들이 사용하는 무기"
	);
	// 레이피어
	strcpy(storeWeaponArr[2].name, "레이피어");
	strcpy(storeWeaponArr[2].typeName, "무기");
	storeWeaponArr[2].type = IT_WEAPON;
	storeWeaponArr[2].min = 2000;
	storeWeaponArr[2].max = 3000;
	storeWeaponArr[2].price = 500000;
	storeWeaponArr[2].sell = storeWeaponArr[2].price * 0.6f;
	strcpy(storeWeaponArr[2].description,
		"요정족이 만들었다고 소문으로만 전해지는 전설의 검. 가벼운 것이 특징"
	);

	// 갑옷 리스트
	_tagItem	storeArmorArr[STORE_WEAPON_MAX] = {};
	// 징박힌 갑옷
	strcpy(storeArmorArr[0].name, "징박힌 값옷");
	strcpy(storeArmorArr[0].typeName, "갑옷");
	storeArmorArr[0].type = IT_ARMOR;
	storeArmorArr[0].min = 105;
	storeArmorArr[0].max = 505;
	storeArmorArr[0].price = 1005;
	storeArmorArr[0].sell = storeWeaponArr[0].price * 0.6f;
	strcpy(storeArmorArr[0].description,
		"고급 가죽 갑옷에 징을 박아 방어력을 더함"
	);
	// 판금 갑옷
	strcpy(storeArmorArr[1].name, "판금 갑옷");
	strcpy(storeArmorArr[1].typeName, "갑옷");
	storeArmorArr[1].type = IT_ARMOR;
	storeArmorArr[1].min = 1005;
	storeArmorArr[1].max = 1505;
	storeArmorArr[1].price = 20005;
	storeArmorArr[1].sell = storeArmorArr[1].price * 0.6f;
	strcpy(storeArmorArr[1].description,
		"판금으로 만들어진 갑옷"
	);
	// 드래곤 스케일 갑옷
	strcpy(storeArmorArr[2].name, "레이피어");
	strcpy(storeArmorArr[2].typeName, "갑옷");
	storeArmorArr[2].type = IT_ARMOR;
	storeArmorArr[2].min = 2005;
	storeArmorArr[2].max = 3005;
	storeArmorArr[2].price = 500005;
	storeArmorArr[2].sell = storeArmorArr[2].price * 0.6f;
	strcpy(storeArmorArr[2].description,
		"전설의 용을 잡아 그 가죽으로 만든 갑옷"
	);

	

	// 메인 화면
	while (true)
	{
		system("clear");
		cout << endl << "========== 메인 메뉴 ==========" << endl << endl;
		cout << "1. 지도 " << endl;
		cout << "2. 상점 " << endl;
		cout << "3. 가방 " << endl;
		cout << "4. 종료 " << endl;
		cout << "메뉴를 선택하세요 : ";
		int menu;
		cin >> menu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (menu == MM_EXIT)
		{
			break;
		}

		switch (menu)
		{
		case MM_MAP:
			while (true)
			{
				system("clear");
				cout << endl << "========== 맵 종류 ==========" << endl<< endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 : ";
				cin >> menu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (menu == MT_BACK)
				{
					// 맵 선택 화면에서 빠져나간다
					break;
				}

				// 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
					// 이렇게 해당 맵의 몬스터를 설정
				_tagMonster monster = monsterArr[menu - 1];

				// 전투
				while (true)
				{
					system("clear");
					switch(menu)
					{
					case MT_EASY:
						cout << "********** 쉬움 **********" << endl;
						break;
					case MT_NORMAL:
						cout << "********** 보통 **********" << endl;
						break;
					case MT_HARD:
						cout << "********** 어려움 **********" << endl;
						break;
					}

					// 플레이어 정보를 출력
					cout << "========== 플레이어 ==========" << endl;
					cout << "이름 : " << player.name << "\t직업 : " << player.className << endl;
					cout << "레벨 : " << player.level << "\t경험치 : " << player.exp << endl;
					cout << "공격력 : " << player.attackMin << " ~ " << player.attackMax << endl;
					cout << "방어력 : " << player.armorMin << " ~ " << player.armorMax << endl;
					cout << "체력 : " << player.hp << " / " << player.hpMax << "\t마나 : " << player.mp << " / " << player.mpMax << endl;
					cout << "소지금 : " << player.inventory.gold << endl << endl;

					// 몬스터 정보를 출력
					cout << "========== 몬스터 ==========" << endl;
					cout << "이름 : " << monster.name << "\t레벨 : " << monster.level << endl;
					cout << "공격력 : " << monster.attackMin << " ~ " << monster.attackMax << endl;
					cout << "방어력 : " << monster.armorMin << " ~ " << monster.armorMax << endl;
					cout << "체력 : " << monster.hp << " / " << monster.hpMax << "\t마나 : " << monster.mp << " / " << monster.mpMax << endl;
					cout << "획득 경험치 : " << monster.exp << "\t획득 골드 : " << monster.goldMin << " ~ " << monster.goldMax << endl << endl;

					cout << "========== 행동 ==========" << endl;
					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "행동을 선택하세요." << endl;
					cin >> menu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (menu == BATTLE_BACK)
					{
						break;
					}

					switch (menu)
					{
					case BATTLE_ATTACK:
						int attack = rand() % (player.attackMax - player.attackMin + 1) + (player.attackMin);
						int armor = rand() % (monster.armorMax - monster.armorMin + 1) + (monster.armorMin);

						int damage = attack - armor;

						// 삼항연산자 : 조건식 ? true일 때 값, : false 일 때 값이 된다.
						// 최소 데미지를 음수가 되지 않고 1로 설정
						damage = damage < 1 ? 1 : damage;

						// 몬스터 HP를 감소시킨다.
						monster.hp -= damage;

						cout << player.name << "가 " << monster.name << "에게 " << damage << "의 피해를 입혔습니다." << endl;

						// 몬스터가 죽음
						if (monster.hp <= 0)
						{
							cout << monster.name << " 몬스터가 사망하였습니다." << endl;

							player.exp += monster.exp;
							int gold = (rand() % monster.goldMax - monster.goldMin + 1) + monster.goldMin;
							player.inventory.gold += gold;

							cout << monster.exp << "의 경험치를 획득하였습니다." << endl;
							cout << gold << "의 골드를 획득하였습니다." << endl;

							// 몬스터 스탯을 초기화
							monster.hp = monster.hpMax;
							monster.mp = monster.mpMax;

							system( "read -n 1 -s -p \"Press any key to continue...\"" );
							break;
						}

						// 몬스터가 살아있으면 플레이어를 공격
						attack = rand() % (monster.attackMax - monster.attackMin + 1) + (monster.attackMin);
						armor = rand() % (player.armorMax - player.armorMin + 1) + (player.armorMin);

						damage = attack - armor;

						damage = damage < 1 ? 1 : damage;

						// 플레이어 HP를 감소시킨다.
						player.hp -= damage;

						cout << monster.name << "가 " << player.name << "에게 " << damage << "의 피해를 입혔습니다." << endl;

						// 플레이어가 죽었을 경우
						if (player.hp <= 0)
						{
							cout << "플레이어가 " << monster.name << "에게 사망하였습니다." << endl;

							// 죽으면 경험치와 골드가 10% 깎인다
							cout << (player.exp * 0.1f) << "경험치를 잃었습니다." << endl;
							cout << (player.inventory.gold * 0.1f) << "골드를 잃었습니다." << endl;
							
							player.exp = player.exp - (player.exp * 0.1f);
							player.inventory.gold = player.inventory.gold - (player.inventory.gold * 0.1f);

							// 플레이어 부활
							player.hp = player.hpMax;
							player.mp = player.mpMax;
						}
						system( "read -n 1 -s -p \"Press any key to continue...\"" );

						break;
					}
				}
			}
			break;
		case MM_STORE:
			while (true)
			{
				system("clear");

				cout << "========== 상점 ==========" << endl;
				cout << "1. 무기 상점" << endl;
				cout << "2. 방어구 상점" << endl;
				cout << "3. 뒤로 가기" << endl;
				cout << "상점을 선택하세요 : ";
				cin >> menu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (menu == SM_BACK)
				{
					break;
				}
 					
				else if (menu < SM_NONE || menu > SM_BACK)
				{
					cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
					system( "read -n 1 -s -p \"Press any key to continue...\"" );
					continue;
				}				

				switch (menu)
				{
				case SM_WEAPON:
					while (true)
					{
						system("clear");
						cout << "=========== 무기 상점 ==========" << endl;
						for (int i = 0; i < STORE_WEAPON_MAX; ++i)
						{
							cout << i + 1 << "번 무기 : " << storeWeaponArr[i].name << endl;
							cout << "공격력 : " << storeWeaponArr[i].min << " ~ " << storeWeaponArr[i].max << endl;
							cout << "구매 가격 : " << storeWeaponArr[i].price << " 골드" << endl;
							cout << "판매 가격 : " << storeWeaponArr[i].sell << " 골드" << endl;
							cout << "특징 : " << storeWeaponArr[i].description << endl;
							cout << "-----------------------------------------" << endl;
						}
						cout << "뒤로가기 : 4번을 누르세요." << endl;
						cout << "구매할 아이템을 선택하시오 : ";
						cout << "현재 소지금 : " << player.inventory.gold << endl;
						cout << "가방 남은 자리 : " << int(INVENTORY_MAX - player.inventory.itemCount) << " / " << INVENTORY_MAX << endl; 

						cin >> menu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (menu < SM2_NONE || menu > SM2_BACK)
						{
							cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
							system( "read -n 1 -s -p \"Press any key to continue...\"" );
							continue;
						}

						switch (menu)
						{							
						case SM2_LIST1:
							if (player.inventory.itemCount >= INVENTORY_MAX)
							{
								cout << "인벤토리가 모두 찼습니다. 상점을 이용할 수 없습니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							if (player.inventory.gold < storeWeaponArr[0].price)
							{
								cout << "소지금이 부족합니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							cout << storeWeaponArr[0].name << "을 구매하셨습니다." << endl;
							player.inventory.gold -= storeWeaponArr[0].price;

							// 무기 바로 장착
							player.attackMin += storeWeaponArr[0].min;
							player.attackMax += storeWeaponArr[0].max;

							// inventory에 아이템 넣기
							player.inventory.itemArr[player.inventory.itemCount++] = storeWeaponArr[0];

							cout << "현재 소지금 : " << player.inventory.gold << endl;
							break;
						case SM2_LIST2:
							if (player.inventory.itemCount >= INVENTORY_MAX)
							{
								cout << "인벤토리가 모두 찼습니다. 상점을 이용할 수 없습니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							if (player.inventory.gold < storeWeaponArr[1].price)
							{
								cout << "소지금이 부족합니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							cout << storeWeaponArr[1].name << "을 구매하셨습니다." << endl;
							player.inventory.gold -= storeWeaponArr[1].price;

							// inventory에 아이템 넣기
							player.inventory.itemArr[player.inventory.itemCount++] = storeWeaponArr[1];

							// 무기 바로 장착
							player.attackMin += storeWeaponArr[1].min;
							player.attackMax += storeWeaponArr[1].max;

							cout << "현재 소지금 : " << player.inventory.gold << endl;
							break;
						case SM2_LIST3:
							if (player.inventory.itemCount >= INVENTORY_MAX )
							{
								cout << "인벤토리가 모두 찼습니다. 상점을 이용할 수 없습니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							if (player.inventory.gold < storeWeaponArr[2].price)
							{
								cout << "소지금이 부족합니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							cout << storeWeaponArr[2].name << "을 구매하셨습니다." << endl;
							player.inventory.gold -= storeWeaponArr[2].price;

							// 무기 바로 장착
							player.attackMin += storeWeaponArr[2].min;
							player.attackMax += storeWeaponArr[2].max;

							// inventory에 아이템 넣기
							player.inventory.itemArr[player.inventory.itemCount++] = storeWeaponArr[2];

							cout << "현재 소지금 : " << player.inventory.gold << endl;
							break;
						case SM2_BACK:	
							break;
						}	
						break;
					}			

					break;
				case SM_ARMOR:					
					while (true)
					{
						system("clear");
						cout << "=========== 갑옷 상점 ==========" << endl;
						for (int i = 0; i < STORE_ARMOR_MAX; ++i)
						{
							cout << i + 1 << "번 무기 : " << storeArmorArr[i].name << endl;
							cout << "공격력 : " << storeArmorArr[i].min << " ~ " << storeWeaponArr[i].max << endl;
							cout << "구매 가격 : " << storeArmorArr[i].price << " 골드" << endl;
							cout << "판매 가격 : " << storeArmorArr[i].sell << " 골드" << endl;
							cout << "특징 : " << storeArmorArr[i].description << endl;
							cout << "-----------------------------------------" << endl;
						}

						cout << "구매할 아이템을 선택하시오 : ";
						cin >> menu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (menu < SM2_NONE || menu > SM2_BACK)
						{
							cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
							system( "read -n 1 -s -p \"Press any key to continue...\"" );
							continue;
						}

						switch (menu)
						{							
						case SM2_LIST1:
							if (player.inventory.itemCount >= INVENTORY_MAX)
							{
								cout << "인벤토리가 모두 찼습니다. 상점을 이용할 수 없습니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							if (player.inventory.gold < storeArmorArr[0].price)
							{
								cout << "소지금이 부족합니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							cout << storeArmorArr[0].name << "을 구매하셨습니다." << endl;
							player.inventory.gold -= storeArmorArr[0].price;

							// 무기 바로 장착
							player.armorMin += storeArmorArr[0].min;
							player.armorMax += storeArmorArr[0].max;

							// inventory에 아이템 넣기
							player.inventory.itemArr[player.inventory.itemCount++] = storeArmorArr[0];

							cout << "현재 소지금 : " << player.inventory.gold << endl;
							break;
						case SM2_LIST2:
							if (player.inventory.itemCount >= INVENTORY_MAX)
							{
								cout << "인벤토리가 모두 찼습니다. 상점을 이용할 수 없습니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							if (player.inventory.gold < storeArmorArr[1].price)
							{
								cout << "소지금이 부족합니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							cout << storeArmorArr[1].name << "을 구매하셨습니다." << endl;
							player.inventory.gold -= storeArmorArr[1].price;

							// inventory에 아이템 넣기
							player.inventory.itemArr[player.inventory.itemCount++] = storeArmorArr[1];

							// 무기 바로 장착
							player.armorMin += storeArmorArr[1].min;
							player.armorMax += storeArmorArr[1].max;

							cout << "현재 소지금 : " << player.inventory.gold << endl;
							break;
						case SM2_LIST3:
							if (player.inventory.itemCount >= INVENTORY_MAX)
							{
								cout << "인벤토리가 모두 찼습니다. 상점을 이용할 수 없습니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							if (player.inventory.gold < storeArmorArr[2].price)
							{
								cout << "소지금이 부족합니다." << endl;
								system( "read -n 1 -s -p \"Press any key to continue...\"" );
								continue;
							}
							cout << storeArmorArr[2].name << "을 구매하셨습니다." << endl;
							player.inventory.gold -= storeArmorArr[2].price;

							// 무기 바로 장착
							player.armorMin += storeArmorArr[2].min;
							player.armorMax += storeArmorArr[2].max;

							// inventory에 아이템 넣기
							player.inventory.itemArr[player.inventory.itemCount++] = storeArmorArr[2];

							cout << "현재 소지금 : " << player.inventory.gold << endl;
							break;
						case SM2_BACK:
							break;
						}
						break;
					}
					break;
				}

				cout << "========== 플레이어 ==========" << endl;
				cout << "이름 : " << player.name << "\t직업 : " << player.className << endl;
				cout << "레벨 : " << player.level << "\t경험치 : " << player.exp << endl;
				cout << "공격력 : " << player.attackMin << " ~ " << player.attackMax << endl;
				cout << "방어력 : " << player.armorMin << " ~ " << player.armorMax << endl;
				cout << "체력 : " << player.hp << " / " << player.hpMax << "\t마나 : " << player.mp << " / " << player.mpMax << endl;
				cout << "소지금 : " << player.inventory.gold << endl << endl;
				cout << "가방 남은 자리 : " << int(INVENTORY_MAX - player.inventory.itemCount) << " / " << INVENTORY_MAX << endl;

				system( "read -n 1 -s -p \"Press any key to continue...\"" );
				continue;
			}

			break;
		case MM_INVENTORY:
			system("clear");
			cout << "========== 현재 소지품 목록 ==========" << endl;
			cout << "가방 남은 자리 : " << int(INVENTORY_MAX - player.inventory.itemCount) << " / " << INVENTORY_MAX << endl;
			for (int i = 0; i < player.inventory.itemCount; ++i)
			{
				cout << player.inventory.itemArr[i].name << endl;
			}

			cout << "골드 : " << player.inventory.gold << endl;
			system( "read -n 1 -s -p \"Press any key to continue...\"" );
			break;
		}
	}


	return 0;
}
