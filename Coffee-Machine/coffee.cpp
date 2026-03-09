#include<iostream>
using namespace std;

class CoffeeMachine {

    private:
        int waterLevel;
        int coffeeBeans;
        double cashCollected;

    public:
        CoffeeMachine()
        {
            waterLevel = 1000;
            coffeeBeans = 500;
            cashCollected = 0.0;
        }

        double getCash() const
        {
            return cashCollected;
        }

        void addWater(int amount)
        {
            waterLevel = waterLevel + amount;
        }

        void addBeans(int amount)
        {
            coffeeBeans = coffeeBeans + amount;
        }

        bool dispenseEspresso(double payment)
        {
            if (payment >= 2.50)
            {
                if(coffeeBeans >= 15)
                {
                    if (waterLevel >= 30)
                    {
                        waterLevel = waterLevel - 30;
                        coffeeBeans = coffeeBeans - 15;
                        cashCollected = cashCollected + 2.50;

                        cout << "Espresso dispensed!" <<endl;
                        return true;
                    }

                    else
                    {
                        cout << "Not enough water"<<endl;
                        return false;
                    }
                    
                }

                else
                {
                     cout << "Not enough beans" <<endl;
                     return false;
                }

            }

            else
            {
                cout << "Insufficient Funds" <<endl;
                return false;
            }
        }

};

int main()
{
    CoffeeMachine c1;

    cout << "Cash in machine: " << c1.getCash() <<endl;

    double payment;

    cout << "Enter the payment: ";
    cin >> payment;

    c1.dispenseEspresso(payment);

    cout << "Cash in Machine now: " << c1.getCash() <<endl;

    return 0;

}
