#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

typedef struct Task {

	char Name[100];
	int PriorityLevel;
	struct Task* next;

} Task;

typedef struct Stack {

	int* Data;
	int TopIndex;

} Stack;

typedef struct QueueNode {

	char TaskName;
	int PriorityLevel;
	struct QueueNode* NextNode;

} QueueNode;

typedef struct Queue {

	QueueNode* Front; //HEAD
	QueueNode* Back; //TAIL

} Queue;

void AddTask(Queue* TaskQueue, char* TaskName, int PriorityLevel);
void ProcessTask(Queue* TaskQueue, Stack* CompletedTaskStack);
void UndoLastTask(Stack* CompletedTaskStack, Queue* TaskQueue);
void ViewPendingTasks(Queue* TaskQueue);
void ViewCompletedTasks(Stack* CompletedTaskStack);
void ShowMenu();
bool isQueueEmpty(Queue* queue);
void Enqueue(Queue* queue, char* name, int pLevel);

int main(void) {

	ShowMenu();

	return 0;
}

void ShowMenu() {

	printf("Task Scheduler Menu:\n");
	printf("1. Add a Task\n");
	printf("2. Process a Task\n");
	printf("3. Undo Last Completed Task:\n");
	printf("4. View Pending Tasks\n");
	printf("5. View Completed Tasks\n");
	printf("6. Exit\n");
	printf("Enter your choice:");

}

void AddTask(Queue* TaskQueue, char* TaskName, int PriorityLevel) {

	if (PriorityLevel > 5 || PriorityLevel < 1) {

		while (PriorityLevel <= 5 && PriorityLevel >= 1) {

			printf("Wrong Priority Level..\n");
			printf("Enter Task Priority..");
			scnaf("%d", PriorityLevel);

		}

	}

	Enqueue(TaskQueue, TaskName, PriorityLevel);

}

bool isQueueEmpty(Queue* queue) {

	return queue->Front == NULL;

}

void Enqueue(Queue* queue, char* name, int pLevel) {

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) {
		printf("Insufficient Memeory");
		exit(EXIT_FAILURE);
	}

	newNode->TaskName = name;
	newNode->PriorityLevel = pLevel;
	newNode->NextNode = NULL;


	if (IsQueueEmpty(queue)) {

		queue->Front = newNode;
		queue->Back = newNode;

		return;
	
	}

	queue->Back->NextNode = newNode;
	queue->Back = newNode;

}