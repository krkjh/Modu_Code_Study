#include <string.h>
#include <iostream>

class PhotonCannon
{
	int hp, shield;				// 포톤캐논의 체력, 실드
	int coord_x, coord_y;		// 포톤캐논의 위치
	int damage;					// 포톤캐논의 공격력

public:
	PhotonCannon(int x, int y);	// x, y 좌표에 포톤캐논 생성
	PhotonCannon(const PhotonCannon& pc);

	void show_status();			// 상태 출력
};

PhotonCannon::PhotonCannon(const PhotonCannon& pc)
{
	std::cout << "복사 생성자 호출!" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}

PhotonCannon::PhotonCannon(int x, int y)
{
	std::cout << "생성자 호출!" << std::endl;

	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}

void PhotonCannon::show_status()
{
	std::cout << "PhotonCannon : " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main()
{
	PhotonCannon pc1(3, 3);
	PhotonCannon pc2(pc1);
	PhotonCannon pc3 = pc2;

	pc1.show_status();
	pc2.show_status();
}