#pragma once
#include"CMessage.h"
#include <algorithm>
#include <unordered_map>

class CListMessage
{
private:
	vector <CMessage> m_Message;
	int m_Amount;
public:
	CListMessage():m_Amount(0) {}
	void Input(const char* fp);
	void Output(const char* fp);
	int FindCode();
	string FindPhone();
	CDate FindDate();
	void Top10();
};

