#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class GameEntry {
public:
    GameEntry(const std::string& n = "", int s = 0) : name(n), score(s) {}
    std::string getName() const { return name; }
    int getScore() const { return score; }
private:
    std::string name;
    int score;
};

class Scores {
public:
    Scores(int maxEnt = 10) : maxEntries(maxEnt), entries(maxEntries), numEntries(0) {}
    ~Scores() {}
    void add(const GameEntry& e);
    GameEntry remove(int i); // Updated: removed throw specifier
    friend std::ostream& operator<<(std::ostream& os, const Scores& scores);
private:
    int maxEntries;
    std::vector<GameEntry> entries;
    int numEntries;
};

void Scores::add(const GameEntry& e) {
    int newScore = e.getScore();
    if (numEntries == maxEntries) {
        if (newScore <= entries[maxEntries - 1].getScore()) return;
    } else numEntries++;

    int i = numEntries - 2;
    while (i >= 0 && newScore > entries[i].getScore()) {
        entries[i + 1] = entries[i];
        i--;
    }
    entries[i + 1] = e;
}

GameEntry Scores::remove(int i) {
    if ((i < 0) || (i >= numEntries)) throw std::range_error("Invalid index");
    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++) entries[j - 1] = entries[j];
    numEntries--;
    return e;
}

std::ostream& operator<<(std::ostream& os, const Scores& scores) {
    for (int j = 0; j < scores.numEntries; j++) {
        os << scores.entries[j].getName() << ", " << scores.entries[j].getScore() << std::endl;
    }
    return os;
}

int main() {
    Scores scores(5);  // A scoreboard with a capacity for 5 entries
    GameEntry ge1("Alice", 110);
    GameEntry ge2("Bob", 150);
    GameEntry ge3("Cindy", 120);

    scores.add(ge1);
    scores.add(ge2);
    scores.add(ge3);

    std::cout << scores;

    try {
        scores.remove(1);  // Remove the entry at index 1 (Cindy)
    } catch (const std::range_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "After removal:" << std::endl;
    std::cout << scores;

    return 0;
}
