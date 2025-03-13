#ifndef TTYPE_H
#define TTYPE_H
#include <string>
#include <vector>

using namespace std;

class TType {
  private:
    string words;
    double runTime;
    int numberOfCorrectWords;
    bool randomWorded;
    int ch;

  public:
    vector<int> input;
    string inputFile;
    bool timeTrial;
    bool quit = false;

    TType();

    void setWords(string fileName); // Custom text

    void clearInput();

    void checkChar();

    void getInput();

    void run();

    void runTimeTrial();

    int getNumberOfSpaces();

    int getRawWPM();

    void checkCharAndRealWPM();

    int getAccuracy();

    void printScore();

    void resetGame();

    void setLines();

    string readFile(string fileName);

    void setRandomWords(string fileName);
};

#endif // TTYPE_H
