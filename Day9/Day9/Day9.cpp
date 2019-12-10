// Day9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const long long int programTemplate[] = { 1102,34463338,34463338,63,1007,63,34463338,63,1005,63,53,1101,0,3,1000,109,988,209,12,9,1000,209,6,209,3,203,0,1008,1000,1,63,1005,63,65,1008,1000,2,63,1005,63,904,1008,1000,0,63,1005,63,58,4,25,104,0,99,4,0,104,0,99,4,17,104,0,99,0,0,1102,1,432,1027,1101,439,0,1026,1101,0,36,1010,1101,0,34,1018,1102,278,1,1029,1101,0,24,1002,1102,1,20,1016,1102,1,31,1011,1102,319,1,1024,1102,21,1,1012,1102,1,763,1022,1102,1,25,1007,1101,0,287,1028,1102,32,1,1008,1101,0,22,1013,1102,38,1,1001,1101,0,314,1025,1102,35,1,1009,1102,1,23,1015,1102,39,1,1019,1102,27,1,1000,1102,1,37,1003,1102,1,28,1017,1101,0,0,1020,1101,0,29,1004,1102,1,30,1006,1102,1,756,1023,1102,1,33,1005,1101,0,1,1021,1102,26,1,1014,109,13,2108,28,-7,63,1005,63,201,1001,64,1,64,1105,1,203,4,187,1002,64,2,64,109,8,21107,40,41,-3,1005,1018,225,4,209,1001,64,1,64,1105,1,225,1002,64,2,64,109,-3,1206,2,239,4,231,1105,1,243,1001,64,1,64,1002,64,2,64,109,-21,1201,6,0,63,1008,63,35,63,1005,63,267,1001,64,1,64,1105,1,269,4,249,1002,64,2,64,109,35,2106,0,-4,4,275,1001,64,1,64,1105,1,287,1002,64,2,64,109,-11,1205,-1,303,1001,64,1,64,1105,1,305,4,293,1002,64,2,64,109,8,2105,1,-5,4,311,1106,0,323,1001,64,1,64,1002,64,2,64,109,-7,21108,41,38,-6,1005,1016,339,1106,0,345,4,329,1001,64,1,64,1002,64,2,64,109,2,21102,42,1,-8,1008,1016,45,63,1005,63,369,1001,64,1,64,1105,1,371,4,351,1002,64,2,64,109,-14,21101,43,0,1,1008,1011,43,63,1005,63,397,4,377,1001,64,1,64,1106,0,397,1002,64,2,64,109,-8,21101,44,0,8,1008,1010,47,63,1005,63,417,1105,1,423,4,403,1001,64,1,64,1002,64,2,64,109,25,2106,0,0,1001,64,1,64,1105,1,441,4,429,1002,64,2,64,109,-20,2107,37,-6,63,1005,63,463,4,447,1001,64,1,64,1106,0,463,1002,64,2,64,109,8,2108,25,-8,63,1005,63,485,4,469,1001,64,1,64,1106,0,485,1002,64,2,64,109,-1,21107,45,44,-1,1005,1013,505,1001,64,1,64,1106,0,507,4,491,1002,64,2,64,109,-11,1207,-1,25,63,1005,63,529,4,513,1001,64,1,64,1106,0,529,1002,64,2,64,109,23,1206,-5,545,1001,64,1,64,1106,0,547,4,535,1002,64,2,64,109,-31,2102,1,5,63,1008,63,27,63,1005,63,569,4,553,1106,0,573,1001,64,1,64,1002,64,2,64,109,27,21102,46,1,-9,1008,1013,46,63,1005,63,595,4,579,1105,1,599,1001,64,1,64,1002,64,2,64,109,-26,2101,0,6,63,1008,63,24,63,1005,63,625,4,605,1001,64,1,64,1106,0,625,1002,64,2,64,109,5,1208,0,37,63,1005,63,645,1001,64,1,64,1105,1,647,4,631,1002,64,2,64,109,7,2102,1,-3,63,1008,63,31,63,1005,63,671,1001,64,1,64,1105,1,673,4,653,1002,64,2,64,109,2,1202,-5,1,63,1008,63,33,63,1005,63,699,4,679,1001,64,1,64,1105,1,699,1002,64,2,64,109,-4,2101,0,-3,63,1008,63,35,63,1005,63,719,1105,1,725,4,705,1001,64,1,64,1002,64,2,64,109,-5,1207,4,32,63,1005,63,741,1106,0,747,4,731,1001,64,1,64,1002,64,2,64,109,29,2105,1,-7,1001,64,1,64,1106,0,765,4,753,1002,64,2,64,109,-26,2107,36,5,63,1005,63,781,1105,1,787,4,771,1001,64,1,64,1002,64,2,64,109,10,1201,-6,0,63,1008,63,32,63,1005,63,809,4,793,1106,0,813,1001,64,1,64,1002,64,2,64,109,3,21108,47,47,-5,1005,1012,835,4,819,1001,64,1,64,1106,0,835,1002,64,2,64,109,-24,1202,9,1,63,1008,63,25,63,1005,63,859,1001,64,1,64,1106,0,861,4,841,1002,64,2,64,109,19,1205,9,875,4,867,1106,0,879,1001,64,1,64,1002,64,2,64,109,-3,1208,-1,32,63,1005,63,897,4,885,1106,0,901,1001,64,1,64,4,64,99,21102,27,1,1,21101,915,0,0,1105,1,922,21201,1,60043,1,204,1,99,109,3,1207,-2,3,63,1005,63,964,21201,-2,-1,1,21102,1,942,0,1106,0,922,21202,1,1,-1,21201,-2,-3,1,21101,957,0,0,1106,0,922,22201,1,-1,-2,1105,1,968,22102,1,-2,-2,109,-3,2105,1,0 };

const enum class RUN_STATE {
    CONTINUE = 0,
    PAUSE,
    HALT
};


class BaseIOHandler {
public:
    virtual long long int readInput() { return 0; };
    virtual RUN_STATE writeOutput(long long int output) { return RUN_STATE::CONTINUE; };
};

class StdIOHandler :
    protected BaseIOHandler
{
public:
    long long int readInput() override {
        long long int input;
        cin >> input;
        return input;
    };

    RUN_STATE writeOutput(long long int output) override {
        cout << output;
        return RUN_STATE::CONTINUE;
    };
};

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
    IOHandler *_ioHandler;
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
    Program(const long long int * memInit, size_t size, IOHandler* ioHandler) {
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


int main()
{
    StdIOHandler iohandler;
    Program<StdIOHandler> *program = new Program<StdIOHandler>(programTemplate, sizeof(programTemplate), new StdIOHandler());
    program->Run();
}
