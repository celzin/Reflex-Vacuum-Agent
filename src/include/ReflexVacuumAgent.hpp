#ifndef REFLEX_VACUUM_AGENT_HPP
#define REFLEX_VACUUM_AGENT_HPP

enum class Location { A, B };
enum class Status { Clean, Dirty };
enum class Action { Suck, Right, Left, NoOp };

class ReflexVacuumAgent {
public:
    Action reflexVacuumAgent(Location location, Status status);
};

#endif 
