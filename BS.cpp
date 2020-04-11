#include<iostream>
#include<string>

using namespace std;

string res[2] = { "zannen","omedetou" };


template <class T>
class Optional {    //盒子模板类定义
private:
	T content;  //盒子内容
	bool isEmpty;
public:
	Optional() {
		isEmpty = 1;
	};
	bool exists() const
	{
		return isEmpty;
	};    //判断盒子是否为空
	void clear()
	{
		isEmpty = 1;
	};   //清空盒子
	void set(const T& t)
	{
		if (!isEmpty)return;
		content = t;
		isEmpty = 0;
	};   //放入物品
	void change(const T&t)
	{
		if (isEmpty)return;
		else content = t;
	}
	T get() const
	{
		return content;
	};  //获取盒子中的物品
};

int main(void)
{
	Optional<int>A;
	Optional<double>B;
	Optional<string>C;
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		int man;
		cin >> man;
		if (man == 1)
		{
			char box;
			cin >> box;
			int op;
			cin >> op;
			if (box == 'A')
			{
				if (op == 1)A.clear();
				if (op == 2)
				{
					int opr;
					cin >> opr;
					A.set(opr);
				}
				if (op == 3)
				{
					int opr;
					cin >> opr;
					A.change(opr);
				}
			}
			if (box == 'B')
			{
				if (op == 1)B.clear();
				if (op == 2)
				{
					double opr;
					cin >> opr;
					B.set(opr);
				}
				if (op == 3)
				{
					double opr;
					cin >> opr;
					B.change(opr);
				}
			}
			if (box == 'C')
			{
				if (op == 1)C.clear();
				if (op == 2)
				{
					string opr;
					cin >> opr;
					C.set(opr);
				}
				if (op == 3)
				{
					string opr;
					cin >> opr;
					C.change(opr);
				}
			}
		}
		if (man == 2)
		{
			char box;
			cin >> box;
			int op;
			cin >> op;
			if (op == 1)
			{
				if (box == 'A')
				{
					int opr;
					cin >> opr;
					if (A.exists())cout << res[0] << endl;
					else {
						int temp = A.get();
						cout << res[temp == opr] << endl;
					}
				}
				if (box == 'B')
				{
					double opr;
					cin >> opr;
					if (B.exists())cout << res[0] << endl;
					else {
						double temp = B.get();
						cout << res[temp == opr] << endl;
					}
				}
				if (box == 'C')
				{
					string opr;
					cin >> opr;
					if (C.exists())cout << res[0] << endl;
					else
					{
						string temp = C.get();
						cout << res[temp == opr] << endl;
					}
				}
			}
		}
	}
	return 0;
}
