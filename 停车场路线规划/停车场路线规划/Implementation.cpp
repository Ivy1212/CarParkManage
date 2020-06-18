/*ҵ���߼�ʵ��*/

#include"implementation.h"

#include<stdio.h>
int versize=0;
int allEageWeights[500]={0};//��Ϊ�ļ������ǰversize�ж��Ǵ�Ŷ���0������n��ͼ�ṹ��������Կ���ֱ����һ����������ж���0���������⳵λ��weight����������������ڵ���
CarportInfo allCarInfo[500];//Ӧ�����ó�ȫ�ֱ�������

//��ʼ��
void seq_init(SeqList *L)
{
	L->size=0;
}

int PrintData(SeqList *L)//������˳�������Ԫ��
{
	int i;
	if(L->size<0)
	{
		printf("������\n");
		return 0;
	}
	else
	{
		printf("����Ԫ������\n");
		for(i=0;i<L->size;i++)
		{
			printf("%d\t",L->list[i]);
		}
		return 1;
	}
}

int ListFind(SeqList L,int x)//��λ����
{
	int i;
	if(L.size<0)
	{
		printf("������\n");
		return 0;
	}
	else
	{
		for(i=0;i<L.size;i++)
		{
			if(L.list[i]==x)
			{
				printf("���ҵ�ָ������\n");
				return i;
			}
		}
		printf("δ�ҵ�ָ������\n");
		return -1;
	}
}

int InsertData(SeqList *L,int i)//������Ԫ��i������������˳���L�У��Ա��ָ�˳����������
{
	int j,k;//j�����������Ա�kΪ������̱����������Ա�
	if(L->size<0)
	{
		printf("��˳���������\n");
		return 0;
	}
	if(L->size>=MAXSIZE)
	{
		printf("˳��������޷�����\n");
		return 0;
	}
	else
	{
		for(j=0;j<L->size;j++);

				L->list[j]=i;
				L->size++;
				//printf("˳��� L->size =%d\n",L->size);
				return 1;
			
		
		return 0;
	}
}

int getdata(SeqList L,int i,int *x){
	*x=L.list[i];
	return *x;
}

////////////////////////////////////////////////
//////////////ͼ�ṹ////////////////////////////
///////////////////////////////////////////////

//GraphOfMatrix�ڽӾ���
//GraphOfList�ڽӱ�


//////////////////////////////////////////////////
//////////////////////�ڽӾ���////////////////////
/////////////////////////////////////////////////

//��ʼ�����ڽӾ���
void init(GraphOfMatrix *G,int n){	//nΪ������
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(i==j){
				G->edge[i][j]=0;//�Խ�����0
			}
			else{
				G->edge[i][j]=MAXWEIGHT;
			}
		}
		G->edgecount=0;

		G->ver.size=0;//˳����ʼ��
}


//���붥�㣨�ڽӾ���
void arr_insertver(GraphOfMatrix *G,int vertex){	//vertexΪ����
	InsertData(&G->ver,vertex);//��vertex������������˳���L��
	//G->ver.size++;
	//printf("���붥��ɹ�����ʱ G->ver.sizeΪ%d\n",G->ver.size);
}

//����ߣ��ڽӾ���
void arr_insertedge(GraphOfMatrix *G,int v1,int v2,int weight){
	//if( v1<0 || v2<0 || v1>G->ver.size || v2>G->ver.size ){	//�ߴ���
	//	printf("�쳣���޷������\n");
	//	return ;
	//}
	//else{
		G->edge[v1][v2]=weight;	//Ȩֵ
		G->edgecount++;
	//}
}


/*********************************ȡ��һ���ڽӶ���***************************************/
/*****************1.��ѯ���ڵ����г�λ      2.��ѯ��һ����λ******************************/
/**************************************************************************************/

//1.���ڲ�ѯ���ڳ�λ
//(���ǡ���һ����λ��/"��һ����λ"---������λ��Ϣ(�к�)����һ��������)
//����v�ĵ�һ���ڽӶ��㣬�����ڽӾ���Ķ���v���дӵ�һ������Ԫ�ؿ�ʼ�ķ�0�ҷ������Ķ���
int *GetFirstVex(GraphOfMatrix *G,int v){
	int col,okCol=0;
	int *vers;//ȫ����ʼ��Ϊ0
	vers=(int *)malloc(sizeof(int)*2);
	if(v<0 || v>=G->ver.size){
		printf("����v1Խ�����\n");
		return NULL;
	}
	for(col=0;col<G->ver.size;col++){
		if(G->edge[v][col]>0 && G->edge[v][col]<MAXWEIGHT){
			vers[okCol]=col;
			//printf("�ҵ���%d�����ڳ�λ����λ����%d\n",okCol+1,vers[okCol]);
			okCol++;
		}
	}
	return vers;
}


//2.ֻ��ѯ��һ����λ������DFS����
int GetFirstVexWithOne(GraphOfMatrix *G,int v){
	int col;
	for(col=0;col<G->ver.size;col++){//��������˳�����v��������
		if(G->edge[v][col]>0 && G->edge[v][col]<MAXWEIGHT){
			return col;
		}
		else
			return -1;
	}
}




