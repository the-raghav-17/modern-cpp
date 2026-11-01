#include <type_traits>

int foo();

static_assert
(
    std::is_void_v<void> == true and
    std::is_void_v<const void> == true and
    std::is_void_v<volatile void> == true and
    std::is_void_v<void*> == false and
    std::is_void_v<int> == false and
    std::is_void_v<decltype(foo)> == false and
    std::is_void_v<std::is_void<void>> == false
);

int main() {
    decltype(foo) a{ 100 };
}
