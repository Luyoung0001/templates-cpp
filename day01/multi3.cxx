#include <iostream>

template <typename... Args>
void print(const Args &...args) {
    using arr = int[];
    (void)arr{0, (std::cout << args << ' ', 0)...};
}

template <typename T, std::size_t N, typename... Args>
void f(const T (&array)[N], Args... index) {
    print(array[index]...);
}
int main() {
    int arr[5] {1, 2, 3, 4, 5};
    f<int,5,int,int,int >(arr, 1, 2, 4);
    return 0;
}
