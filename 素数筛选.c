//筛选1~10的8次方之间的所有素数
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000000
#define N 3333333     //N=MAX/30
#define M 1666666     //M=MAX/60
//因为在计算N和M时有误差，在之后会进行修正
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
		for(j=0;j<N;j++){    //必须从7*7开始
		    for(k=1;k<8;k++){
			    n=num[r]*(j*30+num[k]);
                if(n<MAX) a[n]=0;
                else break;
		    }
        }
	}

    for(i=1;i<=M;i++){   //i<=M属于对M的修正
		for(r=0;r<8;r++){
			for(j=i;j<N;j++){    //这里的N不用修正
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
//对N的修正
    if(a[n+1]) m++;
    if(a[n+7]) m++;
    printf("%lu",m);
    return 0;
}
