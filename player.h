#pragma once

//�����
class PLAYER{
public:
	int score;//����
	bool isbacker;//ׯ��
	int card_hand[14];//����
	int card_hand_locked[16];//����
	int hand; //��������
	int hand_locked; //��������
};

bool Hu(int*);//���Ƶ��ж�
bool is_hu(int,int);//�Ƿ���Ϻ�������
bool is_peng(int,int*,int);//�Ƿ������������
bool is_gang(int,int*,int);//�Ƿ������������(���˳���)
bool is_gang_white(int,int);//�Ƿ������������(�Լ�����)
bool is_gang_black(int,int*);//�Ƿ���ϰ�������
void peng_computer(int);//��������
void gang_computer(int);//�����������
void hu_computer(int);//������Һ���
void gang_human();//�����������(���˳���)
void gang_human_white();//�����������(�Լ�����)
void gang_human_black();//������Ұ���
void peng_human();//�����������
void hu_human();//�������ƽ��
void discard_computer(int,int);//���Գ���
void Getcard_computer(int);//��������
void Getcard_human();//�����������
void discard_human(int);//������ҳ���
void gang_computer_white(int);//��������(�Լ�����)
void gang_computer_black(int pnum);//���԰���(�Լ�����)
void sound_card(int);//���ų�����Ч(ͬ����ʽ)
void sound_do(int);//���Ų�����Ч(ͬ����ʽ)
void sound_do_human(int);//���Ų�����Ч(�첽��ʽ)
void sound_card_human(int);//���ų�����Ч(�첽��ʽ)