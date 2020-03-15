#include "FileProcess.h"
using namespace std;

string file::GetFilePathByGUI(CommandInfo commandInfo)
{
	string filePath = getFilePathByGUI().GetBuffer(0);
	ifstream file;
	file.open(filePath, ios::in);
	if (!file.is_open())
	{
		commandInfo.HasError(fileError);
		exit(-1);
	}
	file.close();
	return filePath;
}

CString file::getFilePathByGUI()
{
	CString path;
	OPENFILENAME open;// 公共对话框结构。
	char file[MAX_PATH];// 用来保存获取文件名称的缓冲区。 
	ZeroMemory(&open, sizeof(OPENFILENAME)); // 初始化选择文件对话框
	open.lStructSize = sizeof(OPENFILENAME);//指定这个结构的大小，以字节为单位。
	open.lpstrFile = file;//打开的文件的全路径
	open.lpstrTitle = "选择文件";//窗口的标题
	open.lpstrFile[0] = '\0'; //第一个字符串是过滤器描述的显示字符串
	open.nMaxFile = MAX_PATH;  //指定lpstrFile缓冲的大小，以TCHARs为单位
	open.lpstrFilter = "文本文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*\0\0";  //打开文件类型
	open.nFilterIndex = 1;  //指定在文件类型控件中当前选择的过滤器的索引
	open.lpstrFileTitle = NULL; // 指向接收选择的文件的文件名和扩展名的缓冲（不带路径信息）。这个成员可以是NULL。
	open.nMaxFileTitle = 0;  //指定lpstrFileTitle缓冲的大小，以TCHARs为单位
	open.lpstrInitialDir = NULL;  //指向以空字符结束的字符串，可以在这个字符串中指定初始目录。
	open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;//位标记的设置，你可以使用来初始化对话框
	if (GetOpenFileName(&open))  // 显示打开选择文件对话框。  
	{
		path = file;
		cout<<path + "\n";
	}
	return path;
}
