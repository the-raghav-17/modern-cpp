#include <vector>
#include <functional>
#include <iostream>


void selection_sort(std::vector<int>& arr,
                    std::function<bool(int, int)> comparator)
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
    std::vector<int> arr{ 4, 5, 3, 1, 2 };

    // Anonymous lambda
    selection_sort(arr,
                   [](int a, int b){
                       return a < b;
                   });

    for (const auto& elem : arr) {
        std::cout << elem << ' ';
    }

    // Named lambda
    auto decreasing_order{
        [](int a, int b) {
            return a > b;
        }
    };

    std::cout << '\n';

    std::vector<int> another_arr{ 4, 5, 3, 1, 2 };
    selection_sort(another_arr, decreasing_order);
    for (const auto& elem : another_arr) {
        std::cout << elem << ' ';
    }

    // In actuality, a lambda is simply just a functor.

    // We can also wrap a lambda inside a function pointer
    // But doing so requires that the lambda's capture clause
    // must be empty

    bool (*lambda_ptr)(int, double) {
        [](int a, double b) -> bool {
            if (a % 2) {
                return false;
            }
            return true;
        }
    };

    // We can also wrap a lambda inside std::function

    std::function lamb{ [](int, double) -> bool {
            if (a % 2) {
                return false;
            }
            return true;
    } };
}
