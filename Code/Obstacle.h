#pragma once
#include "Cells.h"

class Obstacle : public Cells {
public:
    enum ObstacleState {
        DEAD_OBSTACLE = 2,
        ALIVE_OBSTACLE = 3
    };

    Obstacle() : Cells() {}
    
    void SetState(State newState) override;
    State GetState() const override;
    
    void SetObstacleState(ObstacleState obstacleState);
}; 