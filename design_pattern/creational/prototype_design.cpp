#include <iostream>

class prototype {
public:
    virtual prototype *clone() const = 0;
    virtual void show() const = 0;
    virtual ~prototype() = default;
}

class warrior : public prototype{
    string weaponType;

public:
    warrior(string weapon)
    {
        this->weaponType = weapon;
    }

    prototype *clone() const override
    {
        return new warrior(*this);
    }

    void show() const override
    {
        cout << "warrior with weapon" << weaponType << endl;
    }
} 

class maze : public prototype
{
    string weaponType;

public:
    maze(weapon)
    {
        this->weaponType = weapon;
    }

    prototype *clone() const override
    {
        return new maze(*this);
    }

    void show() const override
    {
        cout << "MAZE with weapon" << weapon << endl;
    }
} 

class prototypeFactory
{
    unordered_map<String, prototype *> prototypes;

public:
    prototypeFactory()
    {
        prototypes["warrior"] = new warrior("sword");
        prototypes["maze"] = new maze("knife");
    }

    prototype *create(string warriorType)
    {
        if (prototypes.find(warriorType) != prototypes.end())
        {
            return prototypes[warriorType]->clone();
        }
        return nullptr;
    }
}

int main(){

    prototypeFactory factory;

    prototype warrior1 = factory.create("warrior");
    prototype maze1 = factory.create("maze");

    warrior1->show();
    maze1->show();
}
