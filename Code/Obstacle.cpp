#include "Obstacle.h"

void Obstacle::SetState(State newState) {
    (void)newState;
    return;
}

Cells::State Obstacle::GetState() const {
    return state;
}

void Obstacle::SetObstacleState(ObstacleState obstacleState) {
    state = static_cast<State>(obstacleState);
} 