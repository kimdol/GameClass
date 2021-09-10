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
	std::cout << mAd << "만큼 데미지를 줬다!"
		<< std::endl;
	if ((attacked.mHp -= mAd) <= 0)
	{
		std::cout << "적군이 죽었습니다"
			<< std::endl;
	}

}

void Warrior::Skill()
{
	if (mBersk)
	{
		std::cout << "버서커 모드 OFF!"
			<< std::endl;
		mBersk = 0;
	}
	else
	{
		std::cout << "버서커 모드 ON!"
			<< std::endl;
		mBersk = 1;
	};
}