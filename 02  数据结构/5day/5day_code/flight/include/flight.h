#ifndef __FLIGHT_H__
#define __FLIGHT_H__
#include<string.h>    
#include<stdio.h>    
#define N 8  //    
#define N1 7  // N1Ϊ����������λ��     
#define N2 97// N2Ϊ����     
//������Ϣ    
//int flag1 = 0;
typedef struct flight   
{   
    char number[10];  //�����    
    char staddress[10];   //���վ    
    char arraddress[10];   //�յ�վ    
    char DATE[10];//����    
    char TYPE[4]; //����    
    int stime;     //���ʱ��    
    int atime;   //����ʱ��    
    int value;           //Ʊ��     
}DataType;   
struct flight Flight[N];   
typedef char KeyType;   
struct Node;             //������������    
typedef struct Node jsNode;   
struct Node   
{       
 KeyType key[N1];      
 DataType info;       
 jsNode *next;   
};   
typedef jsNode * jsList;   
typedef struct QueueNode   
{       
    jsNode *f;           //���е�ͷָ��     
    jsNode *e;           //���е�βָ��     
}Queue;   
Queue queue[N2];   
struct Node ys[N+2];

#endif
