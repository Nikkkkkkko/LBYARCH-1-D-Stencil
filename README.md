# LBYARCH-1-D-Stencil
## Average Execution Time Comparison
### In Debug Mode
| Vector Size (n)  | In C Kernel  | In ASM Kernel  |
|------------------|--------------|----------------|
|       2^15       |0.00086666666 |----------------|
|       2^       |||
|       2^       |||
### In Release Mode 
#### Release Mode of the project ran into issues; Result not available.
## Program Output
![alt test](https://github.com/Nikkkkkkko/LBYARCH-1-D-Stencil/blob/main/progOutput.png)
## Analysis of Result
Debug
The performance of the kernels in debug mode showed that the C kernel took longer than the assembly kernel on all the sizes. We believe that this is because assembly cuts away the overhead that C uses for memory allocation and etc. 
