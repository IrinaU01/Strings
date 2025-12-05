#include <iostream>;
using namespace std;
#include "String.h";

int main()
{
    cout << "Initial number of objects: " << String::get_object_count() << "\n\n";

    String s1;
    cout << " s1 (Default).\n";
    s1.read_from_keyboard();
    s1.display();
    cout << "Initial number of objects: " << String::get_object_count() << "\n\n";

    String s2(30);
    cout << " s2 (Sized, 30).\n";
    s2.read_from_keyboard();
    s2.display();
    cout << "\n";

    String s3("Text String");
    cout << " s3 (Initialized).\n";
    s3.display();
    cout << "Current number of objects: " << String::get_object_count() << "\n\n";
    

    {
        String s4("Temporary");
        cout << "Objects number in the block: " << String::get_object_count() << "\n";
    }

    cout << "Objects number outside of the block: " << String::get_object_count() << "\n\n";

    return 0;
}