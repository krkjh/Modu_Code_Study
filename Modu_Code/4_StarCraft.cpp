#include <string.h>
#include <iostream>

class Marine
{
	int hp;						// 마린의 체력
	int coord_x, coord_y;		// 마린의 위치
	int damage;					// 마린의 공격력
	bool is_dead;				// 마린의 사망 여부
	char* name;					// 마린의 이름

public:
	Marine();										// 기본 생성자
	Marine(int x, int y, const char* marine_name);	// 이름까지 생성
	Marine(int x, int y);							// x, y 좌표에 마린 생성
	~Marine();

	int attack();									// 데미지를 리턴
	void be_attacked(int damage_earn);				// 입는 데미지
	void move(int x, int y);						// 새로운 위치

	void show_status();								// 상태 출력
};

Marine::Marine()
{
	hp = 50;					// 기본 체력
	coord_x = coord_y = 0;		// 기본 위치
	damage = 5;					// 기본 공격력
	is_dead = false;			// 기본 사망 여부
	name = NULL;				// 이름 없음
}

Marine::Marine(int x, int y, const char* marine_name)
{
	name = new char[strlen(marine_name) + 1];
	strcpy_s(name, strlen(marine_name) + 1, marine_name);

	hp = 50;					// 기본 체력
	coord_x = x;				// x 좌표
	coord_y = y;				// y 좌표
	damage = 5;					// 기본 공격력
	is_dead = false;			// 기본 사망 여부
}

Marine::Marine(int x, int y)
{
	hp = 50;					// 기본 체력
	coord_x = x;				// x 좌표
	coord_y = y;				// y 좌표
	damage = 5;					// 기본 공격력
	is_dead = false;			// 기본 사망 여부
	name = NULL;				// 이름 없음
}

void Marine::move(int x, int y)
{
	coord_x = x;				// x 좌표 이동
	coord_y = y;				// y 좌표 이동
}

int Marine::attack()
{
	return damage;				// 공격력 리턴
}

void Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;			// 체력 감소
	if (hp <= 0)				// 체력이 0 이하이면
		is_dead = true;			// 사망 처리
}

void Marine::show_status()
{
	std::cout << "*** Marine : " << name << " *** " << std::endl;
	std::cout << "Position: (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "HP: " << hp << std::endl;
}

int main()
{
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine 2");
	marines[1] = new Marine(1, 5, "Marine 1");
	
	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격합니다!" << std::endl;
	
	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
}