#if !defined(QUICKSORT_CONSTANTS)
#define QUICKSORT_CONSTANTS 1

// partitioning algorithms
#define LOMUTO 'L'
#define HOARE 'H'
// partiotioner choices
#define RANDOM 'R'
#define MEDIAN 'M'
#include <string>

/// @brief Struct used for passing test arguments
typedef struct test_info {
    char partitioner;
    char partitioning;
    std::string output_file;
} Test_info;

#endif