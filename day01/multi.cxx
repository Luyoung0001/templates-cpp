#include <iostream>

// using namespace std;


template <typename T> void test(T) { std::puts("template"); }
void test(int) { std::puts("int"); }

void f(const char*, int, double) { puts("值"); }
void f(const char**, int*, double*) { puts("&"); }


template<typename...Args>
void sum(Args...args){  // const char * args0, int args1, double args2
    f(args...);   // 相当于 f(args0, args1, args2)
    f(&args...);  // 相当于 f(&args0, &args1, &args2)
}

int main() {
    test(1);
    // 匹配到test(int)
    test(1.2);
    // 匹配到模板
    test("1");
    // 匹配到模板
    sum("luse", 1, 1.2);
    return 0;
}
