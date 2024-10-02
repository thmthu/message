#include "CListMessage.h"
int main() {
	CListMessage a;
	a.Input("Text.txt");
	a.Output("Text1.txt");
	cout << "\nMa so duoc binh chon nhieu nhat: " << a.FindCode();
	cout << "\nSDT nhan nhieu nhat: " << a.FindPhone();
	CDate temp = a.FindDate();
	cout << "\nNgay nhan tin nhieu nhat: " << temp.getDay() << "/" << temp.getMonth() << "/" << temp.getYear();
	a.Top10();
}
