#define _CRT_SECURE_NO_WARNINGS



//1：例子：printN()
//#include<iostream>
//#include<windows.h>
//using namespace std;
//void PrintN_1(int n)//循环实现
//{
//	for (int i = 1; i <= n; i++)
//	{
//		cout << i << " ";
//	}
//}
//void PrintN_2(int n)//递归实现
//{
//	if (n)
//	{
//		PrintN_2(n - 1);
//		cout << n << " ";
//	}
//}
//int main()
//{
//	int N;
//    cin >> N;//取100000
//	DWORD start_time = GetTickCount();
//	{
//		
//		PrintN_1(N);  //安全运行；
//		PrintN_2(N); //出现问题，没有正常执行！
//		cout << endl;
//	}
//	DWORD end_time = GetTickCount();
//	cout << "The run time is:" << (end_time - start_time) * 1.00 / 1000 << "s!" << endl;//输出运行时间
//	return 0;
//}



 //利用数组的连续存储空间存放线性表的各元素(顺序结构存储)：
//#include<stdio.h>
//#include<malloc.h>
//#define MAXSIZE 100
//typedef double ElementType;
//typedef struct LNode* List;
//struct LNode
//{
//	ElementType Data[MAXSIZE];
//	int Last;//最后一个元素的标号
//};
////具体操作的实现如下：
//List MakeEmpty()//初始化（建立空的顺序表）
//{
//	List Ptrl;
//	Ptrl = (List)malloc(sizeof(LNode));
//	Ptrl->Last = -1;
//	return Ptrl;
//}
//int Find(ElementType X, List Ptrl)//查找
//{
//	int i=0;
//	while (i <= Ptrl->Last && Ptrl->Data[i] != X)
//		i++;
//	if (i > Ptrl->Last) return -1;//没找到
//	else return i;//找到了，返回存储位置
//}
//void Insert(ElementType X,List Ptrl,int i)//插入（插到第i个元素的前面）
//{
//	if (Ptrl->Last + 1 == MAXSIZE)
//	{
//		printf("表满\n");
//		return;
//	}
//	else if (i - 1 < 0 || i - 1 > Ptrl->Last + 1)
//	{
//		printf("位置不合适\n");
//		return;
//	}
//	else
//	{
//		int j;
//		for (j = Ptrl->Last; j >= i; j--)
//			Ptrl->Data[j + 1] = Ptrl->Data[j];
//		Ptrl->Data[i - 1] = X;
//		Ptrl->Last++;
//		return;
//	}
//}
//void Delete(int i, List Ptrl)//删除（删除第i个元素的前一个元素）
//{
//	if (i - 1 < 0 || i - 1 > Ptrl->Last)
//	{
//		printf("不存在该元素\n");
//		return;
//	}
//	else
//	{
//		int j;
//		for (j = i; j <= Ptrl->Last; j++)
//			Ptrl->Data[j - 1] = Ptrl->Data[j];
//		Ptrl->Last--;
//		return;
//	}
//}
//ElementType FindKth(int K, List Ptrl)//根据位序K，返回相应元素
//{
//	return Ptrl->Data[K];
//}
//int Length(List Ptrl)//返回线性表的长度
//{
//	return Ptrl->Last + 1;
//}
//int main()
//{
//	 
//	return 0;
//}



//链式存储实现线性表（不要求逻辑上相邻的两个元素物理上也相邻）：
//#include<stdio.h>
//#include<malloc.h>
//typedef int ElementType;
//typedef struct LNode* List;
//struct LNode
//{
//	ElementType Data;
//	List Next;
//};
//List MakeEmpty()
//{
//	return NULL;
//}
//int Length(List Ptrl)
//{
//	List p = Ptrl;//p指向表的第一个结点
//	int j = 0;
//	while (p)
//	{
//		p = p->Next;
//		j++;        //p指向表的第j个结点
//	}
//	return j;
//}
//List FindKth(int K, List Ptrl)//按序号查找
//{
//	List p=Ptrl;
//	int i = 1;
//	while (p != NULL && i < K)
//	{
//		p = p->Next;
//		i++;
//	}
//	if (i == K) return p;
//	else return NULL;
//}
//List Find(ElementType X, List Ptrl)//按值查找
//{
//	List p = Ptrl;
//	while (p != NULL && p->Data != X)
//		p = p->Next;
//	return p;
//}
//List Insert(ElementType X,int i,List Ptrl)//在第i-1个元素后加一个值为X的元素,注意：空表也可以添加！
//{
//	if (i == 1)
//	{
//		List s;
//		s = (List)malloc(sizeof(LNode));
//		s->Data = X;
//		s->Next = Ptrl;
//		return s;
//	}
//	else//第i-1个元素至少要存在！
//	{
//		List p = FindKth(i - 1,Ptrl);
//		if (p == NULL)
//		{
//			printf("参数i错误\n");
//			return NULL;//异常情况return NULL
//		}
//		else
//		{
//			List s;
//			s = (List)malloc(sizeof(LNode));
//			s->Data = X;
//			s->Next = p->Next;
//			p->Next = s;
//			return Ptrl;
//		}
//	}
//}
//List Delete(int i, List Ptrl)//删除第i个结点，注意：要考虑到空表的情况！
//{
//	if (i == 1)
//	{
//		List s = Ptrl;
//		if (s == NULL)
//		{
//			printf("空表\n");
//			return NULL;
//		}
//		else
//		{
//			Ptrl = Ptrl->Next;
//			free(s);
//			return Ptrl;
//		}
//	}
//	else//要求第i和第i-1个元素都要存在！
//	{
//		List p = FindKth(i-1, Ptrl);
//		if (p == NULL)
//		{
//			printf("第%d个元素不存在\n", i - 1);
//			return NULL;
//		}
//		if (p->Next == NULL)
//		{
//			printf("第%d个结点不存在\n",i);
//			return NULL;
//		}
//		else
//		{
//			List s = p->Next;
//			p->Next = s->Next;
//			free(s);
//			return Ptrl;
//		}
//	}
//}
//
//void ShowList(List head)
//{
//	List p = head;
//	for (p = head; p; p = p->Next)
//		printf("%d ", p->Data);
//	printf("\n");
//}
//
///*链表的逆转算法*/
//List Reverse(List head, int K)//从头开始K个结点逆转
//{
//	int cnt = 1;//计数器
//	List New, Old, Tmp;
//	New = head;
//	Old = head->Next;
//	Tmp = Old;
//	while (cnt < K)
//	{
//		Tmp = Old->Next;
//		Old->Next = New;
//		New = Old;
//		Old = Tmp;
//		cnt++;//操作执行K-1次
//	}
//	head->Next = Tmp;
//	return New;
//}
//
//int main()
//{
//	List l = NULL;
//	int option;
//	int n;
//	int temp;
//	while (1)
//	{
//		int flag = 0;
//		printf("请输入操作选项（1，增加(尾部添加)；2，删除；3，逆转；4，输出；5，退出）：\n");
//		scanf("%d", &option);
//		switch (option)
//		{
//		case 1:
//			printf("请输入要增加的结点的个数：\n");
//			scanf("%d", &n);
//			printf("请输入要增加的结点的值：\n");
//			for (int i = 0; i < n; i++)
//			{
//				scanf("%d", &temp);
//				l=Insert(temp, Length(l) + 1, l);//尾添加
//			}
//			break;
//		case 2:
//			printf("请输入要删除元素的序号：\n");
//			scanf("%d", &n);
//			l=Delete(n, l);
//			break;
//		case 3:
//			printf("请输入要逆转的结点的个数：\n");
//			scanf("%d", &n);
//			l=Reverse(l, n);
//			break;
//		case 4:
//			ShowList(l);
//			break;
//		case 5:
//			flag = 1;
//			break;
//		default:
//			printf("操作不存在\n");
//		}
//		if (flag) 
//		{
//			printf("退出\n");
//			break;
//		}
//	}
//	return 0;
//}

