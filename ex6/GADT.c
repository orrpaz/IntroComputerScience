/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 6
******************************************/

#include "GADT.h"
#include <string.h>
#include <stdlib.h>

typedef void(*cpy_elm)(ELM, ELM);
typedef void(*free_elm)(ELM);
typedef void(*print_elm)(ELM);
typedef int(*cmp_elm)(ELM, ELM);
typedef ELM(*add_elm_to_elm)(ELM, ELM);
typedef ELM(*create_elm)();


struct Node
{
	ELM m_val;
	struct Node* m_next;
};

typedef struct Node Node;

typedef struct SortLinkList {
	Node *			m_head;
	int				m_size;
	cpy_elm			m_cpyElm;
	free_elm		m_free_elm;
	print_elm		m_print_elm;
	cmp_elm			m_cmp_elm;
	add_elm_to_elm  m_add_elm_to_elm;
	create_elm		m_create_elm;
} SortLinkList;

void RemoveByHead(SortLinkList* sll);
void RemoveNode(SortLinkList* sll, Node* prevNode);
RESULT PushNode(SortLinkList* sll, Node *currentNode, ELM node);
RESULT PushNodeByHead(SortLinkList* sll, ELM node);
void CheckLastItem(HEAD* head);




/************************************************************************
* function name: SLCreate
* The Input: poineter to function - create_elm,cpy_elm,cmp_elm,free_elm,
  print_elm add_elm_to_elm.
* The output: return HEAD sorted list-sll
* The Function operation: the function create sorted list.
*************************************************************************/
HEAD SLCreate(ELM head_val, ELM(*create_elm)(), void(*cpy_elm)(ELM, ELM),
	int(*cmp_elm)(ELM, ELM), void(*free_elm)(ELM),
	void(*print_elm)(ELM), ELM(*add_elm_to_elm)(ELM, ELM))
{
	Node *temp = NULL;
	SortLinkList *sll = (SortLinkList*)malloc(sizeof(SortLinkList));
	if (sll == NULL)
	{
		// allocated memory was fail.
		return NULL;
	}
	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		// free list.
		free(sll);
		return NULL;
	}
	sll->m_head = temp;
	sll->m_head->m_next = NULL;
	// allocated memory for value.
	sll->m_head->m_val = (ELM)create_elm();
	if (sll->m_head->m_val == NULL)
	{
		free(sll->m_head);
		free(sll);
		return NULL;
	}
	sll->m_cpyElm = cpy_elm;
	sll->m_cpyElm(temp->m_val, head_val);
	sll->m_size = 1;
	sll->m_create_elm = create_elm;
	sll->m_free_elm = free_elm;
	sll->m_print_elm = print_elm;
	sll->m_cmp_elm = cmp_elm;
	sll->m_add_elm_to_elm = add_elm_to_elm;
	return (HEAD)sll;
}

/************************************************************************
* function name: SLDestroy
* The Input:head type HEAD
* The output: none
* The Function operation: the function free all node and value in list.
  then it free sll.
*************************************************************************/
void SLDestroy(HEAD head)
{
	Node* nextNode = NULL;
	Node* currentNode = NULL;

	SortLinkList *sll = (SortLinkList*)head;
	if (sll != NULL)
	{
		if (sll->m_head != NULL)
		{
			nextNode = sll->m_head->m_next;
			currentNode = sll->m_head;
			while (nextNode != NULL)
			{
				sll->m_free_elm(currentNode->m_val);
				free(currentNode);
				// continue to next node.
				currentNode = nextNode;
				nextNode = nextNode->m_next;
			}
			// free node and val.
			sll->m_free_elm(currentNode->m_val);
			free(currentNode);
		} // end of if
		free(sll);
	} // end of if.
}

