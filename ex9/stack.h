struct list{
	int data;
	struct list *link;
};
void push(struct list **,int);
void pop(struct list **);
void reverse(struct list **);
void show(struct list *);
