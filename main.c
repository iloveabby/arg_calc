#include <stdio.h>
#include <stdlib.h>
#define add 0
#define sub 1
#define mut 2
#define div 3
#define term 0
char get_op(char **argv){
	if(argv[1][0] == '+') return add;	
	else if (argv[1][0] == '-') return sub;
	else if (argv[1][0] == 'x') return mut;
	else if (argv[1][0] == '/') return div;
	else{
		puts("Invaild operator");
		exit(1);
	}
}	
double *get_nums(int argc,char **argv){
	double *ptr =  calloc(argc - 1,sizeof(double));
	char start = 2;
	char count = 0;
	while(start != argc){
		ptr[count] = atof(argv[start]);
		count++;
		start++;
	}		
	ptr[count] = term;
	return ptr;	
}

int main(int argc,char **argv){
	if(argc < 3){
		puts("error!, You lack arguments");
		return 0;
	}
	double output = 0;
	double *argnumbs;
	char op = 0;
	char count = 0;
	op = get_op(argv);
	argnumbs = get_nums(argc,argv);
	if(op == add){
		while(argnumbs[count] != term){
			output = output + argnumbs[count];
			count++;
		}
	}
	else if (op == sub){
		output = argnumbs[count];
		count++;
		while(argnumbs[count] != term){
			output = output - argnumbs[count];
			count++;
		}
	}
	else if(op == mut){
		output = argnumbs[count];
		count++;
		while(count < argc - 2){
			output = output * argnumbs[count];
			count++;
		}
	}
	else if(op == div){
		output = argnumbs[count];
		count++;
		while(count < argc - 2){/*for some reason i couldn't do argnumbs[count] != term so i just used or += with the counter and argc - 3*/
			if(argnumbs[count] == 0){
				puts("Div by zero");
				return 1;
			}
			output = output / argnumbs[count];
			count++;
		}
	}
	printf("%lf\n",output);
	return 0;
}
