struct Node{
	int data;
	struct Node *link;
};
void createNode(struct Node **,int);
void enqueue(struct Node **,int);
void dequeue(struct Node **,int);
void move(struct Node *,int);
