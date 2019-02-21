#include <iostream>

#include "RangeBasedTemplate.hpp"

class Test {
public:
    Test() : m_Number(0), m_Description("-") {}

    Test(int number, std::string m_Description) : m_Number(number),
    m_Description(std::move(m_Description)) {}

    int number() const {
        return m_Number;
    }

    std::string description() const {
        return m_Description;
    };

private:
    int m_Number;
    std::string m_Description;
};

int main() {
    CustomContainer<Test> cont(10);

    cont.add(Test(9, "IX"));
    cont.add(Test(56, "LVI"));
    cont.add(Test(43, "XLIII"));
    cont.add(Test(1984, "MCMXXCIV"));

    for (const auto &obj : cont) {
        std::cout << obj.number() << ": " << obj.description() << std::endl;
    }

    return 0;
}