//顺序存储实现堆栈例：使用一个数组实现两个堆栈，要求最大地利用数组的空间
//#include<stdio.h>
//#define MAXSIZE 100
//typedef char ElementType;
//struct DStack
//{
//	ElementType Data[MAXSIZE];
//	int Top1;
//	int Top2;
//};
//DStack CreateDStack()
//{
//	DStack  S;
//	 S.Top1 = -1;
//	 S.Top2 = MAXSIZE;
//	return  S;
//}
//bool IsFull(DStack& S)
//{
//	return (S.Top2 - S.Top1 == 1);
//}
//bool IsEmpty_1(DStack& S)
//{
//	return (S.Top1 == -1);
//}
//bool IsEmpty_2(DStack& S)
//{
//	return (S.Top2 == MAXSIZE);
//}
//void Push(DStack& S, ElementType item, int Tag)//入栈
//{
//	if (IsFull(S))
//	{
//		printf("栈已满\n");
//		return;
//	}
//	else
//	{
//		if (Tag == 1)
//		{
//			S.Data[++(S.Top1)] = item;
//			return;
//		}
//		else
//		{
//			S.Data[--(S.Top2)] = item;
//			return;
//		}
//	}
//}
//ElementType Pop(DStack& S, int Tag)//出栈(有返回)
//{
//	if (Tag == 1)
//	{
//		if (IsEmpty_1(S))
//		{
//			printf("栈1已空\n");
//			return NULL;
//		}
//		else
//		{
//			ElementType s;
//			s = S.Data[S.Top1--];
//			return s;
//		}
//	}
//	else
//	{
//		if (IsEmpty_2(S))
//		{
//			printf("栈2已空\n");
//			return NULL;
//		}
//		else
//		{
//			ElementType s;
//			s = S.Data[S.Top2++];
//			return s;
//		}
//	}
//}
//int main()
//{
//
//	return 0;
//}



//链式存储实现堆栈
//#include<stdio.h>
//#include<malloc.h>
//typedef char ElementType;
//typedef struct SNode* Stack;//因为此时还未定义SNode,故要加上struct声明
//struct SNode
//{
//	ElementType Element;
//	SNode* Next;
//};
//Stack CreateStack()//堆栈初始化（建立空栈）
//{
//	Stack S;
//	S = (Stack)malloc(sizeof(SNode));
//	S->Next = NULL;
//	return S;
//}
//int IsEmpty(Stack S)//判断堆栈是否为空
//{
//	return (S->Next == NULL);
//}
//void Push(ElementType item, Stack S)//入栈
//{
//	SNode* TmpCell;
//	TmpCell = (SNode*)malloc(sizeof(SNode));
//	TmpCell->Element = item;
//	TmpCell->Next = S->Next;
//	S->Next = TmpCell;
//}
//ElementType Pop(Stack S)//出栈
//{
//	if (IsEmpty(S))
//	{
//		printf("堆栈空\n");
//		return NULL;
//	}
//	else
//	{
//		SNode* FirstCell;
//		ElementType TopElem;
//		FirstCell = S->Next;
//		TopElem = FirstCell->Element;
//		S->Next = FirstCell->Next;
//		free(FirstCell);
//		return TopElem;
//	}
//}
//int main()
//{
//
//	return 0;
//}



//利用链式堆栈实现支持'+','-','*','/','(',')',个位数的中缀表达式转后缀表达式
//



//顺序结构实现队列（顺环）
//#include<stdio.h>
//#include<malloc.h>
//#define MAXSIZE 4
//typedef char ElementType;
//typedef struct QNode* Queue;
//struct QNode
//{
//	ElementType Data[MAXSIZE];
//	int front;
//	int rear;
//};
//Queue CreateQueue()//创建队列
//{
//	Queue Q;
//	Q = (Queue)malloc(sizeof(QNode));
//	(Q->front )= (Q->rear) = 0;
//	return Q;
//}
//void AddQueue(Queue PtrQ, ElementType item)//入队
//{
//	if ((PtrQ->rear + 1) % MAXSIZE== PtrQ->front)
//	{
//		printf("队列满\n");
//		return;
//	}
//	else
//	{
//		PtrQ->rear = (PtrQ->rear+1) % MAXSIZE;
//		PtrQ->Data[PtrQ->rear] = item;
//		return;
//	}
//}
//ElementType DeleteQueue(Queue PtrQ)//出队
//{
//	if (PtrQ->rear == PtrQ->front)
//	{
//		printf("队列空\n");
//		return NULL;
//	}
//	else
//	{
//		PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
//		return PtrQ->Data[PtrQ->front];
//	}
//}
//int main()
//{
//	Queue Q = CreateQueue();
//	AddQueue(Q, 'a');
//    AddQueue(Q, 'b');
//	AddQueue(Q, 'c');
//	AddQueue(Q, 'd');
//	printf("%c", DeleteQueue(Q));
//	printf("%c", DeleteQueue(Q));
//	printf("%c", DeleteQueue(Q));
//	return 0;
//}



