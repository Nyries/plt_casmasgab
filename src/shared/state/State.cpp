//
// Created by louismmassin on 11/8/24.
//
#include "State.h"

#include <iostream>
#include <fstream>
#include <json/json.h>

namespace state {
    State::State(std::string stateJsonPath): accusationSuccess(false), envelope()
    {
        std::ifstream file(stateJsonPath);
        Json::Value stateJsonData;
        file >> stateJsonData;
        file.close();

        players = new CircularPlayerList(stateJsonData["playersCount"].asInt());
        map = new Map(stateJsonData["mapJsonPath"].asString());
    }

    Map* State::getMap() {
        return map;
    }
}