//ȡ��һ���ڽӶ���-(�ڽӾ���Ķ���v1���дӵ�v2+1������Ԫ�ؿ�ʼ�ķ�0�ҷ������Ķ���)
//v1���ڽӶ���v2����һ���ڽӶ���
//DFS��Ҫ�õ�
int GetNextVex(GraphOfMatrix *G,int v1,int v2){
	int col;
	for(col=v2+1;col<G->ver.size;col++){//����˳�����v2+1����㿪ʼ
		if(G->edge[v1][col]>0 &&G->edge[v1][col]<MAXWEIGHT){
			return col;
		}
		else
			return -1;
	}
}



//����ͼ	//rowcolweight edge[]Ϊ��ͼ�ı���Ϣ���ṹ������(�ڽӾ���)
void creat_graph(GraphOfMatrix *G,int ver_arrs[],int ver_count,rowcolweight edge[],int edge_count){
	int i,j;
	init(G,ver_count);	//��ʼ����ver_countΪ������

	for(i=0;i<ver_count;i++){	//��������
		arr_insertver(G,ver_arrs[i]);
		//printf("����%d�����ɹ�\n",i);
		versize=G->ver.size;
		//printf("versize=%d,G->ver.size=%d",versize,G->ver.size);
	}
	//if(i==ver_count)
		//printf("��������ɹ�\n");


	for(j=0;j<edge_count;j++){	//������
		arr_insertedge(G,edge[j].row,edge[j].col,edge[j].weight);
		//printf("��%d�����ɹ�\n",j);
	}
	//if(j==edge_count)
	//	printf("�����߳ɹ�\n");

}
//������ڽӾ���
void outputInfoOfMatrix(GraphOfMatrix *G,int versize){

	int i,j;
	printf("һ����%d����λ\n",G->ver.size);
	//printf("һ����%d����λversize\n",versize);
	printf("\n");

	printf("��λ�Ľṹ��Ϣ����\n");
	for(i=0;i<versize;i++){
		for(j=0;j<G->ver.size;j++)
		{
			//printf("�����%d����",j);
			printf("%d\t",G->edge[i][j]);
		}
		printf("\n");
	}
}




///////////////////////////////////////////////////////
///////////////////�ڽ�����////////////////////////////
/////////////����洢���㣬����洢����Ϣ///////////////
//////////////////////////////////////////////////////


/*
//�����ж�����
//����ͼ�ṹ
typedef struct{
	int row;//���±�
	int col;//���±�
	int weight;//Ȩֵ
}rowcolweight;//��������Ϣ�ṹ��
*/

//��ʼ�����ڽӱ�
void init_link(GraphOfList *G){
	int i;
	G->numofedges=0;
	G->numofverts=0;
	for(i=0;i<MAXVERTICES;i++){
		G->arr[i].adj=NULL;//�ÿ�
		G->arr[i].source=i;//��ʼ��������Զ�Ӧ���±꣬��0��ʼ
	}
}

//���붥��-������������ڽӱ�
void arr_insertver_link(GraphOfList *G,int i,int vertex){
	if(i>=0 && i<MAXVERTICES){
		G->arr[i].data=vertex;
		G->numofverts++;
	}
	else{
		printf("���붥��ʧ�ܣ�\n");
		return ;
	}
}

//�����-������������ڽӱ�
void arr_insertedge_link(GraphOfList *G,int v1,int v2,int weight){
	edge *e;//eΪ�������ͷ
	e=(edge*)malloc(sizeof(edge));//edge�ṹ���С�Ŀռ�
	e->dest=v2;//destΪ�ڽӵ���±�ֵ(���Ϊ��v1��ָ��v2)	///////	��ʾ����v1��v2
	e->next=G->arr[v1].adj;//�½����뵥����ı�ͷ	////////��ʾ����e��v1
	G->arr[v1].adj=e;//ͷָ��ָ���µĵ������ͷ	//����û��next��
	G->numofedges++;
}

//����ͼ(�ڽ�����)
void creat_graph_link(GraphOfList *G,int ver_arrs[],int ver_count,rowcolweight edge[],int edge_count){
	int i,k;
	init_link(G);	//��ʼ��

	for(i=0;i<ver_count;i++)
		arr_insertver_link(G,i,ver_arrs[i]);	//���붥��

	for(k=0;k<edge_count;k++)
		arr_insertedge_link(G,edge[k].row,edge[k].col,edge[k].weight);	//�����
}

//����ڽӱ� 
void outputInfoOfList(GraphOfList *G){
	int i;
	//printf("data\tsources\tadj\tdest next\n");
	printf("sources\tadj  dest next\n");
	//printf("G->numofverts=%d\n",G->numofverts);
	for(i=0;i<G->numofverts;i++){
		//printf("%d\t",G->arr[i].data);
		printf("%d\t",G->arr[i].source);
		if( G->arr[i].adj==NULL){//ע�⣬����next
			printf("^\n");
		}
		else{
			printf("  ");
			while(G->arr[i].adj!=NULL){//ע�⣬����next
				printf("--> ");
				printf("%d  ",G->arr[i].adj->dest);
				G->arr[i].adj=G->arr[i].adj->next;
			}
			printf("\n");
		}
	}
}









