#include <CoalaMOD.h>
#include <stdio.h>
#pragma comment(lib, "CoalaMOD.lib")
#include <math.h>
int main() {
	double pi = 3.14159265358979323846;
	BlockID my_stone = createBlock(BLOCK_NETHERRACK);
	BlockID glass = createBlock(BLOCK_GLASS);
	int px, py, pz;
	getPlayerLocation(&px, &py, &pz);
	double dir = getPlayerDirection();
	double radian = dir * pi / 180.;
	int dx = -10 * sin(radian);
	int dz = 10 * cos(radian);
	px += dx;
	pz += dz;
	//晦菅 1類 ~ 4類
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 10; i++) {
			locateBlock(my_stone, px + i, py + j, pz);
			locateBlock(my_stone, px, py + j, pz - i);
			locateBlock(my_stone, px + 9, py + j, pz - i);
			locateBlock(my_stone, px + i, py + j, pz - 9);
		}
	}
	//嶸葬雖種 1類
	for (int i = 0; i < 10; i++) {
		locateBlock(glass, px + i, py + 4, pz);
		locateBlock(glass, px, py + 4, pz - i);
		locateBlock(glass, px + 9, py + 4, pz - i);
		locateBlock(glass, px + i, py + 4, pz - 9);
	}
	//嶸葬雖種 2類
	for (int i = 1; i < 9; i++) {
		locateBlock(glass, px + i, py + 5, pz - 1); //嬴概還
		locateBlock(glass, px + 1, py + 5, pz - i); //豭薹還
		locateBlock(glass, px + 8, py + 5, pz - i); //螃艇薹還
		locateBlock(glass, px + i, py + 5, pz - 8); //嶺還
	}
	//嶸葬雖種 3類
	for (int i = 3; i < 7; i++) {
		locateBlock(glass, px + i, py + 6, pz - 1); //嬴概還
		locateBlock(glass, px + 1, py + 6, pz - i); //豭薹還
		locateBlock(glass, px + 8, py + 6, pz - i); //螃艇薹還
		locateBlock(glass, px + i, py + 6, pz - 8); //嶺還
	}
	//褊濠陛 雖種 3類
	for (int i = 2; i < 8; i++) {
		locateBlock(my_stone, px + i, py + 6, pz + 4 - 9);
		locateBlock(my_stone, px + i, py + 6, pz + 5 - 9);
		locateBlock(my_stone, px + 4, py + 6, pz + i - 9);
		locateBlock(my_stone, px + 5, py + 6, pz + i - 9);
	}


}