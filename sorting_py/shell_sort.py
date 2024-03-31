def print_array(arr):
    [print(i, end=" ") for i in arr]
    print("")

shell_seq = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576]
def shell_sort(arr, h_seq: list=shell_seq):
    seq_i = 0
    arr_len = len(arr)

    # finds biggest gap
    while h_seq[seq_i + 1] < arr_len:
        seq_i += 1

    while seq_i >= 0:
        h = h_seq[seq_i]

        for i in range(h, arr_len):
            j = i
            key = arr[i]

            while j >= h and arr[j - h] > key:
                arr[j] = arr[j - h]
                j -= h

            arr[j] = key

        seq_i -= 1

arr1 = [16, 14, 12, 1, 8, 4, 9, 6, 15, 13, 11, 2, 7, 3, 10, 5]
arr2 = [3, 10, 5, 16, 14, 12, 1, 8, 4, 9, 6, 15, 13, 11, 2, 7]


def test_sort(arr, func, h_seq: list=shell_seq):
    print_array(arr)
    func(arr)
    print_array(arr)
    print("")


test_sort(arr1, shell_sort)
test_sort(arr2, shell_sort)