#include "geesespotter_lib.h"
#include <iostream>

//works
char *createBoard(std::size_t xdim, std::size_t ydim) {

	int totalGrid = (xdim) * (ydim);
	char *board{ new char[totalGrid]};
	for (int i = 0; i < totalGrid; i++) {
		board[i] = 0;
	}
	return board;
}


/*void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim) {
	int new_xdim = (int) (xdim);
	int new_ydim = (int) (ydim);
	int totalGrid = xdim * ydim;
	int valueCounter { 0 };


	for (int i = 0; i < totalGrid; i++) {
		int j = i, k = i;
		int xloc{i}, yloc{0};

		if ((board[i] & valueMask()) != 0x09) {
			while (j > (new_xdim -1)){
				j -= new_xdim;
				xloc = j;
			}
			while (k > (new_ydim -1)){
				k -= (new_xdim);
				yloc++;
			}
			for (int reveal_y { yloc - 1 }; reveal_y <= (yloc + 1); reveal_y++) {
				for (int reveal_x { xloc - 1 }; reveal_x <= (xloc + 1); reveal_x++) {
					if ((reveal_x < new_xdim) && (reveal_y < new_ydim) && (reveal_x >= 0) && (reveal_y >= 0)) {
						if ((reveal_y * new_xdim + reveal_x) == i) {
						}
						else if ((board[reveal_y * new_xdim + reveal_x] & valueMask()) == 0x09) {
							valueCounter++;
						}
					}
				}
			}
			board[i] = valueCounter;
			valueCounter = 0;
		}
	}
}*/
void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim) {
	unsigned int totalGrid = xdim * ydim;
	int valueCounter = 0, spotCounter_left = 0, spotCounter_right = 0;
	unsigned int array[totalGrid];
	unsigned int moveCounter = 0;

	for (unsigned int i = 0; i < totalGrid; i++) {
		if ((board[i] & 0x09) == 0x09) {
			array[i] = 0x09;
		}
	}
	for (unsigned int i = 0; i < totalGrid; i++) {
		if (moveCounter == xdim) {
			spotCounter_left++;
			spotCounter_right++;
			moveCounter = 0;
		}
		if ((board[i] & 0x09) == 0x09) {
			moveCounter++;
		}
		else {
			moveCounter++;
			//left-side
			if (i == (xdim * spotCounter_left)) {
				//top-left
				if (i == 0) {
					//right
					if ((board[i + 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//bottom-right
					if ((board[i + xdim + 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//bottom
					if ((board[i + xdim] & 0x09) == 0x09) {
						valueCounter++;
					}
				}
				//bottom-left
				else if (i == ((xdim * ydim) - xdim)) {
					//right
					if ((board[i + 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//top-right
					if ((board[i - xdim + 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//top
					if ((board[i - xdim] & 0x09) == 0x09) {
						valueCounter++;
					}
				}
				//middle-left
				else {
					//top
					if ((board[i - xdim] & 0x09) == 0x09) {
						valueCounter++;
					}
					//top-right
					if ((board[i - xdim + 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//right
					if ((board[i + 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//bottom-right
					if ((board[i + xdim + 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//bottom
					if ((board[i + xdim] & 0x09) == 0x09) {
						valueCounter++;
					}
				}
			}
			//right-side
			else if (i == ((xdim - 1) + (xdim * spotCounter_right))) {
				//top-right
				if (i == (xdim - 1)) {
					//left
					if ((board[i - 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//bottom-left
					if ((board[i + xdim - 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//bottom
					if ((board[i + xdim] & 0x09) == 0x09) {
						valueCounter++;
					}
				}
				//bottom-right
				else if (i == ((xdim * ydim) - 1)) {
					//top
					if ((board[i - xdim] & 0x09) == 0x09) {
						valueCounter++;
					}
					//top-left
					if ((board[i - xdim - 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//left
					if ((board[i - 1] & 0x09) == 0x09) {
						valueCounter++;
					}
				}
				//middle-right
				else {
					//top
					if ((board[i - xdim] & 0x09) == 0x09) {
						valueCounter++;
					}
					//top-left
					if ((board[i - xdim - 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//left
					if ((board[i - 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//bottom-left
					if ((board[i + xdim - 1] & 0x09) == 0x09) {
						valueCounter++;
					}
					//bottom
					if ((board[i + xdim] & 0x09) == 0x09) {
						valueCounter++;
					}
				}
			}
			//middle-top
			else if ((i > 0) && (i < (xdim - 1))) {
				//left
				if ((board[i - 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//right
				if ((board[i + 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//bottom
				if ((board[i + xdim] & 0x09) == 0x09) {
					valueCounter++;
				}
				//bottom-left
				if ((board[i + xdim - 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//bottom-right
				if ((board[i + xdim + 1] & 0x09) == 0x09) {
					valueCounter++;
				}
			}
			//middle-bottom
			else if ((i > ((xdim - 1) * ydim)) && (i < ((xdim * ydim) - 1))) {
				//left
				if ((board[i - 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//right
				if ((board[i + 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//top
				if ((board[i - xdim] & 0x09) == 0x09) {
					valueCounter++;
				}
				//top-left
				if ((board[i - xdim - 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//top-right
				if ((board[i - xdim + 1] & 0x09) == 0x09) {
					valueCounter++;
				}
			} else {
				//left
				if ((board[i - 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//right
				if ((board[i + 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//top
				if ((board[i - xdim] & 0x09) == 0x09) {
					valueCounter++;
				}
				//top-left
				if ((board[i - xdim - 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//top-right
				if ((board[i - xdim + 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//bottom
				if ((board[i + xdim] & 0x09) == 0x09) {
					valueCounter++;
				}
				//bottom-left
				if ((board[i + xdim - 1] & 0x09) == 0x09) {
					valueCounter++;
				}
				//bottom-right
				if ((board[i + xdim + 1] & 0x09) == 0x09) {
					valueCounter++;
				}
			}
			array[i] = valueCounter;
			valueCounter = 0;
		}
	}
	for (unsigned int j = 0; j < totalGrid; j++){
		board[j] = array[j];
	}
}

//works
void hideBoard(char *board, std::size_t xdim, std::size_t ydim) {

	int totalGrid = (xdim) * (ydim);

	for (int i = 0; i < totalGrid; i++) {
		board[i] += hiddenBit();
	}

}

//works
void cleanBoard(char *board) {
	delete [] board;
	board=nullptr;
}

//works
void printBoard(char *board, std::size_t xdim, std::size_t ydim) {

	int totalGrid = (xdim) * (ydim);
	unsigned int counter = 0;

	for (int i = 0; i < totalGrid; i++) {
		if (counter == xdim) {
			std::cout << std::endl;
			counter = 0;
		}

		if ((board[i] & markedBit()) == markedBit()) {
			std::cout << 'M';
		}

		else if ((board[i] & hiddenBit()) == hiddenBit()) {
			std::cout << '*';
		}

		else {
			std::cout << (int) board[i];
		}
		counter++;
	}
	std::cout << std::endl;
}

//works
int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
	int new_xdim = (int)(xdim);
	int new_ydim = (int)(ydim);
	int new_xloc = (int)(xloc);
	int new_yloc = (int)(yloc);

	if ((board[new_xdim*(new_yloc) + new_xloc] & markedBit()) == markedBit()) { // if the place is marked

		return 1;
	}
	else if ((board[new_xdim*(new_yloc) + new_xloc] | valueMask()) < 0x09) { // if the place is already revealed

		return 2;
	}
	else if ((board[new_xdim*(new_yloc) + new_xloc] & valueMask()) == 0x09) { //if the place is a goose
		board[new_xdim*(new_yloc) + new_xloc] = (board[new_xdim*(new_yloc) + new_xloc] & valueMask());
		return 9;
	}
	else { // if the place is a 0
		board[new_xdim * (new_yloc) + new_xloc] = (board[new_xdim * (new_yloc) + new_xloc] & valueMask());

		if ((board[new_xdim * (new_yloc) + new_xloc] & valueMask()) == 0) {

			for (int reveal_y {new_yloc - 1}; reveal_y <= (new_yloc + 1); reveal_y++) {

				for (int reveal_x {new_xloc - 1}; reveal_x <= new_xloc + 1; reveal_x++) {

					if ((reveal_x < new_xdim) && (reveal_y < new_ydim) && (reveal_x >= 0) && (reveal_y >= 0)) {

						if ((board[reveal_y * new_xdim + reveal_x] & markedBit()) == 0) {

							board[reveal_y * new_xdim + reveal_x] = board[reveal_y * new_xdim + reveal_x] & valueMask();
						} else {

							board[reveal_y * new_xdim + reveal_x] = board[reveal_y * new_xdim + reveal_x] & valueMask();
						}
					}

				}
			}
		}
		return 0;
	}
}

//works
int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
	if ((board[xdim*(yloc) + xloc] & markedBit()) == markedBit()) {
		board[xdim*(yloc) + xloc] -= markedBit();
		return 2;
	}
	else if (board[xdim*(yloc) + xloc] < 9) {
		return 2;
	}
	else {
		board[xdim*(yloc) + xloc] += markedBit();
		return 0;
	}
}

//works
bool isGameWon(char *board, std::size_t xdim, std::size_t ydim) {

	int totalGrid = (xdim) * (ydim);
	int counter = 0;

	for (int i = 0; i < totalGrid; i++) {
		if (board[i] > 0x09) {
			if ((board[i] & valueMask()) != 0x09){
				counter++;
			}
		}
	}

	if (counter == 0) {
		return true;
	}
	else {
	return false;
	}
	return false;
}

//old reveal code
/*int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {

	if ((board[xdim*(yloc) + xloc] & markedBit()) == markedBit()) { // if the place is marked
		return 1;
	}
	else if ((board[xdim*(yloc) + xloc] | valueMask()) < 0x09) { // if the place is already revealed
		return 2;
	}
	else if ((board[xdim*(yloc) + xloc] & valueMask()) == 0x09) { //if the place is a goose
		return 9;
	}
	else {
		board[xdim*(yloc) + xloc] = (board[xdim*(yloc) + xloc] & valueMask());
		//if the value is 0
		if (board[xdim*(yloc) + xloc] == 0x00) {
			//if the value is top row
			if ((xdim*(yloc) + xloc) <= (xdim-1)){
				//top-left
				if((xdim*(yloc) + xloc) == 0) {
					//right
					if ((board[(xdim*(yloc) + xloc) + 1] & markedBit()) != markedBit()) {
						board[xdim*(yloc) + xloc + 1] &= valueMask();
					}
					//bottom-right
					if ((board[(xdim*(yloc) + xloc) + xdim + 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + xdim + 1] &= valueMask();
					}
					//bottom
					if ((board[(xdim*(yloc) + xloc) + xdim] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + xdim] &= valueMask();
					}
				}
				//top-right
				else if((xdim*(yloc) + xloc) == (xdim-1)) {
					//left
					if ((board[(xdim*(yloc) + xloc) - 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - 1]  &= valueMask();
					}
					//bottom-left
					if ((board[(xdim*(yloc) + xloc) + xdim - 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + xdim - 1] &= valueMask();
					}
					//bottom
					if ((board[(xdim*(yloc) + xloc) + xdim] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + xdim - 1] &= valueMask();
					}
				}
				//top-middle
				else {
					//left
					if ((board[(xdim*(yloc) + xloc) - 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - 1] &= valueMask();
					}
					//right
					if ((board[(xdim*(yloc) + xloc) + 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + 1] &= valueMask();
					}
					//bottom
					if ((board[(xdim*(yloc) + xloc) + xdim] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + xdim] &= valueMask();
					}
					//bottom-left
					if ((board[(xdim*(yloc) + xloc) + xdim - 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + xdim - 1] &= valueMask();
					}
					//bottom-right
					if ((board[(xdim*(yloc) + xloc) + xdim + 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + xdim - 1] &= valueMask();
					}
				}
			}
			//if the value is the bottom row
			if ((xdim*(yloc) + xloc) >= ((xdim*(ydim - 1)))) {
				//bottom-right
				if ((xdim*(yloc) + xloc) == ((xdim*ydim)-1)) {
					//top
					if ((board[(xdim*(yloc) + xloc) - xdim] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - xdim] &= valueMask();
					}
					//top-left
					if ((board[(xdim*(yloc) + xloc) - xdim - 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - xdim - 1] &= valueMask();
					}
					//left
					if ((board[(xdim*(yloc) + xloc) - 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - 1] &= valueMask();
					}
				}
				//bottom-left
				else if ((xdim*(yloc) + xloc) == (xdim*(ydim-1))) {
					//right
					if ((board[(xdim*(yloc) + xloc) + 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + 1] &= valueMask();
					}
					//top-right
					if ((board[(xdim*(yloc) + xloc) - xdim + 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - xdim + 1] &= valueMask();
					}
					//top
					if ((board[(xdim*(yloc) + xloc) - xdim] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - xdim] &= valueMask();
					}
				}
				//bottom-middle
				else{
					//left
					if ((board[(xdim*(yloc) + xloc) - 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - 1] &= valueMask();
					}
					//right
					if ((board[(xdim*(yloc) + xloc) + 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) + 1] &= valueMask();
					}
					//top
					if ((board[(xdim*(yloc) + xloc) - xdim] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - xdim] &= valueMask();
					}
					//top-left
					if ((board[(xdim*(yloc) + xloc) - xdim - 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - xdim - 1] &= valueMask();
					}
					//top-right
					if ((board[(xdim*(yloc) + xloc) - xdim + 1] & markedBit()) != markedBit()) {
						board[(xdim*(yloc) + xloc) - xdim + 1] &= valueMask();
					}
				}
			}
			//left-middle
			else if ((xdim*(yloc) + xloc) == (xdim*yloc)) {
				//top
				if ((board[(xdim*(yloc) + xloc) - xdim] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - xdim] &= valueMask();
				}
				//top-right
				if ((board[(xdim*(yloc) + xloc) - xdim + 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - xdim + 1] &= valueMask();
				}
				//right
				if ((board[(xdim*(yloc) + xloc) + 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + 1] &= valueMask();
				}
				//bottom-right
				if ((board[(xdim*(yloc) + xloc) + xdim + 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + xdim + 1] &= valueMask();
				}
				//bottom
				if ((board[(xdim*(yloc) + xloc) + xdim] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + xdim] &= valueMask();
				}
			}
			//right-middle
			else if ((xdim*(yloc) + xloc) == ((xdim *yloc)+(xdim-1))) {
				//top
				if ((board[(xdim*(yloc) + xloc) - xdim] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - xdim] &= valueMask();
				}
				//top-left
				if ((board[(xdim*(yloc) + xloc) - xdim - 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - xdim - 1] &= valueMask();
				}
				//left
				if ((board[(xdim*(yloc) + xloc) - 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - 1] &= valueMask();
				}
				//bottom-left
				if ((board[(xdim*(yloc) + xloc) + xdim - 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + xdim - 1]  &= valueMask();
				}
				//bottom
				if ((board[(xdim*(yloc) + xloc) + xdim] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + xdim] &= valueMask();
				}
			}
			//middle-middle
			else {
				//left
				if ((board[(xdim*(yloc) + xloc) - 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - 1] &= valueMask();
				}
				//right
				if ((board[(xdim*(yloc) + xloc) + 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + 1] &= valueMask();
				}
				//top
				if ((board[(xdim*(yloc) + xloc) - xdim] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - xdim] &= valueMask();
				}
				//top-left
				if ((board[(xdim*(yloc) + xloc) - xdim - 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - xdim - 1] &= valueMask();
				}
				//top-right
				if ((board[(xdim*(yloc) + xloc) - xdim + 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) - xdim + 1] &= valueMask();
				}
				//bottom
				if ((board[(xdim*(yloc) + xloc) + xdim] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + xdim] &= valueMask();
				}
				//bottom-left
				if ((board[(xdim*(yloc) + xloc) + xdim - 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + xdim - 1] &= valueMask();
				}
				//bottom-right
				if ((board[(xdim*(yloc) + xloc) + xdim + 1] & markedBit()) != markedBit()) {
					board[(xdim*(yloc) + xloc) + xdim + 1] &= valueMask();
				}
			}
		}
		return 0;
	}
}
*/
//works

