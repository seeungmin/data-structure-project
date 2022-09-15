#include <stdio.h>
#include <time.h>
#define MAX 43

int factorial(int);
int factorial_iter(int);
int fib_rec_caching(int);
int fib_iter(int);
int fib_resert[100];  // global ���� ����, global�̿��� ���� 0���� �ʱ�ȭ��
void hanoi_tower(int n, char from, char tmp, char to);

int main() {

	int result, n;
	double duration;
	clock_t start, end;
	start = clock();

	/*for (n = 0; n < MAX; n++) {
		result = fib_iter(n);
		printf("fib(%d) = %d\n",n,result);

	}*/
	hanoi_tower(10, 'A', 'B', 'C');

	end = clock();
	printf("\n");

	duration = (double)(end - start) / CLOCKS_PER_SEC;

	printf("> runing time = %lf", duration);

	return 0;
}

// from ---> to �� 1���� �̵�.
int count = 0;
void hanoi_tower(int n, char from, char tmp, char to) {
	
	if (n == 1) {
		//�� �̻� recursive ȣ���� ���� ����.
		printf("%d: %c ---> %c \n",++count, from, to);
	}
	else {
		// ���� ������ �ٽ� �ڽ� �Լ��� ȣ����. recursive.
		hanoi_tower(n - 1, from, to, tmp);
		printf("%d: %c ---> %c \n",++count, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int fib_iter(int n) {

	int result=0, p=1, pp=0;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		for (int i = 2; i <= n; i++) {
			result = p + pp;
			pp = p;
			p = result;
		}
	}
	return result;
}

//int fib_rec_caching(int n) {
//	int tem1, tem2;
//
//	if (n == 0)
//		return 0;
//	else if (n == 1)
//		return 1;
//	else {
//		// ����: �̹� ���� ����� ����
//		// ����: �� ���� ���. fib_resert �� ����
//		if (fib_resert[n - 2] == 0) {
//			tem1 = fib(n - 2);
//			fib_resert[n - 2] = tem1; // caching�صд�
//		}
//		else {
//			tem1 = fib_resert[n - 2];
//		}
//		if (fib_resert[n - 1] == 0) {
//			tem2 = fib(n - 1);
//			fib_resert[n - 1] = tem2; // caching�صд�
//		}
//		else {
//			tem2 = fib_resert[n - 1];
//		}
//		return tem1 + tem2;
//	}
//		
//
//}

//int factorial_ital(int n) {
//	int i, result = 1;
//	for (i = 1; i <= n; i++) {
//		result *= i;
//	}
//	return result;
//}

//int factorial(int n) {
//
//	if (n <= 1)	return(1);
//	else return n * factorial(n);
//
//}

