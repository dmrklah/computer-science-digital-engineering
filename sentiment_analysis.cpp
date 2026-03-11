/*
 * Sentiment Analysis Program
 * Module: Computer Science and Digital Engineering
 * Degree: BSc Computer Science and Digitization
 *
 * Description:
 * This program evaluates the sentiment of user-entered text
 * and displays the result as an ASCII art shape.
 *
 * Compile: g++ -o sentiment sentiment_analysis.cpp
 * Run:     ./sentiment
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;

// Predefined positive and negative word lists
vector<string> positiveWords = {
    "good", "happy", "joy", "love", "excellent", "awesome", "great", "fantastic",
    "wonderful", "amazing", "brilliant", "superb", "positive", "beautiful", "best"
};

vector<string> negativeWords = {
    "bad", "sad", "hate", "terrible", "horrible", "awful", "worst", "angry", "negative",
    "ugly", "dreadful", "poor", "disgusting", "disappointing", "depressing"
};

// ----------- Utility functions -----------

// Convert string to lowercase
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    return s;
}

// Remove punctuation from a word
string sanitize(const string &w) {
    string out;
    for (char c : w) {
        if (isalnum((unsigned char)c) || c=='\'') out.push_back(c);
    }
    return out;
}

// Simple stemmer: remove common suffixes to normalize tokens
string simpleStem(const string &w) {
    string s = w;
    if (s.length() > 4) {
        if (s.size() > 3 && s.substr(s.size()-3) == "ing") s = s.substr(0, s.size()-3);
        else if (s.size() > 2 && s.substr(s.size()-2) == "ed") s = s.substr(0, s.size()-2);
        else if (s.size() > 1 && s.back() == 's') s = s.substr(0, s.size()-1);
    } else if (s.size() > 2 && s.back() == 's') {
        s = s.substr(0, s.size()-1);
    }
    return s;
}

// Tokenize input into cleaned, lowercase words
vector<string> tokenize(string input) {
    stringstream ss(input);
    string word;
    vector<string> tokens;

    while (ss >> word) {
        // Remove punctuation from word
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        tokens.push_back(toLower(word));
    }
    return tokens;
}

// Analyse sentiment score from tokens
string analyzeSentiment(const vector<string>& tokens,
                         float& score,
                         vector<string>& matchedPos,
                         vector<string>& matchedNeg) {
    score = 0;
    for (const string& token : tokens) {
        string stemmed = simpleStem(token);

        // Check positive words
        for (const string& pw : positiveWords) {
            if (token == pw || stemmed == pw) {
                score++;
                matchedPos.push_back(token);
                break;
            }
        }
        // Check negative words
        for (const string& nw : negativeWords) {
            if (token == nw || stemmed == nw) {
                score--;
                matchedNeg.push_back(token);
                break;
            }
        }
    }

    // Classify sentiment
    if (score > 0.5)  return "Positive";
    if (score < -0.5) return "Negative";
    return "Neutral";
}

// Display ASCII art shape based on sentiment
void displaySentimentShape(const string& sentiment, float score) {
    cout << "\n--- Sentiment Analysis Result ---\n";

    if (sentiment == "Positive") {
        cout << "Overall Sentiment: POSITIVE (score=" << score << ")\n\n";
        cout << "     .-\"\"\"\"-.     \n";
        cout << "    .'  _ _  '.   \n";
        cout << "   /   (o o)   \\  \n";
        cout << "  |    ( ^ )    | \n";
        cout << "   \\  '-----'  /  \n";
        cout << "    '.______.'    \n";
        cout << "       POSITIVE   \n";

    } else if (sentiment == "Negative") {
        cout << "Overall Sentiment: NEGATIVE (score=" << score << ")\n\n";
        cout << "     .--------.   \n";
        cout << "    /  .-. .   \\  \n";
        cout << "   |  ( >_< )  |  \n";
        cout << "    \\  '---'  /   \n";
        cout << "     '------'     \n";
        cout << "       NEGATIVE   \n";

    } else {
        cout << "Overall Sentiment: NEUTRAL (score=" << score << ")\n\n";
        cout << "     .--------.   \n";
        cout << "    /  .- . -  \\  \n";
        cout << "   |   | : |   |  \n";
        cout << "    \\  '---'  /   \n";
        cout << "     '------'     \n";
        cout << "       NEUTRAL    \n";
    }
}

int main() {
    string userInput;
    cout << "Enter a sentence or paragraph for sentiment analysis:\n";
    getline(cin, userInput);

    vector<string> tokens = tokenize(userInput);
    float score = 0;
    vector<string> matchedPos, matchedNeg;

    string sentiment = analyzeSentiment(tokens, score, matchedPos, matchedNeg);
    displaySentimentShape(sentiment, score);

    // Write execution log as proof
    ofstream log("execution_log.txt", ios::app);
    if (log.is_open()) {
        auto now = chrono::system_clock::now();
        time_t tnow = chrono::system_clock::to_time_t(now);
        log << "------\nTime: " << std::ctime(&tnow);
        log << "Input: " << userInput << "\n";
        log << "Sentiment: " << sentiment << "  Score: " << score << "\n";
        log << "PositiveMatches:";
        for (auto &w : matchedPos) log << " " << w;
        log << "\nNegativeMatches:";
        for (auto &w : matchedNeg) log << " " << w;
        log << "\n\n";
        log.close();
    } else {
        cerr << "Warning: Could not open execution_log.txt to write proof.\n";
    }

    return 0;
}
