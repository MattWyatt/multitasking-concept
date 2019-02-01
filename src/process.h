#ifndef MULTITASKING_PROCESS_H
#define MULTITASKING_PROCESS_H


#include <vector>
#include <thread>
#include <sstream>
#include <functional>
#include "process_pipe.h"

class process {
private:
    std::thread _reader;

    process_pipe _pipe;

    std::stringstream _output;

    std::function<void(void)> _function;

    pid_t _pid;

public:
    explicit process(const std::function<void()>& function);

    const std::string output() const;

    void write_to(const std::string &input);

    const pid_t& get_pid() const;

    void wait_for_exit();

};


#endif //MULTITASKING_PROCESS_H
