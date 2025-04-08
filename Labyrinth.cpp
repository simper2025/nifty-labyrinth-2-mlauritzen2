#include "Labyrinth.h"
#include <set>
#include <algorithm>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    (void)start;
    (void)moves;

    MazeCell* curr = start;

    std::set<Item> bagOfHolding;

    for (int i = 0; moves[i] != '\0'; i++) {
        char s = moves[i];

        switch (s)
        {
        case 'N':
            curr = curr->north;
            break;
        case 'E':
            curr = curr->east;
            break;
        case 'W':
            curr = curr->west;
            break;
        case 'S':
            curr = curr->south;
            break;
        default:
            break;
        }

        if (curr == NULL)
            return false;

        auto contains = bagOfHolding.find(curr->whatsHere) != bagOfHolding.end();
        if (curr->whatsHere != Item::NOTHING && !contains) {
            bagOfHolding.insert(curr->whatsHere);
        }

    }

    if (bagOfHolding.size() == 3) {
        return true;
    }

    return false;
}
