//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section A - Linked List Questions
Purpose: Implementing the required functions for Question 1 */

/* CE1007/CZ1007 자료구조
실습 시험: 섹션 A - 연결 리스트 관련 문제
목적: 문제 1에 필요한 함수 구현 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;  //다음 노드
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist{
	int size;
	ListNode *head;		//첫번째 노드
} LinkedList;			// You should not change the definition of LinkedList


///////////////////////// function prototypes ////////////////////////////////////

//You should not change the prototype of this function
int insertSortedLL(LinkedList *ll, int item);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	LinkedList ll;
	int c, i, j;
	c = 1;

	//Initialize the linked list 1 as an empty linked list
	//연결 리스트 1을 빈 연결 리스트로 초기화합니다.
	ll.head = NULL;
	ll.size = 0;

	printf("1: Insert an integer to the sorted linked list:\n");
	//정렬된 연결 리스트에 정수를 삽입합니다
	printf("2: Print the index of the most recent input value:\n");
	//가장 최근에 입력한 값의 인덱스를 출력합니다
	printf("3: Print sorted linked list:\n");
	//정렬된 연결 리스트를 출력합니다
	printf("0: Quit:");
	//종료

	while (c != 0)
	{
		printf("\nPlease input your choice(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: "); 
			scanf("%d", &i);// 입력한 정수를 i에 저장
			j = insertSortedLL(&ll, i); // ll에 i를 정렬된 상태로 삽입, 함수의 반환값을 j에 저장
			printf("The resulting linked list is: "); 
			printList(&ll); //리스트 출력
			break;
		case 2:
			printf("The value %d was added at index %d\n", i, j);
			break;
		case 3:
			printf("The resulting sorted linked list is: ");
			printList(&ll);
			//removeAllItems(&ll);
			//모든 항목 제거(&11)
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}


	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

int insertSortedLL(LinkedList *ll, int item)       // 연결 리스트에 item을 정렬된 위치에 삽입하는 함수
{ 
    // 필요한 포인터 변수 선언
    ListNode *newNode;                             // 새로 만들 노드
    ListNode *cur;                                 // 현재 확인하고 있는 노드
    ListNode *pre;                                 // 현재 노드의 바로 앞 노드
    int index = 1;                                 // 삽입될 위치를 저장할 변수, 처음에는 1부터 시작
 
    // 리스트가 비어 있는지 확인
    if (ll->head == NULL){                         // head가 NULL이면 현재 리스트에 노드가 하나도 없음
        newNode = malloc(sizeof(ListNode));       // 새로운 노드가 들어갈 메모리를 만듦
        newNode->item = item;                      // 새 노드에 삽입할 값을 저장
        newNode->next = NULL;                      // 새 노드의 다음 노드는 없으므로 NULL로 설정
        ll->head = newNode;                        // 리스트의 head가 새 노드를 가리키도록 설정
        ll->size++;                                // 리스트의 노드 개수를 1 증가
        return 0;                                  // 첫 번째 위치에 삽입했으므로 0을 반환
    } 
 
    // 새 item이 현재 첫 번째 노드의 값보다 작거나 같은지 확인
    if (item <= ll->head->item){                   // item이 현재 head의 값보다 작거나 같다면
        newNode = malloc(sizeof(ListNode));       // 새로운 노드가 들어갈 메모리를 만듦
        newNode->item = item;                      // 새 노드에 삽입할 값을 저장
        newNode->next = ll->head;                  // 새 노드가 기존의 head를 가리키도록 연결
        ll->head = newNode;                        // head가 새 노드를 가리키도록 변경
        ll->size++;                                // 리스트의 노드 개수를 1 증가
        return 0;                                  // 첫 번째 위치에 삽입했으므로 0을 반환
    } 
 
    // 첫 번째 위치가 아니라면 삽입할 위치를 찾기 시작
    if (item > ll->head->item){                    // item이 현재 head의 값보다 크다면
        pre = ll->head;                            // pre를 첫 번째 노드를 가리키도록 설정
        cur = pre->next;                            // cur을 두 번째 노드를 가리키도록 설정
    } 
 
    // cur이 가리키는 노드의 값을 item과 비교하면서 위치를 찾음
    while (cur != NULL && cur->item < item)       // cur이 존재하고 cur의 값이 item보다 작으면 반복
    { 
        pre = cur;                                 // pre를 현재 cur 위치로 한 칸 이동
        cur = pre->next;                           // cur을 다음 노드로 한 칸 이동
        index++;                                   // 삽입 위치를 한 칸 증가
    } 
    
    // 현재 cur의 값이 item과 같은지 확인
    if (cur != NULL && cur->item == item)         // 같은 값이 이미 존재한다면
    { 
        return -1;                                 // 중복된 값이므로 삽입하지 않고 -1을 반환
    } 
     
    // 삽입할 위치를 찾았으므로 새로운 노드를 만듦
    newNode = malloc(sizeof(ListNode));            // 새로운 노드가 들어갈 메모리를 만듦
    newNode->item = item;                           // 새 노드에 삽입할 값을 저장
    newNode->next = cur;                            // 새 노드가 현재 cur을 가리키도록 연결
    pre->next = newNode;                            // 이전 노드인 pre가 새 노드를 가리키도록 연결
    ll->size++;                                     // 리스트의 노드 개수를 1 증가
    return index;                                   // 새 노드가 삽입된 위치를 반환
}

///////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}


void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}


ListNode *findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}


