#define FALCON_TESTING
//#define MAZE_TESTING

#define F21
//#define F20





#ifdef MAZE_TESTING

#include "src/maze.h"
#include <stdio.h>
#include <iostream>
#include <vector>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define NORTH_WEST 4
#define NORTH_EAST 5
#define SOUTH_WEST 6
#define SOUTH_EAST 7
#define IS_AT_BEGINNING 8
#define IS_AT_CENTER 9


//Internal for elsewhere
int next_cell_direction = 0; //TOP
int direction; //maze internal

//Signals from/to elsewhere:
int current_direction = NORTH;
int next_direction = -1; //A direction or AT_BEGINNING or AT_CENTER
int drive_distance = 1; //MAZE MUST SPECIFY DISTANCE TO DRIVE IN SPEED DRIVE MODE

int mouse_x = 0;
int mouse_y = 0;

vector<Cell*> stack;


float drive_top_speed = 0.1;
float turn_top_speed = 0.2;

bool has_left_wall = true;
bool has_right_wall = true;

int main() {
	vector<Cell*> stack;
    init_maze();
    //generate_random_walls();
    update_distances(stack);
    explore(stack, mouse_x, mouse_y);
}

#endif





#ifdef FALCON_TESTING

#include "mbed.h"
#include "./config/initDevices.hpp"
#include "./drivers/testFunctions.hpp"

int main()
{
	cycleLEDs(0.5);
	cycleMFs(1.0);
	testBuzzer();
}

#endif