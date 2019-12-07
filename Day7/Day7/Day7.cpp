// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//4138687

#include <iostream>
#include <algorithm>

const int programTemplate[] = { 3,8,1001,8,10,8,105,1,0,0,21,34,55,68,93,106,187,268,349,430,99999,3,9,102,5,9,9,1001,9,2,9,4,9,99,3,9,1001,9,5,9,102,2,9,9,101,2,9,9,102,2,9,9,4,9,99,3,9,101,2,9,9,102,4,9,9,4,9,99,3,9,101,4,9,9,102,3,9,9,1001,9,2,9,102,4,9,9,1001,9,2,9,4,9,99,3,9,101,2,9,9,1002,9,5,9,4,9,99,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,99,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,2,9,9,4,9,99,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,2,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,99,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,99 };
int inputCount = 0;
int inputs[2] = { 0, 0 };
int minPhase = 5;
int maxPhase = 9;

int getInput()
{
    return inputs[inputCount++];
}

void writeOutput(int output)
{
    inputs[1] = output;
}

int getParam(int* program, int ip, bool immMode)
{
    if (immMode)
        return program[ip];
    else
        return program[program[ip]];
}

bool popParamMode(int& paramModes)
{
    int nextMode = paramModes % 2;
    paramModes = paramModes / 10;
    return nextMode == 1;
}

int executeOp(int* program, int& ip)
{
    int opCode = program[ip++];
    int op = opCode % 100;
    int paramModes = opCode / 100;

    switch (op)
    {
    case 1:
    {
        int a = getParam(program, ip++, popParamMode(paramModes));
        int b = getParam(program, ip++, popParamMode(paramModes));
        int res = getParam(program, ip++, true);
        program[res] = a + b;
        break;
    }
    case 2:
    {
        int a = getParam(program, ip++, popParamMode(paramModes));
        int b = getParam(program, ip++, popParamMode(paramModes));
        int res = getParam(program, ip++, true);
        program[res] = a * b;
        break;
    }
    case 3:
    {
        int res = getParam(program, ip++, true);
        program[res] = getInput();
        break;
    }
    case 4:
    {
        int a = getParam(program, ip++, popParamMode(paramModes));
        writeOutput(a);
        return 1;
    }
    case 5:
    {
        int cond = getParam(program, ip++, popParamMode(paramModes));
        int loc = getParam(program, ip++, popParamMode(paramModes));
        if (cond != 0)
            ip = loc;
        break;
    }
    case 6:
    {
        int cond = getParam(program, ip++, popParamMode(paramModes));
        int loc = getParam(program, ip++, popParamMode(paramModes));
        if (cond == 0)
            ip = loc;
        break;
    }
    case 7:
    {
        int a = getParam(program, ip++, popParamMode(paramModes));
        int b = getParam(program, ip++, popParamMode(paramModes));
        int res = getParam(program, ip++, true);
        program[res] = (a < b) ? 1 : 0;
        break;
    }
    case 8:
    {
        int a = getParam(program, ip++, popParamMode(paramModes));
        int b = getParam(program, ip++, popParamMode(paramModes));
        int res = getParam(program, ip++, true);
        program[res] = (a == b) ? 1 : 0;
        break;
    }
    case 99:
    {
        return -1;
    }
    default:
        throw "Invalid OpCode";
    }

    return 0;
}

int runProgram(int* program, int& ip)
{
    int status = 0;
    while (status == 0)
    {
        status = executeOp(program, ip);
    }

    return status;
}

void runAmplification(int phases[5])
{
    int* programs[5];
    int ips[5];
    int status[5];
    inputs[1] = 0;

    // Initialize
    for (int i = 0; i < 5; i++)
    {
        int program[sizeof(programTemplate)];
        memcpy_s(program, sizeof(program), programTemplate, sizeof(programTemplate));
        programs[i] = program;
        ips[i] = 0;
        status[i] = 1;
    }

    int i = 0;
    while(status[i] != -1)
    {
        inputCount = (ips[i] == 0) ? 0 : 1;
        inputs[0] = phases[i];
        status[i] = runProgram(programs[i], ips[i]);
        i = (i + 1) % 5;
    }

    if (i != 0) throw "Ended on wrong amplifier";
}


int main()
{
    int maxSignal = 0;

    for (int a = minPhase; a <= maxPhase; a++)
    {
        for (int b = minPhase; b <= maxPhase; b++)
        {
            if (b == a) continue;
            for (int c = minPhase; c <= maxPhase; c++)
            {
                if (c == b || c == a) continue;
                for (int d = minPhase; d <= maxPhase; d++)
                {
                    if (d == c || d == b || d == a) continue;
                    for (int e = minPhase; e <= maxPhase; e++)
                    {
                        if (e == d || e == c || e == b || e == a) continue;
                        int phases[5] = { a,b,c,d,e };
                        runAmplification(phases);
                        int output = inputs[1];
                        if (output > maxSignal)
                            maxSignal = output;
                    }
                }
            }
        }
    }

    std::cout << maxSignal;
}

