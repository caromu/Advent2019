#include "pch.h"
#include "Program.h"

#include <memory.h>

using namespace std;

namespace IntCode {
    template <class IOHandler>
    Program<IOHandler>::Program(const long long int memInit[], IOHandler& ioHandler) {
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
    long long int Program<IOHandler>::getParam(unsigned int ip, PARAM_MODE mode, bool outParam)
    {
        switch (mode) {
        case PARAM_MODE::IMMEDIATE:
            return _memory[ip];
        case PARAM_MODE::POSITION:
            unsigned int addr = _memory[ip];
            return outParam ? addr : _memory[addr];
        case PARAM_MODE::RELATIVE:
            unsigned int addr = _memory[ip] + _relBase;
            return outParam ? addr : _memory[addr];
        }
    }

    template <class IOHandler>
    PARAM_MODE Program<IOHandler>::popParamMode(long long int& paramModes)
    {
        int nextMode = paramModes % 10;
        paramModes = paramModes / 10;
        return (PARAM_MODE)nextMode;
    }

    template <class IOHandler>
    RUN_STATE Program<IOHandler>::executeOp() {
        long long int opCode = _memory[_ip++];
        long long int op = opCode % 100;
        long long int paramModes = opCode / 100;

        switch (op)
        {
        case 1:
        {
            int a = getParam(_ip++, popParamMode(paramModes));
            int b = getParam(_ip++, popParamMode(paramModes));
            int res = getParam(_ip++, popParamMode, true);
            _memory[res] = a + b;
            break;
        }
        case 2:
        {
            int a = getParam(_ip++, popParamMode(paramModes));
            int b = getParam(_ip++, popParamMode(paramModes));
            int res = getParam(_ip++, popParamMode(paramModes), true);
            _memory[res] = a * b;
            break;
        }
        case 3:
        {
            int res = getParam(_ip++, popParamMode(paramModes), true);
            _memory[res] = _ioHandler.readInput();
            break;
        }
        case 4:
        {
            int a = getParam(_ip++, popParamMode(paramModes));
            return _ioHandler.writeOutput(a);
        }
        case 5:
        {
            int cond = getParam(_ip++, popParamMode(paramModes));
            int loc = getParam(_ip++, popParamMode(paramModes));
            if (cond != 0)
                _ip = loc;
            break;
        }
        case 6:
        {
            int cond = getParam(_ip++, popParamMode(paramModes));
            int loc = getParam(_ip++, popParamMode(paramModes));
            if (cond == 0)
                _ip = loc;
            break;
        }
        case 7:
        {
            int a = getParam(_ip++, popParamMode(paramModes));
            int b = getParam(_ip++, popParamMode(paramModes));
            int res = getParam(_ip++, popParamMode(paramModes), true);
            _memory[res] = (a < b) ? 1 : 0;
            break;
        }
        case 8:
        {
            int a = getParam(_ip++, popParamMode(paramModes));
            int b = getParam(_ip++, popParamMode(paramModes));
            int res = getParam(_ip++, popParamMode(paramModes), true);
            _memory[res] = (a == b) ? 1 : 0;
            break;
        }
        case 9:
        {
            int offset = getParam(_ip++, popParamMode(paramModes));
            _relBase += offset;
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
