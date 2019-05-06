#include <stdio.h>
#include <CoalaMOD.h>
#pragma comment (lib, "CoalaMOD.lib")

#define SWAP(s, e){int t = s; s = e ; e = t;}

int find_min(int a, int b, int c) {
	int min = 999999;

	if (a < min) {
		min = a;
	}
	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
	return min;
}

int main() {
	BlockID stone = createBlock(BLOCK_STONE);
	int k;
	int sx, sy, sz = 0;
	int ex, ey, ez = 0;


	scanf_s("%d %d %d", &sx, &sy, &sz);
	scanf_s(" %d %d %d", &ex, &ey, &ez);


	if (sx > ex) SWAP(sx, ex);
	if (sy > ey) SWAP(sy, ey);
	if (sz > ez) SWAP(sz, ez);


	//�־��� �����ȿ��� ������ ������Ų �ǹ��� �������
	//�� ��ǥ�� ���� �� �ּڰ��� �� ������ �ϴ� ���簢�� �ǹ��̾����.
	k = find_min(ex - sx, ey - sy, ez - sz);


	for (int y = sy; y < sy + k; y++) {
		for (int x = sx; x < sx + k; x++) {
			for (int z = sz; z < sz + k; z++) {
				locateBlock(stone, x, y, z);
			}
		}
	}



}