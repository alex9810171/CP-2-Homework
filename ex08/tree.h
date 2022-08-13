struct list{
	int data;
	struct list* leftchild;
	struct list* rightchild;
};
void ctree(struct list **,int);
void inorder(struct list*,int*);
void eman(struct list *);


