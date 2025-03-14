#pragma once

#include <ncurses.h>

namespace NcursesColors {

// GRUVBOX THEME
//  COLOURS
constexpr int BACKGROUND = 0;
constexpr int TITLE = 1;
constexpr int SUB = 2;
constexpr int TEXT = 3;
constexpr int GREEN_TEXT = 4;
constexpr int RED_TEXT = 5;
constexpr int BACKGROUND_CURSOR = 6;
constexpr int SCORE = 7;

// PAIRS
constexpr int TITLEPAIR = 10;
constexpr int SUBPAIR = 11;
constexpr int TEXTPAIR = 12;
constexpr int GREEN_TEXTPAIR = 13;
constexpr int RED_TEXTPAIR = 14;
constexpr int BACKGROUND_CURSORPAIR = 15;
constexpr int SCORE_PAIR = 16;

inline void initGruvBox() {

    // Initialize custom color
    init_color(BACKGROUND, 40 * 1000 / 255, 40 * 1000 / 255, 40 * 1000 / 255);
    init_color(TITLE, 215 * 1000 / 255, 153 * 1000 / 255, 33 * 1000 / 255);
    init_color(SUB, 69 * 1000 / 255, 133 * 1000 / 255, 136 * 1000 / 255);
    init_color(TEXT, 235 * 1000 / 255, 219 * 1000 / 255, 178 * 1000 / 255);
    init_color(GREEN_TEXT, 104 * 1000 / 255, 157 * 1000 / 255, 106 * 1000 / 255);
    init_color(RED_TEXT, 204 * 1000 / 255, 36 * 1000 / 255, 39 * 1000 / 255);
    init_color(BACKGROUND_CURSOR, 178 * 1000 / 255, 98 * 1000 / 255, 134 * 1000 / 255);
    init_color(SCORE, 152 * 1000 / 255, 151 * 1000 / 255, 26 * 1000 / 255);
}

// Initialize color pairs
inline void initGruvBoxPairs() {
    init_pair(TITLEPAIR, TITLE,
              BACKGROUND); // Assign the custom color to pair number 1 with a black background
    init_pair(SUBPAIR, SUB, BACKGROUND);
    init_pair(TEXTPAIR, TEXT, BACKGROUND);
    init_pair(GREEN_TEXTPAIR, GREEN_TEXT, BACKGROUND);
    init_pair(RED_TEXTPAIR, RED_TEXT, BACKGROUND);
    init_pair(BACKGROUND_CURSORPAIR, TEXT, BACKGROUND_CURSOR);
    init_pair(SCORE_PAIR, SCORE, BACKGROUND);
}

/* Catppuccin Color Scheme for Terminal Application
 * Based on the Catppuccin Mocha flavor with custom adjustments
 */

// Color definitions
#define CATPPUCCIN_BASE 0      // Background (deep dark)
#define CATPPUCCIN_ROSEWATER 1 // Primary text
#define CATPPUCCIN_PEACH 2     // Title elements
#define CATPPUCCIN_TEAL 3      // Subtitles/secondary elements
#define CATPPUCCIN_GREEN 4     // Success/correct text
#define CATPPUCCIN_RED 5       // Error/incorrect text
#define CATPPUCCIN_MAUVE 6     // Cursor highlight
#define CATPPUCCIN_YELLOW 7    // Score/highlight elements

inline void init_catppuccin_colors() {
    // Base Catppuccin Mocha colors
    init_color(CATPPUCCIN_BASE, 30 * 1000 / 255, 30 * 1000 / 255, 46 * 1000 / 255); // #1e1e2e
    init_color(CATPPUCCIN_ROSEWATER, 245 * 1000 / 255, 224 * 1000 / 255,
               220 * 1000 / 255);                                                        // #f5e0dc
    init_color(CATPPUCCIN_PEACH, 249 * 1000 / 255, 179 * 1000 / 255, 135 * 1000 / 255);  // #f9b387
    init_color(CATPPUCCIN_TEAL, 148 * 1000 / 255, 226 * 1000 / 255, 213 * 1000 / 255);   // #94e2d5
    init_color(CATPPUCCIN_GREEN, 166 * 1000 / 255, 227 * 1000 / 255, 161 * 1000 / 255);  // #a6e3a1
    init_color(CATPPUCCIN_RED, 243 * 1000 / 255, 139 * 1000 / 255, 168 * 1000 / 255);    // #f38ba8
    init_color(CATPPUCCIN_MAUVE, 203 * 1000 / 255, 166 * 1000 / 255, 247 * 1000 / 255);  // #cba6f7
    init_color(CATPPUCCIN_YELLOW, 249 * 1000 / 255, 226 * 1000 / 255, 175 * 1000 / 255); // #f9e2af

    // Map to your existing color pairs
    // init_pair(BACKGROUND, COLOR_BLACK, CATPPUCCIN_BASE);
    init_pair(TITLEPAIR, CATPPUCCIN_PEACH, CATPPUCCIN_BASE);
    init_pair(SUBPAIR, CATPPUCCIN_TEAL, CATPPUCCIN_BASE);
    init_pair(TEXTPAIR, CATPPUCCIN_ROSEWATER, CATPPUCCIN_BASE);
    init_pair(GREEN_TEXTPAIR, CATPPUCCIN_GREEN, CATPPUCCIN_BASE);
    init_pair(RED_TEXTPAIR, CATPPUCCIN_RED, CATPPUCCIN_BASE);
    init_pair(BACKGROUND_CURSORPAIR, COLOR_BLACK, CATPPUCCIN_MAUVE);
    init_pair(SCORE_PAIR, CATPPUCCIN_YELLOW, CATPPUCCIN_BASE);
}

} // namespace NcursesColors
