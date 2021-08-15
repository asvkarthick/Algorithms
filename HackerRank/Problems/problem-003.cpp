#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    std::string militaryTime = "";
    if (s[s.length() - 2] == 'A') {
        if (s[0] == '1' && s[1] == '2') {
            militaryTime += "00";
        } else {
            militaryTime.append(s.substr(0, 2));
        }
    } else if (s[s.length() - 2] == 'P') {
        int hour = s[0] - '0';
        hour = hour * 10 + (s[1] - '0');
        if (s[0] == '1' && s[1] == '2')
            militaryTime.append(s.substr(0, 2));
        else
            militaryTime += std::to_string(hour + 12);
    }
    militaryTime += s.substr(2, 6);
    return militaryTime;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
