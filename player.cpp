#include"player.h"
#include"game.h"
#include"main.h"
#include"scene.h"
#pragma comment(lib, "winmm") 

//���Ƶ��ж�
 bool Hu(int b[])
{
	 int i,j,k,x,flat=0;
     int a[14]={0};
     for(i=0; i<14; i++)
             a[i]=b[i];

     for (x=0; x<13; x++)  //���������λ�ü�һ�������������ж��Ƿ�ȫ����0
    {
         if(a[x]==a[x+1]&& a[x]!=0 )//�ı���ԣ���������
        {          
           a[x]=0;
           a[x+1]=0;
         }
        else continue;
      
         for(i=0; i<14; i++)                     //�ҳ���������ͬ���������������Ϊ0
            for(j=0; j<14; j++)
                 for(k=0; k<14; k++) 
                 {
                     if(i==j||j==k||i==k) continue;
                     if( a[i]==a[j] && a[k]==a[j]||a[i]+1==a[j] && a[j]+1==a[k]&& a[i]!=0  )
                     {
                         a[i]=0; a[j]=0; a[k]=0;
                     }
                 }             
                 int    s=0; 
                 for(i=0;i<14;i++) 
                   {
                 s+=a[i];
                     }
                if(s!=0) //���ӵĽ����������´���������ʱ����ԭֵ��
                {
                          for(i=0; i<14; i++)
                          a[i]=b[i];
                 
                 }
                if(s==0)
                 {
                    flat=1;
                    break;
                 }
    }
           if(flat)  
			   return 1;
           else     return 0;
}

 //�Ƿ���Ϻ�������
bool is_hu(int pnum,int c)
{
	int judge[14];
	for(int ii=0;ii<game.player[pnum].hand;ii++)
		judge[ii]=game.player[pnum].card_hand[ii];
	judge[game.player[pnum].hand]=c;
	for(int ii=game.player[pnum].hand+1;ii<14;ii++)
		judge[ii]=37;
	BubbleSort(judge,15) ;
	return Hu(judge);
}

//�Ƿ������������
bool is_peng(int pnum,int array[],int c)
{
	int flag=0;
	for(int i=0;i<game.player[pnum].hand;i++)
		if(array[i]==c)
			flag++;
	if(flag==2)
		return TRUE;
	else return FALSE;
}

//�Ƿ������������(���˳���)
bool is_gang(int pnum,int array[],int c)
{
	int flag=0;
	for(int i=0;i<game.player[pnum].hand;i++)
		if(array[i]==c)
			flag++;
	if(flag==3)
		return TRUE;
	else return FALSE;
}

//�Ƿ������������(�Լ�����)
bool is_gang_white(int pnum,int c)
{
	int flag=0;
	for(int i=0;i<game.player[pnum].hand_locked;i++)
		if(game.player[pnum].card_hand_locked[i]==c)
			flag++;
	if(flag==3)
		return TRUE;
	else return FALSE;
}

//�Ƿ���ϰ�������
bool is_gang_black(int pnum,int array[])
{
	int flag=0;
	for(int i=0;i<game.player[pnum].hand;i++)
		if(array[i]==array[game.player[pnum].hand])
			flag++;
	if(flag==3)
		return TRUE;
	else return FALSE;
}

//��������
void peng_computer(int pnum)
{
	int _end=game.player[pnum].hand;
	curr_player=pnum;
	for(int i=0,flag=0;i<_end,flag<2;i++)
		if(game.player[pnum].card_hand[i]==game.card_desk[desk_pos-1])
		{
			game.player[pnum].card_hand_locked[game.player[pnum].hand_locked]=game.card_desk[desk_pos-1];
			game.player[pnum].card_hand[i]=game.player[pnum].card_hand[game.player[pnum].hand-1];
			game.player[pnum].hand--;
			game.player[pnum].hand_locked++;
			flag++;
		}
	game.player[pnum].card_hand_locked[game.player[pnum].hand_locked]=game.card_desk[desk_pos-1];
	game.player[pnum].hand--;
	game.player[pnum].hand_locked++;
	desk_pos--;
	sound_do_human(1);
}

