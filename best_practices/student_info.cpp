#include <iostream>
#include "student_info.h"

brian::StudentInformation::StudentInformation(std::string name, std::string id) :
        m_name(name), m_id(id) {
}

brian::StudentInformation::~StudentInformation() {
}

void brian::StudentInformation::print_info() {
    std::cout << "Name: " << m_name << ", ID: " << m_id << std::endl;
}

void brian::StudentInformation::print_separator() {

    const int COUNT = 10;

    // printing out separator line
    for (int i = 0; i < COUNT; ++i) {

        std::cout << "-";

    }
}