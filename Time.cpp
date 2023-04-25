//
// Created by anzef on 8. 03. 2023.
//

#include "Time.h"

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds) : hours(hours), minutes(minutes),
                                                                             seconds(seconds) {
}

std::string addZeroIfOneDigit(unsigned int time) {
    std::string timeText = "";
    if (time < 10) {
        timeText = "0" + std::to_string(time);
    } else {
        timeText = std::to_string(time);
    }
    return timeText;
}

std::string Time::toString() const {
    std::string hoursText, minutesText, secondsText;

    hoursText = addZeroIfOneDigit(hours);
    minutesText = addZeroIfOneDigit(minutes);
    secondsText = addZeroIfOneDigit(seconds);

    return hoursText + ":" + minutesText + ":" + secondsText;
}

bool Time::isTimeValid(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    if (hours >= Time::MaxHours || minutes >= Time::MaxMinutes || seconds >= Time::MaxSeconds) {
        return false;
    }
    return true;
}

Time Time::parse(std::string time) {
    std::string delimiter = ":";
    std::string valuesArr[3];

    for (auto &i: valuesArr) {
        std::string token = time.substr(0, time.find(delimiter));
        time.erase(0, time.find(delimiter) + delimiter.length());
        i = token;
    }

    Time emptyObject(std::stoi(valuesArr[0]), std::stoi(valuesArr[1]), std::stoi(valuesArr[2]));
    return emptyObject;
}

unsigned int Time::diffSeconds(const Time *time1, const Time *time2) {
    unsigned int secondsTime1 = time1->hours * 3600 + time1->minutes * 60 + time1->seconds;
    unsigned int secondsTime2 = time2->hours * 3600 + time2->minutes * 60 + time2->seconds;
    int difference = secondsTime1 - secondsTime2;

    return abs(difference);
}

unsigned int Time::convertToSeconds() const {
    return Time::seconds + Time::minutes * 60 + Time::hours * 3600;
}
