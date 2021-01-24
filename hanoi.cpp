#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

//recursive 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    	if (n == 1)
    	{
        	cout << " Move disk 1 from rod " <<  from_rod << " to rod " << to_rod << endl;
        	return;
    	}
    	towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    	cout << " Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    	towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
//recursion end

//iterative
struct Stack                            // A structure to represent a stack
{
        unsigned capacity;
        int top;
        int *array;
};

Stack * createStack(unsigned capacity)           // function to create a stack of given capacity.
{
        Stack * stack = (Stack*) malloc(sizeof(Stack));
        stack -> capacity = capacity;
        stack -> top = -1;
        stack -> array =
        (int*) malloc(stack -> capacity * sizeof(int));
        return stack;
}

int isFull(Stack* stack)                         // Stack is full when top is equal to the last index
{
        return (stack->top == stack->capacity - 1);
}

int isEmpty(Stack* stack)                        // Stack is empty when top is equal to -1
{
        return (stack->top == -1);
}

void push(Stack *stack, int item)                // Function to add an item to stack.  It increases top by 1
{
        if (isFull(stack))
        {
                return;
        }
        stack -> array[++stack -> top] = item;
}

int pop(Stack* stack)            //Function to remove an item from stack.  It decreases top by 1
{
        if (isEmpty(stack))
        return INT_MIN;
        return stack -> array[stack -> top--];
}

void moveDisk(char fromPeg, char toPeg, int disk)       //Function to show moving of disks
{
        cout << "Move the disk " << disk << " from " << fromPeg <<" to " << toPeg << endl;
}

void moveDisksBetweenTwoPoles(struct Stack *src, struct Stack *dest, char s, char d)    // Function of moving between two poles
{
        int pole1TopDisk = pop(src);
        int pole2TopDisk = pop(dest);
        if (pole1TopDisk == INT_MIN)            //pole 1 empty
        {
                push(src, pole2TopDisk);
                moveDisk(d, s, pole2TopDisk);
        }
        else if (pole2TopDisk == INT_MIN)       //pole 2 empty
        {
                push(dest, pole1TopDisk);
                moveDisk(s, d, pole1TopDisk);
        }
        else if (pole1TopDisk > pole2TopDisk)   //pole 1 > top pole 2 disc
        {
                push(src, pole1TopDisk);
                push(src, pole2TopDisk);
                moveDisk(d, s, pole2TopDisk);
        }
        else                                    //top disk of pole1 < top disk of pole2
        {
                push(dest, pole2TopDisk);
                push(dest, pole1TopDisk);
                moveDisk(s, d, pole1TopDisk);
        }
}
void tohIterative(int num_of_disks, Stack *src, Stack *aux, Stack *dest)   //Function to implement TOH puzzle
{
        int i, total_num_of_moves;
        char s = 'S', d = 'D', a = 'A';
        if (num_of_disks % 2 == 0)              //If number of disks is even, then interchange destination pole and auxiliary pole
        {
                char temp = d;
                d = a;
                a  = temp;
        }
        total_num_of_moves = pow(2, num_of_disks) - 1;
        for (i = num_of_disks; i >= 1; i--)             //Larger disks will be pushed first
        {
                push(src, i);
        }
        for (i = 1; i <= total_num_of_moves; i++)
        {
                if (i % 3 == 1)
                {
                        moveDisksBetweenTwoPoles(src, dest, s, d);
                }
                else if (i % 3 == 2)
                {
                        moveDisksBetweenTwoPoles(src, aux, s, a);
                }
                else if (i % 3 == 0)
                {
                        moveDisksBetweenTwoPoles(aux, dest, a, d);
                }
        }
}

//iterative end


int main()
{
	//recursion
    	int n = 0; 		
	cout << endl;
	cout << "Enter number of discs(recursively) " << endl;
	cin >> n;
	towerOfHanoi(n, 'S', 'D', 'A'); 
	cout << endl;
	//recursion end

	//iterative
	cout << endl;
	unsigned int num_of_disks = 0;
        cout << "Enter number of discs(iteratively) " << endl;
        cin >> num_of_disks;
        Stack *src, *dest, *aux;                        //creae three discs 
        src = createStack(num_of_disks);                //of size
        aux = createStack(num_of_disks);                //'num_of_disks'
        dest = createStack(num_of_disks);               //to hold the disks
        tohIterative(num_of_disks, src, aux, dest);
	cout << endl;
	//iterative end 
    	return 0;
	//recursion
}