/*��λ�ṹ��Ϣ�����ͼƬ��*/
int outputCarportOfPic(){
	//չʾһ��ͼƬ����λ�ṹͼ��
	int width=0,height=0;
	IMAGE carportImg;
	loadimage(&carportImg,_T("C:\\Users\\w1396\\Desktop\\carport.jpg"));//����·��+ͼƬ��
	width=carportImg.getwidth();
	height=carportImg.getheight();
	initgraph(width,height);
	BeginBatchDraw();
	putimage(0,0,&carportImg);
	EndBatchDraw();
	system("pause");
	closegraph();//close
	return 1;//���÷���ֵ��ʹ�ڹر�ͼƬ���Զ��˳�ϵͳ�����ǻص����˵�
}





/*********************************�ճ�λ��ѯ��ʹ���ڽӾ���*************************************/
/*****************1.���ݳ�λ��id��ѯ      2.��ѯ�������пճ�λ��������飩**************************/
/**********************************************************************************************/

///////////////////1.�����û�ָ����λ��id��ѯ//////////////////////////////////////
void searchNullPortOfselectId(int selectId){//selectId��0��ʼ����Ӧ����1�����ֶ�Ӧ��selectId-1��
	if(selectId>versize-1){
		printf("�����޸ó�λ\n");
		return ;
	}
	
	if(allCarInfo[selectId-1].carport_isFree==0){
		printf("��λ%d����\n",selectId);
	}
	else{
		printf("�ó�λ���г���\n");
		printf("�ó�λ�ĳ�����ϢΪ��\n");
		printf("���ƺţ�%s\n",allCarInfo[selectId-1].car_id);
		printf("������ɫ��%s\n",allCarInfo[selectId-1].car_color);
	}

}

///////////////////2.��ѯ�������пճ�λ��������飩//////////////////////////////////////
void searchNullPortOfAll(){
	int index=0;
	char nullport[500];
	for(index=0;index<versize-1;index++){
		if(allCarInfo[index].carport_isFree==0){//����
			nullport[index]=index;//��0��ʼ
		}
		else
			nullport[index]=-1;
	}
	printf("���ڲ�ѯ��...\n");
	printf("��ѯ�ɹ�,���г�λ���£�\n");
	for(index=0;index<versize;index++){//��1�ų�λ��ʼ
		if(nullport[index]>0)//�б���ֵ�������г�λ
			printf("%d  ",index+1);//��ʱindex==nullport[index]	//+1
	}
	printf("\n");
}








/*�̳���ڲ�ѯ*/
//���á�����·���ۺϲ�ѯ�����ҵ�����һ��Ҫȥͣ���ĳ�λ�ĳ�λ�ţ����ݸó�λ��ȥ��ѯ��Ӧ���̳���ھ���
/*
	int carport_id;//��λ��(�����)
	double entry_distance;//���̳���ھ���
	int carport_isFree;
*/
double searchMarketEntry(GraphOfMatrix *G,int ver_arrs[200]){
	char *free="NULL";
	int carportId=0;
	printf("���ݳ�λ�Ų�ѯ�������복λ�ţ�");
	scanf("%d",&carportId);
	int wantCarportId=carportId-1;//����·�߲�ѯ���ú������س�λid������ţ�
	printf("�ó�λ�����Ϊ��\n");
	//printf("��λ��wantCarportId��%d\n",wantCarportId);//wantCarportId���ص�ֵ�Ǵ�0��������λ��2ʱwantCarportId=1
	printf("��λ�ţ�%d\n",allCarInfo[wantCarportId].carport_id);//�ṹ�����carport_id���ص�ֵ���ǳ�λ��
	printf("�ó�λ������̳���ڵľ���Ϊ��%.2f m\n",allCarInfo[wantCarportId].entry_distance);
	if(allCarInfo[wantCarportId].carport_isFree==0) free="isfree";
	else free="notisfree";
	printf("�ó�λ���������%s\n",free);
	return 0;
}


/*���ڳ�λ��ѯ*/
//currentCarPortId:��ǰ��λ�ţ�����ţ�
void searchNextPort(GraphOfMatrix *G,int currentCarPortId){
	int *vers;
	int i=0;
	char *free="NULL";
	vers=(int*)malloc(sizeof(int)*2);
	//ȡ��һ���ڽӶ���(���ǡ���һ����λ��/"��һ����λ")
	vers=GetFirstVex(G,currentCarPortId);
	//printf("****versize=%d***\n",versize);//versize==19
	for(i=0;i<2;i++){
		if((currentCarPortId==1) || (currentCarPortId==versize-1)){//���ȼ�����
			printf("���ڵĳ�λ��Ϊ��%d\n",vers[0]);

			if(allCarInfo[vers[0]].carport_isFree==0) free="isfree";
			else free="notisfree";
			printf("��λ %d �Ŀ�������ǣ�%s\n",vers[0],free);

			printf("��λ %d �뵱ǰ��λ�ľ����ǣ�%d m\n",vers[0],G->edge[currentCarPortId][vers[0]]);
			printf("\n");
			break;
		}
		printf("�� %d �����ڵĳ�λ��Ϊ��%d\n",i+1,vers[i]);

		if(allCarInfo[vers[i]].carport_isFree==0) free="isfree";
		else free="notisfree";
		printf("��λ %d �Ŀ�������ǣ�%s\n",vers[i],free);

		printf("��λ %d �뵱ǰ��λ�ľ����ǣ�%d m\n",vers[i],G->edge[currentCarPortId][vers[i]]);
		printf("\n");
	}

}


