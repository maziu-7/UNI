#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("list.hh")
#include "list.hh"
#endif
#endif

struct Container {
    string word;
    Container() {
        word = "";
    }
    Container(const Container &c)
    {
        if (this == &c) return;
    	word = c.word;
    }
	Container &operator=(const Container &c)
	{
    	word = c.word;
        return *this;
	}
};

int main()
{
    List<Container> l;
    List<Container>::iterator it = l.begin();
    List<Container>::iterator itaux = l.begin();
    string command;
    while (cin >> command) {
        if (command == "push_back") {
            Container c;
            cin >> c.word;
            l.push_back(c);
        } else if (command == "push_front") {
            Container c;
            cin >> c.word;
            l.push_front(c);
        } else if (command == "pop_back") {
            l.pop_back();
        } else if (command == "pop_front") {
            l.pop_front();
        } else if (command == "it++") {
            it++;
            itaux++;
        } else if (command == "it--") {
            it--;
            itaux--;
        } else if (command == "moveToEnd") {
            l.moveToEnd(it);
        } else if (command == "*it") {
            cout << (*itaux).word << endl;
        }
    }
}
