#pragma once
class IDGenerator{
public:
    IDGenerator();

    int getNextID(); 

private:
    int next_id;
};