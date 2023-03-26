//#ifndef _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
///*
//01_마인크래프트_283ms
//*/
//
//#include<cstdio>
//#define rint register int
//using LL = long long;
//
//const int LM = 502;
//
//int N, M, B;
//int land[LM][LM];
//
//void check(int min, int max) {
//	int time_min = 1<<30;
//	int height_max = 0; // ans
//
//	for (rint h = min; h <= max; h++) {
//		int time = 0;
//		int inven = B;
//
//		for (rint i = 0; i < N; i++) {
//			for (rint j = 0; j < M; j++) {
//				if (land[i][j] > h) {	// land가 더 높은 경우, 골라내고(2초) 인벤토리에 블럭 추가 (+1)
//					time += 2 * (land[i][j] - h);
//					inven += (land[i][j] - h);
//				}
//				else if (land[i][j] < h) {	// land가 더 낮은 경우, 인벤토리로부터 블럭을 빼서 (-1) 쌓음 (1초)
//					time += (h - land[i][j]);
//					inven -= (h - land[i][j]);
//				}
//			}
//		}
//
//		//printf("높이: %d 일 때, time: %d, inven: %d\n", h, time, inven);
//		if (inven < 0) continue;
//
//		if (time <= time_min) {
//			time_min = time;
//			if (h > height_max) {
//				height_max = h;
//			}
//		}
//	}
//
//	printf("%d %d", time_min, height_max);
//}
//
//int main(void) {
//#ifdef _WIN32
//	freopen("01.txt", "r", stdin);
//#endif
//
//	scanf("%d %d %d", &N, &M, &B);	// (1 <= M, N <= 500, 0 <= B <= 6.4 x 10^7)
//	int min = 256, max = 0, a;
//	for (rint i = 0; i < N; i++) {
//		for (rint j = 0; j < M; j++) {
//			scanf("%d", &a);
//			land[i][j] = a;
//			if (a < min) min = a;
//			if (a > max) max = a;
//		}
//	}
//
//	// 0~256 까지의 땅 높이를 만들었을 때, 가장 시간이 적게 걸리는 경우를 구해야 함.
//	check(min, max);
//
//	return 0;
//}