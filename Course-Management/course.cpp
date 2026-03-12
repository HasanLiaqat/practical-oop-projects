#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Course {

    private:
        string courseCode;
        string courseName;
        int creditHours;
        float feePerCredit;
        bool isLab;

    public:
        Course()        //default
        {
            courseCode = "N/A";
            courseName = "Unassigned";
            creditHours = 0;
            feePerCredit = 0.0;
            isLab = false;
        }

        Course(string cc, string cn, int ch, float fpc, bool il)    //parameterized
        {
            courseCode = cc;
            courseName = cn;
            creditHours = ch;
            feePerCredit = fpc;
            isLab = il;
        }

        Course(const Course &other)     //copy constructor
        {
            courseCode = other.courseCode;
            courseName = other.courseName;
            creditHours = other.creditHours;
            feePerCredit = other.feePerCredit;
            isLab = other.isLab;    
        }

        
        void setCourseCode(string code)
        { 
            courseCode = code; 
        }

        void setCreditHours(int ch) 
        { 
            creditHours = ch; 
        }

        void setIsLab(bool lab)
        {
             isLab = lab; 
        }

        float calculateFee();
        void display();
        bool isSameAs(const Course &other);

};

float Course :: calculateFee()
{
    float a = creditHours * feePerCredit;

    if (isLab == true)
    {
        a = 500 +a;
    }

    return a;
}

void Course :: display()
{
    cout << "Code: " << courseCode
         << " | Name: " << courseName
         << " | Credits: " << creditHours
         << " | Fee/Credit: " << feePerCredit
         << " | Lab: " << (isLab ? "Yes" : "No") << endl;   
}

bool Course :: isSameAs(const Course &other)
{
    if (courseCode.length() != other.courseCode.length())
    {
        return false;
    }

    for (int i=0; i<courseCode.length(); i++)
    {
        char c1 = courseCode[i];
        char c2 = other.courseCode[i];

        if (c1>='A' && c1<='Z')
        {
            c1 = c1 + 32;
        }

        if (c2>='A' && c2<='Z')
        {
            c2 = c2 + 32;
        }

        if (c1 != c2)
        {
            return false;
        }
    }

    return true;
}

int main()
{
     cout << fixed << setprecision(2); //to print decimal

    Course c1;
    cout << "\n=== Default Course ==="<<endl;

    c1.display();
    cout << "Total Fee: Rs. " << c1.calculateFee() <<endl;


    Course c2("CS301", "Data Structures", 3, 1500, false);
    cout << "\n=== Data Structures ==="<<endl;

    c2.display();
    cout << "Total Fee: Rs. " << c2.calculateFee() <<endl;

    Course c3 = c2;
    cout << "\n=== Lab copy ==="<<endl;

    c3.setCourseCode("CS301L");
    c3.setIsLab(true);
    c3.setCreditHours(1);

    c3.display();
    cout << "Total Fee: Rs. " << c3.calculateFee() << " (includes Rs.500 lab surcharge)" <<endl;

    cout << "\nCS301 vs CS301L" <<endl;

    if (c2.isSameAs(c3))
        cout << "Codes match." <<endl;
    else
        cout << "Codes do not match." <<endl;

    cout << "\nFee for CS301: Rs. " << c2.calculateFee() <<endl;
    cout << "Fee for CS301L: Rs. " << c3.calculateFee() <<endl;

    return 0;
}
