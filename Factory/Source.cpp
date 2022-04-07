#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Pizza;
class PizzaIngredientFactory;
class PizzaStore;

class Pizza {
public:
    Pizza(PizzaIngredientFactory *ingredientFactory) {
        m_cost = NULL;
        m_ingredientFactory = ingredientFactory;
    }
    virtual ~Pizza() {
        if (m_ingredientFactory != NULL) {
            delete m_ingredientFactory;
        }
    }
    void setName(string name) {
        m_name = name;
    }
    string getName() {
        return m_name;
    }
    void setCost(float c) {
        m_cost = c;
    }
    float getCost()
    {
        return m_cost;
    }

protected:
    string m_name;
    float m_cost = 0;
    PizzaIngredientFactory* m_ingredientFactory;
};

class ClamPizza : public Pizza {
public:
    ClamPizza(PizzaIngredientFactory *ingredientFactory) : Pizza(ingredientFactory) {}
    virtual ~ClamPizza() {}
};

class CheesePizza : public Pizza {
public:
    CheesePizza(PizzaIngredientFactory *ingredientFactory) : Pizza(ingredientFactory) {}
    virtual ~CheesePizza() {}
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza(PizzaIngredientFactory *ingredientFactory) : Pizza(ingredientFactory) {}
    virtual ~PepperoniPizza() {}
};

class VeggiePizza : public Pizza {
public:
    VeggiePizza(PizzaIngredientFactory *ingredientFactory) : Pizza(ingredientFactory) {}
    virtual ~VeggiePizza() {}
};


class PizzaIngredientFactory {
public:
    PizzaIngredientFactory() {}
    virtual ~PizzaIngredientFactory() {}

};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    NYPizzaIngredientFactory() {}
    virtual ~NYPizzaIngredientFactory() {}
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    ChicagoPizzaIngredientFactory() {}
    virtual ~ChicagoPizzaIngredientFactory() {}
};

class PizzaStore {
public:
    PizzaStore() {}
    virtual ~PizzaStore() {}
    virtual Pizza* createPizza(std::string item) = 0;
    Pizza* orderPizza(string type) {
        Pizza* pizza = createPizza(type);
        //cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore {
public:
    ChicagoPizzaStore() {}
    virtual ~ChicagoPizzaStore() {}
    Pizza* createPizza(string item) {
        Pizza* pizza = NULL;
        PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory();
        if (item == "cheese") {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("Chicago Style Cheese Pizza");
            pizza->setCost(12.99);
        }
        else if (item == "veggie") {
            pizza = new VeggiePizza(ingredientFactory);
            pizza->setName("Chicago Style Veggie Pizza");
            pizza->setCost(13.99);
        }
        else if (item == "clam") {
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("Chicago Style Clam Pizza");
            pizza->setCost(6.99);
        }
        else if (item == "pepperoni") {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza->setName("Chicago Style Pepperoni Pizza");
            pizza->setCost(3.99);
        }
        return pizza;
    }
};

class NYPizzaStore : public PizzaStore {
public:
    NYPizzaStore() {}
    virtual ~NYPizzaStore() {}
    Pizza* createPizza(string item) {
        Pizza* pizza = NULL;
        PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory();
        if (item == "cheese") {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("New York Style Cheese Pizza");
            pizza->setCost(13.99);
        }
        else if (item == "veggie") {
            pizza = new VeggiePizza(ingredientFactory);
            pizza->setName("New York Style Veggie Pizza");
            pizza->setCost(17.99);
        }
        else if (item == "clam") {
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("New York Style Clam Pizza");
            pizza->setCost(20.99);
        }
        else if (item == "pepperoni") {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza->setName("New York Style Pepperoni Pizza");
            pizza->setCost(4.99);
        }
        return pizza;
    }
};


int main() {

    PizzaStore* nyStore = new NYPizzaStore();
    PizzaStore* chicagoStore = new ChicagoPizzaStore();

    Pizza* pizza = nyStore->orderPizza("cheese");
    cout << "Ethan ordered a " << pizza->getName() << " for " << pizza->getCost() <<endl;
    delete pizza;

    pizza = chicagoStore->orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->getName() << " for " << pizza->getCost() << endl;
    delete pizza;

    pizza = nyStore->orderPizza("clam");
    std::cout << "Ethan ordered a " << pizza->getName() << " for " << pizza->getCost() << endl;
    delete pizza;

    pizza = chicagoStore->orderPizza("clam");
    std::cout << "Joel ordered a " << pizza->getName() << " for " << pizza->getCost() << endl;
    delete pizza;

    pizza = nyStore->orderPizza("pepperoni");
    std::cout << "Ethan ordered a " << pizza->getName() << " for " << pizza->getCost() << endl;
    delete pizza;

    pizza = chicagoStore->orderPizza("pepperoni");
    std::cout << "Joel ordered a " << pizza->getName() << " for " << pizza->getCost() << endl;
    delete pizza;

    pizza = nyStore->orderPizza("veggie");
    std::cout << "Ethan ordered a " << pizza->getName() << " for " << pizza->getCost() << endl;
    delete pizza;

    pizza = chicagoStore->orderPizza("veggie");
    std::cout << "Joel ordered a " << pizza->getName() << " for " << pizza->getCost() << endl;
    delete pizza;

    delete nyStore;
    delete chicagoStore;

    return 0;
}

