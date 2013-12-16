#include <iostream>
#include <sstream>
#include <map>
using namespace std;

string countAndStay(int n) {
    string str;
    if (n == 1) {
        return "1";
    }
    else {
        str = "1";
    }
    for (int i = 1; i < n; i++) {
        stringstream ss;
        for (int j = 0; j < str.length(); j++) {
            int cnt = 1;
            while (j + 1 < str.length() && str[j] == str[j + 1]) {
                j++;
                cnt++;
            }
            ss << cnt;
            ss << str[j];
        }
        str = ss.str();
    }
    return str;
}

int main() {
    cout << countAndStay(1) << endl;
    cout << countAndStay(2) << endl;
    cout << countAndStay(3) << endl;
    cout << countAndStay(4) << endl;
    cout << countAndStay(5) << endl;
    cout << countAndStay(6) << endl;
    cout << countAndStay(7) << endl;
    cout << countAndStay(8) << endl;
    cout << countAndStay(9) << endl;
    cout << countAndStay(10) << endl;
    return 0;
}
