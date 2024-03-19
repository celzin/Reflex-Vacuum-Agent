#include "include/ReflexVacuumAgent.hpp"

Action ReflexVacuumAgent::reflexVacuumAgent(Location location, Status status) {
    if (status == Status::Dirty) {
        return Action::Suck;
    } else if (location == Location::A) {
        return Action::Right;
    } else if (location == Location::B) {
        return Action::Left;
    }
    return Action::NoOp;
}