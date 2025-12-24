#include<stdio.h>
#include<math.h>
int main(){
	//Bai 24
	int d1, d2, d3;
	scanf("%d %d %d", &d1, &d2, &d3);
	int kc1 = d1+d2+d3;
	int kc2 = 2*(d1+d3);
	int kc3 = 2*(d2+d3);
	int kc4 = 2*(d1+d2);
	int res = fmin(fmin(kc1,kc2), fmin(kc3,kc4));
	printf("%d", res);
	//Bai25 Doi tiên
	int n;
	scanf("%d", &n);
	int res = 0;
	res += n / 100; n %= 100;
	res += n / 20; n %= 20;
	res += n / 10; n %= 10;
	res += n / 5;  n %= 5;
	res += n;
	printf("%d", n);
	return 0;
}



