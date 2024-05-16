#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
int arr[2],ret;
int main()
{
	int ret,arr[2];
	char ch='A';
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));	
	ret=pipe(arr);
	sigaction(SIGINT,&sa,NULL);
	int count=0;

	while(1)
	{
		write(arr[1],&ch,1);
		count++;
		printf("bytes writen: %d\n",count);

	}
}
void sigint_handler(int sig)
{
		close(arr[1]);
		close(arr[0]);
		_exit(0);
}
	
