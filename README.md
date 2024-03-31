# INF01124-data-search
Codes developed in the INF01124 - Data Search and Classification at UFRGS. (mostly sorting algortihms)

## Sorting Algorithms
##### Copied from [AnasImloul/sorting_algorithms.md](https://gist.github.com/AnasImloul/f29cd4885761514582a925c2edc3252b)
In computer science, a **Sorting Algorithm** is an algorithm that puts elements of a list into an order.

The most frequently used orders are numerical order and lexicographical order, and either ascending or descending. However, you can define your own order

The following function is a valid order and is used to order persons based on their age

def compare(person1, person2):
  return person1.age > person2.age

  

Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.

  

Formally, the output of any sorting algorithm must satisfy two conditions:

* The output is in monotonic order (each element is no smaller/larger than the previous element, according to the required order).
* The output is a permutation (a reordering, yet retaining all of the original elements) of the input. For optimum efficiency, the input data should be stored in a data structure which allows random access rather than one that allows only sequential access.

### Classification

Sorting algorithms can be classified by:

* Computational complexity
    * Best, worst and average case behavior in terms of the size of the list. For typical serial sorting algorithms, good behavior is O(n log n), with parallel sort in O(log2 n), and bad behavior is O(n2). Ideal behavior for a serial sort is O(n), but this is not possible in the average case. Optimal parallel sorting is O(log n).
    * Swaps for "in-place" algorithms.
* Memory usage (and use of other computer resources). In particular, some sorting algorithms are "in-place". Strictly, an in-place sort needs only O(1) memory beyond the items being sorted; sometimes O(log n) additional memory is considered "in-place".
* Recursion: Some algorithms are either recursive or non-recursive, while others may be both (e.g., merge sort).
* Stability: stable sorting algorithms maintain the relative order of records with equal keys (i.e., values).
* Whether or not they are a comparison sort. A comparison sort examines the data only by comparing two elements with a comparison operator.
* General method: insertion, exchange, selection, merging, etc. Exchange sorts include bubble sort and quicksort. Selection sorts include cycle sort and heapsort.
* Whether the algorithm is serial or parallel. The remainder of this discussion almost exclusively concentrates upon serial algorithms and assumes serial operation.
* Adaptability: Whether or not the presortedness of the input affects the running time. Algorithms that take this into account are known to be adaptive.
* Online: An algorithm such as Insertion Sort that is online can sort a constant stream of input.

Stability
---------

Stable sort algorithms sort equal elements in the same order that they appear in the input. For example, in the card sorting example below, the cards are being sorted by their rank, and their suit is being ignored. This allows the possibility of multiple different correctly sorted versions of the original list. Stable sorting algorithms choose one of these, according to the following rule: if two items compare as equal (like the two 5 cards), then their relative order will be preserved, i.e. if one comes before the other in the input, it will come before the other in the output.

![](https://user-images.githubusercontent.com/76872415/205345562-a537ca95-b192-4d70-9d66-c1429b2c1eb1.png)  

Stability is important to preserve order over multiple sorts on the same data set. For example, say that student records consisting of name and class section are sorted dynamically, first by name, then by class section. If a stable sorting algorithm is used in both cases, the sort-by-class-section operation will not change the name order; with an unstable sort, it could be that sorting by section shuffles the name order, resulting in a nonalphabetical list of students.

record (rank, suit), and the key is the rank. A sorting algorithm is stable if whenever there are two records R and S with the same key, and R appears before S in the original list, then R will always appear before S in the sorted list.

When equal elements are indistinguishable, such as with integers, or more generally, any data where the entire element is the key, stability is not an issue. Stability is also not an issue if all keys are different.

Comparison of algorithms
------------------------

In these tables, n is the number of records to be sorted. The columns "Best", "Average" and "Worst" give the time complexity in each case, under the assumption that the length of each key is constant, and therefore that all comparisons, swaps and other operations can proceed in constant time. "Memory" denotes the amount of extra storage needed additionally to that used by the list itself, under the same assumption. The run times and the memory requirements listed are inside big O notation, hence the base of the logarithms does not matter.

### Comparison sorts

Below is a table of comparison sorts. A comparison sort cannot perform better than O(n log n) on average.

| Name | Best | Average | Worst | Memory | Stable | Method | Other notes |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Bubble sort | n   | n^2 | n^2 | 1   | Yes | Exchanging | Tiny code size. |
| Selection sort | n^2 | n^2 | n^2 | 1   | No  | Selection | Stable with O(n) extra space, when using linked lists, or when made as a variant of Insertion Sort instead of swapping the two items. |
| Insertion Sort | n   | n^2 | n^2 | 1   | Yes | Insertion | O(n + d), in the worst case over sequences that have d inversions. |
| Quicksort | n*log(n) | n.log(n) | n^2 | log(n) | No  | Partitioning | Quicksort is usually done in-place with O(log n) stack space. |
| Merge Sort | n.log(n) | n.log(n) | n.log(n) | n   | Yes | Merging | Highly parallelizable (up to O(log n) using the Three Hungarians' Algorithm). |
| In-place merge sort | n.log(n) | n.log(n) | n.(log(n))^2 | 1   | Yes | Merging | Can be implemented as a stable sort based on stable in-place merging. |
| Heapsort | n.log(n) | n.log(n) | n.log(n) | 1   | No  | Selection |     |
| Shellsort | n.log(n) | n^(4/3) | n^(3/2) | 1   | No  | Insertion | Small code size |

Non-comparison sorts
--------------------

The following table describes integer sorting algorithms and other sorting algorithms that are not comparison sorts. As such, they are not limited to Ω(n log n). Complexities below assume n items to be sorted. However Non-comparison sorts can have a time complexity of O(n).

* ### Counting sort
    
    counting sort is an algorithm for sorting a collection of objects according to keys that are small positive integers; that is, it is an integer sorting algorithm. It operates by counting the number of objects that possess distinct key values, and applying prefix sum on those counts to determine the positions of each key value in the output sequence. Its running time is linear in the number of items and the difference between the maximum key value and the minimum key value, so it is only suitable for direct use in situations where the variation in keys is not significantly greater than the number of items. It is often used as a subroutine in radix sort, another sorting algorithm, which can handle larger keys more efficiently.
* ### Radix sort
    
    radix sort is a non-comparative sorting algorithm. It avoids comparison by creating and distributing elements into buckets according to their radix. For elements with more than one significant digit, this bucketing process is repeated for each digit, while preserving the ordering of the prior step, until all digits have been considered. For this reason, radix sort has also been called bucket sort and digital sort. Radix sort can be applied to data that can be sorted lexicographically, be they integers, words, punch cards, playing cards, or the mail.