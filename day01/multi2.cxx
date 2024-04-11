#include <iostream>
template <typename... Args>
void print(const Args &...args) {
    using Arr = int[];
    // 弃值表达式
    // 在这个修改后的代码中，(void) 明确表示这是一个弃值表达式，消除了编译器的警告。
    (void)Arr{0,(std::cout << args<< ' ',0)...};
}
int main() {
    print("luse", 1, 2, 3, 4, 5);
    print();
    return 0;
}