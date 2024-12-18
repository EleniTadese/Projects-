#include<iostream>
#include<iomanip>
#include<sstream>
using namespace std;
void welcome();//Declaration Of Welcome Function
void reciept(int bill,int j);//Declaration Of Cash And Receipt Function
void check(string food_number);
void order_food();//Declaration Of A Function To Order Foods
void order_drink();//Declaration Of A Function To Order Drinks
void order();//Declaration Of A Function To Ask A Customer What To Order Food/Drink
string vv[10]={"0","1","2","3","4","5","6","7","8","9"};
string Name,food_number,drink_number,order_again;
string gap="*****************************";
string line=".............................";
float cash,totalbill,bill=0;
int j=0,z=11;
//Using A Structure For Menu To Hold Foods And Drinks With Their Price
struct menu{
	string food_name;
	float price;
}bil[12]={},food[10]={{" 0. Tibs    ",250.0},{" 1. Kikil   ",200.0},{" 2. Kitfo   ",150.0},
			{" 3. Chicken ",100.0},{" 4. Pizza   ",80.0},{" 5. Burger  ",60.0},{" 6. Beyaynet",50.0},
			{" 7. shiro   ",40.0},{" 8. Firfir  ",40.0},{" 9. Firfir  ",40.0}},
			drink[8]={{" 0. Pepsi   ",110},{" 1. CocaCola",100},{" 2. Mirinda ",90},{" 3. Sprite  ",80},
			{" 4. Wine    ",70},{" 5. Dashen  ",70},{" 6. Water   ",60},{" 7. Ambo    ",50}};	
int main(){
string main_menu;	
main_menu:
welcome();//Calling Welcome Function
cout<<"What You Would Like To Order First Food/Drink ?\n";
order();
cout<<"Do You Want To Order Another Food/Drink ? If You Want\n";
order();
reciept(bill,j);//Calling A Function For Cash And Receipt
	cash=0;
	totalbill=0;
	bill=0;
cout<<"Press Any Key For Main Menu : ";
cin>>main_menu;
goto main_menu;
return 0;}
//Definition Of A Function To Accept Cash And Calculate The Receipt
void reciept(int bill,int j){
string main_menu;
if(bill>0){
string pay;
totalbill=(bill*20/100)+bill-(bill*10/100);
pay:	
cout<<"Please Pay Here  Your Total Bill Is : "<<totalbill<<"  Birr\n";
cout<<"Cash : ";
stringstream convert;
cin>>pay;
convert<<pay;
int check;
convert>>check;
if(check>0&&check>=bill){
cash=check;
cout<<"\nYour Change Is  : "<<cash-totalbill<<"  Birr\n";
cout<<"\nPlease Take Your Receipt\n\nYour Order Will Be Delivered To You In 10 Minute\n"<<endl;
cout<<gap<<endl;
cout<<"\tRECEIPT"<<endl;
cout<<line<<endl;
float Tax,Subtotal,Discount,Total;
Tax=(bill*20/100);
Subtotal=bill+Tax;
Discount=bill*10/100;
Total=Subtotal-Discount;
cout<<" Customer Name : "<<Name<<endl<<line<<endl<<
      " Food/Drink \t"<<setw(5)<<"Price\n"<<line<<endl;
for(int i=0;i<j;i++)
cout<<bil[i].food_name<<setw(5)<<":"<<setw(5)<<bil[i].price<<"  Birr\n";
cout<<" Bill  \t\t:"<<setw(5)<<bill<<"  Birr\n"<<
" Tax   \t\t:"<<setw(5)<<Tax<<"  Birr\n"<<
" Sub Total \t:"<<setw(5)<<Subtotal<<"  Birr\n"<<
" Discount  \t:"<<setw(5)<<Discount<<"  Birr\n"<<
	  " Total \t\t:"<<setw(5)<<Total<<"  Birr\n"<<
"\t....................\n"<<
"\tNovember 15/2023 G.C"<<endl;
cout<<gap<<endl;
cout<<"   ENJOY YOUR MEAL !!!\n";
cout<<line<<endl<<endl;
}
else{	
	cout<<"Your Cash Is Incorrect Please Pay The Riht Amount\n";
	goto pay;}
	}
	else{
	cout<<"\nyou Didnt Order Anything !!!!\n\n";
	}
  }
