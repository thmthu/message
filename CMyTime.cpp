#include "CMyTime.h"
CMyTime::CMyTime() : m_Hour(0), m_Minute(0), m_Sencond(0) {}

CMyTime::CMyTime(CMyTime& a) : m_Hour(a.m_Hour), m_Minute(a.m_Minute), m_Sencond(a.m_Sencond) {}/* {
	m_Hour = a.getH();
	m_Minute = a.getM();
	m_Sencond = a.getS();
}*/

CMyTime::CMyTime(int h, int s, int m) : m_Hour(h), m_Minute(m), m_Sencond(s) {

};
void CMyTime::Input(const char* fileName, int n) {
	ifstream in(fileName);
	if (!in.is_open())
	{
		cout << "cant open file";
		return;
	}
	int pos = 0;
	int h, s, m;
	while (in >> h >> m >> s)
	{
		if (pos == n)
		{
			m_Hour = h;
			m_Minute = m;
			m_Sencond = s;
			in.close();
			return;
		}
		pos++;
	}
	in.close();
	return;

};
void CMyTime::Output(const char* fileName) {
	ofstream fp;
	fp.open(fileName, ios::app);
	if (!fp.is_open())
	{
		cout << "cant open file";
		return;
	}
	fp << setw(2) << setfill('0') << m_Hour << ":";
	fp << setw(2) << setfill('0') << m_Minute << ":";
	fp << setw(2) << setfill('0') << m_Sencond << "\n";
	fp.close();
};

CMyTime CMyTime::operator++() {

	m_Sencond = (m_Sencond + 1) % 60;
	if (m_Sencond == 0)
		m_Minute = (m_Minute + 1) % 60;
	if (m_Minute == 0)
		m_Hour = (m_Hour + 1) % 24;

	return *this;
};
CMyTime CMyTime::operator--() {

	m_Minute = m_Minute - 1;

	if (m_Minute == -1) {
		m_Minute = 59;
		if (m_Hour == 0)
			m_Hour = 23;
		else m_Hour--;
	}

	return *this;
};
CMyTime CMyTime::operator+=(int n) {
	m_Hour = (m_Hour + n) % 24;
	return *this;
};
CMyTime CMyTime::operator-=(int n) {
	int s = m_Hour - n;
	if (s < 0)
		cout << "N vuot qua so gio";
	else m_Hour = m_Hour - n;

	return *this;
};
CMyTime convertToTime(int a) {
	a = abs(a);
	int absoluteSeconds = abs(a);

	int hours = absoluteSeconds / 3600;
	int remainingSeconds = absoluteSeconds % 3600;
	int minutes = remainingSeconds / 60;
	int seconds = remainingSeconds % 60;

	CMyTime result(hours, seconds, minutes);

	return result;

}
int convertToSecond(CMyTime a) {
	return a.getH() * 3600 + a.getM() * 60 + a.getS();
}
CMyTime CMyTime::operator+(CMyTime& a) {
	*this = convertToTime(convertToSecond(a) + convertToSecond(*this));
	return *this;

};
CMyTime CMyTime::operator-(CMyTime& a) {
	*this = convertToTime(convertToSecond(a) - convertToSecond(*this));
	return *this;
};
bool CMyTime::operator>(CMyTime& a) {
	return convertToSecond(a) < convertToSecond(*this);
};
bool CMyTime::operator<(CMyTime& a) {
	return convertToSecond(a) > convertToSecond(*this);
};
bool CMyTime::operator>=(CMyTime& a) {
	return convertToSecond(a) <= convertToSecond(*this);
};
bool CMyTime::operator<=(CMyTime& a) {
	return convertToSecond(a) >= convertToSecond(*this);
};
bool CMyTime::operator==(CMyTime& a) {
	return convertToSecond(a) == convertToSecond(*this);
};
int CDate::getYear() { return year; };
int CDate::getMonth() { return month; };
int CDate::getDay() { return day; };
void CDate::inputDate() {
	int a;
	for (int i = 0; i < 3; i++) {
		cin >> a;
		*(&year + i) = a;
	}
}
void CDate::outputDate() {
	cout << day << "-" << month << "-" << year;
};
bool checkMonth(int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
		return true;
	return false;

}
bool CDate::InspectLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int CDate::getDaysInMonth(int month) {
	if (month == 2) {
		return InspectLeapYear() ? 29 : 28;
	}
	else {
		return checkMonth(month) ? 31 : 30;
	}
}
bool CDate::InspectLeapYear() {
	return InspectLeapYear(year);
}
bool CDate::CheckDate() {
	if (year < 0 || month <= 0 || month > 12 || day < 0)
		return false;
	if (day > getDaysInMonth(month))
		return false;
	return true;

};