//链式存储结构实现队列
//#include<stdio.h>
//#include<malloc.h>
//typedef char ElementType;
//typedef struct QNode* Queue;
//struct Node
//{
//	ElementType Data;
//	Node* Next;
//};
//struct QNode
//{
//	Node* rear;
//	Node* front;
//};
//Queue CreateQueue()//创建队列
//{
//	Queue Q;
//	Q = (Queue)malloc(sizeof(QNode));
//	Q->front = Q->rear = NULL;
//	return Q;
//}
//void AddQueue(Queue PtrQ, ElementType item)//入队
//{
//	if (PtrQ->front == NULL)
//	{
//		PtrQ->front = PtrQ->rear = (Node*)malloc(sizeof(Node));
//		PtrQ->rear->Data = item;
//		PtrQ->rear->Next = NULL;
//	}
//	else
//	{
//		PtrQ->rear->Next = (Node*)malloc(sizeof(Node));
//		PtrQ->rear->Next->Data = item;
//		PtrQ->rear->Next->Next = NULL;
//		PtrQ->rear = PtrQ->rear->Next;  
//	}
//}
//ElementType DeleteQueue(Queue PtrQ)//出队
//{
//	ElementType FrontElem;
//	Node* FrontCell;
//	if (PtrQ->front == NULL)
//	{
//		printf("队列空\n");
//		return NULL;
//	}
//	else
//	{
//		Node* TopPtr = PtrQ->front;                                     
//		ElementType TopCell = TopPtr->Data;
//		PtrQ->front = PtrQ->front->Next;
//		free(TopPtr);
//		return TopCell;
//	}
//}
//int main()
//{
//	Queue Q = CreateQueue();
//	AddQueue(Q, 'a');
//	printf("%c ", DeleteQueue(Q));
//	AddQueue(Q, 'b');
//	printf("%c ", DeleteQueue(Q));
//	return 0;
//}



//链式存储实现多项式的加法和乘法
//#include<stdio.h>
//#include<malloc.h>
//typedef struct PolyNode* Polynomial;
//struct PolyNode
//{
//	int coef;//系数
//	int expon;//指数
//	PolyNode* link;//指向下一个节点的指针
//};
//void Attach(int c, int e, Polynomial* pRear)//添加结点需要对尾指针进行修改，但c里面没有引用！所以传尾指针的地址
//{
//	Polynomial p = (Polynomial)malloc(sizeof(PolyNode));
//	p->coef = c;
//	p->expon = e;
//	p->link = NULL;
//	(*pRear)->link = p;
//	(*pRear) = p;
//}
//int Compare(int x, int y)
//{
//	if (x > y)return 1;
//	else if (x < y)return -1;
//	else return 0;
//}
//int abs(int x)
//{
//	return x > 0 ? x : -x;
//}
//Polynomial PolyAdd(Polynomial P1, Polynomial P2)
//{
//	Polynomial front, temp, rear;
//	int sum;
//	rear = (Polynomial)malloc(sizeof(PolyNode));
//	front = rear;//记录头结点
//	while(P1&&P2)
//	{
//		switch (Compare(P1->expon, P2->expon))
//		{
//		case 1:
//			Attach(P1->coef, P1->expon, &rear);
//			P1 = P1->link;
//			break;
//		case -1:
//			Attach(P2->coef, P2->expon, &rear);
//			P2 = P2->link;
//			break;
//		case 0:
//			sum = P1->coef + P2->coef;
//			if(sum)
//				Attach(sum, P2->expon, &rear);
//			P1 = P1->link;
//			P2 = P2->link;
//			break;
//		}
//	}
//	//将未处理的余项复制
//	for (; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
//	for (; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
//	//尾结点link改成NULL，便于遍历
//	rear->link = NULL;
//	//删除空临时结点
//	temp = front;
//	front = front->link;
//	free(temp);
//	return front;
//}
// //方法一：构造初始多项式，再逐项插入，关键是插入的位置
//Polynomial Mult(Polynomial P1, Polynomial P2)
//{
//	Polynomial P, Rear, t1, t2, temp;
//	int c, e;
//	//判断两个多项式是否为空：
//	if (!P1 || !P2) return NULL;
//	//构建初始多项式：
//	t1 = P1, t2 = P2;
//	Rear = (Polynomial)malloc(sizeof(PolyNode));
//	P = Rear;
//	for (; t2; t2 = t2->link)
//		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
//	//逐项插入：
//	t1 = t1->link;
//	for (; t1; t1 = t1->link)
//	{
//		for (t2 = P2; t2; t2 = t2->link)
//		{
//			c = t1->coef * t2->coef;
//			e = t1->expon + t2->expon;
//			Rear = P;
//			while (Rear->link && Rear->link->expon > e)
//				Rear = Rear->link;
//			if (Rear->link && Rear->link->expon == e)
//			{
//				if (Rear->link->coef + c)
//					Rear->link->coef += c;
//				else
//				{
//					temp = Rear->link;
//					Rear->link = temp->link;
//					free(temp);
//				}
//			}
//			else
//			{
//				temp = (Polynomial)malloc(sizeof(PolyNode));
//				temp->coef = c;
//				temp->expon = e;
//				temp->link = Rear->link;
//				Rear->link = temp;
//				Rear = Rear->link;
//			}
//		}
//	}
//	//删除空结点，返回头指针：(对链表操作之后再删除空结点）
//	temp = P;
//	P = P->link;
//	free(temp);
//	return P;
//}

