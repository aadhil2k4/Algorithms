#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int PRIME = 101; // A prime number for hashing

// Function to calculate hash of a string
long long calculateHash(string& str, int end) {
    long long hash = 0;
    for (int i = 0; i < end; ++i) {
        hash += str[i] * pow(PRIME, i);
    }
    return hash;
}

// Function to recalculate hash by sliding the window
long long recalculateHash(string& str, int oldIndex, int newIndex, long long oldHash, int patternLen) {
    oldHash -= str[oldIndex];
    oldHash /= PRIME;
    oldHash += str[newIndex] * pow(PRIME, patternLen - 1);
    return oldHash;
}

// Rabin-Karp algorithm for pattern matching
vector<int> rabinKarp(string& text, string& pattern) {
    vector<int> result;
    int textLen = text.length();
    int patternLen = pattern.length();

    if (patternLen > textLen) {
        return result;
    }

    // Calculate initial hash values for pattern and text
    long long patternHash = calculateHash(pattern, patternLen);
    long long textHash = calculateHash(text, patternLen);

    // Slide the pattern over the text
    for (int i = 0; i <= textLen - patternLen; ++i) {
        // If the hash values match, check the characters to avoid false positives
        if (patternHash == textHash && text.substr(i, patternLen) == pattern) {
            result.push_back(i); // Match found at index i
        }

        // Recalculate hash for the next window in text
        if (i < textLen - patternLen) {
            textHash = recalculateHash(text, i, i + patternLen, textHash, patternLen);
        }
    }

    return result;
}

int main() {
    string text = "ababcabcababc";
    string pattern = "abc";

    vector<int> occurrences = rabinKarp(text, pattern);

    if (occurrences.empty()) {
        cout << "Pattern not found in the text." << endl;
    }else{
        cout << "Pattern found at indices: ";
        for(int index : occurrences) {
            cout << index << " ";
        }
        cout << endl;
    }
}
