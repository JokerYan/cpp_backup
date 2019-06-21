#include <stdio.h>

struct hand{
	int status;
	hand *next, *last;
	int player;
};

int main(){
	int N, s;
	scanf("%d %d", &s, &N);
	
	struct hand start = {2, nullptr, nullptr, 1};
	struct hand *current = new hand();
	current = &start;
	for(int i = 2; i <= N; i++){
		hand *temp = new hand();
		temp->status = 2;
		temp->last = current;
		temp->player = i;
		current->next = temp;
		current = current->next;
	}
	current->next = &start;
	start.last = current;

	current = &start;
	while(current->next->player != current->player || current->last->player != current->player){
		for(int i = 1; i < s; i++){
			current = current->next;
		}
		// printf("%d ", current->player);
		if(current->status == 2){
			hand *temp1 = new hand{1, nullptr, current->last, current->player};
			hand *temp2 = new hand{1, current->next, temp1, current->player};
			temp1->next = temp2;
			current->last->next = temp1;
			current->next->last = temp2;
			// printf("%d ", temp1->last->player);
			current = temp1;
			// printf("%d %d %d %d %d %d", current->player, current->next->player, current->next->next->player, current->next->next->next->player, current->next->next->next->next->player, current->next->next->next->next->next->player);
			// printf("split\n");
		}
		else if(current->status == 1){
			current->status = 0;
			current = current->next;
			// printf("%d %d %d %d", current->player, current->next->player, current->next->next->player, current->next->next->next->player);
			// printf("down\n");
		}
		else if(current->status == 0){
			current->next->last = current->last;
			current->last->next = current->next;
			current = current->next;
			// printf("%d %d %d %d", current->player, current->next->player, current->next->next->player, current->next->next->next->player);
			// printf("dead\n");
		}
	}

	printf("%d", current->player);
	return 0;
}
