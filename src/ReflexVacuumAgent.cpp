#include "include/ReflexVacuumAgent.hpp"

// Função que determina a ação do agente com base na sua localização e no status dessa localização
Action ReflexVacuumAgent::reflexVacuumAgent(Location location, Status status) {

    // Se o status da localização atual for 'Sujo', a ação 'Suck' é retornada
    if (status == Status::Dirty) {
        return Action::Suck;

        // Se a localização atual for 'A' e estiver 'Limpa', a ação 'Direita' (B) é retornada
    } else if (location == Location::A) {
        return Action::Right;

        // Se a localização atual for 'B' e estiver limpa, a ação 'Esquerda' (A) é retornada
    } else if (location == Location::B) {
        return Action::Left;
    }

    // Caso nenhuma das condições, retorna 'NoOp' (sem operação).
    return Action::NoOp;
}