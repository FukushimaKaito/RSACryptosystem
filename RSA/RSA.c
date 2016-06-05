#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*	関数プロトタイプ宣言	*/
//暗号化
void An(void);
//復号化
void Fuku(void);
//素数
int Prime(int);
//最小公倍数
int LCM(int, int);
//最大公約数
int GCD(int, int, int);

int main(void)
{
	printf("This program is RSA Cryptosystem\n\n");
	printf("暗号:1	復号:2	終了:0	を選択してください＞");
	while (1){
		int c = getch();
		printf("%c", c);
		if (c == '1'){
			printf("\n暗号化します．\n\n");
			An();
			printf("\n暗号:1	復号:2	終了:0	を選択してください＞");
		}
		else if (c == '2'){
			printf("\n復号化します．\n\n");
			Fuku();
			printf("\n暗号:1	復号:2	終了:0	を選択してください＞");
		}
		else if (c == '0'){
			printf("\n正常終了\n");
			return 0;
		}
		else{
			printf("\n暗号:1	復号:2	終了:0	を選択してください＞");
		}
	}
	return 0;
}

/*	暗号化	*/
void An(void)
{
	//p,q:素数,n:pq,M:平文,e:公開鍵,C:暗号文,d:秘密鍵
	int p, q, n, r, M, e, d = 0;
	double C;

	printf("STEP1:平文Mを入力＞");
	scanf_s("%d", &M);
	printf("平文M=%dとして計算します．\n", M);
	printf("STEP2:2つの素数の入力\n");
	for (int i = 0; i < 2; i++)
	{
		while (1)
		{
			printf("%dつ目の素数を入力してください．＞", i + 1);
			scanf_s("%d", &q);
			if (Prime(q) == 0){
				printf("素数であると確認しました．\n");
				break;
			}
			else if (Prime(q) == 1){
				printf("\n素数ではありません．\n");
			}
			else{
				perror("判定不能\n");
			}
		}
		if (i < 1)
		{
			p = q;
		}
	}
	printf("\n1つ目の素数p=%d\n2つ目の素数q=%d	\n", p, q);
	n = p*q;
	r = LCM(p - 1, q - 1);
	printf("公開鍵n:%d	\n", n);
	//printf("演算補助の商r(n):%d	", r);
	//eを決定
	for (e = 2; e < r; e++){
		if (GCD(e, r, 0) == 1){
			//printf("公開鍵e=%d	として計算します．\n\n", e);
			break;
		}
	}
	//dを決定
	d = GCD(r, e, 1);
	if (d < 0)
	{
		d += r;
	}
	printf("暗号化結果\n秘密鍵d:%d\n", d);
	C = fmod(pow(M, e), n);
	printf("暗号文C:%.0lf\n", C);
}
/*	復号化	*/
void Fuku(void)
{
	int C, d, n;
	double M;
	printf("STEP1:暗号文Cを入力＞");
	scanf_s("%d", &C);
	printf("暗号文C=%d	として計算します．\n", C);

	/*
		//int p, q;
		printf("STEP2:2つの素数の入力\n");
		for (int i = 0; i < 2; i++)
		{
		while (1)
		{
		printf("%dつ目の素数を入力してください．＞", i + 1);
		scanf_s("%d", &q);
		if (Prime(q) == 0){
		printf("素数であると確認しました．\n");
		break;
		}
		else if (Prime(q) == 1){
		printf("素数ではありません．\n");
		}
		else{
		perror("判定不能\n");
		}
		}
		if (i < 1)
		{
		p = q;
		}
		}
		printf("1つ目の素数p=%d\n2つ目の素数q=%d	\n", p, q);
		n = p*q;
		*/

	printf("STEP2:公開鍵nを入力してください．＞");
	scanf_s("%d", &n);
	printf("公開鍵n=%d	として計算します．\n", n);

	printf("STEP3:秘密鍵dを入力してください．＞");
	scanf_s("%d", &d);
	printf("秘密鍵d=%d	として計算します．\n", d);
	M = fmod(pow(C, d), n);
	printf("%lf\n", fmod(pow(C, d), n));
}
/*	素数	*/
int Prime(int x)
{
	for (int i = 2; i < x; ++i) {
		if (x%i == 0) {
			return 1;
		}
	}
	return 0;
}
/*	最小公倍数	*/
int LCM(int x, int y)
{
	if (x == 0 || y == 0){
		perror("引数エラー\n");
		return -1;
	}
	return (x * y / GCD(x, y, 0));
}
/*	最大公約数	*/
int GCD(int x, int y, int t)
{
	int x1 = 1, y1 = 0,
		x2 = 0, y2 = 1,
		x3, y3, z3;
	if (t == 0){//通常
		while (y > 0)
		{
			int z = x / y;
			//3
			x3 = x1 - z * x2;
			y3 = y1 - z * y2;
			z3 = x - z * y;
			//1
			x1 = x2;
			y1 = y2;
			x = y;
			//2
			x2 = x3;
			y2 = y3;
			y = z3;
		}
		return(x);
	}
	else{//d専用
		while (1)
		{
			int z = x / y;
			//3
			x3 = x1 - z * x2;
			y3 = y1 - z * y2;
			z3 = x - z * y;
			//1
			x1 = x2;
			y1 = y2;
			x = y;
			//2
			x2 = x3;
			y2 = y3;
			y = z3;
			if (y <= 1)
			{
				return(y2);
			}
		}
	}
}