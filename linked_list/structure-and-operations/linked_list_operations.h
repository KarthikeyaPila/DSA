typedef struct Node {
    int value;
    struct Node *next;
} Node;

void create(Node *head);
void display(Node *head);
void delete_node(Node **head, int node_num);
void add_at_beginning(Node **head, int val);
void add_after_n(Node *head, int node_num, int val);
void append(Node **head, int val);
int count(Node *head);
void clear_list(Node **head);
void bubble_sort(struct Node **head);