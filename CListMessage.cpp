#include "CListMessage.h"
void CListMessage::Input(const char* fp) {
	ifstream in(fp);

	in >> m_Amount;
	for (int i = 0;i < m_Amount;i++) {
		CMessage a;
		a.input(in);
		m_Message.push_back(a);

	}
	in.close();

	
};
void  CListMessage::Output(const char* fp){
	ofstream out(fp);
	out << m_Amount << endl;
	for (int i = 0;i < m_Amount;i++) {
		m_Message[i].output(out);

	}
	out.close();


};



string findMostFrequentString(const vector<string>& vec) {
	unordered_map<string, int> freqMap;

	for (const string& str : vec) {
		freqMap[str]++;
	}

	string mostFrequentString;
	int maxFrequency = 0;

	for (const auto& pair : freqMap) {
		if (pair.second > maxFrequency) {
			maxFrequency = pair.second;
			mostFrequentString = pair.first;
		}
	}

	return mostFrequentString;
}
int  CListMessage::FindCode() {
	vector<string> a;
	for (int i = 0;i < m_Amount;i++) {
		a.push_back(m_Message[i].getVote());
	}
	stringstream ss(findMostFrequentString(a));
	int intValue;
	ss >> intValue;
	return intValue;

};
string  CListMessage::FindPhone() {
	vector<string> a;
	for (int i = 0;i < m_Amount;i++) {
		a.push_back(m_Message[i].getNum());
	}
	return findMostFrequentString(a);
}
template<typename T> T SortFre(std::unordered_map<T, int>& m) {
	std::vector<std::pair<T, int>> p;

	for (auto& it : m) {
		p.push_back(it);
	}

	std::sort(p.begin(), p.end(), [](const std::pair<T, int>& lhs, const std::pair<T, int>& rhs) -> bool {
		return lhs.second > rhs.second; });

	return p[0].first;
}


CDate CListMessage::FindDate() {
	unordered_map <string, int> date;
	for (auto& it : m_Message) {
		CDate d = it.getDate();
		string cur = d.toString();
		if (date.find(cur) != date.end())date[cur]++;
		else date.insert({ cur, 0 });
	}
	std::string d = SortFre(date);
	CDate result(d);
	return result;
}

void CListMessage::Top10() {
	std::unordered_map<std::string, int> voteCount;

	for (const auto& message : m_Message) {
		std::string currentVote = message.getVote();
		voteCount[currentVote]++;
	}

	std::vector<std::pair<std::string, int>> votePairs;
	for (const auto& pair : voteCount) {
		votePairs.push_back(pair);
	}

	std::sort(votePairs.begin(), votePairs.end(), [](const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) {
		return lhs.second > rhs.second;
		});

	cout << "\nTop 10:" << std::endl;
	int count = 0;
	for (const auto& pair : votePairs) {
		if (count < 10) {
			cout << count<< ". " << pair.first << endl;
			count++;
		}
		else {
			break;
		}
	}
}
