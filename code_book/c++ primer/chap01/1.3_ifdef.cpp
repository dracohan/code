#include <iostream>
#include <vector>

using namespace std;

int main() {
    string word;
    vector<string> text;

    while (cin >> word) {
        cout << "text read: " << word << endl;
        text.push_back(word);
    }

    return 0;
}