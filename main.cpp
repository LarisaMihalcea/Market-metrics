#include <iostream>
#include <vector>
#include<string>

using namespace std;

class Person {
public:
    string mName;
    string mProducts;
    double mSalary;

    Person() {
        mName = "";
        mProducts = "None";
        mSalary = 0;
    }

    Person(string Name, string Product, double Salary) {
        mName = Name;
        mProducts = Product;
        mSalary = Salary;
    }

    bool operator==(const Person &p) const {
        if (mName == p.mName && mSalary == p.mSalary)
            return true;
        else return false;
    }

    bool operator<(const Person &p) const {
        if (mName < p.mName)
            return true;
        else return false;
    }
};

class Product {
public:
    string mName;
    string mType;
    double mPrice;

    Product() {
        mType = "None";
        mPrice = 0;
        mName = "";
    }

    Product(string Name, string Type, double Price) {
        mName = Name;
        mType = Type;
        mPrice = Price;
    }

    bool operator==(const Product &p) const {
        if (mName == p.mName && mPrice == p.mPrice)
            return true;
        else return false;
    }

    bool operator<(const Product &p) const {
        if (mName < p.mName)
            return true;
        else return false;
    }
};

class Store {
protected:
    string mStoreName;
    string mType;
    vector<Person> mBuyers;
    vector<Product> mProducts;
public:
    Store(string StoreName, string Type) {
        mStoreName = StoreName;
        mType = Type;
    }

    virtual void add(const Person &p) = 0;

    virtual void remove(const Person &p) = 0;

    virtual void addProduct(const Product &p) = 0;

    virtual void removeProduct(const Product &p) = 0;

    virtual Store *operator+() = 0;

    virtual Store *operator-(const Person &p) = 0;

    string getStoreName() const {
        return mStoreName;
    }

    string getType() const {
        return mType;
    }

    uint16_t getBuyersSize() const {
        return mBuyers.size();
    }

    uint16_t getProductsSize() const {
        return mProducts.size();
    }

    Person getBuyers(uint16_t index) const {
        return mBuyers[index];
    }

    Product getProducts(uint16_t index) const {
        return mProducts[index];
    }
};

class MiniMarket : public Store {
public:
    MiniMarket(string nume_minimarket) : Store(nume_minimarket, "MiniMarket") {
        mBuyers.clear();
        mProducts.clear();
    }

    Store *operator+() {
        return this;
    }

    Store *operator-(const Person &p) {
        return this;
    }

    void add(const Person &p) override {
        mBuyers.push_back(p);
    }

    void remove(const Person &p) override {
        for (int i = 0; i < getBuyersSize(); i++) {
            if (mBuyers[i].mName == p.mName) {
                vector<Person>::iterator it = mBuyers.begin() + i;
                mBuyers.erase(it);
            }
        }
    }

    void addProduct(const Product &p) {
        mProducts.push_back(p);
    }

    void removeProduct(const Product &p) {
        for (int i = 0; i < getProductsSize(); i++) {
            if (mProducts[i].mName == p.mName) {
                vector<Product>::iterator it = mProducts.begin() + i;
                mProducts.erase(it);
            }
        }
    }

};

class Market : public Store {
public:
    Market(string nume_market) : Store(nume_market, "Market") {
        mBuyers.clear();
        mProducts.clear();
    }

    Store *operator+() {
        return this;
    }

    Store *operator-(const Person &p) {
        return this;
    }

    void add(const Person &p) {
        mBuyers.push_back(p);
    }

    void remove(const Person &p) {
        for (int i = 0; i < getBuyersSize(); i++) {
            if (mBuyers[i].mName == p.mName) {
                vector<Person>::iterator it = mBuyers.begin() + i;
                mBuyers.erase(it);
            }
        }
    }

    void addProduct(const Product &p) {
        mProducts.push_back(p);
    }

    void removeProduct(const Product &p) {
        for (int i = 0; i < getProductsSize(); i++) {
            if (mProducts[i].mName == p.mName) {
                vector<Product>::iterator it = mProducts.begin() + i;
                mProducts.erase(it);
            }
        }
    }
};

class SuperMarket : public Store {
public:
    SuperMarket(string nume_supermarket) : Store(nume_supermarket, "SuperMarket") {
        mBuyers.clear();
        mProducts.clear();
    }

    Store *operator+() {
        return this;
    }

    Store *operator-(const Person &p) {
        return this;
    }

    void add(const Person &p) {
        mBuyers.push_back(p);
    }

    void remove(const Person &p) {
        for (int i = 0; i < getBuyersSize(); i++) {
            if (mBuyers[i].mName == p.mName) {
                vector<Person>::iterator it = mBuyers.begin() + i;
                mBuyers.erase(it);
            }
        }
    }

    void addProduct(const Product &p) {
        mProducts.push_back(p);
    }

    void removeProduct(const Product &p) {
        for (int i = 0; i < getProductsSize(); i++) {
            if (mProducts[i].mName == p.mName) {
                vector<Product>::iterator it = mProducts.begin() + i;
                mProducts.erase(it);
            }
        }
    }
};

