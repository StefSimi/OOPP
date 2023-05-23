#pragma once
#include <nlohmann/json.hpp>
#include "PlayerScore.h"
using json = nlohmann::json; 
class PlayerScore
{
public:
    std::string playerName;
    int score;
    PlayerScore() : playerName(""), score(0) {}
    PlayerScore(const std::string& name, int s) : playerName(name), score(s) {}
};

