#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

typedef struct node* Node;

void count_node(Node head){
	int count = 0;
	Node p = head;
	while(p != NULL){
		p = p->link;
		count++;
	}
	printf("Total no. of nodes: %d\n", count);
}

void print_node(Node head){
	Node p = head;
	while(p != NULL){
		printf("%d\t",p->info);
		p = p->link;
	}
	printf("\n");
}

Node node_search(Node head, int data){
	Node p = head;
	while(p->link != NULL){
		if(data == p->info){
			printf("Match found! Node %d is present in the list\n",p->info);
			return head;
		}
		p = p->link;
	}
	printf("Match not found!\n");
	return head;
}

Node create_list(Node head, int data){
	Node p = head;
	Node temp = (Node)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = p;
	p = temp;
	printf("List created!\n");
	return p;	
}

Node add_at_start(Node head, int data){
	Node temp=(Node)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = head;
	head = temp;
	printf("Node %d added at the start of the list\n",temp->info);
	return head;
}

Node add_at_end(Node head, int data){
	Node p = head;
	Node temp = (Node)malloc(sizeof(struct node));
	while(p->link != NULL){
		p = p->link;
	}
	p->link = temp;
	temp->info = data;
	temp->link = NULL;
	printf("Node %d added at the end of the list!\n",data);
	return head;
}

Node add_at_pos(Node head, int data, int pos){
	Node p = head;
	Node temp = (Node)malloc(sizeof(struct node));
	int curr_pos = 1;
	while(p != NULL){
		if(curr_pos == pos-1){
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			printf("Node %d added at position no. %d\n",temp->info, pos);
			return head;
		}
	}
	printf("Node %d could be added at position no. %d\n",data,pos);
	return head;
}

Node del_at_start(Node head){
	Node p = head;
	Node q = p->link;
	free(p);
	head = q;
	printf("First node deleted!\n");
	return head;
}

Node del_at_pos(Node head, int pos){
	Node p = head;
	Node q = NULL;
	int curr_pos = 1;
	while(p != NULL){
		if(curr_pos == pos-1){
			q = p->link;
			p->link = q->link;
			free(q);
			printf("Node at the position %d deleted\n",pos);
			return head;
		}
		p = p->link;
		curr_pos++;
	}
	printf("Node at position %d could not be deleted!\n",pos);
	return head;
}

Node del_at_end(Node head){
	Node p = head;
	Node q = p->link;
	while(q->link != NULL){
		p = p->link;
		q = q->link;
	}
	p->link = NULL;
	free(q);
	printf("Last node is deleted!\n");
	return head;
}

Node reverse_list(Node head){
	Node temp = head;
	Node prev = NULL;
	Node next = NULL;
	while(temp != NULL){
		next = temp->link;
		temp->link = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
	printf("List reversed!\n");
	return head;
}

void free_list(Node head){
	Node p = head;
	Node temp;
	int num = 1;
	while(p != NULL){
		temp = p;
		p = p->link;
		free(temp);
		printf("Node no. %d freed!\n",num);
		num++;
	}
	printf("\nTotal Nodes freed: %d\n", num-1);
	printf("-----End of program-----\n\n");
}

int main(void){
	Node head = NULL;
	head = add_at_start(head, 10);
	head = add_at_start(head, 20);
	head = add_at_start(head, 30);
	head = add_at_start(head, 40);
	head = add_at_end(head, 50);
	head = add_at_pos(head, 15, 2);
	print_node(head);
	count_node(head);
	printf("---------------\n");
	head = del_at_pos(head, 3);
	print_node(head);
	count_node(head);
	printf("---------------\n");
	head = del_at_end(head);
	print_node(head);
	count_node(head);
	printf("----------------\n");
	head = del_at_start(head);
	print_node(head);
	printf("----------------\n");
	head = reverse_list(head);
	print_node(head);
	printf("----------------\n");
	free_list(head);	
	return 0;
}
