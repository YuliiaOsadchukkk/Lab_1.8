//Source.cpp

#include <iostream>
#include "Time.h"
#include "Bill.h"

using namespace std;

int main()
{


	Bill B1;
	Bill::Time T1, T2; //T1-timebeg, T2 - timeend

	B1.Read();
	cout << endl;
	cout << " Enter talk start time:" << endl;
	T1.Read();
	cout << " Enter talk end time:" << endl;
	T2.Read();
	
	cout << "------------------------------------------------------------------------";
	B1.Display();
	cout << " Talk start time: ";
	T1.Display();
	cout << " Talk end time: ";
	T2.Display();
	cout << endl;

	cout << "Sum to pay: " << B1.Sum_For_Pay(T1, T2) << "UAH" << endl;



	cout << "------------------------------------------------------------------------" << endl;
	cout << "                       MANIPULATIONS WITH TIME                          " << endl << endl;

	cout << "Talk start time is earlier than talk end time: ";
	if (T1.IsEarlierThan(T2))
		cout << " TRUE" << endl << endl;
	else
		cout << " FALSE" << endl << endl;

	cout << "Talk end time minus talk start time (in seconds): ";
	unsigned int n = Difference(T1, T2);
	cout << n << endl;

	cout << "Talk end time minus talk start time (in minutes): ";
	unsigned int k = DifferenceForT(T1, T2);
	cout << k << endl << endl;

	cout << "Talk start time in seconds: ";
	unsigned int s = T1.ToSeconds();
	cout << s << endl;

	cout << "Talk start time in minutes: ";
	unsigned int m = T1.ToMinutes();
	cout << m << endl << endl;

	cout << "Subtracting from time a specified number of seconds (talk start time): " << endl;
	T1.SubstractSeconds();
	T1.Display();//
	cout << endl;

	cout << "Adding to time a specified number of seconds (talk start time which was substracted): " << endl;
	T1.TimePlusSeconds();
	T1.Display();//
	
	return 0;
}
