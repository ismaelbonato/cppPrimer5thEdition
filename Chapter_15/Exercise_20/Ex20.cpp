

class Base
{
public:
    void pub_mem();
    void memfcn(Base &b) { b = *this; }

protected:
    int prot_mem;

private:
    char priv_mem;
};

class Sneaky : public Base
{
    friend void clobber(Sneaky &);
    friend void clobber(Base &);
    void memfcn(Base &b) { b = *this; }

    int j;
};

void clobber(Sneaky &s)
{
    s.j = s.prot_mem = 0;
}

void clobber(Base &b)
{
    //b.prot_mem = 0;
}

struct Pub_Derv : public Base
{
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }

    //char g() { return priv_mem; }
};

struct Priv_Derv : private Base
{
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }

};

struct Prot_Derv : protected Base
{
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }

};

struct Derived_from_Public : public Pub_Derv
{
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }

};
struct Derived_from_Private : public Priv_Derv
{
    void memfcn(Base &b) { b = *this; }

};

struct Derived_from_Protected : public Prot_Derv
{
    void memfcn(Base &b) { b = *this; }
};

int main()
{
    { // Ex15.18
     /* Pub_Derv d1;
        Priv_Derv d2;
        Prot_Derv d3;
        Derived_from_Public dd1;
        Derived_from_Private dd2;
        Derived_from_Protected dd3;
    
        Base *p = &d1;
        p = &d2;
        p = &d3;
        p = &dd1;
        p = &dd2;
        p = &dd3;
    */
    }
    
    { // Ex 15.19
    }

    return 0;
}