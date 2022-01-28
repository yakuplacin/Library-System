	#include <stdio.h>
	#include <conio.h>
	#include <time.h>


	struct Book{  //this is for book struct
		char BookName[50];
		char Author[50];
		int B_ID;
		int ageLimit;
		int pricePerWeek;
		int Rented;	
	};
	
	struct Customer{ // same with book
		char CustomerName[50];
		char CustomerSurname[50];
		int C_ID;
		int age;
		int wallet;
	};
	
	struct Rented{  //same with book
		int R_ID;
		int C_ID;
		int B_ID;
		struct tm Rented_Date; //this one for time
		int RentedWeek;
		
	};
	
	void menu_bas(); //this function will print the choises
	void add_book(struct Book *); // it is for adding book
	void list_books(struct Book *); //it is for looking books
	void add_file(struct Book *); // this one add books to books file
	void read_books(struct Book *); // this one looks the previous books that helps the next ones
	void add_customer(struct Customer *); //adding customer
	void list_customers(struct Customer *); //lists customers
	void read_customers(struct Customer *); //looks for the previous customers that helps the next ones
	void add_filetwo(struct Customer *); // adds customers to the customer file
	void rent_book(struct Rented *); //renting book
	void list_rented(struct Rented *); //lists book
	void read_renteds(struct Rented *);//looks for the previous renteds books that helps the next ones
	void add_filethree(struct Rented *); // adds rented books to renteds file
	void add_money(struct Customer *);//adding money to customer wallet
	void update_customer(struct Customer *);//updating customer information
	void update_book(struct Book *);//updating book information
		
	struct Book books[999]; //keeping books array
	struct Customer customers[999]; //keeping customers array
	struct Rented renteds[999]; //keeping renteds array
	
	
	void add_book(struct Book *books){ //for getting books information and add that books.
	
		int s; 
		for(s = 0; s<999 ; s++){  //this is for the finding next book ID. it stops when ID=1 Because I set new B_ID = -1 in the next codes 
			if(books[s].B_ID == -1){
				break;
			}	
		}
		books[s].B_ID=s;
		printf("Books ID: %d ",books[s].B_ID);
		
		printf("Books Name: ");
		scanf("%s",books[s].BookName);
		printf("Author Name: ");
		scanf("%s",books[s].Author);
		printf("Age Limit: ");
		scanf("%d",&books[s].ageLimit);
		printf("Price Per Week: ");
		scanf("%d",&books[s].pricePerWeek);
		books[s].Rented = 0; //the new book is not rented so it seem 0
		books[s+1].B_ID=-1; // this one is the next books ID is -1 that can help the for other books. I explained above
	
	
		printf("The book has been added");
	}
	
	void list_books(struct Book *books){ //getting the list of books
		int s;
		for(s = 0; s<999; s++){ // again this one for the finding the last ID
			if(books[s].B_ID==-1)
				break;
		
		if(books[s].Rented==2){ //if it seems 2 that means the book is deleted. Because we have burn book part. this comes from there
			printf("%d - %s %s %d %d %d",books[s].B_ID,books[s].BookName,books[s].Author,books[s].ageLimit,books[s].pricePerWeek,books[s].Rented);		
			printf("\tThis book was deleted\n");
		}
		else
			printf("%d - %s %s %d %d %d\n",books[s].B_ID,books[s].BookName,books[s].Author,books[s].ageLimit,books[s].pricePerWeek,books[s].Rented);
			
		}
		
	}
	
	void add_file(struct Book *books){//adding books to books file
		
		FILE *fp = fopen("books.txt","w+"); //opens books file and writes
		
		int s;
		for(s=0 ; s<999; s++){ //again, for looking the latest ID while printing informations but this time it continue untill ID = -1 
			if(books[s].B_ID==-1)
				break;
			
			fprintf(fp,"%d %s %s %d %d %d\n",books[s].B_ID,books[s].BookName,books[s].Author,books[s].ageLimit,books[s].pricePerWeek,books[s].Rented);	
		}
		fclose(fp);
		
	}
	
	void read_books(struct Book *books){
		
		FILE *fp = fopen("books.txt","r+");//opening and reading the books file for getting information
			
			
				
		int s;
		for(s= 0; s<999; s++){
			fscanf(fp,"%d %s %s %d %d %d\n",&(books[s].B_ID),books[s].BookName,books[s].Author,&(books[s].ageLimit),&(books[s].pricePerWeek),&(books[s].Rented));
			if(feof(fp)) //when we are in the last part of file, it breaks
				break;	
		}
		fclose(fp);
		books[s+1].B_ID = -1;
	}
	
	void add_customer(struct Customer *customers){//adding customers
		
		int s; 
		for(s = 0; s<999 ; s++){ //like book parts, itfinds out the last ID than set s to this ID for putting information
			if(customers[s].C_ID == -1){
				break;
			}	
		}
		customers[s].C_ID=s;
		printf("Customer ID: %d ",customers[s].C_ID);
		
		printf("Customer Name: ");
		scanf("%s",customers[s].CustomerName);
		printf("Surname: ");
		scanf("%s",customers[s].CustomerSurname);
		printf("Age: ");
		scanf("%d",&customers[s].age);
		printf("Wallet: ");
		scanf("%d",&customers[s].wallet);
	
		customers[s+1].C_ID=-1;  //like books, putting the next ones ID to -1, it helps us to find the next ID
		
		printf("\n\tCustomer has been added");
	}
	void list_customers(struct Customer *customers){//lists customers
		
		int s;
		for(s = 0; s<999; s++){//until ID = -1, that means until last customers, it prints out the information of customers
			if(customers[s].C_ID==-1)
				break;
				
			printf("%d - %s %s %d %d\n",customers[s].C_ID,customers[s].CustomerName,customers[s].CustomerSurname,customers[s].age,customers[s].wallet);
		}
		
	}
	void add_filetwo(struct Customer *customers){//adding customers to customers file
		
		FILE *fp = fopen("customers.txt","w+");//opening and writing to files
		
		int s;
		for(s=0 ; s<999; s++){//like previous ones, the same idea
			if(customers[s].C_ID==-1)
				break;
			
			fprintf(fp,"%d %s %s %d %d\n",customers[s].C_ID,customers[s].CustomerName,customers[s].CustomerSurname,customers[s].age,customers[s].wallet);	
		}
		fclose(fp);
		
	}
	void read_customers(struct Customer *customers){//reading customers that brings from files to the compiler that helps the find information
		
		FILE *fp = fopen("customers.txt","r+");//reading information from customers
		
		int s;
		for(s=0 ; s<999; s++){ //the same idea with previous ones
			fscanf(fp,"%d %s %s %d %d\n",&(customers[s].C_ID),customers[s].CustomerName,customers[s].CustomerSurname,&(customers[s].age),&(customers[s].wallet));	
			if(feof(fp))
				break;		
		}
		fclose(fp);
		customers[s+1].C_ID = -1; // the same idea with previous ones
		
	}
	
	void add_money(struct Customer *customers){ //adding money to the customers' wallet
		int s, extra;
		printf("ENTER ID: ");
		scanf("%d",&s);
		printf("ENTER DEPOSIT MONEY: ");
		scanf("%d",&extra);
		customers[s].wallet = customers[s].wallet + extra; //we add money in this function
	}
	
	void update_customer(struct Customer *customers){//updating customer information
		int s;
		
		printf("ENTER ID TO UPDATE: ");
		scanf("%d",&s);
		printf("Enter new Name: ");
		scanf("%s",customers[s].CustomerName);
		printf("new Surname: ");
		scanf("%s",customers[s].CustomerSurname);
		printf("Age: ");
		scanf("%d",&customers[s].age);
				
	}
	
	void update_book(struct Book *books){//like customers, this is for updating book information
		
		int s;
		
		printf("ENTER BOOK ID TO UPDATE: ");
		scanf("%d",&s);
		printf("Enter new Book Name: ");
		scanf("%s",books[s].BookName);
		printf("Author: ");
		scanf("%s",books[s].Author);
		printf("Age limit: ");
		scanf("%d",&books[s].ageLimit);
		printf("Price Per Week: ");
		scanf("%d",&books[s].pricePerWeek);
		
	}
	
	void burn_book(struct Book *books){ //deleting book
		
		int s;
		printf("Enter Book ID to delete.");
		scanf("%d",&s);
		
		if(books[s].Rented == 0){ // we get book id and check if it is already rented or not. if it is not, program puts rented = 2. this means book will be deleted
		books[s].Rented = 2;
		printf("The book is deleted");
		}
		
		else if(books[s].Rented==1){ // we check rented or not here
		printf("The Book is rented. You cannot burn this book");
		}
		
		else if(books[s].Rented == -1){
		printf("The book does not exist.");
		}
		
	}
	
	void rent_book(struct Rented *renteds){
		
	
		int s,d,w;
		
		printf("Enter Book ID which you want to rent: ");
		scanf("%d",&s);
		if(books[s].Rented==1){//we check if it is rented or not. if it is rented, customer cannot take the book
			printf("This book already rented.");
			return;
		}
		if(books[s].Rented == 2){//and also for deleted one, if it is deleted, customer cannot take the book
			printf("This book was deleted");
			return;
		}
		if(books[s].B_ID < 0){//this means actually if BookID = -1, that means there is no such a book. I put B_ID= -1 for where there is no books like that
			printf("That Books' ID does not exist.");
			return;
		}
		printf("Enter Customer ID to pay: ");
		scanf("%d",&d);
		if(customers[d].age <= books[s].ageLimit){
			printf("Your age is not enough to rent this book.");
			return;
		}
		printf("How many week you want to rent:");
		scanf("%d",&w);
		if(customers[d].wallet<((books[s].pricePerWeek)*w)){
			printf("Your wallet is not enough to rent this book.");
			return;
		}
		
		int y; 
		for(y = 0; y<999 ; y++){//this is like the finding customers' and books' ID. It checks until R_ID = -1 because in the main I put R_ID = -1 like others; 
			if(renteds[y].R_ID == -1){
				break;
			}	
		}
		
		time_t currentTime; //this is for the special function that gives the time
		time(&currentTime);
		struct tm *chtime = localtime(&currentTime); //we put that address with struct
		
		chtime->tm_year-1900; 
		chtime->tm_mon-1;
		chtime->tm_mday;
		
		renteds[y].Rented_Date = *chtime;
		customers[d].wallet = customers[d].wallet - ((books[s].pricePerWeek)*w);
		books[s].Rented = 1;
		renteds[y].R_ID = y;
		renteds[y].B_ID = s;
		renteds[y].C_ID = d;
		renteds[y].RentedWeek = w; 
		
		printf("You rented the book.");
		
		renteds[y+1].R_ID = -1; // I mention already, for finding next ID
		
	}
	void list_rented(struct Rented *renteds){//listing renteds. idea is the same with books and customers
		
		int s;
		for(s = 0; s<999; s++){
			if(renteds[s].R_ID==-1)
				break;
					if(renteds[s].Rented_Date.tm_year < 1900){//I thought and found new idea. I check if year is under 1900, program adds +1900.
					//but it adds 1900 everytime so I put if else condition to check if it is bigger or under 1900. We can also put other years it doesn't matter I guess.
					//I did it because as I understand, pc start with not that year. I dealt with much and I found my approaches. I did it like that because we are in the 2021 year.
			renteds[s].Rented_Date.tm_year = renteds[s].Rented_Date.tm_year + 1900;				
			}
			
			printf("%d - %d %d %d.%d.%d %d\n",renteds[s].R_ID, renteds[s].C_ID,renteds[s].B_ID,renteds[s].Rented_Date.tm_mday,renteds[s].Rented_Date.tm_mon,renteds[s].Rented_Date.tm_year,renteds[s].RentedWeek);
		}
		
		
	}
	
	void read_renteds(struct Rented *renteds){//like others, reads and brings compiler
		
		FILE *fp = fopen("renteds.txt","r+");
		
		int s;
		for(s=0 ; s<999; s++){
			fscanf(fp,"%d %d %d %d.%d.%d %d\n",&(renteds[s].R_ID),&(renteds[s].C_ID),&(renteds[s].B_ID),&renteds[s].Rented_Date.tm_mday,&renteds[s].Rented_Date.tm_mon,&(renteds[s].Rented_Date.tm_year),&(renteds[s].RentedWeek));	
			if(feof(fp))
				break;		
		}
		fclose(fp);
		renteds[s+1].R_ID = -1;
		
	}
	
	void add_filethree(struct Rented *renteds){//adding renteds to renteds file like others
	
		FILE *fp = fopen("renteds.txt","w+");
		
		int s;
		for(s=0 ; s<999; s++){
			if(renteds[s].R_ID==-1)
				break;
			if(renteds[s].Rented_Date.tm_year < 1900){//again the same idea with previous one. I explained before
			renteds[s].Rented_Date.tm_year = renteds[s].Rented_Date.tm_year + 1900;				
			}
			fprintf(fp,"%d %d %d %d.%d.%d %d\n",renteds[s].R_ID, renteds[s].C_ID,renteds[s].B_ID,renteds[s].Rented_Date.tm_mday,renteds[s].Rented_Date.tm_mon,renteds[s].Rented_Date.tm_year,renteds[s].RentedWeek);	
		}
		fclose(fp);
		
	}
	
	void delivery_book(struct Rented *renteds){//delivery book
		int s,d,ew;
		
		printf("ENTER ID: ");
		scanf("%d",&s);
		printf("ENTER BOOK ID");
		scanf("%d",&d);
		if(books[d].Rented==0){//checks if customer have or not
			printf("It seems you do not have this book");
			return;
		}
		if(books[d].Rented==2){//checks if book is deleted or not
			printf("This book was deleted. You do not have the book.");
			return;
		}
		printf("How many weeks early do you give the book?");
		scanf("%d",&ew);
		books[d].Rented = 0; //renteds = 0 because 0 means not rented in this project
		customers[s].wallet = customers[s].wallet + (books[d].pricePerWeek*ew); //adding that extra money like how many weeks early customer puts the books
		
		
		printf("You gave the book");
	}
	
	void menu_bas(){ // for menu
		system("cls"); //I found this method to clear the main page
		printf("1. Create New Customer\n");
		printf("2. Deposit Money to the Customer\n");
		printf("3. Add New Book\n");
		printf("4. Rent A Book\n");
		printf("5. Delivery A Book\n");
		printf("6. Burn Book\n");
		printf("7. Update Customer Information\n");
		printf("8. Update Book Information\n");
		printf("9. List of Customers Who Rent a Book\n");
		printf("10. List of Customers\n");
		printf("11. List of Books\n");
		printf("12. SAVE AND EXIT\n");
		
	}
	
	
	int main(){
		
		int secim, flag = 0; 
	
		
		books[0].B_ID = -1; //These ID = -1's mean that for the beginning there is no book,customer,rented like that. I explained before
		customers[0].C_ID = -1;
		renteds[0].R_ID = -1;
		
		//these things for getting information
		read_books(books); 
		read_customers(customers);
		read_renteds(renteds);
		
		//at everystep, you should choose your choice. The codes under runs as loop that ends when you click 12 which means save and exit
		//program runs what you choose and goes that functions
		while(flag == 0){
			menu_bas();
			scanf("%d",&secim);
			switch(secim){
				case 1:
					add_customer(customers);
					printf("\n\n\tpress ENTER to go to the main page");
					break;
				case 2:
					add_money(customers);
					printf("\n\n\tpress ENTER to go to the main page");
					break;
				case 3:
					add_book(books);
					printf("\n\n\tpress ENTER to go to the main page");
					break;
				case 4:
					rent_book(renteds);
					printf("\n\n\tpress ENTER to go to the main page");
					break;
				case 5:
					delivery_book(renteds);
					printf("\n\n\tpress ENTER to go to the main page");				
					break;
				case 6:
					burn_book(books);
					printf("\n\n\tpress ENTER to go to the main page");					
					break;
				case 7:
					update_customer(customers);
					printf("\n\n\tpress ENTER to go to the main page");
					break;
				case 8:
					update_book(books);
					printf("\n\n\tpress ENTER to go to the main page");				
					break;
				case 9:
					list_rented(renteds);
					printf("\n\n\tpress ENTER to go to the main page");				
					break;
				case 10:
					list_customers(customers);
					printf("\n\n\tpress ENTER to go to the main page");				
					break;
				case 11:
					list_books(books);
					printf("\n\n\tpress ENTER to go to the main page");				
					break;
			
				case 12://YOU SHOULD SAVE. THIS PART IS IMPORTANT!!! PLEASE, DO NOT CLOSE THE COMPILER, AFTER OPERATIONS, YOU MUST CLICK 12 TO SAVE AND EXIT
					add_file(books);
					add_filetwo(customers);
					add_filethree(renteds);
					printf("\n\n Information has been added... HAVE A NICE DAY.. \n\n");
					flag = 1;
		
					break;
				default:
					printf("Wrong choise!\n");
			}		
			
			getch();  //this is waiting for you to click keyboard
				
		
		}	
		
		return 0;
	}

