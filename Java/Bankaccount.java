class Bank
{
  String name;
  long account_no;
  String type;
  long balance;
  void details(String name ,long account_no, String type,long balance)
{
   this.name=name;
   this.account_no=account_no;
   this.type =type;
   this.balance=balance;
}
 void deposit(int deposited_amount)
{
  balance=balance+deposited_amount;
}
 void withdraw(int withdraw_amount)
{
 if(balance>withdraw_amount)
    balance=balance-withdraw_amount;
 else
    System.out.println("Insufficient balance!");
}
 void display()
{
  System.out.println("Name: "+ name);
  System.out.println("Type of account: "+ type); 
  System.out.println("Balance: Rs." + balance);
}
}
class Bankaccount 
{
 public static void main(String args[]) 
{
 Bank obj= new Bank();
 obj.details("Borat",10101, "Savings",75000);
 obj.withdraw(5000);
 obj.display();
}
}
