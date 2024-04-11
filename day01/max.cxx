#include <iostream>
using namespace std::string_literals;
template <typename T> T max(T a, T b) {
    std::cout << "max_tp:" << std::endl;
    return a > b ? a : b;
}
// 既然有”类型模板形参“，自然有非类型的，顾名思义，
// 也就是模板不接受类型，而是接受值或对象。
template <std::size_t N=888> void f() { std::cout << N << '\n'; }

struct Test {
    int v_{};
    Test() = default;
    Test(int v) : v_(v) {}
    bool operator>(const Test &t) const { return this->v_ > t.v_; }
};
int main() {

    // 编译器会实例化两个函数
    int a{1};
    int b{2};
    std::cout << "max(a,b):" << max(a, b) << '\n';

    Test t1{10};
    Test t2{20};
    std::cout << "max(t1,t2):" << max(t1, t2).v_ << '\n';

    double d1{0.1};
    double d2{0.2};
    std::cout << "max(d1,d2):" << max<double>(d1, d2)
              << '\n'; // 传递模板类型实参，函数模板 max 为 max<double>

    std::cout << "max(string1,string2):"
              << ::max<std::string>("hello1"s, "hello2"s) << '\n';

    f<100>();
    f<>();

    return 0;
}