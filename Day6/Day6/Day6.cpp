// Day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <array>
#include <map>
#include <unordered_set>

const std::string COM = "COM";
std::map<std::string, std::unordered_set<std::string>> orbitMap;

void recordOrbit(std::string orbitStr)
{
    size_t delim = orbitStr.find(")");
    std::string center = orbitStr.substr(0, delim);
    std::string orbiter = orbitStr.substr(delim + 1);

    std::map<std::string, std::unordered_set<std::string>>::iterator orbit = orbitMap.find(center);
    if (orbit == orbitMap.end())
    {
        std::pair<std::map<std::string, std::unordered_set<std::string>>::iterator, bool> ret;
        std::unordered_set<std::string> s;
        ret = orbitMap.insert(std::pair< std::string, std::unordered_set<std::string> >(center, s));
        orbit = ret.first;
    }
    orbit->second.insert(orbiter);
}

int countOrbits(std::string center, int depth) {
    std::map<std::string, std::unordered_set<std::string>>::iterator orbit = orbitMap.find(center);
    if (orbit == orbitMap.end()) {
        return 0;
    }

    std::unordered_set<std::string> children = orbit->second;
    int count = children.size() * depth;
    for (auto i = children.begin(); i != children.end(); ++i) {
        count += countOrbits(*i, depth + 1);
    }
    return count;
}

int countDepthTo(std::string a, std::string b)
{
    std::map<std::string, std::unordered_set<std::string>>::iterator orbit = orbitMap.find(a);
    if (orbit == orbitMap.end()) {
        return -1;
    }

    std::unordered_set<std::string> children = orbit->second;
    for (auto i = children.begin(); i != children.end(); ++i) {
        if (*i == b) return 0;
        int subDepth = countDepthTo(*i, b);
        if (subDepth >= 0) return subDepth + 1;
    }
    return -1;
}

std::tuple<bool, bool, std::string> findCommonParent(std::string root, std::string a, std::string b)
{
    std::map<std::string, std::unordered_set<std::string>>::iterator orbit = orbitMap.find(root);
    if (orbit == orbitMap.end()) {
        return std::tuple<bool, bool, std::string>{false, false, ""};
    }

    std::unordered_set<std::string> children = orbit->second;
    bool foundA = false;
    bool foundB = false;
    std::string parent = "";
    for (auto i = children.begin(); i != children.end(); ++i) {
        std::tuple<bool, bool, std::string> result;
        if (*i == a)
        {
            foundA = true;
        }
        else
        {
            result = findCommonParent(*i, a, b);
            foundA = std::get<0>(result);
            foundB = std::get<1>(result);
            parent = std::get<2>(result);
        }

        if (foundA) break;
    }

    if (foundA && !foundB && countDepthTo(root, b) >= 0)
    {
        foundB = true;
        parent = root;
    }

    return { foundA, foundB, parent };
}


int main()
{
    // Process Input
    std::ifstream infile;
    infile.open("input.txt");
    for (std::array<char, 32> a; infile.getline(&a[0], 32); ) {
        std::string orbitStr(&a[0]);
        recordOrbit(orbitStr);
    }
    infile.close();

    // Calculate Result
    // Part 1
    // int result = countOrbits(COM, 1);

    // Part 2
    std::tuple<bool, bool, std::string> parentRes = findCommonParent(COM, "YOU", "SAN");
    if (!std::get<0>(parentRes) || !std::get<1>(parentRes)) throw "FAILED TO FIND COMMON PARENT";
    std::string parent = std::get<2>(parentRes);
    int result = countDepthTo(parent, "YOU") + countDepthTo(parent, "SAN");

    std::cout << result;
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
