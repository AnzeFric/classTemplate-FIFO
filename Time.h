//
// Created by anzef on 8. 03. 2023.
//

#ifndef NALOGA0301_TIME_H
#define NALOGA0301_TIME_H


#include <string>

class Time {
private:
    unsigned int hours, minutes, seconds;
public:
    static const unsigned int MaxHours = 24, MaxMinutes = 60, MaxSeconds = 60;
    Time(unsigned int hours, unsigned int minutes, unsigned int seconds);
    std::string toString() const;
    unsigned int convertToSeconds() const;
    static bool isTimeValid(unsigned int hours, unsigned int minutes, unsigned int seconds);
    static Time parse(std::string time);
    static unsigned int diffSeconds(const Time* time1, const Time* time2);
};


#endif //NALOGA0301_TIME_H