//方法二：
//多项式1的某项乘多项式2得到的多项式
//Polynomial PartMult(Polynomial Ptr, PolyNode* p)
//{
//	Polynomial front, rear, temp;
//	rear = (Polynomial)malloc(sizeof(PolyNode));
//	front = rear;
//	for (; Ptr; Ptr = Ptr->link)
//		Attach(p->coef * Ptr->coef, p->expon + Ptr->expon, &rear);
//	temp = front;
//	front = front->link;
//	free(temp);
//	return front;
//}
//Polynomial Mult(Polynomial P1, Polynomial P2)//乘法转化为加法
//{
//	Polynomial t1 = P1, t2 = P2;
//	Polynomial Mult = NULL;
//	for (; t1; t1 = t1->link)
//		Mult = PolyAdd(Mult, PartMult(t2, t1));
//	return Mult;
//}
//void ShowPoly(Polynomial p)
//{
//	for (; p; p = p->link)
//	{
//		if(p->expon==0)
//			printf("%d", abs(p->coef));
//		else
//		    printf("%d*x^%d", abs(p->coef), p->expon);
//		if (p->link)
//		{
//			if ((p->link)->coef > 0) printf(" + ");
//			else printf(" - ");
//		}
//	}
//	printf("\n");
//}
//Polynomial InputPoly()
//{
//	Polynomial front, rear, temp;
//	int c, e, flag;
//	rear = (Polynomial)malloc(sizeof(PolyNode));
//	front = rear;
//	printf("下面开始高次到低次逐项输入多项式：\n");
//	while (1)
//	{
//		printf("是否继续添加? (1/0\n");
//		scanf("%d", &flag);
//		switch (flag)
//		{
//		case 1:
//			printf("请输入系数和次数：\n");
//			scanf("%d", &c);
//			scanf("%d", &e);
//			Attach(c, e, &rear);
//			break;
//		case 0:
//			printf("输入结束！\n");
//			break;
//		}
//		if (!flag) break;
//	}
//	rear->link = NULL;
//	temp = front;
//	front = front->link;
//	free(temp);
//	return front;
//}
//int main()
//{
//	Polynomial P1 = InputPoly();
//	printf("P1:");
//	ShowPoly(P1);
//	Polynomial P2 = InputPoly();
//	printf("P2:");
//	ShowPoly(P2);
//	Polynomial PMult = Mult(P1, P2);
//	printf("P1*P2:");
//	ShowPoly(PMult);
//	printf("\n");
//	Polynomial PAdd = PolyAdd(P1, P2);
//	printf("P1+P2:");
//	ShowPoly(PAdd);
//	return 0;
//}



