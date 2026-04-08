// 5-1
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;


struct Rotation {
    string left;
    string right;
};


bool compareRotations(const Rotation& a, const Rotation& b) {
    string leftStr = a.right;
    string rightStr = b.right;


    transform(leftStr.begin(), leftStr.end(), leftStr.begin(), ::tolower);
    transform(rightStr.begin(), rightStr.end(), rightStr.begin(), ::tolower);

    return leftStr < rightStr;
}

void printPermutedIndex(const vector<string>& lines) {
    vector<Rotation> all_rotations;
    size_t max_left_len = 0;

    for (const string& line : lines) {
        vector<string> words;
        stringstream ss(line);
        string word;


        while (ss >> word) {
            words.push_back(word);
        }


        for (size_t i = 0; i < words.size(); ++i) {
            string left_part = "";
            string right_part = "";

            for (size_t j = 0; j < words.size(); ++j) {
                if (j < i) {
                    left_part += (left_part.empty() ? "" : " ") + words[j];
                }
                else {
                    right_part += (right_part.empty() ? "" : " ") + words[j];
                }
            }
            all_rotations.push_back({ left_part, right_part });
            max_left_len = max(max_left_len, left_part.length());
        }
    }


    sort(all_rotations.begin(), all_rotations.end(), compareRotations);


    for (const auto& rot : all_rotations) {

        cout << setw(max_left_len) << rot.left << "  " << rot.right << endl;
    }
}

int main() {
    vector<string> input_data = {
        "The quick brown fox",
        "jumped over the fence"
    };

    printPermutedIndex(input_data);

    return 0;
}