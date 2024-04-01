from utils import *
from sorts import *

cpu_name = get_cpu_name()
inp_files = ["1", "2"]

for i in inp_files:
    print(f"# Runing shell_sort sequences for 'input/input{i}.txt'")
    process_input(i, cpu_name, True)