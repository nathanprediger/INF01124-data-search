import time
import cpuinfo

SHELL = "SHELL"
KNUT = "KNUTH"
CIURA = "CIURA"
shell_seq = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576]
knuth_seq = [1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484]
ciura_seq = [1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316,1035711]

def write_output(arr: list, text: str="", output_f=None) -> None:
    '''
    Writes the array to a file, adding a optional text at the end of the line
    '''
    out_str = ''
    for el in arr:
        out_str += f'{el} '


    out_str += f'{text}' if text else ''
    
    if output_f:
        output_f.write(f"{out_str}\n")


def shell_sort(arr: list, tam: int, seq: list, name: str, out_f=None, time_f=None, cpu=None, verbose: bool=False) -> tuple:
    '''
    Runs all the availabe sequences on shell_sort
        
    Parameters:
        arr: array to be sorted (won't change the array)
        tam: array length
        seq: h-sequence used
        name: name of the h-sequence
        out_f: output file stream
        time_f: output file for time data
        cpu: CPU name
        verbose: verbose option to print information while executing

    Returns:
        (moves, time): moves made and total execution time in seconds
    '''

    moves = 0
    # sequence index
    seq_i = 0
    # creates array copy 
    arr_c = arr[:]
    # gets CPU name
    runtime = time.time()

    print(f"{name} ", end=" ") if verbose else 0
    write_output(arr_c, f"SEQ={name}", out_f)

    # finds bigger sequence value smaller than the length of array
    while seq[seq_i + 1] < tam: 
        seq_i += 1

    while seq_i >= 0:
        h = seq[seq_i]

        for j in range(h, tam):
            key = arr_c[j]
            i = j
            
            while i >= h and arr_c[i - h] > key:
                arr_c[i] = arr_c[i - h]
                i -= h
                moves += 1

            arr_c[i] = key

        write_output(arr_c, f"INCR={h}", out_f)
        seq_i -= 1 
    
    runtime = time.time() - runtime

    if time_f:
        # writes sequence name, array length, time in seconds and cpu-name info
        time_f.write(f"{name}, {tam}, {runtime * 1000}, {cpu}\n")

    return (moves, runtime)


def run_sequences(arr: list, tam: int, out_f=None, time_f=None, verbose: bool=False) -> None:
    '''
    Runs the selected sequences on shell_sort for the given array
    '''

    cpu_name = cpuinfo.get_cpu_info()['brand_raw']
    sequences = [(shell_seq, SHELL), (knuth_seq, KNUT), (ciura_seq, CIURA)]
    for s in sequences:
        info = shell_sort(arr, tam, s[0], s[1], out_f, time_f, cpu_name, verbose)
        print(info) if verbose else 0


def process_file(input: str, verbose: bool=False) -> None:
    '''
    Opens input file and execute shell_sort for each line. Writes the output to the output file.
    Also writes runtime information to another file.
    '''

    f = open(f"inputs/input{input}.txt", "r")
    f_out = open(f"inputs/output{input}.txt", "w")
    time_f = open(f"inputs/time_data{input}.txt", "w")

    arr_n = 1
    for x in f:
        # ignores last term ('\n') and converts the terms to int using eval function
        arr = [eval(n) for n in x.split(' ')[:-1]]
        tam = arr[0]
        arr = arr[1:]
        print(f"\n----- ARRAY {arr_n} -----") if verbose else 0
        run_sequences(arr, tam, f_out, time_f, verbose)
        arr_n += 1

    f.close()
    f_out.close()
    time_f.close()


inp_files = ["1", "2"]
for i in inp_files:
    print(f"# Runing shell_sort sequences for 'input/input{i}.txt'")
    process_file(i, 1)