//��������(���˳���)
void gang_computer(int pnum)
{
	int _end=game.player[pnum].hand;
	curr_player=pnum;
	for(int i=0,flag=0;i<_end,flag<3;i++)
		if(game.player[pnum].card_hand[i]==game.card_desk[desk_pos-1])
		{
			game.player[pnum].card_hand_locked[game.player[pnum].hand_locked]=game.card_desk[desk_pos-1];
			game.player[pnum].card_hand[i]=game.player[pnum].card_hand[game.player[pnum].hand-1];
			game.player[pnum].hand--;
			game.player[pnum].hand_locked++;
			flag++;
		}
	game.player[pnum].card_hand_locked[game.player[pnum].hand_locked]=game.card_desk[desk_pos-1];
	game.player[pnum].card_hand[game.player[pnum].hand]=game.card_new[card_end]; //����β����
	card_end--;
	game.player[pnum].hand_locked++;
	desk_pos--;
	sound_do_human(2);
}

//��������(�Լ�����)
void gang_computer_white(int pnum)
{
	curr_player=pnum;
	game.player[pnum].card_hand_locked[game.player[pnum].hand_locked]=game.player[pnum].card_hand[game.player[pnum].hand];
	game.player[pnum].hand_locked++;
	BubbleSort(game.player[pnum].card_hand_locked,game.player[pnum].hand_locked+1);
	game.player[pnum].card_hand[game.player[pnum].hand]=game.card_new[card_end];
	card_end--;
	sound_do_human(2);
}

//���԰���(�Լ�����)
void gang_computer_black(int pnum)
{
	int _end=game.player[pnum].hand;
	curr_player=pnum;
	int c=game.player[pnum].card_hand[game.player[pnum].hand];
	for(int i=0,flag=0;i<_end,flag<3;i++)
		if(game.player[pnum].card_hand[i]==c)
		{
			game.player[pnum].card_hand_locked[game.player[pnum].hand_locked]=c;
			game.player[pnum].card_hand[i]=game.player[pnum].card_hand[game.player[pnum].hand-1];
			game.player[pnum].hand--;
			game.player[pnum].hand_locked++;
			flag++;
		}
	game.player[pnum].card_hand_locked[game.player[pnum].hand_locked]=c;
	game.player[pnum].card_hand[game.player[pnum].hand]=game.card_new[card_end]; //����β����
	card_end--;
	game.player[pnum].hand_locked++;
	sound_do_human(2);
}

//�������ƽ��
void hu_computer(int pnum)
{
	curr_player=pnum;
	game.player[pnum].card_hand[game.player[pnum].hand]=game.card_desk[desk_pos-1];
	desk_pos--;
	sound_do_human(3);
}

//�����������(���˳���)
void gang_human()
{
	int _end=game.player[0].hand;
	curr_player=0;
	for(int i=0,flag=0;i<_end,flag<3;i++)
		if(game.player[0].card_hand[i]==game.card_desk[desk_pos-1])
		{
			game.player[0].card_hand_locked[game.player[0].hand_locked]=game.card_desk[desk_pos-1];
			game.player[0].card_hand[i]=game.player[0].card_hand[game.player[0].hand-1];
			game.player[0].hand--;
			game.player[0].hand_locked++;
			flag++;
		}
	game.player[0].card_hand_locked[game.player[0].hand_locked]=game.card_desk[desk_pos-1];
	game.player[0].card_hand[game.player[0].hand]=game.card_new[card_end]; //����β����
	card_end--;
	game.player[0].hand_locked++;
	desk_pos--;
}

//�����������(�Լ�����)
void gang_human_white()
{
	curr_player=0;
	game.player[0].card_hand_locked[game.player[0].hand_locked]=game.player[0].card_hand[game.player[0].hand];
	game.player[0].hand_locked++;
	BubbleSort(game.player[0].card_hand_locked,game.player[0].hand_locked+1);
	game.player[0].card_hand[game.player[0].hand]=game.card_new[card_end];
	card_end--;
}

//������Ұ���
void gang_human_black()
{
	int _end=game.player[0].hand;
	curr_player=0;
	int c=game.player[0].card_hand[game.player[0].hand];
	for(int i=0,flag=0;i<_end,flag<3;i++)
		if(game.player[0].card_hand[i]==c)
		{
			game.player[0].card_hand_locked[game.player[0].hand_locked]=c;
			game.player[0].card_hand[i]=game.player[0].card_hand[game.player[0].hand-1];
			game.player[0].hand--;
			game.player[0].hand_locked++;
			flag++;
		}
	game.player[0].card_hand_locked[game.player[0].hand_locked]=c;
	game.player[0].card_hand[game.player[0].hand]=game.card_new[card_end]; //����β����
	card_end--;
	game.player[0].hand_locked++;
}

