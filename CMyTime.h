#ifndef CMyTime_h
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class CMyTime
{
private:
	int m_Hour;
	int m_Minute;
	int m_Sencond;

public:
	int getH() { return m_Hour; }
	int getS() { return m_Sencond; }
	int getM() { return m_Minute; }
	CMyTime();
	CMyTime(CMyTime& a);
	CMyTime(int h, int s, int m);
	void Input(const char* fileName, int n);
	void Output(const char* fileName);
	void setTime(int d, int m, int y) {
		m_Hour = d; m_Minute = m; m_Sencond = y;

	}
	CMyTime operator++();
	CMyTime operator--();
	CMyTime operator+=(int n);
	CMyTime operator-=(int n);
	CMyTime operator+(CMyTime& a);
	CMyTime operator-(CMyTime& a);
	bool operator>(CMyTime& a);
	bool operator<(CMyTime& a);
	bool operator>=(CMyTime& a);
	bool operator<=(CMyTime& a);
	bool operator==(CMyTime& a);




};
class CDate
{
private:
	int year;
	int month;
	int day;
public:
	CDate(): day(0), month(0), year(0) {};
	CDate(int d, int m, int y) : day(d), month(m), year(y) {};
	CDate(const CDate &x) : day(x.day), month(x.month), year(x.year) {};
	void setDate(int d, int m, int y) {
		day = d; month = m; year = y;

	}
	CDate(std::string date) {
		int d, m, y;
		for (int i = 0; i < date.size(); i++) {
			if (date[i] == '/')date[i] = ' ';
		}
		std::stringstream ss(date);
		ss >> d >> m >> y;
		day = d;
		month = m;
		year = y;
	}
	friend ostream& operator<<(ostream& out, const CDate& date)
	{
		out << date.day << "/" << date.month << "/" << date.year;
		return out;
	}
	std::string toString() {
		std::stringstream ss;
		ss << *this;
		return ss.str();
	}
	int getYear();
	int getMonth();
	int getDay();

	void inputDate();
	void outputDate();
	bool CheckDate();
	int getDaysInMonth(int);
	bool InspectLeapYear(int year);
	bool InspectLeapYear();

	CDate IncreaseYear();
	CDate IncreaseMonth();
	CDate IncreaseDay();

	CDate DecreaseYear();
	CDate DecreaseMonth();
	CDate DecreaseDay();

	CDate IncreaseYear(int n);
	CDate IncreaseMonth(int n);
	CDate IncreaseDay(int n);

	CDate DecreaseYear(int n);
	CDate DecreaseMonth(int n);
	CDate DecreaseDay(int n);

	int DayOrderInYear();
	int WeekOrderInYear();
	void ConvertDate();


};


#endif CMyTime_h

