void Set_element(Mail_list*head,Mail_list*tail)
{
	Mail_list *p = Create_element();
	printf("请输入姓名：");
	scanf("%s", p->name);
	/*************将字母指针依次指向其各自开头的位置********/
	extern Mail_list * alpha[27];//0-25依次为A-Z, 26为#
	char c = get_first_letters(p->name);
	if(isalpha(c))
    {
        c = toupper(c);//防止存在小写英文开头的人
        int k = c - 'A';//计算位置
        if(!alpha[k] || strcmp(p->name, alpha[k]->name) == -1)alpha[k] = p;//如果该字母的指针为空，则直接指向，否则将判断当前指向的是否小于要插入的
    }
	else alpha[26] = head->next;//#字开头的
	/**********************************************************/
	printf("请输入号码：");
	scanf("%s",p->phone_number[0]);
	if (head->next == tail)//当该表为空表时，直接将改用户插入首尾指针之间
	{
		head->next = p;
		p->previous = head;
		p->next = tail;
		tail->previous = p;
	}
	else//如果该表不为空
	{
		Mail_list *q = head;
		while (q->next!=tail&&strcmp(p->name, q->next->name) > 0)
			q = q->next;
		q->next->previous = p;
		p->next = q->next;
		q->next = p;
		p->previous = q;
	}
}