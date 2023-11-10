#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class date
{
public:
	date(int year=1,int month=1,int day=1);
	void print();
	int GetMonthDay(int year, int Month);


	bool operator==(const date& y);
	bool operator!=(const date& y);


	bool operator>(const date& y);
	bool operator>=(const date& y);
	bool operator<(const date& y);
	bool operator<=(const date& y);

	int operator-(const date& d);
	date& operator+=(int day);
	date operator+(int day);
	date& operator-=(int day);
	date operator-(int day);

	date& operator++();
	date operator++(int);

	date& operator--();
	date operator--(int);
private:
	int _year;
	int _month;
	int _day;
};
