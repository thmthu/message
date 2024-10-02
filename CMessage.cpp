#include "CMessage.h"
std::vector<std::string> splitTokens(std::string line, const std::string& delimeter)
{
    std::vector<std::string> tokens;
    size_t index = 0;
    while ((index = line.find(delimeter)) != std::string::npos)
    {
        tokens.push_back(line.substr(0, index));

        line.erase(0, index + delimeter.length());
    }

    tokens.push_back(line);

    return tokens;
}
vector<int> converted(string temp, string k) {
    vector<string> a = splitTokens(temp, k);
    vector<int> intValues;
    //cout << a[2];
    for (const string& str : a) {
        stringstream ss(str);
        int intValue;
        ss >> intValue;
        if (!ss.fail()) {
            intValues.push_back(intValue);
        }
    }
    return intValues;
}
void CMessage::input(ifstream& in) {
  /*  ifstream in(fileName);
    if (!in.is_open())
    {
        cout << "cant open!!!!!";
        return;
    }*/
    in >> m_Number >> m_Vote;
    string temp;
    string temp2;
    in >> temp;
    vector<int> date = converted(temp,"/");
    m_Date.setDate(date[0], date[1], date[2]);
    in >> temp2;
    vector<int> time = converted(temp2,":");
    m_Time.setTime(time[0], time[1], time[2]);

}
void CMessage::output(ofstream &out) {

    /*ofstream out(fileName);
    if (!out.is_open())
    {
        cout << "cant open!!!!!";
        return;
    }*/
    out << m_Number << endl << m_Vote << endl;
    out << m_Date.getDay() << "/" << m_Date.getMonth() << "/" << m_Date.getYear() << endl;
    out << m_Time.getH() << ":" << m_Time.getM() << ":" << m_Time.getS() << endl;
}

    
