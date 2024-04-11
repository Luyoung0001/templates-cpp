
// 万能转发(引用)
template <typename T> void f(T &&t) { t = 0; }

int main() {
    int a = 10;
    f(a);  // 左值引用
    f(10); //右值引用
    return 0;
}