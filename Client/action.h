#ifndef ACTION_H
#define ACTION_H
#include <string>

struct Action
{
public:
    double direction;
    double velocity;
    double acceleration;
    std::string description;
    Action();
};

#endif // ACTION_H