//链表存储实现二叉树：
//#include<stdio.h>
//#include<malloc.h>
//typedef char ElementType;
//typedef struct TreeNode* BinTree;
//typedef BinTree Position;
//struct TreeNode
//{
//	ElementType Data;
//	BinTree Left;
//	BinTree Right;
//	int tag;
//};
//
////堆栈：
//typedef BinTree ElementType_;
//typedef struct SNode* Stack;//因为此时还未定义SNode,故要加上struct声明
//struct SNode
//{
//	ElementType_ Element;
//	SNode* Next;
//};
//Stack CreateStack()//堆栈初始化（建立空栈）
//{
//	Stack S;
//	S = (Stack)malloc(sizeof(SNode));
//	S->Next = NULL;
//	return S;
//}
//int IsEmpty(Stack S)//判断堆栈是否为空
//{
//	return (S->Next == NULL);
//}
//void Push(ElementType_ item, Stack S)//入栈
//{
//	SNode* TmpCell;
//	TmpCell = (SNode*)malloc(sizeof(SNode));
//	TmpCell->Element = item;
//	TmpCell->Next = S->Next;
//	S->Next = TmpCell;
//}
//ElementType_ Pop(Stack S)//出栈
//{
//	if (IsEmpty(S))
//	{
//		printf("堆栈空\n");
//		return NULL;
//	}
//	else
//	{
//		SNode* FirstCell;
//		ElementType_ TopElem;
//		FirstCell = S->Next;
//		TopElem = FirstCell->Element;
//		S->Next = FirstCell->Next;
//		free(FirstCell);
//		return TopElem;
//	}
//}
////<--------------------------------------------------->
////队列：
//typedef struct QNode* Queue;
//struct Node
//{
//	ElementType_ Data;
//	Node* Next;
//};
//struct QNode
//{
//	Node* rear;
//	Node* front;
//};
//bool IsEmpty(Queue Q)
//{
//	return (Q->front == NULL);
//}
//Queue CreateQueue()//创建队列
//{
//	Queue Q;
//	Q = (Queue)malloc(sizeof(QNode));
//	Q->front = Q->rear = NULL;
//	return Q;
//}
// void AddQueue(Queue PtrQ, ElementType_ item)//入队
//{
//	if (PtrQ->front == NULL)
//	{
//		PtrQ->front = PtrQ->rear = (Node*)malloc(sizeof(Node));
//		PtrQ->rear->Data = item;
//		PtrQ->rear->Next = NULL;
//	}
//	else
//	{
//		PtrQ->rear->Next = (Node*)malloc(sizeof(Node));
//		PtrQ->rear->Next->Data = item;
//		PtrQ->rear->Next->Next = NULL;
//		PtrQ->rear = PtrQ->rear->Next;
//	}
//}
//ElementType_ DeleteQueue(Queue PtrQ)//出队
//{
//	if (PtrQ->front == NULL)
//	{
//		printf("队列空\n");
//		return NULL;
//	}
//	else
//	{
//		Node* TopPtr = PtrQ->front;
//		ElementType_ TopCell = TopPtr->Data;
//		PtrQ->front = PtrQ->front->Next;
//		free(TopPtr);
//		return TopCell;
//	}
//}
//
////or(顺环):
//
////#define MAXSIZE 10//队列容量实际只有9
////typedef struct QNode* Queue;
////struct QNode
////{
////	ElementType_ Data[MAXSIZE];
////	int front;
////	int rear;
////};
////int IsEmpty(Queue Q)
////{
////	return(Q->front == Q->rear);
////}
////Queue CreateQueue()//创建队列
////{
////	Queue Q;
////	Q = (Queue)malloc(sizeof(QNode));
////	(Q->front) = (Q->rear) = 0;
////	return Q;
////}
////void AddQueue(Queue PtrQ, ElementType_ item)//入队
////{
////	if ((PtrQ->rear + 1) % MAXSIZE  == PtrQ->front)
////	{
////		printf("队列满\n");
////		return;
////	}
////	else
////	{
////		PtrQ->rear = (PtrQ->rear + 1) % MAXSIZE;
////		PtrQ->Data[PtrQ->rear] = item;
////		return;
////	}
////}
////ElementType_ DeleteQueue(Queue PtrQ)//出队
////{
////	if (PtrQ->rear == PtrQ->front)
////	{
////		printf("队列空\n");
////		return NULL;
////	}
////	else
////	{
////		PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
////		return PtrQ->Data[PtrQ->front];
////	}
////}
//
////<-------------------------------------------------------------------------->      
//
////**二叉搜索树特有操作：
//// 查找：
//Position Find(ElementType X, BinTree BST)//查找特定元素X
//{
//	if (!BST) return NULL;//没找到
//	if (X > BST->Data) return Find(X, BST->Right);//查找右子树即可
//	else if (X < BST->Data) return Find(X, BST->Left);//查找左子树即可
//	else return BST;//找到了
//}
//Position FindMin(BinTree BST)//查找最小元素（即查找最左叶结点）(尾递归实现）
//{
//	if (!BST) return NULL;
//	else if (!(BST->Left)) return BST;
//	else return FindMin(BST->Left);
//}
//Position FindMax(BinTree BST)//查找最大元素（即查找最右叶结点）（迭代实现）
//{
//	if(BST)
//	     while (!(BST->Right)) BST = BST->Right;
//	return BST;
//}
////***尾递归可以改成迭代函数非递归实现功能***
//// 插入：
//BinTree Insert(ElementType X, BinTree BST)
//{
//	if (!BST)
//	{
//		BST = (BinTree)malloc(sizeof(TreeNode));
//		BST->Data = X;
//		BST->tag = 0;
//		BST->Left = NULL;
//		BST->Right = NULL;
//	}
//	else
//		if (X < BST->Data)
//			BST->Left = Insert(X, BST->Left);//递归插入左子树
//		else if (X > BST->Data)
//			BST->Right = Insert(X, BST->Right);//递归插入右子树
//	    /*else X已存在，无需操作*/
//	return BST;
//}
//
//// 删除：
///*只有左子树或右子树或都没有的结点的删除仿照链表进行操作，将左右子树都有的情况进行转化*/
//BinTree Delete(ElementType X, BinTree BST)
//{
//	Position Tmp;
//	if (!BST) printf("要删除的元素没找到\n");
//	else if (X < BST->Data) BST->Left = Delete(X, BST->Left);
//	else if (X > BST->Data) BST->Right = Delete(X, BST->Right);
//	else 
//	{
//		if (BST->Left && BST->Right)
//		{
//			Tmp = FindMin(BST->Right);
//			BST->Data = Tmp->Data;
//			BST->Right = Delete(BST->Data, BST->Right);
//		}
//		else/*0个或1个子结点*/
//		{
//			Tmp = BST;
//			if (!BST->Right) BST = BST->Right;
//			else if (!BST->Left) BST = BST->Left;
//			else BST = NULL;
//			free(Tmp);
//		}
//	}
//	return BST;
//}
////<------------------------------------------------------------------------------------------>
//
////递归实现二叉树遍历：
////void PreOrderTraversal(BinTree BT)//先序遍历（根->左->右）
////{
////	if (BT)
////	{
////		printf("%c ", BT->Data);
////		PreOrderTraversal(BT->Left);
////		PreOrderTraversal(BT->Right);
////	}
////}
////void InOrderTraversal(BinTree BT)//中序遍历（左->根->右）
////{
////	if (BT)
////	{
////		InOrderTraversal(BT->Left);
////		printf("%c ", BT->Data);
////		InOrderTraversal(BT->Right);
////	}
////}
////void PostOrderTraversal(BinTree BT)//后序遍历（左->右->根）
////{
////	if (BT)
////	{
////		PostOrderTraversal(BT->Left);
////		PostOrderTraversal(BT->Right);
////		printf("%c ", BT->Data);
////	}                                                             
////}
//
////利用堆栈非递归实现二叉树的遍历：
//void InOrderTraversal(BinTree BT)//中序遍历（左->根->右）
//{
//	BinTree T = BT;
//	Stack S = CreateStack();
//	while (T || !IsEmpty(S))
//	{
//		while (T)
//		{
//			Push(T, S);
//			T = T->Left;
//		}
//		if (!IsEmpty(S))
//		{
//			T = Pop(S);
//			printf("%c ", T->Data);//访问一次出栈的结点
//			T = T->Right;
//		}
//	}
//}
//void PreOrderTraversal(BinTree BT)//先序遍历（根->左->右）
//{
//	BinTree T = BT;
//	Stack S = CreateStack();
//	while (T || !IsEmpty(S))
//	{
//		
//		while (T)
//		{
//			printf("%c ", T->Data); //遇到结点就访问
//			Push(T, S);
//			T = T->Left;
//		}
//		if (!IsEmpty(S))
//		{
//			T = Pop(S);
//			T = T->Right;
//		}
//	}
//
//}
//void PostOrderTraversal(BinTree BT)//后序遍历（左->右->根）
//{
//	BinTree T = BT;
//	Stack S = CreateStack();
//	while (T || !IsEmpty(S))
//	{
//		while (T)
//		{
//			T->tag = 0;
//			Push(T, S);
//			T = T->Left;
//		}
//		if (!IsEmpty(S))
//		{
//			T = Pop(S);
//			if (T->tag)
//			{
//				printf("%c ", T->Data);//访问二次出栈的结点
//				T =NULL;
//			}
//			else
//			{
//				 
//				T->tag = 1;
//				BinTree temp = T;
//			    T = temp->Right;
//				Push(temp, S);//再入栈
//			}
//		}
//	}
//	 
//}
////层序遍历（队列实现）：
//void LevelOrderTraversal(BinTree BT)
//{
//	Queue Q;
//	BinTree T;
//	if (!BT) return;
//	Q = CreateQueue();
//	AddQueue(Q, BT);//根结点入队
//	while (!IsEmpty(Q))
//	{
//		T = DeleteQueue(Q);
//		printf("%c ", T->Data);//访问出队的结点
//		if (T->Left) AddQueue(Q, T->Left);
//		if (T->Right) AddQueue(Q, T->Right);
//	}
//}

