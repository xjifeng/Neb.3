#pragma once
#include "Head.h"

date::date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (_year<1||
		_month<1||_month>12||
		_day>GetMonthDay(_year,_month))
	{
		print();
		cout << "日期非法" << endl;
	}
}
void date::print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}
int date::GetMonthDay(int year, int month)
{
	assert(year >= 1 && month>=1 && month <= 12);
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31 };
	if (month==2&&(year%4==0&&year%100!=0)||(year%400==0))
	{
		return 29;
	}
	return monthArray[month];
}
bool date::operator==(const date& y)
{
	return _year == y._year
		&& _month == y._month
		&& _day == y._day;
}
bool date::operator!=(const date& y)
{
	return !(*this == y);
}
bool date::operator>(const date& y)
{
	if (_year>y._year)
	{
		return true;
	}
	else if (_year == y._year && _month > y._month)
	{
		return true;
	}
	else if (_year == y._year && _month == y._month && _day>y._day)
	{
		return true;
	}
	return false;
}
bool date::operator>=(const date& y)
{
	return (*this > y) || (*this == y);
}
bool date::operator<(const date& y)
{
	return !(*this > y);
}
bool date::operator<=(const date& y)
{
	return (*this < y) || (*this == y);
}
date& date::operator+=(int day)
{
	if (day<0)
	{
		//return *this -= (-day);
	}
	_day += day;
	while (_day>GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month==13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
date date::operator+(int day)
{
	date tmp(*this);
	tmp += day;
	return tmp;
}
date& date::operator-=(int day)
{
	if (day<0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month==0)
		{
			--_year;
			_month = 12;
		}
		_day = GetMonthDay(_year, _month);
	}
	return *this;
}
date date::operator-(int day)
{
	date tmp(*this);
	tmp -= day;
	return tmp;
}
date& date::operator++()
{
	*this += 1;
	return *this;
}
date date::operator++(int)
{
	date tmp(*this);
	tmp + 1;
	return tmp;
}
date& date::operator--()
{
	*this -= 1;
	return *this;
}
date date::operator--(int)
{
	date tmp(*this);
	tmp -= 1;
	return tmp;
}