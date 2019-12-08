// Day8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <array>
#include <vector>

const int WIDTH = 25;
const int HEIGHT = 6;
std::vector<std::array<std::array<char, WIDTH>, HEIGHT>> layers;
const char PRINTCHAR[2] = { ' ', '#' };

void  solve()
{
    for (int i = 0; i < HEIGHT; i++) {
        std::cout << "\n|";
        for (int j = 0; j < WIDTH; j++) {
            for (auto k = layers.begin(); k != layers.end(); ++k) {
                char ch = (*k)[i][j];
                if ((ch - '0') < 2) {
                    std::cout << PRINTCHAR[ch - '0'];
                    break;
                }
            }
        }
    }
}

int main()
{
    // Process Input
    std::ifstream infile;
    infile.open("input.txt");
    int rowIdx = 0;
    std::array<std::array<char, 25>, 6> currLayer;
    if (!infile.is_open()) throw "Failed to open file";
    for (std::array<char, WIDTH> a; infile.read(&a[0], WIDTH); ) {
        std::array<char, WIDTH> row(a);
        currLayer[rowIdx] = row;

        rowIdx = (rowIdx + 1) % HEIGHT;
        if (rowIdx == 0) {
            std::array<std::array<char, 25>, 6> completeLayer(currLayer);
            layers.push_back(completeLayer);
        }
    }
    infile.close();

    if (rowIdx != 0) throw "Bad file length";

    solve();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
