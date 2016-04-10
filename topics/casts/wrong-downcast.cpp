struct Animal { virtual ~Animal(); };
struct Dog : public Animal { };
struct Cat : public Animal { };

Animal* cat = new Cat;
Dog* dog = (Dog*) cat;
