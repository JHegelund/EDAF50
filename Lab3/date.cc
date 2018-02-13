#include <ctime>  // time and localtime
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d): year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

std::ostream& operator <<(std::ostream& os, const Date& d){
	cout << setw(4) << setfill('0') << d.getYear() << '-';
	cout << setw(2) << setfill('0') << d.getMonth() << '-';
	cout << setw(2) << setfill('0') << d.getDay();
}

std::istream& operator >>(std::istream is, Date& d){
	int year, month, day;
	char char1, char2;
	is >> year;
	is >> char1;
	is >> month;
	is >> char2;
	is >> day;

	if(month >= 1 && month <= 12 && day >= 1 && day < daysPerMonth[month]){
		d.year = year;
		d.month = month;
		d.day = day;
	} else {
		is.setstate(ios_base::failbit);
	}

	return is;
}

void Date::next() {
	day++;
	if(daysPerMonth[month] < day){
		month++;
		day = 1;
		if(month > 12){
			year++;
			month = 1;
		}
	}
}

