#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
01_마인크래프트
*/

#include<cstdio>
#define rint register int

const int LM = 502;

int N, M, B;
int land[LM][LM];
int time[257] = { 0 };	// 특정 높이를 쌓기 위해 필요한 시간
int block[257] = { 0 };	// 특정 높이를 쌓기 위해 필요한 블럭

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
				if (unit_height < k) {	// 목표로 하는 높이보다 낮으면 → 쌓아야 함.
					time[k]++;
					block[k]--;
				}
				else if (unit_height > k) {	// 목표로 하는 높이보다 높으면 → 빼야 함
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