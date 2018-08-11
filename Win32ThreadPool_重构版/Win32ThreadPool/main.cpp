
//		Win-Thread-Pool
// https://www.codeproject.com/Articles/11976/Win-Thread-Pool

#include "ThreadPool.h"
#include <stdlib.h>

struct CTaskOne :ThreadPool::IRunObject
{
	CTaskOne()
	{

	}
	virtual ~CTaskOne()
	{
		printf("����\n");
	}
	virtual void Run()
	{
		printf("Ok\n");
		Sleep(300); // ģ��ִ������
	}
	// �Ƿ����̳߳�ִ���̸߳���ɾ��
	virtual bool AutoDelete()
	{
		return true;
	}
};

int main(int agrc,char* agrv)
{
	ThreadPool* pThreadPool = new ThreadPool(5);
	for (int i=0;i<10;i++)
	{
		ThreadPool::IRunObject* pTask = new CTaskOne();
		pThreadPool->Run(pTask);
	}
	Sleep(1000);
	pThreadPool->Destroy();
	delete pThreadPool;
	return 0;
}
