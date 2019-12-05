// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//4138687

#include <iostream>
#include <algorithm>

const int target = 19690720;

const int programTemplate[] = {3,225,1,225,6,6,1100,1,238,225,104,0,101,14,135,224,101,-69,224,224,4,224,1002,223,8,223,101,3,224,224,1,224,223,223,102,90,169,224,1001,224,-4590,224,4,224,1002,223,8,223,1001,224,1,224,1,224,223,223,1102,90,45,224,1001,224,-4050,224,4,224,102,8,223,223,101,5,224,224,1,224,223,223,1001,144,32,224,101,-72,224,224,4,224,102,8,223,223,101,3,224,224,1,223,224,223,1102,36,93,225,1101,88,52,225,1002,102,38,224,101,-3534,224,224,4,224,102,8,223,223,101,4,224,224,1,223,224,223,1102,15,57,225,1102,55,49,225,1102,11,33,225,1101,56,40,225,1,131,105,224,101,-103,224,224,4,224,102,8,223,223,1001,224,2,224,1,224,223,223,1102,51,39,225,1101,45,90,225,2,173,139,224,101,-495,224,224,4,224,1002,223,8,223,1001,224,5,224,1,223,224,223,1101,68,86,224,1001,224,-154,224,4,224,102,8,223,223,1001,224,1,224,1,224,223,223,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,108,226,677,224,1002,223,2,223,1006,224,329,1001,223,1,223,1007,226,226,224,1002,223,2,223,1006,224,344,101,1,223,223,1008,226,226,224,102,2,223,223,1006,224,359,1001,223,1,223,107,226,677,224,1002,223,2,223,1005,224,374,101,1,223,223,1107,677,226,224,102,2,223,223,1006,224,389,101,1,223,223,108,677,677,224,102,2,223,223,1006,224,404,1001,223,1,223,1108,677,226,224,102,2,223,223,1005,224,419,101,1,223,223,1007,677,226,224,1002,223,2,223,1006,224,434,101,1,223,223,1107,226,226,224,1002,223,2,223,1006,224,449,101,1,223,223,8,677,226,224,102,2,223,223,1006,224,464,1001,223,1,223,1107,226,677,224,102,2,223,223,1005,224,479,1001,223,1,223,1007,677,677,224,102,2,223,223,1005,224,494,1001,223,1,223,1108,677,677,224,102,2,223,223,1006,224,509,101,1,223,223,1008,677,677,224,102,2,223,223,1005,224,524,1001,223,1,223,107,226,226,224,1002,223,2,223,1005,224,539,101,1,223,223,7,226,226,224,102,2,223,223,1005,224,554,101,1,223,223,1108,226,677,224,1002,223,2,223,1006,224,569,1001,223,1,223,107,677,677,224,102,2,223,223,1005,224,584,101,1,223,223,7,677,226,224,1002,223,2,223,1005,224,599,101,1,223,223,108,226,226,224,1002,223,2,223,1005,224,614,101,1,223,223,1008,677,226,224,1002,223,2,223,1005,224,629,1001,223,1,223,7,226,677,224,102,2,223,223,1005,224,644,101,1,223,223,8,677,677,224,102,2,223,223,1005,224,659,1001,223,1,223,8,226,677,224,102,2,223,223,1006,224,674,1001,223,1,223,4,223,99,226 };

int getInput()
{
    int input;
    std::cin >> input;
    return input;
}

void writeOutput(int output)
{
    std::cout << output;
}

int getParam(int* program, int ip, bool immMode)
{
    if (immMode)
        return program[ip];
    else
        return program[program[ip]];
}

bool getNextParamMode(int &paramModes)
{
    int nextMode = paramModes % 2;
    paramModes = paramModes / 10;
    return nextMode == 1;
}

void executeOp(int* program, int& ip)
{
    int opCode = program[ip++];
    int op = opCode % 100;
    int paramModes = opCode / 100;
    switch (op)
    {
    case 1:
    {
        int a = getParam(program, ip++, getNextParamMode(paramModes));
        int b = getParam(program, ip++, getNextParamMode(paramModes));
        int res = getParam(program, ip++, true);
        program[res] = a + b;
        return;
    }
    case 2:
    {
        int a = getParam(program, ip++, getNextParamMode(paramModes));
        int b = getParam(program, ip++, getNextParamMode(paramModes));
        int res = getParam(program, ip++, true);
        program[res] = a * b;
        return;
    }
    case 3:
    {
        int res = getParam(program, ip++, true);
        program[res] = getInput();
        return;
    }
    case 4:
    {
        int a = getParam(program, ip++, getNextParamMode(paramModes));
        writeOutput(a);
        return;
    }
    case 5:
    {
        int cond = getParam(program, ip++, getNextParamMode(paramModes));
        int loc = getParam(program, ip++, getNextParamMode(paramModes));
        if (cond != 0)
            ip = loc;
        return;
    }
    case 6:
    {
        int cond = getParam(program, ip++, getNextParamMode(paramModes));
        int loc = getParam(program, ip++, getNextParamMode(paramModes));
        if (cond == 0)
            ip = loc;
        return;
    }
    case 7:
    {
        int a = getParam(program, ip++, getNextParamMode(paramModes));
        int b = getParam(program, ip++, getNextParamMode(paramModes));
        int res = getParam(program, ip++, true);
        program[res] = (a < b) ? 1 : 0;
        return;
    }
    case 8:
    {
        int a = getParam(program, ip++, getNextParamMode(paramModes));
        int b = getParam(program, ip++, getNextParamMode(paramModes));
        int res = getParam(program, ip++, true);
        program[res] = (a == b) ? 1 : 0;
        return;
    }
    default:
        throw "Invalid OpCode";
    }
}

void runProgram()
{
    int program[sizeof(programTemplate)];
    memcpy_s(program, sizeof(program), programTemplate, sizeof(programTemplate));

    int ip = 0;

    while (program[ip] != 99)
    {
        executeOp(program, ip);
    }
}


int main()
{
    runProgram();
}
