#pragma once
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "PlayerScore.h"
using json = nlohmann::json;

class JsonObject
{
public:
    void updatePlayerHighestScore(const std::string& playerName, int newScore);
    void updateTop5Scores(const std::string& playerName, int newScore);


private:
    int readPlayerHighestScore(const std::string& playerName);
    std::vector<PlayerScore> readTop5Scores();


};

