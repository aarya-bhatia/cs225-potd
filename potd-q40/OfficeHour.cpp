#include <iostream>
#include "OfficeHour.h"
#include <vector>
#include <assert.h>

/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent)
{
    if(onDutyStaff.empty()) return -1;

    int timeElapsed = 0;
    std::vector<int> timeLeft;
    timeLeft.reserve(onDutyStaff.size());

    for(size_t i = 0; i < timeLeft.size(); i++)
    {
        timeLeft[i] = 0;
    }

    size_t staffSize = onDutyStaff.size();

    int n = 0;

    while(n < nthStudent)
    {
        Student &student = queue.front();
        bool found = false;

        bool noStaff = false;
        for(size_t i = 0; i < staffSize; i++)
        {
            if(onDutyStaff[i].getEnergyLevel() > 0) {
                noStaff = true;     
                break;
            }
        }

        if(!noStaff) {
            return -1;
        }

        for(size_t i = 0; i < staffSize; i++)
        {
            if(timeLeft[i] == 0 && onDutyStaff[i].getEnergyLevel() > 0)
            {
                Staffer &staffer = onDutyStaff[i];
                int waitTime = staffer.answerQuestion(student.getQuestionType(),student.getTimeNeeded());
                printf("%s assigned to %s with expected wait time of %d mins\n", staffer.name.c_str(), student.name, waitTime);
                timeLeft[i] += waitTime;
                found = true;
                assert(waitTime > 0);
                break;
            }
        }

        if(found)
        {
            queue.pop();
            n++;
            // printf("Number of students remaining in queue: %lu\n", queue.size());
        }
        else
        {
            printf("No staff memebers available for student %s\n", student.name);
            int minTime = timeLeft[0];

            for(size_t i = 0; i < staffSize; i++)
            {
                if(timeLeft[i] < minTime) {
                    minTime = timeLeft[i];
                }
            }

            for(size_t i = 0; i < staffSize; i++)
            {
                timeLeft[i] -= minTime;
            }

            timeElapsed += minTime;
        }

        for(size_t i = 0; i < staffSize; i++)
        {
            printf("%s waiting time: %d min\n", onDutyStaff[i].name.c_str(), timeLeft[i]);
        }

        printf("Time elapsed: %d\n", timeElapsed);
    }
   
    return timeElapsed;
}
