#pragma once

#include "RunState.h"
#include "IOHandler.h"

namespace IntCode {

    const enum class PARAM_MODE {
        IMMEDIATE = 0,
        POSITION,
        RELATIVE
    };

    template <class IOHandler = StdIOHandler>
    class Program
    {
    private:
        long long int _memory[20000];
        unsigned int _ip;
        RUN_STATE _state;
        IOHandler _ioHandler;
        int _relBase = 0;

        long long int getParam(unsigned int ip, PARAM_MODE mode, bool outParam = false);
        PARAM_MODE popParamMode(long long int& paramModes);
        RUN_STATE executeOp();

    public:
        Program(const long long int memInit[], IOHandler &ioHandler);

        IOHandler& get_IOHandler() { return _ioHandler; }
        RUN_STATE get_state() { return _state; }

        void Run();
    };

}

