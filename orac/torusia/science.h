// You may change the following constant for debugging
#define SIZE 4096

//Your program should implement these two functions:
void alison();
void bill();

//The provided library will implement these functions:

//Function that Alison can call
void mark(int x, int y);

//Functions that Bill can call
int numRow(int y);
int numColumn(int x);
void found(int x, int y);

#include <stdio.h>
#include <stdlib.h>

#define MAX_TURNS 10000
#define LOG_FILE "mark_log"

char _science_player;
int _science_turn;
int _science_numRow[SIZE];
int _science_numCol[SIZE];
char _science_marked[SIZE][SIZE];
int _science_alisonX, _science_alisonY;

FILE* _science_log;

void _science_exit() {
	if (_science_log) fclose(_science_log);
	exit(0);
}

void _science_nextTurn() {
	int x, y;
	_science_turn++;

	//Too many turns!
	if (_science_turn > MAX_TURNS) {
		fprintf(stderr, "Exceeded %d minutes, exiting now.", MAX_TURNS);
		_science_exit();
	}

	//Alison has already stopped marking, no need to read from file
	if (feof(_science_log)) return;

	//Try to read next marked square from file
	if (fscanf(_science_log, "%d %d ", &x, &y) != 2) {
		fprintf(stderr, "Bad data in mark log file. Have you forgotten to run Alison first, or accidentally tampered with the file?\n");
		_science_exit();
	}

	//Are co-ordinates sane?
	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
		fprintf(stderr, "Bad data in log file. Have you accidentally tampered with the file?\n");
		_science_exit();
	}

	//Translate to Bill's co-ordinates
	x = (x + _science_alisonX) % SIZE;
	y = (y + _science_alisonY) % SIZE;
    printf("square at %d %d\n",x,y);

	if (!_science_marked[x][y]) {
		_science_marked[x][y] = 1;
		_science_numRow[y]++;
		_science_numCol[x]++;
	}
}

void mark(int x, int y) {
	if (_science_player != 'A') {
		fprintf(stderr, "Function 'mark' should only be called by Alison!\n");
		_science_exit();
	}

	
	_science_turn++;

	if (_science_turn > MAX_TURNS) {
		fprintf(stderr, "Exceeded %d minutes, exiting now.", MAX_TURNS);
		_science_exit();
	}

	if (x >= SIZE || x < 0 || y >= SIZE || y < 0) {
		fprintf(stderr, "Bad parameters to mark(%d, %d). Must be in range [0,%d]\n",
				x, y, SIZE-1);
		_science_exit();
	}

	fprintf(_science_log, "%d %d\n", x, y);
}

int numRow(int y) {
	if (_science_player != 'B') {
		fprintf(stderr, "Function 'numRow' should only be called by Bill!\n");
		_science_exit();
	}

	_science_nextTurn();

	if (y < 0 || y >= SIZE) {
		fprintf(stderr, "Bad parameter to numRow(%d), must be in range [0,%d]\n", y, SIZE-1);
		_science_exit();
	}

	return _science_numRow[y];
}

int numColumn(int x) {
	if (_science_player != 'B') {
		fprintf(stderr, "Function 'numColumn' should only be called by Bill!\n");
		_science_exit();
	}

	_science_nextTurn();

	if (x < 0 || x >= SIZE) {
		fprintf(stderr, "Bad parameter to numColumn(%d), must be in range [0,%d]\n", x, SIZE-1);
		_science_exit();
	}

	return _science_numCol[x];
}

void found(int x, int y) {
	float score;
	if (_science_player != 'B') {
		fprintf(stderr, "Function 'found' should only be called by Bill!\n");
		_science_exit();
	}

	if (x == _science_alisonX && y == _science_alisonY) {
		fprintf(stderr, "CORRECT! Bill found Alison at (%d, %d) in %d minutes.\n", x, y, _science_turn);

		score = 13000.0 / (_science_turn ? _science_turn : 1) + 10.0;
		if (score > 100.0) score = 100.0;
		fprintf(stderr, "Score: %.2f / 100\n", score);
	} else {
		fprintf(stderr, "Incorrect. Bill thinks Alison is at (%d, %d), actually she was at (%d, %d).\n", x, y, _science_alisonX, _science_alisonY);
	}
	_science_exit();

}

int main(int argc, char *argv[]) {
   if (SIZE != 4096) {
      fprintf(stderr, "Warning: you are testing on a %dx%d grid.\n", SIZE, SIZE);
   }
	
	if (scanf("%c", &_science_player) != 1) {
		fprintf(stderr, "Program must be provided with 'A' or 'B' in standard input.\n");
		_science_exit();
	}

	if (_science_player == 'A') {

		_science_log = fopen(LOG_FILE, "w");
		if (!_science_log) {
			fprintf(stderr, "Could not open log file '%s' for writing.\n", LOG_FILE);
			_science_exit();
		}

		//Pass control to user (Alison)
		alison();

		fclose(_science_log);

		fprintf(stderr, "Alison successfully completed execution, wrote log to '%s'. Now you should run this program as Bill.\n", LOG_FILE);

	} else if (_science_player == 'B') {

		if (scanf("%d %d", &_science_alisonX, &_science_alisonY) != 2) {
			fprintf(stderr, "After 'B', input should contain two space separated integers for Alison's X and Y position.\n");
			_science_exit();
		}
		if (_science_alisonX < 0 || _science_alisonX >= SIZE
		 || _science_alisonY < 0 || _science_alisonY >= SIZE) {
			fprintf(stderr, "Alison's X and Y co-ordinates (%d, %d) must be in range [0,%d].\n",
					_science_alisonX, _science_alisonY, SIZE-1);
			_science_exit();
		}

		_science_log = fopen(LOG_FILE, "r");
		if (!_science_log) {
			fprintf(stderr, "Could not open log file '%s' for reading. Make sure you run this program as Alison first and leave the log file unchanged.\n", LOG_FILE);
			_science_exit();
		}
		fscanf(_science_log, " "); //if empty file, skip the \n to the EOF

		//Pass control to user (Bill)
		bill();

		//Execution should never reach here, means that 'found' wasn't called.
		fprintf(stderr, "Bill didn't call 'found' before exiting!\n");
		_science_exit();

	} else {
		fprintf(stderr, "First character of input must be 'A' or 'B'.\n");
		_science_exit();
	}
}

