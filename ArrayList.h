#pragma once

class ArrayList {
private:
    int *array;
    int capacity;
    int size;

public:
    ArrayList(int startSize = 10);
    ~ArrayList();

    void add(int element);
    int get(int index) const;
    int getSize() const;
    void insert( int index, int element);
    int search(int element) const;
    void print() const;
    void remove(int index);
private:
    void resize();
};