#include <iostream>
#include "include/ReflexVacuumAgent.hpp"

int main() {
    ReflexVacuumAgent agent;
    int totalScore = 0;
    int scenarioCount = 0;

    // Arrays para manter os diferentes status e localizações
    Status allStatuses[2] = { Status::Clean, Status::Dirty };
    Location allLocations[2] = { Location::A, Location::B };

    // Loop sobre os dois locais possiveis onde o aspirador pode começar: A ou B
    for (Location startingLocation : allLocations) {
        // Loop sobre os dois estados possiveis de A: limpo ou sujo
        for (Status statusA : allStatuses) {
            // Loop sobre os dois estados possiveis de B: limpo ou sujo
            for (Status statusB : allStatuses) {
                int scenarioScore = 0;
                Location location = startingLocation;
                Status statusAtA = statusA;
                Status statusAtB = statusB;

                std::cout << "Início: " << (location == Location::A ? "A" : "B")
                    << ", (A: " << (statusAtA == Status::Clean ? "Limpo" : "Sujo")
                    << ", B: " << (statusAtB == Status::Clean ? "Limpo)" : "Sujo)") << std::endl;

                // Executa o agente até que ambos os locais estejam limpos
                while (statusAtA == Status::Dirty || statusAtB == Status::Dirty) {
                    // Determina o status atual com base na localização do agente
                    Status currentStatus = (location == Location::A) ? statusAtA : statusAtB;
                    // Agente decide a ação com base na sua localização e status
                    Action action = agent.reflexVacuumAgent(location, currentStatus);

                    std::cout << "Localização: " << (location == Location::A ? "A" : "B")
                        << ", (A: " << (statusAtA == Status::Clean ? "Limpo" : "Sujo")
                        << ", B: " << (statusAtB == Status::Clean ? "Limpo)" : "Sujo)")
                        << ", Ação: " << (action == Action::Suck ? "Aspirar" : (action == Action::Right ? "Direita" : "Esquerda"));

                    // Realiza a ação e atualiza a pontuação se a ação "Aspirar" for em local sujo
                    if (action == Action::Suck) {
                        // Se o local estava sujo, limpa e incrementa a pontuação
                        if ((location == Location::A && statusAtA == Status::Dirty) || (location == Location::B && statusAtB == Status::Dirty)) {
                            scenarioScore++;
                            if (location == Location::A) {
                                statusAtA = Status::Clean; // Limpa A
                            } else {
                                statusAtB = Status::Clean; // Limpa B
                            }
                            std::cout << ", Pontuação: " << scenarioScore;
                        }
                    } else if (action == Action::Right) {
                        location = Location::B; // Move para direita (B)
                    } else if (action == Action::Left) {
                        location = Location::A; // Move para esquerda (A)
                    }
                    std::cout << std::endl;
                }

                // Incrementa os contadores e imprime a pontuação final para o cenário
                totalScore += scenarioScore;
                scenarioCount++;
                std::cout << "Cenário Completo! Pontuação Final: " << scenarioScore << "\n" << std::endl;
            }
        }
    }

    // Calcula e imprime a pontuação média geral.
    std::cout << "Pontuação Média Geral: " << (totalScore / static_cast<double>(scenarioCount)) << std::endl;

    return 0;
}
