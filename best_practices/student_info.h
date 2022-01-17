#ifndef _STUDENT_INFO
#define _STUDENT_INFO

#include <string>

using std::string;

namespace brian {

    class StudentInformation {

    private:
        string m_name;
        string m_id;

    public:
        StudentInformation(string name, string id);

        virtual ~StudentInformation();

        void print_info();

        void print_separator();
    };
}

#endif