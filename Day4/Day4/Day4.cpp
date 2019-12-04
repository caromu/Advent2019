// Day4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

bool containsDoubleDigit(std::string pw)
{
    int matchingRun = 1;
    char previous = '\0';
    for (size_t i = 0; i < pw.length(); i++)
    {
        if (pw[i] == previous)
        {
            matchingRun++;
        }
        else if (matchingRun == 2)
        {
            return true;
        }
        else
        {
            matchingRun = 1;
        }

        previous = pw[i];
    }
    return matchingRun == 2;
}

bool digitsIncreasing(std::string pw)
{
    for (size_t i = 1; i < pw.length(); i++)
    {
        if (pw[i] < pw[i - 1]) return false;
    }
    return true;
}

int main()
{
    int validPws = 0;
    for (int i = 152085; i < 670283; i++) {
        std::string pw = std::to_string(i);
        if (containsDoubleDigit(pw) && digitsIncreasing(pw)) validPws++;
    }
    std::cout << validPws;
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
