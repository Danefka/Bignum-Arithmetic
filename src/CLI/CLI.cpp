//
// Created by Даниил Гиршович on 21.12.2024.
//

#include "include/CLI.h"

void CLI::help() {
    nlohmann::json data;
    std::unordered_map<int, std::string> map;
    std::ifstream inFile("commands.json");

    if (!inFile.is_open()) {
        throw std::runtime_error("Не удаётся открыть файл commands.json, проверьте целостность проекта.\n");
    }

    inFile >> data;
    inFile.close();


    for (const auto &[shortCommand, fullCommand] : data.items()) {
        int i = atoi(shortCommand.data());
        map[i] = fullCommand;
    }
    for (int i = 1; i <= 45; i++) {
        if (i < 10){
            std::cout << i << "  :" << map[i] << std::endl;
            continue;
        }
        std::cout << i << " :" << map[i] << std::endl;
    }


}

void CLI::run() {
    while (true){
        std::string input;
        std::cin >> input;
        int i = std::stoi(input);
        switch (i) {
            case 1:

        }
    }
}
