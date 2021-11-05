#include "OfficeHour.h"
#include "Student.h"
#include <iostream>

using namespace std;

int findWaitTime()
{
    queue<Student> students;
    vector<Staffer> staff;
    int n = 4;

    students.push(Student(8, "THEORY", "Taylor"));
    students.push(Student(13, "MP", "Timmy"));
    students.push(Student(6, "LAB", "Billie"));
    students.push(Student(7, "THEORY", "Jean"));

    staff.push_back(Staffer("THEORY", 100, std::string("Wade")));
    staff.push_back(Staffer("LAB", 100, std::string("Mattox")));

    return waitTime(students, staff, n);
}

int findWaitTime2() {
    Student Billy = Student(12, "POTD");
    Student Joel = Student(15, "MP");
    Student Jean = Student(8, "MP");
    Student Taylor = Student(6, "LAB");
    Student TimTim = Student(13, "POTD");

    queue<Student> officeHourQueue;
    officeHourQueue.push(Billy);
    officeHourQueue.push(Joel);
    officeHourQueue.push(Jean);
    officeHourQueue.push(Taylor);
    officeHourQueue.push(TimTim);

    Staffer Wade = Staffer("LAB", 2);
    Staffer Mattox = Staffer("MP", 0);
    vector<Staffer> onDutyStaff {Wade, Mattox};

    int expectedWaitTime = waitTime(officeHourQueue, onDutyStaff, 4);

    cout << "The expected wait time for Taylor, the fourth student in the queue, is " << to_string(expectedWaitTime) << " minutes." << endl;

    return expectedWaitTime;
};

int main()
{
    int expectedWaitTime = findWaitTime();
    printf("Expected wait time: %d min\n", expectedWaitTime);

    printf("============================\n");

    expectedWaitTime = findWaitTime2();
    printf("Expected wait time: %d min\n", expectedWaitTime);
}
