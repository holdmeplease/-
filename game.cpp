#include<time.h>
#include<Windows.h>
#include"game.h"

int card_front;//��ǰ�ƶ�λ��
int card_end;//�ƶ�ĩβλ��
int curr_player;//��ǰ���
int desk_pos;//��������ж�����
bool just_peng;//�ղ��Ƿ�������,Ӱ��������Ƶ�����

GAME game;

//ð������������������
void BubbleSort(int array[], int n)  
{  
    int temp;
	for (int i = 0; i < n-1; i++)  
    {  
        for (int j = i + 1; j < n-1; j++)  
        {  
            if (array[i]>array[j])  
			{
				temp = array[i];  
				array[i] = array[j];  
                array[j] = temp; 
			}  
        }  
    }  
}  

//ϴ���㷨
void random(int a[], int n)  
{  
   int index, tmp, i;  
   srand(unsigned(time(NULL)));    
    for(i=n-1; i>0; i--)  
    {  
        index=rand()%i;  
        tmp=a[i];  
        a[i]=a[index];  
        a[index]=tmp;  
    }  
}

//����,��һЩ��Ҫ�������г�ʼ��
void deal_card() 
{
    card_front=0;//��ǰ�ƶ�λ��
    card_end=131;//�ƶ�ĩβλ��
    curr_player=1;//��ǰ���
    desk_pos=0;//��������ж�����
	just_peng=0;
	for(int i=0;i<4;i++)
	{
		game.player[i].hand=13;
		game.player[i].hand_locked=0;
	}
	for(int i=0,j=0;i<33;i++,j++)
	{
		if((j+1)%10==0)
			j++;
		game.card_new[i]=j+1;
	}
	for(int i=33;i<132;i++)
		game.card_new[i]=game.card_new[i%33];
	random(game.card_new,132);//ϴ��
	for(int i=0;i<13;i++)
	{
		game.player[0].card_hand[i]=game.card_new[i];
	}
	for(int i=13;i<26;i++)
	{
		game.player[1].card_hand[i%13]=game.card_new[i];
	}
	for(int i=26;i<39;i++)
	{
		game.player[2].card_hand[i%13]=game.card_new[i];
	}
	for(int i=39;i<52;i++)
	{
		game.player[3].card_hand[i%13]=game.card_new[i];
	}
	for(int i=0;i<52;i++)
		game.card_new[i]=0;
	card_front=52;
}