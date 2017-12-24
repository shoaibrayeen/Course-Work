#include <stdio.h>
int fibonaci(int i) {
	if(i == 0) {
		return 0;
	}
	if(i == 1) {
		return 1;
	}
	return fibonaci(i-1) + fibonaci(i-2);
}
int main() {
	int i;
	for (i = 0; i < 20 ; i++) {
		printf("%d\t", fibonaci(i));
	}
	return 0;
}
