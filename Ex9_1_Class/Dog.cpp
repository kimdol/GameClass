#include "Dog.h"

int Dog::GetAge()
{
	return mAge;
}

void Warrior::Setting(int hp, int ad, int bersk)
{
	mHp = hp;
	mAd = ad;
	mBersk = bersk;
}


void Warrior::Attack(Warrior& attacked)
{
	std::cout << mAd << "��ŭ �������� ���!"
		<< std::endl;
	if ((attacked.mHp -= mAd) <= 0)
	{
		std::cout << "������ �׾����ϴ�"
			<< std::endl;
	}

}

void Warrior::Skill()
{
	if (mBersk)
	{
		std::cout << "����Ŀ ��� OFF!"
			<< std::endl;
		mBersk = 0;
	}
	else
	{
		std::cout << "����Ŀ ��� ON!"
			<< std::endl;
		mBersk = 1;
	};
}