#include "RunContest.h"

int Cheetah::GetSpeed()
{
	return this->speed;
}

int Antelope::GetSpeed()
{
	return this->speed;
}

int Lion::GetSpeed()
{
	return this->speed;
}

int Dog::GetSpeed()
{
	return this->speed;
}

int Human::GetSpeed()
{
	return this->speed;
}

int Horse::GetSpeed()
{
	return this->speed;
}

int RunContest(Animal *a1, Animal *a2)
{
	if (a1->GetSpeed() > a2->GetSpeed())
		return 1;
	else if (a1->GetSpeed() < a2->GetSpeed())
		return 0;
	else
		return -1;
}