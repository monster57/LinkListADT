typedef struct LinkList LinkList;
typedef struct Node Node;
struct LinkList{
	Node *head;
	Node *tail;
	int numOfElements;
};

struct Node{
	void *data;
	Node *next;
};

LinkList createList(void);

Node * create_node(void *data);

int add_to_list(LinkList *,Node *);

void *get_first_element(LinkList list);

void *get_last_element(LinkList list);

void traverse(LinkList, void (*)(void *data));

void * getElementAt(LinkList, int );

int indexOf(LinkList, void *);

void * deleteElementAt(LinkList *, int);

int asArray(LinkList, void **);

LinkList * filter(LinkList, int (*)(void *));