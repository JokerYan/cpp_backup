#include <stdio.h>

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		int queue[N];
		int stack[N];
		int pqueue[N] = {0};
		
		int queueInIndex = 0, queueOutIndex = 0, stackIndex = 0, pqueueIndex = 0;
		
		bool isQueue = 1, isStack = 1, isPqueue = 1;
		
		for(int i = 0; i < N; i++){
			int command, content;
			scanf("%d %d", &command, &content);
			if(command == 1){
				queue[queueInIndex++] = content;
				stack[stackIndex++] = content;
				pqueue[pqueueIndex++] = content;
			}
			else if(command == 2){
				if(isQueue){
					int tempContent = queue[queueOutIndex];
					queue[queueOutIndex++] = 0;
					if(tempContent != content) isQueue = 0;
				}
				if(isStack){
					int tempContent = stack[--stackIndex];
					stack[stackIndex] = 0;
					if(tempContent != content) isStack = 0;
				}
				if(isPqueue){
					int max = 0, maxIndex = -1;
					for(int j = 0; j < N; j++){
						if(pqueue[j] > max){
							maxIndex = j;
							max = pqueue[j];
						}
					}
					pqueue[maxIndex] = 0;
					if(max != content) isPqueue = 0;
				}
			}
		}
		if(!isQueue && !isStack && !isPqueue) printf("impossible\n");
		else if(isQueue && ! isStack && !isPqueue) printf("queue\n");
		else if(!isQueue && isStack && !isPqueue) printf("stack\n");
		else if(!isQueue && !isStack && isPqueue) printf("priority queue\n");
		else printf("not sure\n");
	}
	return 0;
}
