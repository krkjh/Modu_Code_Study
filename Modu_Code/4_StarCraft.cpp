#include <string.h>
#include <iostream>

class Marine
{
	int hp;						// ������ ü��
	int coord_x, coord_y;		// ������ ��ġ
	int damage;					// ������ ���ݷ�
	bool is_dead;				// ������ ��� ����
	char* name;					// ������ �̸�

public:
	Marine();										// �⺻ ������
	Marine(int x, int y, const char* marine_name);	// �̸����� ����
	Marine(int x, int y);							// x, y ��ǥ�� ���� ����
	~Marine();

	int attack();									// �������� ����
	void be_attacked(int damage_earn);				// �Դ� ������
	void move(int x, int y);						// ���ο� ��ġ

	void show_status();								// ���� ���
};

Marine::Marine()
{
	hp = 50;					// �⺻ ü��
	coord_x = coord_y = 0;		// �⺻ ��ġ
	damage = 5;					// �⺻ ���ݷ�
	is_dead = false;			// �⺻ ��� ����
	name = NULL;				// �̸� ����
}

Marine::Marine(int x, int y, const char* marine_name)
{
	name = new char[strlen(marine_name) + 1];
	strcpy_s(name, strlen(marine_name) + 1, marine_name);

	hp = 50;					// �⺻ ü��
	coord_x = x;				// x ��ǥ
	coord_y = y;				// y ��ǥ
	damage = 5;					// �⺻ ���ݷ�
	is_dead = false;			// �⺻ ��� ����
}

Marine::Marine(int x, int y)
{
	hp = 50;					// �⺻ ü��
	coord_x = x;				// x ��ǥ
	coord_y = y;				// y ��ǥ
	damage = 5;					// �⺻ ���ݷ�
	is_dead = false;			// �⺻ ��� ����
	name = NULL;				// �̸� ����
}

void Marine::move(int x, int y)
{
	coord_x = x;				// x ��ǥ �̵�
	coord_y = y;				// y ��ǥ �̵�
}

int Marine::attack()
{
	return damage;				// ���ݷ� ����
}

void Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;			// ü�� ����
	if (hp <= 0)				// ü���� 0 �����̸�
		is_dead = true;			// ��� ó��
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

	std::cout << std::endl << "���� 1 �� ���� 2 �� �����մϴ�!" << std::endl;
	
	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
}