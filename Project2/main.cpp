#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

const unsigned char FULL = 219;

int wynik = 0; int druzyna1 = 0; int druzyna2 = 0;

void setCursor(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_screen() {
    wynik = 0;
    cout << "\033[2J\033[1;1H";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    for (int i = 53; i < 99; ++i) {
        for (int j = 4; j < 21; ++j) {
            if ((i % 3 != 1) && (j % 3 != 0)) {
                setCursor(i, j);
                cout << FULL;
            }
        }
    }

    for (int i = 102; i < 107; ++i) {
        for (int j = 4; j < 21; ++j) {
            if ((j % 3 != 0) && (i != 144)) {
                setCursor(i, j);
                cout << FULL;
            }
        }
    }

    setCursor(74, 1);
    cout << FULL;
    setCursor(75, 1);
    cout << FULL;
    setCursor(74, 2);
    cout << FULL;
    setCursor(75, 2);
    cout << FULL;
    setCursor(77, 1);
    cout << FULL;
    setCursor(78, 1);
    cout << FULL;
    setCursor(77, 2);
    cout << FULL;
    setCursor(78, 2);
    cout << FULL;
    setCursor(48, 11);
    cout << druzyna1;
    setCursor(110, 11);
    cout << druzyna2;
}

void big_x(int x, int y) {
    setCursor(x, y);
    cout << "\\";
    setCursor(x + 1, y);
    cout << "/";
    setCursor(x + 1, y + 1);
    cout << "\\";
    setCursor(x, y + 1);
    cout << "/";
}

void small_x(int x, int y) {
    setCursor(x, y);
    cout << "X";
}

void punkty1() {
    druzyna1 += wynik;
    wynik = 0;
    setCursor(48, 11);
    cout << druzyna1;
}

void punkty2() {
    druzyna2 += wynik;
    wynik = 0;
    setCursor(150, 11);
    cout << druzyna2;
}

void aktualizuj_wynik() {
    setCursor(94, 1);
    cout << wynik << "            ";
    setCursor(94, 2);
    cout << "                  ";
}

void podwoj_wynik() {
    wynik *= 2;
    aktualizuj_wynik();
}

int main() {
    Sleep(100);
    draw_screen();
    Sleep(100);
    big_x(43, 21);
    Sleep(100);
    small_x(46, 18);
    Sleep(100);
    wynik = 7;
    aktualizuj_wynik();
    Sleep(100);
    podwoj_wynik();
    Sleep(100);
    punkty1();
    Sleep(100);
    draw_screen();
    Sleep(1000);
    return 0;
}
