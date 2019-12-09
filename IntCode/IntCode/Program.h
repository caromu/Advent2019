#pragma once

#include "RunState.h"
#include "IOHandler.h"

namespace IntCode {

    template <class IOHandler = StdIOHandler>
    class Program
    {
    private:
        int* _memory;
        int _ip;
        RUN_STATE _state;
        IOHandler _ioHandler;

        int getParam(int* program, int ip, bool immMode);
        bool popParamMode(int& paramModes);
        RUN_STATE executeOp();

    public:
        Program(int memInit[], IOHandler &ioHandler);

        IOHandler& get_IOHandler() { return _ioHandler; }
        RUN_STATE get_state() { return _state; }

        void Run();
    };

}

