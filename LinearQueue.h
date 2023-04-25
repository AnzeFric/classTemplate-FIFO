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
    LinearQueue(std::vector<T> &values);
    bool empty() const;
    int size();
    T element() const;
    void add(T value);
    bool remove();
    std::string toString() const;
    void reverse();
    T getMax();
    T getLast() const;
    void sort();
    void print() const;
};

template<typename T>
LinearQueue<T>::LinearQueue(std::vector<T> &values) : values(values){}

template<typename T>
bool LinearQueue<T>::empty() const {
    if(LinearQueue<T>::values.size() > 1){
        return false;
    }
    return true;
}

template<typename T>
int LinearQueue<T>::size() {
    return LinearQueue<T>::values.size();
}

template<typename T>
T LinearQueue<T>::element() const {
    if(!LinearQueue<T>::values.empty()) {
        return LinearQueue<T>::values.front();
    } else{
        std::cout << "The vector is empty: ";
        return -1;
    }
}

template<typename T>
void LinearQueue<T>::add(T value) {
    LinearQueue<T>::values.push_back(value);
}

template<typename T>
bool LinearQueue<T>::remove() {
    int size = LinearQueue<T>::size();
    LinearQueue<T>::values.erase(LinearQueue<T>::values.begin());
    if(LinearQueue<T>::size() != size){
        return true;
    }
    return false;
}

template<typename T>
std::string LinearQueue<T>::toString() const {
    std::string str;
    for(T v : LinearQueue<T>::values){
        str += std::to_string(v) + " ";
    }
    return str;
}

template<typename T>
void LinearQueue<T>::reverse() {
    std::vector<T> startingValues = LinearQueue<T>::values;
    int index = 0;
    for(int i = LinearQueue<T>::values.size(); i > 0; i--){
        LinearQueue<T>::values[index] = startingValues[i - 1];
        index++;
    }
}

template<typename T>
T LinearQueue<T>::getMax() {
    T element = values.back();
    for(T v : LinearQueue<T>::values){
        if(v > element){
            element = v;
        }
    }
    return element;
}

template<typename T>
T LinearQueue<T>::getLast() const {
    return LinearQueue<T>::values.back();
}

template<typename T>
void LinearQueue<T>::sort(){
    for (int i = 0; i < LinearQueue<T>::values.size() - 1; i++) {
        for (int j = 0; j < LinearQueue<T>::values.size() - i - 1; j++) {
            if (LinearQueue<T>::values[j] > LinearQueue<T>::values[j + 1]) {
                std::swap(LinearQueue<T>::values[j], LinearQueue<T>::values[j + 1]);
            }
        }
    }
}

template<typename T>
void LinearQueue<T>::print() const {
    std::cout << LinearQueue<T>::toString() << std::endl;
}

template<>
class LinearQueue<Time> {
private:
    std::vector<Time> values;
public:
    LinearQueue(std::vector<Time> &values);
    bool empty() const;
    int size();
    Time element() const;
    void add(Time value);
    bool remove();
    std::string toString() const;
    void reverse();
    Time getMax();
    Time getLast() const;
    void sort();
    void print() const;
};

LinearQueue<Time>::LinearQueue(std::vector<Time> &values) : values(values){}

bool LinearQueue<Time>::empty() const {
    if(LinearQueue<Time>::values.size() > 1){
        return false;
    }
    return true;
}

int LinearQueue<Time>::size() {
    int size = 0;
    for(Time t : LinearQueue<Time>::values){
        size++;
    }
    return size;
}

Time LinearQueue<Time>::element() const {
    if(!LinearQueue<Time>::values.empty()) {
        return LinearQueue<Time>::values.front();
    } else{
        std::cout << "The vector is empty: ";
        return {0,0,0};
    }
}

void LinearQueue<Time>::add(Time value) {
    LinearQueue<Time>::values.push_back(value);
}

bool LinearQueue<Time>::remove() {
    int size = LinearQueue<Time>::size();
    LinearQueue<Time>::values.erase(LinearQueue<Time>::values.begin());
    if(LinearQueue<Time>::size() != size){
        return true;
    }
    return false;
}

std::string LinearQueue<Time>::toString() const {
    std::string str;
    for(Time v : LinearQueue<Time>::values){
        str += v.toString() + " ";
    }
    return str;
}

void LinearQueue<Time>::reverse() {
    std::vector<Time> startingValues = LinearQueue<Time>::values;
    int index = 0;
    for(unsigned int i = LinearQueue<Time>::values.size(); i > 0; i--){
        LinearQueue<Time>::values[index] = startingValues[i - 1];
        index++;
    }
}

Time LinearQueue<Time>::getMax() {
    Time element = values.back();
    for(Time v : LinearQueue<Time>::values){
        if(v.convertToSeconds() > element.convertToSeconds()){
            element = v;
        }
    }
    return element;
}

Time LinearQueue<Time>::getLast() const {
    return LinearQueue<Time>::values.back();
}

void LinearQueue<Time>::sort(){
    for (int i = 0; i < LinearQueue<Time>::values.size() - 1; i++) {
        for (int j = 0; j < LinearQueue<Time>::values.size() - i - 1; j++) {
            if (LinearQueue<Time>::values[j].convertToSeconds() > LinearQueue<Time>::values[j + 1].convertToSeconds()) {
                std::swap(LinearQueue<Time>::values[j], LinearQueue<Time>::values[j + 1]);
            }
        }
    }
}

void LinearQueue<Time>::print() const {
    std::cout << LinearQueue<Time>::toString() << std::endl;
}

#endif //NALOGA0801_LINEARQUEUE_H
