#include <iostream>
template <typename... Args>
void print(const Args &...args) {

    int _[]{0, (std::cout << args << ' ', 0)...};
    // int _1[]{0,}; 跟随一个逗号,是合法的
    for (int element : _) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}
int main() {
    print("hello", 1, 2, 3, 4, 5, 6);
    print();
    return 0;
}