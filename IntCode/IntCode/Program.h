#pragma once

#include "RunState.h"
#include "IOHandler.h"
#include <memory>

namespace IntCode {

    const enum class PARAM_MODE {
        POSITION = 0,
        IMMEDIATE,
        RELATIVE
    };

    template <class IOHandler = StdIOHandler>
    class Program
    {
    private:
        long long int _memory[20000];
        unsigned int _ip;
        RUN_STATE _state;
        IOHandler* _ioHandler;
        long long int _relBase = 0;

        long long int getParam(unsigned int ip, PARAM_MODE mode, bool outParam = false) {
            unsigned int addr;
            switch (mode) {
            case PARAM_MODE::IMMEDIATE:
                return _memory[ip];
            case PARAM_MODE::POSITION:
                addr = _memory[ip];
                return outParam ? addr : _memory[addr];
            case PARAM_MODE::RELATIVE:
                addr = _memory[ip] + _relBase;
                return outParam ? addr : _memory[addr];
            default:
                throw "Invalid Param Mode";
            }
        };
        PARAM_MODE popParamMode(long long int& paramModes) {
            int nextMode = paramModes % 10;
            paramModes = paramModes / 10;
            return (PARAM_MODE)nextMode;
        };
        RUN_STATE executeOp() {
            long long int opCode = _memory[_ip++];
            long long int op = opCode % 100;
            long long int paramModes = opCode / 100;

            switch (op)
            {
            case 1:
            {
                long long int a = getParam(_ip++, popParamMode(paramModes));
                long long int b = getParam(_ip++, popParamMode(paramModes));
                int res = getParam(_ip++, popParamMode(paramModes), true);
                _memory[res] = a + b;
                break;
            }
            case 2:
            {
                long long int a = getParam(_ip++, popParamMode(paramModes));
                long long int b = getParam(_ip++, popParamMode(paramModes));
                int res = getParam(_ip++, popParamMode(paramModes), true);
                _memory[res] = a * b;
                break;
            }
            case 3:
            {
                int res = getParam(_ip++, popParamMode(paramModes), true);
                _memory[res] = _ioHandler->readInput();
                break;
            }
            case 4:
            {
                long long int a = getParam(_ip++, popParamMode(paramModes));
                return _ioHandler->writeOutput(a);
            }
            case 5:
            {
                long long int cond = getParam(_ip++, popParamMode(paramModes));
                unsigned int loc = getParam(_ip++, popParamMode(paramModes));
                if (cond != 0)
                    _ip = loc;
                break;
            }
            case 6:
            {
                long long int cond = getParam(_ip++, popParamMode(paramModes));
                unsigned int loc = getParam(_ip++, popParamMode(paramModes));
                if (cond == 0)
                    _ip = loc;
                break;
            }
            case 7:
            {
                long long int a = getParam(_ip++, popParamMode(paramModes));
                long long int b = getParam(_ip++, popParamMode(paramModes));
                int res = getParam(_ip++, popParamMode(paramModes), true);
                _memory[res] = (a < b) ? 1 : 0;
                break;
            }
            case 8:
            {
                long long int a = getParam(_ip++, popParamMode(paramModes));
                long long int b = getParam(_ip++, popParamMode(paramModes));
                int res = getParam(_ip++, popParamMode(paramModes), true);
                _memory[res] = (a == b) ? 1 : 0;
                break;
            }
            case 9:
            {
                long long int offset = getParam(_ip++, popParamMode(paramModes));
                _relBase += offset;
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
        };

    public:
        Program(const long long int* memInit, size_t size, IOHandler* ioHandler) {
            memcpy_s(this->_memory, sizeof(this->_memory), memInit, size);
            this->_ioHandler = ioHandler;

            this->_ip = 0;
            this->_state = RUN_STATE::CONTINUE;
        };

        IOHandler* get_IOHandler() { return _ioHandler; }
        RUN_STATE get_state() { return _state; }

        void Run() {
            if (this->_state == RUN_STATE::HALT) { return; }

            this->_state = RUN_STATE::CONTINUE;

            while (this->_state == RUN_STATE::CONTINUE) {
                this->_state = this->executeOp();
            }
        };
    };

}