//DFS�㷨
void DFS(GraphOfMatrix *G,int vex,int flag[]){//verΪ��ʼ���㣬flag[]����Ƿ��ѷ���
	int midvex;
	printf("%d ",vex);
	flag[vex]=1;
	midvex=GetFirstVexWithOne(G,vex);//ȡ��һ���ڽӶ���
	while(midvex!=-1){
		if(!flag[midvex])//û�б�����
		{
			DFS(G,midvex,flag);//��ȡ���ġ���һ���ڽӶ��㡱��Ϊ�µĳ�ʼ����
		}

		/*���ݣ����ݵ���ǰ�������һ������vex��vex����һ������(����midvex�Ķ���)����������·����*/
		midvex=GetNextVex(G,vex,midvex);//�����vexÿ���ڵݹ����ʱ����������
	}
	/*

	�൱���������
				   --> E
	   --> B -> D --  
	A--			   -->F
	   --> C
	
	�൱�ڣ�
	D:	vex 
	E:	midvex
	F:	��һ���ڽӶ���

	*/



}
/*********************************��λ����·���ۺϲ�ѯ*************************************/
/*****************1.���ݵ�ǰλ���복λ����  2.����Ŀ�공λ���̳���ھ���*********************/
/**************************************************************************************/

//1. ���ݵ�ǰλ���복λ����
//DFS-----�����Խ����ʹ��DFS�����ʵ��Ӧ�������ֲ������ƣ��������鷳��
//���Բ�����ͨѭ���ķ�ʽ���Ա���DFS�����Ľӿڣ����ں���ά��
int searchBestRoad(GraphOfMatrix *G,int ver_arrs[200]){//����·�߲�ѯ���ú������س�λid������ţ�
	//int flag[200]={0};
	//DFS(G,ver_arrs[0],flag);
	int i=0;
	int free=-1;
	//allEageWeights[i]=edge[i].weight
	for(i=0;i<versize;i++){//��i�����ڶ��������棬����allEageWeights�ı�������
		
		if(allCarInfo[i].carport_isFree==0) free=0;//����
		else free=1;
	
		if(!free){
			printf("��ǰ��λ����%d������״̬Ϊ�����С�\n",i+1);
			printf("����ǰ��ó�λ�ľ�����%d m\n",allEageWeights[i]);
			printf("Ŀ�공λ������̳���ھ�����%.2lf m\n",allCarInfo[i].entry_distance);
			return i;
		}
	}
	printf("��Ǹ�����⳵λ������û���ҵ����г�λ\n");
	return -1;//1�����㡰2������ȥ0�ų�λ�⣬�ٴ�0��ʼ����
}


//2.�ҵ����̳��������ĳ�λ������Ǹ���λ�г�
int searchBestRoadOfEnter(){
	int i,free=-1,minDistance=1,minCarport=-1,j;
	minDistance=allCarInfo[0].entry_distance;
	for(i=0;i<versize;i++){//��i�����ڶ��������棬����allEageWeights�ı�������
		//allCarInfo[0]����Ƕ���1
		if(allCarInfo[i].carport_isFree==0) free=0;//����
		else free=1;

		if(allCarInfo[i].entry_distance < minDistance){
			minDistance=allCarInfo[i].entry_distance;
			minCarport=allCarInfo[i].carport_id;
		}
	}

	if(!allCarInfo[minCarport].carport_isFree){	//minCarport����
			printf("ֱ���ҵ�\n");
			printf("��Ϊ��Ѱ�ҵ������̳��������ĳ�λ\n");
			printf("��ǰ��λ����%d������״̬Ϊ�����С�\n",minCarport);
			printf("����ǰ��ó�λ�ľ�����%d m\n",allEageWeights[minCarport]);
			printf("Ŀ�공λ������̳���ھ�����%.2lf m\n",minDistance);
			return minCarport;
	}
	else{	//Ѱ�����ڳ�λ(����ϵͳ������λ���ص㣨�ӽ���Զ����������������ֱ����minCarport����ĳ�λ����)
		printf("Ѱ�����ڳ�λ\n");
		for(j=minCarport+1;j<versize;j++){
			if(!allCarInfo[j].carport_isFree){//minCarport����

				printf("��Ϊ��Ѱ�ҵ������̳��������ĳ�λ\n");
				printf("��ǰ��λ����%d������״̬Ϊ�����С�\n",j+1);
				printf("����ǰ��ó�λ�ľ�����%d m\n",allEageWeights[j]);
				printf("Ŀ�공λ������̳���ھ�����%.2lf m\n",allCarInfo[j].entry_distance);
				return j;
			}
		}		
	}
	printf("��Ǹ�����⳵λ������û���ҵ����г�λ\n");
	return -1;

}






/*����������г�λ�����Ϣ*/
void outputCarportInfo(){//������Carportgraph *G
	int index;
	printf("�������г�λ�������Ϣ���£�\n");
	printf("��λ��\t�����̳�   �Ƿ����    ���ƺ�   ������ɫ\n");
	for(index=0;index<versize-1;index++){
		printf("%d\t%.2lf m\t\t%d\t%s\t%s\n",allCarInfo[index].carport_id,allCarInfo[index].entry_distance,allCarInfo[index].carport_isFree,allCarInfo[index].car_id,allCarInfo[index].car_color);
		
	}
}




