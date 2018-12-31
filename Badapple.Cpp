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
	if(!readBadApple()) return 0;//如果读取失败则直接返回 
	reset_hwnd://重置Hwnd 
   	int iHwnd;
	HWND mHwnd;
	//-----等待输入 Hwnd 
	SetConsoleTitle("BadApple Wait Hwnd...");
    cout<<"Hwnd：";
	cin>>iHwnd;//输入Hwnd 
	mHwnd= (HWND)iHwnd;//将整数的Hwnd转换为HWND型 
	if(!IsWindow(mHwnd))//判断是否有效窗口句柄 
	{
		cout<<"Hwnd错误"<<endl; 
		goto reset_hwnd; //错误则跳转到reset_hwnd 
	} 
	SetConsoleTitle("BadApple Wait...");
	//-----等待输入 Y
	cout<<"Run [Y]：";
	char input;
	cin>>input;
    if(input != 'Y')  return 0;//如果输入的不是Y直接返回 
    //-----开始运行 
	cout<<"开始！"<<endl;//开始输出字符画 
	sndPlaySound ("g:\\BadApple.wav", SND_ASYNC | SND_NODEFAULT);//歌曲文件路径 SND_ASYNC异步 SND_SYNC同步 
	string frame;
	SetConsoleTitle("BadApple Playing...");
	for (int a=0; a<3553; a=a+1)//共输出3553帧 
	{
		frame = "";
		for (int countk=0; countk<30; countk=countk+1)//30行为一帧 所以要把30行的文本组合为一帧 然后输出 
		{
			frame = frame + BAtext [a*30+countk] + "\n" ;//组合文本 
		}
		SendMessageA (mHwnd, 12, (WPARAM) 0, LPARAM(temp.c_str()));//发送信息 输出一帧的文本 
		Sleep(55);//每帧延时 如果音频快了则把延时调低 慢了反之 
	}
	//-----结束运行
	SetConsoleTitle("BadApple End");
	cout<<"End";
	return 0; 
}
//读取文本数据 
bool readBadApple()
{
	string line;//每一行文本 
    int count; //行数 
    ifstream in("g:\\Bad apple data.txt");//读入文本 "g:\\Bad apple data.txt"为文本文件所在路径 
    if (in) //是否读取成功 
    {    
	    while(getline(in,line))//循环读取 
        {	
        	BAtext [count] = line ; )//给数组赋值 
        	count++; //行数增加 
        }
   	}
   	else
   	{
   	    return false;//如读取失败则返回false 
	}
   	
}
