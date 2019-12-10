#pragma once

#include "RunState.h"
#include <iostream>
#include <queue>

using namespace std;

namespace IntCode {
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

    class QueueIOHandler :
        protected BaseIOHandler
    {
    public:
        queue<long long int> *inputs;
        queue<long long int>* outputs;

        QueueIOHandler(queue<long long int>* inputs, queue<long long int>* outputs) {
            this->inputs = inputs;
            this->outputs = outputs;
        }

        long long int readInput() override {
            if (inputs->size() == 0) return 0;

            long long int input = inputs->front();
            inputs->pop();
            return input;
        };

        RUN_STATE writeOutput(long long int output) override {
            outputs->push(output);
            return RUN_STATE::PAUSE;
        };
    };
}

