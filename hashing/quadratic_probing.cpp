#include <iostream>
#include <vector>

using namespace std;

class HashTable
{
    int size, c1, c2;
    vector<int> table, prob; // 1d array

    // int countDigits(int val)
    // {
    //     int digits = 1;
    //     while (val >= 10)
    //     {
    //         val = val / 10;
    //         digits++;
    //     }
    //     return digits;
    // }

    int generateHashKey(int val)
    {
        int hashKey = -1, i = 1, quadProb;
        val = abs(val);
        hashKey = val % size;

        if(table[hashKey] == -1 || table[hashKey] == val){
            return hashKey;
        }

        cout<<"Collision occured"<<endl;

        do{
            quadProb = (hashKey + c1 * i + (c2 * (i * i))) % size;
            if (table[quadProb] == -1 || table[quadProb] == val)
            {
                return hashKey;
            }
            i++;
        }while (i < size);

        return -1;
    }

public:
    HashTable(int size, int c1, int c2) : c1(c1), c2(c2), size(size)
    {
        table.resize(size, -1);
    }

    bool insertVal(int val)
    {
        if (searchVal(val))
        {
            return true;
        }
        int hashKey = generateHashKey(val);
        if (hashKey != -1)
        {
            table[hashKey] = val;
            return true;
        }
        return false;
    }

    bool deleteVal(int val)
    {
        if (!searchVal(val))
        {
            return false;
        }
        int index = generateHashKey(val);
        table[index] = -1;
        return true;
    }

    bool searchVal(int val)
    {
        int hashKey = generateHashKey(val);
        if (hashKey != -1)
            return table[hashKey] == val;
        else
            return false;
    }

    void printTable()
    {
        for (int i = 0; i < size; i++)
        {
            // if(table[i] == -1){
            //     cout<<"NULL"<<endl;
            // }
            // else{
            cout << table[i] << endl;
            // }
        }
    }
};

int main(int argc, char *argv[])
{
    int n, ch, val, c1, c2;
    cout << "Enter the size of hash table- ";
    cin >> n;
    cout << "Enter constant c1- ";
    cin >> c1 >> c2;
    HashTable hashTable(n, c1, c2);
    while (true)
    {
        cout << "\n1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Search" << endl;
        cout << "4.Print Table" << endl;
        cout << "5.Exit\n"
             << endl;
        cout << "Enter your choice- ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value to insert- ";
            cin >> val;
            if (hashTable.insertVal(val))
            {
                cout << "Inserted Successfully." << endl;
            }
            else
                cout << "Insertion unsuccessful. No space available." << endl;
            break;

        case 2:
            cout << "Enter the value to delete from hash table- ";
            cin >> val;
            if (hashTable.deleteVal(val))
            {
                cout << val << " deleted successfully from hash table." << endl;
            }
            else
                cout << val << " not found in hash Table." << endl;
            break;

        case 3:
            cout << "Enter the value to search in the hash table- ";
            cin >> val;
            if (hashTable.searchVal(val))
            {
                cout << val << " found." << endl;
            }
            else
                cout << val << " not found in hash Table." << endl;
            break;

        case 4:
            hashTable.printTable();
            cout << endl;
            break;

        case 5:
            exit(0);

        default:
            cout << "Please enter a correct choice." << endl;
        }
    }
}