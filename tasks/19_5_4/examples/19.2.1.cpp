class vector {

	vector() :sz(0), elem(0), space(0) {}
    vector(int s) :sz(s), elem(new double[s]) , space(s)
        {
            for (int i=0; i<sz; ++i) elem[i]=0; // элементы
        }// инициализированы

    vector(const vector&); // копирующий конструктор
    vector& operators(const vector&); // копирующее присваивание
    ~vector() { delete[] elem; } // деструктор

    const double operator[](int n) const { return elem[n]; } // const return element
    double& operator[](int n) { return elem[n]; }

	int sz;
	double* elem;
	int space;

public:

	void reserve(int newalloc);
	void cut(int newalloc);

    int size() const { return sz; }
	int capacity() const { return space; }

	void resize(int newsize);
	void push_back(double d);

	vector& operator=(const vector& a);
};

void vector::reserve(int newalloc)
{
    if (newalloc <= space) return;
    double* p = new double[newalloc];
    for (int i=0; i<sz; ++i) p[i] = elem[i];

    delete[] elem;
    elem = p;
    space = newalloc;
}

void vector::cut(int newcut)
{
	if (newcut > space) return;
	int i = 0;
	while (sz > newcut)
	{
		elem[sz - i] = 0;
		i++;
	}
	sz = newcut;
}

void vector::resize(int newsize)
{
	if (newsize == sz) return;
	if (newsize < sz) cut(newsize);

	reserve(newsize);
	for (int i = sz; i < newsize; ++i) elem[i] = 0;
	sz = newsize;
}

void vector::push_back(double d)
{
	if (space == 0) reserve(8);
	else if (sz == space) reserve(2*space);
	elem[sz] = d;
	++sz;
}

vector& vector::operator=(const vector& a)
// похож на конструктор копирования,
// но мы должны работать со старыми элементами
{
    if (this == &a) return *this;
    if (a.sz <= space)
    {
        for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];\
        sz = a.sz;

        return *this;
    }

	double *p = new double[a.sz]; // выделяем новую память
	for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i] ; // копируем
// элементы
	delete[] elem; // освобождаем старую память
	space = sz = a.sz; // устанавливаем новый размер
	elem = p; // устанавливаем новые элементы
	return *this;
}

int main()
{
	return 0;
}