///*test*/
////int main()
////{
////	BinTree BST=NULL;
////	char option;
////	bool flag = 0;
////	while (1)
////	{
////		printf("请输入操作选项(a:add, d:delete, o:output, p:pause)：\n");
////		scanf("%c", &option);
////		getchar();
////		switch (option)
////		{
////		case 'a':
////			printf("请输入要添加的元素：\n");
////			char a;
////			scanf("%c", &a);
////			getchar();
////			BST=Insert(a, BST);
////			break;
////		case 'd':
////			printf("请输入要删除的元素：\n");
////			char d;
////			scanf("%c", &d);
////			getchar();
////			BST=Delete(d, BST);
////			break;
////		case 'o':
////			PreOrderTraversal(BST);
////			printf("\n");
////			break;
////		case 'p':
////			printf("操作结束，退出\n");
////			flag = 1;
////			break;
////		default:
////			printf("操作不存在！\n");
////		}
////		if (flag) break;
////	}
////	return 0;
////}

///*判断不同序列建立的二叉树是否相同*/
//int check(BinTree T, char v)
//{
//	if (T->tag)
//	{
//		if (v > T->Data) return (check(T->Right, v));
//		if (v < T->Data) return (check(T->Left, v));
//		else return 1;
//	}
//	else
//	{
//		if (v == T->Data)//根结点
//		{
//			T->tag = 1;
//			return 1;
//		}
//		else return 0;//路过没标记的结点，不一致
//	}
//}
//void Reset(BinTree T)
//{
//	if (T->Left) Reset(T->Left);
//	if (T->Right) Reset(T->Right);
//	T->tag = 0;
//}
//void FreeTree(BinTree T)
//{
//	if (T->Left) FreeTree(T->Left);
//	if (T->Right) FreeTree(T->Right);
//	free(T);//注意，free()函数不会改变指针的值，会产生“野指针”，需要手动将指针改成NULL！否则if判断会出现bug
//}
//int main()
//{
//	int N, L;
//	char V;
//	BinTree T=NULL;
//	while (1)
//	{
//		printf("请输入二叉树的结点个数：\n");
//		scanf("%d", &N);
//		if (!N)
//		{ 
//			printf("退出\n");
//			break; 
//		}
//		else
//		{
//			printf("请输入有几组需要判断的序列：\n");
//			scanf("%d", &L);
//			printf("请输入建树序列：\n");
//			for (int i = 0; i < N; i++)
//			{
//				getchar();
//				scanf("%c", &V);
//				T = Insert(V, T);//同时将结点的tag值设成0
//			}
//			for (int i = 0; i < L; i++)
//			{
//				int flag = 0;/*0表示目前还一致，1表示不一致*/
//				printf("请输入要比较的序列：\n");
//					for (int i = 0; i < N; i++)
//					{
//						getchar();
//						scanf("%c", &V);
//						if ((!flag) && (!check(T, V))) flag= 1;
//					}
//					if (flag) printf("No\n");
//					else printf("Yes\n");
//					Reset(T);
//			}
//		}
//		FreeTree(T);
//		T = NULL;
//	}
//	return 0;
//}



//判断两二叉树同构（静态链表实现）：
//#include<stdio.h>
//#define MaxTree 10
//#define ElementType char
//#define Tree int
//#define Null -1
//
//struct TreeNode
//{
//	ElementType Element;
//	Tree Right;
//	Tree Left;
//};
//TreeNode T1[MaxTree];
//TreeNode T2[MaxTree];
//Tree BuildTree(TreeNode T[])
//{
//	Tree i, N,Root=Null;
//	char cl, cr;
//	bool check[MaxTree];
//	printf("Please input the number of nodes:\n");
//	scanf("%d", &N);
//	if (N)
//	{
//		 
//		for (i = 0; i < N; i++) check[i] = 0;
//		for (i = 0; i < N; i++)
//		{
//			getchar();//***吞掉回车符！***
//			printf("Please input the information of the node:\n");
//			scanf("%c %c %c", &(T[i].Element),&cl,&cr);//***%c输入时，缓冲区遇到的一切都会被看成字符！包括空格，Tab，回车***
//			if (cl != '-')
//			{
//				T[i].Left = cl - '0';
//				check[T[i].Left] = 1;
//			}
//			else T[i].Left = Null;
//			if (cr != '-')
//			{
//				T[i].Right = cr - '0';
//				check[T[i].Right] = 1;
//			}
//			else T[i].Right = Null;
//		}
//		for (i = 0; i < N; i++)//没有被指向的结点就是根节点！
//			if (!check[i]) break;
//		Root = i;
//	}
//	return Root;
//}
//bool Isomorphic(Tree R1, Tree R2)//递归实现，对每一个结点进行操作，因此关键在于涵盖所有的情况！
//{
//	//基本情况:单看根就能出结果（递归终止）
//	if ((R1 == Null) && (R2 == Null))
//		return 1;//两个空树认为是同构
//	if (((R1 != Null) && (R2 == Null)) || ((R1 == Null) && (R2 != Null)))
//		return 0;//其中一个是空树
//	if (T1[R1].Element != T2[R2].Element)
//		return 0;//根不相同
//	//单看根不能出结果，就左子树进行讨论：
//	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
//		return Isomorphic(T1[R1].Right, T2[R2].Right);//都没左子树，就看右子树
//	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
//		return Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right);//不需要交换左右子树
//	else return Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left);//需要交换左右子树
//}
//int main()
//{
//	Tree R1, R2;
//	printf("The first binary tree inputting.....\n");
//	R1 = BuildTree(T1);
//	printf("The second binary tree inputting.....\n");
//	R2 = BuildTree(T2);
//	if (Isomorphic(R1, R2)) printf("Yes\n");
//	else printf("No\n");
//	return 0;
//}



