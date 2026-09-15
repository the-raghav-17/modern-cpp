#include <iostream>
#include <vector>


// We're allowing the caller to provide a comparator, based on which
// the sorting is done either in ascending or descending order
//
// The comparator is a function that takes two integers, andd returns
// boolean which decides which kind of sorting is to be done
void selection_sort(std::vector<int>& arr, bool (*comparator)(int, int))
{
    auto size{ arr.size() };

    for (int i = 0; i < size - 1; i++) {
        int min{ arr.at(i) };
        int min_j{ i };

        for (int j = i + 1; j < size; j++) {
            if (comparator(arr.at(j), min)) {
                min = arr.at(j);
                min_j = j;
            }
        }

        std::swap(arr.at(min_j), arr.at(i));
    }
}


int main()
{
    std::vector<int> arr1{ 5, 3, 1, 5, 10, 4 };
    std::vector<int> arr2{ 5, 3, 1, 5, 10, 4 };

    selection_sort(arr1, [](int x, int y){ return x > y; } ); // providing a comparator that does
                                                              // descending sorting

    for (const auto& num : arr1) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    selection_sort(arr2, [](int x, int y){ return x < y; } ); // providing a comparator that does
                                                              // ascending sorting

    for (const auto& num : arr2) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}
