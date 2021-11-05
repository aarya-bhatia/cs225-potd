#pragma once

#include <algorithm>
#include <cmath>
#include <string>

class Staffer {
    public:
        Staffer(std::string favQuestion, int startingEnergy, std::string name = "");

        int getEnergyLevel();

        int answerQuestion(std::string questionType, int anticipatedTime);

        std::string name;

    private:
        int energyLevel;
        std::string favoriteType;
};
