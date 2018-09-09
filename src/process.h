#ifndef MULTITASKING_PROCESS_H
#define MULTITASKING_PROCESS_H


#include <vector>
#include <thread>
#include <functional>
#include "process_pipe.h"

class process {
private:
    static std::vector<std::thread> _readers;

    process_pipe _pipe;

    std::string _output;

    std::function<void(void)> _function;

public:
    static void exit_processes();

    process(const std::function<void()> &_function);

    void execute();

    const std::string &output() const;

    void write_to(const std::string &input);

};


#endif //MULTITASKING_PROCESS_H
