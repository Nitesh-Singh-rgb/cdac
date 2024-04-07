#include <cstdio>
class Profitable
{
	public : 
	   virtual void AddInterest() = 0;

};
class Account
{
  public: 
	  virtual void Deposit(double)=0;
	  virtual void Withdraw(double)=0;
	  void Transfer(Account* other, double b)
	  {
		this->Withdraw(b);
		other->Deposit(b);
	  }

	  double GetBalance()
          {

		  return bal;
	  }

	  int GetId()
	  {
		 return id; 
	  }
  protected:
	  int id;
	  double bal;
	  static int count;
};

class SavingsAccount : public Account , public Profitable
{
  public:
	SavingsAccount()
    	{
            id = ++count;
	    bal = 5000;
	}
  
        SavingsAccount(double b)
	{	
	    id = ++count;
	    bal = 5000+ b;
	}	
       
         void Deposit(double b)
	 {
		bal = bal + b;
	 }
        
         void Withdraw(double b)
	 {	
		 if ((bal - b) < 5000)
			 throw b;
		 bal = bal - b;

	 }

         void AddInterest()
	 {
		bal = bal + 0.1 * bal;
	 }	 

};

class CurrentAccount : public Account
{
  public:
	CurrentAccount()
    	{
            id = ++count;
	    bal = 0;
	}
  
        CurrentAccount(double b)
	{	
	    id = ++count;
	    bal = b;
	}	
       
         void Deposit(double b)
	 {
		if (bal < 0)
	            bal = bal + b * 0.9;
		else
		    bal = bal + b;
	 }
        
         void Withdraw(double b)
	 {	
		 bal = bal - b;

	 }	 

};

void GiveInterest(Account* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		Profitable * p = dynamic_cast<Profitable*>(a);
		p->AddInterest();

	}	
}




int Account::count = 100;

int main()
{
	/*Account* s = new SavingsAccount(20000);
	Account* c = new CurrentAccount(10000);

	printf("Account with id:%d has bal of %lf\n", s->GetId(), s->GetBalance());
	printf("Account with id:%d has bal of %lf\n", c->GetId(), c->GetBalance());	   s->Transfer(c, 5000);

	printf("Account with id:%d has bal of %lf\n", s->GetId(), s->GetBalance());
	printf("Account with id:%d has bal of %lf\n", c->GetId(), c->GetBalance());
	 
	//s->AddInterest();
	// Wrong way as DIP is getting violated
	// SavingsAccount* p = dynamic_cast<SavingsAccount*>(s);
	//p->AddInterest();
	//
	Profitable* p = dynamic_cast<Profitable*>(s);
	if (p)
		p->AddInterest();
	printf("Account with id:%d has bal of %lf\n", s->GetId(), s->GetBalance());
        */

        // New Code Starts over here
	//
	Account* acc[5];
	acc[0] = new SavingsAccount(20000);
	acc[1] = new CurrentAccount(30000);
	acc[2] = new SavingsAccount(40000);
	acc[3] = new SavingsAccount(50000);
	acc[4] = new CurrentAccount(50000);
	for (int 
	GiveInterest(acc, 5);


}











}