/*1.�ļ���������-----------------------���복λ�ṹ��ϵ*/
//ver_arrs[200] ��λ��������������
//ver_countΪʵ�ʶ������;edge_countΪ������
int readCartport(GraphOfMatrix *Gr,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count){
	FILE *fp;
	int index=0;
	if((fp=fopen("CarPark.txt","r"))==NULL){
		printf("���ļ�����\n");
		exit(0);
	}
	printf("��λ���ļ�CarPark.txt�����ڶ�ȡ...\n");
	//printf("�ļ��е��������£�\n");
	/*
0,1,1:0
0,2,2:0
0,3,3:0
0,4,4:0
0,5,5:0
0,6,6:0
0,7,7:0
0,8,8:0
0,9,9:0
0,10,10:0
0,11,11:0
0,12,12:0
0,13,13:0
0,14,14:0
0,15,15:0
0,16,16:0
0,17,17:0
0,18,18:0
1,2,1:1
2,1,1:2
2,3,1:2
3,2,1:3
3,4,1:3
4,3,1:4
4,5,1:4
5,4,1:5
5,6,1:5
6,5,1:6
6,7,1:6
7,6,1:7
7,8,1:7
8,7,1:8
8,9,1:8
9,8,1:9
9,10,1:9
10,9,1:10
10,11,1:10
11,10,1:11
11,12,1:11
12,11,1:12
12,13,1:12
13,12,1:13
13,14,1:13
14,13,1:14
14,15,1:14
15,14,1:15
15,16,1:15
16,15,1:16
16,17,1:16
17,16,1:17
17,18,1:17
18,17,1:18


*/
	while(!feof(fp)){
		/*ע�⣺���ļ�������ϢҪ�� & */
		fscanf(fp,"%d,%d,%d:%d\n",&edge[index].row,&edge[index].col,&edge[index].weight,&ver_arrs[index]);
		//printf("index=%d : %d,%d,%d",index,edge[index].row,edge[index].col,edge[index].weight);
		//printf("\nver_arrs[%d]=%d\n\n",index,ver_arrs[index]);
		allEageWeights[index]=edge[index].weight;
		index++;
	}
	printf("��ȡ�ļ��ɹ�\n");
	fclose(fp);

	//����ͼ
	creat_graph(Gr,ver_arrs,ver_count,edge,edge_count);
	creat_graph_link(Glist,ver_arrs,ver_count,edge,edge_count);
	return 0;
}




/*
CarInfo.txt
1,3,0,NULL NULL
2,2,0,NULL NULL
3,1,0,NULL NULL
4,1,0,NULL NULL
5,2,0,NULL NULL
6,3,0,NULL NULL
7,3,0,NULL NULL
8,2,0,NULL NULL
9,1,0,NULL NULL
10,1,0,NULL NULL
11,2,0,NULL NULL
12,3,0,NULL NULL
13,3,0,NULL NULL
14,2,0,NULL NULL
15,1,0,NULL NULL
16,1,0,NULL NULL
17,2,0,NULL NULL
18,3,0,NULL NULL
*/
/*2.�ļ���������-----------------------���복λ��Ϣ����*/
/*
�ṹ�����CarportInfo
int carport_id		��λ�ţ�����ţ�
double entry_distance		��λ���̳�����
int carport_isFree		�����������(����Ϊ0)
char car_id[20]		���ƺ�
char car_color[20]	��ɫ
*/
//��ʼ���г�λ�����У��г������Ҫ�����µĳ�λ��Ϣ���ļ��У�����/���ã�
int readCarInfo(){
	FILE *fp2;
	//CarportInfo allCarInfo[500];Ӧ�����ó�ȫ�ֱ�������
	int index=0;
	if((fp2=fopen("CarInfo.txt","r"))==NULL){
		printf("��ȡ�ļ�CarInfoʧ��\n");
		exit(0);
	}
	printf("��λ���ļ�CarInfo.txt�����ڶ�ȡ...\n");
	printf("�ļ��е��������£�\n");
	printf("��λ��\t�����̳�   �Ƿ����    ���ƺ�   ������ɫ\n");

	while(!feof(fp2)){
		//ע�⣺entry_distance��double�ͣ�%lfд��%d�������һ��������Ϣcarport_isFree��ȡ����
		/*��Ϊ���ַ������ͣ�ϵͳ���ܽ�����Ҳʶ����ַ�����һ���֣����Բ��Խ����ֻ���˵�һ��Ȼ���һֱ����...��,
		  �����һ���ַ����Ӹ� �ַ� ��Ϊ������-----------------�������������Ҳ���У�����*/
		/*����һ�����⣺
		  1,3,0,NULL,NULL  ��������д��һ�����Ѷ���Ҳʶ����˵�һ��char[]���ַ���ֵ�����Ժ��������һ���ַ���
		  �Ķ�ȡ��������һ�� %s �޷���ȡ�����Ծ͡���...��*/

		/*
		���ս��������
			д�� 1,3,0,NULL NULL ������ʽ�����ˣ��ÿո�ָ������ַ�������ע�������ͨ���м��ɣ����üӿո�ʲô��
		*/
		fscanf(fp2,"%d,%lf,%d,%s %s\n",&allCarInfo[index].carport_id,&allCarInfo[index].entry_distance,&allCarInfo[index].carport_isFree,allCarInfo[index].car_id,allCarInfo[index].car_color);//�ǵ�ȡַ�� & (ע�⣺��������char���Ͳ��� & )
		//printf("allCarInfo[index].carport_isFree=%d\n",allCarInfo[index].carport_isFree);
		//printf("��ȡ�ļ��ɹ�\n");
		printf("%d\t%.2lf m\t\t%d\t%s\t%s\n",allCarInfo[index].carport_id,allCarInfo[index].entry_distance,allCarInfo[index].carport_isFree,allCarInfo[index].car_id,allCarInfo[index].car_color);
		index++;
	}
	printf("��ȡ�ļ��ɹ�\n");
	fclose(fp2);
	return 0;
}




