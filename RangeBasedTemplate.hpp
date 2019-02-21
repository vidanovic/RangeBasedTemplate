#pragma once

#include <memory>

template<typename T>
class CustomContainer;

template<typename T>
class CustomIterator {
public:
    explicit CustomIterator(const CustomContainer<T> &c, unsigned idx = 0) : m_Container(c), m_Index(idx) {}

    bool operator!=(const CustomIterator &other) {
        return (m_Index != other.m_Index);
    }

    const CustomIterator &operator++() {
        m_Index++;
        return *this;
    }

    T &operator*() const { return m_Container.get(m_Index); };

private:
    const CustomContainer<T> &m_Container;
    unsigned m_Index;
};

template<typename T>
class CustomContainer {
public:
    explicit CustomContainer(const unsigned capacity) : m_CurrentIndex(0), m_Capacity(capacity),
                                                        buffer(new T[m_Capacity]) {}

    void add(const T &obj) {
        buffer[m_CurrentIndex++] = obj;
    }

    T &get(unsigned idx) const {
        //assert(idx < m_CurrentIndex);
        return buffer[idx];
    }

    CustomIterator<T> begin() const {
        return CustomIterator<T>(*this, 0);
    }

    CustomIterator<T> end() const {
        return CustomIterator<T>(*this, m_CurrentIndex);
    }

private:
    unsigned m_CurrentIndex;
    unsigned m_Capacity;
    std::unique_ptr<T[]> buffer;
};