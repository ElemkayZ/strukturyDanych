#pragma once


struct Pair
{
    int key;
    int value;
    Pair() : key(-1), value(-1) {};
    Pair(int _key, int _value) : key(_key), value(_value) {}
};