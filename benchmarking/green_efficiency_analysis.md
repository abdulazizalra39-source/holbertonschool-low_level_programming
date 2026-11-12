# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken on the same machine, running Ubuntu under WSL, using the clock() function from time.h. clock() returns the processor time used by the program, and each duration was converted to seconds by dividing the difference between two clock() readings by CLOCKS_PER_SEC. Every program was compiled with gcc using -Wall -Werror -Wextra -pedantic and no optimisation flags, so all programs were treated equally. The baseline program performs 100000000 iterations of a simple modulo loop and was run three consecutive times. The comparison program times two algorithms that count even numbers in the same 50000-element array, and it was also run three times to compute averages. Finally, instrumentation_lab.c was instrumented with clock() calls placed between each phase (build, process, reduce), with TOTAL measured from before the first phase to after the last one.

## Observed Performance Differences

The baseline runs took between 0.088345 and 0.098688 seconds, with an average of 0.094932 seconds. The spread was about 10.9% of the average, which shows that even an identical, deterministic program does not produce identical timings. In the algorithm comparison, the naive algorithm took 0.664872 seconds on average, while the single-pass algorithm took 0.000024 seconds on average, making the naive version roughly 27703 times slower. This gap comes from the structure of the code, not from the hardware: the naive version uses a nested loop and re-scans the array for every element, so its work grows quadratically, while the single-pass version reads each element exactly once. In the instrumentation experiment, the total time was 0.000242 seconds, split into 0.000099 seconds for building the dataset, 0.000099 seconds for processing it and 0.000044 seconds for the checksum reduction.

## Relation Between Runtime and Energy Consumption

None of the programs measured energy directly, so energy can only be reasoned about through runtime. When a program keeps the CPU busy for longer, the processor stays in a high-power state for longer and consumes more energy. Since clock() measures CPU time, a longer measured time means more CPU work was performed. Based on the recorded averages, the naive algorithm kept the CPU busy about 27703 times longer than the single-pass algorithm for the same task, so a comparable increase in the energy spent by the processor is expected. The baseline loop, at around 0.094932 seconds per run, shows that even simple operations repeated many times add up to measurable CPU work.

## Limitations of the Experiment

The main limitation is that energy was never measured: conclusions about energy are inferred from CPU time, while real power usage also depends on frequency scaling, memory activity and other hardware factors. In addition, clock() has limited resolution, so very short phases such as the 0.000099 seconds measured for the process phase are close to the measurement noise. The programs also ran inside WSL alongside background processes, which explains part of the 10.9% variation between baseline runs. Finally, only three runs were recorded per program, which is enough to observe a trend but not to produce a statistically strong average.

## Practical Engineering Takeaway

The most effective way to reduce runtime, and therefore likely energy use, is to choose a better algorithm. The measured difference between the naive and single-pass versions was far larger than the natural run-to-run variation seen in the baseline, which means algorithmic choices matter much more than small timing fluctuations. Engineers should measure before optimising, repeat measurements several times, place timing boundaries consistently around each phase, and focus their effort on the parts of a program that dominate the total time.
