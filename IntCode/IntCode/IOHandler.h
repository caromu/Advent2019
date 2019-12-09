#pragma once

#include "RunState.h"
#include <iostream>
#include <queue>

using namespace std;

namespace IntCode {
    class BaseIOHandler {
    public:
        virtual int readInput() {};
        virtual RUN_STATE writeOutput(int output) {};
    };

    class StdIOHandler :
        protected BaseIOHandler
    {
    public:
        int readInput() override {
            int input;
            cin >> input;
            return input;
        };

        RUN_STATE writeOutput(int output) override {
            cout << output;
            return RUN_STATE::CONTINUE;
        };
    };

    class QueueIOHandler :
        protected BaseIOHandler
    {
    public:
        queue<int> *inputs;
        queue<int>* outputs;

        QueueIOHandler(queue<int>* inputs, queue<int>* outputs) {
            this->inputs = inputs;
            this->outputs = outputs;
        }

        int readInput() override {
            if (inputs->size() == 0) return 0;

            int input = inputs->front();
            inputs->pop();
            return input;
        };

        RUN_STATE writeOutput(int output) override {
            outputs->push(output);
            return RUN_STATE::PAUSE;
        };
    };
}