/************************************************************************
* function name: SLAddListElement
* The Input: head type HEAD*, node(val) type ELM
* The output:  return result. 'badArgs' or 'success'
* The Function operation: the function add new node to list in suitable place.
*************************************************************************/
RESULT SLAddListElement(HEAD* head, ELM node)
{
	Node *nextNode = NULL, *currentNode = NULL;
	int temp;
	RESULT result;
	SortLinkList *sll = NULL;
	if (head == NULL || *head == NULL || node == NULL)
	{
		return badArgs;
	}
	sll = *((SortLinkList**)head);
	nextNode = sll->m_head->m_next;
	currentNode = sll->m_head;
	// push by head
	temp = sll->m_cmp_elm(currentNode->m_val, node); 
	if (temp > 0)
	{
		// enter new node to head.
		result = PushNodeByHead(sll, node);
		return result;
	}
	while (nextNode != NULL)
	{ 
		// compare value.
		temp = sll->m_cmp_elm(nextNode->m_val, node);
		if (temp > 0)
		{
			// push node.
			 result = PushNode(sll, currentNode, node);
			 return result;
		}
		// continue to next node.
		currentNode = nextNode;
		nextNode = nextNode->m_next;
	}  // end of while.
	// push by tail
	result = PushNode(sll, currentNode, node); 
	return result;
}

/************************************************************************
* function name: SLRemoveElement
* The Input: head type HEAD*, node(val) type ELM
* The output: return result. 'badArgs' or 'success'
* The Function operation: the function remove element in list
*************************************************************************/
RESULT SLRemoveElement(HEAD* head, ELM node)
{
	int compare;
	SortLinkList *sll = NULL;
	Node* currentNode = NULL;
	Node* previous = NULL;
	if (head == NULL || *head == NULL || node == NULL)
	{
		return badArgs;
	}
	 sll = *(SortLinkList**)head;
	 currentNode = sll->m_head->m_next;
	 previous = sll->m_head;
	 // remove by head.
	 compare = sll->m_cmp_elm(previous->m_val, node);
	 if (compare == 0)
	 {
		 RemoveByHead(sll);
		 CheckLastItem(head);
		 return success;
	 }
	 while (currentNode != NULL)
	 {
		 // remove node, search the suitable node.
		 compare = sll->m_cmp_elm(currentNode->m_val, node);
		 if (compare == 0)
		 {
			 RemoveNode(sll,previous);
			 CheckLastItem(head);
			 return success;
		 }
		 // if wasn't found,continue to next node.
		 previous = currentNode;
		 currentNode = currentNode->m_next;
	 }
	 return badArgs;
}

/************************************************************************
* function name: RemoveByHead
* The Input: sll type SortLinkList*
* The output: none
* The Function operation: remove the head in list.
*************************************************************************/
void RemoveByHead(SortLinkList* sll)
{
	Node* remove = sll->m_head;
	// new head point to next node
	sll->m_head = sll->m_head->m_next;
	// free val
	sll->m_free_elm(remove->m_val);
	free(remove);
	--(sll->m_size);

}

/************************************************************************
* function name: RemoveNode
* The Input: sll type SortLinkList* prevNode type node*
* The output: none
* The Function operation: the function remove node in list.
*************************************************************************/
void RemoveNode(SortLinkList* sll, Node* prevNode)
{
	Node* remove = prevNode->m_next;
	// re-connect 
	prevNode->m_next = prevNode->m_next->m_next;
	// free val.
	sll->m_free_elm(remove->m_val);
	// free node.
	free(remove);
	--(sll->m_size);

}

/************************************************************************
* function name: PushNode
* The Input: sll type SortLinkList*, node type ELM ,currentNode type node*
* The output: return result . 'success' or 'outOfMem'
* The Function operation: push node in suitable place in the list.
*************************************************************************/
RESULT PushNode(SortLinkList* sll,Node *currentNode, ELM node)
{
	Node* temp = currentNode->m_next;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return outOfMem;
	}
	// create new node.
	newNode->m_val = sll->m_create_elm();
	if (newNode->m_val == NULL)
	{
	    free(newNode);
		return outOfMem;
	}
	// copy the value to node.
	sll->m_cpyElm(newNode->m_val, node);
	// push after currentNode
	currentNode->m_next = newNode;
	newNode->m_next = temp;
	// count the size of list
	++(sll->m_size);
	return success;
}

