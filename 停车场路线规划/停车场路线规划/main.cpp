/*������*/


#include"implementation.h"
//#include"G_Interface.h"

int main(){
	GraphOfMatrix Gr;
	//GraphOfMatrix G;
	GraphOfList Glist;
	/*����ver_count,edge_count����Ϊһ��ͣ�����ĳ�λ����λ����Թ̶���һ�㲻�������ʱ������λ�������*/
	int i,j,ver_count=19,edge_count=52;//ver_countΪʵ�ʶ������;edge_countΪ������(18�����㣬52����)
	//int ver_arrs[MAXVERTICES];//MAXVERTICESΪͼ����󶥵����
	//rowcolweight edge[]={{0,1,10},{0,2,6},{0,3,15},{1,4,7},{2,4,12},{2,5,7},{3,6,16},{4,7,9},{5,6,3},{6,7,6}};//8�����㣬10����
	rowcolweight edge[200];
	//int ver_arrs[]={1,2,3,4,5,6,7,8};//8������
	int ver_arrs[200];
	char user_name[50];
	char password[50];
	int flag=0;
	//int readCartport(GraphOfMatrix *Gr,GraphOfList *Glist,rowcolweight edge[200],int ver_arrs[200],int ver_count,int edge_count)
	//readCartport(&Gr,&Glist,edge,ver_arrs,ver_count,edge_count);
	//////////////////////////////
	//�ڽӾ���
	/////////////////////////////

	
	//����ͼ
	//init(&Gr,ver_count);
	//creat_graph(&Gr,ver_arrs,ver_count,edge,edge_count);
	//creat_graph_link(&Glist,ver_arrs,ver_count,edge,edge_count);//List
	//printf("main����ִ�� outputInfoOfMatrix(&Gr) ����\n");
	//outputInfoOfMatrix(&Gr,versize);
	//printf("\n\n");
	//readCarInfo();
	//addCar(carId,carColor);//����





	printf("��ӭʹ��ͣ����·�߹滮ϵͳ\n");
	printf("�������û���:");
	scanf("%s",user_name);
	printf("����������:");
	scanf("%s",password);
	while(!flag){
		if((!strcmp(user_name,"cars")) && (!strcmp(password,"123456"))){//�ַ�����ͬ����0
			interface_call(&Gr,&Glist,edge,ver_arrs,ver_count,edge_count);
			flag=1;
			break;
		}
		else{
			printf("�û����������������,����������\n");
			printf("�������û���:");
			scanf("%s",user_name);
			printf("����������:");
			scanf("%s",password);
		}
	}

	
	
	return 0;
}