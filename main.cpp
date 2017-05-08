#include "config/initModes.hpp"


#if _OPERATING_MODE == 'M'

	#include "src/maze.cpp"
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

	using namespace std;

	//Internal for elsewhere
	// int next_cell_direction = 0; //TOP
	// int direction; //maze internal

	//Signals from/to elsewhere:
	// int current_direction = NORTH;
	// int next_direction = -1; //A direction or AT_BEGINNING or AT_CENTER
	// int drive_distance = 1; //MAZE MUST SPECIFY DISTANCE TO DRIVE IN SPEED DRIVE MODE

	int mouse_x = 0;
	int mouse_y = 0;

	vector<unsigned char> stack;


	// float drive_top_speed = 0.1;
	// float turn_top_speed = 0.2;

	int main() {
		cycleLEDs(0.1);
		Maze();
		print_maze();
		vector<unsigned char> stack;
	    update_distances(stack);
	    explore(stack, mouse_x, mouse_y);
	}
// END





#elif _OPERATING_MODE == 'D'

	#include "mbed.h"
	#include "config/initDevices.hpp"
	#include "drivers/testFunctions.hpp"
	#include "drivers/debug_io.hpp"


	int main()
	{
		simpleDemo();
	}
// END





#elif _OPERATING_MODE == 'T'
	#include "mbed.h"
	#include "config/initDevices.hpp"
	#include "drivers/testFunctions.hpp"
	#include "drivers/debug_io.hpp"
	#include "drivers/drive_controller.hpp"

	int main()
	{		
		cycleLEDs(0.05);

		/*
		while(1) {
			wait(0.1);
			print_gyro();
			testBuzzer();
		}
		*/
		
		/*
		bluetooth.printf("Executing...\r\n");
		bluetooth.printf("Left Motor:  InvFwd = %d \t InvBkwd = %d\r\n", leftMotor.invFwd, leftMotor.invBkwd);
		bluetooth.printf("Right Motor: InvFwd = %d \t InvBkwd = %d\r\n\n", rightMotor.invFwd, rightMotor.invBkwd);
		
		turnLeft();
		wait(0.1);
		turnRight();
		
		bluetooth.printf("\r\n");
		*/
		
		forward();
		wait(0.5);
		turnLeft();
		wait(0.5);
		forward();
		wait(0.5);
		turnLeft();
		wait(0.5);
		forward();
		wait(0.5);
		turnLeft();
		wait(0.5);
		forward();
		wait(0.5);
		turnLeft();
	}


#endif