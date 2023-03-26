//#ifndef _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
///*
//01_마인크래프트_시간 빨라졌으나 50점.. 이유 모르겠음.
//*/
//
//#include<cstdio>
//#define rint register int
//
//const int LM = 502;
//
//int N, M, B;
//int time[257] = { 0 };	// 특정 높이를 쌓기 위해 필요한 시간
//int block[257] = { 0 };	// 특정 높이를 쌓기 위해 필요한 블럭
//
//int main() {
//#ifdef _WIN32
//	freopen("01.txt", "r", stdin);
//#endif
//
//	scanf("%d %d %d", &N, &M, &B);
//
//	int unit_height;
//	int diff;
//
//	for (rint i = 0; i < N; i++) {
//		for (rint j = 0; j < M; j++) {
//			scanf("%d", &unit_height);
//			for (rint k = 0; k <= 256; k++) {
//				if (unit_height < k) {	// 목표로 하는 높이보다 낮으면 → 쌓아야 함.
//					diff = (k - unit_height);
//					time[k] += diff;
//					block[k] -= diff;
//				}
//				else if (unit_height > k) {	// 목표로 하는 높이보다 높으면 → 빼야 함
//					diff = (unit_height - k);
//					time[k] += (2 * diff);
//					block[k] += diff;
//				}
//			}
//		}
//	}
//
//	int time_min = 1 << 30;
//	int height_max = 0;
//	for (rint i = 0; i <= 256; i++) {
//
//		//printf("time: %d, h: %d, block: %d\n", time[i], i, block[i] + B);
//		if (block[i] > B) 
//			continue;
//
//		if (time[i] <= time_min) {
//			time_min = time[i];
//			if (i > height_max) {
//				height_max = i;
//			}
//		}
//	}
//
//	printf("%d %d", time_min, height_max);
//}