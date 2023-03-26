#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
01_����ũ����Ʈ
*/

#include<cstdio>
#define rint register int

const int LM = 502;

int N, M, B;
int land[LM][LM];
int time[257] = { 0 };	// Ư�� ���̸� �ױ� ���� �ʿ��� �ð�
int block[257] = { 0 };	// Ư�� ���̸� �ױ� ���� �ʿ��� ��

int main() {
#ifdef _WIN32
	freopen("01.txt", "r", stdin);
#endif

	scanf("%d %d %d", &N, &M, &B);

	int unit_height;
	for (rint i = 0; i < N; i++) {
		for (rint j = 0; j < N; j++) {
			scanf("%d", &unit_height);
			for (rint k = 0; k <= 256; k++) {
				if (unit_height < k) {	// ��ǥ�� �ϴ� ���̺��� ������ �� �׾ƾ� ��.
					time[k]++;
					block[k]--;
				}
				else if (unit_height > k) {	// ��ǥ�� �ϴ� ���̺��� ������ �� ���� ��
					time[k] += 2;
					block[k]++;
				}
			}
		}
	}

	int time_min = 1 << 30;
	int height_max = 0;
	for (rint i = 0; i <= 256; i++) {

		printf("h: %d, time: %d, block: %d\n", i, time[i], block[i]+B);
		/*if (block[i] < B) continue;

		if (time[i] <= time_min) {
			time_min = time[i];
			if (i > height_max) {
				height_max = i;
			}
		}*/
	}

	printf("%d %d", time_min, height_max);
}