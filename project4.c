#include "project4.h"


void addToList(GroupPtr* head, int size, char* name, bool inStore) {
	// add a new node to the end of linked list "head"
	GroupPtr temp = (GroupPtr) malloc(sizeof(Group));
	temp->group_name = (char*) malloc(sizeof(char)*(26));
	strcpy(temp->group_name, name);
	temp->group_size = size;
	temp->status = (inStore?waiting:called);
	temp->next = NULL;
	if ((*head) == NULL || head == NULL) {
		*head = temp;
		return;
	}
	while ((*head)->next != NULL) {
		(*head) = (*head)->next;
	}

	(*head)->next = temp;

	return;
}

bool doesNameExist(GroupPtr head, char* name) {
	while (head->next != NULL) {
		if (!strcmp(name,head->group_name))
			return true;
		head = head->next;
	}

	return false;
}

bool updateStatus(GroupPtr head, char* name) {
	while (strcmp(name, head->group_name) && head->next != NULL) {
		head = head->next;
	}

	if (!strcmp(head->group_name, name) && head->status != waiting) {
		head->status = waiting;
		return true; 
	}

	printf("Party '%s' is either not found, or already in store.\n", name);

	return false;
}

void removeNthNode(GroupPtr* head, int n) {
	int counter = 0;

	if ((*head) == NULL) {
		return;
	}
	if (n == 1) {
		*head = (*head)->next;
	} else if (n > 1) {
		while (n-2 > counter && (*head) != NULL) {
			(*head) = (*head)->next;

			counter++;
		}
		free((*head)->next);
		(*head)->next = (*head)->next->next;

	}
}

char* retrieveAndRemove(GroupPtr* head, int size) {

	int counter = 1;
	GroupPtr trailer = NULL;
	GroupPtr headd = *head;

	while (headd != NULL && headd->group_size > size) {
		trailer = headd;
		headd = headd->next;
		counter++;
	}

	if (headd != NULL) {
		char* group_name = (char*) malloc(sizeof(char)*(strlen(headd->group_name)+1));
		strcpy(group_name,headd->group_name);
		removeNthNode(head, counter);
		return group_name;
	}


	return NULL;
}

int countGroupsAhead(char* name, GroupPtr head) {
	int count = 0;

	while (strcmp(name,head->group_name)) {
		head = head->next;
	}
	while (head->next != NULL) {
		count++;
		head = head->next;
	}

	return count;
}

void displayGroupSizeAhead(char* name, GroupPtr head) {
	int count = 0;
	printf("In order from first in line to last:\n");
	while (head != NULL) {
		if (!strcmp(head->group_name, name)) {
			break;
		}
		printf("Group size: %d \n", head->group_size);
		count++;
		head = head->next;
	}
	printf("Number of groups ahead: %d\n", count);
	return;
}

void displayListInformation(GroupPtr head) {
	int status;
	int counter = 0;
	while(head != NULL) {
		status = head->status;
		printf("Group Name: %s\n", head->group_name);
		printf("Group Size: %d\n", head->group_size);
		printf("Group Status: ");
		switch( status ) {
			case 1:
				printf("Called ahead");
				break;
			case 2:
				printf("In-store");
				break;
			default:
				printf("None");
				break;
		}

		printf("\n");
		head = head->next;
		counter++;

	}

	printf("Total number of waiting parties: %d\n", counter);

	return;
}

/*
char* readInput() {
	char* input = (char*) malloc(sizeof(char)*51);
	fgets(input, 50, stdin);
	return input;
}

int parseInput(char* input, char* arg1, char* arg2) {

	char command;

	arg1 = (char*) malloc(sizeof(char)*26);
	arg2 = (char*) malloc(sizeof(char)*26);

	sscanf(input, "%c %s %s", &command, arg1, arg2);

	switch (command) {
		case 'q':
			return -1;
		case '?':
			return 0;
		case 'a':
			return 1;
		case 'c':
			return 2;
		case 'w':
			return 3;
		case 'r':
			return 4;
		case 'l':
			return 5;
		case 'd':
			return 6;
		default:
			return -2;
	}
}


int getInt(char* string) {
	// get int from first char in string (useful for a, c, and r commands)
	return string[0]-'0';
}

void printHelp() {
	printf("AVAILABLE COMMANDS:\n\n")
	printf("q - Quit the program.\n
	? - List the commands used by this program and a brief description of how
to use each one.\n")
	printf("a <size> <name> - Add the group to the wait list using the given group size and name
specifying the group is waiting in the restaurant\n");
	printf("c <size> <name> - Add the group to the wait list using the given group size and name
specifying the group as a call ahead group.\n");
	printf("w <name> - Mark the call ahead group using the given name as waiting in the
restaurant.\n");
	printf("r <table-size> - Retrieve and remove the first group on the wait list that is waiting in
the restaurant and is less than or equal to the table size.\n");
	printf("l <name> - List total number of groups that are in the wait list in front of the group
specified by the given name.\n");
	printf("d - Display the total number of groups in the wait list.\n\n");
	printf("**End list**\n");
}



int main() {
	GroupPtr head = (GroupPtr) malloc(sizeof(GroupPtr));
	int go = 1;
	char* input;
	char* arg1;
	char* arg2;
	char* group_name;
	bool inStore;
	int table_size, group_size;
	while (go != -1 ) {
		input = readInput();
		go = parseInput(input, arg1, arg2);
		switch (go) {
			case 0:
				printHelp();
				break;
			case 1:
				group_size = getInt(arg1);
				addToList(head, group_size, group_name, true);
				inStore = true;
			case 2:
				group_size = getInt(arg1);
				addToList(head, group_size, group_name, false);
				break;
			case 3:
				group_name = arg1;
				updateStatus(head, group_name);
				break;
			case 4:
				table_size = getInt(arg1);
				break;
			case 5:
				group_name = arg1;
				displayGroupSizeAhead(group_name, head);
				break;
			case 6:
				displayListInformation(head);
				break;
			default:
				printf("The specified command cannot be found. Please try again.\n");
				break;
		}

		free(input);
		free(arg1);
		free(arg2);
	}
	return 0;
}
*/