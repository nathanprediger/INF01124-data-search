# Lab 1: shell sort with different sequences

The ideia of the task is to implement shell sort with 3 different sequences (see below) and print the output of the sorting onto 2 different files: one for the array on each h-gap used, and another for time and CPU information about the executions. 

## Installation

To install the requirements, you'll need python3 pip installed. After that, run:
```bash
pip install py-cpuinfo
```
after installing the `py-cpuinfo` package, you're able to run the script

## How it works

The main code reads the inputs declared on the `inp_files` array. The inputs are read from the directory `/inputs/` and their name is always `input<x>.txt`, where x is the name which was given on the inp_files array:
```python
inp_files = ["1", "-big_numbers", "-test_one"]
```
The live above shows an example of input filenames. After that, it's important to understand the function `process_input()`, especially, the last argument: verbose.

When verbose is `true`, the program will print the sequence used and the time it took to sort the array with that sequence. Besides, the output of each step is written to an output file in the `/outputs` folder.
Additionally, a text file with information about the size of the array, time taken, and processor used are printed into another file.

When verbose is `false`, only the data about the array and time taken are written in the output folder.

<b>By default, verbose is `false`.</b>

## Sequences used

The sequenced used are hardcoded to minize execution time. They are: powers of 2 (initialy proposed sequence for the shell sort algorithm), the Knuth sequence and the Ciura sequence. <br>Learn more about the available sequences for the shell sort algorithm on it's [Wikipedia page](https://en.wikipedia.org/wiki/Shellsort).

### 1 - Shell sequence
The original sequence used by the shell sorting algorithm proposed intialy. 

```python
shell_seq = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576...]
```

### 2 - Knuth sequence

```python
knuth_seq = [1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484...]
```

### 3 - Ciura sequence
```python
ciura_seq = [1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316,1035711...]
```
