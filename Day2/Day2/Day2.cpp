// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//4138687

#include <iostream>
#include <algorithm>

const int target = 19690720;

const int programTemplate[] = {
    1,0,0,3,
    1,1,2,3,
    1,3,4,3,
    1,5,0,3,
    2,6,1,19,
    1,19,10,23,
    2,13,23,27,
    1,5,27,31,
    2,6,31,35,
    1,6,35,39,
    2,39,9,43,
    1,5,43,47,
    1,13,47,51,
    1,10,51,55,
    2,55,10,59,
    2,10,59,63,
    1,9,63,67,
    2,67,13,71,
    1,71,6,75,
    2,6,75,79,
    1,5,79,83,
    2,83,9,87,
    1,6,87,91,
    2,91,6,95,
    1,95,6,99,
    2,99,13,103,
    1,6,103,107,
    1,2,107,111,
    1,111,9,0,
    99,
    2,14,0,0
};

void executeOp(int * program, int op, int idxA, int idxB, int idxRes)
{
    if (op == 1)
    {
        program[idxRes] = program[idxA] + program[idxB];
    }
    else if (op == 2)
    {
        program[idxRes] = program[idxA] * program[idxB];
    }
    else
    {
        throw "Invalid OpCode";
    }
}

int runProgram(int noun, int verb) {
    int program[sizeof(programTemplate)];
    memcpy_s(program, sizeof(program), programTemplate, sizeof(programTemplate));

    int ip = 0;

    program[1] = noun;
    program[2] = verb;

    while (program[ip] != 99)
    {
        executeOp(program, program[ip], program[ip + 1], program[ip + 2], program[ip + 3]);
        ip += 4;
    }

    return program[0];
}


int main()
{
    int result = 0;
    for (int noun = 0; noun < 100; noun++)
    {
        for (int verb = 0; verb < 100; verb++)
        {
            if (runProgram(noun, verb) == target)
            {
                std::cout << noun * 100 + verb;
                return 0;
            }
        }
    }
}

