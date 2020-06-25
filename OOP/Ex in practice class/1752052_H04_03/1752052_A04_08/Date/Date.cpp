#include "Date.h"

Date::Date()
{
	this->day = 2;
	this->month = 11;
	this->year = 2012;
}

Date::Date(int year)
{
	this->day = 1;
	this->month = 1;
	this->year = year;
}

Date::Date(int year, int month)
{
	this->day = 1;
	this->month = month;
	this->year = year;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date &d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

int Date::CheckLeapYear()
{
	if (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0)
		return 1;
	else
		return -1;
	return 0;
}

Date Date::Tomorrow()
{
	if (this->month != 12)
	{
		if (this->day <= 30 && this->month != 2)
		{
			this->day += 1;
			this->month = this->month;
			this->year = this->year;
		}
		else if (this->day == 31 && this->month != 2)
		{
			this->day = 1;
			this->month += 1;
			this->year = this->year;
		}
		else //this->month == 2
		{
			if (this->CheckLeapYear() == false)
			{
				this->day += 1;
				this->month = 2;
				this->year = this->year;
			}
			else
			{
				this->day = 1;
				this->month = 3;
				this->year = this->year;
			}
		}
	}
	else //this->month == 12
	{
		if (this->day <= 30)
		{
			this->day += 1;
			this->month = 12;
			this->year = this->year;
		}
		else
		{
			this->day = 1;
			this->month = 1;
			this->year += 1;
		}
	}
	return *this;
}

Date Date::Yesterday()
{
	if (this->month != 1)
	{
		if (this->day >= 2 && this->month == (2, 4, 6, 9, 11))
		{
			if (this->day >= 2)
			{
				this->day -= 1;
				this->month = this->month;
				this->year = this->year;
			}
			else
			{
				this->day = 31;
				this->month -= 1;
				this->year = this->year;
			}
		}
		else if (this->day >= 2 && this->month == (5, 7, 8, 10, 12))
		{
			if (this->day >= 2)
			{
				this->day -= 1;
				this->month = this->month;
				this->year = this->year;
			}
			else
			{
				this->day = 30;
				this->month -= 1;
				this->year = this->year;
			}
		}
		else //d.month == 3
		{
			if (this->CheckLeapYear() == false)
			{
				this->day == 28;
				this->month == 2;
				this->year = this->year;
			}
			else
			{
				this->day = 29;
				this->month = 2;
				this->year = this->year;
			}
		}
	}
	else //d.month == 1
	{
		if (d.day >= 2)
		{
			this->day -= 1;
			this->month = 1;
			this->year = this->year;
		}
		else
		{
			this->day = 31;
			this->month = 12;
			this->year -= 1;
		}
	}
	return *this;
}

int Date::operator>(const Date &d)
{
	if (this->year == d.year)
	{
		if (this->month == d.month)
		{
			if (this->day > d.day)
				return 1;
			else
				return 0;
		}
		else if (this->month > d.month)
			return 1;
		else
			return 0;
	}
	else if (this->year > d.year)
		return 1;
	else
		return 0;
}

int Date::operator<(const Date & d)
{
	if (this->year == d.year)
	{
		if (this->month == d.month)
		{
			if (this->day < d.day)
				return 1;
			else
				return 0;
		}
		else if (this->month < d.month)
			return 1;
		else
			return 0;
	}
	else if (this->year < d.year)
		return 1;
	else
		return 0;
}

int Date::operator>=(const Date &d)
{
	if (this->year == d.year)
	{
		if (this->month == d.month)
		{
			if (this->day >= d.day)
				return 1;
			else
				return 0;
		}
		else if (this->month >= d.month)
			return 1;
		else
			return 0;
	}
	else if (this->year >= d.year)
		return 1;
	else
		return 0;
}

int Date::operator<=(const Date &d)
{
	if (this->year == d.year)
	{
		if (this->month == d.month)
		{
			if (this->day <= d.day)
				return 1;
			else
				return 0;
		}
		else if (this->month <= d.month)
			return 1;
		else
			return 0;
	}
	else if (this->year <= d.year)
		return 1;
	else
		return 0;
}

int Date::operator==(const Date &d)
{
	if (this->year == d.year)
	{
		if (this->month == d.month)
		{
			if (this->day == d.day)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}

int Date::operator!=(const Date &d)
{
	if (this->year == d.year)
	{
		if (this->month == d.month)
		{
			if (this->day != d.day)
				return 1;
			else
				return 0;
		}
		else if (this->month != d.month)
			return 1;
		else
			return 0;
	}
	else 
		return 1;

}

Date& Date::operator=(const Date &d)
{
	if (this != &d)
	{
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
	}
	return *this;
}

Date Date::operator+(Date d)
{
	Date temp;
	temp.day = this->day + d.day;
	if (temp.month != 2)
	{
		if (temp.month == 1, 3, 5, 7, 8, 10 && temp.day > 31)
			temp.month += 1;
		else if (temp.month == 4, 6, 9, 11 && temp.day > 30)
			temp.month += 1;
		else if (temp.month == 12 && temp.day > 31)
			temp.year += 1;
	}
	else if (d.CheckLeapYear == true && temp.day > 29)
		temp.month = 3;
	else if (d.CheckLeapYear == false && temp.day > 28)
		temp.month = 3;
	return temp;
}

Date Date::operator-(Date d)
{
	Date temp;
	if (this->day > d.day)
		temp.day = this.day - d.day;

}

Date& Date::operator+=(int days)
{
	this->day = this->day + days;

	if (this->month != 2)
	{
		if (this->month == 1, 3, 5, 7, 8, 10 && this->day > 31)
			this->month += 1;
		else if (this->month == 4, 6, 9, 11 && this->day > 30)
			this->month += 1;
		else if (this->month == 12 && this->day > 31)
			this->year += 1;
	}
	else if (d.CheckLeapYear == true && this->day > 29)
		this->month = 3;
	else if (d.CheckLeapYear == false && this->day > 28)
		this->month = 3;
	return *this;
}

Date& Date::operator-=(int days)
{
	if (this->day > days)
	{
		this->day = this->day - days;
		for (int i = 0; i <= this->day; i++)
		{
			if (this->day < 1)
				this->month -= 1;
			if (this->month < 1)
				this->year -= 1;
		}
	}
}

Date& Date::operator++()
{
	if (this->month != 12)
	{
		if (this->day <= 30 && this->month != 2)
		{
			this->day += 1;
			this->month = this->month;
			this->year = this->year;
		}
		else if (this->day == 31 && this->month != 2)
		{
			this->day = 1;
			this->month += 1;
			this->year = this->year;
		}
		else //this->month == 2
		{
			if (this->CheckLeapYear() == false)
			{
				this->day += 1;
				this->month = 2;
				this->year = this->year;
			}
			else
			{
				this->day = 1;
				this->month = 3;
				this->year = this->year;
			}
		}
	}
	else //this->month == 12
	{
		if (this->day <= 30)
		{
			this->day += 1;
			this->month = 12;
			this->year = this->year;
		}
		else
		{
			this->day = 1;
			this->month = 1;
			this->year += 1;
		}
	}
	return *this;
}

Date Date::operator++(int x)
{
	Date temp(*this)
		if (this->month != 12)
		{
			if (this->day <= 30 && this->month != 2)
			{
				this->day += 1;
				this->month = this->month;
				this->year = this->year;
			}
			else if (this->day == 31 && this->month != 2)
			{
				this->day = 1;
				this->month += 1;
				this->year = this->year;
			}
			else //this->month == 2
			{
				if (this->CheckLeapYear() == false)
				{
					this->day += 1;
					this->month = 2;
					this->year = this->year;
				}
				else
				{
					this->day = 1;
					this->month = 3;
					this->year = this->year;
				}
			}
		}
		else //this->month == 12
		{
			if (this->day <= 30)
			{
				this->day += 1;
				this->month = 12;
				this->year = this->year;
			}
			else
			{
				this->day = 1;
				this->month = 1;
				this->year += 1;
			}
		}
	return temp;
}

Date& Date::operator--()
{
	Date temp(*this)
	if (this->month != 1)
	{
		if (this->day >= 2 && this->month == (2, 4, 6, 9, 11))
		{
			if (this->day >= 2)
			{
				this->day -= 1;
				this->month = this->month;
				this->year = this->year;
			}
			else
			{
				this->day = 31;
				this->month -= 1;
				this->year = this->year;
			}
		}
		else if (this->day >= 2 && this->month == (5, 7, 8, 10, 12))
		{
			if (this->day >= 2)
			{
				this->day -= 1;
				this->month = this->month;
				this->year = this->year;
			}
			else
			{
				this->day = 30;
				this->month -= 1;
				this->year = this->year;
			}
		}
		else //d.month == 3
		{
			if (this->CheckLeapYear() == false)
			{
				this->day == 28;
				this->month == 2;
				this->year = d.year;
			}
			else
			{
				this->day = 29;
				this->month = 2;
				this->year = this->year;
			}
		}
	}
	else //d.month == 1
	{
		if (d.day >= 2)
		{
			this->day -= 1;
			this->month = 1;
			this->year = this->year;
		}
		else
		{
			this->day = 31;
			this->month = 12;
			this->year -= 1;
		}
	}
	return temp;
}

Date::operator int()
{
	return (int) day : month : year;
}

Date::operator float()
{
	return (float) day : month : year;
}

int Date::GetDay()
{
	day = this->day;
	return day;
}

int Date::GetMonth()
{
	month = this->month;
	return month;
}

int Date::GetYear()
{
	year = this->year;
	return year;
}

ostream& operator<<(ostream &os, const Date &d)
{
	os << d.GetDay << ":" << d.GetMonth << d.GetYear;
	return os;
}

istream& operator>>(istream &is, Date &d)
{
	is >> d.GetDay >> d.GetMonth >> d.GetYear;
	return is;
}
