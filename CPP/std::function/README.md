A type-erasing wrapper containing a callable thing with a specificn signature.
Callable things: Function pointers, Objects with a call operator(functor ), Lambda fucntions
functions:


int add(int a,int b){return a+b;}
struct Add{
	int operator()(int x,int y) const{
		return x+y;
	}
};

std::function<int(int,int)> f;
f = add; // function
f = add(); // functor
f = [](int x,int y){return x+y;}; // lambda


std::fucntion has transformed the way async callbacks are written.
