//#ifndef _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
///*
//01_����ũ����Ʈ_�ð� ���������� 50��.. ���� �𸣰���.
//*/
//
//#include<cstdio>
//#define rint register int
//
//const int LM = 502;
//
//int N, M, B;
//int time[257] = { 0 };	// Ư�� ���̸� �ױ� ���� �ʿ��� �ð�
//int block[257] = { 0 };	// Ư�� ���̸� �ױ� ���� �ʿ��� ��
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
//				if (unit_height < k) {	// ��ǥ�� �ϴ� ���̺��� ������ �� �׾ƾ� ��.
//					diff = (k - unit_height);
//					time[k] += diff;
//					block[k] -= diff;
//				}
//				else if (unit_height > k) {	// ��ǥ�� �ϴ� ���̺��� ������ �� ���� ��
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