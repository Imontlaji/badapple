#include <iostream> 
#include <windows.h>
#include <mmsystem.h>
#include <fstream>
#include <string>
using namespace std;
string BAtext[106600] ;//106590/30=3553
bool readBadApple() ;
int main()
{ 
    SetConsoleTitle("BadApple Please wait...");	
	if(!readBadApple()) return 0;//�����ȡʧ����ֱ�ӷ��� 
	reset_hwnd://����Hwnd 
   	int iHwnd;
	HWND mHwnd;
	//-----�ȴ����� Hwnd 
	SetConsoleTitle("BadApple Wait Hwnd...");
    cout<<"Hwnd��";
	cin>>iHwnd;//����Hwnd 
	mHwnd= (HWND)iHwnd;//��������Hwndת��ΪHWND�� 
	if(!IsWindow(mHwnd))//�ж��Ƿ���Ч���ھ�� 
	{
		cout<<"Hwnd����"<<endl; 
		goto reset_hwnd; //��������ת��reset_hwnd 
	} 
	SetConsoleTitle("BadApple Wait...");
	//-----�ȴ����� Y
	cout<<"Run [Y]��";
	char input;
	cin>>input;
    if(input != 'Y')  return 0;//�������Ĳ���Yֱ�ӷ��� 
    //-----��ʼ���� 
	cout<<"��ʼ��"<<endl;//��ʼ����ַ��� 
	sndPlaySound ("g:\\BadApple.wav", SND_ASYNC | SND_NODEFAULT);//�����ļ�·�� SND_ASYNC�첽 SND_SYNCͬ�� 
	string frame;
	SetConsoleTitle("BadApple Playing...");
	for (int a=0; a<3553; a=a+1)//�����3553֡ 
	{
		frame = "";
		for (int countk=0; countk<30; countk=countk+1)//30��Ϊһ֡ ����Ҫ��30�е��ı����Ϊһ֡ Ȼ����� 
		{
			frame = frame + BAtext [a*30+countk] + "\n" ;//����ı� 
		}
		SendMessageA (mHwnd, 12, (WPARAM) 0, LPARAM(temp.c_str()));//������Ϣ ���һ֡���ı� 
		Sleep(55);//ÿ֡��ʱ �����Ƶ���������ʱ���� ���˷�֮ 
	}
	//-----��������
	SetConsoleTitle("BadApple End");
	cout<<"End";
	return 0; 
}
//��ȡ�ı����� 
bool readBadApple()
{
	string line;//ÿһ���ı� 
    int count; //���� 
    ifstream in("g:\\Bad apple data.txt");//�����ı� "g:\\Bad apple data.txt"Ϊ�ı��ļ�����·�� 
    if (in) //�Ƿ��ȡ�ɹ� 
    {    
	    while(getline(in,line))//ѭ����ȡ 
        {	
        	BAtext [count] = line ; )//�����鸳ֵ 
        	count++; //�������� 
        }
   	}
   	else
   	{
   	    return false;//���ȡʧ���򷵻�false 
	}
   	
}