from sorts import *
import cpuinfo

def get_cpu_name() -> str:
    return cpuinfo.get_cpu_info()['brand_raw']

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


def time_to_ms(s: float) -> float:
    '''
    Converts time in seconds to ms with 7 decimal places
    '''

    return round(s * 1000, 7)


def run_sequences(arr: list, tam: int, out_f=None, time_f=None, cpu_name="", verbose: bool=False) -> None:
    '''
    Runs the selected sequences on shell_sort for the given array
    '''

    SHELL = "SHELL"
    KNUT = "KNUTH"
    CIURA = "CIURA"
    shell_seq = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576]
    knuth_seq = [1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484]
    ciura_seq = [1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316,1035711]

    sequences = [(shell_seq, SHELL), (knuth_seq, KNUT), (ciura_seq, CIURA)]
    for s in sequences:
        info = shell_sort(arr, tam, s[0], s[1], out_f, time_f, cpu_name, verbose)
        print(info) if verbose else 0


def process_input(input: str, cpu_name: str, verbose: bool=False) -> None:
    '''
    Opens input file and execute shell_sort for each line. Writes the output to the output file.
    Also writes runtime information to another file.

    Parameters:
        input: name of the input file (considering its parent folder is `inputs`).
        cpu_name: CPU name
        verbose: if True, will create output_file with the array sorting algorithm traceback 
            steps and print the return of the shell_sort algorithm on screen.
            Else, the function will only write the execution time information
            to a file in the `outputs` folder.
    '''

    INPUT_DIR = "inputs"
    OUTPUT_DIR = "outputs"

    f = open(f"{INPUT_DIR}/input{input}.txt", "r")
    f_out = open(f"{OUTPUT_DIR}/output{input}.txt", "w") if verbose else None
    time_f = open(f"{OUTPUT_DIR}/time_data{input}.txt", "w")

    arr_n = 1
    for x in f:
        # ignores last term ('\n') and converts the terms to int using eval function
        arr = [int(n) for n in x.split(' ')[:-1]]
        tam = arr.pop(0)
        if verbose:
            print(f"\n----- ARRAY {arr_n} -----")
            arr_n += 1

        run_sequences(arr, tam, f_out, time_f, cpu_name, verbose)

    f.close()
    f_out.close() if verbose else 0
    time_f.close()