//Definition Of A Function To Welcome The Customer
void welcome(){
string menu;
cout<<"\n  Dear Customer Welcome To\n\n "<<gap<<endl<<" *"<<
 "   \tASTU RESTAURANT\t     *\n "<<gap<<
 "\nPress Any Key For Menu : ";
cin>>menu;
cout<<"\n......Here Is Our Menu......\n\n";
cout<<gap<<endl;
cout<<"\tFOOD MENU"<<endl;
cout<<line<<endl;
cout<<"    Food"<<setw(20)<<"Price\n";
cout<<line<<endl;
for(int i=0;i<10;i++){
cout<<food[i].food_name<<setw(15)<<food[i].price<<endl;}
cout<<gap<<endl;
cout<<"\tDRINK MENU\n";
cout<<line<<endl;
cout<<"   Drink"<<setw(20)<<"Price\n";
cout<<line<<endl;
for(int i=0;i<8;i++){
cout<<drink[i].food_name<<setw(15)<<drink[i].price<<endl;}
cout<<gap<<"\nPlease Enter Your Name To Order\n Name : ";
cin>>Name;	
  }
void check(string food_number){
	for(int i=0;i<10;i++){
if(vv[i]==food_number)
z=i;	
}
}
//Definition Of A Function To Ask What To Order Order Food/Drink
void order(){
cout<<"Please Sir Press What You Would Like To Order\n"<<
" Press  1\t\tFor\t\tFood\n press  2\t\tFor\t\tDrink\n Press  ANY Other KEY   To\t\tContinue\n I Prefer : ";
cin>>order_again;	
check(order_again);//
switch(z){
case 1:
order_food();
break;
case 2:
order_drink();
break;
}	
}
//Definition Of A Function To Order Food
void order_food(){
int quant;
cout<<"Dear Customer You Can Order Your Food Here:"<<endl;
food_order:
cout<<" Food Number : ";
cin>>food_number;
z=11;
check(food_number);
switch(z){
case 11:
cout<<"This Order Is Not Appear Try Again\n";
goto food_order;
break;	
default:
cout<<" Food : "<<food[z].food_name<<endl;
enter_food_quantity:
cout<<"Please Enter The Quantity  : ";
string quantity;
stringstream convert;
cin>>quantity;
convert<<quantity;
int check;
convert>>check;
if(check>0){
quant=check;
}
else{	
	cout<<"Please Enter The Right Quantity\n";
	goto enter_food_quantity;}
}
bil[j].food_name=food[z].food_name;
bil[j].price=food[z].price*quant;
j++;
bill=bill+food[z].price*quant;
cout<<"Do You Want To Order Another Food ? \n"<<
" press  1\t\tFor\t\tYes\n Press  ANY Other KEY   To\t\tContinue\n I Prefer : ";
cin>>order_again;	
check(order_again);//
switch(z){
case 1:
order_food();
}
}
//Definition Of A Function To Order Drink
void order_drink(){
int quant;
cout<<"Dear Customer You Can Order Your Drink Here:"<<endl;
drink_order:
cout<<" Drink Number : ";
cin>>drink_number;
z=11;
check(drink_number);
switch(z){
case 11:
cout<<"This Order Is Not Appear Try Again\n";
goto drink_order;
break;	
default:
cout<<"Food : "<<drink[z].food_name<<endl;
enter_drink_quantity:
cout<<"Please Enter The Quantity  : ";
string quantity;
stringstream convert;
cin>>quantity;
convert<<quantity;
int check;
convert>>check;
if(check>0){
quant=check;
}
else{	
	cout<<"Please Enter The Right Quantity\n";
	goto enter_drink_quantity;}
}
bil[j].food_name=drink[z].food_name;
bil[j].price=drink[z].price*quant;
j++;
bill=bill+drink[z].price*quant;
cout<<"Do You Want To Order Another Drink ? \n"<<
" press  1\t\tFor\t\tYes\n Press  ANY Other KEY   To\t\tContinue\n I Prefer : ";
cin>>order_again;
check(order_again);//
switch(z){
case 1:
order_drink();
}
}
 /*    C++ course project guideline
 
1.	Project Selection: Choose a project title and specifying its functionality.
	# Restaurant ordering system.
2.	Problem-solving life cycles: you have to follow software development procedures.
Phase 1: Development
 Step 1: Analyze the Problem
	# Identifying the problem that we are going to solve.
		* Restaurant Ordering System.
 Step 2: Develop a Solution
    # Write an algorithm to solve the problem.
	* A program  that welcomes the customer and diplay the order menu and asks wether he/she wants to order food or drink
	* If the customer wants to order food it asks to enter the food he/she wants from the menu. 
      if he/she enters the correct option it asks the quantity he/she wants.if he/she enters 
	  options which does not appaer on the menu it displays error message and gives another chance until the correct option is entered.
	  after he/she entered the correct food option and quantity
	  it asks if he/she wants to order another food .if he/she wants it provides .if he/she dont wants to order again it provides the next service.
	* If the customer wants to order drink it asks to enter the drink he/she wants from the menu. 
	  if he/she enters the correct option it asks the quantity he/she wants.if he/she enters 
	  options which does not appaer on the menu it displays error message and gives another chance until the correct option is entered.
	  after he/she entered the correct drink option and quantity
	  it asks if he/she wants to order another drink .if he/she wants it provides .if he/she dont wants to order again it provides the next service.
	* after he/she ordered what they want it asks for the last time if they want to order anything else 
	* after ordering is finished the program calculates the bill and asks the customer for payment.
	  if the customer enters wrong character or less amount than the bill, it displays error message and
	  gives another channce to pay until the customer enters greater or equal amount.if the customer enters greater amount it gives a change. And finally it give a
	  receipt card for the customer.
	* And after all the program is ready for another customer.
 Step 3: Code the Solution
	# changing written algorithms byusing techniques like :
		* Sequence
		* Selection
		* Iteration
		* Invocation
Step 4: Test and Correct the Program
	# testing the program coded and make corrections if it have an error.
		* Testing
		* Debugging
Phase 2: Documentation
	# documenting the corrected and error-free code.
		* Program description
		* Algorithm development and changes
		* Well-commented program listing
		* Sample test runs
		* Users' manual
Phase 3: Maintenance
		* well corrected and error-free code
3.	User Input: The project should handle user input effectively.
	# All the orders are performed by inputs from the user.
            * choose food
            * choose drink
            * choose food/drink quantity
            * payment
4.	Program Structure: Your have to write a well-structured program.
	# A well structured program by handling multiple tasks with different functions.
			* A function to welcome the customer.
 			* A function to ask What To Order food/drink.
			* A function to order food.
			* A function to order drink.
			* A function to accept cash and calculate the receipt.
5.	Output Formatting: format the program's output effectively.
	# A program that have good format for user interaction.
6.	Code Re-usability: You have to write reusable code by creating functions and modules that can be used in multiple parts of the program.
	# Re-using of function codes multiple times.
7.	Error Handling: The project should handle errors and exceptions within their program.
	# error-free program that have been checked multiple times
8.	File Handling: If applicable to the project, Your have to use files.
9.	Documentation: You have to prepare documentation (Program description,Algorithm development and changes,….) their code.
Project rule
1. One group can have only 4 members
2. Each members of the project should participate actively 
3. You have to submit your project title and group members name before November 7 

 */
 