/********************************************************/
/*****1.ͣ����2.ȡ��������3.�޸���Ϣ�������д���ļ�********/
/********************************************************/
/*
�ṹ�����CarportInfo
int carport_id		��λ�ţ�����ţ�
double entry_distance		��λ���̳�����
int carport_isFree		�����������(����Ϊ0)
char car_id[20]		���ƺ�
char car_color[20]	��ɫ
*/

///////////////1.ͣ��/////////////
/*
������
wantCarportId:������Ҫͣ���ĳ�λ�ţ�����ţ�
carId[20]:���ƺ�
carColor[20]:������ɫ
*/
//��������� ���±����ļ�����lastestCarPortInfoFile()
void addCar(GraphOfMatrix *G,char carId[20],char carColor[20],int ver_arrs[200]){
	int op=-1;
	int wantCarportId=-1;
	printf("\n������������������ʽƥ�䳵λ��");
	while(op!=0){
		MenuOfSearchBest();
		scanf("%d",&op);
		if(op==1){
			wantCarportId=searchBestRoad(G,ver_arrs);
			break;
		}//����·�߲�ѯ���ú������س�λid������ţ�
		else if(op==2){
			wantCarportId=searchBestRoadOfEnter();
			break;
		}
		else{
			printf("����������\n");
			scanf("%d",&op);
		}
	}
	if(wantCarportId==-1) return ;
	//printf("\n\naddCar()����\n");
	//printf("%d,%.2lf,%d,%s,%s\n",allCarInfo[0].carport_id,allCarInfo[0].entry_distance,allCarInfo[0].carport_isFree,allCarInfo[0].car_id,allCarInfo[0].car_color);
	allCarInfo[wantCarportId].carport_isFree=1;//ͣ������Ϊ1������λ������
	/*�ַ�������*/
	strcpy(allCarInfo[wantCarportId].car_id,carId);
	strcpy(allCarInfo[wantCarportId].car_color,carColor);
	//�����ļ�����������Ϣ���棩-----------ͣ��������deleteCarportId������0
	lastestCarPortInfoFile(wantCarportId,allCarInfo[wantCarportId].car_id,allCarInfo[wantCarportId].car_color,0);
	printf("��������λ������ǰ��ָ����λͣ��\n");
}


///////////////2.ȡ��/////////////
/*
������
deleteCarportId:������Ҫȡ���ĳ�λ�ţ�����ţ�
*/
//��������� ���±����ļ�����lastestCarPortInfoFile()
void deleteCar(int deleteCarportId){
	if(allCarInfo[deleteCarportId-1].carport_isFree==0){
		printf("������ĳ�λ�޳���������������\n");
		return ;
	}
	allCarInfo[deleteCarportId-1].carport_isFree=0;//ȡ��������λ��Ϊ����
	/*�ַ�������*/
	strcpy(allCarInfo[deleteCarportId-1].car_id,"NULL");//��ΪNULL�����ʼֵһ��
	strcpy(allCarInfo[deleteCarportId-1].car_color,"NULL");
	//�����ļ�����������Ϣ���棩-----------ȡ��������wantCarportId������0
	lastestCarPortInfoFile(0,allCarInfo[deleteCarportId-1].car_id,allCarInfo[deleteCarportId-1].car_color,deleteCarportId);
	printf("ȡ���ɹ�\n");
}


