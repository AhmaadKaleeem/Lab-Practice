#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void savegame(const string& filename, const string& targetWord, int attemptsLeft, const vector<string>& board) {
    ofstream outFile(filename);
    if (outFile) {
        outFile << targetWord << "\n";
        outFile << attemptsLeft << "\n";
        for (const auto& row : board) {
            outFile << row << "\n";
        }
    }
}

bool loadgame(const string& filename, string& targetWord, int& attemptsLeft, vector<string>& board) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    getline(inFile, targetWord);
    inFile >> attemptsLeft;
    inFile.ignore();

    board.clear();
    string row;
    while (getline(inFile, row)) {
        board.push_back(row);
    }
    return true;
}

vector<string> loadwords(const string& filename) {
    vector<string> words;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error loading word file.\n";
        return words;
    }

    string word;
    while (getline(inFile, word)) {
        words.push_back(word);
    }
    return words;
}

void createWordsFile(const string& filename) {
    vector<string> words = {
        "about", "acorn", "actor", "admit", "alien", "angel", "apple", "arrow", "asset", "audit", "basic", "beach", "black", "blame", "blend", "blink", "bliss", "block", "blown", "brand", "brave", "brick", "bride", "bring", "brisk", "broke",
"brush", "cabin", "cable", "catch", "charm", "chase", "chart", "chess", "chest", "chick", "chill", "chime", "chose", "claim", "clash", "class", "clear", "clerk", "click", "clock", "cloud", "clown", "coach", "cobra", "couch", "craft",
"crane", "crave", "crawl", "crazy", "cream", "creek", "creep", "crest", "crime", "crisp", "cross", "crown", "crush", "dance", "dandy", "dated", "dazed", "death", "delay", "dense", "depth", "devil", "diced", "dicey", "digit", "ditch",
"eagle", "earth", "elite", "empty", "enter", "entry", "equal", "erase", "ethic", "event", "exact", "exist", "extra", "fable", "faith", "false", "fault", "favor", "feast", "field", "flair", "flame", "flash", "flask", "flint", "float",
"flock", "flour", "focus", "forge", "fresh", "frost", "fruit", "fudge", "gains", "galaxy", "gamer", "giant", "glare", "glide", "glint", "glory", "gnash", "grace", "grasp", "grate", "great", "grind", "groom", "guest", "habit", "hatch",
"heart", "hello", "hoist", "hotel", "house", "hover", "human", "humor", "image", "index", "inner", "ivory", "joker", "joint", "jolly", "juice", "jumpy", "kites", "kneel", "knife", "latch", "layer", "lions", "logic", "lover", "lucky",
"march", "minor", "mount", "naval", "night", "oasis", "optic", "orbit", "overt", "piano", "plant", "prank", "pride", "print", "punch", "quiet", "quilt", "reach", "reset", "river", "rival", "royal", "scale", "scene", "shape", "shock",
"short", "sight", "smile", "snake", "spark", "stack", "stone", "stuck", "taste", "teach", "tiger", "token", "train", "trust", "truth", "ultra", "unity", "vapor", "vital", "vivid", "vowel", "water", "weird", "whale", "whisk", "witty",
"world", "yacht", "yarns", "youth", "zebra", "zones", "zoned", "zesty"
    };

    ofstream outFile(filename);
    if (outFile) {
        for (const auto& word : words) {
            outFile << word << "\n";
        }
    }
    else {
        cerr << "Error creating the word file.\n";
    }
}

int main() {
    const string saveFile = "wordle_save.txt";
    const string wordsFile = "words.txt";  // File containing words list

    vector<string> wordList = loadwords(wordsFile);
    if (wordList.empty()) {
        cout << "No words file found. Creating it now...\n";
        createWordsFile(wordsFile);
        wordList = loadwords(wordsFile);
    }

    srand(static_cast<unsigned int>(time(0)));

    string targetWord;
    int maxAttempts = 6;
    int attemptsLeft = maxAttempts;
    vector<string> board(maxAttempts, "*");

    char choice;
    cout << "Do you want to continue the previous game? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        if (!loadgame(saveFile, targetWord, attemptsLeft, board)) {
            cout << "No saved game found. Starting a new game.\n";
            targetWord = wordList[rand() % wordList.size()];
        }
        else {
            cout << "Game loaded successfully. Resuming...\n";
        }
    }
    else {
        targetWord = wordList[rand() % wordList.size()];
    }

    cout << "Welcome to Wordle! Guess the 5-letter word.\n";

    for (int attempt = maxAttempts - attemptsLeft; attempt < maxAttempts; ++attempt) {
        string guess;
        cout << "Attempt " << attempt + 1 << "/" << maxAttempts << ": ";
        cin >> guess;

        if (guess.size() != 5) {
            cout << "Invalid input. Please enter a 5-letter word.\n";
            --attempt;
            continue;
        }

        string result = "";
        for (int i = 0; i < 5; ++i) {
            if (guess[i] == targetWord[i])
                result += guess[i];
            else if (targetWord.find(guess[i]) != string::npos)
                result += '?';
            else
                result += '*';
        }

        board[attempt] = result;

        for (const auto& row : board)
            cout << row << "\n";

        if (guess == targetWord) {
            cout << "Congratulations! You guessed the word.\n";
            remove(saveFile.c_str());
            return 0;
        }

        --attemptsLeft;
        savegame(saveFile, targetWord, attemptsLeft, board);
    }

    cout << "You've used all attempts! The word was: " << targetWord << "\n";
    remove(saveFile.c_str());
    return 0;
}
