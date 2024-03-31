#include <iostream>
#include <vector>

using namespace std;

class HashTable
{
    int size;
    vector<vector<int>> table;

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
        int hashValue = 0;
        val = abs(val);
        string valString = to_string(val);
        int chunkSize = to_string(size).length()-1, startPos = 0;
        while(startPos<valString.length()){
            string chunk = valString.substr(startPos,chunkSize);
            hashValue+=stoi(chunk);
            startPos+=chunkSize;
        }
        string hashValueSt = to_string(hashValue);
        startPos = hashValueSt.length() - chunkSize;
        cout<<hashValue<<endl;
        if(startPos > 0){
            string subH = hashValueSt.substr(startPos,chunkSize);
            hashValue = stoi(subH);
            cout<<subH<<endl;
        }
        return hashValue;
    }

public:
    HashTable(int size)
    {
        this->size = size;
        table.resize(size);
    }

    bool insertVal(int val)
    {
        if (searchVal(val) != -1)
        {
            return true;
        }
        int hashKey = generateHashKey(val);
        bool collision = !table[hashKey].empty();
        table[hashKey].push_back(val);
        return collision;
    }

    bool deleteVal(int val)
    {
        int index = searchVal(val);
        if (index == -1)
        {
            return false;
        }
        int hashKey = generateHashKey(val);
        table[hashKey].erase(table[hashKey].begin() + index);
        return true;
    }

    int searchVal(int val)
    {
        int hashKey = generateHashKey(val);
        if (!table[hashKey].empty())
        {
            for (int i = 0; i < table[hashKey].size(); i++)
            {
                if (table[hashKey][i] == val)
                    return i;
            }
        }

        return -1;
    }

    void printTable()
    {
        for (auto row : table)
        {
            if (row.empty())
                cout << "NULL" << endl;
            else
            {
                for (int i : row)
                {
                    cout << i << "-->";
                }
                cout << endl;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    int n, ch, val;
    cout << "Enter the size of hash table- ";
    cin >> n;
    HashTable hashTable(n);
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
                cout << "Collision occured. Inserted Successfully." << endl;
            }
            else
                cout << "Inserted successfully." << endl;
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
            if (hashTable.searchVal(val) != -1)
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