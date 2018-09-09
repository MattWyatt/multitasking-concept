# multitasking
this is a simple proof of concept multitasking library. my intent is to use this to rewrite [sybil's](https://github.com/MattWyatt/sybil-process-manager) process management.

# example
```cpp
/* create a process object with a function*/
process p([]() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "hello, multitasking!" << std::endl;
});

/* begin execution 
 * the process object will store the task's output
 * even if the task is not completed yet */
p.execute();


std::cout << "process created!" << std::endl;

/* perform some task in the frontend that may take a bit */
std::cout << "working on other things for a bit..." << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(2));

std::cout << "done working. earlier process is finished by now.\noutput: " << std::endl;

/* grab the output of the process, even though it may not be over yet */
std::cout << p.output();

/* ensure that before we exit, we exit all the created processes */
process::exit_processes();
return 0;
```