#pragma once
#include <iostream>
#include "CMyTime.h"
#include <vector>
#include <fstream>
using namespace std;



class CMessage
{
private:
	string m_Number;
	string m_Vote;
	CDate m_Date;
	CMyTime m_Time;
public:
	CMessage() :m_Number("0"), m_Vote("0"), m_Date(), m_Time() {};
	//m_Number(a.m_Number), m_Vote(a.m_Vote), m_Date(a.m_Date), m_Time(a.m_Time)
	CMessage(const CMessage& a)
	{
		m_Number = a.m_Number;
		m_Vote = a.m_Vote;
		m_Date = a.m_Date;
		m_Time = a.m_Time;
	};
	string getVote() const { return m_Vote; }
	string getNum() { return m_Number; }
	CDate getDate() { return m_Date; }
	CMyTime getTime() { return m_Time; };
	void input(ifstream &in);
	void output(ofstream &out);


};

