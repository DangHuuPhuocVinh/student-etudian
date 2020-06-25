#pragma once
#ifndef _RUNCONTEST_H
#define _RUNCONTEST_H

#include<iostream>
#include<conio.h>

using namespace std;

class Animal
{
public:
	virtual int GetSpeed() = 0;
};

class Cheetah : public Animal
{
private:
	int speed = 100;
public:
	int GetSpeed();
};

class Antelope : public Animal
{
private:
	int speed = 80;
public:
	int GetSpeed();
};

class Lion : public Animal
{
private:
	int speed = 70;
public:
	int GetSpeed();
};

class Dog : public Animal
{
private: 
	int speed = 60;
public:
	int GetSpeed();
};

class Human : public Animal
{
private:
	int speed = 30;
public:
	int GetSpeed();
};

class Horse : public Animal
{
private:
	int speed = 60;
public:
	int GetSpeed();
};
int RunContest(Animal *a1, Animal *a2);
#endif  
