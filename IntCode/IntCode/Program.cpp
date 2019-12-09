#include "pch.h"
#include "Program.h"

#include <memory.h>

using namespace std;

namespace IntCode {
    template <class IOHandler>
    Program<IOHandler>::Program(int memInit[], IOHandler &ioHandler) {
        this->_memory[sizeof(memInit)];
        memcpy_s(this->_memory, sizeof(this->_memory), memInit, sizeof(memInit));
        this->_ioHandler = ioHandler;

        this->_ip = 0;
        this->_state = RUN_STATE::CONTINUE;
    }

    template <class IOHandler>
    void Program<IOHandler>::Run() {
        if (this->_state == RUN_STATE::HALT) { return; }

        this->_state = RUN_STATE::CONTINUE;

        while (this->_state == RUN_STATE::CONTINUE) {
            this->_state = this->executeOp();
        }
    }

    template <class IOHandler>
    int Program<IOHandler>::getParam(int* program, int ip, bool immMode)
    {
        if (immMode)
            return program[ip];
        else
            return program[program[ip]];
    }

    template <class IOHandler>
    bool Program<IOHandler>::popParamMode(int& paramModes)
    {
        int nextMode = paramModes % 2;
        paramModes = paramModes / 10;
        return nextMode == 1;
    }

    template <class IOHandler>
    RUN_STATE Program<IOHandler>::executeOp() {
        int opCode = _memory[_ip++];
        int op = opCode % 100;
        int paramModes = opCode / 100;

        switch (op)
        {
        case 1:
        {
            int a = getParam(_memory, _ip++, popParamMode(paramModes));
            int b = getParam(_memory, _ip++, popParamMode(paramModes));
            int res = getParam(_memory, _ip++, true);
            _memory[res] = a + b;
            break;
        }
        case 2:
        {
            int a = getParam(_memory, _ip++, popParamMode(paramModes));
            int b = getParam(_memory, _ip++, popParamMode(paramModes));
            int res = getParam(_memory, _ip++, true);
            _memory[res] = a * b;
            break;
        }
        case 3:
        {
            int res = getParam(_memory, _ip++, true);
            _memory[res] = _ioHandler.readInput();
            break;
        }
        case 4:
        {
            int a = getParam(_memory, _ip++, popParamMode(paramModes));
            return _ioHandler.writeOutput(a);
        }
        case 5:
        {
            int cond = getParam(_memory, _ip++, popParamMode(paramModes));
            int loc = getParam(_memory, _ip++, popParamMode(paramModes));
            if (cond != 0)
                _ip = loc;
            break;
        }
        case 6:
        {
            int cond = getParam(_memory, _ip++, popParamMode(paramModes));
            int loc = getParam(_memory, _ip++, popParamMode(paramModes));
            if (cond == 0)
                _ip = loc;
            break;
        }
        case 7:
        {
            int a = getParam(_memory, _ip++, popParamMode(paramModes));
            int b = getParam(_memory, _ip++, popParamMode(paramModes));
            int res = getParam(_memory, _ip++, true);
            _memory[res] = (a < b) ? 1 : 0;
            break;
        }
        case 8:
        {
            int a = getParam(_memory, _ip++, popParamMode(paramModes));
            int b = getParam(_memory, _ip++, popParamMode(paramModes));
            int res = getParam(_memory, _ip++, true);
            _memory[res] = (a == b) ? 1 : 0;
            break;
        }
        case 99:
        {
            return RUN_STATE::HALT;
        }
        default:
            throw "Invalid OpCode";
        }

        return RUN_STATE::CONTINUE;
    }
}
