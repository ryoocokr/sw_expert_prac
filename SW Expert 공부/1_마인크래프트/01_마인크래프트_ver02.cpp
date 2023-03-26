#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
01_����ũ����Ʈ_�ð� ���������� 95��.. ���� �𸣰���.
*/

#include<cstdio>
#define rint register int

const int LM = 502;

int N, M, B;
int cnt[257] = { 0 };

int main() {
#ifdef _WIN32
	freopen("01.txt", "r", stdin);
#endif

	scanf("%d %d %d", &N, &M, &B);

	int unit_height;
	int diff;

	int min = 256;
	int max = 1;

	for (rint i = 0; i < N; i++) {
		for (rint j = 0; j < M; j++) {
			scanf("%d", &unit_height);
			cnt[unit_height]++;
			if (unit_height < min)	min = unit_height;
			if (unit_height > max) max = unit_height;
		}
	}

	int time_min = 1 << 30;
	int height_max = 0;

	for (rint i = 0; i <= 256; i++) {
		int time_h = 0;
		int block_h = B;
		for (rint j = min; j <= max && cnt[j]; j++) {
			if (j < i) {	// ��ǥ�� �ϴ� ���̺��� ������ �� �׾ƾ� ��.
				diff = (i - j);
				time_h += cnt[j] * diff;
				block_h -= cnt[j] * diff;
			}
			else if (j > i) {	// ��ǥ�� �ϴ� ���̺��� ������ �� ���� ��
				diff = (j - i);
				time_h += cnt[j] * 2 * diff;
				block_h += cnt[j] * diff;
			}
			//printf("time: %d, h: %d, block: %d\n", time[i], i, block[i] + B);
		}
		if (block_h < 0)
			continue;

		if (time_h <= time_min) {
			time_min = time_h;
			if (i > height_max) {
				height_max = i;
			}
		}
	}


	printf("%d %d", time_min, height_max);
}