#pragma once

//ö����Ϸ���ȣ����ڲ�ͬ����µ��û���ˢ��
enum MOMENT{
	create,//��Ϸ��ʼ��
	before_start,//��Ϸδ��ʼ
	playing,//���Գ��ƽ׶�
	human,//��ҳ��ƽ׶�
	human_peng,//�������
	human_gang,//�������(���˳���)
	human_gang_black,//��Ұ���
	human_gang_white,//�������(�Լ�����)
	human_hu,//��Һ���
	game_over,//��Ϸ����(�����ʤ��)
	no_winner //��Ϸ����(����ʤ��)
};
extern MOMENT moment;