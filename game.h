#include"player.h"
#pragma once

extern int card_front;//��ǰ�ƶ�λ��
extern int card_end;//�ƶ�ĩβλ��
extern int curr_player;//��ǰ���
extern int desk_pos;//��������ж�����
extern bool just_peng;//�ղ��Ƿ�������,Ӱ��������Ƶ�����

//��Ϸ��
class GAME{
public:
	int card_new[132]; //�ƶ�
	int card_desk[132];//��������
	PLAYER player[4]; //player[0]��ʾ�������
	int backer;//ׯ��
};
extern GAME game;

void BubbleSort(int*,int);//ð������������������
void random(int*,int);//ϴ���㷨
void deal_card();//����,��һЩ��Ҫ�������г�ʼ��
