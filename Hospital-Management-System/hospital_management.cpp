#include<iostream>
using namespace std;

class Patient {
    
    protected:
        char* name;
        int patientID;
        double dailyBill;

    public:
        Patient(const char* name, int patientID, double dailyBill)
        {
            int len = 0;

            while (name[len] != '\0') 
                len++;

            this->name = new char[len+1];
            for (int i=0; i<=len; i++)
                this->name[i] = name[i];

            this->patientID = patientID;
            this->dailyBill = dailyBill;
        }

        virtual ~Patient()
        {
            cout << "Patient " << name << " discharged "<<endl;
            delete[] name;
        }

        virtual void treatmentSummary() const
        {
            cout << "Name: " << name << " | ID: " << patientID << " | Daily Bill: $" << dailyBill <<endl;
        }

        double getDailyBill() const
        {
            return dailyBill;
        }
};

class GeneralPatient : public Patient {

    private:
        char* ward;

    public:
        GeneralPatient(const char* name, int patientID, double dailyBill, const char* ward)
            : Patient(name, patientID, dailyBill)
        {
            int len = 0;
            while (ward[len] != 0)
                len++;

            this -> ward = new char[len+1];
            for (int i=0; i<=len; i++)
            {
                this -> ward[i] = ward[i];
            }
        }

        ~GeneralPatient()
        {
            cout << "[GeneralPatient] " << name << " leaving ward " << endl;
            delete[] ward;
        }

        void treatmentSummary() const
        {
            Patient::treatmentSummary();
            cout << "Ward: " << ward <<endl;
        }
};

class ICUPatient : public Patient {

    private:
        int criticalLevel;

    public:
        ICUPatient(const char* name, int patientID, double dailyBill, int criticalLevel)
            : Patient(name, patientID, dailyBill)
        {
            this -> criticalLevel = criticalLevel;
        }

        ~ICUPatient()
        {
            cout << "[ICUPatient] " << name << " leaving ICU " <<endl;
        }

        void treatmentSummary() const 
        {
            Patient::treatmentSummary();
            cout << "Critical Level: " << criticalLevel <<endl;
        }
};

void runWard(Patient** ward, int size)
{
    cout << "== Treatment Summaries ==" <<endl;

    double total = 0;
    Patient** ptr = ward;

    while (ptr != ward + size)
    {
        (*ptr) -> treatmentSummary();
        total = total + (*ptr) -> getDailyBill();
        ++ptr;
    }

    cout << "== Total Daily Biling: $" << total << " ==" <<endl;
}

int main()
{
    int choice;

    do
    {   
        cout << "\n======== Main Menu ========\n";
        cout << "1. Run Scripted Sequence\n";
        cout << "2. User Driven Menu\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice; 

        if (choice == 1)
        {
            Patient** patients = new Patient*[5];

            Patient** ptr = patients;
            *ptr = new GeneralPatient("Alice", 201, 450.00, "Cardiology");   
            ++ptr;

            *ptr = new GeneralPatient("Bob",   202, 380.00, "Orthopedics");   
            ++ptr;

            *ptr = new GeneralPatient("Carol", 203, 410.00, "Neurology");     
            ++ptr;

            *ptr = new ICUPatient("Dave", 301, 950.00,  4);                   
            ++ptr;

            *ptr = new ICUPatient("Eve",  302, 1100.00, 5);

            runWard(patients, 5);

            ptr = patients + 4;
            while (ptr >= patients)
            {
                delete *ptr;
                --ptr;
            }
            delete[] patients;
        }

        else if (choice == 2)
        {
            const int max = 50;
            Patient** patients = new Patient*[max];
            int count =0;

            Patient** ptr = patients;
            while (ptr != patients + max)
            {
                *ptr = nullptr;
                ++ptr;
            }

            int menuChoice;

            do
            {
                cout << "\n== Hospital Ward Menu ==\n";
                cout << "1. Add General Patient\n";
                cout << "2. Add ICU Patient\n";
                cout << "3. Show All Treatment Summaries\n";
                cout << "4. Show Total Billing\n";
                cout << "5. Discharge Patient\n";
                cout << "0. Back\n";

                cout << "Enter choice: ";
                cin >> menuChoice;
                
                if (menuChoice == 1)
                {
                    if (count >= max)
                    {
                        cout << "Ward is full!" <<endl;
                    }

                    else
                    {
                        char pname[256];
                        int pid;
                        double bill;
                        char wardName[256];

                        cout << "Enter name: ";
                        cin >> pname;

                        cout << "Enter ID: ";
                        cin >> pid;

                        cout << "Enter daily bill: ";
                        cin >> bill;

                        cout << "Enter ward name: ";
                        cin >> wardName;

                        *(patients + count) = new GeneralPatient(pname, pid, bill, wardName);
                        count++;
                        cout << "General patient added" <<endl;
                    }
                }

                else if (menuChoice == 2)
                {
                    if (count >= max)
                    {
                        cout << "Ward is full!" <<endl;
                    }
                    
                    else
                    {
                        char pname[256];
                        int pid;
                        double bill;
                        int level;

                        cout << "Enter name: ";
                        cin >> pname;

                        cout <<"Enter ID: ";
                        cin >> pid;

                        cout << "Enter daily bill: ";
                        cin >> bill;

                        cout << "Enter critical level (1-5): ";
                        cin >> level;

                        *(patients + count) = new ICUPatient(pname, pid, bill, level);
                        count++;
                        cout << "ICU patient added" <<endl;
                    }
                }

                else if (menuChoice == 3)
                {
                    if (count == 0)
                    {
                        cout << "No patients in ward"<<endl;
                    }

                    else
                    {
                        cout << "== Treatment Summaries ==\n";
                        Patient** p = patients;
                        while (p != patients + count)
                        {
                            (*p) -> treatmentSummary();
                            ++p;
                        }
                    }
                }

                else if (menuChoice == 4)
                {
                    if (count == 0)
                    {
                        cout << "No patients in ward"<<endl;
                    }
                    
                    else
                    {
                        double total = 0;
                        Patient**p = patients;
                        while (p != patients + count)
                        {
                            total = total + (*p) -> getDailyBill();
                            ++p;
                        }

                        cout << "Total daily billing: $" << total <<endl;
                    }
                }

                else if (menuChoice == 5)
                {
                    if (count == 0)
                    {
                        cout << "No patients to discharge" <<endl;
                    }

                    else
                    {
                        cout << "Select patient to discharge: " <<endl;
                        Patient** p = patients;

                        int idx = 0;
                        while (p != patients + count)
                        {
                            cout << "[" << idx << "]";
                            (*p) -> treatmentSummary();
                            ++p;
                            ++idx;
                        }

                        int sel;
                        cout << "Enter index: ";
                        cin >> sel;

                        if (sel<0 || sel >= count)
                        {
                            cout << "Invalid index!" <<endl;
                        }

                        else
                        {
                            delete *(patients + sel);

                            //left shifting by pointer arthimatic
                            Patient** shift = patients + sel;
                            while (shift != patients + count - 1)
                            {
                                *shift = *(shift + 1);
                                ++shift;
                            }
                            count--;
                            *(patients + count) = nullptr;
                            cout << "Patient discharged" <<endl;
                        }
                    }
                }

                else if (menuChoice == 0)
                {
                    Patient** p = patients;
                    while (p != patients + count)
                    {
                        delete *p;
                        ++p;
                    }
                    delete[] patients;
                    count = 0;
                    cout << "Returning to main menu" <<endl;
                }

                else
                {
                    cout << "Invalid choice! Try Again" <<endl;
                }
                
            }   while (menuChoice != 0);
            
        }

        else if (choice == 0)
        {
            cout << "Exiting..." <<endl;
        }

        else
        {
            cout << "Invalid choice" <<endl;
        }
    
    }   while (choice != 0);
    
    return 0;
}
