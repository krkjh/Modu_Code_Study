#include <iostream>

class Marine
{
	int hp;						// ������ ü��
	int coord_x, coord_y;		// ������ ��ġ
	int damage;					// ������ ���ݷ�
	bool is_dead;				// ������ ��� ����

public:
	Marine();					// �⺻ ������
	Marine(int x, int y);		// x, y ��ǥ�� ���� ����

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
}

Marine::Marine(int x, int y)
{
	hp = 50;					// �⺻ ü��
	coord_x = x;				// x ��ǥ
	coord_y = y;				// y ��ǥ
	damage = 5;					// �⺻ ���ݷ�
	is_dead = false;			// �⺻ ��� ����
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

	std::cout << std::endl << "���� 1 �� ���� 2 �� �����մϴ�!" << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}