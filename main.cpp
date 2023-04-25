#include <iostream>
#include "LinearQueue.h"

int main() {
    std::cout << "Testing for int: " << std::endl;
    std::vector<int> vecInt = {5, 1, 100, 3, 5, 1, 6, 8, 9, 21, 4, 12, 6, 14, 61};
    LinearQueue<int> intVar(vecInt);
    std::cout << "is empty: " << intVar.empty() << std::endl;
    std::cout << "size: " << intVar.size() << std::endl;
    std::cout << "front element: " << intVar.element() << std::endl;
    std::cout << "add element: ";
    intVar.add(2023);
    intVar.print();
    std::cout << "remove first element: " << intVar.remove() << std::endl;
    intVar.print();
    std::cout << "reverse: " << std::endl;
    intVar.reverse();
    intVar.print();
    std::cout << "get max: " << intVar.getMax() << std::endl;
    std::cout << "get last: " << intVar.getLast() << std::endl;
    std::cout << "sort: ";
    intVar.sort();
    intVar.print();

    std::cout << "==================" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Testing for float and double" << std::endl;

    std::vector<float> vecFloat = {1.1f, 3.2f, 41.2f, 6.1f, 8.8f};
    LinearQueue<float> floatVar(vecFloat);

    std::cout << "float reverse: ";
    floatVar.reverse();
    floatVar.print();
    std::cout << "float sort: ";
    floatVar.sort();
    floatVar.print();

    std::vector<double> vecDouble = {1.231, 152.213, 32311.231, 532.123, 3.213, 32.32, 2.1233};
    LinearQueue<double> doubleVar(vecDouble);

    std::cout << "double reverse: ";
    doubleVar.reverse();
    doubleVar.print();
    std::cout << "double sort: ";
    doubleVar.sort();
    doubleVar.print();

    std::cout << "==================" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Testing for Time" << std::endl;

    std::vector<Time> timeVec = {Time(1,2,3), Time(3,2,1), Time(2,2,2)};
    LinearQueue<Time> time(timeVec);

    std::cout << "empty: " << time.empty() << std::endl;
    std::cout << "size: " << time.size() << std::endl;
    std::cout << "first el.: " << time.element().toString() << std::endl;
    std::cout << "add: ";
    time.add({5,5,5});
    time.print();
    std::cout << "remove: " << time.remove() << std::endl;
    time.print();
    std::cout << "reverse: ";
    time.reverse();
    time.print();
    std::cout << "get max: " << time.getMax().toString() << std::endl;
    std::cout << "get last: " << time.getLast().toString() << std::endl;
    std::cout << "sort: ";
    time.sort();
    time.print();
    return 0;
}
