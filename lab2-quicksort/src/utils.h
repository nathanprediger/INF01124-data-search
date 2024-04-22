// swaps positions i and f in arr
void swap(int arr[], int i, int f);

/// @brief generates trully random number between min and max (inclusive)
/// @param min first value of interval
/// @param max last value of interval
/// @return random number in interval
int get_random_number(int min, int max);

/// @brief executes insertion sort (used for median3 to sort arrays of size 3)
/// @param arr array to sort
/// @param tam array size 
void insertion_sort(int arr[], int tam);

/// @brief Calculates the median element of array of size 3 (first, mid and last element)
/// @param arr 
/// @param min 
/// @param max 
/// @return the median of the 3 positions
int median3(int arr[], int min, int max);
