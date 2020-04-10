#include<iostream>
using namespace std;

struct node
{
	int x;
	int y;
	int step;
};

int main(void)
{
	int next[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
	};//方向数组

	int time;
	cin >> time;
	for (int i = 0; i < time; i++)
	{
		int startx, starty, p, q;
		int tx, ty;
		struct node que[122];
		char map[11][11];
		int book[11][11] = { 0 };
		int m, n, t;
		cin >> m >> n >> t;
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= n; k++)
			{
				cin >> map[j][k];
				if (map[j][k] == 'M')
				{
					p = j;
					q = k;
				}
				if (map[j][k] == 'D')
				{
					startx = j;
					starty = k;
				}
			}
		//读入地图并且查找起点终点坐标

		int head = 1, tail = 1;
		que[tail].x = startx;
		que[tail].y = starty;
		que[tail].step = 0;
		tail++;
		book[startx][starty] = 1;

		int flag = 0;
		while (head < tail)
		{
			if (que[head].step == t)break;//如果循环次数超过t，即t步内没找到M就退出。
			for (int k = 0; k <= 3; k++)
			{
				tx = que[head].x + next[k][0];
				ty = que[head].y + next[k][1];
				if (tx<1 || tx>m || ty<1 || ty>n)continue;
				if (map[tx][ty] !='#'&&book[tx][ty] == 0)
				{
					book[tx][ty] = 1;
					que[tail].x = tx;
					que[tail].y = ty;
					que[tail].step = que[head].step + 1;
					tail++;
				}
				if (tx == p && ty == q)
				{
					flag = 1;
					//如果找到了M点，才标记flag=1
					break;
				}
			}
			if (flag == 1)break;
			head++;
		}

		//flag=1表示在规定次数内找到了M，否则表示找不到M或者没能在规定次数内找到
		if (flag == 1)
			cout << que[tail - 1].step << endl;
		else cout << "OMG! DUDU is bound to Kneel keyboard" << endl;

	}
	return 0;
}