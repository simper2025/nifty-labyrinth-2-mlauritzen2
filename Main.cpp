#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

/* Change this constant to contain your name.
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const std::string kYourName = "Michael Lauritzen";

/* Change these constants to contain the paths out of your mazes. */
const std::string kPathOutOfNormalMaze = "SSSWENWNWSWSNENESENNWWWS";
const std::string kPathOutOfTwistyMaze = "NSENENNE.";

//maze solver test
string SolveMaze(MazeCell*, string,bool,bool,bool);


bool hasPot = false;
bool hasWand = false;
bool hasBook = false;

set<string>edges;

auto contains = edges.find(MazeCell*) != bagOfHolding.end();

int main() {
	/* Generate the maze.
	 *
	 * Note: Don't set a breakpoint on this line. Otherwise, you'll see startLocation before
	 * it's been initialized.
	 */
	MazeCell* startLocation = mazeFor(kYourName);

	/* Set a breakpoint here to explore your maze! */
	if (isPathToFreedom(startLocation, kPathOutOfNormalMaze)) {
		std::cout << "Congratulations! You've found a way out of your labyrinth." << std::endl;
	}
	else {
		std::cout << "Sorry, but you're still stuck in your labyrinth." << std::endl;
	}


	/* Generate the twisty maze.
	 *
	 * Note: Don't set a breakpoint on this line. Otherwise, you'll see twistyStartLocation before
	 * it's been initialized.
	 */
	MazeCell* twistyStartLocation = twistyMazeFor(kYourName);

	string path = SolveMaze(startLocation, path, hasPot, hasBook, hasWand);

	/* Set a breakpoint here to explore your twisty maze! */
	if (isPathToFreedom(twistyStartLocation, kPathOutOfTwistyMaze)) {
		std::cout << "Congratulations! You've found a way out of your twisty labyrinth." << std::endl;
	}
	else {
		std::cout << "Sorry, but you're still stuck in your twisty labyrinth." << std::endl;
	}

	return 0;
}


string SolveMaze(MazeCell* curr, string path, bool pot, bool book, bool wand)
{

	if (curr->whatsHere == Item::POTION)
		pot = true;
	if (curr->whatsHere == Item::SPELLBOOK)
		book = true;
	if (curr->whatsHere == Item::WAND)
		wand = true;

	if (pot && book && wand)
		return path;

	if (curr->north != nullptr)
		return SolveMaze(curr->north, path + "N", pot, book, wand);
	if (curr->south != nullptr)
		return SolveMaze(curr->south, path + "S", pot, book, wand);
	if (curr->east != nullptr)
		return SolveMaze(curr->east, path + "E", pot, book, wand);
	if (curr->west != nullptr)
		return SolveMaze(curr->west, path + "W", pot, book, wand);

}