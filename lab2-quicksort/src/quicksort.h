// lomuto partiotioning algorithm (default for simple quicksort implementations)
int lomuto(int arr[], int left, int right);

// a more complex and detailed partitioning algorithm, makes less moves
int hoare(int arr[], int left, int right);

int partition(int arr[], int i, int f, int partitioning);

/*!*****************************************************************************
 * @brief quicksort with different partiotioning and partioner algorithms
 * @param arr: array to be sorted
 * @param i: index of array first element
 * @param f: index of array last element
 * @param partitioner: RANDOM/MEDIAN
 * @param partitioning: LOMUTO/HOARE
 *******************************************************************************/
void quicksort(int arr[], int i, int f, char partitioner, char partiotining);
