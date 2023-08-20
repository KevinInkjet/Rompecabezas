#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Pila
{
	public:
		Pila(int);
	    void push(int);
	    int pop();
	    bool overflow();
	    bool underflow();
	    int gettop() { return top; }
	private:
		int * stack = NULL;
	    int top;
};

class Cola
{
	public:
		Cola(int);
	    void enqueue(int);
	    int dequeue();
	    bool overflow();
	    bool underflow();
	private:
		int * queue = NULL;
		int head;
		int tail;
};

Pila::Pila(int n)
{
	stack = new int[n];
	top = 0;
}

Cola::Cola(int n)
{
	queue = new int[n];
	head = 0;
	tail = -1;
}

bool Pila::overflow()
{
	if(top == 5000)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pila::underflow()
{
	if(top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Pila::push(int a)
{
	if(overflow())
	{
		cout << "Full queue" << endl;
		return;
	}
	stack[top] = a;
	top++;
}

int Pila::pop()
{
	if(underflow() == true)
	{
		cout << "Empty stack" << endl;
		return 0;
	}
	top--;
	return stack[top];
}

void Cola::enqueue(int a)
{
	if(overflow())
	{
		cout << "Full queue" << endl;
		return;
	}
	queue[head] = a;
	if(head == sizeof(queue))
	{
		head = 0;
	}
	else
	{
		head++;
	}
}

bool Cola::overflow()
{
	if(head == tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Cola::underflow()
{
	if(tail == -1)
	{
		return true;
	}
	return false;
}

int Cola::dequeue()
{
	int aux;
	if(underflow() == true)
	{
		cout << "Empty queue" << endl;
		return 0;
	}	
	aux = queue[tail];
	if((sizeof(queue) % tail) == head)
	{
		head = 0;
		tail = -1;
	}
	else if(tail == sizeof(queue))
	{
		tail = 0;
	}
	else
	{
		tail++;
	}
	return aux;
}

void mover(int x, int y, int* tablero[], Pila* px, Pila* py, int n)
{
	if(tablero[x][y] == 0)
	{
		cout << "Try another coordinate" << endl;
		return;
	}
	else if(x == 0 && y ==0)
	{

		if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x+1);
			py->push(y);
			return;
		}
		else if(tablero[x][y+1] == 0) 
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y+1);
			return;
		}	
	}
	else if(x==0 && y == n-1) 
	{
		if(tablero[x][y-1] == 0) 
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y-1);
			return;
		}
		else if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x+1);
			py->push(y);
			return;
		}
	}
	else if(x==n-1 && y == 0) 
	{
		if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x-1);
			py->push(y);
			return;
		}
		else if(tablero[x][y+1] == 0)
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y+1);
			return;
		}
	}
	else if(x==n-1 && y == n-1) 
	{
		if(tablero[x][y-1] == 0)
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y-1);
			return;
		}
		else if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x-1);
			py->push(y);
			return;
		}
	}
	else if(x == 0)
	{
		if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x+1);
			py->push(y);
			return;
		}
		else if(tablero[x][y+1] == 0)
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y+1);
			return;
		}
		else if(tablero[x][y-1] == 0)
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y-1);
			return;
		}
	}
	else if(x == n-1)
	{
		if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x-1);
			py->push(y);
			return;
		}
		else if(tablero[x][y+1] == 0)
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y+1);
			return;
		}
		else if(tablero[x][y-1] == 0)
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y-1);
			return;
		}
	}
	else if(y == 0)
	{
		if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x+1);
			py->push(y);
			return;
		}
		else if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x-1);
			py->push(y);
			return;
		}
		else if(tablero[x][y+1] == 0)
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y+1);
			return;
		}
	}
	else if(y == n-1)
	{
		if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x+1);
			py->push(y);
			return;
		}
		else if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x-1);
			py->push(y);
			return;
		}
		else if(tablero[x][y-1] == 0)
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			px->push(x);
			py->push(y-1);
			return;
		}
	}
	else if(tablero[x+1][y] == 0) 
	{
		tablero[x+1][y] = tablero[x][y];
		tablero[x][y] = 0;
		px->push(x+1);
		py->push(y);
		return;
	}
	else if(tablero[x-1][y] == 0)
	{
		tablero[x-1][y] = tablero[x][y];
		tablero[x][y] = 0;
		px->push(x-1);
		py->push(y);
		return;
	}
	else if(tablero[x][y+1] == 0)
	{
		tablero[x][y+1] = tablero[x][y];
		tablero[x][y] = 0;
		px->push(x);
		py->push(y+1);
		return;
	}
	else if(tablero[x][y-1] == 0)
	{
		tablero[x][y-1] = tablero[x][y];
		tablero[x][y] = 0;
		px->push(x);
		py->push(y-1);
		return;
	}
	else
	{
		cout << "Try another coordinate" << endl;
		return;
	}
}

