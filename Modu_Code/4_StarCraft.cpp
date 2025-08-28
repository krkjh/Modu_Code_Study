#include <iostream>

class Marine
{
	int hp;						// 마린의 체력
	int coord_x, coord_y;		// 마린의 위치
	int damage;					// 마린의 공격력
	bool is_dead;				// 마린의 사망 여부

public:
	Marine();					// 기본 생성자
	Marine(int x, int y);		// x, y 좌표에 마린 생성

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
}

Marine::Marine(int x, int y)
{
	hp = 50;					// 기본 체력
	coord_x = x;				// x 좌표
	coord_y = y;				// y 좌표
	damage = 5;					// 기본 공격력
	is_dead = false;			// 기본 사망 여부
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
	std::cout << "Marine Status: " << std::endl;
	std::cout << "Position: (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "HP: " << hp << std::endl;
}

int main()
{
	Marine marine1(2, 3);
	Marine marine2(3, 5);
	
	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격합니다!" << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}