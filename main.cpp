#include <iostream>

#include "long_lists.cpp"
// defines one_hundred[], one_thousand[], ten_thousand[], hundred_thousand[]

/*
 *  The quickSearch function finds the index if a key value in an array and
 *  returns that index.
 *  Parameters:
 *      key -- the value we're looking for
 *      collection -- The array of values we're looking in
 *      length -- the length of the collection array
 *      counter -- Used to pass back the number of iterations used by the
 *                 algorithm
 *  Returns:
 *      The index of the value in the list if found, otherwise -1 is returned
 *      if the value is not found in the list.
 */

template<class DataType>
int quickSearch(const DataType key, DataType *collection, int length, long &counter) {
    int lo = 0;
    int hi = length -1;
    while (lo <= hi) {
        counter++;
        int mid = lo + (hi -lo) / 2;
        if (key < collection[mid]) {
            hi = mid - 1;
        } else if (key > collection[mid]) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

/*
 * linearSearch's parameters and results are the same as quickSearch, only the
 * implemented algorithm is different
 */
template<class DataType>
int linearSearch(const DataType key, DataType *collection, int length, long &counter) {

    for (int i = 0; i < length; ++i) {
        counter++;
        if (collection[i] == key) {
            return i;
        }
    }
    return -1;

}

int main() {
    // fill an array with odd numbers from 1 to 201
    // [1, 3, 5, 7, ... 195, 197, 199]
    int test_collection[100];
    for (int i = 0; i < 100; ++i) {
        test_collection[i] = i * 2 + 1;
    }

    int test_collection2[] = {34, 7, 3, 23, 65, 8, 94, 7};

    int find = 135;
    long counter = 0;

    int result = quickSearch<int>(find, test_collection, 100, counter);

    std::cout << "Quick Search found " << find << " at index "
              << result << " in "
              << counter << " iterations."
              << std::endl;


    counter = 0;

    result = linearSearch(find, test_collection, 100, counter);

    std::cout << "Linear Search found " << find << " at index "
              << result << " in "
              << counter << " iterations."
              << std::endl;


    return 0;
}