CDate CDate::IncreaseYear() {
	if (InspectLeapYear())
	{
		if (month == 2 && day == 29)
			day = 28;
	}
	year++;

	return *this;
};
CDate CDate::IncreaseMonth() {
	if (month == 12) year++;
	month = 1 + month % 12;
	if (day > getDaysInMonth(month))
		day = getDaysInMonth(month);
	return *this;
};
CDate CDate::IncreaseDay() {
	int daysInMonth = getDaysInMonth(month);
	if (month == 12 && day == 31) {
		year++;
		month = 1;day = 1;
		return *this;
	}
	if (day == daysInMonth) {
		month = (month % 12) + 1;
		day = 1;
	}
	else {
		day++;
	}
	return *this;
};

CDate CDate::DecreaseYear() {
	bool isLastYearLeap = InspectLeapYear(year - 1);
	if (month == 2 && day == 29 && !isLastYearLeap) {
		day = 28;
	}
	year--;
	return *this;
}
CDate CDate::DecreaseMonth() {
	if (month == 1) {
		month = 12;
		year--;
		return *this;
	}
	if (month > 1) {
		month--;
	}
	else {
		month = 12;
		year--;
	}
	int daysInMonth = getDaysInMonth(month);
	if (day > daysInMonth) {
		day = daysInMonth;
	}
	return *this;
}
CDate CDate::DecreaseDay() {
	if (day > 1) {
		day--;
	}
	else {
		if (month > 1) {
			month--;
			if (month == 2) {
				day = InspectLeapYear() ? 29 : 28;
			}
			else {
				day = checkMonth(month) ? 31 : 30;
			}
		}
		else {
			month = 12;
			day = 31;
			year--;
		}
	}
	return *this;
}

CDate CDate::IncreaseYear(int n) {
	year = year + n;
	if (month == 2 && day == 29 && !InspectLeapYear(year)) {
		day--;
	}
	return *this;
}
CDate CDate::IncreaseMonth(int n) {
	for (int i = 1; i <= n;i++) {
		IncreaseMonth();
	}
	return *this;
}
CDate CDate::IncreaseDay(int n) {
	for (int i = 1; i <= n;i++) {
		IncreaseDay();
	}
	return *this;
}

CDate CDate::DecreaseYear(int n) {
	if (month == 2 && day == 29 && !InspectLeapYear(year - n))
		day = 28;
	year -= n;
	return *this;
}
CDate CDate::DecreaseMonth(int n) {
	for (int i = 1; i <= n;i++) {
		DecreaseMonth();
	}
	return *this;
};
CDate CDate::DecreaseDay(int n) {
	for (int i = 1; i <= n;i++) {
		DecreaseDay();
	}
	return *this;
}

int CDate::DayOrderInYear() {
	int s = 0;
	for (int i = 1;i < month;i++) {
		s += getDaysInMonth(i);
	}
	s += day;
	return s;

}
int CDate::WeekOrderInYear() {
	return (DayOrderInYear() - 1) / 7 + 1;
}
void CDate::ConvertDate() {
	string monthNames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	cout << monthNames[month - 1] << " " << day << ", " << year << endl;
}


