#include <iostream>
#include <vector>
#include <set>

template<typename T> void DumbSearch(const T begin, const T end) {
    std::cout << "Dumb search: "<< std::endl;
    for (T p1=begin;p1!=end;++p1) {
        T p2;
        for (p2=begin; p2!=p1; ++p2)
            if (*p1==*p2)
                break;
        if (p1==p2)
            std::cout << *p1 << " ";
    }
    std::cout << std::endl;
}

template<typename T> void SmartSearch(const T begin, const T end) {
    std::cout << "Smart search: "<< std::endl;
    std::set<std::string> buf(begin, end);
    for (auto i : buf) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<std::string> MyVec = {"One", "Two", "Three", "Two", "Four", "Five", "One", "Two", "Snake!",};
    std::multiset<std::string> MySet(MyVec.begin(), MyVec.end());
    DumbSearch(MyVec.begin(), MyVec.end());
    DumbSearch(MySet.begin(), MySet.end());
    SmartSearch(MyVec.begin(),MyVec.end());
    SmartSearch(MySet.begin(),MySet.end());
    return 0;
}
