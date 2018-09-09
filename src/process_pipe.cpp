#include <unistd.h>
#include "process_pipe.h"

process_pipe::process_pipe() {
    if (pipe(_input_pipe) < 0) {
        throw "error creating input pipe";
    }

    if (pipe(_output_pipe) < 0) {
        throw "error creating output pipe";
    }
}

int process_pipe::iread() {
    return _input_pipe[0];
}

int process_pipe::iwrite() {
    return _input_pipe[1];
}

int process_pipe::oread() {
    return _output_pipe[0];
}

int process_pipe::owrite() {
    return _output_pipe[1];
}
