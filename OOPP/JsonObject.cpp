#include "JsonObject.h"
#include "PlayerScore.h"
void JsonObject::updatePlayerHighestScore(const std::string& playerName, int newScore)
{
    int currentPlayerHighestScore = readPlayerHighestScore(playerName);
    if (newScore > currentPlayerHighestScore) {
        json jsonData;
        std::ifstream file("scores.json");
        if (file.is_open()) {
            file >> jsonData;
            file.close();
        }

        jsonData[playerName] = newScore;  
        std::ofstream outFile("scores.json");
        if (outFile.is_open()) {
            outFile << jsonData.dump(4);  
            outFile.close();
            std::cout << "New highest score for player " << playerName << ": " << newScore << std::endl;
        }
        else {
            std::cerr << "Failed to open scores.json for writing!" << std::endl;
        }
    }
}
void JsonObject::updateTop5Scores(const std::string& playerName, int newScore)
{
    std::vector<PlayerScore> currentTopScores = readTop5Scores();
    currentTopScores.emplace_back(playerName, newScore);

    
    std::sort(currentTopScores.begin(), currentTopScores.end(),
        [](const PlayerScore& a, const PlayerScore& b) {
            return a.score > b.score;
        });

    
    if (currentTopScores.size() > 5) {
        currentTopScores.resize(5);
    }

    json jsonData;
    jsonData["top_scores"] = json::array();
    for (const auto& score : currentTopScores) {
        jsonData["top_scores"].push_back({ {"player_name", score.playerName}, {"score", score.score} });
    }

    std::ofstream outFile("top5.json");
    if (outFile.is_open()) {
        outFile << jsonData.dump(4);  
        outFile.close();
        std::cout << "Updated top 5 scores saved." << std::endl;
    }
    else {
        std::cerr << "Failed to open top5.json for writing!" << std::endl;
    }
}
int JsonObject::readPlayerHighestScore(const std::string& playerName)
{
    std::ifstream file("scores.json");
    if (!file.is_open()) {
        return 0;  
    }

    json jsonData;
    file >> jsonData;
    file.close();

    if (jsonData.contains(playerName)) {
        return jsonData[playerName].get<int>();
    }
    else {
        return 0;  
    }
}

std::vector<PlayerScore> JsonObject::readTop5Scores()
{
    std::ifstream file("top5.json");
    if (!file.is_open()) {
        return std::vector<PlayerScore>(); 
    }

    json jsonData;
    file >> jsonData;
    file.close();

    std::vector<PlayerScore> topScores;
    if (jsonData.contains("top_scores")) {
        for (const auto& entry : jsonData["top_scores"]) {
            std::string playerName = entry["player_name"].get<std::string>();
            int score = entry["score"].get<int>();
            topScores.emplace_back(playerName, score);
        }
    }

    return topScores;
}
