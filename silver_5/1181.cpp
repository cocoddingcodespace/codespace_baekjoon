#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool compare(string& lhs, string& rhs) {
    if (lhs.size() == rhs.size()) {
        return lhs < rhs;
    } else {
        return lhs.size() < rhs.size();
    }
}

int main() {
    int n;
    set<string> s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        s.insert(word);
    }

    vector<string> w = vector<string>(s.begin(), s.end());

    sort(w.begin(), w.end(), compare);

    for (int i = 0; i < w.size(); i++) {
        cout << w[i] << endl;
    }

    return 0;
}