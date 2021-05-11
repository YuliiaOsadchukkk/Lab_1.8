//Bill.cpp
#include "Bill.h"


void Bill::Time::SetHour(unsigned int value)
{
	if (value > 23 || value < 0)
		value = 0;
	this->hour = value;
}

void Bill::Time::SetMinute(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->minute = value;
}

void Bill::Time::SetSecond(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->second = value;
}



void Bill::Time::Init_time(unsigned int hour, unsigned int minute, unsigned int second)
{
	SetHour(hour);
	SetMinute(minute);
	SetSecond(second);
}

void Bill::Time::Read()
{
	unsigned int h, m, s;
	do {
		cout << " Enter hour: "; cin >> h;
	} while (h > 23 || h < 0);

	do {
		cout << " Enter minute: "; cin >> m;
	} while (m > 59 || m < 0);

	do {
		cout << " Enter second: "; cin >> s;
	} while (s > 59 || s < 0);

	Init_time(h, m, s);
}

void Bill::Time::Display() {
	cout << endl << toString() << endl;
}

string Bill::Time::toString() const {
	stringstream sout;
	sout << " " << hour << ":" << minute << ":" << second;
	return sout.str();
}


////////////////////////////////////////////////////////////////////////
bool Bill::Time::IsEarlierThan(Time T2)
{
	if (hour == T2.hour)
	{
		if (minute == T2.minute)
		{
			if (second == T2.second)
				return false;
			else if (second < T2.second)
				return true;
			else
				return false;
		}
		else if (minute < T2.minute)
			return true;
		else
			return false;
	}
	else if (hour < T2.hour)
		return true;
	else
		return false;
}

bool Bill::Time::IsSameAs(Time T2)
{
	if (hour == T2.hour)
	{
		if (minute == T2.minute)
		{
			if (second == T2.second)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Bill::Time::IsLaterThan(Time T2)
{
	if (IsEarlierThan(T2))
		return false;
	else if (!IsSameAs(T2))
		return true;
}

void Bill::Time::SubstractSeconds()
{
	unsigned int substr;
	do {
		cout << "Enter how much seconds to substract: "; cin >> substr;
	} while (substr < 1);

	do {
		if (substr < second)
		{
			second = second - substr;
			substr = 0;
		}
		else
		{
			substr = substr - second;

			if (minute == 0)//1
			{
				minute = 60;// 60
				hour--;
			}
			else
			{
				minute--;
				second = 60; //60
			}
		}
	} while (substr != 0);
}

void Bill::Time::TimePlusSeconds()
{
	unsigned int seconds;
	do {
		cout << "Enter how much seconds to add: "; cin >> seconds;
	} while (seconds < 1);

	short SecondsLeft;
	do {
		SecondsLeft = 60 - second;
		if (seconds < SecondsLeft)
		{
			second = second + seconds;
			seconds = 0;
		}
		else
		{
			second = second + SecondsLeft;
			seconds = seconds - SecondsLeft;
			if (minute == 60)
			{
				minute = 0;//
				hour++;
			}
			else
			{
				second = 0;//
				minute++;
			}
		}
	} while (seconds != 0);
}

unsigned int Bill::Time::ToSeconds()
{
	unsigned int t;
	t = hour * 3600 + minute * 60 + second;
	return t;
}

unsigned int Bill::Time::ToMinutes()
{
	unsigned int t;
	if (second < 1)
	{
		t = hour * 60 + minute;
	}
	if (second > 0)
	{
		t = hour * 60 + minute + 1;
	}
	return t;
}

unsigned int Difference(Bill::Time T1, Bill::Time T2)
{
	return T2.ToSeconds() - T1.ToSeconds();
}

unsigned int DifferenceForT(Bill::Time T1, Bill::Time T2)
{
	int k;
	k = Difference(T1, T2) / 60.;
	return k;
}

//////Bill

void Bill::SetTaryf(double v)
{
	this->taryf = v;
}

void Bill::SetZnyzhka(double v)
{
	if (v > 100 || v < 0)
	{
		v = 0;
	}
	this->znyzhka = v;
}

void Bill::SetSumforpay(double v)
{
	this->sumforpay = v;
}

void Bill::Init(string surname, string cellnumb, double taryf, double znyzhka)
{
	SetSurname(surname);
	SetCellnumb(cellnumb);
	SetTaryf(taryf);
	SetZnyzhka(znyzhka);
}

void Bill::Read()
{
	string surname;
	cout << " Enter surname: "; cin >> surname;
	string cellnumb;
	cout << " Enter phone number: "; cin >> cellnumb;

	double taryf, znyzhka;
	cout << " Enter taryf per minute: "; cin >> taryf;
	do {
		cout << " Enter discount, %: "; cin >> znyzhka;
	} while (znyzhka > 100 || znyzhka < 0);



	Init(surname, cellnumb, taryf, znyzhka);
}

string Bill::toString() const
{
	stringstream sout;
	sout << endl << " Surname: " << surname << endl;
	sout << " Phone number: " << cellnumb << endl;
	sout << " Taryf per minute: " << taryf << "UAH" << endl;
	sout << " Discount: " << znyzhka << "%" << endl;

	return sout.str();
}

void Bill::Display()
{
	cout << toString() << endl;
}


double Bill::Sum_For_Pay(Time T1, Time T2)
{
	return DifferenceForT(T1, T2) * taryf - (DifferenceForT(T1, T2) * taryf) * (znyzhka / 100);
}
