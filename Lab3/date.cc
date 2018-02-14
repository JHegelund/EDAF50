#include <ctime>  // time and localtime
#include <iomanip> // for setw and setfill
#include <iostream>
#include "date.h"

using std::cout;
using std::setw;
using std::setfill;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d): year(y), month(m), day(d) {
	if(m >= 1 && m <= 12 && d >= 1 && d < daysPerMonth[m]){
		year = y;
		month = m;
		day = d;
	} else {
		throw std::invalid_argument("Invalid");
	}
}

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
	return os;
}

std::istream& operator >>(std::istream is, Date& d){
	int yearInput, monthInput, dayInput;
	char char1, char2;
	is >> yearInput;
	is >> char1;
	is >> monthInput;
	is >> char2;
	is >> dayInput;

	try{
		d = Date(yearInput, monthInput, dayInput);
	} catch (const std::invalid_argument& e) {
		is.setstate(std::ios_base::failbit);
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

