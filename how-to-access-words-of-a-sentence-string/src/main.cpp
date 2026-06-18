#include <bits/stdc++.h>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Create a stringstream object
    stringstream ss(sentence);
    string word;

    // Vector to store the words
    vector<string> words;

    // Extract words from the stringstream
    while (ss >> word) {
        words.push_back(word);
    }

    // Output the words
    cout << "The words are:\n";
    for (const string& w : words) {
        cout << w << endl;
    }

    return 0;
}