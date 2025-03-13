#include "Printer.h"
#include "TType.h"
#include "nCursesConfig.h"

int main() {
    nCursesCFG();

    TType game;

    callTitle(game);

    while (true) {
        game.resetGame();

        if (game.timeTrial) {
            game.runTimeTrial();
        } else {
            game.run();
        }
    }
}
