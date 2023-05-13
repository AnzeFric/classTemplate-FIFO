//
// Created by anzef on 24. 04. 2023.
//

#ifndef NALOGA0801_LINEARQUEUE_H
#define NALOGA0801_LINEARQUEUE_H

#include <vector>
#include <string>
#include "Time.h"

template<typename T>
class LinearQueue {
private:
    std::vector<T> values;
public:
    explicit LinearQueue(std::vector<T> &values) : values(values) {};

    bool empty() const {
        if (LinearQueue<T>::values.size() > 1) {
            return false;
        }
        return true;
    };

    int size() {
        return LinearQueue<T>::values.size();
    };

    T element() const {
        if (!LinearQueue<T>::values.empty()) {
            return LinearQueue<T>::values.front();
        } else {
            return -1;
        }
    };

    void add(T value) {
        LinearQueue<T>::values.push_back(value);
    };

    bool remove() {
        if (values.empty()) {
            return false;
        }
        int size = LinearQueue<T>::size();
        LinearQueue<T>::values.erase(LinearQueue<T>::values.begin());
        if (LinearQueue<T>::size() != size) {
            return true;
        }
        return false;
    };

    std::string toString() const {
        std::string str;
        for (T v: LinearQueue<T>::values) {
            str += std::to_string(v) + " ";
        }
        return str;
    };

    void reverse() {
        std::vector<T> startingValues = LinearQueue<T>::values;
        int index = 0;
        for (int i = LinearQueue<T>::values.size(); i > 0; i--) {
            LinearQueue<T>::values[index] = startingValues[i - 1];
            index++;
        }
    };

    T getMax() {
        if (values.empty()) {
            return 0;
        }
        T element = values.back();
        for (T v: LinearQueue<T>::values) {
            if (v > element) {
                element = v;
            }
        }
        return element;
    };

    T getLast() const {
        if (values.empty()) {
            return 0;
        }
        return LinearQueue<T>::values.back();
    };

    void sort() {
        if (values.empty()) {
            std::cout << "The queue is empty!" << std::endl;
            return;
        }
        for (int i = 0; i < LinearQueue<T>::values.size() - 1; i++) {
            for (int j = 0; j < LinearQueue<T>::values.size() - i - 1; j++) {
                if (LinearQueue<T>::values[j] > LinearQueue<T>::values[j + 1]) {
                    std::swap(LinearQueue<T>::values[j], LinearQueue<T>::values[j + 1]);
                }
            }
        }
    };

    void print() const {
        std::cout << LinearQueue<T>::toString() << std::endl;

    };

    void addElements(std::vector<T> vec) {
        values.insert(values.end(), vec.begin(), vec.end());

    };
};


template<>
class LinearQueue<Time> {
private:
    std::vector<Time> values;
public:
    explicit LinearQueue(std::vector<Time> &values) : values(values) {};

    bool empty() const {
        if (LinearQueue<Time>::values.size() > 1) {
            return false;
        }
        return true;
    };

    int size() {
        int size = 0;
        for (Time t: LinearQueue<Time>::values) {
            size++;
        }
        return size;
    };

    Time element() const {
        if (!LinearQueue<Time>::values.empty()) {
            return LinearQueue<Time>::values.front();
        } else {
            return {0, 0, 0};
        }
    };

    void add(Time value) {
        LinearQueue<Time>::values.push_back(value);
    };

    bool remove() {
        if (values.empty()) {
            return false;
        }
        int size = LinearQueue<Time>::size();
        LinearQueue<Time>::values.erase(LinearQueue<Time>::values.begin());
        if (LinearQueue<Time>::size() != size) {
            return true;
        }
        return false;
    };

    std::string toString() const {
        std::string str;
        for (Time v: LinearQueue<Time>::values) {
            str += v.toString() + " ";
        }
        return str;
    };

    void reverse() {
        if (values.empty()) {
            std::cout << "The queue is empty!";
            return;
        }
        std::vector<Time> startingValues = LinearQueue<Time>::values;
        int index = 0;
        for (unsigned int i = LinearQueue<Time>::values.size(); i > 0; i--) {
            LinearQueue<Time>::values[index] = startingValues[i - 1];
            index++;
        }
    };

    Time getMax() {
        if (values.empty()) {
            return {0, 0, 0};
        }
        Time element = values.back();
        for (Time v: LinearQueue<Time>::values) {
            if (v.convertToSeconds() > element.convertToSeconds()) {
                element = v;
            }
        }
        return element;
    };

    Time getLast() const {
        if (values.empty()) {
            return {0, 0, 0};
        }
        return LinearQueue<Time>::values.back();
    };

    void sort() {
        if (values.empty()) {
            std::cout << "The queue is empty!";
            return;
        }
        for (int i = 0; i < LinearQueue<Time>::values.size() - 1; i++) {
            for (int j = 0; j < LinearQueue<Time>::values.size() - i - 1; j++) {
                if (LinearQueue<Time>::values[j].convertToSeconds() >
                    LinearQueue<Time>::values[j + 1].convertToSeconds()) {
                    std::swap(LinearQueue<Time>::values[j], LinearQueue<Time>::values[j + 1]);
                }
            }
        }
    };

    void print() const {
        std::cout << LinearQueue<Time>::toString() << std::endl;

    };

    void addElements(std::vector<Time> vec) {
        values.insert(values.end(), vec.begin(), vec.end());

    };
};


#endif //NALOGA0801_LINEARQUEUE_H
