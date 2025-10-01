#include <iostream>

class Marine
{
	static int total_marine_num;	// 생성된 마린의 총 수
	const static int i = 0;

	int hp;							// 마린의 체력
	int coord_x, coord_y;			// 마린의 위치
	bool is_dead;					// 마린의 사망 여부

	const int default_damage;		// 마린의 기본 공격력

public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);

	int attack();						// 데미지를 리턴
	Marine& be_attacked(int damage_earn);	// 입는 데미지
	void move(int x, int y);			// 새로운 위치

	void show_status();					// 상태 출력
	static void show_total_marine();
	~Marine()
	{
		total_marine_num--;
	}
};

int Marine::total_marine_num = 0;
void Marine::show_total_marine()
{
	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false)
{
	total_marine_num++;
}

Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false)
{
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) : hp(50), coord_x(x), coord_y(y), default_damage(default_damage), is_dead(false)
{
	total_marine_num++;
}

void Marine::move(int x, int y)
{
	coord_x = x;				// x 좌표 이동
	coord_y = y;				// y 좌표 이동
}

int Marine::attack()
{
	return default_damage;
}

Marine& Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0)
	{
		is_dead = true;
		hp = 0;
	}
	return *this;
}

void Marine::show_status()
{
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " 현재 총 마린 수 :  " << total_marine_num << std::endl;
}


int main()
{
	Marine marine1(2, 3, 5);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();


	std::cout << std::endl << "마린 1이 마린 2를 두번 공격!" << std::endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}