//�����������
void peng_human()
{
	int _end=game.player[0].hand;
	curr_player=0;
	just_peng=1;
	for(int i=0,flag=0;i<_end,flag<2;i++)
		if(game.player[0].card_hand[i]==game.card_desk[desk_pos-1])
		{
			game.player[0].card_hand_locked[game.player[0].hand_locked]=game.card_desk[desk_pos-1];
			game.player[0].card_hand[i]=game.player[0].card_hand[game.player[0].hand-1];
			game.player[0].hand--;
			game.player[0].hand_locked++;
			flag++;
		}
	game.player[0].card_hand_locked[game.player[0].hand_locked]=game.card_desk[desk_pos-1];
	game.player[0].hand--;
	game.player[0].hand_locked++;
	desk_pos--;
}

//�������ƽ��
void hu_human()
{
	curr_player=0;
	game.player[0].card_hand[game.player[0].hand]=game.card_desk[desk_pos-1];
	desk_pos--;
}

//���Գ���
void discard_computer(int pnum,int cnum)
{
	game.card_desk[desk_pos]=game.player[pnum].card_hand[game.player[pnum].hand];
	sound_card_human(game.card_desk[desk_pos]);
	game.player[pnum].card_hand[game.player[pnum].hand]=0;
	desk_pos++;
	for(int i=curr_player+1;i<curr_player+4;i++)
	{
		if(is_hu((i)%4,game.card_desk[desk_pos-1]))
		{
			if((i)%4==0)
			{
				moment=human_hu;
				InvalidateRect(hwnd,NULL,1);
				return;
			}
			else
			{    
				hu_computer(i%4);
				moment=game_over;
				InvalidateRect(hwnd,NULL,1);
				return;
			}
		}
	}
	for(int i=curr_player+1;i<curr_player+4;i++)
	{
		if(is_gang(i%4,game.player[i%4].card_hand,game.card_desk[desk_pos-1]))
		{
			if(i%4==0)
			{
				moment=human_gang;
				InvalidateRect(hwnd,NULL,1);
				return;
			}
			else
			{
				gang_computer(i%4);
				discard_computer(curr_player,0);
				moment=playing;
				InvalidateRect(hwnd,NULL,1);
				return;
			}
		}
	}
	for(int i=curr_player+1;i<curr_player+4;i++)
	{
		if(is_peng(i%4,game.player[i%4].card_hand,game.card_desk[desk_pos-1]))
		{
			if(i%4==0)
			{
				moment=human_peng;
				InvalidateRect(hwnd,NULL,1);
				return;
			}
			else
			{
				peng_computer(i%4);
				discard_computer(curr_player,0);
				moment=playing;
				InvalidateRect(hwnd,NULL,1);
				return;
			}
		}
	}
}

//��������
void Getcard_computer(int pnum)
{
		if(card_front>card_end)
		{
			moment=no_winner;
			InvalidateRect(hwnd,NULL,1);
		}
		curr_player=pnum;
	    game.player[pnum].card_hand[game.player[pnum].hand]=game.card_new[card_front];
	    card_front++;
		if(is_hu(pnum,game.player[pnum].card_hand[game.player[pnum].hand]))
	    {
			moment=game_over;
		    InvalidateRect(hwnd,NULL,1);
			sound_do_human(3);
		    return;
	    }
		if(is_gang_black(pnum,game.player[pnum].card_hand))
	    {
		    gang_computer_black(pnum);
			discard_computer(pnum,0);
			moment=playing;
		    InvalidateRect(hwnd,NULL,1);
		    return;
	    }
	    if(is_gang_white(pnum,game.player[pnum].card_hand[game.player[pnum].hand]))
	    {
		    gang_computer_white(pnum);
			discard_computer(pnum,0);
			moment=playing;
		    InvalidateRect(hwnd,NULL,1);
		    return;
	    }
		discard_computer(pnum,game.player[pnum].hand);
}

