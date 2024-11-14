#include <iostream>

void DoSomething(int i, bool b, float f, double d, unsigned int u, char c){
    // does smth
}

struct DoSomethingFunctor
{
    DoSomethingFunctor(int i, bool b, float f, double d, unsigned int u)
            : m_i(i)
            , m_b(b)
            , m_f(f)
            , m_d(d)
            , m_u(u)
    {}

    int operator() (char c) const{
        DoSomething(m_i, m_b, m_f, m_d, m_u, c);
        ++m_count;
    }

    int m_i;
    bool m_b;
    float m_f;
    double m_d;
    unsigned int m_u;
    mutable unsigned int m_count;
};

int Add(int x, int y){
    return x + y;
}

int main() {
    DoSomethingFunctor o(1, true, 2.f, 3., 4u);
    o('a');
    o('c');
    return 0;
}

