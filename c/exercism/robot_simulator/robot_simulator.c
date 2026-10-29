#include "robot_simulator.h"
#include "string.h"


robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t status;
    status.direction = direction;
    status.position.x = x; 
    status.position.y = y;


    return status;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    if (robot == NULL || commands == NULL) return;

    if(robot->direction < DIRECTION_NORTH || robot->direction >= DIRECTION_MAX) return;

    for (size_t i = 0; commands[i] != '\0'; ++i)
    {
        switch (commands[i])
        {
            case 'R':
                robot->direction = (robot->direction + 1) % DIRECTION_MAX;
                break;
            case 'L':
                robot->direction = (robot->direction - 1 + DIRECTION_MAX) % DIRECTION_MAX;
                break;
            case 'A':
                switch (robot->direction)
                {
                    case DIRECTION_NORTH:
                        robot->position.y += 1;
                        break;
                    case DIRECTION_EAST:
                        robot->position.x += 1;
                        break;
                    case DIRECTION_SOUTH:
                        robot->position.y -= 1;
                        break;
                    case DIRECTION_WEST:
                        robot->position.x -= 1;
                        break;
                    default:
                        break; // This should never happen due to the earlier check
                }
                break;
            default:
                // Invalid command, ignore or handle as needed
                break;
        }
    }

    
}