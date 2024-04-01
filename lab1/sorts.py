import time
import utils as u

def insertion_sort(arr: list, h=1, tam=None) -> int:
    '''
    Insertion sort 

    Parameters:
        arr: array to be sorted (changes the array)
        i: begining of array
        h: gap
        tam: length of array

    Returns:
        (int): number of moves made in the ordering
    '''

    # in case tam wasn't passed, calculates length
    if not tam:
        tam = len(arr)

    moves = 0
    for j in range(h, tam):
        key = arr[j]
        i = j
    
        while i >= h and arr[i - h] > key:
            arr[i] = arr[i - h]
            i -= h
            moves += 1

        arr[i] = key

    return moves

def shell_sort(arr: list, tam: int, seq: list, name: str=None, out_f=None, time_f=None, cpu=None, verbose: bool=False) -> tuple:
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
        (moves, time): moves made and total execution time in milliseconds
    '''

    moves = 0
    seq_i = 0
    i = 0
    arr_c = arr[:]

    if verbose:
        print(f"{name} ", end=" ")
        u.write_output(arr_c, f"SEQ={name}", out_f)

    # finds bigger sequence value smaller than the length of array
    while seq[seq_i + 1] < tam: 
        seq_i += 1

    runtime = time.process_time();
    while seq_i >= 0:
        h = seq[seq_i]
        moves += insertion_sort(arr_c, h, tam)
        u.write_output(arr_c, f"INCR={h}", out_f) if verbose else 0
        seq_i -= 1 
    
    runtime = time.process_time() - runtime

    # writes sequence name, array length, time in seconds and cpu-name info
    if time_f:
        time_f.write(f"{name}, {tam}, {u.time_to_ms(runtime)}, {cpu}\n")

    return (moves, u.time_to_ms(runtime))
