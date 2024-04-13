#include <iostream>
#include <type_traits>
// std::common_type_t 的作用很简单，就是确定我们传入的共用类型，
// 说白了就是这些东西都能隐式转换到哪个，那就会返回那个类型。
template <typename... Args, typename RT = std::common_type_t<Args...>>
RT sum(const Args &...args) {
    RT _[]{static_cast<RT>(args)...};
    RT n{};
    for (int i = 0; i < long(sizeof...(args)); ++i) {
        n += _[i];
    }
    return n;
}
int main() {
    double ret = sum(1, 2, 3, 4, 5, 6.7);
    std::cout << ret << '\n';
    return 0;
}