#ifndef MULTITASKING_PROCESS_PIPE_H
#define MULTITASKING_PROCESS_PIPE_H


class process_pipe {
private:
    int _input_pipe[2];
    int _output_pipe[2];

public:
    process_pipe();

    int iread();

    int iwrite();

    int oread();

    int owrite();
};


#endif //MULTITASKING_PROCESS_PIPE_H
