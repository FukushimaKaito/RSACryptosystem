#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*	�֐��v���g�^�C�v�錾	*/
//�Í���
void An(void);
//������
void Fuku(void);
//�f��
int Prime(int);
//�ŏ����{��
int LCM(int, int);
//�ő����
int GCD(int, int, int);

int main(void)
{
	printf("This program is RSA Cryptosystem\n\n");
	printf("�Í�:1	����:2	�I��:0	��I�����Ă���������");
	while (1){
		int c = getch();
		printf("%c", c);
		if (c == '1'){
			printf("\n�Í������܂��D\n\n");
			An();
			printf("\n�Í�:1	����:2	�I��:0	��I�����Ă���������");
		}
		else if (c == '2'){
			printf("\n���������܂��D\n\n");
			Fuku();
			printf("\n�Í�:1	����:2	�I��:0	��I�����Ă���������");
		}
		else if (c == '0'){
			printf("\n����I��\n");
			return 0;
		}
		else{
			printf("\n�Í�:1	����:2	�I��:0	��I�����Ă���������");
		}
	}
	return 0;
}

/*	�Í���	*/
void An(void)
{
	//p,q:�f��,n:pq,M:����,e:���J��,C:�Í���,d:�閧��
	int p, q, n, r, M, e, d = 0;
	double C;

	printf("STEP1:����M����́�");
	scanf_s("%d", &M);
	printf("����M=%d�Ƃ��Čv�Z���܂��D\n", M);
	printf("STEP2:2�̑f���̓���\n");
	for (int i = 0; i < 2; i++)
	{
		while (1)
		{
			printf("%d�ڂ̑f������͂��Ă��������D��", i + 1);
			scanf_s("%d", &q);
			if (Prime(q) == 0){
				printf("�f���ł���Ɗm�F���܂����D\n");
				break;
			}
			else if (Prime(q) == 1){
				printf("\n�f���ł͂���܂���D\n");
			}
			else{
				perror("����s�\\n");
			}
		}
		if (i < 1)
		{
			p = q;
		}
	}
	printf("\n1�ڂ̑f��p=%d\n2�ڂ̑f��q=%d	\n", p, q);
	n = p*q;
	r = LCM(p - 1, q - 1);
	printf("���J��n:%d	\n", n);
	//printf("���Z�⏕�̏�r(n):%d	", r);
	//e������
	for (e = 2; e < r; e++){
		if (GCD(e, r, 0) == 1){
			//printf("���J��e=%d	�Ƃ��Čv�Z���܂��D\n\n", e);
			break;
		}
	}
	//d������
	d = GCD(r, e, 1);
	if (d < 0)
	{
		d += r;
	}
	printf("�Í�������\n�閧��d:%d\n", d);
	C = fmod(pow(M, e), n);
	printf("�Í���C:%.0lf\n", C);
}
/*	������	*/
void Fuku(void)
{
	int C, d, n;
	double M;
	printf("STEP1:�Í���C����́�");
	scanf_s("%d", &C);
	printf("�Í���C=%d	�Ƃ��Čv�Z���܂��D\n", C);

	/*
		//int p, q;
		printf("STEP2:2�̑f���̓���\n");
		for (int i = 0; i < 2; i++)
		{
		while (1)
		{
		printf("%d�ڂ̑f������͂��Ă��������D��", i + 1);
		scanf_s("%d", &q);
		if (Prime(q) == 0){
		printf("�f���ł���Ɗm�F���܂����D\n");
		break;
		}
		else if (Prime(q) == 1){
		printf("�f���ł͂���܂���D\n");
		}
		else{
		perror("����s�\\n");
		}
		}
		if (i < 1)
		{
		p = q;
		}
		}
		printf("1�ڂ̑f��p=%d\n2�ڂ̑f��q=%d	\n", p, q);
		n = p*q;
		*/

	printf("STEP2:���J��n����͂��Ă��������D��");
	scanf_s("%d", &n);
	printf("���J��n=%d	�Ƃ��Čv�Z���܂��D\n", n);

	printf("STEP3:�閧��d����͂��Ă��������D��");
	scanf_s("%d", &d);
	printf("�閧��d=%d	�Ƃ��Čv�Z���܂��D\n", d);
	M = fmod(pow(C, d), n);
	printf("%lf\n", fmod(pow(C, d), n));
}
/*	�f��	*/
int Prime(int x)
{
	for (int i = 2; i < x; ++i) {
		if (x%i == 0) {
			return 1;
		}
	}
	return 0;
}
/*	�ŏ����{��	*/
int LCM(int x, int y)
{
	if (x == 0 || y == 0){
		perror("�����G���[\n");
		return -1;
	}
	return (x * y / GCD(x, y, 0));
}
/*	�ő����	*/
int GCD(int x, int y, int t)
{
	int x1 = 1, y1 = 0,
		x2 = 0, y2 = 1,
		x3, y3, z3;
	if (t == 0){//�ʏ�
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
	else{//d��p
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