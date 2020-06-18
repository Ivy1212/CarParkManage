//#include"seqlist.h"
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#define MAXVERTICES 200//ͼ�Ķ���������
#define MAXWEIGHT 9999

extern int versize;
//extern CarportInfo allCarInfo[500];//Ӧ�����ó�ȫ�ֱ������ã�����дextern���ṹ��ԭ�򣿣�

//seqlist
#define MAXSIZE 500
typedef struct {
	int list[MAXSIZE];
	int size;
}SeqList;



//��λ��Ϣ�ṹ��
//��λ��Ϣ����λ�ţ�����ţ������̳��ľ��룬��λ�������
typedef struct Carport{
	int carport_id;//��λ��(�����)
	double entry_distance;//���̳���ھ���
	int carport_isFree;//��λ�������(����c����û��bool���ͣ�c++���У�������int����bool�÷�)
	
	/*�����ͣ��λ���г�,������������ԣ����û������ΪNULL������ʼΪNULL*/
	char car_id[20];//���ƺ�
	char car_color[20];//��ɫ

}CarportInfo;


/*
�ýṹ��ϲ�������λ��Ϣ�ṹ�塱�����㴦��

//������Ϣ�ṹ��
//���ƺţ�������ɫ
typedef struct Car{
	char car_id[20];//���ƺ�
	char car_color[20];//��ɫ
}CarInfo;

*/


//����ͼ�ṹ(����)
typedef struct{
	int row;//���±�
	int col;//���±�
	int weight;//Ȩֵ
	//int entry_distance;//add--��λ���̳���ڵľ���(ERR:����������ṹ����ƣ���Ϊ����ṹ���Ǵ洢����Ϣ�ģ�
											//��entry_distance�ǹ��ڵ���Ϣ��)
}rowcolweight;//��������Ϣ�ṹ��



////////////////////////
//////�ڽӾ���//////////
///////////////////////
typedef struct{
	SeqList ver;//���Ա�ṹ���Ա����˳������ڴ�Ŷ���
	int edge[MAXVERTICES][MAXVERTICES];//��űߵ��ڽӾ���
	int edgecount;//������
}GraphOfMatrix;


//��ʼ�����ڽӾ���
void init(GraphOfMatrix *G,int n);		//ɾȥextern--6.13 22��46


//���붥�㣨�ڽӾ���
void arr_insertver(GraphOfMatrix *G,int vertex);



//����ߣ��ڽӾ���
void arr_insertedge(GraphOfMatrix *G,int v1,int v2,int weight);


//ȡ��һ���ڽӶ���(���ǡ���һ����λ��/"��һ����λ")
//1.���ڲ�ѯ���ڳ�λ
int *GetFirstVex(GraphOfMatrix G,int v);
//2.ֻ��ѯ��һ����λ������DFS����
int GetFirstVexWithOne(GraphOfMatrix *G,int v);


//ȡ��һ���ڽӶ���
int GetNextVex(GraphOfMatrix *G,int v1,int v2);

//����ͼ	//rowcolweight edge[]Ϊ��ͼ�ı���Ϣ���ṹ������(�ڽӾ���)
void creat_graph(GraphOfMatrix *G,int ver_arrs[],int ver_count,rowcolweight edge[],int edge_count);






////////////////////////
//////�ڽ�����//////////
///////////////////////

typedef struct Node{
	int dest;//�ڽӱߵĶ����±�
	int weight;//Ȩֵ
	struct Node *next;
}edge;//����Ϣ������

typedef struct{
	int data;
	int source;//��ǰ�����Ӧ���±�ֵ
	edge *adj;//�ڽӱߵ�ͷָ��
}arr_edge;//����Ϣ������

typedef struct{
	arr_edge arr[MAXVERTICES];	//ͼ�Ķ��������� / MAXVERTICES����洢���е������ĸ���
	int numofverts;//�������
	int numofedges;//������
}GraphOfList;//���ܣ��ڽӱ�ṹ��-ͼ



//��ʼ�����ڽӱ�
void init_link(GraphOfList *G);




//���붥��-������������ڽӱ�
void arr_insertver_link(GraphOfList *G,int i,int vertex);




//�����-������������ڽӱ�
void arr_insertedge_link(GraphOfList *G,int v1,int v2,int weight);






//����ͼ(�ڽ�����)
void creat_graph_link(GraphOfList *G,int ver_arrs[],int ver_count,rowcolweight edge[],int edge_count);



//������ڽӾ���
void outputInfoOfMatrix(GraphOfMatrix *G,int versize);

//������ڽ�����
void outputInfoOfList(GraphOfList *G);
//again















/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////



#include<stdio.h>
#include<stdlib.h>
//#include"implementation.h"//���������룬�������ֽṹ�������ض��壨����	10	error C2011: ��Node��:��struct�������ض��壩
/*�˵�����*/
void interface_call(GraphOfMatrix *G,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count);				//ɾȥextern--6.13 22��46


/*�˵�����*/
void menu_main();//���˵�
void Menucarinfo();//����
void menu_carinfo(GraphOfMatrix *G,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count);//��λ��Ϣ�ṹͼ �˵�
void Menucarsituation();
void menu_carsituation(GraphOfMatrix *G,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count);//��λ�����ѯ �˵�
void Menunullport();
void nullPortSelectMenu(GraphOfMatrix *G,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count);//�ճ�λ��ѯ�˵�
void MenuOfSearchBest();


/*��λ�ṹ��Ϣ���*/
int outputCarportOfPic();


/*�ճ�λ��ѯ*/
//ʹ���ڽӾ���
void searchNullPortOfselectId(int selectId);//1.�����û�ָ����λ��id��ѯ
void searchNullPortOfAll();//2.��ѯ�������пճ�λ��������飩



/*�̳���ڲ�ѯ*/
double searchMarketEntry(GraphOfMatrix *G,int ver_arrs[200]);//������Carportgraph *G��int j


/*���ڳ�λ��ѯ*/
void searchNextPort(GraphOfMatrix *G,int currentCarPortId);


/*********************************��λ����·���ۺϲ�ѯ*************************************/
/*****************1.���ݵ�ǰλ���복λ����  2.����Ŀ�공λ���̳���ھ���*********************/
/**************************************************************************************/
//1.���ݵ�ǰλ���복λ����
int searchBestRoad(GraphOfMatrix *G,int ver_arrs[200]);//����·�߲�ѯ���ú������س�λid������ţ�
// 2.����Ŀ�공λ���̳���ھ���
int searchBestRoadOfEnter();



/*����������г�λ�����Ϣ*/
void outputCarportInfo();


/*
//��λ�ṹ��Ϣ���
void outputInfoOfMatrix();//�ڽӾ������
void outputInfoOfList();//�ڽ��������
*/






/*�ļ���������*/
/*1.�ļ���������-----------------------���복λ�ṹ��ϵ*/
//ver_countΪʵ�ʶ������;edge_countΪ������
int readCartport(GraphOfMatrix *Gr,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count);


/*2.�ļ���������-----------------------���복λ��Ϣ����*/
int readCarInfo();


/*1.ͣ����2.ȡ��������3.�޸���Ϣ�������д���ļ�*/
//1.ͣ��
void addCar(GraphOfMatrix *G,char carId[20],char carColor[20],int ver_arrs[200]);

//2.ȡ��
void deleteCar(int deleteCarportId);

//3.��ͣ��/ȡ���������д���ļ�
void lastestCarPortInfoFile(int wantCarportId,char carId[20],char carColor[20],int deleteCarportId);


