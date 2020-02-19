#include <stdio.h>
#include <stdlib.h>

typedef int Etype;

typedef struct OLnode
{
    int i,j;					/* 行号、列号域 */
    Etype e;					/* 数据域 */
    struct OLnode *right,*down; /* 行、列向的指针域 */
}OLnode, *OLink;				/* 数据元素结点类型  */

typedef struct{
    OLink *rh,*ch;
    int mu,nu,tu;
}Crosslist;						/* 十字链表行、列表头 */

/* 函数声明 */
void creatMatrix(Crosslist *M);
void out_M(Crosslist M);

/*  主函数 */
int main()
{
    Crosslist ma;
    creatMatrix(&ma);
    out_M(ma);
    return 0;
}

void creatMatrix(Crosslist * M)
{
    int m,n,t;
    int i,j,e;
    int jud;
    OLink p,q;
    printf("输入行数、列数、非零元数:\n");
    scanf("%d%d%d", &m, &n, &t);
    M->mu=m;
    M->nu=n;
    M->tu=t;
    jud=t;
    if(!(M->rh=(OLink *)malloc((m+1)*sizeof(OLink))))
		exit(0);
    if(!(M->ch=(OLink *)malloc((n+1)*sizeof(OLink))))
		exit(0);
    for(i=0;i<=m;i++)
		M->rh[i]=NULL;
    for(i=0;i<=n;i++)
		M->ch[i]=NULL;
    for(jud=0;jud<t;jud++)
    {
        scanf("%d%d%d", &i, &j, &e);
        if(!(p=(OLnode *)malloc(sizeof(OLnode))))
			exit(0);
        p->i=i;
		p->j=j;
		p->e=e;
        if(M->rh[i]==NULL||M->rh[i]->j>j)
		{
			p->right=M->rh[i];
			M->rh[i]=p;
		}
        else
		{
            for(q=M->rh[i];(q->right)&&(q->right->j<j);q=q->right);
            p->right=q->right;
			q->right=p;
        }
        if(M->ch[j]==NULL||M->ch[j]->i>i)
		{
			p->down=M->ch[j];
			M->ch[j]=p;
		}
        else
		{
            for(q=M->ch[j];(q->down)&&q->down->i<i;q=q->down);
            p->down=q->down;
			q->down=p;
        }
    }

}
void out_M(Crosslist M)
{
     int j;
     OLink p;
     printf("mu = %d,nu = %d,tu = %d\n",M.mu,M.nu,M.tu);
	 for(j=1;j<=M.mu;j++)
	 {
		 p=M.rh[j];
		 while(p)         
		 {
			 printf("(%d,%d,%d) ",p->i,p->j,p->e);
			 p=p->right;
		 }
		 printf("\n");
	 }
}