//ɸѡ1~10��8�η�֮�����������
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000000
#define N 3333333     //N=MAX/30
#define M 1666666     //M=MAX/60
//��Ϊ�ڼ���N��Mʱ������֮����������
int main(void)
{
	int k,r;
	long long i,j,m,n;
    char *a;
	int num[8]={1,7,11,13,17,19,23,29};
    a=(char*)malloc(MAX*sizeof(char)+1);
    for(i=0;i<MAX;i++) a[i]=1;

	for(k=1;k<8;k++){
		for(j=1;j<N;j++){
		    n=num[k]*(j*30+1);
            if(n<MAX) a[n]=0;
            else break;
		}
	}

	for(r=1;r<8;r++){
		for(j=0;j<N;j++){    //�����7*7��ʼ
		    for(k=1;k<8;k++){
			    n=num[r]*(j*30+num[k]);
                if(n<MAX) a[n]=0;
                else break;
		    }
        }
	}

    for(i=1;i<=M;i++){   //i<=M���ڶ�M������
		for(r=0;r<8;r++){
			for(j=i;j<N;j++){    //�����N��������
			    for(k=0;k<8;k++){
				    n=(i*30+num[r])*(j*30+num[k]);
                    if(n<MAX) a[n]=0;
                    else break;
			    }
				if(n>=MAX) break;
            }
		}
    }
    m=2;
    for(i=0;i<N;i++){
		for(k=0;k<8;k++){
			if(a[i*30+num[k]]) m++;
		}
    }
    n=N*30;
//��N������
    if(a[n+1]) m++;
    if(a[n+7]) m++;
    printf("%lu",m);
    return 0;
}
