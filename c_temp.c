#include <stdio.h>
#define swap(x, y) (*x = (void *)((unsigned long int)*x ^ (unsigned long int)*y), *y = (void *)((unsigned long int)*x ^ (unsigned long int)*y), *x = (void *)((unsigned long int)*x ^ (unsigned long int)*y));
int main() {
	void *a = (int*)1, *b = (int*)2;
	printf("a = %p\tb = %p\n", a, b);
	swap(&a, &b);
	printf("a = %p\tb = %p\n", a, b);
}
