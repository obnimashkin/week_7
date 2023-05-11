#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <ctime>
using namespace std;


//task 1
bool isLeap(int year) { //task 1 and 2
	return ((year % 4 == 0 || year % 100 == 0 || year % 400 == 0) ? true : false);
}

//task 2
int monthLengthSwitch(int year , int month) {
	switch (month)
	{
		case 1: 
			return 31;
			break;
		case 2: 
			if (isLeap(year)) return 29;
			else return 28;
		case 3:
			return 31;
			break;
		case 4:
			return 30;
			break;
		case 5:
			return 31;
			break;
		case 6:
			return 30;
			break;
		case 7:
			return 31;
			break;
		case 8:
			return 31;
			break;
		case 9:
			return 30;
			break;
		case 10:
			return 31;
			break;
		case 11:
			return 30;
			break;
		case 12:
			return 31;
			break;
	default:
		return -1;
		break;
	}
}
int monthLengthArray(int year, int month) {
	int dayInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && isLeap(year)) return 29;
	return (dayInMonth[month - 1]);
}
//task 3
struct Date {
	int year;
	int month;
	int day;;
};

Date today(void) {
	Date _today;
	time_t t = time(NULL);
	tm tl = *localtime(&t);
	_today.year = tl.tm_year + 1900;
	_today.month = tl.tm_mon + 1;
	_today.day = tl.tm_mday;
	return _today;
}

Date enterBirth() {
	Date t;
	cout << "enter your birthday by space(year,month,day): ";
	cin >> t.year >> t.month >> t.day;
	return  t;
}

int daysHavePassed(Date _today, Date _birth) {
	int count = 0;

	count = monthLengthArray(_birth.year, _birth.month) - _birth.day;
	for (int m = _birth.month + 1; m <= 12;m++) count += monthLengthArray(_birth.year, m);

	for (int year = _birth.year + 1;year < _today.year;year++) {
		if (isLeap(year)) count += 366;
		else count += 365;
	}
	count += _today.day;
	for (int m = _today.month - 1; m >= 1;m--) count += monthLengthArray(_today.year, m);

	return count;
}

//task 1
/*
int main() {
	for (int yr = 1995; yr < 2017; yr++)
		cout << yr << " -> " << isLeap(yr) << endl;


	return 0;
}
*/
//task 2

//int main() {
//	cout << "method by switch\n";
//	for (int yr = 2000; yr < 2002; yr++) {
//		for (int mo = 1; mo <= 12; mo++)
//			cout << monthLengthSwitch(yr, mo) << " ";
//		cout << endl;
//	}
//
//	cout << "method by array\n";
//	for (int yr = 2000; yr < 2002; yr++) {
//		for (int mo = 1; mo <= 12; mo++)
//			cout << monthLengthArray(yr, mo) << " ";
//		cout << endl;
//	}
//	return 0;
//}

//task 3

int main()
{
	Date tOday , birth;
	int count = 0;

	cout << "enter your birthday by space(year,month,day): ";
	cin >> birth.year >> birth.month >> birth.day;

	tOday = today();
	

	count = monthLengthArray(birth.year, birth.month) - birth.day;
	for (int m = birth.month + 1; m <= 12;m++) count += monthLengthArray(birth.year, m);

	for (int year = birth.year + 1;year < tOday.year;year++) {
		if (isLeap(year)) count += 366;
		else count += 365;
	}
	count += tOday.day;
	for (int m = tOday.month - 1; m >= 1;m--) count += monthLengthArray(tOday.year, m);

	cout << count;

	return 0;
}
