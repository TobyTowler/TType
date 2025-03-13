#include "fileSelector.h"
#include "Colours.h"
#include "Printer.h"
#include <filesystem>
#include <fstream>
#include <iterator>
#include <ncurses.h>
#include <vector>

/*
 * fileSelector
 * keyboard up and down selector
 * search fuzzy find
 */

string fileSelector(string path) {
    vector<string> files;
    for (const auto &entry : filesystem::directory_iterator(path)) {
        files.push_back(entry.path().filename().string());
    }
    string chosen = files[0];

    bool play = true;
    int selected = 0;
    while (play) {
        clear();
        printw("Available Files: ");
        for (int i = 0; i < files.size(); i++) {
            if (i == selected) {
                attron(COLOR_PAIR(NcursesColors::BACKGROUND_CURSORPAIR));
                printw("\n  %s", files[i].c_str());
                attroff(COLOR_PAIR(NcursesColors::BACKGROUND_CURSORPAIR));
            } else {
                printw("\n  %s", files[i].c_str());
            }
        }

        attron(COLOR_PAIR(NcursesColors::SUBPAIR));
        printw("\n\n\n Binds: \n");
        printw(" 'J': down  'K': up  'Enter': select");
        attroff(COLOR_PAIR(NcursesColors::SUBPAIR));

        int ch = getch();
        switch (ch) {
        case 'j':
            selected++;
            if (selected > files.size() - 1) {
                selected = 0;
            }
            break;
        case 'k':
            selected--;
            if (selected < 0) {
                selected = files.size() - 1;
            }
            break;
        case 10:
            chosen = selected;
            play = false;
            break;
        }
    }

    return files[selected];
}

void createFile(TType &obj) {
    clear();

    obj.quit = false;
    obj.input.clear();

    while (!obj.quit) {
        clear();
        printw("ENTER TITLE: \n");
        for (auto c : obj.input) {
            printw("%c", c);
        }

        printw("\n\nENTER to continue");
        obj.getInput();
    }

    string fileName(obj.input.begin(), obj.input.end());
    obj.input.clear();

    obj.quit = false;
    while (!obj.quit) {
        clear();
        printw("ENTER CONTENT: \n");
        for (auto c : obj.input) {
            printw("%c", c);
        }
        printw("\n\nENTER to continue");
        obj.getInput();
    }

    ofstream file("./../text/" + fileName + ".txt");
    string line(obj.input.begin(), obj.input.end());
    file << line;
    file.close();
    callTitle(obj);
}
