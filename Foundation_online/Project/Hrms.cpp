#include <cstdio>

class Employee
{	
	public:
	   Employee()
	   {
		   id = ++count;
		   hours = 180;
		   rate = 100;
		   puts("Employee instance created");
	   }

	   Employee(double hh, double rr)
	   {
		id = ++count;
		hours = hh;
		rate = rr;
	   }

	   static int EmployeeCount()
	   {
		return count;
	   }
	   
	   virtual double Income()
	   {
		return rate * hours;
	   }
	protected:
	 
	   int id;
	   double hours;
	   double rate;
	   static int count;


};

class SalesPerson : public Employee
{
    	public: 
           SalesPerson() : Employee()
	   {
		comm = 25000;
		puts("Salesperson Activated");
	   }

           SalesPerson(double hh, double rr, double cc) : Employee(hh, rr)
	   {
		comm = cc;
		puts("SalesPerson Activated");
           }
     		   
	   double Income()
	   {
		double i = 0;
		
		i = Employee::Income() + 0.25 * comm;

                return i;

	   }
	private:
	   double comm;

};

int Employee:: count = 100;

double Tax(Employee& emp)
{
	double income = emp.Income();  //Employee::Income(&emp)
	if (income < 10000)
		return 0;
	return (income - 10000) * .10;
}

int main()
{
   Employee e(100, 100);
   SalesPerson s(100, 100, 50000);

   printf("Sal of Employee is %lf and Tax is %lf\n", e.Income(), Tax(e));
   printf("Sal of SalesPerson is %lf and Tax is %lf\n", s.Income(), Tax(s));

   return 0;

}
