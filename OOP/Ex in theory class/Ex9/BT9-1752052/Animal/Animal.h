#pragma once
#ifndef _ANIMAL_H	
#define _ANIMAL_H

#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class Animal
{
protected:
	string move;
	string eat;
	string givebirth;
public:
	virtual void Move();
	virtual void Eat();
	virtual void GiveBirth();
	virtual void Boi();
};


/*
class Shark : public Animal
{};
class Carp : public Animal
{};
class Lion : public Animal
{};
class Cow : public Animal
{};
class Whale : public Animal
{};
class Sparrow : public Animal
{};
class Eagle : public Animal
{};
class Crocodile : public Animal
{};
class Chameleon : public Animal
{};
class Bat : public Animal
{};
int SwimContest(Animal *a1, Animal *a2)
*/

#endif