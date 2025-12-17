#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H

#include <windows.h>
#include <iostream>

using namespace std;

// Color codes for Windows console
enum ConsoleColor {
    BLACK = 0,
    DARK_BLUE = 1,
    DARK_GREEN = 2,
    DARK_CYAN = 3,
    DARK_RED = 4,
    DARK_MAGENTA = 5,
    DARK_YELLOW = 6,
    LIGHT_GRAY = 7,
    DARK_GRAY = 8,
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    RED = 12,
    MAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

class ColorUtils {
public:
    static void setColor(int foreground, int background = BLACK) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, foreground | (background << 4));
    }
    
    static void resetColor() {
        setColor(LIGHT_GRAY, BLACK);
    }
    
    // Colorful text functions
    static void printColored(const string& text, int color) {
        setColor(color);
        cout << text;
        resetColor();
    }
    
    // Print with background color
    static void printColoredBG(const string& text, int foreground, int background) {
        setColor(foreground, background);
        cout << text;
        resetColor();
    }
    
    // Print title with special formatting
    static void printTitle(const string& text, int color) {
        setColor(color);
        cout << text;
        resetColor();
    }
    
    // Print menu option with color
    static void printMenuOption(const string& text, int color) {
        setColor(color);
        cout << text;
        resetColor();
    }
};

#endif

