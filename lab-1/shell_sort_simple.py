SHELL = "SHELL"
KNUT = "KNUT"
CIURA = "CIURA"
shell_seq = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576]
knuth_seq = [1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484]
ciura_seq = [1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316,1035711]

def print_array(arr, text):
    for el in arr:
        print(el, end=" ")

    print(text)

def shell_sorting(arr, seq, name):
    # cria copia do array
    arr_c = arr[:]
    moves = 0
    seq_i = 0
    i = 0

    print_array(arr_c, f"SEQ={name}")

    # encontra maior valor da sequencia menor que o tamanho do array
    while seq[seq_i + 1] < len(arr_c): 
        seq_i += 1

    while seq_i >= 0:
        i = 0
        while i + seq[seq_i] < len(arr_c):
            key = arr_c[i + seq[seq_i]]
            
            if (arr_c[i] > key):
                arr_c[i + seq[seq_i]] = arr[i]
                arr[i] = key

            i += 1

        print_array(arr_c, f"INC={seq[seq_i]}")
        seq_i -= 1


arr1 = [16, 16, 14, 12, 1, 8, 4, 9, 6, 15, 13, 11, 2, 7, 3, 10, 5][1:]
arr2 = [16, 3, 10, 5, 16, 14, 12, 1, 8, 4, 9, 6, 15, 13, 11, 2, 7][1:]

arrays = [arr1, arr2]

for arr_el in arrays:
    shell_sorting(arr_el, shell_seq, SHELL)
    shell_sorting(arr_el, knuth_seq, KNUT)
    shell_sorting(arr_el, ciura_seq, CIURA)