/************************************************************************
* function name: PushNodeByHead
* The Input: sll type SortLinkList*, node type ELM
* The output: return result . 'success' or 'outOfMem'
* The Function operation: the function push node to begining of list
*************************************************************************/
RESULT PushNodeByHead(SortLinkList* sll, ELM node)
{
	// save current head
	Node* temp = sll->m_head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return outOfMem;
	}
	// create new node
	newNode->m_val = sll->m_create_elm();
	if (newNode->m_val == NULL)
	{
		free(newNode);
		return outOfMem;
	}
	// copy the value to node.
	sll->m_cpyElm(newNode->m_val, node);
	// new head.
	sll->m_head = newNode;
	// put the 'head' after newnode.
	newNode->m_next = temp;
	// count the size of list
	++(sll->m_size);
	return success;
}

/************************************************************************
* function name: SLFindElement
* The Input: head(sll) type HEAD, node(val) type ELM
* The output: return ELM (val)
* The Function operation: sherch val in the node of list.
*************************************************************************/
ELM SLFindElement(HEAD head, ELM node)
{
	// struct
	SortLinkList* sll = head;
	Node* current = NULL;
	if (head == NULL || node == NULL)
	{
		return NULL;
	}
	current = sll->m_head;
	while (current != NULL)
	{
		// compare.
		if (sll->m_cmp_elm((current->m_val),node) == 0)
		{
			
			return current->m_val;
		}
		// next node.
		current = current->m_next;
	}
	// didnt found.
	return NULL;
}

/************************************************************************
* function name: SLAddToElement
* The Input: head type HEAD*, toEL and addEL type ELM
* The output: none
* The Function operation: the function add element to element.
  then she resort the list.
*************************************************************************/
void SLAddToElement(HEAD* head, ELM toEl, ELM addEl)
{
	ELM data;
	SortLinkList* sll = NULL;
	if (head == NULL || *head == NULL || toEl == NULL || addEl == NULL)
	{
		return;
	}
	sll =  *((SortLinkList**)head);
	// shearch the element.
	data = SLFindElement(sll,toEl);
	if (data == NULL)
	{
		return;
	}
	// adding.
	sll->m_add_elm_to_elm(data, addEl);
	// re-sort
	SLAddListElement(&sll, data);
	SLRemoveElement(&sll, data);


}

/************************************************************************
* function name: PrintSll
* The Input: head type HEAD
* The output: none
* The Function operation: the function print the values in list.
*************************************************************************/
void PrintSll(HEAD head)
{
	int i;
	SortLinkList *sll;
	Node* current;
	int counter = 0;
	if (head == NULL)
	{
		return;
	}
	sll = (SortLinkList*)head;
	current = sll->m_head;
	while (current != NULL)
	{
		for (i = 0; i < counter; i++)
		{
			printf("\t");
		}
		// increase the counter (amount of tabs)
		counter++;
		sll->m_print_elm(current->m_val);
		// next node.
		current = current->m_next;
	}
}

/************************************************************************
* function name: PrintSize
* The Input: head type HEAD
* The output: none
* The Function operation: print the size of link list.
*************************************************************************/
void PrintSize(HEAD head)
{
	printf("%d\n", ((SortLinkList*)head)->m_size);
}

/************************************************************************
* function name: CheckLastItem
* The Input: sll type Head*
* The output: none
* The Function operation: the function if there isnt node in list.
*************************************************************************/
void CheckLastItem(HEAD* sll)
{
	// casting
	SortLinkList *psll = *(SortLinkList**)sll;
	if ((psll)->m_size == 0)
	{
		SLDestroy(*sll);
	    *sll = NULL;
	}
}





