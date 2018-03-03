#include<iostream>
using namespace std;


//Programmer: Dongxu Li
//Date: Sep18, 2017
//Purpose: The Purpose of the program is to  implement functionality to
//accrue interest for an investment account.

//Function prototype
/*
This function accrues interest, as per the way our "bank" allows, over the
specified number of months.The parameter balanceAmt is used as both input
(the initial balance of the account prior to interest accrual) and output
(the final balance after the specified number of months' worth of interest
have beenaccrued.
*/
bool accrueInterest
(
   double &balanceAmt,
   const int numMonths,
   const bool doPrintEachMonth
);

/*
This function accrues interest, as per the way our "bank" allows, for a single
month (the period in which our "bank" accrues interest). The parameter
balanceAmt is used as both input (the initial balance of the account prior to
interest accrual) and output (the final balance after the months' worth of
interest has been accrued.
*/
bool accrueOneMonthsInterest
(
   double &balanceAmt,
   const bool doPrintInfo
);



int main()
{
   double balanceAmt;
   int numMonths;
   bool doPrintEachMonth;
   char yesOrNo;
   bool success;

   cout << "Enter the initial balance of the account: ";
   cin >> balanceAmt;
   cout << "Enter the number of months to accrue interest: ";
   cin >> numMonths;
   cout << "Show month-by-month results - 'y' for yes, any other for no: ";
   cin >> yesOrNo;
   //keep a record of initial balance
   double initialBalance = balanceAmt;
   //If doPrintEachMonth is false, the function performs silently, but if true,
   //the amount of interest added each month, along with the balance after that
   //month, will be printed.
   if(yesOrNo == 'y')
   {
      doPrintEachMonth = true;
   }
   else
   {
      doPrintEachMonth = false;
   }
   success = accrueInterest(balanceAmt, numMonths, doPrintEachMonth);
   if(success)
   {
      cout << "Interest accrued for " << numMonths << " months!" << endl << endl;
      cout << "Initial balance: " << initialBalance << endl;
      cout << "Total interest accrued: " << balanceAmt - initialBalance << endl;
      cout << "Final balance: " << balanceAmt << endl;
   }
};


bool accrueInterest
(
   double &balanceAmt,
   const int numMonths,
   const bool doPrintEachMonth
)
{
   //Test the if the input is legal
   if(balanceAmt < 0)
   {
      accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
      return false;
   }
   if(numMonths <  0)
   {
      cout << "ERROR in accrueInterest: numMonths must be > 0, ";
      cout << "but the value " << numMonths << " was provided!" << endl;
      cout << "Sorry, an error was detected.  Unable to provide results!" << endl;
      return false;
   }
   // Call accrueOneMonthsInterest function in the loop
   // for calculating the accumulated interest.
   for(int i = 0; i < numMonths; i++)
   {
      accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
   }
   return true;
}


bool accrueOneMonthsInterest
(
   double &balanceAmt,
   const bool doPrintInfo
)
{
   double interestAmt;
   double interestRate;
   double initialBalance = balanceAmt;
   //Test the if the input is legal
   if(balanceAmt < 0)
   {
      cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0, ";
      cout << "but the value " << balanceAmt << " was provided!"<< endl;
      cout << "Sorry, an error was detected.  Unable to provide results!" << endl;
      return false;
   }
   //Customer balances under $1000.00 (exclusive) will be given a monthly
   //interest rate of 0.15%. Customer balances over $15000.00 (inclusive) will
   //be given a monthly interest rate of 0.4%, Other balances (i.e. between
   //$1000.00 (inclusive) and $15000.00 (exclusive)) will be given a monthly
   //interest rate of 0.225%.
   float lowAmount = 1000.00;
   float highAmout = 15000.00;
   if(balanceAmt < lowAmount)
   {
      interestRate = 0.0015;
   }
   else if(balanceAmt >= highAmout)
   {
      interestRate = 0.004;
   }
   else
   {
      interestRate = 0.00225;
   }

   interestAmt = balanceAmt * interestRate;
   balanceAmt = balanceAmt + interestAmt;
   // Specify the optional print out
   if(doPrintInfo)
   {
      cout << "Accruing interest for 1 month:" << endl;
      cout << "  Initial balance: " << initialBalance << endl;
      cout << "  Initial rate: " << interestRate << endl;
      cout << "  Interest accrued: " << interestAmt << endl;
      cout << "  New balance: " << balanceAmt << endl;
   }
   return true;
}
