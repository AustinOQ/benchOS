# benchOS
BenchOS is targeted towards hyper perdictable behavior that will allow for
accurate hardware and software benchmarking. The main change from the standard 
linux kernel will be modifications to the scheduler to only allow 1 process 
other than the os to run ar one time. This one process may have multiple 
threads.
 
The OS will also do little to optimize for responsiveness, instead opting to optimize for compute performance. 

This is a pet project and will likely not be an optimal, or even acceptable, OS for most users. 

