#include <iostream>
#include <string>
using namespace std;

class document{
    string *content;

    public:
    document(string original) {
        content = new string(original);
        *content = original;
    }

    document(document &other){
        content = new string(*other.content);
    }

    ~document(){delete content;}

    void setContent(string con){
        *content = con;
    }

    void operator = (document &other) {
        delete content;
        content = new string(*other.content);
       
    }

    void display(){cout << *content << endl;}
};

int main(){
    document d1("This is some content.");
    document d2(d1);
    document d3 = d1;
    d1.display();
    d2.display();
    d3.display();
    d1.setContent("Changes are made to the content.");
    d1.display();
    d2.display();
    d3.display();


    return 0;
}