#include <iostream>
using namespace std;

class Kopiec {
private:
	int rozmiar;
	int tab[8192];
public:
	Kopiec::Kopiec();
	void heapify(int i);
	void build(int tab[], int rozmiar);
	void clear();
	void join(Kopiec kopiec);
	void print();
	void push(int v);
	void pop();
};

Kopiec::Kopiec()
{
	rozmiar = 0;
}

void Kopiec::heapify(int i)
{
	
	int larg = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if ((l < rozmiar) && (tab[l] > tab[larg])) larg = l;
	if ((r < rozmiar) && (tab[r] > tab[larg])) larg = r;

	if (larg != i)
	{
		swap(tab[i], tab[larg]);
		heapify(larg);
	}
}
void Kopiec::build(int tabpom[], int roz)
{
	rozmiar = roz;
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = tabpom[i];
	}
	for (int i = (roz / 2) - 1; i >= 0; i--)
		heapify(i);
}
void Kopiec::print()
{
	
	for (int i = 0; i < rozmiar; i++)
		cout << tab[i] << " ";
	cout << "\n";
}
void Kopiec::clear()
{
	while (rozmiar = 0)
	{
		rozmiar--;
	}
}
void Kopiec::join(Kopiec kopiec)
{
	//cout << rozmiar << endl;//
	//cout << kopiec.rozmiar << endl;//

	int rozmiar1 = rozmiar;
	rozmiar = rozmiar + kopiec.rozmiar;
	//cout << rozmiar << endl;//
	int *tab_lacz;
	tab_lacz = new int[rozmiar];

	for (int i = 0; i < rozmiar1; i++)
	{
		tab_lacz[i] = tab[i];
	}
	int j = 0;
	int i = rozmiar1;
	while ((i < rozmiar) && (j < kopiec.rozmiar))
	{
		tab_lacz[i] = kopiec.tab[j];
		i++;
		j++;
	}

	build(tab_lacz, rozmiar);
	delete[] tab_lacz;
}
void Kopiec::push(int v)
{
	int i, j;

	i = rozmiar++;					// do i idzie rozmiar, zwiekszamy go
	j = (i - 1) / 2;				// indeks ojca

	while (i > 0 && tab[j] < v)		// spraawdzamy warunek kopca
	{
		tab[i] = tab[j];			// ojciec idzie na mniejsce syna
		i = j;						// idziemy na pozycje gdzie jest ojciec
		j = (i - 1) / 2;			// liczymy indeks ojca
	}

	tab[i] = v;						// wstawiamy elem do kopca
}
void Kopiec::pop()
{
	cout << tab[0] << "\n";
	int i, j, v;

	if (rozmiar--)
	{
		v = tab[rozmiar];						// w v zapamiętujemy ostatni elem

		i = 0;									// korzen
		j = 1;									// j lewym synem

		while (j < rozmiar)						// schodzimy w dol
		{
			if (j + 1 < rozmiar && tab[j + 1] > tab[j]) j++; // szukamy wiekszego syna
			if (v >= tab[j]) break;							// jesli warunek kopca spelniony wychodzimy
			tab[i] = tab[j];								// inaczej kopiujemy wiekszego syna do ojca
			i = j;											// przechodzimy na pozycje gdzie jest wiekszy syn
			j = 2 * j + 1;									// j wskazuje lewego syna
		}

		tab[i] = v;											// umieszczmy w kopcu
	}
}

int main()
{
	int *tabpom;
	int n, nr, v, a, b;
	char znak;
	Kopiec kop[10];


	while (cin.good())
	{
		cin >> znak;

		switch (znak)
		{
		case '+':
			cin >> nr;
			cin >> v;
			kop[nr].push(v);
			break;
		case '-':
			cin >> nr;
			kop[nr].pop();
			break;
		case 'p':
			cin >> nr;
			kop[nr].print();
			break;
		case 'r':
			cin >> nr;
			kop[nr].clear();
			cin >> n;
			tabpom = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> tabpom[i];
			}
			kop[nr].build(tabpom, n);
			delete[] tabpom;
			break;
		case 'j':
			cin >> a;
			cin >> b;
			kop[a].join(kop[b]);
			kop[b].clear();
			break;
		case 'q':
			exit(0);
			break;
		}
	}

	return 0;
}