void mover_s(int x, int y, int* tablero[], Pila* pxe, Pila* pye, int n)
{
	if(tablero[x][y] == 0)
	{
		cout << "Try another coordinate" << endl;
		return;
	}
	else if(x == 0 && y ==0)
	{

		if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x][y+1] == 0) 
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}	
	}
	else if(x==0 && y == n-1) 
	{
		if(tablero[x][y-1] == 0) 
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
	}
	else if(x==n-1 && y == 0) 
	{
		if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x][y+1] == 0)
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
	}
	else if(x==n-1 && y == n-1) 
	{
		if(tablero[x][y-1] == 0)
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
	}
	else if(x == 0)
	{
		if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x][y+1] == 0)
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x][y-1] == 0)
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
	}
	else if(x == n-1)
	{
		if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x][y+1] == 0)
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x][y-1] == 0)
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
	}
	else if(y == 0)
	{
		if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x][y+1] == 0)
		{
			tablero[x][y+1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
	}
	else if(y == n-1)
	{
		if(tablero[x+1][y] == 0) 
		{
			tablero[x+1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x-1][y] == 0)
		{
			tablero[x-1][y] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
		else if(tablero[x][y-1] == 0)
		{
			tablero[x][y-1] = tablero[x][y];
			tablero[x][y] = 0;
			return;
		}
	}
	else if(tablero[x+1][y] == 0) 
	{
		tablero[x+1][y] = tablero[x][y];
		tablero[x][y] = 0;
		return;
	}
	else if(tablero[x-1][y] == 0)
	{
		tablero[x-1][y] = tablero[x][y];
		tablero[x][y] = 0;
		return;
	}
	else if(tablero[x][y+1] == 0)
	{
		tablero[x][y+1] = tablero[x][y];
		tablero[x][y] = 0;
		return;
	}
	else if(tablero[x][y-1] == 0)
	{
		tablero[x][y-1] = tablero[x][y];
		tablero[x][y] = 0;
		return;
	}
	else
	{
		cout << "Try another coordinate" << endl;
		return;
	}
}

int main()
{
	int n, i, j, a=0, x, y, count, azarx, azary, tope, comp, an;
	bool win = false;
	srand(time(NULL));
	
	cout << "Enter the dimension (n) of the puzzle: (nxn)" << endl;
	cin>>n;
	cout << endl;

	int** tablero = new int*[n];
	for(int i = 0; i<n; ++i)
	{
    	tablero[i] = new int[n];
	}
	
	Pila *px;
	px = new Pila(5000);
	
	Pila *py;
	py = new Pila(5000);
	
	Pila *pxe;
	pxe = new Pila(5000);
	
	Pila *pye;
	pye = new Pila(5000);
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			a = a + 1;
			tablero[i][j] = a;
		}
	}
	
	tablero[n-1][n-1] = 0;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cout << tablero[i][j] << "\t"; 
		}
		cout << endl;
	}
	
	tope = n*n;
	count = 0;
	comp = 0;
	do
	{
		azarx = rand()%n;
		azary = rand()%n;
		
		if(tablero[azarx][azary] == 0)
		{
			//cout << "Prueba otra coordenada" << endl;
		}
		else if(azarx == 0 && azary ==0)
		{
	
			if(tablero[azarx+1][azary] == 0) 
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx][azary+1] == 0) 
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}	
		}
		else if(azarx==0 && azary == n-1) 
		{
			if(tablero[azarx][azary-1] == 0) 
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx+1][azary] == 0) 
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
		}
		else if(azarx==n-1 && azary == 0) 
		{
			if(tablero[azarx-1][azary] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx][azary+1] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
		}
		else if(azarx==n-1 && azary == n-1) 
		{
			if(tablero[azarx][azary-1] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx-1][azary] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
		}
		else if(azarx == 0)
		{
			if(tablero[azarx+1][azary] == 0) 
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx][azary+1] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx][azary-1] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
		}
		else if(azarx == n-1)
		{
			if(tablero[azarx-1][azary] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx][azary+1] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx][azary-1] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
		}
		else if(azary == 0)
		{
			if(tablero[azarx+1][azary] == 0) 
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx-1][azary] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx][azary+1] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
		}
		else if(azary == n-1)
		{
			if(tablero[azarx+1][azary] == 0) 
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx-1][azary] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
			else if(tablero[azarx][azary-1] == 0)
			{
				mover(azarx, azary, tablero, px, py, n);
				count++;
			}
		}
		else if(tablero[azarx+1][azary] == 0) 
		{
			mover(azarx, azary, tablero, px, py, n);
			count++;
		}
		else if(tablero[azarx-1][azary] == 0)
		{
			mover(azarx, azary, tablero, px, py, n);
			count++;
		}
		else if(tablero[azarx][azary+1] == 0)
		{
			mover(azarx, azary, tablero, px, py, n);
			count++;
		}
		else if(tablero[azarx][azary-1] == 0)
		{
			mover(azarx, azary, tablero, px, py, n);
			count++;
		}
		else
		{
			//cout << "Prueba otra coordenada" << endl;
		}
		
		if(comp != count)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					cout << tablero[i][j] << "\t"; 
				}
				cout << endl;
			}
			cout << "-----------------" << endl;
			cout << "Number of random steps: " << count << endl;
			comp++;
		}
	}while(count != tope);
	
	mover(azarx, azary, tablero, px, py, n);
	count++;
	
	count = 0;
	a=0;
	do
	{	
		do
		{
			cout << "Enter the y coordinate:" << endl;
			cin>>x;
		}while(x > n-1 || x < 0);
		
		do
		{
			cout << "Enter the x coordinate: " << endl;
			cin>>y;
		}while(y > n-1 || y < 0);
		
		mover(x, y, tablero, px, py, n);
		
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				cout << tablero[i][j] << "\t"; 
			}
			cout << endl;
		}
		
		if(tablero[n-1][n-1] == 0)
		{
			count++;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				a = a + 1;
				if(tablero[i][j] == a)
				{
					count++;
				}
			}
		}
		if(count == (n*n))
		{
			win = true;
		}
		//cout << "Count: " << count << endl;
		count = 0;
		a = 0;
		
		do
		{	
			cout << "If you want to return a move type -1, if you want to advance a move type 1, if you want it to be resolved automatically type 2, and if you do not want to use these options type 0." << endl;
			cin>>an;
		}while(an < -1 || an > 2);
		switch(an)
		{
			case -1:
				x = px->pop();
				y = py->pop();
				mover_s(x, y, tablero, px, py, n);
				for(i=0; i<n; i++)
				{
					for(j=0; j<n; j++)
					{
						cout << tablero[i][j] << "\t"; 
					}
					cout << endl;
				}
				break;
			case 0:
				break;
			case 1:
				x = pxe->pop();
				y = pye->pop();
				mover_s(x, y, tablero, px, py, n);
				for(i=0; i<n; i++)
				{
					for(j=0; j<n; j++)
					{
						cout << tablero[i][j] << "\t"; 
					}
					cout << endl;
				}
				if(tablero[n-1][n-1] == 0)
				{
					count++;
				}
				for(i=0; i<n; i++)
				{
					for(j=0; j<n; j++)
					{
						a = a + 1;
						if(tablero[i][j] == a)
						{
						count++;
						}	
					}
				}
				if(count == (n*n))
				{
					win = true;
				}
				count = 0;
				a = 0;
				break;
			case 2:
				do
				{
					x = px->pop();
					y = py->pop();
					mover_s(x, y, tablero, px, py, n);
					for(i=0; i<n; i++)
					{
						for(j=0; j<n; j++)
						{
							cout << tablero[i][j] << "\t"; 
						}
						cout << endl;
					}
					cout << "----------------" << endl;
				}while(px->gettop() != 0);
				win = true;
				break;	
		}
		
	}while(win == false);
	
	cout << "You won!" << endl;
	
}
