#include<Windows.h>
#pragma once

extern HWND hwnd;
extern HDC hdc;
extern HDC hdcmem;
extern HBITMAP hbitmap;
extern HBRUSH hbrush;

void paint_card_hand(int); //�����������
void paint_card_desk(int,int,int);//���������ϵ���
void paint_card_computer();//���Ƶ�������
void paint_name();//���������ϵľ��ο�͡����ԡ�������ҡ�����
void paint_word(int);//������������
void paint_result(int);//������Ϸ���
void paint_do(int);//�������ƵȲ���ͼ��
void paint_card_locked();//��������
void paint_computer_end();//��Ϸ��������Ƶ���������

