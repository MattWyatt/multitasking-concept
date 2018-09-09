#include <iostream>
#include <zconf.h>
#include "process.h"

int main() {
    process p([]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "hello, multitasking!" << std::endl;
    });
    p.execute();
    std::cout << "process created!" << std::endl;
    std::cout << "working on other things for a bit..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "done working. earlier process is finished by now.\noutput: " << std::endl;
    std::cout << p.output();
    process::exit_processes();
    return 0;
}