class Mall : public Store {
public:
    Mall(string nume_mall) : Store(nume_mall, "Mall") {
        mBuyers.clear();
        mProducts.clear();
    }

    Store *operator+() {
        return this;
    }

    Store *operator-(const Person &p) {
        return this;
    }

    void add(const Person &p) {
        mBuyers.push_back(p);
    }

    void remove(const Person &p) {
        for (int i = 0; i < getBuyersSize(); i++) {
            if (mBuyers[i].mName == p.mName) {
                vector<Person>::iterator it = mBuyers.begin() + i;
                mBuyers.erase(it);
                break;
            }
        }
    }

    void addProduct(const Product &p) {
        mProducts.push_back(p);
    }

    void removeProduct(const Product &p) {
        for (int i = 0; i < getProductsSize(); i++) {
            if (mProducts[i].mName == p.mName) {
                vector<Product>::iterator it = mProducts.begin() + i;
                mProducts.erase(it);
            }
        }
    }
};

int main() {
    vector<Store *> magazin;
    string comanda;
    string tip_cuvant2;
    string nume_magazin, nume_persoana, nume_produs, tip_produs;
    double salariu_mm = 0, salariu_m = 0, salariu_sp = 0, salariu_mall = 0;
    int nr_pers_sterse_m=0, nr_pers_sterse_mm=0,nr_pers_sterse_sp=0,nr_pers_sterse_mall=0;
    double m_sal_ramas=0,mall_sal_ramas=0;
    double salariu, pret_produs;
    while (cin >> comanda >> tip_cuvant2) {
        if (comanda == "add") {
            if (tip_cuvant2 == "MiniMarket") {
                cin >> nume_magazin;
                magazin.push_back(new MiniMarket(nume_magazin));
            }
            else if (tip_cuvant2 == "Market") {
                cin >> nume_magazin;
                magazin.push_back(new Market(nume_magazin));
            }
            else if (tip_cuvant2 == "SuperMarket") {
                cin >> nume_magazin;
                magazin.push_back(new SuperMarket(nume_magazin));
            }
            else if (tip_cuvant2 == "Mall") {
                cin >> nume_magazin;
                magazin.push_back(new Mall(nume_magazin));
            }

            else if (tip_cuvant2 == "buyer") {
                cin >> nume_persoana >> nume_produs >> salariu;
                if (salariu < 500) {
                    int i = 0;
                    while (magazin[i]->getType() != "MiniMarket") i++;
                    magazin[i]->add(Person(nume_persoana, nume_produs, salariu));
                } else if (salariu >= 500 && salariu < 1000) {
                    int i = 0;

                    while (magazin[i]->getType() != "Market") i++;
                    magazin[i]->add(Person(nume_persoana, nume_produs, salariu));
                } else if (salariu >= 1000 && salariu < 2000) {

                    int i = 0;
                    while (magazin[i]->getType() != "SuperMarket") i++;
                    magazin[i]->add(Person(nume_persoana, nume_produs, salariu));
                } else if (salariu >= 2000) {

                    int i = 0;
                    while (magazin[i]->getType() != "Mall") i++;
                    magazin[i]->add(Person(nume_persoana, nume_produs, salariu));
                }
            }

            else if (tip_cuvant2 == "product") {
                cin >> nume_produs >> tip_produs >> pret_produs >> nume_magazin;
                for (int i = 0; i < magazin.size(); i++) {
                    if (nume_magazin == magazin[i]->getStoreName()) {
                        magazin[i]->addProduct(Product(nume_produs, tip_produs, pret_produs));
                    }
                }
            }
        } else if (comanda == "remove") {
            if (tip_cuvant2 == "buyer") {
                cin >> nume_persoana >> nume_magazin;

                for (int i = 0; i < magazin.size(); i++) {
                    for(int j=0;j<magazin[i]->getBuyersSize();j++)
                    {
                        if (nume_persoana == magazin[i]->getBuyers(j).mName) {

                            if(magazin[i]->getStoreName()==nume_magazin && magazin[i]->getType()=="MiniMarket") {
                                magazin[i]->remove(Person(nume_persoana, "\0", 0));
                               nr_pers_sterse_mm++;
                               break;
                            }
                            else if(magazin[i]->getStoreName()==nume_magazin && magazin[i]->getType()=="Market"){
                               nr_pers_sterse_m++;
                               m_sal_ramas=mall_sal_ramas+salariu;
                                magazin[i]->remove(Person(nume_persoana, "\0", 0));
                                break;
                            }
                            else if(magazin[i]->getStoreName()==nume_magazin && magazin[i]->getType()=="SuperMarket"){
                                nr_pers_sterse_sp++;
                                magazin[i]->remove(Person(nume_persoana, "\0", 0));
                                break;
                            }
                            else if(magazin[i]->getStoreName()==nume_magazin && magazin[i]->getType()=="Mall"){

                                nr_pers_sterse_mall++;
                                magazin[i]->remove(Person(nume_persoana, "\0", 0));
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int nr_minimarket = 0, nr_market = 0, nr_supermarket = 0, nr_mall = 0;

    int nr_total_pers_mm = 0, nr_total_pers_m = 0, nr_total_pers_sp = 0, nr_total_pers_mall = 0;
    int nr_cumparate_mm = 0, nr_cumparate_m = 0, nr_cumparate_sp = 0, nr_cumparate_mall = 0;
    for (int i = 0; i < magazin.size(); i++) {
        if (magazin[i]->getType() == "MiniMarket") {
            nr_minimarket++;
            for (int j = 0; j < magazin[i]->getBuyersSize(); j++) {
                salariu_mm += magazin[i]->getBuyers(j).mSalary;
            }
            nr_total_pers_mm += magazin[i]->getBuyersSize();
        } else if (magazin[i]->getType() == "Market") {
            nr_market++;
            for (int j = 0; j < magazin[i]->getBuyersSize(); j++) {
                salariu_m += magazin[i]->getBuyers(j).mSalary;
            }
            nr_total_pers_m += magazin[i]->getBuyersSize();
        } else if (magazin[i]->getType() == "SuperMarket") {
            nr_supermarket++;
            for (int j = 0; j < magazin[i]->getBuyersSize(); j++) {
                salariu_sp += magazin[i]->getBuyers(j).mSalary;
            }
            nr_total_pers_sp += magazin[i]->getBuyersSize();
        } else if (magazin[i]->getType() == "Mall") {
            nr_mall++;
            for (int j = 0; j < magazin[i]->getBuyersSize(); j++) {
                salariu_mall += magazin[i]->getBuyers(j).mSalary;
            }
            nr_total_pers_mall += magazin[i]->getBuyersSize();
        }
    }


    for (int i = 0; i < magazin.size(); i++) {
        if (magazin[i]->getType() == "MiniMarket") {
            for (int j = 0; j < magazin[i]->getBuyersSize(); j++) {
                if (magazin[i]->getBuyers(j).mSalary < 500) {
                    for (int k = 0; k < magazin[i]->getProductsSize(); k++) {
                        if (magazin[i]->getProducts(k).mName == magazin[i]->getBuyers(j).mProducts) {
                            nr_cumparate_mm++;
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < magazin.size(); i++) {
        if (magazin[i]->getType() == "Market") {
            for (int j = 0; j < magazin[i]->getBuyersSize(); j++) {

                if (magazin[i]->getBuyers(j).mSalary >= 500 && magazin[i]->getBuyers(j).mSalary<1000) {
                    for (int k = 0; k < magazin[i]->getProductsSize(); k++) {
                        if (magazin[i]->getProducts(k).mName == magazin[i]->getBuyers(j).mProducts &&
                                magazin[i]->getProducts(k).mPrice<= magazin[i]->getBuyers(j).mSalary) {
                            //cout<<magazin[i]->getBuyers(j).mName<<" ";
                            nr_cumparate_m++;
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < magazin.size(); i++) {
        if (magazin[i]->getType() == "SuperMarket") {
            for (int j = 0; j < magazin[i]->getBuyersSize(); j++) {
                if (magazin[i]->getBuyers(j).mSalary >= 1000 && magazin[i]->getBuyers(j).mSalary<2000) {
                    for (int k = 0; k < magazin[i]->getProductsSize(); k++) {
                        if (magazin[i]->getProducts(k).mName == magazin[i]->getBuyers(j).mProducts) {
                            nr_cumparate_sp++;
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < magazin.size(); i++) {
        if (magazin[i]->getType() == "Mall") {
            for (int j = 0; j < magazin[i]->getBuyersSize(); j++) {
                //cout<<magazin[i]->getBuyers(j).mName<<" ";
                if (magazin[i]->getBuyers(j).mSalary >= 2000) {
                    for (int k = 0; k < magazin[i]->getProductsSize(); k++) {
                        if (magazin[i]->getProducts(k).mName == magazin[i]->getBuyers(j).mProducts) {
                            nr_cumparate_mall++;
                        }
                    }
                }
            }
        }
    }

    salariu_mm = salariu_mm / nr_total_pers_mm;
    salariu_m = salariu_m / (nr_total_pers_m);
    salariu_sp = salariu_sp /(nr_total_pers_sp);
    salariu_mall = salariu_mall /(nr_total_pers_mall);

    cout << "Number of MiniMarkets: " << nr_minimarket << endl;
    cout << "Number of Markets: " << nr_market << endl;
    cout << "Number of SuperMarkets: " << nr_supermarket << endl;
    cout << "Number of Malls: " << nr_mall << endl;
    cout << "Average Salary for MiniMarkets " << salariu_mm << endl;
    cout << "Average Salary for Markets " << salariu_m << endl;
    cout << "Average Salary for SuperMarkets " << salariu_sp << endl;
    cout << "Average Salary for Malls " << salariu_mall << endl;
    cout << "Products Sale in MiniMarkets " << nr_cumparate_mm << endl;
    cout << "Products Sale in Markets " << nr_cumparate_m << endl;
    cout << "Products Sale in SuperMarkets " << nr_cumparate_sp << endl;
    cout << "Products Sale in Malls " << nr_cumparate_mall << endl;
    return 0;
}