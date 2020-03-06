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
	if(top == sizeof(stack))
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
		cout << "Fila llena" << endl;
		return;
	}
	stack[top] = a;
	top++;
}

int Pila::pop()
{
	if(underflow() == true)
	{
		cout << "Pila vacia" << endl;
		return 0;
	}
	top--;
	return stack[top];
}

void Cola::enqueue(int a)
{
	if(overflow())
	{
		cout << "Cola llena" << endl;
		return;
	}
	//if(tail == -1) { tail++; } //
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
		cout << "Cola vacia" << endl;
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

void mover(int x, int y, int* tablero[], Pila* px, Pila* py)
{
	if(tablero[x][y] == 0)
	{
		cout << "Prueba otra coordenada" << endl;
		return;
	}
	else if(tablero[x+1][y] == 0) //Revisa si abajo está libre
	{
		tablero[x+1][y] = tablero[x][y];
		tablero[x][y] = 0;
		px->push(x);
		py->push(y);
		cout << "Just a validation 1" << endl;
		return;
	}
	else if(tablero[x-1][y] == 0)
	{
		cout << "Just a validation 2" << endl;
		tablero[x-1][y] = tablero[x][y];
		tablero[x][y] = 0;
		px->push(x);
		py->push(y);
		return;
	}
	else if(tablero[x][y+1] == 0)
	{
		cout << "Just a validation 3" << endl;
		tablero[x][y+1] = tablero[x][y];
		tablero[x][y] = 0;
		px->push(x);
		py->push(y);
		return;
	}
	else if(tablero[x][y-1] == 0)
	{
		cout << "Just a validation 4" << endl;
		tablero[x][y-1] = tablero[x][y];
		tablero[x][y] = 0;
		px->push(x);
		py->push(y);
		return;
	}
	else
	{
		cout << "Prueba otra coordenada" << endl;
		return;
	}
	cout << "chale" << endl;
}

int main()
{
	int n, i, j, a=0, x, y, count, azarx, azary, tope;
	bool win = false;
	srand(time(NULL));
	
	cout << "Dame la dimension del rompecabezas" << endl;
	cin>>n;
	cout << endl;

	int** tablero = new int*[n];
	for(int i = 0; i<n; ++i)
	{
    	tablero[i] = new int[n];
	}
	
	Pila *px;
	px = new Pila(n*n*n);
	
	Pila *py;
	py = new Pila(n*n*n);
	
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
	
	//REVOLVER 
	/*
	tope = n*n;
	count = 0;
	do
	{
		azarx = rand()%n;
		azary = rand()%n;
		if(tablero[azarx+1][azary] == 0)
		{
			mover(azarx, azary, tablero, px, py);
			count++;
			
			//IMPRIME LA MATRIZ
				
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					cout << tablero[i][j] << "\t"; 
				}
				cout << endl;
			}
		}
		else if(tablero[azarx-1][azary] == 0)
		{
			mover(azarx, azary, tablero, px, py);
			count++;
			
			//IMPRIME LA MATRIZ
				
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					cout << tablero[i][j] << "\t"; 
				}
				cout << endl;
			}
		}
		else if(tablero[azarx][azary+1] == 0)
		{
			mover(azarx, azary, tablero, px, py);
			count++;
			
			//IMPRIME LA MATRIZ
				
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					cout << tablero[i][j] << "\t"; 
				}
				cout << endl;
			}
		}
		else if(tablero[azarx][azary-1] == 0)
		{
			mover(azarx, azary, tablero, px, py);
			count++;
			
			//IMPRIME LA MATRIZ
				
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					cout << tablero[i][j] << "\t"; 
				}
				cout << endl;
			}
		}
	}while(count != tope);
	*/
	
	
	count = 0;
	a=0;
	do
	{
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
		if(count == n*n)
		{
			win = true;
		}
		count = 0;
		
		do
		{
			cout << "Dame la coordenada de x:" << endl;
			cin>>x;
		}while(x > n-1 || x < 0);
		
		do
		{
			cout << "Dame la coordenada de y: " << endl;
			cin>>y;
		}while(y > n-1 || y < 0);
		
		cout << "Hora de mover la pieza" << endl;
		//MOVER LA PIEZA
		mover(x, y, tablero, px, py);
		cout << "F" << endl;
		
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				cout << tablero[i][j] << "\t"; 
			}
			cout << endl;
		}
	}while(win == false);
	
	cout << "Ganaste xd" << endl;
	
}