/*堆的实现*/
//#include<stdio.h>
//#include<malloc.h>
//#define MaxData 10000
//#define MinData 0
//typedef int ElementType;
//typedef struct HeapStruct* MaxHeap;
//struct HeapStruct
//{
//	ElementType* Element;/*存储堆元素的数组*/
//	int Size;/*堆当前的元素个数*/
//	int Capacity;/*堆的最大容量*/
//};
//MaxHeap CreateEmptyMaxHeap(int MaxSize)/*创建容量为MaxSize的空的最大堆*/
//{
//	MaxHeap H = (MaxHeap)malloc(sizeof(HeapStruct));
//	H->Element = (ElementType*)malloc((MaxSize + 1) * sizeof(HeapStruct));/*将数组的0号元素作为哨兵，其值要大于堆中所有可能元素的值*/
//	H->Size = 0;
//	H->Capacity = MaxSize;
//	H->Element[0]= MaxData;
//	return H;
//}
//bool IsFull(MaxHeap H)
//{
//	return (H->Size == H->Capacity);
//}
//bool IsEmpty(MaxHeap H)
//{
//	return (H->Size == 0);
//}
//void Insert(MaxHeap H, ElementType item)
//{
//	if (IsFull(H))
//	{
//		printf("最大堆已满\n");
//		return;
//	}
//	H->Size++;
//	int i = H->Size;/*i指向插入item之后最后一个元素的位置*/
//	for (; H->Element[i / 2] < item; i /= 2)/*设置哨兵之后循环跳出时就没必要关注i了*/
//		H->Element[i] = H->Element[i / 2];/*向下过滤元素*/
//	H->Element[i] = item;/*插入item*/
//}
//ElementType Delete(MaxHeap H)/*从最大堆中取出键值最大的元素，并删除一个结点*/
//{
//	if (IsEmpty(H))
//	{
//		printf("最大堆已为空\n");
//		return -1;
//	}
//	ElementType MaxItem, Temp;
//	int parent, child;
//	MaxItem = H->Element[1];
//	Temp= H->Element[H->Size]; 
//	H->Size--;
//	for (parent = 1; parent * 2 <= H->Size; parent = child)
//	{
//		child = parent * 2;
//		if (child != H->Size && H->Element[child] < H->Element[child + 1])
//			child++;/*有左右子树，指向较大的那个;只有左子树，不操作*/
//		if (Temp > H->Element[child])
//			break;/*若父结点键值更大，退出循环*/
//		else
//			H->Element[parent] = H->Element[child];/*移动Temp到下一层*/
//	}
//	H->Element[parent] = Temp;/*parent定位作用*/
//	return MaxItem;
//}
//MaxHeap CreateMaxHeap()/*建立含有n个结点的最大堆*/
//{
//	MaxHeap H;
//	ElementType Tmp;
//	int n,parent, child,MaxSize;
//	printf("请输入最大堆的最大容量：\n");
//	scanf("%d", &MaxSize);
//	H = CreateEmptyMaxHeap(MaxSize);
//	printf("请输入最大堆结点的个数:\n");
//	scanf("%d", &n);
//	printf("请输入结点的值：\n");
//	for (int i = 1; i <= n; i++)
//    {
//		scanf("%d", &Tmp);
//		H->Element[i] = Tmp;
//	}
//	H->Size = n;
//	parent = H->Size / 2;
//	for (; parent >= 1; parent--)
//	{
//		/*与删除的操作类似，解决的是左右子树都是最大堆的情况下，如何将整棵树调成最大堆*/
//		Tmp = H->Element[parent];
//		for (; parent * 2 <= H->Size; parent = child)
//		{
//			child = parent * 2;
//			if (child != H->Size && H->Element[child] < H->Element[child + 1])
//				child++;/*有左右子树，指向较大的那个;只有左子树，不操作*/
//			if (Tmp > H->Element[child])
//				break;/*若父结点键值更大，退出循环*/
//			else
//				H->Element[parent] = H->Element[child];/*移动Temp到下一层*/
//		}
//		H->Element[parent] = Tmp;
//	}
//	return H;
//}
//void Show(MaxHeap H)
//{
//	for (int i = 1; i <= H->Size; i++)
//	{
//		printf("%d ", H->Element[i]);
//	}
//	printf("\n");
//}
//
///*Huffman树（最优二叉树）*/
//typedef char ElementType_;
//struct TreeNode
//{
//	char Data;
//	ElementType Weight;
//	TreeNode* Left;
//	TreeNode* Right;
//};
//
//
///*最小堆*/
//typedef struct TreeNode* Element_Type;
//typedef struct Heap_Struct* MinHeap;
//struct Heap_Struct
//{
//	Element_Type* Element;/*存储堆元素的数组*/
//	int Size;/*堆当前的元素个数*/
//	int Capacity;/*堆的最大容量*/
//};
//bool IsFull(MinHeap H)
//{
//	return (H->Size == H->Capacity);
//}
//bool IsEmpty(MinHeap H)
//{
//	return (H->Size == 0);
//}
//MinHeap CreateEmptyMinHeap(int MaxSize )/*创建容量为MaxSize的空的最小堆*/
//{                                         
//	MinHeap H = (MinHeap)malloc(sizeof(HeapStruct));
//	H->Element = (Element_Type*)malloc((MaxSize + 1) * sizeof(HeapStruct));/*将数组的0号元素作为哨兵，其值要小于堆中所有可能元素的值*/
//	H->Size = 0;
//	H->Capacity = MaxSize;
//	H->Element[0] = (Element_Type)malloc(sizeof(TreeNode));
//	H->Element[0]->Weight = MinData;
//	return H;
//}
//void InsertMinHeap(MinHeap H, Element_Type item )
//{
//	if (IsFull(H))
//	{
//		printf("最小堆已满\n");
//		return;
//	}
//	H->Size++;
//	int i = H->Size;/*i指向插入item之后最后一个元素的位置*/
//	for (; H->Element[i / 2]->Weight > item->Weight; i /= 2)/*设置哨兵之后循环跳出时就没必要关注i了*/
//		H->Element[i] = H->Element[i / 2];/*向下过滤元素*/
//	H->Element[i] = item;/*插入item*/
//}
//Element_Type DeleteMinHeap(MinHeap H )/*从最小堆中取出键值最小的元素，并删除一个结点*/
//{
//	if (IsEmpty(H))
//	{
//		printf("最小堆已为空\n");
//		return NULL;
//	}
//	Element_Type MinItem, Temp;
//	int parent, child;
//	MinItem = H->Element[1];
//	Temp = H->Element[H->Size];
//	H->Size--;
//	for (parent = 1; parent * 2 <= H->Size; parent = child)
//	{
//		child = parent * 2;
//		if (child != H->Size && H->Element[child]->Weight > H->Element[child + 1]->Weight)
//			child++;/*有左右子树，指向较小的那个;只有左子树，不操作*/
//		if (Temp->Weight < H->Element[child]->Weight)
//			break;/*若父结点键值更小，退出循环*/
//		else
//			H->Element[parent] = H->Element[child];/*移动Temp到下一层*/
//	}
//	H->Element[parent] = Temp;/*parent定位作用*/
//	return MinItem;
//} 
//
//
//typedef TreeNode* HuffmanTree;
///*利用最小堆构建Huffman树*/
//HuffmanTree Huffman(MinHeap H)
//{
//	int i;
//	HuffmanTree T;
//	int times = H->Size - 1;
//	for (i = 1; i <=times; i++)/*做H->Size-1次合并*/
//	{
//		T = (HuffmanTree)malloc(sizeof(TreeNode));
//		T->Data = '*';
//		T->Left = DeleteMinHeap(H);
//		T->Right = DeleteMinHeap(H);
//		T->Weight = T->Left->Weight + T->Right->Weight;
//		InsertMinHeap(H, T);
//	}
//	T = DeleteMinHeap(H);
//	return T;
//}
//
///*队列*/
//typedef struct QNode* Queue;
//struct Node
//{
//	Element_Type Data;
//	Node* Next;
//};
//struct QNode
//{
//	Node* rear;
//	Node* front;
//};
//bool IsEmpty(Queue Q)
//{
//	return (Q->front == NULL);
//}
//Queue CreateQueue()//创建队列
//{
//	Queue Q;
//	Q = (Queue)malloc(sizeof(QNode));
//	Q->front = Q->rear = NULL;
//	return Q;
//}
// void AddQueue(Queue PtrQ, Element_Type item)//入队
//{
//	if (PtrQ->front == NULL)
//	{
//		PtrQ->front = PtrQ->rear = (Node*)malloc(sizeof(Node));
//		PtrQ->rear->Data = item;
//		PtrQ->rear->Next = NULL;
//	}
//	else
//	{
//		PtrQ->rear->Next = (Node*)malloc(sizeof(Node));
//		PtrQ->rear->Next->Data = item;
//		PtrQ->rear->Next->Next = NULL;
//		PtrQ->rear = PtrQ->rear->Next;
//	}
//}
// Element_Type DeleteQueue(Queue PtrQ)//出队
//{
//	if (PtrQ->front == NULL)
//	{
//		printf("队列空\n");
//		return NULL;
//	}
//	else
//	{
//		Node* TopPtr = PtrQ->front;
//		Element_Type TopCell = TopPtr->Data;
//		PtrQ->front = PtrQ->front->Next;
//		free(TopPtr);
//		return TopCell;
//	}
//}
//void LevelOrderTraversal(HuffmanTree BT)/*层序遍历哈夫曼树，确认字符的哈夫曼编码*/
//{
//	Queue Q;
//	HuffmanTree T;
//	if (!BT) return;
//	Q = CreateQueue();
//	AddQueue(Q, BT);//根结点入队
//	while (!IsEmpty(Q))
//	{
//		T = DeleteQueue(Q);
//	    printf("%c ", T->Data);//访问出队的结点
//		if(T->Left)  AddQueue(Q, T->Left);
//		if(T->Right) AddQueue(Q, T->Right);
//	}
//	printf("\n");
//}
//void PreOrderTraversal(HuffmanTree BT)//先序遍历（根->左->右）
//{
//	if (BT)
//	{
//		printf("%c ", BT->Data);
//		PreOrderTraversal(BT->Left);
//		PreOrderTraversal(BT->Right);
//	}
//}
//void InOrderTraversal( HuffmanTree BT) //中序遍历（左->根->右）
//{
//	if (BT)
//	{
//		InOrderTraversal(BT->Left);
//		printf("%c ", BT->Data);
//		InOrderTraversal(BT->Right);
//	}
//}
///*利用哈夫曼树实现哈夫曼编码*/
//void Translate(char a[],HuffmanTree Root)
//{
//	HuffmanTree T=Root;
//	for (int i = 0; a[i]; i++)
//	{
//		if (a[i] - '0') T = T->Right;
//		else T = T->Left;
//		if (T->Right == NULL && T->Left == NULL)
//		{
//			printf("%c",T->Data);
//			T = Root;
//		}
//	}
//	printf("\n");
//}
//int main()
//{
//	printf("创建哈夫曼树....\n");
//	int flag = 1;
//	char c;
//	int weight;
//	MinHeap H=CreateEmptyMinHeap(20);
//	do
//	{
//		printf("请输入字符和权值：\n");
//		scanf("%c", &c);
//		getchar();
//		scanf("%d", &weight);
//		getchar();
//		TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
//		tmp->Data = c;
//		tmp->Left = NULL;
//		tmp->Right = NULL;
//		tmp->Weight = weight;
//		InsertMinHeap(H,tmp);
//		printf("是否继续添加？(1/0)\n");
//		scanf("%d", &flag);
//		getchar();
//	} while (flag);
//	HuffmanTree T=Huffman(H);
//	/*printf("哈夫曼树先序遍历序列如下：\n");
//	PreOrderTraversal(T);
//	printf("\n");
//	printf("哈夫曼树中序遍历序列如下：\n");
//	InOrderTraversal(T);
//	printf("\n");*/
//	printf("哈夫曼树层序遍历序列如下：\n");
//	LevelOrderTraversal(T);
//	printf("请输入要翻译的哈夫曼编码：\n");
//	char s[100];
//	scanf("%s", s);
//	printf("翻译如下：\n");
//	Translate(s, T);
//	return 0;
//}



