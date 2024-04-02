# LBYARCH-1-D-Stencil
## Average Execution Time Comparison
### In Debug Mode
| Vector Size (n)  | In C Kernel  | In ASM Kernel  |
|------------------|--------------|----------------|
|       2^10       |0.000033333336|0.00003333333   |
|       2^20       |0.0163        |0.00163         |
|       2^24       |4.04256666667 |0.34826666666   |
### In Release Mode 
#### Release Mode of the project ran into issues; Result not available.
## Program Output
![alt test](https://github.com/Nikkkkkkko/LBYARCH-1-D-Stencil/blob/main/progOutput.png)
## Analysis of Result
Unfortunately, we were unable to fix the lingering issues on the release mode of the project that prevented us from running tests in time. In addition 2^10 was used as a replacement test case for 2^30 as 2^24 was the highest our machines could run without crashing due to taking too long to finish.

In the meantime, for the Debug mode, as we expected, the average runtime of the x86-64 kernel proved that it was faster than it's C' counterpart. Interestingly, we had observed that this gap in speed grew wider with larger vector size as shown in the table above. We believe that this is because assembly cuts away the overhead that C uses for memory allocation therefor essentially letting it perform tasks with fewer middlemen.
