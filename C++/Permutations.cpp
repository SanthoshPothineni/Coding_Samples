***********************************************
  Author: Santhosh Pothineni
  Date: 12/5/21

  Purpose: Generates and prints all permutaions of input, ignores duplicate values in the input
***********************************************/
#include <iostream>
#include <algorithm>
#include<list>
#include <fstream>
#include <sstream>
#include<string>

using namespace std;

template <class T>
list<list<T>> generate_permutations(list<T> il);

template <class ListofLists>
void print_permutations(ListofLists permutations);

int main(int argc, char* argv[])
{
    list<string> inputList;
    string aLine, aString;

    // read in strings from stdin 
    cout << "Enter strings, separated by a space:";
    getline(cin, aLine); //read a line from keyboard 
    istringstream iss(aLine); //convert aLine to an istringstream obj 
    //COMP.2010            HW 11  F21
    

        //parse each string 
        while (iss >> aString)
        {
            inputList.push_back(aString);
        }

    auto permutations = generate_permutations(inputList);

    // print permutations to stdout 
    print_permutations(permutations);

    return 0;
}
template <class T>
list<list<T>> generate_permutations(list<T> il)
{
    list<list<T>>temp;
    il.sort();
    il.unique();// removes duplicates from list
    do {
        temp.push_back(il);
    } while (next_permutation(il.begin(), il.end()));// gets next permutation
    return temp;
}

template <class ListofLists>
void print_permutations(ListofLists permutations)
{
    int num = 1;
    for (const auto& i : permutations)// runs through each list in list of lists
    {
        cout << num << ". ";
        for (const auto& j : i) //prints all values from each list stored in outerlist
        {
            cout << j << "  ";
        }
        cout << endl;
        num++;
    }
}