/*使用静态链表和双亲表示法实现集合的表示*/
//#include<stdio.h>
//#define Null -1
//typedef int ElementType;
//struct SetType//单个结点
//{
//	ElementType Data;
//	int parent;//双亲表示法，存储父节点的下标，集合的根结点的parent记为"-集合的基数"
//};
//int Find(SetType S[],int MaxSize, ElementType X)//根据所给的元素找其所在的集合，找到返回根结点下标，没找到返回Null
//{
//	int i;
//	for (i = 0; i < MaxSize && S[i].Data != X; i++);//定位到元素下标
//	if (i >= MaxSize) return Null;
//	for (; S[i].parent >= 0; i = S[i].parent);//找根结点
//	return i;
//}
//void Union(SetType S[], int MaxSize, ElementType X1, ElementType X2)
//{
//	int Root1, Root2;
//	Root1 = Find(S, MaxSize, X1);
//	Root2 = Find(S, MaxSize, X2);
//	//为了提高查找效率，尽量将基数小的往基数大的并！
//	if (Root1 != Root2)
//	{
//		if (Root1 < Root2)//第一个集合基数更大
//			S[Root2].parent = Root1;
//		else
//			S[Root1].parent = Root2;
//	}
//}
//int main()
//{
//	return 0;
//}




 