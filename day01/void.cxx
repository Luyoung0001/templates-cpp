#include <iostream>

int getValue() {
    std::cout << "Getting value..." << std::endl;
    return 42;
}

int main() {

    (void)getValue();

    // 使用弃值表达式，修改变量的值
    int x = 10;
    (void)((x > 5) ? (std::cout << "hello1\n", 0)
                   : (std::cout << "hello2\n", 0));

    return 0;
}