//�����������
void Getcard_human()
{
	if(card_front>card_end)
	{
		moment=no_winner;
		InvalidateRect(hwnd,NULL,1);
		return;
	}
	curr_player=0;
	game.player[0].card_hand[game.player[0].hand]=game.card_new[card_front];
	card_front++;
	if(is_hu(0,game.player[0].card_hand[game.player[0].hand]))
	{
		moment=human_hu;
		InvalidateRect(hwnd,NULL,1);
		return;
	}
	if(is_gang_black(0,game.player[0].card_hand))
	{
		moment=human_gang_black;
		InvalidateRect(hwnd,NULL,1);
		return;
	}
	if(is_gang_white(0,game.player[0].card_hand[game.player[0].hand]))
	{
		moment=human_gang_white;
		InvalidateRect(hwnd,NULL,1);
		return;
	}
}

//������ҳ���
void discard_human(int pos)
{
	game.card_desk[desk_pos]=game.player[0].card_hand[pos];	
	game.player[0].card_hand[pos]=game.player[0].card_hand[game.player[0].hand];
	game.player[0].card_hand[game.player[0].hand]=0;
	desk_pos++;	
}

//���ų�����Ч(�첽��ʽ)
void sound_card_human(int i)
{
	switch(i)
	{
	case 1:
		PlaySound("sound\\һ��.wav",NULL,SND_ASYNC);
		break;
	case 2:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 3:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 4:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 5:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 6:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 7:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 8:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 9:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 11:
		PlaySound("sound\\һ��.wav",NULL,SND_ASYNC);
		break;
	case 12:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 13:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 14:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 15:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 16:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 17:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 18:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 19:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 21:
		PlaySound("sound\\һͲ.wav",NULL,SND_ASYNC);
		break;
	case 22:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_ASYNC);
		break;
	case 23:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_ASYNC);
		break;
	case 24:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_ASYNC);
		break;
	case 25:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_ASYNC);
		break;
	case 26:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_ASYNC);
		break;
	case 27:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_ASYNC);
		break;
	case 28:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_ASYNC);
		break;
	case 29:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_ASYNC);
		break;
	case 31:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 32:
		PlaySound("sound\\�Ϸ�.wav",NULL,SND_ASYNC);
		break;
	case 33:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 34:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 35:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	case 36:
		PlaySound("sound\\����.wav",NULL,SND_ASYNC);
		break;
	default:
		break;
	}
}

//���ų�����Ч(ͬ����ʽ)
void sound_card(int i)
{
	switch(i)
	{
	case 1:
		PlaySound("sound\\һ��.wav",NULL,SND_SYNC);
		break;
	case 2:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 3:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 4:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 5:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 6:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 7:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 8:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 9:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 11:
		PlaySound("sound\\һ��.wav",NULL,SND_SYNC);
		break;
	case 12:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 13:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 14:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 15:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 16:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 17:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 18:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 19:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 21:
		PlaySound("sound\\һͲ.wav",NULL,SND_SYNC);
		break;
	case 22:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_SYNC);
		break;
	case 23:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_SYNC);
		break;
	case 24:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_SYNC);
		break;
	case 25:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_SYNC);
		break;
	case 26:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_SYNC);
		break;
	case 27:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_SYNC);
		break;
	case 28:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_SYNC);
		break;
	case 29:
		PlaySound("sound\\��Ͳ.wav",NULL,SND_SYNC);
		break;
	case 31:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 32:
		PlaySound("sound\\�Ϸ�.wav",NULL,SND_SYNC);
		break;
	case 33:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 34:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 35:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	case 36:
		PlaySound("sound\\����.wav",NULL,SND_SYNC);
		break;
	default:
		break;
	}
}

//���Ų�����Ч(ͬ����ʽ)
void sound_do(int i)
{
	switch(i)
	{
	case 1:
		PlaySound("sound\\��.wav",NULL,SND_SYNC);
		break;
	case 2:
		PlaySound("sound\\��.wav",NULL,SND_SYNC);
		break;
	case 3:
		PlaySound("sound\\��.wav",NULL,SND_SYNC);
		break;
	default:
		break;
	}
}

//���Ų�����Ч(�첽��ʽ)
void sound_do_human(int i)
{
	switch(i)
	{
	case 1:
		PlaySound("sound\\��.wav",NULL,SND_ASYNC);
		break;
	case 2:
		PlaySound("sound\\��.wav",NULL,SND_ASYNC);
		break;
	case 3:
		PlaySound("sound\\��.wav",NULL,SND_ASYNC);
		break;
	default:
		break;
	}
}