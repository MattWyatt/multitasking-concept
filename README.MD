# multitasking
this is a simple proof of concept multitasking library. my intent is to use this to rewrite [sybil's](https://github.com/MattWyatt/sybil-process-manager) process management.

# example
```cpp
/* create a process object with a function
 * execution begins immediately */
process p([]() {
	for (int i = 0; i < 5; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "hello, multitasking! " << i << std::endl;
	}
});


std::cout << "process created!" << std::endl;

/* perform some task in the frontend that may take a bit */
std::cout << "working on other things for a bit..." << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(2));

std::cout << "done working. output from process: " << std::endl;

/* grab the output of the process, even though it may not be over yet */
std::cout << p.output() << std::endl;

/* wait for the process to exit before we end the program */
p.wait_for_exit();

/* grab the output after it's finished */
std::cout << "process finished and exited! output: " << std::endl;
std::cout << p.output() << std::endl;
return 0;
```
