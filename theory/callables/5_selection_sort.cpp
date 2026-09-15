#include <iostream>
#include <vector>


void selection_sort(std::vector<int>& arr)
{
    auto size{ arr.size() };

    for (int i = 0; i < size - 1; i++) {
        int min{ arr.at(i) };
        int min_j{ i };

        for (int j = i + 1; j < size; j++) {
            if (arr.at(j) < min) {
                min = arr.at(j);
                min_j = j;
            }
        }

        std::swap(arr.at(min_j), arr.at(i));
    }
}


int main()
{
    std::vector<int> arr{ 5, 4, 3, 2, 1 };
    selection_sort(arr);

    for (const auto& elem : arr) {
        std::cout << elem << ' ';
    }

    std::cout << '\n';
}