/////////////3.��ͣ��/ȡ���������д���ļ�(ֻ���¶�Ӧ������ص�3������)/////////////
/*
carport_isFree:�Ƿ����
carId[20]:���ƺ�
carColor[20]:������ɫ
*/
//sk������ʱ����Ĭ�ϲ�����wantCarportId��deleteCarportId���Դ�������add����delete
void lastestCarPortInfoFile(int wantCarportId,char carId[20],char carColor[20],int deleteCarportId){
	FILE *fp3;
	int index=0;
	if((fp3=fopen("CarInfo.txt","w"))==NULL){
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	//printf("�ļ��򿪳ɹ�������ִ��д�����...\n");

	/*�տ�ʼ���ԡ�ֻд��һ�Σ�һ�У�������while(!feof(fp3))��
	----------���Ժ��֣�����
	--------ֻд��һ�лὫ���µ���������ֱ�Ӹ��������ļ��������Ǹ���ԭ�ļ���ĳ�е�ֵ
	--------Ӧ�ò��������ļ��������õķ����ȽϺã���Ȼ�ȽϷ���
	*/

	//allCarInfo[]��ȫ�ֱ�����add��delete֮�����ֵ����������
		
		//add
		if(wantCarportId!=0 && deleteCarportId==0){//����������ֻ����������add��������delete��������ʵ������
			/*ע�⣺д�ļ��Ľ�����������eof����Ϊ�ǲ��������*/
			//while(!feof(fp3)){
			for(index=0;index<versize-1;index++){//-1�Ǽ�ȥ0�ų�λ
				/*
				��������ʹ�ã���������ѭ����һֱ�ڸ���wantCarportId��
				fprintf(fp3,"%d,%.2lf,%d,%s %s\n",allCarInfo[wantCarportId].carport_id,allCarInfo[wantCarportId].entry_distance,allCarInfo[wantCarportId].carport_isFree,allCarInfo[wantCarportId].car_id,allCarInfo[wantCarportId].car_color);
				*/

				//��Ϊ�Ǹ��£���д�������ļ��������Ǵ�ͷ��ʼ��index=0��ʼ
				fprintf(fp3,"%d,%lf,%d,%s %s\n",allCarInfo[index].carport_id,allCarInfo[index].entry_distance,allCarInfo[index].carport_isFree,allCarInfo[index].car_id,allCarInfo[index].car_color);
				//printf();
				
			}
		//	}
		}
		
		//delete
		if(wantCarportId==0 && deleteCarportId!=0){
			/*ע�⣺д�ļ��Ľ�����������eof����Ϊ�ǲ��������*/
			//while(!feof(fp3)){
			for(index=0;index<versize-1;index++){//-1�Ǽ�ȥ0�ų�λ
				/*
				ͬ�ϣ���������ʹ�ã���������ѭ����һֱ�ڸ���deleteCarportId��
				fprintf(fp3,"%d,%.2lf,%d,%s %s\n",allCarInfo[deleteCarportId].carport_id,allCarInfo[deleteCarportId].entry_distance,allCarInfo[deleteCarportId].carport_isFree,allCarInfo[deleteCarportId].car_id,allCarInfo[deleteCarportId].car_color);
				*/
				fprintf(fp3,"%d,%.2lf,%d,%s %s\n",allCarInfo[index].carport_id,allCarInfo[index].entry_distance,allCarInfo[index].carport_isFree,allCarInfo[index].car_id,allCarInfo[index].car_color);
			
			//printf();
				
			}
			//}
		}
		printf("�ļ�д��ɹ�,������Ϣ�Ѹ���\n");
		fclose(fp3);
}













/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


/*ͼ�λ��û�����*/



/*���˵�*/
void menu_main(){
	printf("\n*****************************��ӭʹ��ͣ����·�߹滮ϵͳ************************\n");
	printf("***  1.���ļ���ȡͣ������λ��Ϣ          2.ͣ������λ��Ϣ�ṹͼ             ***\n");
	printf("***  3.��λ�����ѯ                      4. ��Ҫͣ��(����·��һ����ѯ)      ***\n");
	printf("***  5. ��Ҫȡ��                         6.��λ�ṹͼƬ                     ***\n");
	printf("***  7. �˳�ϵͳ                                                            ***\n");
	printf("*******************************************************************************\n");
}

void MenuOfSearchBest(){
	printf("\n*****************************��λ����·���ۺϲ�ѯ*****************************\n");
	printf("***  1.���ݵ�ǰλ���복λ����               2.����Ŀ�공λ���̳���ھ���   ***\n");
	printf("******************************************************************************\n");
}

void Menucarinfo(){
	printf("*****************************ͣ������λ��Ϣ�ṹͼ*******************************\n");
	printf("***  1.�ڽӾ�����ʽ���                        2. �ڽ�������ʽ���          ***\n");
	printf("***  3. ������һ�� 			       4.�˳�ϵͳ      	            ***\n");
	printf("*******************************************************************************\n");

}


void Menucarsituation(){
	printf("*****************************��λ�����ѯ**************************************\n");
	printf("***  1.����������г�λ�������Ϣ                        2. �ճ�λ��ѯ      ***\n");
	printf("***  3. �̳���ڲ�ѯ				         4.���ڳ�λ��ѯ     ***\n");
	printf("***  5.������һ�� 				         6.�˳�ϵͳ         ***\n");
	printf("*******************************************************************************\n");

}

void Menunullport(){
	printf("\n*****************************�ճ�λ��ѯ****************************************\n");
	printf("***  1.����ָ����λ�Ų�ѯ                     2.��ѯ�������пճ�λ���      ***\n");
	printf("***  3. ������һ�� 			      4.�˳�ϵͳ    	            ***\n");
	printf("*******************************************************************************\n");
}


void nullPortSelectMenu(GraphOfMatrix *G,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count){
	int op=0;
	int selectId;

	Menunullport();
	
	while(op!=6){
		printf("����ݲ˵���ʾ����ѡ�");
		scanf("%d",&op);
		switch(op){
			case 1:	//����ָ����λ�Ų�ѯ
				printf("��������Ҫ��ѯ�ĳ�λ��\n");
				scanf("%d",&selectId);
				searchNullPortOfselectId(selectId);
				printf("\n");
				Menunullport();
				break;
			case 2:	//��ѯ�������пճ�λ���
				searchNullPortOfAll();
				printf("\n");
				Menunullport();
				break;
			case 3:	//������һ��
				printf("\n");
				interface_call(G,Glist,edge,ver_arrs,ver_count,edge_count);break;
			case 4:	//�˳�ϵͳ
				printf("��ӭ�ٴ�ʹ�ø�ϵͳ���ټ�\n");
				exit(0);
			default:
				printf("�������������\n");
				scanf("%d",&op);
				break;
		}
	}


}

/*��λ��Ϣ�ṹͼ �˵�*/
void menu_carinfo(GraphOfMatrix *G,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count){
	
	int op=0;
	Menucarinfo();//����

	while(op!=6){
		printf("����ݲ˵���ʾ����ѡ�");
		scanf("%d",&op);
		switch(op){
			case 1:	//�ڽӾ������
				outputInfoOfMatrix(G,versize);
				printf("\n");
				Menucarinfo();
				break;
			case 2:	//�ڽ��������
				outputInfoOfList(Glist);
				printf("\n");
				Menucarinfo();
				break;
			case 3:	//������һ��
				printf("\n");
				interface_call(G,Glist,edge,ver_arrs,ver_count,edge_count);break;
			case 4:	//�˳�ϵͳ
				printf("��ӭ�ٴ�ʹ�ø�ϵͳ���ټ�\n");
				exit(0);
			default:
				printf("�������������\n");
				scanf("%d",&op);
				break;
		}
	}
}

/*��λ�����ѯ �˵�*/
void menu_carsituation(GraphOfMatrix *G,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count){
	int op=0;
	int selectId;
	int currentCarPortId;


	Menucarsituation();
	
	while(op!=6){
		printf("����ݲ˵���ʾ����ѡ�");
		scanf("%d",&op);
		switch(op){
			case 1:	//����������г�λ�������Ϣ
				outputCarportInfo();
				printf("\n");
				Menucarsituation();
				break;
			case 2:	//�ճ�λ��ѯ
				nullPortSelectMenu(G,Glist,edge,ver_arrs,ver_count,edge_count);
				break;
			case 3:	//�̳���ڲ�ѯ
				searchMarketEntry(G,ver_arrs);
				printf("\n");
				Menucarsituation();
				break;
			case 4:	//���ڳ�λ��ѯ
				printf("�����뵱ǰ��λ�ţ�");
				scanf("%d",&currentCarPortId);
				searchNextPort(G,currentCarPortId);
				Menucarsituation();
				break;
			case 5:	//������һ��
				printf("\n");
				interface_call(G,Glist,edge,ver_arrs,ver_count,edge_count);break;
			case 6:	//�˳�ϵͳ
				printf("��ӭ�ٴ�ʹ�ø�ϵͳ���ټ�\n");
				exit(0);
			default:
				printf("�������������\n");
				scanf("%d",&op);
				break;
		}
	}

}


/*�˵�ѡ�����*/
void interface_call(GraphOfMatrix *G,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count){
	int op=0;//ѡ��
	int deletecarid=0;
	char carId[20];//���ƺ�
	char carColor[20];//������ɫ
	int test=-1;
	menu_main();
	
	
	while(op!=6){
		printf("����ݲ˵���ʾ����ѡ�");
		scanf("%d",&op);
		switch(op){
			case 1:	//���ļ��ж�ȡ��λ��Ϣ(�ṹ��Ϣ+��λ������Ϣ)����ȡ�����ļ���
				readCartport(G,Glist,edge,ver_arrs,ver_count,edge_count);
				readCarInfo();
				printf("\n");
				menu_main();
				break;
			case 2:	//����ͣ������λ��Ϣ�ṹͼ�˵�
				menu_carinfo(G,Glist,edge,ver_arrs,ver_count,edge_count);break;
			case 3:	//���ó�λ�����ѯ�˵�
				menu_carsituation(G,Glist,edge,ver_arrs,ver_count,edge_count);break;
			case 4:	//��Ҫͣ��(����·��һ����ѯ)
				printf("���������ĳ��ƺš�������ɫ:");
				scanf("%s%s",carId,carColor);
				addCar(G,carId,carColor,ver_arrs);
				menu_main();
				//searchBestRoad();��addCar()�����������·�߲�ѯ������ѯ���Ķ���Ŵ���addCar()��
				break;
			case 5:	//��Ҫȡ��
				printf("��������ͣ���ĳ�λ�ţ�");
				scanf("%d",&deletecarid);
				deleteCar(deletecarid);
				printf("\n");
				menu_main();
				break;

			case 6:	//��λ�ṹͼƬ
				test=outputCarportOfPic();
				if(test=1) interface_call(G,Glist,edge,ver_arrs,ver_count,edge_count);
				break;
			case 7:	//�˳�ϵͳ
				printf("��ӭ�ٴ�ʹ�ø�ϵͳ���ټ�\n");
				exit(0);
			default:
				printf("�������������\n");
				scanf("%d",&op);
				break;
		}
	}

}