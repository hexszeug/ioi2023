#ifndef INTLIST_H
#define INTLIST_H


class IntList {
private:
    int len;
    int cap;
    int* arr;
public:
    IntList() {
        len = 0;
        cap = 1;
        arr = new int[cap];
    }
    ~IntList() {
        delete arr;
    }
    int get(int index) {
        return arr[index];
    }
    void append(int elm) {
        if (len >= cap) {
            cap = cap << 1;
            int* newArr = new int[cap];
            for (int i = 0; i < len; i++) {
                newArr[i] = arr[i];
            }
            delete arr;
            arr = newArr;
        }
        arr[len] = elm;
        len++;
    }
    int size() {
        return len;
    }
};

#endif // INTLIST_H
